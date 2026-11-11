# XAO — POINTLESS ASCII Engine and Reuse Boundary Audit (Pass 45)

Date: 2026-11-10
Scope: direct inspection of POINTLESS source, ASCII renderer, test fixtures and licensing notices from the supplied archive. This is source review, not an XAO port or an AE runtime validation.

## 1. What the source actually implements

Inspected:
- `pointless [open source]/src/core/AsciiRenderer.cpp`
- `pointless [open source]/src/core/AsciiRenderer.h`
- `pointless [open source]/src/core/CellSample.h`
- `pointless [open source]/src/core/ColorMath.h`
- `pointless [open source]/src/gpu/shaders/ascii.frag`
- `pointless [open source]/src/gpu/shaders/ascii_grid.frag`
- `pointless [open source]/tests/render_golden.cpp`
- `pointless [open source]/tests/nearest_glyph_check.cpp`
- `pointless [open source]/README.md`
- `pointless [open source]/THIRD_PARTY_LICENSES.txt`

Verified CPU renderer behavior:
- Glyph darkness is selected from measured per-character ink coverage. The renderer rasterizes each candidate character to a small image, counts covered pixels, and normalizes the coverage values against the densest glyph.
- Coverage results are cached using font-related settings and charset as part of the cache key.
- The renderer builds a glyph atlas with padded tiles and includes special characters for directional edges/hatching.
- Cell width is derived from the selected font's measured advance for 'M'; cell height is separately configured. This is more font-aware than a fixed character lookup ramp, but the single-reference-glyph cell metric is still a simplification.
- Nearest-coverage selection is precomputed as sorted coverage breakpoints rather than scanning every glyph for every cell. Duplicate coverage values collapse to a deterministic representative; ties resolve to the lower charset index.
- An ordered-dither mode can choose between adjacent coverage glyphs using a Bayer threshold, rather than always selecting only the nearest single glyph.
- The renderer includes separate edge, hatching, stipple and contour paths. Edge orientation is derived from local gradients and mapped to directional marks; hatching is a shadow-threshold path; contour adds tonal isolines; stipple perturbs local darkness with deterministic cell noise.
- The source has a dedicated GPU ASCII shader path and separate CPU renderer code. The project README states that some operations fall back to CPU when not expressible in its shader path. That claim is recorded as project documentation; no independent benchmark or pixel-equivalence test was run in this pass.

## 2. What the tests prove — and do not prove

- `render_golden.cpp` creates repeatable synthetic source imagery and renders several ASCII configurations (fixed tones, image colors/effects and a non-square/hexagonal grid), alongside other renderer modes. It is a useful deterministic regression-fixture design.
- `nearest_glyph_check.cpp` independently checks the optimized nearest-coverage breakpoint selection against a brute-force scan over randomized character coverage arrays, duplicate coverage values and exact breakpoint probes.
- These files show deliberate regression testing around glyph selection. They do not prove Arabic shaping, full Unicode correctness, AE SmartFX correctness, MFR safety, or cross-backend pixel identity for all settings.

## 3. Critical limitations for XAO

- The renderer uses Qt `QFont`, `QFontMetricsF`, `QImage` and `QPainter`. These are application-framework dependencies and cannot be copied into XAO's native AE plugin without deliberately adding Qt as a dependency, which is outside XAO's current native SDK architecture.
- Its charset iteration and drawing use `QString::size()`, `QChar`, and `QString(charset.at(i))` in the inspected paths. This is not evidence of a complete grapheme-cluster, bidi or contextual-shaping pipeline. Do not treat it as an Arabic text renderer.
- The 'M' advance used for cell width is a heuristic; XAO should use explicit glyph metrics and baseline-aware layout for mixed-width scripts.
- POINTLESS is a complete Qt desktop application with UI, project, timeline, video and export systems. Those systems are not suitable to embed in an AE effect.
- Its GPU preview is based on Qt RHI/Direct3D and its shader interface; this is not an AE GPU SmartFX implementation.

## 4. Licensing and code-reuse decision

- The repository declares GPLv3 in its README and LICENSE.
- Its third-party notice separately identifies libdither-derived material, FFmpeg, Funnel Display (OFL-1.1), paper-design/shaders (Apache-2.0), and Qt (LGPLv3/GPLv3).
- Therefore, do not copy or adapt POINTLESS source files into XAO unless the XAO distribution's licensing strategy is explicitly compatible with GPLv3 and all third-party notices/dependencies are satisfied.
- The safe current use is analytical reference only: document observed behavior and independently design XAO algorithms without translating protectable implementation expression. Reassess with legal review before any source-derived port.
- Do not bundle its Funnel Display font or other assets merely because they are present in the project; verify the individual asset license and XAO packaging plan.

## 5. XAO design decisions from this pass

1. Keep a measured-coverage glyph matching mode as a candidate core strategy, with per-glyph raster bounds/advance/baseline rather than assuming one 'M' width.
2. Consider deterministic ordered selection between neighboring coverage candidates as an optional quality mode, separately from ordinary nearest-glyph mapping.
3. Keep edge marks, hatching, contour and stipple as independent modules/controls so they can be combined or disabled without changing the base tone mapper.
4. Build XAO's native font subsystem without Qt and with explicit Unicode shaping/fallback. Arabic text mode and independent glyph-art mode must remain distinct.
5. Establish CPU reference output first; any optional GPU path must be validated against it and must not be required for the effect to work.

## 6. Remaining gates

- Finish the targeted S1 GlyphAtlas build/render trace and identify its actual atlas input and glyph-selection metrics.
- Continue tracing Crates, OVN and L3tt3rM4pp3r2 internal render paths.
- Complete the 45-font coverage/shaping/license matrix.
- Review remaining ASCII open-source files and exact dependency licenses.
- Do not close the ASCII audit or claim implementation completion until the native font/render design and AE-specific validation gates are satisfied.

