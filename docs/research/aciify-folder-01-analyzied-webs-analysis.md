# Aciify archive — Folder 01: `analyzied webs`

> Analysis date: 2026-11-16  
> Source: `aciify.zip`, folder `aciify/analyzied webs/`  
> Purpose: web ASCII/effect references for XAO.

## Inventory

- `index.html` (~327 KB): ASCII — Everything is Characters web app (HTML + inline JavaScript).
- `saveweb2zip-com-filtr-org-uk.zip`: Filtr web effects site archive.
- `saveweb2zip-com-ultimatedesigntools-com.zip`: Ultimate Photo Effects Lab archive.
- Extracted JS: `main.js` (~236 KB, 4,917 lines), `filtr_inline.js` (~2 KB), `ult_inline.js` (~62.6 KB, 1,119 lines).
- Archive integrity checks passed.

## ASCII — Everything is Characters

Main JavaScript contains a substantial ASCII/generative renderer:
- Canvas/glyph-atlas rendering and grid/cell mapping.
- Typed arrays and seeded Mulberry32 randomness.
- 2D image and word/text modes plus 3D/generative forms (donut, cube, sphere, knot, pyramid and additional matrix/plasma/life/fire/flow/stars/tunnel-style engines).
- Z-buffer/depth-related rendering for 3D forms.
- Presets, controls, animation, project/state handling and export paths.
- Export formats include PNG/GIF/text/ANSI (as present in app code).

Useful concepts: seeded randomness, cell/glyph atlas, multiple source/engine modes, depth-aware ASCII, and multi-format output. This is browser JavaScript, not AE SDK code.

## Filtr

Saved web app is a WebGL2 retro/image-video effects experience. Feature families visible in the bundle/site include ASCII, dithering, halftone, bloom/glow, grain, scanlines and chromatic aberration. Bundle is roughly 337 KB.

**Inspection limit:** bundle is minified/compiled; it was extracted and examined at bundle/feature level, not fully deminified and audited statement-by-statement. Exact shader formulas and every UI branch are not claimed.

## Ultimate Photo Effects Lab

The app implements an effect-stack workflow with approximately 17 effect families:
Dither, Halftone, Duotone, Threshold, Stipple, Crosshatch, Edges, Mosaic, Pixel Sort, Scanlines, Chromatic, Glitch, Noise, Vignette, Overlay and ASCII, plus stack order/opacity/blending, presets, random seed, and PNG/SVG/JSON export paths.

Useful XAO concepts: non-destructive stack, per-effect controls, seedable randomness and separate export formats.

## Fonts and UI

Font families referenced include IBM Plex Mono, Chakra Petch, DM Sans, JetBrains Mono and Anton. CSS and font references were reviewed; font binary glyphs were not individually inspected.

## XAO takeaways

- Keep ASCII, dither and halftone as composable but distinct effect stages.
- Support seeded random behavior so results can be reproduced.
- Design a non-destructive effect stack with parameters and presets.
- Use glyph atlases/cell mapping for efficient ASCII output.
- Treat browser implementations as algorithm/UI references, not drop-in AE plug-ins.

## Limits / verification

- Files and archives extracted; ZIP integrity checked.
- The main ASCII source was inspected at code/function level; Filtr's minified bundle was not fully decompiled.
- Font binaries were not glyph-by-glyph audited.
- No browser runtime or build test was claimed.
- No source code was integrated into XAO by this report.
