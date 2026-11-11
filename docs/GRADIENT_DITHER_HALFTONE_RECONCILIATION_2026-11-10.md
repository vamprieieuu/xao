# XAO — Gradient Intent, Dither & Halftone Reconciliation
Date: 2026-11-10
Branch: xao/recovery-baseline-2026-11-10
Status: research reconciliation only. No source code changed and no engine is reimplemented in this pass.

## 1. User-confirmed project state and hard boundaries

The user explicitly confirmed that Gradients, Depth, Rays, Glow and Glint have already been completed in the prior XAO work. They must not be described as pending or restarted based on older audit documents. This note reconciles the intended design and source evidence; it does not invalidate that completed status.

Do not touch the separate GradientStudio project/component. Do not port or expose the standalone Lines effect/module from Dither Majid. A line-shaped mark inside Halftone remains a separate geometry concept and is not the excluded Dither Majid Lines effect.

The user's latest request is to understand the gradient design intent before any integration/merging, and to revisit Dither and Halftone source/reference analysis in the XAO archive for a more accurate understanding.

## 2. Gradient — recovered intent and evidence

### 2.1 Distinguish three concepts

Do not conflate:
1. The already-completed Gradient engine(s) in XAO, as confirmed by the user.
2. An advanced gradient editing/control model evidenced by the supplied BFX Map Ramp and Gradient Designer references.
3. The separate GradientStudio project/component, which is explicitly out of scope and must not be modified.

Earlier conversation context also records a desired central/shared gradient-and-color control capability for engines, including creating colors and saving them as presets. The exact boundary between the completed XAO gradient engine and any shared control UI must be reconciled against the latest XAO source before implementation.

### 2.2 Advanced editor capabilities evidenced in the archive

The Gradient Designer audit records:
- Basic Shape / Layer Map modes.
- Basic shapes: Horizontal, Vertical, Linear, Elliptical, Rectangular and Radial.
- Anchor, Position, uniform/non-uniform Scale, Rotation and X/Y Shear.
- Layer-map channels including Grayscale, RGB, Alpha, Luminance, Average, Lightness, Hue, Saturation, CMY, Lab L/a/b and YUV U/V.
- Invert, Premultiply With Alpha and optional Levels (input black/white, map gamma, output black/white).
- 1–12 color entries, each with Use state, Color, Alpha and Position.
- Color bank/presets, gradient interface and cycle controls.
- Repeat modes: None, Wrap, Hold and Mirror; Reverse and Dither.
- UI actions/strings for inserting/deleting stops, even spacing, resetting positions, cycle drag/reset, and color/alpha gradient display.
- Render modes: Gradient Map, Gradient Only and Composite; composite blend mode, preserve transparency and opacity.

The audit identifies custom widget classes (wUIGradient, wUIColorSwatch, wUIColorSliders, wUISlider, wUISystemColorPicker), indicating a dedicated drawn gradient editor rather than a stock three-color parameter panel.

BFX Map Ramp independently demonstrates AE Custom UI + Drawbot paths/handles, stop hit-testing/selection, color picker interaction and parameter refresh. Its exact callback wiring and full insert/delete behavior still need focused binary cross-reference before claiming a pixel-identical reproduction.

### 2.3 Do not mistake the simple open-source Gradient Map for the intended advanced editor

The separate open-source gradientmap.cpp is only a three-stop luminance map (Low/Mid/High), with contrast and mix. It has no draggable arbitrary stops, alpha stops or advanced custom widget. It is a useful simple algorithm reference only, not a complete specification of the advanced gradient editor.

### 2.4 Working interpretation — not an implementation authorization

The likely design direction to validate against the latest XAO source is:
- Preserve the completed Gradient render engine(s).
- Treat the multi-stop ramp/editor as an advanced color-control model where applicable, with per-stop color/alpha/position and interactive stop editing.
- Keep gradient mapping, shape/layer-map generation, and per-engine color controls conceptually distinct.
- Allow reusable color definitions/presets where the user's shared-control concept requires it, without turning the separate GradientStudio into part of XAO.
- Share color-state/picker infrastructure with Ink Mixer where appropriate, but never represent ink plates as gradient stops.
- Keep gradient state authoritative in serializable AE parameter/state data; the custom UI is only its editor/view.

No new gradient code should be written until the latest completed XAO gradient implementation and the user's exact shared-control intent are mapped from the actual source and previous conversation artifacts.

## 3. Dither — source and reference reconciliation

### 3.1 Supplied XAO archive source

XAO/dither/dither ofx [open source]/dither.cpp is an OFX Bayer 4x4 implementation, not a native AE implementation and not the full Dither Majid project. It:
- Builds a low-resolution grid using per-cell average luminance.
- Uses a Bayer 4x4 threshold matrix and contrast/spread.
- Maps cell values to fixed palettes (Game Boy, mono, amber, ice, ember).
- Upscales with nearest-neighbor to crisp square cells.
- Has a single global pixel-size control, palette, spread and contrast.
- Advertises 8/16/float and RGB/RGBA dispatch, but writes alpha to maximum for RGBA, so it does not preserve source alpha.
- Disables tile support because its grid is built over the full source frame.
- Is OFX code with host dependencies, not a drop-in AE core.

This is a limited single-scale Bayer reference, not a complete XAO Dither specification.

### 3.2 Dither Majid reference

The Dither Majid repository is a build/architecture and selected dither-algorithm reference. Its 49 dither/screen algorithms may be studied and selectively implemented after algorithm-by-algorithm validation. Do not port its standalone Lines module, parameters, UI or presets.

Known issues from the audit that must not be copied:
- PiPL effect version mismatch with PF_VERSION.
- Smart Pre-render checkout/error handling requires hardening.
- Smart Render callback/world/stride/pixel-format checks require hardening.
- The purported parallel_rows implementation is serial.
- Frame timing assumes 30 fps rather than using AE timebase.
- CI binary checks do not prove AE runtime correctness.

### 3.3 PixelDitherGo is a distinct visual reference

The MAIN IDEAS PixelDitherGo recording and notes show:
- A restricted black/dark-green/bright yellow-green palette.
- Coarse square/block regions plus a much finer regular lattice.
- Micro-dot/cross-like marks and thin structural seams.
- Mixed cell scales, local pattern-density changes and irregular transitions between solid and patterned regions.
- The grid appears spatially anchored while source content changes; the exact temporal mechanism remains unproven.

Do not reduce this to a generic Bayer 4x4 filter or random-noise overlay. The current best hypothesis is a multi-scale structured dither composition: coarse tonal/block map, fine micro-pattern map, and optional subtle grid/edge/detail layer. Exact formula and animation behavior still require frame-by-frame source/output tracking.

## 4. Halftone — reconciled feature model and reference evidence

### 4.1 Distinguish Halftone from Dither and Array

Halftone is a screen/ink geometry and tonal-coverage engine. Dither is quantization/threshold/error-diffusion. Array is a multi-level shape-field system. They may share sampling, palettes, shape math and deterministic randomness, but must not be collapsed into one renderer or one generic control set.

### 4.2 Recovered Halftone feature concepts

Across Halftone Dean, Halftone Lap, Halftone Studio, Shape Halftone references and XAO's prior audits:
- Screen families: AM and FM; mono and independently angled multi-plate screens.
- Geometry: dot, line, square, diamond, ellipse, cross, ring, spiral, wave, noise, stipple, hex and checker, subject to final user references.
- Layouts: square, diagonal, hexagonal and radial.
- Multi-ink: mono, CMYK-like, spot and extended creative channels; independent plate angle, color/tint, visibility, offset/registration and screen parameters.
- Tone mapping: luminance/plate separation, threshold range, curves, gamma, contrast, highlights/shadows and tone-to-area/radius transfer.
- Print-style controls: dot gain, ink spread, shape slur/roughness, jitter, distortion, grain and misregistration.
- Geometry quality: signed-distance shapes, analytic antialias coverage, equal-area normalization and special handling for subpixel dots.
- Output/compositing: knockout, multiply/overprint, additive where explicitly required, source/transparent/custom background behavior and alpha preservation.
- Stable global image-space grid anchoring; crops, tiles, proxy scales and MFR must not shift or reseed the screen.

### 4.3 Explicit user restriction

The user explicitly does not want a paper layer, paper background, or paper-surface simulation added to the XAO Halftone engine. Older reference UIs may show Paper/Paper Grain controls; those are not authorization to include them. Retain only the other visual/print controls supported by the user's desired result.

### 4.4 Reference quality and reuse boundaries

- Halftone Dean (MIT) is a Python renderer and useful feature/algorithm reference, not a native AE runtime.
- Halftone Lap (MIT) is browser Canvas and useful print behavior reference, not native code.
- Halftone Studio has useful AM/FM, SDF, analytic coverage, equal-area and plate separation concepts; no confirmed license in the supplied folder, so use as behavior reference only until cleared.
- Halftone Akam has conflicting MIT and personal-use/non-commercial terms; do not copy/adapt code unless provenance and rights are clarified.
- Halftone Master/Mike contain legacy AE source copies without clear archive license; behavior research only until rights are established. Old SDK code is not a safe AE 2023 drop-in.
- Halftone PS is Photoshop UXP, not an AE adapter; do not bring UXP/DOM host runtime into XAO.
- A line-shaped halftone stamp is permissible as a Halftone geometry if supported by the user's references; it is not the excluded Dither Majid Lines effect.

## 5. Technical invariants for both engines

- Preserve source alpha; never silently force RGBA output opaque.
- Define straight vs premultiplied alpha and linear vs encoded RGB explicitly.
- Support 8/16/32-bpc only where tested; preserve HDR values where supported.
- Use deterministic integer hashes/PRNG keyed by stable engine/layer/cell/plate identity and absolute AE time where animation is intended.
- Use full-frame/source-space coordinate anchoring so tiled/cropped/region renders match full-frame output.
- Use bounded scratch buffers and immutable/thread-safe cache entries for MFR.
- Error diffusion is scan-order dependent; do not parallelize independent rows in a way that changes the algorithm. Ordered screens can use a different parallel strategy.
- Native C++ core must not depend on Python, NumPy, Qt, browser Canvas, DOM, Photoshop UXP or OFX host APIs.
- Validate with golden image fixtures and per-bit-depth/alpha/bounds tests before marking an engine verified.

## 6. Next audit sequence

1. Map the latest actual XAO source for the already-completed Gradient, Depth, Rays, Glow and Glint work; do not rewrite them.
2. Reconcile the Gradient engine's current code/state with the user's advanced editor and shared color/preset intent; inspect prior Gradient conversation artifacts if present.
3. Inspect every Dither source/reference in XAO and the Dither Majid repo, classify each algorithm, test correctness, alpha, color space, tiles and determinism.
4. Reinspect the PixelDitherGo recording at original timestamps and correlate coarse/fine pattern structure to the current Dither implementation.
5. Reinspect all Halftone source folders and Shape Halftone images/settings, distinguishing allowed behavior concepts from license-restricted code.
6. Produce a source-of-truth engine map with actual source paths, license status, tests, AE integration status and remaining gaps before integration/merge.

## 7. Validation statement

This document is a research reconciliation based on existing GitHub audit documents, supplied source paths and recovered conversation context. It does not claim new source implementation, new builds, or After Effects runtime testing.
