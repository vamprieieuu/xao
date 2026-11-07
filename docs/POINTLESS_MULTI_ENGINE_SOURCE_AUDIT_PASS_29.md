# Pointless Multi-Engine Source Audit — Pass 29

Date: 2026-11-07
Scope: targeted review of the supplied Pointless source project, focusing on core renderers, animation, grid generation, shared sampling, compositing and threading. Pointless is GPL-3.0; this is a feature/architecture study only.

## 1. Licensing boundary

The project is GPL-3.0. Do not copy, port, translate, or adapt its implementation into a proprietary XAO binary unless the project makes an explicit GPL compliance decision and satisfies the license. Names of algorithms and independently designed behavior can inform requirements; implementation code and derivative code are not a safe reuse path. Keep this source isolated from XAO production code.

## 2. Architectural value

Pointless is a useful example of a multi-engine creative renderer:
- Separate renderer modules for ASCII, Dither, Halftone, Mosaic and Dot Grid.
- Shared grid generation, cell sampling, color math, tonal/palette mapping and blend compositing.
- Per-layer parameters and layer/document animation tracks.
- CPU renderers plus selected GPU paths, with explicit GPU eligibility checks and CPU fallback.
- A global QtConcurrent pool helper that divides independent rows into chunks.
- Cached glyph/text atlases and pre-warmed ordered-dither masks.

This reinforces the XAO design: independent engines should share infrastructure (sampling, palette, mask, compositing, cache, time mapping) rather than each reimplementing it.

## 3. Dither engine — algorithm families confirmed in source

The source contains distinct implementations for:
- Ordered: Bayer, clustered-dot, blue-noise, void-and-cluster, custom pattern, analytic line-hatch.
- Error diffusion: Floyd–Steinberg, False Floyd–Steinberg, Jarvis–Judice–Ninke, Burkes, Atkinson, Sierra, Sierra Lite and Stucki.
- Variable error diffusion: Ostromoukhov coefficient-table method.
- Riemersma: Hilbert-curve traversal with a weighted error history.
- Dot diffusion: class-matrix processing.
- Threshold / multi-tone mapping.

### Important implementation lessons and limitations
- Error diffusion is inherently scan-order dependent and cannot be parallelized by independent rows without changing results. The source keeps diffusion raster processing sequential (optionally serpentine), while row-parallel work is used for independent operations.
- Ordered masks can be parallelized by output rows because each pixel is independent.
- The GPU path is intentionally limited to ordered/threshold modes and rejects unsupported tonal combinations. This is a sound pattern: capability checks and explicit CPU fallback, not pretending every algorithm has a GPU equivalent.
- The source precomputes Bayer/blue-noise/void-cluster masks and uses deterministic static data. XAO should make any random/custom mask seed explicit and stable.
- The code has both linear-light and gamma/perceptual-space buffer paths, chosen according to the tonal mode. XAO must make this policy deliberate and documented rather than mix spaces accidentally.
- Several paths composite transparent source pixels over white for print-like dither output. That is a valid effect choice but must not become XAO's universal alpha behavior. XAO should offer explicit paper/background treatment and preserve source alpha when transparency is requested.

## 4. Shared cell sampling and color-space warning

The shared CellSample helper averages source RGB in linear light and separately records linear luminance. It exposes two perceptual tone derivations:
- sRGB-encode the mean linear luminance.
- Calculate perceptual luma from the individually averaged linear RGB channels.

The source explicitly warns these are not mathematically equivalent and different engines use different variants. This is a useful caution: XAO should standardize a canonical working-space pipeline but allow engine-specific perceptual mapping when visual behavior requires it. Add regression images before unifying any existing algorithms.

The cell sampler clamps the requested cell rectangle at image edges. Empty cells have a default white mean and an explicit `empty` flag; each caller chooses its own fallback. XAO should keep empty-cell policy explicit rather than silently treating missing coverage as black or white.

## 5. Animation model — not directly suitable for AE timing

Animation tracks store integer frame numbers, values and easing. Supported easing includes Linear, Hold, cubic Ease In, cubic Ease Out and cubic Ease In/Out. Parameters can be animated at document or per-layer scope.

This is a useful control/UX reference, but XAO must not use integer frame index as its canonical time. AE supports rational frame rates, non-integer rates, time remapping, reverse playback and subframe requests. Evaluate all XAO animation from absolute AE time using the host time scale (or a normalized rational representation), with deterministic interpolation and explicit behavior outside the key range.

The `upsertKey` implementation updates a key's value but retains its previous easing when a key already exists. This may be intentional, but XAO's key-edit UX should make easing retention/replacement explicit.

## 6. Grid generator and cell layout

The grid generator supports transformed square and hexagonal layouts, rotation, stretch factor/angle, follow-grid-rotation, image-centred lattice phase and bounds computed by inverse-transforming the image corners. This is a strong conceptual basis for XAO's shared grid system.

For XAO:
- Grid phase must be anchored in source/image coordinates by default to avoid cell crawling.
- Rotated/stretched grids need correct inverse bounds and render padding.
- Pixel aspect ratio and non-square render scales must be included.
- Randomized cell selection must be deterministic from cell identity + seed + absolute time, not iteration order.
- Hex/square lattice and shape geometry are separate from engine-specific marks.

## 7. Compositor

The source includes separable blend functions, non-separable PDF-style blend helpers (Hue, Saturation, Color, Luminosity families), and deterministic coordinate hashing for Dissolve. It provides a useful coverage of blend-mode requirements.

XAO still needs a rigorously tested compositor contract:
- Define straight vs premultiplied alpha at every boundary.
- Apply blend functions to unassociated RGB in the correct compositing formulation.
- Preserve/compute alpha according to the selected blend mode and effect policy.
- Define linear-light vs gamma-space blending.
- Test zero alpha, partial alpha, HDR values and out-of-bounds padding.

Do not copy its compositor wholesale; treat it as a reference checklist.

## 8. Parallelism and MFR

Pointless uses QtConcurrent's global thread pool, with a small-workload serial fallback and bounded chunks per call. This is safer than creating a new set of threads per row pass, but it is still a standalone application's global pool and is not an AE render contract.

XAO should not blindly nest its own pool inside AE's concurrent frame rendering. Establish one CPU budget, avoid unbounded nested parallelism, and benchmark MFR on the actual target machine. Sequential diffusion algorithms remain serial within each frame unless a mathematically equivalent parallel algorithm is implemented.

## 9. Smart Object Tracker connection

Pointless's shared cell sampler/grid and layer compositor suggest a clean XAO integration point: the Smart Object Tracker emits a soft per-pixel mask plus object ID, confidence and motion metadata. Each engine consumes this common mask:
- Dither: gate coverage/threshold or restrict cell processing.
- ASCII: gate glyph coverage and optionally bias cell selection by object motion.
- Halftone: clip ink coverage to the mask.
- Mosaic/Array: select cells inside the tracked object.
- Glow/Rays/Glint: use the mask as source/highlight isolation and as a composite matte.

Do not make each engine run AI or own a separate tracking cache. Tracking analysis remains an offline preprocessing stage; render engines read immutable, timestamp-indexed mask data.

## 10. Status

This is a focused review of selected Pointless source modules. Pointless remains GPL-3.0 and is not approved for code reuse in XAO. This does not complete the full archive audit, all visual references, or AE runtime verification. No XAO build was performed.
