# XAO Focused Audit — Legacy Native Halftone and OFX Port References — Pass 19

Date: 2026-11-07

## Scope

Reviewed the supplied Halftone Master/Mike source, the legacy compiled AEX, the Halftone eas OFX source, and the decompiler output for CratesHalftone:
- `Halftone.cpp/.hpp`, `HalftoneSampler.hpp`, `HalftoneVector.hpp`, `HalftonePiPL.r`, README and TODO
- byte-for-byte comparison of Master and Mike copies
- `Halftone eas/halftone.cpp`
- `c+/CratesHalftone.aex.c` and related Sapphire S_HalfTone/S_HalfToneColor/S_HalfToneRings decompiler outputs

The Master and Mike source copies are byte-identical across all five principal source/build files checked. No clear license file was supplied for the Master/Mike project. Treat this code as behavior reference only until source rights are established.

## 1. Legacy AE Halftone Master/Mike — actual algorithm

- This is a legacy Adobe After Effects SDK effect using the classic `PF_Cmd_RENDER` path, not SmartFX.
- The output is rendered by iterating every pixel with the AE Iterate8/Iterate16 suites.
- It creates three independent screen normals from three user-controlled angles. Each screen has a rotated grid and a shared cell spacing.
- For each output pixel and each channel screen, it projects the pixel into the rotated grid, finds the nearest screen cell, calculates the four corners of that cell, and samples the source at those four corner positions.
- For each RGB channel, it evaluates the corresponding channel values at those four sample points and accumulates shape coverage.
- Shape options are Round, Square, Euclidean Dot, Ellipse, Line, Diamond and Flower.
- Tone controls dot radius: channel value is transformed by a shape-specific power/geometry curve and multiplied by the maximum cell radius. A signed distance/coverage value is softened by the Soften parameter and accumulated into the output channel.
- It copies the source alpha unchanged and optionally converts the final RGB result to greyscale.
- Parameters are limited to Mode, Size, Soften, Channel 1 angle, Channel 2 angle, Channel 3 angle and Greyscale.
- The implementation has 8-bit and 16-bit paths only. Its own TODO explicitly says 16/32-bit colour support remains incomplete (despite 16-bit code existing, 32-bit is absent).

## 2. Important limitations

1. **No 32-bpc path:** only Iterate8/Iterate16 are dispatched. This cannot be the XAO pixel-format foundation.
2. **Legacy render architecture:** no Smart Pre-render/Smart Render path, no modern render-bounds contract, and no demonstrated Multi-Frame Rendering safety. Do not infer current AE compatibility from the included old binary.
3. **Sampling cost:** each output pixel calculates three rotated grids and up to twelve source sample locations (four per channel), then performs multiple trigonometric/power operations for shape coverage. This can be expensive at high resolutions.
4. **Repeated coordinate math:** the same screen grid and shape geometry are recomputed for every output pixel. XAO should precompute or incrementally step grid coordinates per row/tile and cache tone/shape tables where correct.
5. **Potential coordinate/bounds concerns:** sample coordinates are clamped to source dimensions, but the sampler's direct pixel-address calculation relies on the supplied world pointer and rowbytes. XAO must use explicit world origins, rowbytes and validated bounds in its own adapter.
6. **Coverage/softening semantics:** the effect accumulates channel coverage with additive saturation, so overlapping marks can brighten toward full channel values. This is not identical to simple multiply-ink compositing; XAO must choose the compositing model based on visual references.
7. **Colour model:** screens operate on individual RGB channels with independent angles. There is no documented ICC/CMYK conversion, ink limit, dot gain calibration or linear-light contract.
8. **Build age:** README targets CC 15 and the CC 2015 SDK. The binary is a reference artifact, not a verified build for AE 2023.2.1 / Windows 11.

## 3. Halftone eas OFX — separate simpler implementation

- Implements a rotated periodic screen with nearest cell-center sampling.
- Samples the source channel or luminance at the screen-dot center using bilinear interpolation.
- Dot radius is `sqrt(darkness) * dotSize * 0.72`, with contrast applied around the 0.5 midpoint.
- Supports Newsprint mono (dark ink on cream paper) and a three-screen CMY mode with 15°, 75° and 0° relative angles.
- Mixes the generated RGB result with the original source and copies source alpha unchanged.
- Supports UByte, UShort and Float in its OFX render dispatch.
- The implementation explicitly disables tiles because sampling reads from positions outside the current output pixel.
- The source includes a missing `../common/purzfx.hpp` dependency, so the supplied folder is not independently buildable.
- No clear license file is included in the supplied folder.

### OFX-specific limitations
- `multiThreadProcessImages` is empty; processing is serial.
- Dot size scales using `renderScale.x` only.
- Grid and source coordinates assume the full source bounds and convert top-down to OFX coordinates manually; this needs careful validation for non-zero bounds/origins.
- The CMY mode is a simplified RGB-channel screen and does not model black separation, ICC profiles or print calibration.
- The source is OFX, not an AE SDK plugin.

## 4. CratesHalftone / Sapphire binary decompiler evidence

- The supplied CratesHalftone decompiler output is a large recovered C-like listing, not original source. Searching it for readable UI/control labels did not establish a reliable parameter schema or recover the actual halftone mathematics.
- The related S_HalfTone, S_HalfToneColor and S_HalfToneRings outputs are also decompiler listings of proprietary Sapphire binaries. They must not be mistaken for self-contained algorithm source.
- No XAO code should depend on Crates/Sapphire runtime DLLs or bundled proprietary assets.
- The available evidence is insufficient to claim exact parity with these effects.

## 5. XAO decisions

- Keep the legacy three-angle RGB screen concept and the seven geometric stamp shapes as algorithm candidates, subject to the supplied visual references.
- Keep alpha preservation as a mandatory contract.
- Rebuild the rotated-grid sampler with robust coordinate transforms, explicit bounds/origins, render-scale handling and deterministic sampling.
- Optimize by precomputing screen basis vectors, tone/radius lookup tables and per-row cell indices; benchmark before choosing sample count and antialiasing strategy.
- Provide a true FP32/HDR path and explicit colour-space/working-space policy.
- Do not copy Master/Mike source until its license/provenance is resolved; do not copy the Sapphire decompiler listings.
- Do not reuse the missing-dependency OFX code without resolving both the helper dependency and licensing.
- These line-shaped halftone marks are a shape within the Halftone engine. They are not the separately excluded Dither Majid Lines effect.

## 6. Review status

This pass covers the listed legacy AE source files, the separate OFX source file and the available decompiler evidence. It is not a current Windows/AE build, not a runtime test, and not a review of every file in all Halftone folders.
