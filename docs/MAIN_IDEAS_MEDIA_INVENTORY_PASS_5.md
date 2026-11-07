# XAO MAIN IDEAS Media Inventory — Pass 5

Date: 2026-11-07

All nine supplied video files were opened and decoded programmatically for this inventory. A frame-difference scan was run over every decoded frame. This is not yet a manual visual sign-off of every frame at full resolution.

## Video inventory

| Reference | Decoded frames | Approx. average FPS | Duration |
|---|---:|---:|---:|
| Array / Plugin settings | 866 | 43.60 | 19.86 s |
| ASCII CGO | 234 | 49.35 | 4.74 s |
| ASCII Ghost | 248 | 47.54 | 5.22 s |
| Golden Glow Halftone | 276 | 48.71 | 5.67 s |
| Liquid ASCII | 200 | 51.50 | 3.88 s |
| Mosaic ASCII | 195 | 50.87 | 3.83 s |
| PixelDitherGo | 145 | 49.18 | 2.95 s |
| Rainbow ASCII | 205 | 50.20 | 4.08 s |
| Threshold ASCII | 145 | 50.00 | 2.90 s |

Total decoded frames: 2,514.

Note: container metadata reports nominal stream rates around 60/240 fps for some recordings, while decoded average rates differ because the recordings are variable-frame-rate. Use actual presentation timestamps for any future frame-accurate reference extraction; do not assume a fixed 30 or 60 fps timeline.

## Written notes extracted from MAIN IDEAS

### Liquid ASCII
- Cells are rounded rectangles with independent width and height.
- Each rectangle uses a background color sampled from the underlying source image.
- Japanese characters/words or random glyph strings move/change randomly within cells.
- Controls requested: hide words, enlarge text, change font, replace text with random symbols or historical/foreign scripts, and control text color.
- The user's target is to match the visual behavior shown in the clip, not merely place a uniform ASCII grid.

### ASCII Ghost
- Individual glyphs, symbols and numbers sample their own color from the source image.
- The look includes a Rays/light-beam component; this must be composable with the glyph result.

### Rainbow ASCII
- Explicitly requests a combined ASCII + Glow + Rays look, with unusual/multicolor glyphs and multicolor glow/rays.

### ASCII CGO
- Requests glow around selected glyphs/characters/numbers, not every glyph.
- User wants control over which glyphs glow, with fixed or randomized selection/position, and control over glow color.

### Mosaic ASCII
- Mosaic cells plus glow and reduced saturation.
- Glyphs vary in size; some are large and colorful, others tiny. User asks for detailed control of this hierarchy and random movement.

### Threshold ASCII
- Threshold-derived field of moving lines, rectangles and squares, with extensive geometry and color controls. This is a separate Threshold/ASCII reference, not the excluded Dither Majid Lines effect.

### Golden Glow Halftone
- User specifically wants this to remain one Halftone engine with a distinctive golden/orange glow treatment, not a separate Glow-Halftone engine.

### PixelDitherGo
- User's note says they cannot fully describe the look and asks for close visual analysis of the reference clip, including how it is formed and animated. This reference remains pending manual frame-by-frame visual sign-off.

## External links supplied in THE WEBS.txt

- GLCHLAB: https://glchlab.com/
- Effect.app: https://effect.app/explore
- ASCII: https://ascii.krackeddevs.com/#e=torusknot&c=photo&k=ice&sp=50&ce=8&ct=125&aw=1080&ah=1080
- Nexus: https://nexus.synkit.net/phone?claim=lunar-weave-xrvjgkqf,azure-orbit-trfixa3r,neon-orbit-j9gxgnwi,golden-crystal-55zbj7x3,saffron-contour-fjpmvsy7&from=claim&utm_source=instagram&utm_medium=manychat&utm_campaign=patternmerge-linerpro-pixelcrusher-shapehalftone-cmykprint

## Remaining visual-analysis work

- Review contact sheets of all 2,514 frames and annotate exact control/visual changes per clip.
- Decode the long Array settings recording at presentation timestamps and map each control to the visible result.
- Inspect all still images and settings screenshots alongside their corresponding clips.
- Compare the observed result against candidate engine algorithms and define measurable golden-image targets.
