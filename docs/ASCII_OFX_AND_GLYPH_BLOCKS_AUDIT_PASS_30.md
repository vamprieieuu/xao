# ASCII OFX and Glyph Blocks Source Audit — Pass 30

Date: 2026-11-07
Scope: targeted review of the supplied `ascii.cpp` and `glyphblocks.cpp` OpenFX sources. They are reference implementations, not native AE plugins.

## 1. ASCII OFX — two different algorithms

The source implements two modes using an embedded 8×8 bitmap font:
- **Structural:** sample 64 luminance positions within each cell, threshold each sample against the cell's mean, then compare the resulting 64-bit mask against ASCII glyph bitmaps using Hamming distance. Search is limited to printable codes 32–126.
- **Brightness:** average the 64 luminance samples and select a character from a 70-character density ramp.

Other details:
- Cell grid is derived from output dimensions/aspect ratio; default cell range 2–64.
- Foreground is either one of three fixed phosphor schemes (green, amber, white) or source-sampled colour.
- Contrast is applied around 0.5 before glyph selection.
- The grid is built once, then the output render window is painted from cached per-cell glyph codes and colours.
- The included 8×8 font is intended to avoid a runtime font dependency.

### Critical limitations
1. **RGBA alpha is forced opaque.** For four-channel output, every pixel's alpha is set to the maximum, including glyph background pixels. This is unsuitable as XAO's default transparency contract.
2. **Single-byte glyph set only.** The bitmap table covers 128 codes and the search only 32–126. It cannot render Arabic, Japanese, Unicode or user font files.
3. **No host image threading.** `multiThreadProcessImages` is empty; the grid build and per-pixel output are serial.
4. **Tile behavior is constrained.** The processor builds a whole-frame grid before writing the render window. This is not naturally compatible with independent tile renders unless the host is told tiles are unsupported or a deterministic global-grid cache is provided.
5. **Luma uses Rec.601 coefficients.** XAO must use a documented working-space policy and not blindly copy these coefficients.
6. **Output grid is tied to output dimensions.** XAO should normally anchor grid phase in source/layer coordinates so crop changes, region renders and scaling do not cause glyph crawl.
7. **Sampling and writing use separate coordinate calculations.** The source carefully accounts for OFX bottom-up y coordinates; an AE port must explicitly map origin conventions and rowbytes.

Decision: retain the *structural glyph matching* concept as an optional ASCII mode. Rebuild it with the XAO glyph atlas/shaping system, proper Unicode/font support, soft coverage, alpha preservation and AE-safe global grid coordinates.

## 2. Glyph Blocks OFX — PETSCII-style 2×2 quadrant engine

The source divides each cell into four quadrants. It computes the mean luma for each quadrant and the full cell, then sets one of four bits when a quadrant's contrast-adjusted mean exceeds the cell mean. Rendering fills each quadrant with either:
- a selected phosphor colour,
- the cell's average source colour,
- or a dark background.

A mix parameter blends the stylized output with the source. The source alpha is copied to output, unlike the ASCII OFX implementation.

### Limitations and risks
- Cell sizes are limited to 4–24 pixels.
- The source uses four coarse quadrants, so it produces block glyphs, not font glyphs.
- The source is scanned over the full frame to build the grid and the processor's multi-thread callback is empty.
- Cell size is scaled using `renderScale.x` only; non-uniform render scale / pixel aspect needs more careful handling.
- The source depends on `../common/purzfx.hpp`, which is absent from the supplied folder. Its full host helper behavior cannot be audited from this file alone.
- No clear redistribution license was established in the supplied folder; do not reuse code until rights are confirmed.

Decision: the 2×2 quadrant representation is a useful independent ASCII/Glyph Blocks mode for XAO. Implement the bitmask logic independently and support adjustable quadrant subdivision (2×2, 3×3, 4×4), mask coverage, palette and source alpha.

## 3. How these references fit XAO

Keep three concepts separate:
- **Glyph ASCII:** actual font glyphs selected by luminance/structure.
- **Structural ASCII:** glyph shape selected by matching local image structure, not only brightness.
- **Glyph Blocks:** font-independent quadrant/block symbols.

All three can share the common XAO cell sampler, grid transform, palette and compositor, but should have distinct mode-specific analysis and glyph/shape selection.

Smart Object Tracker integration can gate each cell's coverage with the shared soft object mask. For structural mode, the mask should be included in the 64-sample comparison so pixels outside the subject do not influence the chosen glyph.

## 4. Lines exclusion

The separate Dither Majid **Lines** effect remains excluded. This audit concerns two ASCII/Glyph Blocks OFX implementations only; it does not authorize a standalone Lines engine.

## 5. Status

Targeted source review only. Glyph Blocks depends on a missing helper header and has no verified reuse license. No XAO build or AE runtime test was performed; the full archive audit remains in progress.
