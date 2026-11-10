# XAO — First Native ASCII Core Engine (Pass 69)

Target branch: xao/recovery-baseline-2026-11-10

## Implemented
- Added a host-independent AsciiEngine implementing the existing xao::Engine interface.
- Added a compact built-in 5x7 raster glyph ramp. Output is rendered as cell glyph masks, not a character-string overlay.
- Added cell size, glyph scale, contrast, brightness, invert, colorize, ink, paper and cell-alpha controls.
- Uses average cell luminance for glyph selection and average premultiplied cell color for colorized output.
- Writes every output pixel and validates matching source/destination dimensions.
- Added a focused ASCII engine test target.

## Deliberate limits
- This is the first working CPU ASCII raster engine, not the completed XAO ASCII feature set.
- The small built-in glyph ramp must be extended by a licensed font-atlas pipeline after font and shaping checks.
- No AE adapter, PiPL, Windows AEX build or After Effects runtime test is included in this pass.
- No MAJEED effect code or MAJEED identity is used.
