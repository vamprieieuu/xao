# MAIN IDEAS — Native-Resolution Sequence Review Addendum Pass 38

Date: 2026-11-07  
Scope: Eight MAIN IDEAS effect clips only (Array settings walkthrough excluded from this addendum).

## Review method
- Re-extracted the effect side (right half) of each comparison clip.
- Reviewed contact sheets sampled at 5 frames/second (0.2-second intervals) at native-source aspect ratio, scaled only for montage viewing.
- This gives denser temporal inspection than the one-second review in Pass 37, but it is still sampled review rather than manual inspection of every decoded frame.

## Additional observations

### PixelDitherGo
- The pattern is more clearly layered than the earlier broad description: a stable fine lattice of thin horizontal/vertical lines and tiny repeated marks sits behind/around larger quantized square regions.
- Large lime/yellow square clusters describe the source silhouette and tonal blocks; microdots and line intersections form a dense secondary texture.
- The grid remains anchored across the clip. No evidence of a moving-image/scrolling grid was observed.
- Best XAO decomposition: coarse square quantizer + fine repeated micro-pattern + very subtle grid-line pass. Their scales and contrast should be independent. Do not label the exact original dither kernel as known.

### Liquid ASCII
- Each row is a horizontal run of rounded rectangular tiles; tile widths vary considerably within a row, and row heights/spacing can vary. It is not simply a uniform rectangular grid.
- Each tile contains one short text token/word or glyph group; the source clip visibly uses word-like Latin and East-Asian-looking strings rather than only isolated ASCII characters.
- Fill colors are regionally sampled and vary from pale cyan/blue through beige/brown to saturated red/orange. The tile boundaries are dark and clearly separated.
- Tile geometry stays stable enough to read as a mosaic of message/input chips while source colors and content evolve.
- XAO should support row-wise partitioning/variable tile widths, variable row heights, corner radius, inter-tile gap, source-sampled fill, text fitting/alignment, and independent glyph/text animation. This should not be approximated by putting arbitrary text over a conventional square grid.

### Mosaic ASCII
- The large square cells are concentrated around strong tonal boundaries and the bright diagonal subject feature; much of the interior is a finer, nearly continuous glyph field.
- The fine layer uses sparse, small letters/numbers/symbols in cool pale colors, while larger square blocks create darker/paler stepped transitions.
- A bright white-violet bloom is localized around the diagonal highlight, with dark navy negative space in lower regions.
- XAO should allow adaptive coarse blocks plus a fine glyph layer, rather than forcing every pixel region into the same coarse square size.

### ASCII CGO
- The glyph rows form a highly regular repeated texture; tone is encoded by changing the dominant character/density across regions (for example, repeated dense glyph rows versus brighter, more open rows).
- The subject is a dark silhouette against brighter text fields. Orange/red emission is localized to small selected features (notably face/eye region and lower highlights), with some scattered warm specks.
- Character changes are visible but the underlying row/cell structure remains stable. Animation should vary glyph identity/selected accents without jittering the entire grid.
- The requested fixed/random glow selection should be a mask/selection system over cells or glyph IDs, not a single global glow toggle.

### ASCII Ghost
- The ray contribution is clearly visible as diagonal streaks crossing the lower/right portion of the field, integrated with the red/pink glyph texture.
- Glyph distribution is row-structured and spatially dense; colors range from pale cream/pink to deeper red based on image region.
- XAO should keep glyph source-color sampling and the ray field separately controllable, with an explicit composite order and optional ray mask.

### Golden Glow Halftone
- The dot screen remains extremely stable through the clip while the source pose changes.
- Dots have bright golden cores and soft warm halos, with dot size/density shaping the subject silhouette against nearly pure black.
- The glow should be derived from the halftone ink/dot output or a dedicated dot-emission mask; a generic blurred source image would lose the reference's crisp bright dot cores.

## Remaining status
- These 5-fps sheets are a denser review aid, not a substitute for checking native-resolution crops and transition frames individually.
- Rainbow ASCII and Threshold ASCII still need the same targeted native-resolution crop/transition inspection before the MAIN IDEAS folder can be closed.
- Array walkthrough still needs finer sampling around each UI state transition.
- MAIN IDEAS remains open. No move to ASCII folder yet.
