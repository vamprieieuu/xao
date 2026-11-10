# XAO — ditherlib Halftone and Colour Separation Implementation Trace (Pass 57)

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Upstream: https://github.com/Downmoto/ditherlib
Files inspected: `src/effects/dither/halftone.rs`, `src/selection.rs`, `src/renderer.rs`, and `src/effects/dither/` source inventory.

## 1. Halftone implementation — observed source behavior

The concrete `Halftone` type stores:
- a target palette;
- one of Circle, Square, Diamond, Ellipse, Line or Cross shapes;
- independent cell width and height (default 8×8);
- clockwise screen angle in radians;
- phase offsets in image pixels along rotated axes;
- positive dot scale (default 1.0).

The implementation calls `halftone_threshold(shape, cell_width, cell_height, angle, phase, scale, x, y)` using pixel-centre coordinates `(x+0.5, y+0.5)`. It converts the threshold to a signed brightness adjustment around 0.5, adds that adjustment equally to R, G and B, clamps each to 0..255, then selects the nearest palette colour. This is a threshold-modulated palette quantizer; it is not simply drawing a black dot over a paper background.

Cell dimensions must be non-zero; angle and phase must be finite; scale must be finite and positive. The type defaults to 8×8 cells and scale 1.

## 2. Colour-halftone model — confirmed API/source declarations

The same source defines:
- RGB and CMYK channel modes;
- per-channel screen angle and offset;
- shared shape, cell width/height and scale;
- traditional CMYK preset and a moiré-resistant preset;
- separate screen-channel identities for R/G/B/C/M/Y/K.

The source documents CMYK as under-colour removal, independent screening of four subtractive channels, then recombination into RGB. This pass inspected the declarations and setup, but did not yet complete the entire per-pixel CMYK implementation trace. Do not treat the full CMYK equations as audited.

## 3. Selection and compositing — important AE caveat

The library's renderer is explicitly RGBA8, row-major, four bytes per pixel. It copies immutable source bytes into a reusable current buffer, applies each effect into a scratch buffer, and swaps buffers for ordered pipeline execution.

Polygon selections are rasterized with a fixed 4×4 subpixel sample grid. Partial mask coverage is composited after the effect returns. The final renderer blends all four RGBA channels independently using integer weighted interpolation.

The Halftone effect itself writes only RGB bytes; it leaves the alpha byte unchanged. This is not enough to prove correct premultiplied-alpha behavior for XAO. The library's generic RGBA8 storage does not define the AE host's premultiplication or 16/32-bpc contract.

## 4. XAO design implications

- Retain the concept of image-coordinate anchored screens with independent angle and phase.
- Keep cell width and height independent; non-square screens are supported by the reference API.
- Preserve geometric shape as a true threshold field, not an overlay asset.
- Keep palette selection distinct from screen geometry.
- For XAO, compute screen phase from absolute source-image coordinates so AE tile requests do not restart the pattern at tile origin.
- Do not copy the RGBA8 renderer or its selection compositor into the AE adapter. XAO must use its own typed 8/16/32-bpc pixel bridge and explicit alpha rules.
- Add reference fixtures for shape, angle, phase, cell aspect ratio, scale and palette selection before implementing equivalent C++.

## 5. Remaining source work

The source inventory confirms separate modules for:
- `cells.rs`
- `colour.rs`
- `diffusion.rs`
- `halftone.rs`
- `noise.rs`
- `ostromoukhov.rs`
- `palette.rs`
- `riemersma.rs`
- `threshold.rs`
- a substantial `tests.rs`

Next trace the actual CMYK conversion/recombination, blue-noise construction and tiling, diffusion kernels/scan order, and tests/fixtures. Do not assume a feature is verified from its filename or public enum alone.

## 6. Verification boundary

This pass inspected actual upstream source for Halftone, Selection and Renderer plus the complete dither module file inventory. It did not run Rust tests or benchmarks, and it did not complete source-level verification of every dither module. No source was copied into XAO.
