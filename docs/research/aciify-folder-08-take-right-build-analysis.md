# Aciify archive — Folder 08: TAKE RIGHT BUILD

**Source:** `aciify.zip` → `aciify/TAKE RIGHT BUILD/`  
**Inventory:** 2,247 entries including a nested `.git` history (2,101 entries); about 15.37 MB of non-directory content.  
**Identity:** YMDithers FX Studio / YMDithers v7 native AE plug-in plus a web dithering/halftone studio. This is the most directly relevant native-plugin source in the archive. **Analyzed and documented only; no source was integrated into XAO.**

## Layout

- `ae/`: native After Effects entry, PiPL generator/resources, version resource, DEF and build verification scripts.
- `core/`: native C++ processing/algorithm implementation (full source tree).
- `extern/AfterEffectsSDK/`: vendored SDK dependency.
- `src/`: React/TypeScript browser studio and algorithm engine.
- `public/`, `dist/`: web distribution and plugin artifacts.
- Root CMake, package/TypeScript/Vite configuration, test files, README, prebuilt `.aex` versions.
- Nested `.git/`: upstream project history/object data; not counted as source files to port.

## 1. Product / web engine

README describes a studio for **49 dithering and continuous halftone algorithms**:
- 15 error-diffusion methods: Floyd–Steinberg and serpentine, JJN, Stucki, Atkinson, Burkes, Sierra variants, Fan/Shiau-Fan, Skip Neighbours, Xerox Grain.
- 7 ordered/stochastic: Bayer 2/4/8/16, Blue Noise, Jimenez Interleaved Gradient Noise, White Noise.
- 27 continuous halftone/pattern screens: newspaper angles, matrix/square/mosaic, modulation, engraving/hatch/grid/cyber/cross-square/diamond/star/bytewav/circuit/stitch/clock/knit families.
- Render modes: monochrome/custom ink, duotone, per-channel RGB, tonal bands, indexed color-grade/palette.
- Preprocessing: 5-point tonal levels, unsharp, blur/denoise/grain, hue/saturation and negative.
- Viewport: before/after slider, side-by-side/isolated, zoom/pan, eyedropper.
- Recipes and export PNG/JPEG print scales, SVG, palette JSON, text/HTML/session/video as listed in README.

### Web source paths (preserved in archive)
- `src/App.tsx` — UI/application (~49 KB)
- `src/engine/ditherAlgorithms.ts` — algorithm definitions (~12 KB)
- `src/engine/ditherEngine.ts` — dither engine (~26 KB)
- `src/engine/linesEngine.ts` — continuous-line/screen engine (~25 KB)
- `src/engine/paletteUtils.ts` — palette utilities
- `src/engine/processor.ts` — preprocessing/pipeline (~26 KB)
- `src/types.ts` — types
- `src/index.css`, `src/main.tsx`

The browser implementation is a useful algorithm/UX reference, but TS/Canvas code is not native AE C++ and should not be pasted directly into XAO.

## 2. Native AE plugin source

### Files
- `ae/ymdithers_ae.cpp` (~27.7 KB): native AE effect implementation/entry and parameter/render wiring.
- `ae/Majeed_PiPL.r`, `Majeed_PiPL.rc`, `Majeed_PiPL.bin`: PiPL resource source/generated artifacts.
- `ae/pipl_gen.py`: PiPL generation script.
- `ae/YMDithers_Version.rc`: version resource.
- `ae/YMDithers.def`: exported entry definitions.
- `ae/verify_build.py`: build/PiPL verification script (~9.9 KB).
- `core/`: C++ algorithm and processing modules; inspect these individually before any port.
- `extern/AfterEffectsSDK/`: SDK vendored into this snapshot; avoid treating it as XAO's authoritative SDK copy without version comparison.

### Build system
Root CMake:
- CMake 3.20+, C++17/C11, Windows x64 only.
- Uses Python to generate PiPL resource from `ae/Majeed_PiPL.r`.
- Adds SDK subdirectory, compiles AE and core `.cpp` sources into `YMDithers_v7.aex`.
- MSVC path sets Windows/AE definitions, static runtime and optimization; MinGW path has separate flags.
- Post-build copies plugin to build/public/dist paths.
- Build instructions and verification script are source claims; this analysis did not compile it.

### PiPL compatibility note
`YMDithers_PiPL_FIX_README.txt` says the PiPL generator and binaries/root/public AEX can be replaced without changing `src/`, `core/`, or SDK; states PiPL layout matches a supplied “YMDithers after best.aex” resource byte-for-byte. It also explicitly calls for final AE 23.2.1 Windows load testing. Treat this as author note, not independent verification. Do not overwrite XAO PiPL/resource configuration based on it.

## 3. Relevance to XAO (architecture lessons, not code reuse)

- Separate AE wrapper/parameters/PiPL from algorithm core—useful architectural pattern.
- Keep CPU image processing in isolated core modules with clear input/output and pixel-format contracts.
- Treat browser algorithm implementations as reference equations and parity test candidates; port one algorithm at a time into XAO's own pixel pipeline.
- Compare native source's PF world formats, rowbytes, alpha, channel handling, output bounds, and MFR/thread assumptions against XAO before reuse.
- CMake/PiPL generator/verification patterns may inform build reliability, but XAO retains its own names, resources, exports, SDK version and packaging.
- Use the web studio for algorithm/controls/preset ideas; not a native AE UI implementation.

## 4. Artifacts and provenance

- Prebuilt files present: `YMDithers.aex`, `YMDithers_v7.aex`, `YMDithers after best.aex` (plus `dither.obj`, `lines.obj`, test PiPL artifacts). Binaries are evidence/reference only; not source and not a substitute for rebuilding.
- README metadata identifies “YMDithers Studio - Dithering & Halftone FX”; metadata lists a Gemini server-side capability, but the README's offline/local rendering claim and this metadata are not reconciled here. Verify actual network behavior from source/runtime before making privacy claims.
- Nested Git history may contain older states; it was inventoried but commit history/diffs were not exhaustively reviewed.

## Licensing and boundaries
- The archive's own license/provenance must be checked before reuse. A bundled SDK has its own Adobe terms; do not redistribute SDK files without permission.
- Do not assume the native plugin or web source is MIT merely because some dependencies are permissive.
- No files were copied to XAO; no code integration, build, host load, render, or parity test was performed.

## Inspection limits
- Root README, CMake, metadata, PiPL fix note, native AE entry file inventory and web engine file inventory were inspected.
- The complete `core/` source was not line-by-line analyzed in this report; a later targeted pass can examine each algorithm module and native lifecycle in depth.
- No Windows/MSVC/AE 23.2.1 runtime was available/used for validation.
