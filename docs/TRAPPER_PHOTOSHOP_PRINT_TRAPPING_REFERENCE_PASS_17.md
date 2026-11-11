# XAO Focused Audit — Trapper Photoshop Color-Trapping Reference — Pass 17

Date: 2026-11-07

## Scope

Reviewed the supplied Trapper Photoshop UXP project:
- README and Apache-2.0 license
- `TrappingEngine.js`
- `TrapSizeParser.js`
- controller workflow and documented architectural decisions
- project constraints and known issues

This is a Photoshop UXP extension, not an After Effects plugin. It is a peripheral print-production reference, not a core XAO effect. Its license is Apache-2.0; any code reuse would still require preserving notices and meeting Apache conditions. The current XAO scope does not require importing its Photoshop API or panel.

## 1. Algorithm

- Scans an 8-bit RGBA image and counts exact RGB triplets, ignoring fully transparent pixels.
- Calculates a simple Rec.601-style weighted brightness value (0.299R + 0.587G + 0.114B).
- Sorts distinct colors from lightest to darkest.
- Assigns the lightest color the maximum trap and the darkest color zero trap, with linear interpolation for intermediate colors.
- Converts physical trap sizes from inches/points/fractions to pixels using document DPI.
- Uses iterative four-connected morphological dilation to expand light-color masks into eligible neighboring transparent pixels.
- Also includes a four-connected erosion operation and a simple white-underbase generator with optional choke.

## 2. Technical limitations and risks

1. **Exact RGB color extraction only:** anti-aliased or slightly varying colors can explode the number of unique colors. The controller therefore filters tiny color populations and limits the supported number of colors. This is not robust continuous-tone separation.
2. **Dilation uses a four-connected cross structuring element:** repeated iterations produce a Manhattan-distance expansion, not a circular/Euclidean trap radius. The result can be directionally biased.
3. **Neighbor conflict resolution is order-dependent:** a newly filled pixel copies the first eligible neighbor in a fixed top/right/bottom/left order. At boundaries where multiple colors compete, the chosen color can be biased by this scan order.
4. **Performance scales with radius × pixels:** each dilation/erosion iteration scans the full image and allocates a new image buffer. Large dimensions or trap radii can become expensive; a distance-transform or optimized morphology approach would be preferable for a native high-performance implementation.
5. **Mask is only checked by alpha:** the mask does not encode which neighboring color is permitted or which region owns the target pixel. The caller must supply a carefully constructed mask.
6. **Transparent pixels are treated as empty, but partial alpha is not modeled as coverage:** color analysis ignores only alpha==0; all nonzero-alpha pixels count as full color samples. Trapping behavior for partially transparent/antialiased edges is therefore underspecified.
7. **Underbase logic is simplistic:** it treats any nontransparent pixel not within a fixed RGB tolerance of the garment color as requiring solid white. This is not a production-grade spot-color underbase or CMYK-aware print separation.
8. **Trap-size parser accepts loose numeric parsing:** `parseFloat` can accept strings with trailing junk; fraction parsing does not validate finite values or denominator sign/range. A production parameter parser should be strict.
9. **DPI is an external assumption:** physical size conversion is only accurate if the document resolution and pixel coordinate mapping are correct and stable.
10. **The README's workflow is intentionally restrictive:** RGB, 8-bit, at most ten colors, one unlocked layer/preflight preparation. These limitations are not suitable as general XAO engine assumptions.

## 3. Relevance to XAO

- The only potentially useful concepts are a separate print-trapping utility, explicit physical-unit conversion, and morphological expansion/choke.
- These are not part of the user's defined primary XAO engine list and should not be added to the core effect set without a matching visual/product requirement.
- If XAO later needs a print-trap sub-engine, it should use a documented distance metric, deterministic ownership/tie-breaking, alpha-aware coverage, strict DPI/unit validation, optimized morphology/distance transforms and dedicated tests.
- Do not bring Photoshop UXP APIs, document-layer orchestration, or this plugin's one-layer/8-bit assumptions into the AE adapter.

## 4. Status

This pass covers the core trapping algorithm, physical-size parser, license and project-level constraints. It does not build or run the UXP extension and does not complete the broader XAO archive audit.
