# Aciify archive — Folder 05: codes

**Source:** `aciify.zip` → `aciify/codes/`  
**Inventory:** 20 ZIP entries (19 text files + folder entry), ~131 KB.  
**Role:** shader snippets, ASCII glyph bitmaps/palettes, rendering experiments and notes. No code integrated into XAO.

## File catalog and findings

| File | Contents / reusable idea |
|---|---|
| `6x6 ascii.txt` | Packed 6×6 bitmap glyph font in uint words (108 32-bit values), plus a 96-character palette ordered by luminance. Shadertoy-style sampling/render scaffold. Compact glyph atlas alternative to font rasterization. |
| `alot of ascii codes.txt` | Collection of shader fragments: cell-based source sampling, average/brightness-to-glyph selection, 8×8 glyph rendering, coverage compensation, EGA dithering/color, Sobel edge orientation and directional glyph choice. Multiple snippets appear concatenated; treat as experiments, not one clean compilable shader. |
| `army ascii.txt` | Andrew Wild / akohdr 2016 pedagogical font/video shader. Configurable terminal resolution, scroll/speed, colored ink, temporal flashing and antialiased line primitives; Bézier distance functions and line stylization. Header declares CC BY-NC-SA 3.0—noncommercial/share-alike constraints matter. |
| `ascii art.txt` | movAX13h bitmap-to-ASCII fragment shader. Encodes each 5×5 glyph as integer bit pattern; cell sample → luminance thresholds → glyph bit mask. Includes limited and expanded A–Z/0–9 sets. Cited original shader and update history. |
| `ascii char.txt` | Character/glyph lookup and bitmap/character mapping notes; preserve as lookup reference. |
| `ascii filter very good.txt` | Larger ASCII filter experiments combining cell sampling, luminance/glyph selection, edge/Sobel and color paths. Read as multiple variants/snippets; not a standalone validated program. |
| `ascii on moving objects.txt` | Temporal/motion-oriented ASCII experiments; useful research lead for frame-to-frame behavior, not verified stable motion tracking. |
| `ascii shader.txt` | Shader snippets and character rendering routines; source-level research only. |
| `ascii space.txt` | Space/cell/grid-related ASCII notes and shader fragments. |
| `ascii term.txt` | Terminal-style ASCII rendering/configuration snippets. |
| `colorfull ascii.txt` | Color-preserving ASCII output experiments: sample original RGB and apply glyph mask/coverage. |
| `donate ascii.txt` | Empty file (0 bytes). |
| `gragh ascii.txt` | Small graph/character palette or mapping snippet; preserve as a minor reference. |
| `hexa ascii.txt` | Hex/packed glyph representation and shader experiments. |
| `permeds ascii.txt` | Permutation/noise/randomized ASCII experiments; inspect before reuse for exact algorithm. |
| `rbg ascii.txt` | RGB variant/fork of movAX13h/Silexars ASCII shader. Uses luminance thresholds and 5×5 integer glyph bitmaps, with cell size 16 in the shown version. |
| `remakes ascii.txt` | Code-golf/refactor notes: replace long threshold trees with arrays; bit tests via shifts; simplify 5×5 glyph lookup; demonstrates compact lookup table approach. |
| `shape noise.txt` | MIT-licensed Inigo Quilez oriented-box SDF + 3D simplex-noise GLSL material; references patriciogonzalezvivo/glslViewer recreation. Preserve MIT notice if any portions are reused. |
| `stera ascii.txt` | Compact 5×5 glyph-bit shader, Rec.709 luminance, cell/pixel size controls and brightness thresholds selecting glyph bit patterns; monochrome or RGB mask mode. |

## Technical patterns retained for XAO

1. **Cell sampling:** snap pixel coordinates to a character-cell origin, sample source once per cell, and derive a cell-level intensity/color.
2. **Luminance:** examples use both legacy weighted RGB `0.3/0.59/0.11` and Rec.709 `0.2126/0.7152/0.0722`; choose deliberately and account for color-space/linear-vs-sRGB.
3. **Glyph selection:** brightness threshold ladder, ordered glyph palette, packed 5×5/6×6 bitmap, or font-atlas sampling. Palette order should be measured by glyph coverage/visual density, not assumed from character code.
4. **Bitmap decode:** integer bit fields and bitwise tests provide compact procedural glyph masks; 5×5 patterns fit in 25 bits. Verify bit orientation and coordinate inversion carefully.
5. **Coverage/color:** mask glyph against source RGB; coverage compensation can counter glyph density and improve perceived brightness. Avoid clipping/saturation artifacts.
6. **Edge-aware characters:** Sobel magnitude/orientation can select `-`, `|`, `/`, `\\` or edge-focused symbols; use thresholds with hysteresis/soft transitions to reduce flicker.
7. **Temporal experiments:** animated noise/flashing/scrolling can create motion looks, but deterministic frame-time/seed handling is required for AE scrubbing and MFR.
8. **Procedural geometry:** SDF/noise snippets are separate effect building blocks—not automatically ASCII conversion code.

## Licensing and source cautions

- `army ascii.txt` explicitly states Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported; it is not suitable for commercial reuse without permission/appropriate terms.
- `shape noise.txt` includes an MIT notice; retain copyright/license text for reuse.
- `ascii art.txt` and `rbg ascii.txt` cite movAX13h and Silexars origins; check original licenses/attribution before copying.
- Other files are mixed snippets and do not all state a license. Archive inclusion is not permission to redistribute.
- ShaderToy `mainImage` snippets are not AE C++ code. Any port requires translating texture/resolution/time/input assumptions into XAO's CPU/SmartFX path or a supported AE GPU path.

## Limits
- All 19 text files were catalogued; representative shader source and key glyph/luminance sections were inspected. This report is conceptual/source analysis, not a full compile/test of every concatenated snippet.
- No shader execution, image parity, performance benchmark, or AE runtime test was performed.
- Original files remain in the archive; nothing was copied into XAO source.
