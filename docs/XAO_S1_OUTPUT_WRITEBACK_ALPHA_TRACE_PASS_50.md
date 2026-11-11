# XAO — S1 Output Writeback and Alpha Clamp Trace (Pass 50)

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Scope: continue the static trace of `S1AsciiArt.aex.c`, focusing on the output pixel writeback after the ASCII renderer finishes.
Status: decompiler inspection only. No original vendor source, SDK headers, or AE runtime test was available in this pass.

## 1. Input channel interpretation visible in the 8-bit path

The render routine selects a pixel stride of 4 bytes when the depth flag is clear and 8 bytes when set. In the 8-bit input path, it reads each four-byte pixel as:
- byte +1 -> first color component stored in the internal float RGBA row;
- byte +2 -> second color component;
- byte +3 -> third color component;
- byte +0 -> alpha component.

Each byte is normalized by 1/255 before being passed to `AsciiRenderer::AddSourceRow`.

The source therefore treats the first byte as alpha and the following three bytes as color components in this path. This agrees with the common AE 8-bit pixel field ordering, but the conclusion is based on the decompiled offsets and not an SDK header included in the supplied source.

## 2. Output writeback and premultiplication evidence

In the 8-bit output branch, the renderer computes output alpha and three color components, converts each to an 8-bit range, and writes them to consecutive byte positions:
- output byte +0 receives alpha;
- output bytes +1, +2 and +3 receive the three color components.

For each color component, the decompilation clamps the converted value so it cannot exceed the converted alpha value before storing it. This is strong evidence that this plugin's 8-bit output path writes premultiplied color channels (RGB <= A), rather than unconstrained straight-alpha color.

The output alpha is also explicitly clamped to [0,1] before conversion. Color values are clamped to [0,1], then bounded by alpha.

This is a useful reference behavior for XAO's AE output adapter, but it must not be generalized to all AE formats or every plugin's host contract without verifying the SDK and actual host behavior.

## 3. Important distinction: evidence is not a complete pixel contract

This pass does not establish:
- the exact channel semantics of the 16-bit path;
- float/32-bpc support (the observed reference path branches between 4-byte and 8-byte pixels);
- whether all upstream source values are already premultiplied or are converted before rendering;
- transfer function / linear-light handling;
- behavior for negative RGB, HDR values, or values above 1;
- whether the output descriptor always has the same alpha convention as the input.

The previous Pass 48 observation remains valid: the reference checks a depth-related flag and selects a 4-byte or 8-byte pixel path. It does not prove 32-bpc support.

## 4. Cancellation and row processing

The render routine checks the host abort callback periodically during source-row ingestion and output-row composition. It also calls the host progress callback with row-range values. The cadence is coarser than every pixel and is visible in the row loop.

XAO should preserve host responsiveness by checking abort at row or tile boundaries, while ensuring that partially rendered buffers are never reported as successful output.

## 5. XAO implementation consequences

1. Keep the core image representation explicit; do not silently equate the generic core's linear-premultiplied RGBA contract with the host's raw pixel storage.
2. Implement separate tested adapters for each supported AE pixel format and depth.
3. For integer premultiplied output, clamp color channels to alpha after the final color/alpha operation, with rounding and range behavior covered by tests.
4. Do not add 32-bpc support claims until the adapter and tests explicitly support PF_PixelFloat.
5. Preserve cancellation checks and guarantee that every successful render writes the complete requested output region.
6. Add fixtures for fully transparent pixels with nonzero RGB, opaque pixels, partial alpha, and color values near quantization boundaries.

## 6. Conclusion

The supplied S1 decompilation gives strong evidence of alpha-first byte ordering and premultiplied 8-bit output, including an explicit RGB-to-alpha clamp. It also shows host abort/progress checks during row processing. This is a reference-specific finding, not yet XAO's implemented pixel adapter or proof of the full AE pixel contract.
