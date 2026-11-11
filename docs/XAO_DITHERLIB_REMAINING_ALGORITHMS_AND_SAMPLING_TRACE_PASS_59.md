# XAO Ditherlib Remaining Algorithms and Sampling Trace — Pass 59

Date: 2026-11-10  
Upstream: https://github.com/Downmoto/ditherlib  
Audited ref: `master`  
License: Apache-2.0 (see Pass 58)

## Riemersma / Hilbert-curve diffusion

The implementation walks logical cells along a Hilbert space-filling curve. It retains a bounded FIFO history of recent quantisation errors (default length 16), weighted by exponentially decaying weights (default newest-to-oldest ratio 16:1). The adjusted source is clamped to 8-bit RGB, quantised to the nearest palette entry, and the source-minus-quantised error is appended to history.

Important boundary behavior:
- A discontinuity in the clipped rectangular Hilbert traversal resets the error history.
- A cell with no selected sample also resets history.
- Logical cell dimensions, image-space grid offset, and sampling mode are configurable.
- The Hilbert square is padded to the next power-of-two side and out-of-rectangle points are skipped. The source itself notes recursive pruning as a future optimization for very narrow, high-resolution images.

XAO implication: this is a distinct, sequential error-diffusion look, not ordinary raster error diffusion. The padded square traversal can be wasteful for extreme aspect ratios. Preserve deterministic traversal and reset rules; do not claim MFR/tile independence without designing a frame-global or region-aware execution strategy.

## Ostromoukhov variable-coefficient diffusion

The source embeds the 128-entry coefficient table attributed in comments to Appendix I of Victor Ostromoukhov, “A Simple and Efficient Error-Diffusion Algorithm,” SIGGRAPH 2001. Tone values above 127 mirror the table index. Processing is serpentine, with row direction anchored to the logical image row.

- Each RGB channel independently selects its coefficient triplet from its error-adjusted tone.
- The three weights are normalized by their own sum.
- Contributions go to the forward same-row, backward next-row, and same-column next-row destinations (mirrored according to scan direction).
- Two row buffers and two error buffers are swapped as the scan advances.
- A target receives error only if its logical cell has a valid selected sample.
- Errors use fixed-point scale 256.

XAO implication: high-value tone-adaptive diffusion reference. Preserve the published table and exact coefficient indexing if implementing this algorithm; add fixture comparisons against known reference outputs. The implementation is sequential and cannot be naively split into independent AE render tiles.

## Palette construction and matching

The palette module supports:
- Explicit non-empty RGB palettes.
- Source-derived palettes that ignore fully transparent pixels.
- All distinct visible source colours in first-seen order, using a 24-bit colour-presence bitset.
- Limited palettes using deterministic frequency-weighted median cut. Splitting chooses the widest RGB channel, then a population-balanced split; representatives are actual source colours nearest to each bucket's weighted mean, with deterministic tie ordering.
- Matching in RGB, linear RGB, or Oklab (colour-space transforms detailed in Pass 58).
- Full-colour or luminance-only matching. Equal-distance ties retain the earlier palette entry.
- Built-in monochrome, black/white, greyscale, Game Boy, CGA, and PICO-8 palettes.
- A fast exact-colour membership path for palettes derived with all source colours.

XAO implication: source-derived palette workflows and stable tie-breaking are useful. The 24-bit bitset uses 2 MiB, which is reasonable but should be an explicit memory/performance decision in XAO. Median cut here is RGB-channel range based, not perceptual-space clustering. Do not label it perceptual median cut.

## Cell sampling and selection behavior

Logical grid supports five sampling modes:
1. Average: mask-coverage-weighted RGB average.
2. Centre: selected source pixel nearest the cell centre.
3. Darkest: selected pixel with minimum integer RGB luma.
4. Lightest: selected pixel with maximum integer RGB luma.
5. Dominant Colour: exact RGB value with greatest accumulated mask coverage; ties preserve earliest encounter order.

- Cell bounds are clipped to image dimensions.
- Grid index uses Euclidean division, so negative offsets anchor consistently.
- Cells are anchored to image coordinates, not the selection bounding box.
- Zero-coverage pixels are skipped.
- Writes preserve the original alpha byte and modify only selected pixels.
- Dominant Colour allocates a hash map per sampled cell; this may be costly for large cells/high-colour images.

XAO implication: the five sampling modes can become a shared grid-sampling capability across Dither and Halftone engines. Native implementation must generalize to AE 8/16/32-bpc and explicitly handle premultiplied alpha; this upstream code is RGBA8 and must not be copied as the AE pixel contract.

## Ordered threshold maps

The inspected threshold module provides:
- Validated custom row-major rank maps; dimensions, rank count and rank range are checked.
- Bayer 2×2, 4×4, 8×8.
- Built-in 16×16 blue-noise map (same fixed rank table described in Pass 58).
- Clustered dots 6×6.
- Horizontal lines, vertical lines, diagonal lines, crosshatch, checkerboard.
- Dispersed-dot 3×3 and 5×5.
- Ordered-map rotation (0/90/180/270°), horizontal/vertical mirroring, x/y offset, strength [0,2] quantized to 1/256.
- A specialized fast path for untransformed Bayer 2×2/4×4/8×8 maps.

XAO implication: custom rank-map support is more valuable than a hardcoded list alone. A native XAO pattern asset format should validate dimensions and ranks, preserve deterministic image-origin anchoring, and expose transforms without shifting the pattern when AE requests a subregion.

## Verification boundaries

This pass inspected the implementation source for Riemersma, Ostromoukhov, palette, cells, and threshold. It did not run the upstream Rust tests or benchmarks. Although a test module exists and was inspected in part during the previous pass, this report does not claim the entire test suite passes. No code was copied into XAO.

## Recommended native implementation order

1. Implement shared logical-grid sampling with explicit float/16-bit/8-bit pixel adapters and alpha-preserving fixtures.
2. Implement ordered threshold maps (Bayer, custom maps, clustered and line patterns) as image-coordinate deterministic parallel passes.
3. Implement stateless white/blue noise after validating the blue-noise tile spectrum and periodicity.
4. Implement palette matching and deterministic source palette derivation.
5. Implement sequential error diffusion (including serpentine) with clearly documented full-frame/tile limitations.
6. Implement Hilbert Riemersma and Ostromoukhov as sequential algorithms, benchmarked independently.
