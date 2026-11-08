# XAO — MAIN IDEAS Final Deep Audit (Pass 39)
Date: 2026-11-08

## Evidence and honesty
This pass consolidates the MAIN IDEAS visual review. "Verified" means directly visible in supplied stills/contact sheets or screen recordings; "Inferred" is a plausible implementation model, not recovered proprietary source; "Unknown" means the supplied evidence cannot settle it. Earlier inventory counted 41 regular files (9 videos, 23 stills, 7 text/reference files). The original ZIP is not mounted in this execution workspace, so this is not a fresh byte-for-byte inspection of all originals or an exhaustive native-resolution review of every frame. The available extracted contact sheets and prior observations are the evidence base.

## Final findings by reference

### ASCII CGO
**Verified:** dense regular glyph rows; broad source tonal silhouette; localized warm orange/red luminous glyph accents rather than uniform glow.
**Inferred engine:** stable layer-anchored cell grid; per-cell source sampling; glyph ramp/charset selection; deterministic per-cell variation; separate accent/emission mask and localized glow.
**Controls:** cell size/density, charset, glyph fit/size, tone curve, color mode, accent selection/probability, glow radius/intensity, speed/seed.
**Unknown:** exact glyph ramp, random distribution, and accent-selection rule.

### ASCII Ghost
**Verified:** dense symbol field with pale/cream and deep red/maroon regions; diagonal/radial ray-like contribution, strongest toward lower/right in the example; source structure retained in glyphs.
**Inferred engine:** independent ASCII and Rays passes sharing source/mask but not renderer. Cell sampling should support average, center, weighted modes.
**Controls:** ASCII controls plus ray origin/direction/spread/intensity/color/decay/blend.
**Unknown:** exact ray model.

### Golden Glow Halftone
**Verified:** near-black negative space; gold/orange dot field defines subject; bright dot cores and softer luminous rims; glow follows the dots.
**Inferred engine:** halftone coverage -> ink/color response -> emission mask derived from dots -> localized multiscale glow. Treat as coordinated Halftone+Glow preset, not generic full-frame glow.
**Controls:** cell size, screen angle, dot curve/shape, gain/threshold, ink hue, core brightness, glow, background, blend.
**Unknown:** exact screen frequency/angle, dot kernel, blur profile.

### Liquid ASCII
**Verified:** not a uniform square grid; rows of rounded rectangular/pill tiles with variable widths and possibly row heights; short text/token/glyph groups; source-related cyan/blue, beige/brown, red/orange fills.
**Inferred engine:** row-wise variable-width partitioning, optional variable row heights, corner radius/gap, source-sampled tile fill, text fitting/alignment. This is a tile/typography layout engine, not ordinary ASCII over pixels.
**Controls:** text visibility/content/charset, font, glyph size, tile width range, row height, spacing, corner radius, alignment, fill/text color, seed/motion.
**User intent:** Japanese and ancient/symbol glyph collections; control glyph appearance and text size; avoid uncontrolled repeated glyph clutter.
**Unknown:** exact partition algorithm and whether dimensions are content-driven or randomized.

### Mosaic ASCII
**Verified:** two scales: large square mosaic blocks plus fine letters/numbers/symbols; coarse blocks establish broad tone/color while glyphs add fine texture; dark navy/black negative space and selective pale/violet bloom.
**Inferred engine:** independent coarse mosaic and fine glyph passes, each with its own scale, sampling, visibility and optional glow.
**Controls:** coarse cell size, fine glyph size/density, charset, color sampling, tone mapping, pass opacity, selective glow, seed.
**Unknown:** exact compositing order and whether fine glyphs are clipped to coarse blocks.

### PixelDitherGo
**Verified:** yellow/lime against near-black; fine lattice with thin horizontal/vertical line structure and tiny repeated marks; larger quantized square/block clusters carry the silhouette.
**Inferred engine:** coarse square quantization + fine micro-pattern pass + optional subtle lattice. Keep scales independent. This is distinct from the explicitly excluded Dither Majid Lines effect.
**Controls:** coarse block size, fine pattern size/type/density, grid weight, threshold/contrast, palette, edge response, seed.
**Unknown:** proprietary quantization kernel and whether marks are procedural or atlas-based.

### Rainbow ASCII
**Verified from available overview/contact sheets:** dense glyph field, not a smooth global rainbow gradient; dark navy/black regions coexist with localized violet, blue, cyan, pale/white and occasional warm accents; brighter source regions produce brighter/denser glyph clusters; color is spatially related to source.
**Inferred engine:** per-cell source sampling -> tone/occupancy mapping -> cell-local palette selection -> glyph render -> optional localized glow/rays. Never apply one full-frame rainbow tint.
**Controls:** glyph size/density, charset, source-color/palette mode, palette stops, tone curve, dark threshold, emission mask, glow/rays, deterministic seed.
**Unknown:** exact palette mapping and whether bright areas use a separate light pass.

### Threshold ASCII
**Verified from available overview/contact sheets:** aligned horizontal rows/segments with variable lengths and density; light/dark bands encode source tone; blocks and point-like marks support detail. Not a conventional uniform character grid and not Dither Majid Lines.
**Inferred engine:** row/cell threshold map -> segment occupancy/length -> optional block/point accents -> palette/contrast response. Any motion must be deterministic in absolute time.
**Controls:** row spacing, segment length/width, threshold, contrast/gamma, shape mode, block/point detail, color, motion amount/speed, seed.
**Unknown:** whether bar lengths come from row-integrated luminance, local threshold crossings, or a pattern map.

### Array settings walkthrough
**Verified UI concepts:** multiple shape levels/slots with per-level colors and add/remove; separate edge-shape slots; shape library includes quarter-circles, rings/arcs, crosses, stars, directional marks, stripes, checker patterns and stepped blocks. Color modes: Preserve, Sample Source, Override, Palette, Gradient. Palette swatches and background toggle/color. Controls observed: All Sizes, Cell Size, Rotation Jitter, Scale Jitter, Detailing, Clump, Amount, Chaos multiplier, Clump By, Invert, Empty Below, Contrast, Gamma. Blend choices observed: Normal, Darken, Multiply, Color Burn, Lighten, Screen, Plus Lighter, Color Dodge, Overlay, Soft Light, Hard Light, Difference, Exclusion, Hue, Saturation, Color, Luminosity.
**Inferred engine:** multi-level spatial shape-field engine, not one uniform halftone grid. Each level owns shape selection, size behavior, color mode, amount/opacity and deterministic seed. Edge shapes are evaluated separately from fill shapes. Clump/Chaos affect distribution deterministically, not mutable render-order state.
**Unknown:** exact level weighting, Clump By semantics, spatial distribution function.

### Shape Halftone
**Verified controls:** Intensity, Blend, Show Source, Paper, Glow, Exposure, Cell Size, Size Spread, Dot Gain, Paper Grain, Misregistration, Threshold Range; red-channel angle/shape/ink controls; Ink Mode Knockout/Multiply/Additive; Ink Curve Dots/Lines/Stars/Squares/Rings/Crosses/Arrows/Smileys; common darken/lighten/contrast blend modes. Six preset images show distinct horse renderings/screens/palettes.
**Inferred engine:** channel/screen-based halftone with cell geometry, gain curve, per-channel angle/shape/ink, paper response and registration offsets. Ink Curve is a coverage/shape response, not merely a palette.
**Unknown:** exact channel angles/order and paper model. Screenshot slider positions are observations, not canonical defaults.

### Typeset
**Verified controls:** Blend, Show Source, Mode (Fixed/Sample Source/Palette), Content, Repeat to Fill, Font, Weight, Style, Size, Line Height, Letter Spacing, Empty Below, Invert, Contrast, Gamma. Visible font list includes Inter, Roboto, Open Sans, Lato, Montserrat, Poppins, Raleway, Nunito, Oswald, Bebas Neue, Playfair Display. Weight range Thin 100 through Black 900. Presets show text forming the source silhouette, not simply overlaying text.
**Inferred engine:** real typography raster/layout engine; source tone controls text visibility/density/color; supports repeat-to-fill and fixed/source/palette modes. Arabic requires Unicode shaping and bidi ordering for ordinary text. Symbol-art mode may intentionally use an atlas.
**Unknown:** exact wrapping, sampling positions and text-flow strategy. Example values (Inter Black 900, size 27, line-height 1.10, letter spacing 24, empty below 15%) are not defaults.

## Shared engineering requirements
1. Keep each visual identity as its own renderer/pass graph. Share sampling, color, glyph atlas, masks, glow and compositing utilities, not a generic renderer.
2. Randomness must be deterministic from seed, absolute time, cell identity and pass identity; never depend on render call order.
3. Separate source color sampling from luminance sampling; preserve alpha and premultiplication.
4. Anchor grids to layer/composition coordinates so ROI/tile renders do not crawl.
5. Typography requires font fallback, glyph coverage, metrics, shaping, bidi, line layout, clipping and caching.
6. Glow derives from a defined emission mask and remains independently controllable.
7. Multi-scale looks (Mosaic ASCII, PixelDitherGo) keep independent scales.
8. Array shape levels composite independently and have independent deterministic seeds.
9. CPU-first: bounded memory, immutable caches, cancellation, no per-pixel allocations, no MFR oversubscription.
10. Output must not depend on tile order, reverse playback, frame order or concurrent MFR scheduling.

## Explicit prohibitions
- Do not create a separate Dither Majid Lines effect/source/UI/controls/presets.
- Do not collapse ASCII CGO, Ghost, Liquid, Mosaic, Rainbow and Threshold into one renderer.
- Do not treat Liquid ASCII as a square glyph grid.
- Do not reduce Mosaic ASCII to one resolution.
- Do not implement Rainbow ASCII as a global rainbow overlay.
- Do not reduce PixelDitherGo to a simple threshold/ordinary line screen.
- Do not reduce Shape Halftone to basic monochrome dots.
- Do not implement Typeset as uniformly stamped text.
- Do not claim proprietary algorithms were recovered from appearance alone.

## Closure matrix
| Reference | Visual identity | UI/control evidence | Algorithm certainty |
|---|---|---|---|
| ASCII CGO | Verified | Partial | Inferred |
| ASCII Ghost | Verified | Partial | Inferred |
| Golden Glow Halftone | Verified | Partial | Inferred |
| Liquid ASCII | Verified | Partial | Inferred |
| Mosaic ASCII | Verified | Partial | Inferred |
| PixelDitherGo | Verified | Partial | Inferred |
| Rainbow ASCII | Verified from available contact sheets | Partial | Inferred |
| Threshold ASCII | Verified from available contact sheets | Partial | Inferred |
| Array | Verified | Strong | Inferred |
| Shape Halftone | Verified | Strong | Inferred |
| Typeset | Verified | Strong | Inferred |

**Closure decision:** MAIN IDEAS is sufficiently characterized as a design specification for implementation planning. This does not mean proprietary source algorithms were recovered or every original frame/file was exhaustively rechecked at native resolution in this execution. If the original archive becomes available again, perform a final filename/hash reconciliation; reopen visual conclusions only if new evidence contradicts them.

## Next phase
Per the user's specified order, proceed to **ASCII** next. Do not start Halftone until ASCII audit is complete. Keep MAIN IDEAS frozen unless new evidence materially changes a finding.
