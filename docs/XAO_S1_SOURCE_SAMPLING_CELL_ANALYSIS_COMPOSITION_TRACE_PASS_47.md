# XAO — S1 ASCII Source Sampling, Cell Analysis and Composition Trace (Pass 47)

Date: 2026-11-10
Scope: trace the supplied `S1AsciiArt.aex.c` decompilation from the AE render routine through `AsciiRenderer::AddSourceRow`, `Finish`, `ComposeRow`, and the pixel-channel blend helpers. This is static analysis of a decompiled listing; it is not original source, pixel-equivalence testing, or an AE runtime test.

## 1. Render setup and row ingestion

Verified in the render routine:
- The plugin constructs an `AsciiRenderer`, calls `AsciiRenderer::Begin` with the atlas, render parameters, grid mapping and render bounds, then feeds source rows through `AddSourceRow`.
- The row-ingestion loop supplies float pixel records to the renderer and finishes the analysis stage with `Finish()`.
- The decompilation shows explicit source pixel channels and alpha being passed into the renderer; the renderer's internal accumulators maintain weighted channel sums and a weight/coverage accumulator per cell.
- `AddSourceRow` maps source scanlines into the configured grid using grid origin and cell spacing. It handles fractional overlap at cell boundaries rather than assuming each source pixel belongs wholly to one cell. The code has separate paths for full coverage and fractional coverage, distributing weighted contributions across adjacent cells.
- Each cell accumulates weighted red, green, blue and alpha-related values, plus total contribution weight. This is an area-coverage integration strategy, not simply sampling one pixel at the cell center.

Interpretation:
- S1's cell analysis is based on integrating source pixels over the grid footprint, including fractional edge coverage. This should reduce aliasing and sensitivity to cell-boundary alignment compared with center-only sampling.
- The exact coordinate conventions and all edge cases should be independently validated before implementing a matching XAO resampler.

## 2. Finish — cell color, alpha and tone

Verified in `AsciiRenderer::Finish`:
- For each cell, the accumulated channel sums are normalized by the accumulated alpha/weight when the denominator is positive.
- A normalized cell alpha/coverage value is computed and clamped to the [0,1] range.
- The normalized RGB is clamped to [0,1] for the tone/color operations visible in this path.
- Cell luminance is calculated with Rec.709 coefficients: 0.2126 red + 0.7152 green + 0.0722 blue.
- Contrast is applied around the midpoint 0.5 using `(luminance - 0.5) * contrast + 0.5`, clamped to [0,1]. An invert flag then maps the result to `1 - tone`.
- A tonal palette lookup is conditionally applied when the corresponding palette/color mode flags are enabled.
- A separate color normalization path scales RGB by the maximum channel under its own mode flags.
- The final tone is passed to `NearestDensityIndex` with a precomputed density array; the resulting index is mapped through a stored glyph-index table and saved as the cell's selected glyph.

Interpretation:
- The base glyph choice is a nearest measured-density lookup driven by the cell's processed luminance.
- The selected glyph index, normalized cell color, tone and alpha are retained as separate per-cell state. That separation is important: tone selects the glyph, while color and alpha can independently influence the final composite.

## 3. ComposeRow — glyph mask and source/backdrop blending

Verified in `AsciiRenderer::ComposeRow`:
- Composition walks the grid cells intersecting the output row and retrieves the cell's selected glyph, tone, alpha and color state.
- It obtains the selected glyph's raster coverage mask from the atlas-backed raster data.
- The glyph mask coverage is combined with cell alpha/opacity and a separate character-strength/opacity factor before contributing to the output.
- The routine supports several character color blend modes through `BlendCharacterChannel`; the helper implements multiple channel operations, including multiply, screen-like, overlay-like, difference and additive/clamped behavior.
- Character color is mixed against the selected source/backdrop color according to the configured blend mode and blend amount.
- The output accumulation uses coverage-weighted contributions and maintains an alpha term; it is not simply a direct replacement of the source pixel with a flat glyph color.
- When no valid glyph is selected, the path can use the configured source/backdrop behavior instead of dereferencing an invalid glyph.

Caution:
- Some decompiler variable names and offsets are opaque. The mode cases can be matched to channel equations in `BlendCharacterChannel`, but the complete UI label-to-enum mapping must be traced from parameter setup before assigning exact names to every mode.
- The code shows an alpha-aware composition path, but exact host pixel format and premultiplication assumptions require a separate trace of the AE render buffer conversion and output writeback.

## 4. Luminance and blend equations visible in the listing

The helper `Luminance(r,g,b)` returns clamped Rec.709 luminance:
`0.2126*r + 0.7152*g + 0.0722*b`.

The helper `Tone(value, contrast, invert)`:
1. Applies contrast around 0.5.
2. Clamps to [0,1].
3. Optionally inverts.

`BlendCharacterChannel(mode, character, backdrop)` clamps both inputs and exposes these operations:
- Default: backdrop channel.
- Mode 1: multiply.
- Mode 2: screen (`a + b - a*b`).
- Mode 3: overlay-like branch based on the character channel's 0.5 threshold.
- Mode 5: absolute difference.
- Mode 6: additive with clamp.
- Mode 4: a nonlinear soft-light-like branch.

The exact UI names and enum mapping beyond these equations remain pending parameter-setup correlation.

## 5. XAO architecture decisions

1. **Resampling:** implement a deterministic area/coverage resampler for each grid cell, with fractional pixel overlap. Keep a cheaper selectable sampling mode only if benchmarks justify it.
2. **Cell state:** store mean premultiplied color, effective alpha/coverage, luminance/tone, selected glyph ID, and optional edge/shape features as distinct values.
3. **Glyph mapping:** use measured glyph coverage with a stable nearest-density search, but allow additional shape/edge-aware scoring as a separate strategy.
4. **Compositing:** keep glyph mask coverage, glyph opacity/strength, character color, source/backdrop color, blend mode and alpha as separate controls/stages.
5. **Color correctness:** define XAO's working color space and premultiplication contract explicitly. Do not blindly copy S1's apparent [0,1] clamp or assume its host buffer format.
6. **Determinism:** precompute immutable atlas/ramp data; keep render-time cell calculations local and deterministic for arbitrary frame order and AE MFR.

## 6. What this pass does not establish

- It does not prove exact visual equivalence to S1.
- It does not establish the full parameter-to-enum mapping for all blend modes, palettes or strength controls.
- It does not establish S1's complete AE pixel-format, SmartFX, GPU, MFR or threading behavior.
- It does not validate any S1 source-code redistribution rights.
- No proprietary code has been copied into XAO.

## 7. Next targets

- Correlate `RenderParams` fields and UI parameter registration with the cell analysis/composition flags and enum values.
- Trace AE input/output buffer conversion and alpha handling around the render function.
- Finish the S1 atlas character-set names and UI mapping.
- Use these findings to write an implementation-ready XAO ASCII pipeline spec, then implement against the existing XAO architecture rather than creating a parallel renderer.

