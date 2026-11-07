# XAO Deep Source Review — Pass 2

Date: 2026-11-07

Status: targeted source-code review of representative native, C++, shader, and web projects inside the supplied XAO.zip. This document distinguishes inspected source from projects that still require a complete line-by-line review. No XAO native binary is claimed to exist or have passed After Effects runtime tests.

## User scope decision

- The standalone Lines effect from Dither Majid is excluded from XAO.
- Do not port its source, controls, presets, UI, or create a Lines engine.
- This exclusion does not automatically ban line-shaped halftone screen geometry when it is part of the Halftone engine's own visual design.

## Confirmed archive inventory

The extracted XAO.zip contains 996 ZIP entries, including directory entries, and 805 regular files. Main top-level groups: MAIN IDEAS, ASCII, Dither, Glow, Halftone, Other Open Source, and Rays. The Halftone group contains seven named source-project folders in this archive, not nine. fonts.zip contains 45 font files (24 Arabic, 10 English, 11 unusual/symbol fonts).

## ASCII — source-level findings

### ASCII Art main (MIT, C++/Qt/OpenCV)
Inspected: GlyphMapper.h, Luminance.h, CMake files, engine headers and test layout.
- Cell mapping is separated behind a GlyphMapper strategy interface.
- Luminance mode uses Rec.709 weighted RGB, gamma adjustment, contrast/brightness, and a configurable ramp.
- Edge mode uses precomputed gradient magnitude and four quantized edge directions, with Sobel analysis upstream.
- Useful portable concepts: per-cell sampled colour/luminance, edge features, mapper strategies, and unit-test boundaries.
- It is a Qt/OpenCV desktop application, not an AE plugin. Its Qt GUI, camera capture and OpenCV dependencies should not be brought into XAO's AE adapter.
- The built-in ramp is single-byte character-oriented; it is not a substitute for a Unicode font atlas or Arabic shaping.

### AuraASCII (MIT, TypeScript/WebGL)
Inspected: AsciiRenderer.ts and ASCII fragment shader.
- Uses a two-pass pipeline: source analysis into an edge/feature buffer, then glyph-atlas sampling and composition.
- This separation is a good design reference for CPU/GPU parity: a common cell-feature model can feed either CPU rasterization or an optional GPU backend.
- It depends on Three.js, browser canvas and WebGL; those are not part of the native AE runtime. Reimplement the algorithm in the XAO core and AE GPU adapter rather than importing the web application.

### Morphing ASCII Shader (MIT)
- Shader-oriented project with separate rendering and memory-grid/ink-bleed concepts.
- Keep as a visual/transition reference; do not treat its JavaScript/browser runtime as an AE plug-in implementation.
- A focused pass over all shader functions and parameter semantics remains pending.

### ASCII OFX and GlyphBlocks OFX
- Both are OpenFX, not Adobe AE effects.
- Their source references a shared ../common/purzfx.hpp that is absent from the supplied archive; they cannot be built standalone from the provided files.
- No clear license file was found in the supplied project folders. Do not copy source until provenance and license are established.
- The bundled 8x8 bitmap glyph header is not the primary XAO font path; XAO must use actual user-supplied font files and glyph atlases.

### Pointless (GPL-3.0)
- Large C++/Qt application with ASCII, halftone, dither, mosaic, animation and compositing code.
- Valuable as a feature/algorithm comparison reference.
- Keep its implementation out of a proprietary XAO binary unless the product's licensing and distribution are intentionally made GPL-compliant.

## Halftone — source-level findings

### Legacy native AE Halftone (Halftone master / mike)
Inspected: Halftone.cpp and Halftone.hpp; the copies in master and mike are byte-identical for the principal C++ implementation files.
- Native AE legacy implementation; uses Iterate8 and Iterate16 paths.
- Three independently rotated channel screens; exposes Round, Square, Euclidean Dot, Ellipse, Line, Diamond and Flower geometries, plus antialiasing/softening and greyscale.
- Only 8/16-bit paths are present in the inspected render code; no SmartFX 32-bpc path is implemented.
- Uses legacy per-pixel callbacks and old SDK conventions (README says tested with CC 2015). This is research material, not a safe drop-in for AE 2023.
- No clear license was found in the supplied source folder. Do not reuse code in the distributed product until permission/license is resolved.
- The line-dot/line-screen geometry here is part of this Halftone implementation; it is distinct from the excluded standalone Dither Majid Lines effect.

### Halftone eas (OFX)
Inspected: halftone.cpp.
- Implements a simple rotated monochrome/CMY screen with channel angle offsets and basic shape coverage.
- Depends on missing ../common/purzfx.hpp; source is incomplete as supplied and is not native AE code.
- No clear license was found in the supplied folder; use only for behavioral research pending rights verification.

### Halftone dean (MIT, Python/PySide6)
- Feature reference for 13 screen styles, multiple grid layouts, mono/CMYK/multichannel separations, tone and print FX, palettes and JSON presets.
- Python/PySide6 application, not a native AE engine. Reimplement only selected algorithms in the shared C++ core.

### Halftone lap (MIT, browser Canvas)
- Feature/visual reference for CMYK, bitmap, duotone/tritone, misregistration, ink spread and paper grain.
- Browser implementation; port selected processing math, not the browser UI/runtime.

### Halftone akam
- Contains a permissive-looking MIT LICENSE alongside a LICENSE.md that expressly prohibits commercial use and redistribution.
- Excluded from source reuse until the copyright holder clarifies the conflicting terms.

### Halftone ps (Photoshop UXP)
- Contains a substantial modular JS processing engine: screen geometry, separation, resampling, jitter, quantization, grading, blur, dither, SVG and presets.
- Photoshop UXP host integration is not usable as an AE plug-in runtime.
- A clear license file was not confirmed in the supplied folder. Treat as reference-only until the license is verified.

## Glow — source-level findings

### HaloGlow (MIT, native AE C++)
Inspected: CMakeLists.txt, HaloGlow_CPU.cpp, HG_Core.cpp, HG_Parallel.h, README and license.
- Strongest native AE Glow candidate in the archive.
- Architecture separates an AE adapter from a host-independent image-processing core.
- CPU adapter normalizes 8/16/32-bpc worlds to FP32 RGBA, runs the shared core and converts back; float path intentionally preserves HDR values above 1.
- Pixel access respects AE rowbytes and world origins; input/output mapping is explicit.
- CPU renderer has row-band parallelism with disjoint output rows; MFR still requires the full plug-in's sequence/pre-render/UI state to be reviewed for thread safety.
- Core has a multi-scale pyramid, domain planning, local kernels, downsampling and accumulation.
- CMake supports optional GPU backends; inspect dependencies and build options before adopting any backend.
- MIT notice must be retained if code is reused. A source-level review does not establish that it compiles in XAO's target SDK or runs in AE 2023.

### SuperBloom (MIT, Svelte/web/Photoshop UXP/Electron)
- Useful as a bloom/preset and highlight-isolation reference.
- Not a native AE implementation; port only independently understood algorithms where useful.

### Deep Glow / Starglow / S_Glint
- Supplied AEX binaries are behavior references.
- Adjacent .c / .h files are decompiler output, not vendor source and not suitable for direct compilation or integration.

## Dither / Other Open Source

### Filtr (MIT, TypeScript/WebGL)
Inspected: CPU error-diffusion kernel table and glyph atlas builder.
- CPU implementation includes Floyd–Steinberg, Atkinson, Jarvis–Judice–Ninke, Stucki, Burkes, Sierra, Sierra Two Row and Sierra Lite.
- Ordered methods include Bayer 2x2/4x4/8x8/16x16, clustered dot, blue noise and interleaved gradient.
- Glyph atlas builder uses Unicode code points via spread iteration, but browser canvas font fallback does not guarantee the exact user font face, contextual Arabic shaping or robust bidi. XAO needs native font rasterization and shaping.
- Browser/WebGL implementation is a reference; no browser runtime in XAO.

### Trapper Photoshop (Apache-2.0, UXP)
- Processing logic analyzes color regions and computes trapping/expansion for print separations.
- Potentially useful as a future print-production utility, but not a core visual engine in the current XAO engine list. Photoshop host integration is not portable to AE.

### Supplied Dither OFX
- The XAO archive's Dither folder contains one OFX source file, not an AE-native plug-in.
- It is separate from Dither Majid. No standalone Lines effect from Dither Majid is to be included.

## Unresolved items — not yet signed off

1. Full line-by-line review of every source file in every project (the archive contains hundreds of source and asset files).
2. Exact license/provenance resolution for ASCII OFX, GlyphBlocks OFX, Dither OFX, Halftone master/mike/eas, and Halftone Photoshop UXP.
3. Complete shader math review and visual parity tests for ASCII, Halftone, Dither, Glow, Rays and Glint.
4. Full analysis of all decompiled AEX files, parameter tables, UI controls, pixel formats and render behavior.
5. Full analysis of every MAIN IDEAS clip at native frame rate and every reference image/settings note.
6. Build/dependency review for HaloGlow optional GPU backends and a clean XAO-native adaptation plan.
7. Font-by-font licensing confirmation, especially files with missing or ambiguous metadata.

## Implementation decisions

- Build XAO as a native AE C++ effect with a host-independent core and a thin AE adapter.
- CPU rendering is mandatory; GPU is optional.
- Use exact user-supplied TTF/OTF assets through font loading and atlas rasterization; restricted fonts remain local/user-imported unless redistribution rights are confirmed.
- Arabic typography uses shaping and bidi; glyph-art mode may treat glyphs as independent visual units.
- Preserve independent engine modules and a deterministic composition pipeline.
- No Dither Majid Lines feature, code, parameters, presets or UI.
- Do not mark any engine complete until it passes golden-image, format, bounds, alpha, performance and AE runtime tests.
