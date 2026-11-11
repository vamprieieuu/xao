# XAO ASCII — Reference Recovery & Acceptance Brief
Date: 2026-11-11
Repository: https://github.com/vamprieieuu/xao
Active branch: xao/recovery-baseline-2026-11-10
Scope: ASCII engine only. This records recovered user requirements and supplied reference inventory. It is not a claim that the engine is complete.

## Product identity and architecture
- Plugin display name must be XAO, not XAO ASCII.
- ASCII is the default/primary engine when the effect is applied.
- ASCII must be independently disableable so the user can run Halftone alone; other engines must be independently enabled/disabled and composable.
- Planned engines in the latest user brief: ASCII, Halftone, Dither, Glow, Rays.
- Complete ASCII to reference-matching quality before moving on to the next engine.
- Preserve the working native AE build/SmartFX adapter while replacing and expanding the visual engine. Build success is not visual acceptance.
- MAJEED Dither is strictly a build/SDK architecture reference; do not port its effects or assets.

## User-supplied Library assets recovered
1. /XAO.zip — 150,137,425 bytes.
   - XAO/MAIN IDEAS/ contains visual concept folders and their videos, stills, and explanatory text.
   - XAO/MAIN IDEAS/THE WEBS.txt lists web references.
   - XAO/ascii [ main ]/ contains ASCII AEX references, C exports, and multiple open-source projects.
2. /main gradients files.zip — 4,587,722 bytes. Contains additional Main Gradients reference material, including Retratone v1.0.5 and other material; use only where relevant to ASCII/typographic/color behavior, not as permission to copy proprietary source.
3. /fonts.zip — 2,346,514 bytes. Contains grouped Arabic, English, and weird/ornamental fonts. Treat these as actual user-supplied glyph-source assets to inspect and turn into font/charset presets/atlases, subject to font licensing and embedding restrictions.

## Main Ideas — ASCII visual requirements recovered from user notes
### Ascii cgo
- Dense ASCII made from letters, numbers, and symbols that change rapidly/randomly.
- Some glyphs alone receive glow, not all glyphs.
- Controls to choose which glyphs glow, relocate glow to chosen glyphs, keep glow locations fixed or random, and control glow colors.
- A surrounding glow/outline around the subject is also visible and needs detailed study.
- User supplied AEX and C++ references for glow behavior.

### Ascii ghost
- Random letters/symbols; each glyph takes color from the corresponding underlying image/background region.
- Includes rays/light-beam behavior; reproduce the combined look and allow it to be controlled.

### Liquid ascii
- Image is partitioned into rectangular message-like panels/blocks.
- Each rectangle contains moving/random Japanese characters/words; blocks inherit colors from the underlying image.
- Controls requested: rectangle width/height, hide/show words, glyph/text size, change font/charset to random symbols or old/ancient language-inspired glyphs (including Japanese), and text color.
- Must not reduce this to a single uniform grid of identical cells.

### Mosaic ascii
- ASCII combined with a mosaic layer, glow, and low saturation.
- Glyphs include letters, symbols, and numbers, animated/randomized.
- Glyph scale varies substantially: some large and some very small; larger glyphs are colorized.
- User expects fine-grained controls over these details.

### Rainbow ascii
- ASCII mixed with glow and rays.
- Unusual vivid colors, colored rays and colored glow are central, not optional generic finishing effects.

### Threshold ascii
- Threshold-based look with lines, rectangles, and randomly moving squares/rectangles.
- Requires detailed controls for shapes, movement, and colors.

### Other folders in MAIN IDEAS
- Array_ includes raw image, result image, and plugin settings screen recording.
- Dither asci_ and Pixeldithergo are additional concepts to inspect; Pixeldithergo note explicitly asks for frame-by-frame analysis of how the effect is made and moves.
- Golden glow halftone_ is a separate Halftone concept: a distinctive glow and color treatment should be integrated into the Halftone engine, not treated as the primary ASCII engine.
- Shape Halftone/ and Typeset/ contain preset/settings reference images; not ASCII-first but relevant to later engine/typographic study.

## Required reference analysis procedure
- For every Main Ideas clip, inspect the whole clip frame-by-frame (or sufficiently dense sampling with documented timestamps), not just a single screenshot.
- Identify split-screen Before/After divider, isolate source and processed halves, and compare the same image region.
- Record grid/cell geometry, glyph family, glyph size distribution, sampling/color mapping, edge behavior, masks, glow/rays, motion, randomization, temporal behavior, and compositing.
- Distinguish what is directly visible from inferred implementation; do not claim exact hidden algorithm without evidence.
- The Webs file lists:
  - https://glchlab.com/
  - https://effect.app/explore
  - https://ascii.krackeddevs.com/#e=torusknot&c=photo&k=ice&sp=50&ce=8&ct=125&aw=1080&ah=1080
  - https://nexus.synkit.net/phone?claim=lunar-weave-xrvjgkqf,azure-orbit-trfixa3r,neon-orbit-j9gxgnwi,golden-crystal-55zbj7x3,saffron-contour-fjpmvsy7&from=claim&utm_source=instagram&utm_medium=manychat&utm_campaign=patternmerge-linerpro-pixelcrusher-shapehalftone-cmykprint&fbclid=PAVERFWAVEygFleHRuA2FlbQIxMABwZG9mAmZkaWQWUQo6FKtvXx4w_EY5UiMuoDN0km5hCXNydGMGYXBwX2lkDzEyNDAyNDU3NDI4NzQxNAABp2O6__bC5Qjb7GKCHkTifdyYJgvjHb8zgBjoTB6nt4Yc5Qm01t-L1OL8iYAJ_aem_7b35oKcGBJqyOw1UWi2rqA
- Website inspection must record actual behavior, controls, rendering characteristics, and limitations. Do not assume every URL is a relevant ASCII engine without checking.

## ASCII plugin/source inventory in XAO.zip
### Binary and reverse-engineering references
- aex/CratesASCII.aex + c+/CratesASCII.aex.c
- aex/L3tt3rM4pp3r2.aex + c+/L3tt3rM4pp3r2.aex.c
- aex/OVN_ASCII.aex + c+/OVN_ASCII.aex.c
- aex/S1AsciiArt.aex + c+/S1AsciiArt.aex.c
- Treat C exports as decompiler output, not authoritative original source. Trace functions/parameters and validate behavior before translating concepts.
- Do not copy proprietary binary code or decompiled implementation verbatim. Extract observable behavior, parameter contracts, data structures, and algorithmic insights only.

### Open-source folders present
- ASCII Art main [open source] — C++ project with GlyphMapper, Luminance, Ramp, RenderConfig, AsciiFrame, color/pipeline/rendering and tests.
- ascii ofx [open source] — OpenFX ASCII implementation and 8x8 font header.
- auraascii master [open source] — WebGL/GLSL renderer, glyph atlas, edge shader, custom presets and controls.
- glyphblocks ofx [open source] — Glyph-block rendering implementation.
- morphing ascii shader [open source] — ASCII shader reference with animated demos for bleed, blur, brightness, cell size, color mode/variation, contrast, edges and related behaviors.
- pointless [open source] — C++/Qt app with ASCII, Dither, Halftone, Mosaic renderers, GPU shaders, animation and tests. Its repository license is GPL-3.0; do not copy its code into a differently licensed closed-source XAO distribution without resolving license obligations.
- Additional source candidates named in prior analysis: ASCII Art Camera (native C++/OpenCV), GLIF, Asciify. Verify exact source presence, version, license, and algorithm before relying on prior summaries.

## Recovered research targets / algorithmic direction
- Do not select glyphs only from average cell brightness.
- Investigate shape-aware glyph matching: compare source-cell structure/edge distribution with rendered glyph masks; use glyph coverage/ink distribution and directional features.
- Glyph atlas/font rasterization with custom character sets.
- Edge preservation and directional glyph mapping.
- Adaptive cell resolution and variable glyph scale.
- Color-aware glyph mapping: glyph color should sample the local underlying image region; support tint/uniform color/background/blend controls as separate modes.
- Temporal stability for video: stable glyph assignment/randomness across adjacent frames; animated modes must be deterministic from seed/time and avoid arbitrary flicker.
- Optional animated character cycling/randomization with explicit speed, amount, seed, and fixed-vs-random behavior.
- Multi-style layout modes: regular grid, variable-size glyph composition, rectangular text panels, mosaic, threshold/shape overlays. These should be deliberate modes/controls, not one generic grid.
- Per-glyph selective glow with mask/selection rules, fixed/random placement, color and intensity controls; separate subject halo/outline glow if supported by reference.
- Rays are a separate controllable layer/engine that can be combined with ASCII.
- Support custom glyph sources including supplied Arabic/English/weird font families and ASCII/Japanese/other character sets, with correct Unicode shaping/rasterization where applicable.

## Existing XAO ASCII implementation — known gap
- Current engine is an early CPU 5x7 raster glyph-density ramp with ten patterns, average cell luminance selection and average cell color.
- Current controls include cellSize, glyphScale, contrast, brightness, invert, colorize, preserveCellAlpha, ink and paper.
- It is not yet a true typographic/font-atlas ASCII engine, not shape-aware, and does not implement the user-requested styles above. It is a foundation only and must be substantially replaced/extended.
- The native AEX build/PiPL/SmartFX pipeline has passed structural verification; this is separate from visual-reference acceptance and does not prove a full After Effects runtime test.

## First ASCII completion milestone (acceptance gates)
1. Reference inventory: every ASCII-related clip and still assigned an ID; timestamps/panels and visible traits documented.
2. Source audit: each supplied AEX, C export, open-source project, README, license, dependency and relevant algorithm reviewed; record what is reusable, what must be reimplemented, and why.
3. Font audit: enumerate supplied fonts, inspect glyph coverage and licensing; create font/charset atlas pipeline and preview sheets.
4. Engine design: document modes and parameter schema before coding.
5. Implement a real glyph raster/atlas system and multiple mapping strategies (luma baseline, shape-aware, edge/directional, color-aware), then the user-specific styles.
6. Build deterministic video behavior and selective glow controls; add image/video golden tests.
7. Compare XAO outputs against each reference with matched source frames and recorded visual differences.
8. Only call ASCII complete when all user-visible reference criteria are satisfied and verified in AE; build success alone is not acceptance.

## What is still needed from the user
- No new uploads are currently required: the XAO, Main Gradients, and Fonts archives are present in the Library and were inspected at the archive/index level.
- Do not ask the user to repeat the explanations already recorded in Main Ideas text files or previous conversations.
- Ask a user clarification only if a genuinely ambiguous visual behavior remains after frame analysis.
