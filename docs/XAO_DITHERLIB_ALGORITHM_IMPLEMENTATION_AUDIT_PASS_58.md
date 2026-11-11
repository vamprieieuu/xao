# XAO Ditherlib Algorithm Implementation Audit — Pass 58

Date: 2026-11-10  
Upstream: https://github.com/Downmoto/ditherlib  
Audited ref: `master` (repository default branch at audit time)  
License observed in repository metadata and LICENSE: Apache-2.0

## Scope and limits

This pass inspected the actual upstream implementation files under `src/effects/dither/`, especially `colour.rs`, `noise.rs`, `diffusion.rs`, and `halftone.rs`, plus package metadata and license. The repository tree also confirms dedicated modules for cells, palette, Riemersma, Ostromoukhov, threshold, and tests. This is not a full line-by-line audit of every module, and no Rust tests or benchmarks were run in this pass.

## Verified implementation details

### Colour spaces

- The implementation exposes gamma-encoded sRGB, linear-light sRGB, and Oklab matching spaces.
- sRGB decoding uses the IEC 61966-2-1 piecewise transfer function (0.04045 breakpoint, 12.92 slope, 0.055 offset, 1.055 scale, 2.4 exponent).
- Oklab conversion uses the reference linear-sRGB → LMS cube-root → Oklab matrix transform.
- Luminance uses BT.709/sRGB coefficients (0.2126, 0.7152, 0.0722); Oklab uses its L component.
- Oklab components are clamped separately: L to [0,1], a/b to [-0.5,0.5]. This is an implementation policy, not a general gamut-mapping solution.

**XAO implication:** palette matching should be able to choose encoded RGB, linear RGB, or perceptual Oklab. Do not treat gamma-space Euclidean RGB distance as the only quality mode. A future native implementation must define its HDR/out-of-gamut and alpha semantics independently.

### Noise dithering

- White noise is deterministic per logical image coordinate and seed, using a stateless 64-bit mixing function.
- Blue noise is a fixed 16×16 rank/threshold table of 256 entries. It is not generated at runtime.
- The seed chooses per-tile translations, axis swap, and horizontal/vertical reflections of the fixed table. Thus it creates deterministic tile variants; it does not prove a newly generated globally optimized blue-noise field.
- The logical pixel grid supports independent width/height, image-space offset, and sampling mode.
- Noise strength is validated in [0,2] and quantized to 1/256 increments.
- Coordinate-based sampling is explicitly designed so traversal order and selection bounds do not shift the surrounding field.

**XAO implication:** this is a useful deterministic CPU design for a repeatable blue-noise screen, but label it accurately as a seeded transform of a fixed 16×16 map. For XAO, test tile periodicity and boundary visibility before exposing it as a premium blue-noise mode. Keep the noise anchor in image coordinates, not tile/render-request coordinates.

### Error diffusion

The source defines explicit weighted kernels including Floyd–Steinberg, Atkinson, Jarvis–Judice–Ninke, Stucki, Burkes, Sierra, Two-Row Sierra, Sierra Lite, False Floyd–Steinberg, Fan, Shiau Fan variants, Stevenson–Arce, and a two-dimensional Knuth pattern.

- Kernels are represented as weighted relative destination taps.
- The API exposes independent-channel versus luminance-only error propagation.
- The implementation exposes colour-space selection, palette matching, pixel-grid controls and scan mode.
- The test source includes a serpentine-scan fixture and verifies output remains palette-quantized while preserving each source pixel's alpha byte.
- The serpentine fixture specifically checks that a selected image row is processed in the expected reverse direction, rather than treating selection-local row direction as the image's coordinate system.

**XAO implication:** translate only after checking every kernel's normalization, scan-direction mirroring, boundary handling, mask/selection behavior, and deterministic frame-order behavior. Error diffusion is stateful across pixels, so parallelization must preserve scan dependencies; do not claim arbitrary tile/MFR equivalence without a deliberate strategy. Alpha should not be diffused as colour.

### Halftone and colour separation

- Shapes implemented: circle, square, diamond, ellipse, line, and cross.
- Screen controls include independent cell width/height, clockwise angle in radians, phase/offset in image pixels, and scale.
- Threshold evaluation is based on pixel centers (x+0.5, y+0.5), with screen coordinates rotated and phase-shifted before evaluating the geometric threshold field.
- RGB colour halftone thresholds the three additive channels independently.
- CMYK mode performs RGB→CMYK with under-colour removal, screens four subtractive channels, then recombines them into RGB.
- Traditional CMYK angles are C=15°, M=75°, Y=0°, K=45°. The documented moiré-resistant preset uses approximately C=18.4°, M=71.6°, Y=0°, K=45°.
- Each channel can have an independent angle and offset.
- The per-pixel implementation writes RGB only; it does not write the alpha byte in these routines. This is not proof of AE premultiplication behavior.

**XAO implication:** the geometric screen function, independent channel phase/angle, RGB/CMYK modes, and UCR conversion are strong algorithm references. Do not copy its RGBA8 assumptions into XAO's float/16-bit AE pipeline. Preserve alpha explicitly in the native adapter and test premultiplied/unpremultiplied inputs.

## License and reuse boundary

The repository declares Apache-2.0 and includes the Apache 2.0 license text. This permits reuse subject to its conditions, including retaining the license and applicable notices, marking modified files, and including NOTICE attributions if upstream provides a NOTICE file. This pass did not establish whether every transitive dependency or optional codec is needed by XAO. The crate itself depends on Rust's `image` package; XAO should port selected algorithms into native C++ rather than introduce a Rust runtime or image-codec dependency.

## Not established in this pass

- Full implementation and edge-case behavior of Riemersma, Ostromoukhov, palette matching, threshold matrices, and cell sampling.
- The complete list/normalization of all diffusion kernels beyond the inspected source excerpts.
- Whether the fixed blue-noise rank table has an upstream provenance or a spectral-quality validation.
- AE SDK integration, SmartFX, MFR safety, 16/32-bpc handling, premultiplication, HDR, GPU implementation, or performance on XAO target hardware.
- No source code was copied into XAO in this pass; this is an algorithm and reuse-boundary audit only.

## Recommended XAO follow-up

1. Finish dedicated traces of Riemersma, Ostromoukhov, palette matching, threshold matrices, cell sampling and their tests.
2. Build native C++ fixtures for RGB/linear/Oklab palette matching and CMYK/UCR screen separation.
3. Add deterministic coordinate and scan-direction fixtures, including partial selections and render-window boundaries.
4. Benchmark CPU error diffusion separately from embarrassingly parallel ordered/noise screens.
5. Keep all AE pixel-format and alpha handling in XAO's own typed adapter; never import the crate's RGBA8 contract as an AE contract.
