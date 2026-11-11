# XAO — S1 ASCII Parameter Registration IDs: Confirmed Labels (Pass 52)

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Evidence: supplied static decompilation `XAO/ascii [ main ]/c+/S1AsciiArt.aex.c`.
Scope: recover literal parameter/group labels and the numeric IDs assigned immediately before the parameter-definition suite call. This is not a complete parameter map.

## 1. Literal section/group labels

The setup code assigns the following literal labels and numeric IDs to the parameter-definition structure:

| Literal label | ID (hex) | ID (decimal) |
|---|---:|---:|
| Color & Palette | 0x15 | 21 |
| Characters | 0x17 | 23 |
| Background | 0x19 | 25 |

These entries use the section/group type value `auStack_e8[3] = 0x0d` in the recovered setup sequence.

## 2. Literal control labels

| Literal label | ID (hex) | ID (decimal) | Recovered definition detail |
|---|---:|---:|---|
| Palette Mapping | 0x10 | 16 | Popup choices: Tonal, Original |
| Palette Color Strength | 0x11 | 17 | Floating control; recovered bounds/default encoding still needs SDK-structure confirmation |
| Blend Mode | 0x12 | 18 | Popup: Normal, Multiply, Screen, Overlay, Soft Light, Difference, Add |

The three controls above use recovered type values in `auStack_e8[3]`: popup controls use 7; Palette Color Strength uses 10.

## 3. Important interpretation boundary

The numeric values above are copied from the decompiler's `auStack_e8[0]` assignments immediately preceding the parameter-definition suite call. They are strong candidates for the stable parameter IDs supplied to that call, and are recorded as such for traceability.

However, this pass does not claim a complete UI map:
- Many labels are supplied through `GetStringPtr(resource_id)`, not literal strings.
- The full resource string table has not yet been decoded and correlated.
- A section/group ID is not a render parameter value and must not be read as one.
- The render routine's `param_3[index]` references are not safely interchangeable with the setup IDs without tracing the host parameter array and setup call semantics.
- The parameter definitions for font, grid, source/color controls, and other controls still need a one-to-one registration-to-render correlation.

## 4. Confirmed popup choices

The literal choice strings recovered in this pass are:
- Palette Mapping: `Tonal|Original`
- Blend Mode: `Normal|Multiply|Screen|Overlay|Soft Light|Difference|Add`

Do not silently add other choices or rename these values when reproducing the reference behavior.

## 5. Next trace

Continue by extracting the plugin's string resource table and mapping each `GetStringPtr(n)` resource index to the control definition where it is used. Then correlate the resulting stable parameter IDs with render-time accesses and typed value reads. Only after that should XAO define a compatibility-facing parameter schema.

## 6. Scope

This is static decompilation analysis only. It does not establish AE runtime behavior, complete parameter defaults/ranges, SmartFX support, or a validated SDK implementation.
