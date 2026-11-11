# XAO Focused Audit — Halftone Dean Python Renderer — Pass 20

Date: 2026-11-07

## Scope

Reviewed the supplied six-file Halftone Dean project, including the complete `main.py` renderer, defaults/presets, UI controls, image preparation, preview/high-resolution worker lifecycle, import/export and license. The project declares MIT licensing. It is a Python/NumPy/Pillow/PySide6 desktop app, not an AE plugin.

## 1. Rendering algorithm

- Uses a vectorized NumPy renderer with a full-resolution pixel-coordinate grid.
- Supports 13 shape styles: Dot, Line, Square, Diamond, Cross, Ring, Spiral, Wave, Noise, Stipple, Hex, Ellipse and Checker.
- Supports four layouts: Square, Diagonal, Hex and Radial.
- Supports mono, 4-channel CMYK-like, 6-channel and 8-channel ink separations.
- Each plate has its own angle, ink color and tint. The 4-channel set uses nominal offsets of C +15°, M +75°, Y 0°, K +45° from the base rotation; extended plates add further angles.
- Cell assignment is calculated in rotated coordinates for square/diagonal/hex layouts, or in concentric rings and angular sectors for radial layout.
- Each cell gets a deterministic coordinate/plate-derived hash used for jitter, distortion and tonal grain.
- Samples the source bilinearly at the displaced cell center, computes a per-plate tone value, applies gamma/contrast/highlight/shadow/grain/fill adjustment, and maps tone to a shape scale.
- Shape coverage is calculated in normalized local coordinates; ink layers are composited over a paper-color base using Normal, Multiply, Screen, Overlay or Soft Light.
- A final deterministic grain pass perturbs the output paper/ink composite.
- Source preprocessing includes exposure, saturation, unsharp mask, invert and vignette.

## 2. Critical mismatches between labels and actual algorithms

1. **“Floyd” is not Floyd–Steinberg error diffusion.** In `_apply_dither`, both `floyd` and `stipple` fall through to a seeded hash-noise threshold perturbation. No quantization-error propagation or scan-order diffusion occurs. XAO must never label this as Floyd–Steinberg.
2. **Chromatic Aberration is not RGB-channel displacement.** The `aberration` value shifts the common source sample position for the plate along the screen-angle vector. It does not independently offset red/green/blue channels as a conventional chromatic-aberration effect would.
3. **The renderer is RGB-only and fully opaque.** It converts source images to RGB and initializes a paper-color RGB output; alpha is discarded at load, preprocessing and render output. This cannot be used as XAO's alpha/premultiplication model.
4. **“Diagonal” layout shares the staggered-row cell placement branch with Hex.** Both use a half-cell alternate-row offset and the same row-step logic; there is no independent diagonal lattice transform in the renderer.
5. **Tone and shape coverage are stylized, not calibrated print separations.** The CMYK values are approximate RGB-derived channel amounts; no ICC profiles, device-link transforms, total ink limit, dot gain calibration or print-screen validation are implemented.
6. **“8-channel” is a fixed eight-plate mode, not arbitrary eight independent source channels.** It renders C/M/Y/K plus R/G/B/V extra color-key fields. It is a creative extended-ink look, not a standardized press workflow.

## 3. Performance and memory constraints

- The renderer allocates full-frame coordinate grids and multiple temporary arrays for each plate: cell indices, cell positions, hashes, jitter, sampled colors, tone, shape coverage, alpha and blend intermediates.
- In 6- or 8-plate mode, this work and memory allocation are repeated for each plate. At 4K, several simultaneous float32 full-frame arrays can require hundreds of megabytes; concurrent AE frame renders would multiply the peak.
- The algorithm uses many full-frame NumPy vector operations and transcendental functions (sin, cos, atan2, sqrt, power) for every pixel and plate.
- The preview caps its maximum dimension at 512, while high-resolution rendering runs at the original source dimensions. The preview is therefore not evidence of final-render performance.
- The UI runs a single QThread worker. It defers a new render if the previous worker is still active; this is not a parallel frame-render design.
- A user-adjusted slider can queue a debounced render; settings and source are copied for the worker, but this desktop lifecycle is not a substitute for AE's per-frame deterministic render contract.

## 4. Additional correctness and design observations

- The cell-seed hash is deterministic for fixed coordinates and plate index, which is a useful concept for XAO. However, it is not exposed as a user seed in the reviewed settings.
- The hash uses floating-point sine and large constants. Cross-platform bit-identical results are not guaranteed; XAO should use a specified integer PRNG/hash if deterministic reproducibility across CPU architectures matters.
- The radial layout's ring count and angular sector count vary with radius, which can create discontinuities where ring indices change; test transitions and center behavior if this concept is implemented.
- The tone dither uses a 4×4 Bayer matrix for Bayer mode. The noise/stipple modes are hash-based perturbations, not error diffusion.
- The color-blend modes are custom formulas; they are not guaranteed to match After Effects' exact blend-mode implementations.
- The source is converted to 8-bit RGB before rendering. There is no high-bit-depth/HDR source path.
- Preview and hi-res rendering call the same render function at different dimensions, but no AE time input or animation exists in this project.

## 5. XAO decisions

- Keep the shape catalogue, independent screen plates, per-plate angle/color/tint, radial layout, deterministic cell jitter and tone-to-area mapping as candidate concepts.
- Reimplement with a bounded tile/row pipeline and reusable render-local buffers; avoid full-frame allocation multiplication per plate.
- Provide correct, separately implemented ordered dithering and error diffusion algorithms; name each mode according to what it actually computes.
- Preserve alpha and support AE 8/16/32-bpc and HDR in the shared core.
- Use a stable integer hash/PRNG and explicitly key randomness by layer, engine, cell, plate and requested AE time when animated.
- Treat the UI as a feature inventory only. XAO still needs the user's requested unified shared control surface, not a direct copy of this desktop panel.
- Use independent native C++ implementations; do not bring Python, NumPy, Pillow or Qt runtime dependencies into the AE plugin.

## 6. Review status

This pass covers the full main renderer and the key application/settings/preset/render lifecycle sections of the supplied Halftone Dean project. It is a source review, not a local Python GUI run, AE SDK build, or After Effects runtime test. Other Halftone projects and remaining XAO folders still require review.
