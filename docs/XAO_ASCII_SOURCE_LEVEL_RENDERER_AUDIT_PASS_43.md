# XAO — ASCII Source-Level Renderer Audit (Pass 43)

Date: 2026-11-10
Scope: direct source inspection of the supplied ASCII open-source projects.
Status: source-level findings; no implementation port or AE runtime claim.

## 1. auraascii — two-pass edge-aware glyph renderer

Inspected:
- `auraascii master  [open source]/src/engine/AsciiRenderer.ts`
- `auraascii master  [open source]/src/engine/GlyphAtlas.ts`

Verified implementation:
- The renderer uses two passes: an edge-analysis render target (EdgeFBO) followed by an ASCII compositing pass.
- The edge target stores gradient magnitude, angle and luminance in a half-float target according to the source comments.
- The ASCII pass samples the source texture, edge target and glyph atlas.
- Glyph atlas is built once from the charset and uploaded as a texture; changing charset/font size/family rebuilds it.
- Atlas construction deduplicates Unicode code points while preserving order, measures a reference 'M' width, assumes line height = 1.2 × font size, and packs glyphs into a square-ish grid in a power-of-two canvas.
- Cell count is calculated from CSS dimensions and configured cell size; the WebGL renderer uses a pixel ratio capped at 2.

Important limitations for XAO:
- The atlas implementation does not perform font fallback validation, glyph coverage validation, per-glyph metrics, shaping, or bidi processing. A Unicode code point in the charset is not sufficient proof that the chosen font can render it correctly.
- The reference glyph 'M' and fixed 1.2 line-height are heuristics; XAO should use measured per-glyph bounds/advance and explicit baseline/atlas padding.
- This is browser/WebGL code, not directly portable to native AE. The transferable ideas are the two-pass separation and atlas caching, subject to CPU fallback and AE render semantics.
- Its render loop and mutable WebGL state are not a direct SmartFX implementation.

## 2. ASCII Art main — mapper and tone semantics

Inspected:
- `ASCII Art main [open source]/src/engine/GlyphMapper.h`
- `ASCII Art main [open source]/src/engine/Luminance.h`
- `ASCII Art main [open source]/src/engine/RenderConfig.h`

Verified:
- The engine separates per-cell input data (mean RGB, luminance, index, edge magnitude and edge direction) from mapping strategy.
- LuminanceMapper maps tone to a ramp index; color can be monochrome or source truecolor.
- EdgeMapper selects one of four directional edge glyphs when Sobel-derived edge magnitude exceeds a threshold; otherwise it falls back to the luminance ramp. This is a genuine independent edge-aware mode, not merely a larger charset.
- EmojiMapper uses hue/category selection and falls back to the luminance ramp for neutral colors.
- RenderConfig separates cellWidth and cellHeight, contrast, brightness, gamma, invert, edge threshold, enhancement and render mode.
- Luminance uses Rec.709 coefficients and a gamma exponent; tone mapping applies contrast around 0.5 then brightness; ramp indexing optionally reverses the ramp.

XAO decisions:
- Preserve the separation between sampling, analysis and glyph mapping.
- Keep grid dimensions/aspect separate from glyph scale.
- Edge glyphs must remain a selectable strategy/overlay and not silently replace the complete ramp.
- Treat the supplied gamma/tone equations as one source implementation, not as universal color-management truth. XAO must define its working color space and apply transforms consistently.

Limitations:
- The current mapper uses `std::string(1, ramp_[idx])` and `QChar`-style single-character assumptions elsewhere; it is not a Unicode shaping engine.
- The source's own comment comparing itself to three reference projects is not independently verified; this audit records code behavior, not that comparative claim.
- The emoji mode depends on a finite category palette and is not a general glyph/font matching algorithm.

## 3. Morphing ASCII Shader — temporal and post-process techniques

Inspected:
- `morphing ascii shader   [open source]/src/AsciiEffect.js`
- `morphing ascii shader   [open source]/src/MemoryGrid.js`
- `morphing ascii shader   [open source]/src/InkBleed.js`
- `morphing ascii shader   [open source]/docs/PARAMETERS.md`

Verified:
- The ASCII effect uses a runtime glyph atlas and a Sobel edge operator with directional edge glyph selection.
- The source documents square cells in drawing-buffer pixels, source sampling at the cell center, tone controls, and glyph selection from luminance or edge direction.
- MemoryGrid stores per-cell state in ping-pong render targets; it blends previous cell luminance/color toward the current target and derives a residual/activity value.
- InkBleed uses a 64-sample Vogel disk. Per-sample direction/radius/weight are baked once to a kernel texture/uniform array; the image pass accumulates ink-weighted color and optional blur, preserving input alpha.
- The shader early-outs when both bleed and blur are disabled.
- The source describes an SDF-based glyph transition/morph path and multiple independent parameters in PARAMETERS.md.

XAO decisions:
- Do not port mutable previous-frame feedback directly into AE Smart Render. Any temporal look must be reproducible for arbitrary frame order, reverse playback, repeated renders and MFR. Use absolute-time deterministic evaluation or a separately designed immutable analysis/cache stage.
- Treat InkBleed as a post-ASCII color diffusion concept. A 64-tap full-resolution CPU implementation is likely expensive; use bounded sampling/downsampling/region-aware strategies and benchmark before exposing high-quality defaults.
- Keep edge, glyph morph, memory/trails, bleed and blur as separate controls/stages.
- Preserve alpha independently from RGB during all post-processing.

## 4. Unicode and font system implications

The inspected atlas and mapper sources demonstrate why XAO needs a more rigorous native font subsystem:
- Unicode scalar iteration must not be confused with grapheme clusters or shaped glyph runs.
- Arabic text requires bidi resolution and contextual shaping before rasterization; glyph-art mode should remain a distinct mode that intentionally treats selected symbols as independent marks.
- Atlas keys must include font identity/version, variation axes, size, shaping/features, glyph ID and rasterization settings.
- Atlas entries need measured bearings, advance, ink bounds, baseline and padding; a single fixed cell based on 'M' is insufficient.
- Missing glyphs must be detected and fall back predictably.
- Font licensing must be checked separately from technical support.

## 5. Implementation boundary

No source from these projects has been copied into the native XAO renderer in this pass. These are architecture and algorithm findings only. Browser/WebGL, Qt application code, UI code and mutable GPU render loops are not native AE SmartFX drop-ins.

## 6. Remaining ASCII gates

- Finish full read-through and dependency/license classification of the remaining source files in ASCII Art main, auraascii and POINTLESS.
- Continue tracing the four AEX decompilations at parameter setup, command dispatch and render entry points; do not equate strings/imports with verified behavior.
- Validate all 45 supplied fonts for actual glyph coverage, shaping and license status.
- Complete visual review of MAIN IDEAS and the open-source demos; existing metadata/contact sheets do not equal frame-by-frame manual review.
- Design and test a deterministic, thread-safe native glyph raster/atlas and SmartFX pipeline before phase closure.
