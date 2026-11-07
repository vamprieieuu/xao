# XAO Halftone Studio Source Review — Pass 7

Date: 2026-11-07

Source reviewed: supplied Halftone Photoshop UXP project, especially src/engine, src/state/params.js, tests and README. The folder contains no confirmed top-level license file in the supplied archive; until provenance and license are resolved, use it as a behavior/algorithm reference only. It is Photoshop UXP, not an AE-native plug-in.

## 1. It contains two distinct processing engines

### Halftone engine
- AM screen: fixed grid, dot radius/area varies with local tone.
- FM screen: fixed-size dots, dot count/placement varies stochastically.
- Single screen or independently angled per-ink screens, composited into a CMYK-style rosette.
- Supports angle, density/DPI, radius, radius curve, dot gain, edge-aware sampling, jittered position/size/rotation, misregistration and deterministic seed.
- Supports circle, ellipse, square, diamond, cross and horizontal-line screen shapes.
- Shape geometry uses signed-distance functions (SDF) with analytic coverage antialiasing. Tiny dots use exact analytic area so highlights fade smoothly rather than popping.
- Several shapes use equal-area normalization, so changing a dot shape does not arbitrarily change overall ink coverage.
- The ellipse is deliberately rotated 45 degrees and uses a 1.3:1 axis ratio to soften the abrupt joining of circles near midtones.
- The renderer includes a fast interior-span path for shapes where a guaranteed fully-covered horizontal span can be calculated.

### Dither engine
- 24 algorithm entries are described in the README; the source's algorithm table includes threshold, multiple Bayer matrices, clustered screens, line-oriented ordered matrices, blue noise, white noise and error-diffusion kernels.
- Error diffusion includes Floyd–Steinberg, False Floyd–Steinberg, Jarvis, Stucki, Atkinson, Burkes, Sierra 3, Sierra 2, Sierra Lite and Stevenson–Arce.
- Serpentine scanning alternates row direction to reduce directional artifacts.
- Dither is a separate mode from Halftone; the UI shares palette, grade and preprocessing controls where appropriate.

## 2. Color, separation and print behavior

- Color utilities include sRGB/linear conversion, Rec.709 and Rec.601 luma, perceptual luminance, RGB↔OKLab and HSL conversion.
- Palette extraction supports median cut, k-means and popularity-based methods.
- Palette spreading uses OKLab; locked swatches can be preserved while other colors are re-extracted.
- Tonal mapping can allocate separate palette ranges to shadows, midtones and highlights.
- Multi-ink separation uses screen-angle presets and ink-density/reflectance concepts, rather than merely applying colored circles to the source.
- Includes ink offset/misregistration, ink ordering, dot gain, preprocessing, blur, sharpening, noise reduction, grading curves and tone mapping.
- Pipeline and tests are separated from Photoshop host calls, which is useful for a host-independent native core design.

## 3. What XAO can learn from it

1. Treat screen geometry, tone-to-area mapping, color separation and print simulation as separate modules.
2. Support both AM and FM screens; these produce materially different print textures.
3. Use analytic shape coverage and equal-area calibration to keep shape changes visually consistent.
4. Add edge-aware sampling so cells straddling a sharp boundary do not average foreground and background into muddy dots.
5. Use deterministic coordinate hashing for per-cell jitter and a seed parameter so animation/render results remain reproducible.
6. Keep palette extraction, locked colors, tonal zones and ink separation independent from the shape renderer.
7. Use the 24 dither algorithm definitions as a feature comparison list, but validate algorithms independently in native C++.

## 4. Important integration boundaries

- Do not copy Photoshop UXP host code, document/layer APIs, batch-apply behavior or panel UI into XAO.
- No confirmed license file was present in the supplied project folder; no source-code reuse until permission/license is resolved.
- Reimplement selected math in the XAO C++ core, with tests and reference-frame comparisons.
- Keep the standalone Dither Majid Lines effect excluded. The Halftone project's line-shaped screen is an optional Halftone geometry and is not the same effect/module; retain it only if the user's Halftone references require it.

## 5. Proposed XAO Halftone architecture

- Sampling: global-coordinate grid, scale/DPI, cell center and edge-aware refinement.
- Tone: color-space-aware luminance, curves, threshold, radius/area transfer.
- Geometry: SDF shape library, analytic antialiasing, equal-area normalization.
- Screen: AM/FM, angle, channel phase and per-ink grids.
- Print: palette/ink separation, dot gain, ink spread, grain, misregistration and overprint.
- Variation: seeded position/size/rotation jitter with temporal stability.
- Output: compositing with source alpha, correct premultiplication, 8/16/32-bpc validation and SmartFX bounds.
