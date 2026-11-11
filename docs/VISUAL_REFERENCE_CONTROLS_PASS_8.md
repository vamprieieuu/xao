# XAO Visual Reference Controls — Shape Halftone and Typeset — Pass 8

Date: 2026-11-07

This pass inspects all supplied Shape Halftone and Typeset preset/settings images in MAIN IDEAS, including OCR-assisted control reading and direct visual comparison of the preset images.

## 1. Shape Halftone — six visual presets

The six supplied horse-image presets demonstrate that the intended effect is a shape-based screen rather than a single round-dot filter:
- Several presets use a dense regular screen of tiny marks with dark negative-space shadows.
- Shape and ink colors vary across the presets: red/black, cyan/white, yellow/black, violet/green, cream/black and cyan/pink.
- Some looks appear to use multicolor/overprinted screen components, while others use a restricted two-color or monochrome treatment.
- The same source subject is retained, but the screen geometry, palette, intensity and print texture substantially change the result.

## 2. Shape Halftone — controls read from the four settings screenshots

Confirmed visible controls:
- Intensity
- Blend mode, including Normal, Darken, Multiply, Color Burn, Lighten, Screen, Plus Lighter, Color Dodge, Overlay and Soft Light (the dropdown also shows further modes)
- Show Source
- Paper color
- Glow
- Exposure
- Cell Size
- Size Spread
- Dot Gain
- Paper Grain
- Misregistration
- Ink Mode: Knockout, Multiply and Additive
- Ink Curve
- Threshold Range
- Shape choices visible in the picker: Dots, Lines, Stars, Squares, Rings, Crosses, Arrows and Smileys
- Red Angle and Red Ink color, indicating per-ink angle/color controls; the remaining ink controls are not fully visible in this screenshot set.

### Design consequences
- Shape Halftone must support a selectable stamp/shape library, not only geometric dots.
- Per-cell brightness/threshold should determine the size or coverage of the selected stamp.
- Palette/ink channels need per-channel angle and color controls where the selected screen mode supports them.
- Ink compositing must distinguish knockout, multiply and additive behavior.
- Paper color, grain, exposure, glow and misregistration are part of the integrated print treatment.
- The exact Nexus control labels are reference requirements, not a reason to copy its proprietary code.

## 3. Typeset — controls read from the six settings screenshots

Confirmed visible controls:
- Blend mode and Show Source
- Mode: Fixed or Sample Source
- Content: a user-provided string (the screenshot shows NEXUS)
- Repeat to Fill
- Font family
- Weight: Thin 100 through Black 900
- Style: Regular or Italic
- Size
- Line Height
- Letter Spacing
- Empty Below threshold
- Invert
- Contrast
- Gamma

### Design consequences
- Typeset needs two distinct mapping modes:
  1. Fixed: repeat the user's exact content across the image.
  2. Sample Source: use source-derived content/tones or mapping behavior, as supported by the final design.
- Text layout needs explicit line-height and tracking rather than relying on a default font layout.
- Weight/style selection must map to the actual selected font face or variable-font axes; do not simulate a weight when the chosen font does not contain it without making that limitation clear.
- Empty Below is a threshold control for suppressing text in low-value regions.
- Source sampling, inversion, contrast and gamma affect the tonal distribution of the repeated text.
- Typeset must share the same exact-font loader, Arabic shaping and bidi pipeline as ASCII, while preserving text-run layout rather than treating every glyph as a disconnected cell.

## 4. Boundary between engines

- Shape Halftone remains part of the Halftone engine.
- Typeset remains its own independent engine and can be composed with ASCII, Glow or Rays through the shared stack.
- The Lines option visible in the Shape Halftone shape picker is a halftone stamp geometry. It is not the separate Dither Majid Lines effect, which remains excluded from XAO.
