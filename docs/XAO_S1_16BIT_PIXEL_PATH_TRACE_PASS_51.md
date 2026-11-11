# XAO — S1 16-bit Pixel Path and Parameter-Mapping Boundary (Pass 51)

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Scope: inspect the supplied `S1AsciiArt.aex.c` decompilation around its 16-bit source conversion and output writeback; establish what is and is not proven.
Status: static decompilation only. No AE SDK headers or runtime tests were used.

## 1. 16-bit source path

The render routine selects the 16-bit branch when its depth-related flag is set. It reads 16-bit channel values from the input row, reorders the packed components using SIMD shuffle operations, converts them to floating point, and multiplies by a constant held in a read-only data vector.

The decompilation shows:
- 16-bit component extraction using masks/shuffles;
- conversion from integer components to float;
- normalization through a shared vector constant;
- four float components per pixel passed to the same `AsciiRenderer::AddSourceRow` interface used by the 8-bit path.

The exact numeric value and semantic name of the normalization constant are not recovered in this excerpt. It is therefore not safe to label this as a verified 1/32768 or 1/65535 conversion from the shown code alone.

## 2. 16-bit output path

The output branch writes four 16-bit values per pixel using four consecutive `short` stores at offsets 0, 2, 4 and 6 bytes.

The values are derived from four floating-point output components:
- the alpha-like component is clamped to [0,1], then quantized using a multiplier of 32768 and rounding by +0.5;
- each of the three color-like components is clamped to [0,1], quantized using the same 32768 scale and rounding, then capped at the quantized alpha value;
- the stored 16-bit components therefore use an explicit 0..32768 range in this writeback path, not the full unsigned 0..65535 range.

The color-to-alpha cap is consistent with premultiplied output, matching the 8-bit path's explicit color <= alpha clamp.

## 3. What this establishes

For this reference plugin's observed 16-bit path:
- a 16-bit input conversion path exists;
- four components per pixel are expanded to float for rendering;
- four 16-bit output components are written;
- output quantization uses 32768 as the scale;
- each output color component is constrained not to exceed the output alpha component.

This is strong reference-specific evidence for a premultiplied integer 16-bit output path.

## 4. What remains unproven

The supplied decompilation does not, in this pass, conclusively establish:
- the exact channel names/order in the 16-bit source and destination structures (the SIMD shuffles are visible, but the SDK type declarations are not);
- the exact input normalization constant;
- handling of values outside the nominal normalized range or HDR;
- transfer-function/linear-light semantics;
- any 32-bpc float pixel path;
- whether the source and destination alpha flags can differ.

Do not infer that this legacy reference supports PF_PixelFloat. The inspected render branch visibly distinguishes 4-byte and 8-byte pixels only.

## 5. Parameter registration versus render fields

The same source contains a parameter setup routine and a render routine, but the decompiler's recovered stack slots and `param_3[index]` accesses do not form a reliable symbolic mapping by themselves. Some labels are literal strings; others are resolved by `GetStringPtr`. The render routine consumes a selected font, grid/layout values, flags, percentage controls, two colors, palette selection, palette mapping, and blend mode.

Only mappings explicitly correlated in Pass 48 should be treated as confirmed. Do not assign guessed UI labels to the remaining indices. A complete map requires tracing each parameter definition's stable parameter ID through the setup call and matching the render access to that ID, not relying on decompiler stack offsets.

## 6. XAO implementation requirements

1. Use AE SDK pixel structures and documented channel semantics as the authoritative contract for XAO, not the decompiled plugin's inferred memory layout.
2. Implement a dedicated 16-bpc adapter with explicit range conversion and premultiplied-alpha behavior.
3. Add tests for 0, 1, midpoint, maximum, partial alpha, and color values exceeding alpha before output clamping.
4. Treat 32768 as a reference-specific quantization scale; do not copy it until the intended AE SDK format and representation are confirmed.
5. Keep 32-bpc float support a separate implementation and test gate.
6. Continue parameter mapping by stable IDs and setup registration, not guessed array indices.

## 7. Conclusion

S1's 16-bit output path is substantially clearer than the exact input normalization: output uses four 16-bit stores, quantizes normalized components at 32768, and clamps each color component to alpha. This supports a premultiplied 16-bit interpretation for this reference. The input normalization constant, exact channel semantics, float support, and full parameter-ID map remain open.
