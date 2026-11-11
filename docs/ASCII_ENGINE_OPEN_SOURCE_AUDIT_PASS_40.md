# XAO — ASCII Engine & Open-Source Reference Audit (Pass 40)
Date: 2026-11-08
Status: research/design audit; no production implementation or AE runtime verification performed.

## Evidence labels
- Verified (source): stated in accessible repository documentation.
- Observed (XAO reference): recorded from supplied MAIN IDEAS material.
- Inferred (XAO design): proposed architecture, not a recovered proprietary algorithm.
- Unknown: requires original files, deeper source inspection, or runtime experiments.

## 1. XAO ASCII looks — separate render identities

### ASCII CGO
Observed: regular dense glyph rows, tone silhouette, selective orange/red glowing glyph accents.
Inferred: stable grid + luminance/color sampling + glyph ramp + deterministic cell variation + separate accent/emission mask. Accent mask and glow remain independently controlled.
Unknown: exact charset, accent selection and animation distribution.

### ASCII Ghost
Observed: dense glyphs with cream and deep red/maroon regions; diagonal/radial ray-like contribution.
Inferred: ASCII renderer plus independent Rays pass, sharing source/mask but not renderer. Edge orientation may optionally influence glyph direction.
Unknown: ray generation model and whether color comes from source sampling or palette bands.

### Liquid ASCII
Observed: rounded pill/rectangular tiles arranged in rows, variable widths, short word/glyph groups, source-related fill colors. Not a square grid.
Inferred: row partition/layout engine, variable tile widths and optional row heights, corner radius/gap, source-sampled fill, text fitting and clipping. This is a text layout system, not only glyph lookup.
Unknown: exact row partition constraints and content-driven vs seeded-random sizing.

### Mosaic ASCII
Observed: coarse square mosaic blocks plus a second fine glyph layer; dark negative space and selective glow.
Inferred: two independently scaled passes with independent sampling, visibility and opacity. Fine glyph clipping by coarse occupancy is a design option, not confirmed.
Unknown: exact compositing order and clipping relationship.

### Rainbow ASCII
Observed: dense glyph field with local color variation, dark background and bright cyan/blue/violet/white plus occasional warm accents. Not a full-frame rainbow tint.
Inferred: per-cell source-color sampling or quantized palette assignment coupled with tone/occupancy mapping. Local emission/glow is separate.
Unknown: direct source hue vs palette-band assignment.

### Threshold ASCII
Observed: row-aligned bars/segments of varying length and density, with block/point details.
Inferred: row/segment occupancy renderer driven by local or row-integrated tone; optional block/point accents. Distinct from conventional glyph ramp and explicitly distinct from the prohibited Dither Majid Lines effect.
Unknown: whether segment length is row-integrated luminance, threshold crossings, or pattern lookup.

## 2. Public-source comparison

### A. Ruchi2117/ASCII-Art — C++20, Qt6, OpenCV, MIT
Verified source description: pure engine separated from capture/UI; luminance, color and edge-directional modes; Sobel chooses directional glyphs; adaptive detail; CLAHE/unsharp options; threaded capture -> conversion -> UI pipeline; unit tests for luminance, color and glyph mapping.
Useful for XAO: separation of pure renderer from host/UI bridge; explicit glyph mapping strategies; CPU baseline and test organization; edge-directional glyph mapping.
Do not copy blindly: Qt/OpenCV are not suitable mandatory dependencies inside the AE AEX; capture/GUI pipeline is irrelevant; newest-frame-wins buffering is unsuitable for deterministic AE offline rendering.
License: repository states MIT; verify exact LICENSE and preserve notice before adapting.
Source: https://github.com/Ruchi2117/ASCII-Art

### B. sunilgentyala/auraascii — WebGL2, MIT
Verified source description: two-pass GPU pipeline. Pass 1 uses a 3x3 BT.709 Sobel kernel to output edge magnitude, angle and luminance to a half-float target. Pass 2 maps cells to a pre-rendered glyph atlas. Atlas is built once, avoiding per-frame CPU text rendering. README states fully client-side and MIT.
Useful for XAO: glyph atlas architecture; separation of edge analysis and glyph composition; edge-aware glyph selection; precompute glyph raster/metrics and reuse immutable atlas.
Risks: browser/WebGL implementation is not a native AE CPU engine; GPU-only assumptions must not become mandatory; inspect shader source before relying on alpha, angle use or exact output behavior.
License: MIT stated in README; verify LICENSE and attribution.
Source: https://github.com/sunilgentyala/auraascii

### C. niccolofanton/morphing-ascii-shader — Three.js/postprocessing
Verified source description: glyph-atlas ASCII/halftone; optional Sobel directional edge glyphs; per-cell temporal memory with exponential smoothing; SDF morph between glyphs; separate ink-bleed/bloom-like pass; film grain with blend modes. Parameters include cell size, glyph scale, charset, variety, invert, color mode, brightness/contrast/gamma, edge threshold/chars, memory/morph, grain and bleed.
Useful for XAO: SDF glyph representation and analytic glyph morphing; separate optional edge and ink-bleed stages; grouped controls.
Critical AE risk: per-cell memory updated as frames arrive is order-dependent. AE may request frames out of order, reverse, concurrently and under MFR. Do not port mutable temporal state into Smart Render. Replace with stateless absolute-time evaluation or precomputed immutable analysis data.
Unknown: verify full license/compatibility and source-level details in LICENSE and code before reuse.
Sources: https://github.com/niccolofanton/morphing-ascii-shader and https://www.npmjs.com/package/@niccolofanton/morphing-ascii-shader

### D. Theovia/ascii-lab — WebGL2 study
Verified source description: samples each cell center, maps luminance to glyph ramp, reads glyph from pre-rendered atlas, composites true RGB or palette. Variants explore Sobel + Difference-of-Gaussians edge detection, directional glyphs, and two-pass ASCII -> FBO -> bloom/aberration/CRT. Per-cell hash thresholds drive a scroll dissolve.
Useful for XAO: reproducible cell-to-atlas mapping; directional edge glyphs; deterministic hash per cell for transitions.
Do not copy: cursor-reactive face deformation and scroll/page interactions are demo-specific. Global UV warping would violate stable-cell identity for most XAO looks.
License: repo states MIT; verify LICENSE and asset rights independently.
Source: https://github.com/Theovia/ascii-lab

### E. POINTLESS — native C++/Qt6 renderer
Verified source description: native image/video renderer with ASCII, halftone, dithering and mosaic modes, layers/blend modes/keyframed animation.
Useful for XAO: compare renderer boundaries, compositing semantics, animation parameter organization and test cases.
Risks: project license is GPL-3.0 according to repository license; do not copy or link code into a proprietary/distributed XAO plugin unless XAO deliberately accepts GPL obligations. Inspect alpha, threading and render-order behavior before treating it as a technical model.
Source: https://github.com/nicolobuselli/POINTLESS

## 3. Recommended native XAO architecture
Shared low-level services (not one generic look):
- SourceSampler: coordinate-correct source color/luminance sampling; center, box average and weighted average.
- ToneMapper: black/white points, gamma, contrast, threshold and optional local adaptation.
- GlyphCatalog: Unicode/grapheme metadata, font fallback, glyph coverage, advance/bearing/line metrics, raster/SDF atlas.
- GlyphAtlasCache: immutable cache keyed by font identity/version, size bucket, charset, raster mode and render scale.
- CellGrid: layer-anchored cell coordinates; independent grid dimensions per pass.
- DeterministicRandom: stateless hash from user seed, absolute time, cell coordinates and pass ID. Never mutable global RNG.
- EmissionMask: independent luminance/coverage mask for optional glow.
- Compositor: explicit alpha/premultiplication and blend semantics.
- MaskSampler: optional Smart Object Tracker mask integration; tracker is not required for ASCII.

Distinct renderers:
1. AsciiRampRenderer — CGO base and standard glyph ramps.
2. AsciiGhostRenderer — glyph field plus separate Rays contribution.
3. LiquidTileTextRenderer — row partitioning, variable tile geometry and text fitting; not a standard cell renderer.
4. MosaicGlyphRenderer — coarse mosaic plus fine glyph passes.
5. RainbowGlyphRenderer — per-cell palette/source color mapping and local emission.
6. ThresholdSegmentRenderer — row/segment geometry, blocks and point accents.
7. PixelDitherGoRenderer is a related pixel-pattern renderer, not a generic ASCII glyph ramp; keep separate if included in this phase.

## 4. Typography and Unicode
- Store text as UTF-8 at the API boundary; validate and decode safely.
- Distinguish Unicode scalar values from grapheme clusters. Combining marks, variation selectors and emoji sequences must not be split blindly.
- Ordinary Arabic text requires paragraph bidi ordering and script shaping. HarfBuzz shapes glyph runs; bidi paragraph ordering needs a separate implementation such as ICU or a platform service.
- Glyph-art mode may intentionally map selected codepoints to visual marks, but label it glyph-art, not natural-language typesetting.
- Missing glyphs need deterministic fallback; do not silently replace all unsupported characters with '?'.
- Text fitting accounts for advance width, bearing, ascent/descent, baseline and clipping.

## 5. Time, determinism, alpha and AE correctness
- No state that advances because a frame happened to render.
- Animation derives from absolute composition/source time and seed.
- If temporal smoothing/history is essential, run it in explicit pre-analysis and store immutable timestamp-indexed data. Never update temporal memory from Smart Render.
- Same frame must render identically under sequential, reverse, random-order and parallel MFR requests.
- Preserve source alpha unless a documented mode intentionally changes it; composite glyph alpha in the correct premultiplied convention.
- Define tone mapping in linear-light or display-referred space; do not mix without explicit conversions.
- Support AE pixel formats with correct rowbytes/stride and ROI offsets; pad atlas glyphs to prevent neighboring glyph bleed.
- Avoid per-pixel heap allocation; preallocate scratch buffers and cap atlas/cache memory.

## 6. Proposed parameter groups (not final UI)
- Grid: cell width/height, spacing, anchor, offset, fit/crop policy.
- Glyph: charset, font, size/scale, weight/style, variety, fit, alignment, invert.
- Tone: brightness, contrast, gamma, black/white point, threshold, edge weight.
- Color: monochrome, source color, tint, palette, per-cell quantization.
- Edges: enable, threshold, orientation glyph set, edge contribution.
- Animation: enable, speed, variation, seed, time quantization.
- Emission: glow enable, source, radius, intensity, threshold.
- Text/tile-only: row height, variable tile width range, corner radius, padding, line spacing, content source.
- Multi-pass-only: independent pass sizes, opacity, blend mode, mask/clipping.
Do not expose every low-level parameter in every look. Share controls only where their semantics are genuinely shared.

## 7. CPU-first performance strategy
- Pre-rasterize glyph atlas on demand; cache immutable glyph bitmaps/SDF.
- Use fast luminance path; avoid Sobel unless edge mode is enabled.
- Compute source samples once per cell, not once per output pixel.
- Restrict atlas charset and resolution; lazy-build additional glyphs.
- SIMD/vectorize tone mapping and cell sampling where safe; keep scalar reference implementation for correctness tests.
- Parallelize independent rows/cells with bounded worker count; avoid nested pools under AE MFR.
- Cache only immutable, fully keyed data; include font/version, charset, grid, render scale, tone settings and source identity.
- Preview quality may reduce sample quality only if cell scale remains stable and final output remains deterministic.
- Benchmark 1080p and 4K on the actual older Intel CPU before claiming real-time performance.

## 8. Required test matrix
1. Glyph atlas: ASCII, Latin extended, Japanese sample glyphs, symbol sets, missing-glyph fallback and font substitution.
2. Arabic: shaping, bidi, joining, diacritics, mixed Arabic/Latin/numbers.
3. Grid: odd dimensions, non-square pixels, offsets, crop/ROI and tile boundaries.
4. Alpha: opaque, semitransparent, zero-alpha colored pixels and premultiplied edges.
5. Color: grayscale ramp, saturated patches, linear/display transforms.
6. Determinism: fixed seed, animated time, random frame order, reverse and MFR.
7. Edges: horizontal/vertical/diagonal lines and corners; directional glyph mapping stability.
8. Cache: font/charset/render-scale change, project reopen and invalidation.
9. Performance: 1080p/4K, 8/16/32 bpc, dense vs restricted charset.
10. AE host: load, apply, preview, render, cancel, save/reopen and multiple instances.

## 9. Legal/reuse gate
- MIT repositories: verify exact LICENSE, copyright holder and included assets before adapting.
- GPL-3.0 POINTLESS: research only unless XAO distribution intentionally complies with GPL obligations.
- Verify npm package license and transitive dependencies before reuse.
- Do not copy font files or source artwork without separate rights.
- Prefer independent implementations from written algorithm descriptions when provenance/license is uncertain.

## 10. Decisions locked for XAO
- CPU-first; GPU acceleration optional, never required.
- Native C++ AE effect; no browser/Qt/UXP runtime dependency.
- No separate Dither Majid Lines effect, UI, controls, presets or source.
- Keep CGO, Ghost, Liquid, Mosaic, Rainbow and Threshold as distinct renderers.
- Liquid is not square-grid ASCII; Mosaic keeps coarse and fine scales; Rainbow is not a global rainbow overlay.
- No mutable per-cell memory in Smart Render.
- Deterministic, layer-anchored cells and alpha-safe compositing.

## 11. Open gates before implementation
1. Reattach/mount the dedicated XAO ASCII folder or archive so every file can be inventoried and compared. Current ZIP absence is a hard evidence limitation.
2. Verify exact licenses from each repository LICENSE before code reuse.
3. Inspect source implementations (not README only) for atlas padding, alpha, edge orientation, random-state behavior and memory ownership.
4. Confirm AE SDK 23.2.1 APIs and MFR contract in the chosen build environment.
5. Establish golden image crops for each XAO ASCII look before coding.
6. Define final UI control mapping per renderer without duplicating meaningless controls.

## Conclusion
The technical direction is clear: shared CPU-first glyph/text infrastructure supporting genuinely different renderers. Public references are useful for architecture and algorithm study, not plug-and-play AE code. The dedicated ASCII folder asset audit remains open until original files are available. Do not claim that the ASCII folder is fully closed.