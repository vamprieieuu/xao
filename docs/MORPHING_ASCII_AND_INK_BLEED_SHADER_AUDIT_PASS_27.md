# Morphing ASCII and Ink Bleed — Detailed Shader Audit (Pass 27)

Date: 2026-11-07
Scope: full targeted review of the supplied Morphing ASCII toolkit's `AsciiEffect.js`, `InkBleed.js`, `MemoryGrid.js` and parameter documentation. This is source-level research, not an XAO implementation or runtime test.

## 1. ASCII renderer: complete pipeline

The renderer builds two horizontal glyph atlases:
- Alpha atlas: white glyph pixels on transparent background.
- SDF atlas: one signed-distance field per glyph, generated with a separable Felzenszwalb-Huttenlocher Euclidean distance transform (row/column passes, O(n) per line).

For each output pixel:
1. Compute its fixed grid cell from drawing-buffer pixel coordinates.
2. Sample one representative source colour at the cell centre, or use the per-cell temporal memory texture.
3. Compute Rec.601-style luma, then gamma/contrast/brightness.
4. Optionally evaluate Sobel gradient from the eight neighboring cell centres and select a directional contour glyph.
5. Otherwise map inverse luma to a glyph-density index, apply deterministic cell-index hash jitter, and choose a single glyph or blend adjacent glyphs.
6. Optionally interpolate two glyph SDFs and threshold the interpolated field to morph one shape into another.
7. Apply colour mode, white cutoff, per-character mottling and a static noise layer.

### Valuable design ideas for XAO
- Separate cell size from glyph scale; density and glyph footprint are different controls.
- Separate character atlas from SDF atlas so normal crisp rendering does not pay the SDF cost.
- Use deterministic cell-index variation, not frame-random variation.
- Use Sobel edge orientation to select directional glyphs.
- SDF interpolation is a genuine shape morph, unlike alpha cross-fade.
- Skip optional noise/mottling work entirely when its amount is zero; the source explicitly uses a no-op fast path for mottling.
- Expose independent noise blend modes and a separately controlled white cutoff.

## 2. Critical host-port issues

1. **Alpha is forced opaque.** All four ASCII colour-mode branches write `outputColor.a = 1.0`. The source effect therefore does not preserve the input alpha. XAO must preserve source alpha/coverage and composite glyph/background modes explicitly, including premultiplication.
2. **Unicode indexing is not glyph shaping.** `charset.length` and `charset[i]` operate on UTF-16 code units. Supplementary characters can split into surrogate halves; combining marks, Arabic joining, ligatures and grapheme clusters are not handled. The atlas uses a fixed browser font stack, not the user's installed/supplied font selection. XAO must build glyph atlases from shaped glyph IDs and actual font metrics.
3. **One centre sample can miss detail.** A cell's representative colour is a single centre sample. XAO should support centre, multi-sample and area-average modes, plus optional edge-aware sampling.
4. **Edge detector reads beyond image bounds.** Neighbor UVs are sampled without explicit clamping in this shader. Browser texture wrap behavior can affect borders. XAO should define clamp/reflect/transparent edge policy explicitly.
5. **Sobel cost is paid per output pixel.** The shader computes the same cell-level Sobel neighborhood for every pixel in the cell. XAO should compute cell analysis once into a low-resolution feature buffer, then render the glyph pass from that buffer.
6. **The SDF atlas scales linearly with charset length.** A single texture of width glyphSize × charset length can exceed texture limits for large or multilingual sets. Use atlas pages/texture arrays, lazy glyph caching, explicit maximum dimensions and LRU eviction.
7. **SDF raster threshold is binary.** Alpha >127 defines inside/outside. Thin glyph details may vanish; per-font/per-glyph padding and SDF spread need validation.
8. **Hard white cutoff can pop.** The documented cutoff is a hard threshold, so a cell can suddenly disappear when it crosses it. XAO should offer a soft threshold/feather option.
9. **Luma convention differs across code.** The ASCII shader uses Rec.601-style luma constants while other reviewed engines use Rec.709-style values. XAO should centralize working-space/luma selection rather than silently mixing conventions.
10. **Colour mode output is not an AE compositing contract.** Some modes create white or configured backgrounds and the shader emits opaque output. XAO must distinguish glyph alpha from background fill and offer transparent-background behavior.

## 3. InkBleed: algorithm and performance

The post-process samples 64 points distributed across a disk using a Vogel/golden-angle pattern. Per-sample weights are Gaussian-like `exp(-r² × 2.2)`. It computes:
- A darkness-weighted ink colour and coverage for bleed.
- A weighted colour average for blur.
- Separate bleed and blur mixes.
- An early-out when both amounts are zero.

The author precomputes the 64-entry kernel into a float texture on the GPU and reads it back to avoid repeated transcendental math. A host-side JavaScript kernel is a fallback when float render targets are unavailable. The source reports a performance measurement on an Apple M1 Pro, but that measurement is not transferable to XAO's CPU renderer.

### XAO implications
- A literal 64-tap full-resolution CPU port is too expensive as a default. Use a downsampled pyramid, separable blur, or bounded radius-dependent sample count, with preview/final quality modes.
- Precomputed kernel tables are useful, but XAO should generate deterministic constants on the CPU or use a shared immutable table; do not depend on a GPU render/readback during effect initialization.
- The kernel's weights and coordinates should be normalized and tested for radius/aspect ratio and edge behavior.
- The bleed stage preserves `inputColor.a` but computes its RGB from sampled RGB values. XAO must test transparent edges and premultiplied input explicitly to avoid colour fringes.
- The current luma calculation uses Rec.601-style weights and treats dark RGB as ink. XAO should support linear-light and selected working-space semantics.
- Keep bleed as a separate optional post stage, not baked into the glyph atlas. This permits applying it to ASCII, Halftone or other ink-like engines.

## 4. MemoryGrid and temporal determinism

The state shader updates one texel per ASCII cell using exponential smoothing:
`k = min(1 - exp(-dt × rate), MAX_STEP)`, then mixes prior state toward current cell colour. Its alpha stores residual luminance activity used to control glyph cross-fades/morphing.

The implementation:
- Uses two ping-pong render targets.
- Prefers half-float, then float, then 8-bit fallback.
- Clamps `dt` to 0.1 seconds.
- Reinitializes both buffers after resize/reset.
- Depends on the order and elapsed time of calls to `update(dt)`.

This confirms the feature is a history-dependent simulation, not a deterministic function of absolute source time. It must not be used as mutable render state inside XAO's AE Smart Render/MFR path. Use precomputed immutable per-frame states or a deterministic absolute-time formulation.

## 5. Recommended XAO ASCII pipeline

1. Source sampling and working-space conversion.
2. Low-resolution cell feature analysis (colour, luma, gradient, optional motion/mask coverage).
3. Shaped glyph selection and deterministic variation.
4. Glyph atlas/SDF rendering.
5. Optional edge-glyph substitution.
6. Optional ink bleed / blur pyramid.
7. Mask and alpha-aware compositing in the common XAO compositor.

This pipeline also makes Smart Object Tracker integration natural: the tracker mask can gate cell coverage or alter glyph density without coupling AI inference to the ASCII renderer.

## 6. Lines exclusion

The separate Dither Majid **Lines** effect remains excluded in full. The directional contour glyphs described here are part of the ASCII renderer's edge treatment, not the standalone Lines effect. Line-shaped Halftone marks remain a separate geometry option within Halftone.

## 7. Status

This is a targeted source review of the supplied Morphing ASCII files. It does not mean every archive file or every video frame has been fully audited. No XAO build or AE runtime test was performed.
