# MAIN IDEAS — Deep Visual and Asset Audit Pass 37

Date: 2026-11-07  
Scope: `XAO/MAIN IDEAS/` only. This pass deepens the prior inventory and frame-difference audit; it does not declare MAIN IDEAS closed.

## 1. Inventory verification

The archive contains 41 regular files under MAIN IDEAS:
- 9 video references (8 effect examples + 1 Array settings walkthrough)
- 23 still images (6 Shape Halftone presets, 4 Shape Halftone settings, 5 Typeset presets, 6 Typeset settings, 2 Array before/after images)
- 7 text/reference files (effect notes, RTF notes, and THE WEBS.txt)
- The `Dither asci_` directory is present in the folder structure but contains no files in the archive.

All 41 regular files were extracted and included in this pass. The two RTF notes were decoded directly from Unicode escapes because generic RTF text extraction dropped their Arabic content.

## 2. New visual review of all nine clips

All clips were decoded previously (2,514 total frames). This pass additionally created a time-indexed visual contact sheet at approximately one frame per second for every clip, reviewed the complete sampled sequence, and cross-checked the still screenshots. This is a broader visual review, not a claim that every decoded frame was manually inspected individually at native resolution.

### PixelDitherGo
- Source note explicitly says the user cannot easily describe the effect and asks for square-by-square analysis.
- Visual sequence: high-contrast yellow/lime and near-black output; dense regular micro-grid remains spatially anchored while the source image changes.
- The visible pattern is multi-scale: larger square/block clusters establish the main silhouette and tone; much finer dots/cross-like marks and thin grid structure provide secondary texture.
- The effect appears to preserve a stable cell lattice rather than animate the whole image or randomly shuffle cells. Changes in the output are primarily tied to the moving source content.
- Implementation direction: separate coarse block quantization, fine micro-pattern layer, and subtle grid/edge layer. Expose their scales/strengths independently. Exact proprietary pattern-generation formula remains unknown; do not claim a recovered algorithm.

### Liquid ASCII
- The output is a tightly packed field of rounded rectangular/pill-like tiles, not loose glyphs floating over the image.
- Each tile has a colored fill that tracks the source region; text is drawn inside each tile. Tile dimensions and text content are independently important.
- Visible content mixes short Latin-like words/labels and glyphs; source note also explicitly requests random Japanese/ancient-language glyph sets, hide/show words, text size, font, and text color controls.
- Across the sequence, the tile field stays registered to the frame while tile contents/appearance vary; do not move the whole grid to create motion.
- Implementation direction: rectangle-cell layout with independent width/height/aspect distribution, source-sampled fill color, text/glyph atlas, per-cell deterministic animation, padding/corner radius, and separate fill/text color controls.

### Mosaic ASCII
- Confirmed two-scale structure: large square mosaic cells form the primary image, while small letters/numbers/symbols are overlaid within/among those cells.
- Larger blocks carry stronger source colors and tonal structure; fine glyphs provide a second texture layer. The look includes low-saturation dark regions and selective bright bloom/glow.
- The sequence shows the bright diagonal region and dark negative-space regions moving with source content while the square lattice remains coherent.
- Implementation direction: independent coarse mosaic and fine glyph passes, independent cell sizes/density, source color sampling, glyph size distribution, selective glow, saturation control, and stable grid anchoring.

### Golden Glow Halftone
- Output is a dark/near-black field with warm gold/orange halftone dots and luminous rims/highlights.
- Dot density and apparent dot size follow the subject's tonal/silhouette structure; the subject is not simply covered by a uniform glow layer.
- The visual is a combined Halftone engine treatment: screen/dot formation plus warm ink color and localized glow. It is not a separate Glow effect.
- The dot pattern is spatially coherent while the source pose changes. Preserve dark negative space and the small bright cores/rims.
- Implementation direction: halftone coverage first, then ink color/tone mapping, then thresholded/local glow derived from the halftone energy. Expose dot scale, gain/threshold, glow radius/intensity/color separately.

### ASCII CGO
- Dense, regularly structured glyph rows form a tonal image. The glyph field is not merely random text: character density and local glyph choice support the image's tonal structure.
- Warm orange/red luminous accents appear in selected regions and around selected glyphs; they are localized rather than a uniform glow wash.
- User's note requires fast/random glyph/number/symbol variation, plus glow selection that can be fixed to chosen cells/regions or randomized/reassigned.
- Implementation direction: stable cell layout + tone-aware glyph mapper + deterministic per-cell temporal glyph variation + independently maskable glow layer with fixed/random selection modes.

### ASCII Ghost
- Dense symbol/number/character field with red/maroon and pale/white values; the color visibly follows the source image rather than using one global glyph color.
- A broad directional/radial ray-like component is integrated into the composition. Preserve it as a distinct Rays contribution composited with the ASCII field.
- User explicitly requires every glyph to be able to sample color from its corresponding background region.
- Implementation direction: source color sampling per cell (cell average/center/weighted sampling modes), optional palette/tint, plus separate Rays mask/energy controls.

### Rainbow ASCII
- Dense dark glyph field with localized multicolor regions (green, orange/yellow, magenta/purple and other spectral accents).
- Bright colors are tied to subject features and selected regions; this is not a flat rainbow gradient laid over all characters.
- Glow and colored rays are visually combined with the ASCII field, as explicitly stated in the user's RTF note.
- Implementation direction: per-cell color field/palette mapping + localized emission/glow + colored directional rays, with independent controls and a unified compositor.

### Threshold ASCII
- The output is primarily horizontal, row-aligned bars/segments with varying lengths and tonal density, plus blocky/point details.
- Light and dark bands encode the source's tonal structure; the arrangement is not just arbitrary moving rectangles or generic thresholding.
- The user asks for extensive control over the shapes, motion, and colors.
- Implementation direction: row/cell threshold map, segment-length and gap rules, optional block/point accents, deterministic motion offsets, and separate palette/contrast controls. This remains distinct from the excluded standalone Dither Majid Lines effect.

### Array settings walkthrough
- The 19.86-second recording is a mobile browser/plugin UI walkthrough; the changing phone/browser chrome and panel scrolling are not effect animation.
- Shape system: Light/Random modes; multiple enabled levels with shape slots; separate edge-shape slots; add/remove level and shape actions.
- Shape library includes primitives and many compound geometric marks (quarter circles, rings/arcs, crosses, stars, directional marks, stripes, checker-like and stepped patterns).
- Color modes shown: Preserve, Sample Source, Override, Palette, Gradient. Palette controls include slots and sampled swatches; background toggle/color is separate.
- Additional visible controls: All Sizes, Cell Size, Rotation Jitter, Scale Jitter, Detailing, Clump toggle/type, Amount, Chaos multiplier, Clump By, Invert, Empty Below, Contrast, Gamma, and blend modes.
- Blend menu visibly includes Normal, Darken, Multiply, Color Burn, Lighten, Screen, Plus Lighter, Color Dodge, Overlay, Soft Light, Hard Light, Difference, Exclusion, Hue, Saturation, Color, and Luminosity.
- Treat this as a multi-level shape-field engine, not a single static mosaic filter.

## 3. Still-image and settings cross-check

### Shape Halftone
- Six supplied presets use the same horse source but vary screen/pattern treatment and color combinations (warm red/black, cyan/black, teal/black, green/black, violet/black and related variants).
- OCR-verified controls include Intensity, Blend, Show Source, Paper color, Glow, Exposure, Cell Size, Size Spread, Dot Gain, Paper Grain, Misregistration, Ink Mode, Ink Curve, Threshold Range, Red Shape/Angle/Ink.
- Ink Mode: Knockout, Multiply, Additive.
- Ink Curve choices visible: Dots, Lines, Stars, Squares, Rings, Crosses, Arrows, Smileys.
- Blend list includes Normal, Darken, Multiply, Color Burn, Lighten, Screen, Plus Lighter, Color Dodge, Overlay, Soft Light, Hard Light. Preserve the UI's full blend-mode family where confirmed in the other screenshot.
- Screenshot values include Intensity 100%, Glow 0.16, Exposure about 0.788, Cell Size 8.0, Size Spread 0.00, Dot Gain 0.912, Paper Grain 0.54, Misregistration 0.47, Threshold Range about 16%, and a purple/red ink example. These are screenshot examples, not required defaults.

### Typeset
- Five supplied visual presets show typography/glyph texture applied to dark backgrounds, with some bright/red/white/blue glyph accents.
- Controls confirmed: Blend, Show Source, Mode (Fixed / Sample Source / Palette), Content, Repeat to Fill, Font, Weight, Style, Size, Line Height, Letter Spacing, Empty Below, Invert, Contrast, Gamma.
- Font list includes Inter, Roboto, Open Sans, Lato, Montserrat, Poppins, Raleway, Nunito, Oswald, Bebas Neue, Playfair Display.
- Weight menu runs Thin 100 through Black 900. Example screenshots show Inter Black 900 Regular, size 27, line height 1.10, letter spacing 24.0, empty below 15%, contrast 1.13, gamma 1.42. Other screenshot values vary; these are not canonical defaults.
- Important architecture distinction: Typeset is a real typography/text layout engine (including source sampling and repeat-to-fill), not merely the ASCII glyph mapper.

### Array before/after stills
- Raw source and processed image are both present and correspond to the horse image used by the Array settings reference.
- The processed image is composed of many differently sized/weighted shapes and marks rather than a uniform grid of identical cells.

## 4. Corrected requirements and implementation implications

1. Keep the eight visual concepts separate as presets/behaviors over shared engines; do not collapse them into one generic ASCII preset.
2. Shared infrastructure can include stable cell grids, source sampling, glyph atlas, palette, masks, deterministic per-cell animation, glow/rays, and compositing.
3. Each concept needs a distinct recipe and parameter group:
   - CGO: selective/fixed/random glyph glow.
   - Ghost: per-cell source color + Rays.
   - Golden Glow Halftone: warm ink + halftone-derived glow.
   - Liquid: rounded rectangular tiles with text.
   - Mosaic: coarse mosaic + fine glyph overlay.
   - PixelDitherGo: coarse/fine multi-scale pattern with stable grid.
   - Rainbow: localized multicolor glyph emission + Glow/Rays.
   - Threshold: row-aligned variable-length tonal bars/segments.
4. Animation must be deterministic from absolute composition time, seed, and cell identity; never depend on mutable previous-frame state or render order.
5. Source/grid registration must remain stable in image coordinates. The effect must not slide the underlying image as progress/time changes.
6. The Array shape-level system and Shape Halftone ink/paper system remain separate engines with shared compositor/color infrastructure.
7. Do not add the excluded standalone Dither Majid Lines effect. Threshold ASCII's horizontal segments are part of its own visual concept, not a separate line-stamp effect.

## 5. Remaining closure work

MAIN IDEAS is **not yet closed**. Remaining checks:
- Inspect the original videos at native resolution beyond the one-second contact-sheet pass, focusing on transition moments and fine cell/glyph behavior.
- Inspect all six Shape Halftone settings and six Typeset settings individually at full resolution to settle any OCR ambiguity and record exact control states.
- Inspect the Array recording at finer temporal intervals around each menu/slider transition to ensure no settings were missed.
- Reconcile every item against prior Passes 33–36 and mark duplicates vs genuinely new findings.
- Only after those checks can MAIN IDEAS be marked complete and the audit move to ASCII.
