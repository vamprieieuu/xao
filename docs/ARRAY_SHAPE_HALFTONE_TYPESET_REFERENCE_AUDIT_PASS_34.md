# XAO Reference UI and Shape-System Audit — Pass 34
Date: 2026-11-07
Scope: Full control-panel recording for the Nexus Array/shape-halftone reference, Shape Halftone screenshots, and Typeset screenshots. This is a grouped visual/control audit, not an implementation or AE runtime test.

## 1. Array / shape field reference — control inventory recovered from the full recording

The supplied 19.89-second vertical screen recording is a browser session at nexus.synkit.net. It shows a layered shape-field/halftone system, not merely a single fixed mosaic. The following controls are visibly present:

### Global compositing and source
- Intensity
- Blend mode, with at least Normal, Darken, Multiply, Color Burn, Lighten, Screen, Plus Lighter, Color Dodge, Overlay, Soft Light, Hard Light; additional Difference, Exclusion, Hue, Saturation and Color choices appear in the expanded menu.
- Show Source toggle

### Shape construction
- Shapes selector: Light / Random
- Multiple independently enabled levels (Level 1, Level 2, Level 3), each with a shape slot and add/remove affordances.
- Edge shape(s) are configured separately from the levels.
- A shape/vector library is visible with many geometric, starburst, cross, dot, ring, diagonal, block, quarter-circle and directional symbols. This is a selectable stamp library, not just a circle/square toggle.
- All Sizes control, followed by scale/size behavior controls.

### Color and palette
- Color Mode: Palette
- Random toggle
- Slots count
- Individually editable palette entries (example visible colors include #2A2A2A, #8C8C8C and #FF6A00)
- Background toggle/color
- A mode menu exposes Preserve, Sample Source, Override and Gradient (visible in the recording).

### Grid, jitter and structure
- Cell Size
- Rotation Jitter
- Scale Jitter
- Detailing
- Clamp (shown as a range/shape control)
- Amount
- Chaos
- Clamp By: Random
- Invert
- Empty Below
- Contrast
- Gamma
- Edges toggle/shape control

### Important structural inference
This UI describes a multi-level procedural shape field with per-level shape selection, independent edge marks, palette assignment, and several distinct spatial randomization controls. It should not be reduced to “randomly place shapes”: cell layout, level participation, edge selection, color assignment, size distribution, rotation, clumping, and tone gating are separate dimensions.

### XAO implementation proposal
- Represent each level as an immutable layer descriptor: enabled, shape ID, size range, opacity/coverage, rotation policy, palette policy, and deterministic seed stream.
- Keep the grid origin anchored in source-image coordinates. Region/tile renders must not re-seed or shift the pattern.
- Separate random streams for cell selection, shape choice, palette choice, rotation, scale, and clump membership. A change to one control should not reshuffle every other dimension.
- Implement Clamp By as an explicit distribution/gating policy, not as an unexplained generic random slider.
- Empty Below should be a tone/coverage gate with a documented luma domain and a soft transition option.
- Edge shapes should be a separate pass/layer with independent size and color behavior.
- The UI's large shape library should be indexed and previewable; do not ship unlicensed third-party glyph artwork without rights review.

## 2. Shape Halftone screenshots — separate print-oriented engine, not the same as Array

The supplied Shape Halftone panel exposes:
- Intensity, Blend, Show Source, Paper
- Glow, Exposure, Cell Size, Size Spread, Dot Gain, Paper Grain, Misregistration
- Ink Mode: Knockout, Multiply, Additive
- Ink Curve / stamp geometry: Dots, Lines, Stars, Squares, Rings, Crosses, Arrows, Smileys
- Threshold Range
- Per-ink controls including Red Shape, Red Angle and Red Ink color.

Implementation distinctions:
- Paper grain and glow are post/print-material treatments; they should not be conflated with the screen geometry.
- Misregistration should be per-ink spatial offset, deterministic and independently seeded.
- Ink Mode must explicitly define overlap and alpha behavior. Knockout, Multiply and Additive are different compositing models, not UI aliases.
- Threshold Range and Dot Gain should affect ink coverage in a calibrated order; test monotonicity and prevent dot shapes from shrinking unexpectedly when coverage increases.
- A Line is allowed here as one selectable halftone stamp geometry only. It is not the excluded standalone Dither Majid Lines effect.

## 3. Typeset screenshots — source-aware typography controls

The supplied Typeset panel visibly exposes:
- Blend mode and Show Source
- Mode: Fixed / Sample Source
- Content
- Repeat to Fill
- Font
- Weight (Thin 100 through Black 900)
- Style (Regular / Italic)
- Size
- Line Height
- Letter Spacing
- Empty Below
- Invert
- Contrast
- Gamma

Visible example defaults/values include Inter, Black (900), Regular, Size 27, Line Height 1.10, Letter Spacing 4.0, Empty Below 5%; another view shows letter spacing 24.0 and Empty Below 15%, demonstrating that these are user-adjustable rather than fixed preset constants. The font menu includes Inter, Roboto, Open Sans, Lato, Montserrat, Poppins, Raleway, Nunito, Oswald, Bebas Neue and Playfair Display.

### XAO Typeset behavior requirements
- Fixed mode lays out user-authored content; Sample Source derives content/selection from the source image's sampled tone/structure. These must remain separate modes.
- Repeat to Fill should be deterministic and layout-aware, respecting line breaks and shaped glyph advances.
- Weight/style must resolve to actual font faces or variable-font axes where available; do not fake bold/italic by simply expanding outlines when a real face exists.
- Line Height and Letter Spacing are typography metrics, not image-space cell-size controls.
- Empty Below is a tone threshold that can suppress low-information regions; define whether it is applied before or after contrast/gamma and keep that ordering consistent.
- Arabic and other complex scripts require bidi segmentation and shaping (joining, ligatures, glyph advances). Do not treat Unicode codepoints as independently printable cells in normal Typeset mode. Glyph-art mode can remain a separate intentional per-glyph mode.
- Font availability and redistribution rights must be tracked separately. A font installed locally may be usable by the user without being legally bundleable inside XAO.

## 4. Shared engine architecture decisions
1. Array and Shape Halftone share grid, shape atlas, tone analysis and deterministic random infrastructure, but they remain distinct looks with different compositing/coverage models.
2. Typeset uses a real text-layout subsystem and may share the glyph atlas cache with ASCII, but it is not just ASCII with a larger cell size.
3. Each control must have a documented effect on the render graph and cache invalidation. Changing only blend mode must not rebuild glyph/shape atlases or source analysis.
4. Preserve source alpha; paper/background options must be explicit. Never force opaque output silently.
5. All animation/randomness must be based on absolute AE time and stable per-layer/per-cell seeds; no browser wall-clock time or Math.random.
6. The shape library must support deterministic custom/user-defined shape input later, but initial shipping assets must be license-cleared.
7. The standalone Dither Majid Lines effect remains excluded. A line stamp inside the Shape Halftone ink-curve menu is a geometry choice only.

## 5. Evidence and limitations
- Array settings were read from the supplied full 19.89-second MP4 recording using multiple timeline samples; the source is a web UI recording, not XAO source code.
- Shape Halftone and Typeset settings were read from the supplied screenshots.
- Values listed as examples are only those legible in the supplied images; they are not asserted as universal defaults.
- No claim is made that the exact Nexus implementation or its source code is available, licensed, or reusable.
- This pass does not claim the Array look has been visually reverse-engineered pixel-by-pixel. It establishes the visible control model and architectural requirements.
