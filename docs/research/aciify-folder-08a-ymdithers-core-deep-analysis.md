# YMDithers native core — focused source pass (supplement to Folder 08)

This is a deeper pass over `TAKE RIGHT BUILD/core/` and the AE wrapper. It supplements [folder 08](aciify-folder-08-take-right-build-analysis.md). **Source is analyzed only; no transplant or build.**

## Core files
- `core/majeed_core.h` (4,410 bytes): shared core contract.
- `core/dither.cpp` (28,906 bytes): dither/palette/algorithm implementation.
- `core/lines.cpp` (35,356 bytes): procedural strokes and object-contour engine.
- `ae/ymdithers_ae.cpp` (27,732 bytes): AE parameter/event/render wrapper.

## Shared data model (`majeed_core.h`)
- `Color`: float RGB.
- `Image`: width, height and pointer to contiguous float RGBA pixels; `at(x,y)` clamps coordinates and returns a 4-float pixel pointer.
- `LinesParams`: many independent controls—enabled, count/length/width and randomization, angle, color/color mode, opacity; object-contour settings; hand-made curve; duplicate stroke settings; animation speed/randomness/amount.
- Enums distinguish single/sampled/random line color and along/perpendicular/random/custom edge direction.
- This float RGBA abstraction is convenient for algorithm code but requires an AE adapter: PF worlds may be 8/16/32 bpc, different rowbytes, channel order, alpha/premultiplication and region bounds. Do not reinterpret AE pixel memory as this buffer without conversion/stride handling.

## Dither core (`dither.cpp`)
- Defines RGB palette structures and named 2-/4-color palettes (monochrome, phosphor green, lava, red, Game Boy, cyberpunk, amber CRT).
- Contains Bayer 2×2 and 4×4 threshold matrices (normalized 0–1); source includes more algorithm/palette implementation below the initial section.
- Dither implementation should be treated as a separate pure-processing stage, with inputs normalized and parameters explicit.
- Porting must preserve algorithm-specific scan order, error propagation, serpentine behavior, boundary clamping and deterministic seed semantics. Error diffusion is inherently neighborhood/stateful; naïve tile parallelization can change output. Ordered dithering is easier to parallelize and MFR safely.
- Color palette quantization and monochrome thresholding should be tested against known fixtures; RGB and alpha are not interchangeable.

## Lines engine (`lines.cpp`)
Header describes a contour-following procedural strand engine:
- Object mode: multi-scale Gaussian prefiltering, multi-channel Sobel gradients, Canny non-maximum suppression, subpixel ridge refinement and 8-direction connected contour chain tracing.
- Hand-made mode: organic curve/wobble with a curve control while anchoring to contours.
- Duplicate strokes: parallel companions with independent count/spacing/length/width/opacity.
- Animation follows contours rather than detaching.
- Bounded-memory and NaN/Inf guards are explicitly advertised; implementation includes `safe_flt`, contour-node tangent/normal and arc-length data, and vectors for chains/segments.
- Rasterization is described as row-banded bounding-box and optimized for high counts (the comment claims 10,000+ lines); this performance claim has not been benchmarked here.
- Input alpha is clamped; RGB channels and Rec.709 luma are separately cached in contour extraction. Image accessor clamps at boundaries.

**Potential XAO lesson:** contour tracing and line rasterization are a distinct optional effect—not part of ASCII glyph conversion. It could become a separate “contour strands” mode only after scope approval and performance testing.

## AE wrapper (`ae/ymdithers_ae.cpp`)
- Declares effect version macros and a parameter ID enum grouped by Dither, Lines, Object, Hand-made, Duplicate and further sections.
- Dither controls include algorithm/color mode/blend/amount/strength/scale/white-black/levels/threshold/pattern scale-angle/contrast/brightness/randomness/serpentine/linear-gamma/pixelate/animated noise/seed.
- Lines and object controls map to the shared `LinesParams` concept.
- This demonstrates a large parameter surface organized into groups, but parameter UX complexity is substantial. XAO should selectively expose controls and avoid copying a large panel wholesale.

## Engineering cautions before any XAO reuse
1. **MFR:** confirm every render invocation owns its scratch buffers/state; no mutable global random state or shared image scratch. AE sequence data must be used according to host lifecycle.
2. **Memory:** `Image` uses float RGBA (16 bytes/pixel); full-frame conversion can be costly. Consider bounded buffers, reuse per render, and region/tile processing.
3. **Alpha:** explicit policy for premultiplied vs straight alpha, transparent pixels and compositing.
4. **Rowbytes/bounds:** adapt PF world rowbytes and render rectangles; avoid assuming contiguous host memory.
5. **Color management:** determine whether values are linear or display-encoded; palette/luma math should match XAO's chosen pipeline.
6. **Determinism:** use stable seeds/frame time for scrubbing and repeated renders; animated random must not depend on worker scheduling.
7. **Algorithm parity:** create fixed input images and parameter snapshots, compare output pixels for each ported method.
8. **Licensing:** this folder's code provenance/license remains to be established. No code copy is authorized by this research report.

## Scope of this pass
Core/header and wrapper file sizes and representative declarations/algorithm sections were inspected; this is not a line-by-line audit of every function. No compile, AE load, image parity, MFR stress, memory/performance benchmark, or UI interaction test was run.
