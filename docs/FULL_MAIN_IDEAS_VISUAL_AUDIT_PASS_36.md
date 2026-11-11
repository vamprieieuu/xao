# XAO Full MAIN IDEAS Clip Audit — Pass 36
Date: 2026-11-07
Scope: Consolidated audit of all nine videos in XAO/MAIN IDEAS, including full decode verification, denser temporal inspection, visual mid-frame inspection, and a more complete Array settings inventory.
Status: all supplied video frames decoded successfully in this pass. This is not a claim of manual human inspection of every individual frame or pixel-perfect source-code reconstruction.

## 1. Full inventory and decode verification

| Reference clip | Decoded frames | Dimensions | Duration |
|---|---:|---:|---:|
| Array / Plugin settings | 866 | 828×1792 | 19.8617 s |
| ASCII CGO | 234 | 466×474 | 4.7417 s |
| ASCII Ghost | 248 | 656×354 | 5.2167 s |
| Golden Glow Halftone | 276 | 214×386 | 5.6667 s |
| Liquid ASCII | 200 | 304×374 | 3.8833 s |
| PixelDitherGo | 145 | 310×374 | 2.9483 s |
| Rainbow ASCII | 205 | 298×392 | 4.0833 s |
| Mosaic ASCII | 195 | 296×368 | 3.8333 s |
| Threshold ASCII | 145 | 294×376 | 2.9000 s |
| **Total** | **2,514** | — | **53.335 s** |

All 2,514 frames were successfully decoded and passed through a frame-difference scan. The eight effect examples are split before/after comparisons: the left side is source, the right side is the effect. The central vertical divider and its plus handle, as well as pause controls, are recording UI and not part of the visual effect.

The MOV files report nominal 60 fps but contain approximately 47.54–51.50 decoded frames per second on average. The Array MP4 has approximately 43.60 decoded frames per second. These are not reliable fixed-rate animation clocks. XAO must use AE's rational time/time-scale values and absolute render time.

## 2. Array / Plugin settings — expanded control inventory

Reference: ScreenRecording_10-24-2026 22-24-15_1.MP4
This recording is primarily a mobile browser settings-panel walkthrough. The actual Array preview is small; the recording is most useful for control hierarchy and UI behavior, not for reverse-engineering the renderer's exact output.

### Main controls visible
- Intensity (shown at 100%).
- Blend (shown as Normal).
- Show source toggle.
- Shapes mode: Light / Random.
- Level 1, Level 2, Level 3; each has an enable/color swatch, selected shape slots, an add-shape button and a remove-level control.
- Add level button.
- Edges: separate shape slot collection with an add button.
- All sizes (shown at 1.00).
- Color Mode menu: Preserve, Sample Source, Override, Palette, Gradient.
- Random toggle.
- Slots count (shown as 3).
- Palette entries (visible example values): #2A2A2A, #8C8C8C, #FF6A00.
- Background toggle/color.
- Cell Size (shown as 25).
- Rotation Jitter (shown as 0°).
- Scale Jitter (shown as 0%).
- Detailing (shown as 0%).
- Clump toggle/selector.
- Amount (shown as 20%).
- Chaos (shown as 3×).
- Clump By (shown as Random).
- Invert toggle.
- Empty Below (shown as 0%).
- Contrast (shown as 1.00).
- Gamma (shown as 1.00).
- Edges enable/color control is visible near the bottom of the panel.

### Blend menu items directly visible
Normal, Darken, Multiply, Color Burn, Lighten, Screen, Plus Lighter, Color Dodge, Overlay, Soft Light, Hard Light. OCR and earlier captures also indicate Difference, Exclusion, Hue, Saturation and Color in the expanded list; verify exact availability in the live reference if this list is ever reproduced.

### Shape library
The shape picker is a large grid of white vector-like stamp thumbnails. It contains geometric primitives, quarter-circles, rings, arcs, crosses, stars, chevrons, stripes, checker patterns, stepped blocks and directional forms. It is a selectable shape atlas, not merely a small dropdown of Circle/Square/Diamond. The visible levels can each contain multiple selected shapes; the Edges collection is separate.

### XAO architecture requirements
1. Level is a first-class render layer, with enabled state, color, multiple shape IDs, scale, opacity/coverage, distribution and deterministic seed.
2. Edge shapes use a distinct pass and mask; do not overload a level's shape selection.
3. Light/Random must specify the selection distribution. "Light" likely refers to source-lightness-driven shape choice, but the exact semantics are not fully proven by the panel alone.
4. Color Mode is a five-way source/palette policy. Preserve, Sample Source, Override, Palette and Gradient must be explicit and testable.
5. Clump Amount and Chaos are separate controls: Amount should determine clump coverage/strength, Chaos should determine spatial irregularity. Do not collapse them into one noise amplitude.
6. Cell Size, All Sizes, Rotation Jitter and Scale Jitter must have separate, predictable influence.
7. Empty Below is a threshold gate. Contrast and Gamma are source-analysis controls with a documented order.
8. Stable grid anchoring and separate deterministic random streams are required. Editing palette or glow must not reshuffle shape placement.
9. The standalone Dither Majid Lines effect remains excluded. The Array shape atlas may contain bar/line-like stamps only as individual Array geometry choices, not as a standalone Lines module.

## 3. ASCII CGO — visual structure refinement
- The source/output comparison confirms a regular character grid, with glyphs such as letters, punctuation, digits and repeated symbol runs.
- Character identity is visibly structured by local tone and region; it is not simply random Unicode noise across the whole image.
- The output has strong warm orange highlights and pale glyphs against a very dark background.
- The subject's silhouette and clothing folds are preserved by changes in glyph density and character selection.
- The source clip moves through the full duration; the output tracks source pose and local details.
- Keep glyph selection, source-tone mapping, palette, glow eligibility and glow color as separate controls.
- The user's requested random glyph animation should be an optional temporal mode, not the only behavior.

## 4. ASCII Ghost — visual structure refinement
- Output is a high-density, tightly packed character field. The source is a colorful architectural/coastal scene; the rendered side is dominated by dark red/maroon and pale glyphs.
- Glyphs vary with tone and local structure, creating large repeated-character bands in some regions and punctuation-heavy detail in others.
- The overall red tint is strong; the reference does not establish that every glyph is an exact unmodified source RGB sample.
- XAO should expose source-sampled glyph color as an explicit mode (cell average / center / edge-weighted) alongside palette/tint modes.
- Rays remain a separate optional engine driven by a chosen glyph/highlight mask, consistent with the user's note.

## 5. Golden Glow Halftone — visual structure refinement
- A split portrait comparison shows the right side as bright orange-gold circular dots with a luminous rim/halo on a near-black background.
- Dot size and density vary with image tone; the subject is readable through the dot distribution.
- There is a visible glow halo around the dot field, but the dots remain legible as the base halftone geometry.
- Treat it as Halftone + a dedicated glow sub-pass. Controls should include screen scale, dot gain, threshold/tone curve, ink color, glow threshold, radius, exposure, and background policy.
- Preserve empty/black regions; do not create a full-frame glow wash.

## 6. Liquid ASCII — visual structure refinement
- The output is composed of tightly packed rounded rectangular tiles with varied widths and row heights.
- Many tiles contain short words or glyph strings; the visible example includes Hangul/Korean-like text and Latin words, not only Japanese characters.
- Tile fill colors are sampled/varied from source regions, with a warm neutral palette and selective red/orange accent tiles.
- The tiles have consistent row alignment and small gaps. They do not float freely or behave as independent unstructured capsules.
- XAO should support Unicode text sets generally, not hard-code Japanese. Normal Typeset mode must shape complex scripts correctly; glyph-art mode can intentionally select individual glyphs.
- Tile dimensions, corner radius, gap, text fit, baseline, content mode, font and color must be separate controls.

## 7. PixelDitherGo — visual structure refinement
- The rendered half is a high-contrast yellow-green/black field with thin, clearly visible square grid lines.
- Large contiguous square/block regions carry the main tonal structure, while very fine dot/cross-like substructure fills cells and edges.
- The pattern is spatially aligned to a regular grid; some regions show large blocks that span multiple fine cells.
- The output is not a plain single-scale ordered dither, not just a pixel mosaic, and not a simple Bayer matrix.
- In the clip, the grid structure appears stable; visible changes mostly follow the changing source image. Current evidence does not prove autonomous travelling noise, feedback, or random cell motion.
- Recommended implementation hypothesis remains a two-scale or multi-scale dither: coarse block occupancy plus fine patterned fill, with edge/detail preservation and a limited palette. Keep this provisional until a deeper algorithmic match test is performed.

## 8. Rainbow ASCII — visual structure refinement
- The output is a dark, very dense glyph/mark field, with small bright multicolor accents (green, orange, magenta, violet and occasional yellow).
- The color appears spatially selective and tied to source features; it is not a uniform linear rainbow overlay.
- The effect reads as tiny colored glyph/dot-like marks with bright local clusters and deep black gaps.
- The accompanying user requirement is to combine ASCII + Glow + Rays and permit multicolor glyphs, multicolor glow and multicolor rays.
- Implement as an effect recipe over shared engines. Do not bake the three components into one inseparable renderer.

## 9. Mosaic ASCII — visual structure refinement
- The output is a clear grid of large square cells; many cells contain tiny glyphs or symbols.
- Cell fills have semi-transparent/tonal variation, while the glyphs add finer information within the cells.
- A bright diagonal highlight/bloom region dominates the upper-right part of the output; dark navy/black regions preserve negative space.
- The coarse cell mosaic and fine glyph content are two separately controllable visual layers.
- The effect follows the source subject and source highlights; do not let cell positions drift with progress or animation.
- Keep cell size, glyph density/size, source sample, palette, saturation and glow as independent parameters.

## 10. Threshold ASCII — visual structure refinement
- Output consists of horizontal rectangular bars with tone-dependent lengths and occupancy, aligned to a consistent row grid.
- Dark and light bands form the subject silhouette; some rows contain many short segments, while others form long continuous bars.
- Fine square/point-like details are also visible in selected dark/high-detail regions.
- This is not merely random moving lines: the dominant structure is a row-based threshold/segment renderer.
- The user's requested motion of lines/rectangles/squares should be an optional animation layer on top of the stable threshold structure.
- Keep it separate from the excluded Dither Majid Lines effect.

## 11. Temporal analysis across all clips
- All frames in all nine supplied videos decoded successfully (2,514 total).
- Frame-to-frame image differences were computed on the effect/output half for the eight before/after clips. The strongest temporal variation is in Liquid ASCII, where text/tile content changes rapidly; PixelDitherGo has lower variation and a visibly stable grid; Golden Glow Halftone is mostly stable in pattern structure while the source pose changes.
- The Array recording is a UI walkthrough and scroll interaction, not a clean effect-animation reference. Its changing frames mostly reflect panel scrolling, menus and the mobile control center at the end.
- No mutable per-render animation state should be used in XAO. Use absolute AE time and stable per-cell/layer hashes.
- A stable pattern that follows a moving source is not evidence of effect motion. Distinguish source-driven changes from independent temporal animation in each engine.

## 12. Remaining limits before calling visual audit complete
- All frames were decoded and scanned, but not every individual frame was manually inspected at native resolution.
- The visual audit has not recovered proprietary shader/source code or exact mathematical formulas from the clips.
- PixelDitherGo's exact coarse/fine pattern-generation formula remains unresolved.
- The Array preview in the settings walkthrough is small; the control model is much clearer than the exact render algorithm.
- The next validation stage should include per-frame output/source registration, temporal glyph/shape tracking, cell-grid estimation and selected pixel-level crop comparisons for PixelDitherGo, Liquid ASCII, Mosaic ASCII and Golden Glow Halftone.
