# XAO Focused Audit — ASCII OFX Source Projects — Pass 13

Date: 2026-11-07

## Scope

Direct source inspection of:
- `ascii ofx [open source]/ascii.cpp`
- `ascii ofx [open source]/font8x8_basic.h`
- `glyphblocks ofx [open source]/glyphblocks.cpp`

Both projects are OFX effects, not After Effects-native plugins. The ASCII source describes its public-domain 8x8 bitmap font; the archive does not include a clear top-level project license for either complete project. GlyphBlocks includes a missing `../common/purzfx.hpp` dependency, so it is not independently buildable from the supplied folder.

## 1. ASCII OFX — algorithms

Two modes are implemented over a fixed 8x8 sample mask per cell:

1. **Structural mode:** samples 64 luminance points, thresholds each against the cell's mean luminance, packs the 64-bit mask, then compares it against each glyph from ASCII 32 to 126 using Hamming distance/popcount. The closest bitmap glyph wins.
2. **Brightness ramp:** averages the 64 luminance samples and maps the inverse mean to a 70-character density ramp.

It also supports Green, Amber, White and Source Colour output. Source colour is the average RGB of the 64 samples; terminal colours use fixed phosphor values. Cell dimensions are calculated from output aspect ratio and rounded grid counts. It supports UByte, UShort and Float and clamps sampled coordinates to the source bounds.

## 2. ASCII OFX — correctness/performance issues

- **Alpha is forced fully opaque:** for RGBA output the writer always sets alpha to the channel maximum. Original source alpha is discarded. Do not copy this behavior.
- **Render window vs whole-frame grid:** the grid is built from the source bounds on every render call, then only the requested render window is written. With tiles disabled this may work in a simple host path, but it prevents efficient tile rendering and repeats full-frame grid construction if the host invokes multiple windows.
- **No multithreading:** `multiThreadProcessImages` is empty and host frame threading is disabled. A native XAO port should use bounded, deterministic work partitioning rather than inheriting the serial whole-frame path.
- **Anisotropic render scale:** cell size is scaled using `renderScale.x` only. A robust implementation must account for both axes and pixel aspect ratio, or define cell dimensions in comp-space units and map them correctly.
- **Colour interpretation:** luma uses fixed Rec.601-like coefficients (0.299/0.587/0.114) without an explicit transfer-function/working-space contract. XAO needs a documented linear-light or display-referred strategy.
- **Cell sampling:** 8x8 samples per cell and a brute-force comparison against 95 glyphs is simple and deterministic, but cost grows with number of cells. Precompute masks and use a compact lookup/cache where appropriate.
- **Font limitation:** the supplied 8x8 table is basic ASCII only; it cannot supply Japanese, Arabic, Unicode symbols or user-selected font faces. It is useful as an optional retro bitmap set, not as the XAO typography foundation.

## 3. GlyphBlocks OFX — algorithm

- Splits each cell into four quadrants.
- Accumulates per-quadrant luminance and full-cell RGB average.
- Compares each quadrant mean (after contrast around midpoint) with the full-cell mean and sets one of four bits.
- Uses the four-bit mask to create a 2x2 block mosaic.
- Foreground may use a fixed phosphor scheme (Green, Amber, White, C64 Blue) or the cell's average source colour; background is near-black.
- The final result is mixed with the original source by a mix parameter.
- The implementation is deterministic from source and parameters and preserves source alpha in the output.

## 4. GlyphBlocks — limitations

- The shared helper header `../common/purzfx.hpp` is absent from the supplied archive; this folder cannot be treated as a standalone complete build.
- The project has no verified license file in the supplied folder; do not reuse source until provenance/license is established.
- Cell scaling also uses `renderScale.x` only.
- Grid construction scans the entire source and allocates several temporary arrays per render; this is expensive and repeats work for multiple render windows.
- The quadrant decision uses a fixed 2x2 binary structure; it is a narrow PETSCII/block-mosaic look, not a general Unicode glyph engine.

## 5. XAO decisions

- Keep Structural ASCII matching as a candidate algorithmic mode; compare perceptual glyph matching and SDF matching against it.
- Keep brightness-to-density ramp mapping as a core ASCII mode, but use configurable glyph metrics and controlled font atlases.
- Treat the 2x2 quadrant mask as an independent retro block-mosaic algorithm, not as a replacement for general ASCII.
- Preserve source alpha, support all intended render scales, and use explicit color-space/luma handling.
- Build a full-frame immutable cell-analysis buffer only when required, with caching keyed by source/time/parameters and safe bounds. Do not silently assume tile or frame-threading support.
- No source code is to be copied from GlyphBlocks until its missing dependency and license are resolved.

## 6. Status

This is a source-level review of the two supplied OFX implementations. It does not establish AE-native compatibility, a complete project build, or After Effects runtime correctness. Other ASCII projects and XAO groups remain under audit.
