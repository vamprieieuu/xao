# XAO Focused Audit — AuraASCII WebGL Engine — Pass 14

Date: 2026-11-07

## Scope

Direct source review of the supplied AuraASCII project:
- `AsciiRenderer.ts`
- `GlyphAtlas.ts`
- `edge.frag.glsl`, `ascii.frag.glsl`, `common.vert.glsl`
- `types.ts`, preset definitions, render-target setup and resize lifecycle

The project is MIT-licensed. It is a React/Three.js/WebGL2 application; the browser UI, DOM canvas, animation loop and WebGL objects are not portable into a native AE plugin.

## 1. Rendering pipeline

AuraASCII uses a two-pass GPU pipeline:

1. **Edge pass:** samples a 3x3 source neighborhood, computes BT.709 luminance, applies Sobel X/Y kernels, writes gradient magnitude, gradient angle and center luminance into an RGBA edge buffer.
2. **ASCII pass:** determines the cell index for each output pixel, samples edge/luminance at the cell center, blends luminance and edge magnitude using Edge Weight, maps the result to an ordered glyph index, samples the glyph atlas at the matching within-cell coordinate, and composites foreground glyph color over background.

The edge angle is stored but not used by the current ASCII pass; it is reserved for directional glyph selection. The source texture uniform in the ASCII pass is also currently unused.

## 2. Glyph atlas

- Characters are deduplicated while preserving order using JavaScript code-point iteration (`[...charset]`), which is better than UTF-16 indexing for supplementary code points.
- The browser measures `M` to estimate glyph width, assumes line height = 1.2× font size, and draws each character into a power-of-two canvas atlas.
- This is adequate for simple monospace Latin glyph sets, but it is not a robust typography system: variable-width glyphs, fallback fonts, combining marks, grapheme clusters, Arabic joining, BiDi, emoji sequences and font-specific vertical metrics are not handled.
- The atlas uses browser Canvas/system font resolution, so glyph appearance can vary between machines and browser environments.

## 3. Verified limitations / correctness issues

1. **Output is always opaque:** the final fragment shader writes `vec4(color, 1.0)`; source alpha is not propagated. XAO must preserve alpha or provide an explicit background-composite mode.
2. **Directional edge data is unused:** the edge angle is calculated and stored but has no effect on the selected character. Direction-aware glyph mapping is a future concept, not an implemented behavior in this project.
3. **Color sampling mode is absent:** the source sampler in the final pass is unused; the renderer currently outputs a uniform foreground and background color rather than per-cell sampled source colors.
4. **Density direction is semantically fragile:** the shader assumes the charset is ordered dense-to-sparse and maps increasing intensity to increasing glyph index. The supplied defaults/presets must maintain this ordering or the tonal mapping reverses.
5. **Contrast is a simple multiplier:** `intensity * contrast` is clamped; it is not a midpoint-centered contrast curve and can crush highlights quickly.
6. **Glyph dimensions assume monospace:** width is estimated from `M`; glyphs with different advances or bearings can be clipped/misaligned. The shader stretches each atlas cell across the output cell.
7. **Browser color handling is implicit:** there is no explicit shared working-space contract across texture upload, FBO and output. XAO needs a defined linear-light/display-referred policy.
8. **Full-frame GPU buffers and per-pixel atlas lookups:** the two-pass approach is efficient on capable GPUs, but XAO must have an equivalent CPU implementation and a memory/performance budget for older Intel systems.
9. **Animation loop is wall-clock driven:** requestAnimationFrame/FPS loop is appropriate for an interactive browser demo, not deterministic AE frame rendering. XAO animation must be a pure function of AE time and parameters.

## 4. XAO decisions

- Keep the two-stage conceptual pipeline (edge analysis, then glyph composition) as a useful design.
- Add directional glyph selection only as an actual implemented mode, using edge angle and a documented orientation mapping.
- Support per-cell sampled color as a distinct color mode, rather than claiming the current AuraASCII shader already does it.
- Preserve source alpha and define explicit premultiplied-alpha behavior.
- Replace browser font metrics with a native font backend, controlled licensed font loading, proper shaping/BiDi and stable glyph atlas caching.
- Use AE time, not wall-clock/requestAnimationFrame state, for every animated result.
- Build and benchmark the CPU path first; GPU is an optional acceleration path, not a requirement.

## 5. Status

This pass covers the listed AuraASCII rendering/atlas/shader files and selected preset/config definitions. It does not constitute a complete line-by-line review of all 47 files in the AuraASCII folder, a native AE build, or runtime testing. Other ASCII sources and all remaining XAO groups still require audit.
