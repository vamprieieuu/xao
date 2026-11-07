# AuraASCII and ASCII Art Main — Detailed Renderer Audit (Pass 31)

Date: 2026-11-07
Scope: targeted source review of AuraASCII's two-pass WebGL ASCII renderer and the MIT C++ ASCII Art desktop engine. These are independent reference projects; this pass is not an XAO implementation or AE runtime test.

## 1. AuraASCII — two-pass renderer and a confirmed character-index bug

Reviewed:
- `src/engine/AsciiRenderer.ts`
- `src/engine/GlyphAtlas.ts`
- `src/engine/types.ts`
- `src/engine/shaders/edge.frag.glsl`
- `src/engine/shaders/ascii.frag.glsl`
- `src/workers/shader.worker.ts`

### Pipeline
1. Pass 1 computes a Sobel gradient from a 3×3 source neighborhood and writes gradient magnitude, angle and centre luminance into a half-float render target.
2. Pass 2 reads one feature sample per cell, blends luminance and edge magnitude, maps the result to a glyph index, samples the corresponding subregion in a pre-rendered glyph atlas, and composites foreground/background colours.
3. GlyphAtlas deduplicates the input charset and rasterizes it into a square power-of-two Canvas texture. Font and charset changes rebuild the atlas.
4. The render loop is driven by requestAnimationFrame and the source supports PNG export and plain-text ASCII extraction.

### Confirmed character ordering bug
- The atlas comment and default charset define index 0 as the densest glyph and the last index as the sparsest glyph.
- The shader computes `charIndex = floor(intensity * (charCount - 1))`.
- Therefore, as intensity increases, the shader selects later, sparser glyphs, which is opposite to the comments' stated mapping (high intensity/edge -> dense glyph at index 0).
- The shader comments and code disagree. XAO must define one tested convention (e.g. darkness-to-density or brightness-to-density) and include a monotonic glyph-ramp regression test.

### Other limitations
1. **Angle is computed but unused.** The edge pass stores Sobel angle in G, but the ASCII pass reads only R and B. The claimed directional edge glyph feature is not implemented in this shader version.
2. **Alpha is opaque.** The shader writes alpha 1.0 and always composites a background colour. XAO needs transparent glyph-only mode and explicit background/paper mode with correct source alpha.
3. **Sobel cost is repeated per source pixel.** The first pass computes 8 neighboring texture reads per output pixel, even though the second pass consumes only one sample per cell. XAO can compute features at cell resolution (or use a reduced feature buffer) where quality permits.
4. **Sobel borders rely on sampler state.** Neighbor UVs are not explicitly clamped. XAO must specify clamp/reflect/transparent edge policy.
5. **Luma is BT.709 coefficients, but no explicit linearization is visible.** Sampling texture RGB directly and applying luma coefficients may be gamma-encoded depending on texture setup. XAO needs an explicit working-space policy.
6. **Atlas dimensions are based on a reference 'M'.** Other fonts/glyphs may have different advance widths, bearings and ascenders/descenders. Fixed glyphW/glyphH and Canvas fillText at top-left can clip or misalign glyphs, especially proportional fonts and non-Latin scripts.
7. **Unicode is still not typography shaping.** `[...charset]` iterates Unicode code points (better than UTF-16 indexing), but does not segment grapheme clusters, shape Arabic/Indic scripts, handle bidi, or build a glyph atlas from HarfBuzz glyph IDs.
8. **Atlas grows as a single square texture.** Large multilingual character sets may exceed practical texture dimensions. XAO should use paged atlases and explicit size limits.
9. **DPR and grid dimensions require care.** Resize uses CSS dimensions to compute cell counts while the render target is sized in device pixels. This can be a deliberate CSS-pixel cell size, but must be consistent across render resolution, source resolution and AE render scale.
10. **GPU-only browser implementation.** It is not a CPU renderer or AE adapter. Only the algorithmic decomposition should inform XAO.

## 2. ASCII Art Main — independent C++ CPU engine

Reviewed the engine design and implementation files:
- `GlyphMapper.h`, `Luminance.h`, `Ramp.h`, `RenderConfig.h`
- `AsciiRenderer.cpp/.h`, `FrameConverter.cpp/.h`
- `AsciiFrame.h`, `Color.h`, unit tests and project README.

### Strengths
- Core engine types are separated from Qt/OpenCV capture and GUI code.
- The renderer has explicit luminance, colour and edge strategies.
- Edge mapping uses Sobel gradient magnitude and direction to choose among directional glyphs such as vertical, horizontal and diagonal marks.
- Adaptive detail, local contrast enhancement and unsharp masking are treated as input preparation rather than hidden glyph-selection behavior.
- The app separates capture, conversion and UI painting; its latest-frame buffer intentionally drops stale frames rather than accumulating latency.
- Unit tests cover luminance, colour, glyph mapping and the frame buffer.

### Porting constraints
1. The GUI uses a fixed monospace font (Cascadia Mono) for painting. It is not a general font-atlas system and does not provide Unicode shaping or per-glyph metrics.
2. The renderer outputs an RGB QImage in the inspected path; alpha/premultiplication behavior is not an AE-ready contract.
3. The capture and latest-frame-wins architecture is appropriate for live preview but not for deterministic AE offline rendering, where every requested frame must be reproducible.
4. OpenCV/Qt GUI and capture dependencies should not enter the XAO .aex binary. Reimplement the pure algorithmic parts against AE pixel buffers.
5. Edge enhancement and CLAHE can materially alter image appearance before mapping; keep these as explicit optional source-analysis stages, not mandatory preprocessing.
6. A ramp-based luma mapping and a directional edge strategy should be independently selectable, not mutually hidden behind one opaque "ASCII" mode.

## 3. XAO ASCII design decisions reinforced by this pass

- Add explicit mapping convention and ramp orientation, validated by tests.
- Keep luminance ramp, structural glyph matching and directional edge glyphs as distinct strategies.
- Compute cell features once, then render glyph pixels from a stable atlas.
- Use per-glyph metrics and shaped glyph IDs, paged atlases, and a proper bidi/shaping pipeline for complex scripts.
- Preserve alpha and offer transparent glyph output, paper/background fill and source composite as separate modes.
- Anchor grid phase in source coordinates; make cell aspect ratio explicit.
- Keep preview frame dropping separate from final AE rendering. Final render must be deterministic and must not depend on wall-clock animation loops.

## 4. Smart Object Tracker integration

A shared soft object mask can be sampled during cell analysis:
- Ignore outside-mask pixels when calculating a cell's representative luma/colour.
- Scale glyph coverage by the cell's mask coverage, with a configurable minimum coverage threshold.
- Optionally align a local grid to the tracked object's bounding box or centroid, but keep source-anchored grid as the stable default.
- Use object motion metadata to bias directional glyphs or animate glyph selection only when explicitly enabled.

AI inference remains in the separate analysis stage, never inside the ASCII render callback.

## 5. Licensing boundary

The ASCII Art Main project declares MIT. Preserve its license notice if code is reused. AuraASCII's project license must be checked in the archive before any code reuse; this pass uses it as a behavior/architecture reference only.

## 6. Exclusion and status

The separate Dither Majid **Lines** effect remains excluded. Directional edge glyphs within ASCII are not that standalone Lines effect.

This is a targeted source review, not completion of all archive files or all video frames. No XAO binary was built and no After Effects runtime test was performed.
