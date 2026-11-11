# XAO — S1 Parameter Mapping and AE Pixel-Buffer Contract Trace (Pass 48)

Date: 2026-11-10
Scope: correlate the supplied `S1AsciiArt.aex.c` parameter registration with fields consumed by the render routine, and record the AE buffer validation visible at the render entry. Static decompilation analysis only.

## 1. Parameter registration: directly visible labels and choices

The parameter setup routine registers a sequence of parameter IDs. The decompilation exposes these labels and popup entries:

- Section: `Color & Palette`
- `Palette Mapping`: popup choices `Tonal|Original`
- `Palette Color Strength`: floating slider, with the stored value later normalized by dividing by 100.
- Section: `Characters`
- `Blend Mode`: popup choices `Normal|Multiply|Screen|Overlay|Soft Light|Difference|Add`
- Section: `Background`
- Additional section/control labels are obtained through `GetStringPtr(...)`; their exact visible text is not fully recovered from this code excerpt and must not be guessed.

The setup code also registers color parameters, popup controls, checkboxes and numeric sliders. Several parameter IDs are visible in the render routine through the `param_3[index]` accesses, but the mapping from every index to a UI label is not yet fully established.

## 2. Render parameter consumption: confirmed relationships

From the render routine:
- The selected font is read from one parameter and passed through `ForcedFont`; if no forced font applies, another font parameter supplies the selected index.
- A grid/layout-related value is read from the first parameter block and combined with the selected font and other render settings to construct `RenderParams` and `GridMapping`.
- Several boolean controls are packed into render flags. The decompilation shows distinct tests for parameter values 2 and 3, and separate enabled flags from other parameter slots.
- A normalized strength value is read as percentage / 100 and clamped to [0,1].
- Another percentage value is normalized and clamped to [0,1].
- A further percentage-derived setting is clamped to [0,3], so it is not a simple opacity percentage.
- Two color controls are read through the AE ColorParamSuite helper and copied into the render parameter structure.
- A palette popup value is range-checked against 0–9 and selects among hard-coded palette data. The selected palette entries are normalized from 8-bit RGB to [0,1].
- Palette mapping selection is represented separately from palette color strength.
- Blend Mode is registered as seven named choices. The render blend helper exposes the corresponding seven cases: Normal/default, Multiply, Screen, Overlay, Soft Light, Difference and Add. This is the clearest parameter-to-render mapping recovered in this pass.

Caution: the decompiler's stack offsets and packed flag fields are not a stable source-level ABI. Do not use these offsets as XAO parameter IDs or structure layout.

## 3. AE input buffer validation visible at Render entry

The render routine validates before processing:
- Input and output dimensions must be non-zero.
- Input and output pixel pointers must be non-null.
- Input and output row-byte/stride values must be large enough for the expected row width.
- A flag/depth-related bit in the input descriptor is compared with the corresponding output descriptor bit.
- The expected bytes-per-pixel path is selected from that flag: the decompilation derives 4 bytes or 8 bytes per pixel.
- Invalid buffer/depth combinations return an error and set an AE error message: `Invalid input/output pixel buffer or depth mismatch.`
- The routine checks the input/output dimensions and rejects image dimensions that exceed its supported integer range.
- It validates the font atlas is initialized before proceeding.
- It asks `AsciiRenderer::Begin` to create the grid and rejects invalid parameters or working-memory requirements that exceed its limit.

This demonstrates explicit buffer and memory validation in the original plugin. It does not by itself prove correct handling of every AE pixel format, channel order, premultiplication convention, SmartFX request rectangle, or MFR execution.

## 4. Output conversion and alpha: unresolved

This pass did not yet establish a complete, trustworthy mapping of:
- PF_Pixel8 versus PF_Pixel16 or float buffer structures,
- channel ordering and byte offsets,
- straight versus premultiplied alpha at the host boundary,
- whether all source/output color values are linearized or remain in the host working space,
- exact output writeback and alpha preservation for every branch.

The renderer's internal float records and alpha-aware composition do not prove the host boundary's premultiplication contract. This remains a mandatory XAO implementation gate.

## 5. XAO decisions

1. Give XAO explicit typed adapters for each supported AE pixel format; never infer format from an undocumented flag or raw byte count alone.
2. Validate dimensions, pointers, row strides, request bounds and overflow before allocating cell/atlas working memory.
3. Normalize controls into a typed immutable render configuration once per render call; avoid packed bitfields with implicit parameter-index coupling.
4. Keep palette selection, palette mapping mode and palette strength as three separate concepts.
5. Expose blend modes by stable enum and test their equations independently.
6. Define a single alpha contract at the AE boundary and convert to/from the internal working representation explicitly.
7. Add tests for zero dimensions, negative/short stride, overflow, partial bounds, transparent pixels, 8/16/float formats and MFR.

## 6. Next targets

- Recover all UI labels and correlate every registered parameter ID with its RenderParams field.
- Trace S1 output pixel writeback and alpha/channel conversion end-to-end.
- Inspect SmartFX/sequence setup behavior and determine whether this legacy-style render path has any meaningful tile/MFR guarantees.
- Translate the verified behavior into an XAO implementation spec without inheriting S1's uncertain buffer assumptions.

