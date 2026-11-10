# XAO — crates.io Source Audit: ditherlib (Pass 56)

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Upstream: https://github.com/Downmoto/ditherlib
Registry docs: https://docs.rs/ditherlib/latest/ditherlib/
Inspected: published API documentation, upstream `Cargo.toml`, root source layout and effect module inventory.

## 1. Identity, language version and license

The inspected upstream manifest declares:
- Package: `ditherlib` 1.0.0
- Rust edition 2024
- Minimum Rust version 1.88
- License: Apache-2.0
- Required runtime dependency: `image` 0.25.10, with codec features disabled at dependency declaration and enabled selectively by crate features.
- Default features: JPEG and PNG codecs.
- Criterion 0.8.2 is a development/benchmark dependency.

This is not a C++ library and would introduce a Rust toolchain/runtime integration decision that is unnecessary for XAO's native AE C++ architecture. No source copied.

## 2. Effect and algorithm catalogue

The published API documents:
- Greyscale and Gaussian blur;
- thresholding;
- ordered Bayer and artistic/custom threshold maps;
- deterministic white-noise and blue-noise dithering;
- print-style Halftone with circle, square, diamond, ellipse, line and cross shapes;
- ColourHalftone with independent RGB or CMYK screens;
- fourteen error-diffusion presets plus custom kernels;
- Ostromoukhov variable-coefficient diffusion;
- Riemersma/Hilbert-curve diffusion;
- palette matching in gamma-encoded RGB, linear RGB and Oklab;
- whole-image, anti-aliased polygon and custom-mask selections;
- ordered multi-effect pipelines and reusable renderer buffers.

The API states that CMYK processing performs under-colour removal, screens C/M/Y/K separately, then recombines subtractive channels into RGB. The documented traditional screen angles are C=15°, M=75°, Y=0°, K=45°; the moiré-resistant preset is C=18.4°, M=71.6°, Y=0°, K=45°. These are source-documented defaults, not universal print standards.

## 3. XAO-relevant technical ideas

High-value candidates for native implementation study:
1. Separate screen angle and phase/offset per color channel.
2. Explicit geometric halftone cell shapes, including line and cross.
3. Deterministic stateless noise indexed by absolute image coordinates and seed, so selections/tiles do not shift the pattern.
4. Five sampling modes for logical pixels: coverage-weighted average, centre, darkest, lightest and dominant colour (per API documentation).
5. Oklab and linear-RGB palette matching as optional color-distance strategies.
6. Explicit error-diffusion strength, clamp and scan-direction controls.
7. A reusable pipeline model that always begins from immutable source pixels, avoiding cumulative re-render drift.

These ideas should be evaluated against XAO's existing Screen/InkMixer and Halftone architecture. Do not create duplicate features just because another crate offers them.

## 4. Important limits

- The crate's `SourceImage` is documented as immutable RGBA8; it is not a direct match for XAO's AE 8/16/32-bpc host buffer contract.
- The crate uses an owned image/renderer abstraction and image codecs; XAO should not import this host/image-I/O layer.
- The documentation claims deterministic/stateless thresholding for specific modes; validate exact coordinate anchoring and tile behavior in source before adopting it.
- API feature lists do not establish MFR safety or AE SmartFX compatibility.
- No benchmark numbers are copied into this report; the benchmark guide and source harness need separate inspection.
- Rust 1.88 / edition 2024 are not compatible with the current C++-only XAO build without introducing a new toolchain integration.

## 5. License boundary

The upstream manifest declares Apache-2.0. Before literal reuse, preserve the license and required notices, inspect any bundled assets/example attributions, and ensure any dependencies or generated resources have compatible terms. This pass does not authorize copying source into XAO.

## 6. Recommendation

**High-value algorithm reference, not a runtime dependency.**

The strongest contribution to XAO is the combination of:
- deterministic, image-origin-anchored screens/noise;
- RGB/CMYK independent screen channels;
- six geometric screen shapes;
- palette-aware color matching;
- explicit sampling and diffusion controls.

The user’s existing Retratone requirements already include four ink plates, independent pattern angles, offsets and 13 pattern families. Therefore, use ditherlib to cross-check missing mathematical behaviors and edge cases, not to replace the Retratone/InkMixer design.

## 7. Verification boundary

This pass inspected the upstream manifest and public API documentation, plus the source tree/effect-module inventory. It did not yet trace each implementation file, run Cargo tests, execute benchmarks, or compare pixel fixtures. Full source-level verification of ColourHalftone, geometric screens, sampling, diffusion and alpha handling remains open.
