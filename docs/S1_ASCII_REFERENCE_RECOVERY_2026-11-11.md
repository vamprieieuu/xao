# S1 ASCII Art — Binary Reference Recovery
Date: 2026-11-11
Source: supplied S1AsciiArt.aex and S1AsciiArt.aex.c
XAO branch: xao/recovery-baseline-2026-11-10

## Character-set recovery

The S1 Character Set popup contains nine sets: Classic, Minimal, Detailed, Bourke, Braille, Katakana, Blocks, Quadrants and Box Drawing.

### Exact 92-glyph master ramp

The AEX contains the following 92-character master ramp, in this exact order:

` \`.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@`

This is the source atlas used by the four Latin-style character sets.

### Latin subset behavior

The binary builds three subsets from the 92-glyph atlas by measuring each glyph’s average coverage/density across its 13 font masks, sorting glyphs by density, then selecting glyphs evenly across the density range:
- Classic: 10 glyphs
- Minimal: 6 glyphs
- Detailed: all 92 glyphs, identity order
- Bourke: 28 glyphs

The subset selector chooses the nearest unused glyph for each evenly spaced density target, then sorts the selected glyphs by density. XAO reproduces this selection procedure using the selected installed font’s glyph coverage as its density source. This preserves the algorithm; exact subset membership can vary if a different font family is selected because S1 averages its 13 embedded font masks.

### Specialty character sets

The binary’s specialty-codepoint arrays recover to:

- Braille: all 256 codepoints U+2800 through U+28FF.
- Katakana: no explicit specialty-codepoint array; the set uses a forced font index (12) in S1. XAO uses a Japanese-capable Windows font fallback such as Yu Gothic UI.
- Blocks: U+0020 SPACE, U+2591 LIGHT SHADE, U+2592 MEDIUM SHADE, U+2593 DARK SHADE, U+2588 FULL BLOCK.
- Quadrants: U+0020 SPACE, U+2580 UPPER HALF BLOCK, U+2584 LOWER HALF BLOCK, U+258C LEFT HALF BLOCK, U+2590 RIGHT HALF BLOCK, U+2588 FULL BLOCK, then U+2596 through U+259F.
- Box Drawing: U+0020 SPACE, U+2504, U+2500, U+253C, U+254B, U+2588.

The XAO character-set catalog and Windows glyph-atlas builder now include these recovered sets. Braille, blocks, quadrants and box-drawing glyphs are built from the exact codepoint lists above rather than broad guessed ranges.

## Exact S1 palette stops

The S1 renderer’s palette switch stores RGB byte triplets and divides each channel by 255 before constructing the palette. Exact recovered RGB8 stops:

| Palette | RGB hex stops |
|---|---|
| Monitor Glow | #222323, #F0F6F0 |
| Game Boy DMG | #0F380F, #306230, #8BAC0F, #CADC81 |
| Oil 6 | #272744, #494D7E, #8B6D9C, #C69FA5, #F2D3AB, #FBF5EF |
| Retrotronic | #392B35, #BB474F, #486B7F, #7A9C96, #D1BFB0 |
| Gothic Bit | #0E0E12, #1A1A24, #333346, #535373, #8080A4, #A6A6BF, #C1C1D2, #E6E6EC |
| Curiosities | #46425E, #15788C, #FF6973, #00B9BE, #FFB0A3, #FFEECC |
| CGA Palette 1 | #000000, #AA00AA, #00AA00, #AAAAAA |
| CGA Palette 1 Bright | #000000, #FF55FF, #55FF55, #FFFFFF |
| CGA Palette 0 Bright | #000000, #FF5555, #55FFFF, #5555FF |

Important: the S1 Game Boy DMG final stop is #CADC81 in this binary, not the more commonly encountered #9BBC0F. Do not silently substitute a similarly named external palette.

XAO stores these values as RGB8 reference data in core/include/xao/AsciiReferencePalettes.h. Convert sRGB values to XAO’s linear-light working space before compositing or interpolation.

## Color modes and mapping

Recovered S1 modes:
- Monochrome
- Source Color
- Palette

Recovered palette controls:
- Palette Mapping: Tonal / Original
- Palette Color Strength
- Blend modes: Normal, Multiply, Screen, Overlay, Soft Light, Difference, Add

The user has asked to carry these actual palette stops into XAO, but the final advanced color-system UI and behavior remain pending their further explanation. Do not finalize that design prematurely.

## Reuse and licensing boundary

The AEX contains an embedded IBM Plex Mono font and its embedded copyright/license strings identify the font as SIL Open Font License. If XAO ever redistributes that font, include its complete OFL license and notices. Do not copy S1’s proprietary plugin wrapper or renderer code. The XAO implementation uses the recovered set data and independently implements the atlas/subset logic.
