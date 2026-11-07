# XAO Research Audit — Initial Source & Build Review

Date: 2026-11-07

This document records verified findings from the supplied XAO.zip and fonts.zip archives and the user's Dithering_MAJEED_build_ready GitHub repository. It is an audit, not a claim that XAO has been implemented or runtime-tested.

## 1. Current XAO repository

- Repository: https://github.com/vamprieieuu/xao
- Default branch: main
- At inspection time the repository had size 0 and no project files.
- The first commits should establish documentation, build infrastructure, and source attribution before effect implementation.

## 2. Supplied archive inventory

- XAO.zip: 805 files across ASCII, Halftone, Glow, Rays, Dither, Other Open Source, and MAIN IDEAS.
- fonts.zip: 45 font files: 24 Arabic, 10 English, 11 unusual/symbolic (counts from the archive's file listing).
- MAIN IDEAS includes 9 video recordings, reference images, preset/settings screenshots, and Arabic notes.
- The Dither folder inside XAO.zip contains only one OFX source file (dither.cpp); the complete Dither Majid reference source is available separately in the user's GitHub repository Dithering_MAJEED_build_ready.

## 3. MAIN IDEAS — required visual systems

The reference clips and accompanying notes specify:
- PixelDitherGo: square-cell pixel/dither field, green monochrome palette, density and scale control.
- Liquid ASCII: rounded rectangular text cells; per-cell sampled background colour; randomized/animated Japanese or other glyph strings; hide text and control typography.
- ASCII Ghost: randomized glyphs inherit local source-image colours, with a rays/light-beam layer.
- ASCII CGO: dense glyph field with selective per-glyph glow; glow positions may be fixed or randomized/animated.
- Rainbow ASCII: multi-colour glyph field with controllable spectrum, saturation and glow.
- Mosaic ASCII: variable glyph/cell sizes, mosaic blocks, selective colour and glow, low-saturation treatment.
- Threshold ASCII: thresholded image represented by moving lines, rectangles and squares with controllable geometry and colour.
- Golden Glow Halftone: golden/orange glowing halftone screen on dark areas.
- Array: geometric arrays and levels, edge-aware shapes, palette/colour modes, cell sizing, rotation/scale jitter and clumping controls.
- Shape Halftone: print-screen geometry plus paper, exposure, glow, dot gain, grain, ink curve and misregistration.
- Typeset: image formed by repeated text, with typography, scale, spacing, contrast and source sampling controls.

## 4. Dither Majid build reference

Repository: https://github.com/vamprieieuu/Dithering_MAJEED_build_ready

Verified structure:
- Native AE adapter in ae/ymdithers_ae.cpp.
- Dither algorithms in core/dither.cpp. The separate Lines module is explicitly excluded from XAO by the user.
- PiPL source in ae/Majeed_PiPL.r and generator ae/pipl_gen.py.
- CMake project includes the AE SDK headers and builds a Windows x64 .aex.
- GitHub Actions uses Windows 2022 + MSVC x64, configures CMake, builds Release, verifies the PE/exports/resources, and uploads the AEX.
- Verification explicitly checks x64 PE32+, DLL characteristics, Windows GUI subsystem, EffectMain and PluginDataEntryFunction2 exports, and selected import/runtime properties.
- The code exposes 49 dither/screen algorithms. XAO may study and selectively port the dither algorithms only; the separate Lines effect/module must not be included, exposed, or ported.

Important issues found — do not copy this repository blindly:
1. The source uses PF_VERSION(1,0,0,RELEASE,1), which encodes to 0x00080601. The PiPL file currently contains AE_Effect_Version 67073 (0x00010601), which decodes to 0.2.0 release build 1. These do not match and must be aligned.
2. SmartPreRender copies PF_CheckoutResult fields without first establishing a successful checkout in every path; harden error handling and initialize/check result data.
3. SmartRender should check callback return codes and all world dimensions/strides/pixel formats before processing.
4. parallel_rows() in majeed_core.h currently executes one serial callback; it is not actually parallel.
5. FrameCtx::frame() assumes 30 fps. XAO animation must derive time/frame deterministically from AE's actual timebase.
6. CI verifies binary structure and exports, but that alone does not prove the plug-in loads and renders correctly in AE. Runtime validation remains mandatory.

The PiPL global OutFlags and OutFlags2 values do match the C++ GLOBAL_SETUP values in this reference. Preserve this agreement and generate both from one source of truth in XAO.

### Dither scope clarification (user decision, 2026-11-07)
- XAO includes a Dither engine, but does **not** include the separate Lines effect from Dither Majid.
- Do not port `core/lines.cpp`, its parameters, UI, presets, or any standalone Lines feature into XAO.
- The Dither Majid repository remains a build/architecture and dither-algorithm reference only. The supplied XAO archive's `dither.cpp` is an OFX Bayer 4x4 implementation, not an AE-native plugin; use it as an algorithm reference and reimplement/adapt in the native AE core after validation.

## 5. Source projects — initial reuse classification

### ASCII
- ASCII Art main: MIT; C++ project, useful for image/cell processing concepts.
- auraascii: MIT; web/TypeScript/WebGL-oriented, useful for glyph atlas, mapping and shader concepts; not a drop-in AE C++ engine.
- morphing ascii shader: MIT; shader-focused, useful for glyph atlas/morphing/edge-aware rendering.
- Pointless: GPL-3.0. Do not incorporate its code into a proprietary XAO build unless the distribution/licensing model is deliberately made GPL-compliant. It may be studied for algorithm ideas.
- ascii ofx and glyphblocks OFX folders require separate source/license inspection before reuse.

### Halftone
- Halftone akam contains both LICENSE and LICENSE.md with different terms (MIT and a personal-use/non-commercial license). Treat as license-conflicted until clarified; do not copy code yet.
- Halftone dean and Halftone lap have MIT license files and are candidates for selective reuse.
- Halftone master is an older AE C++ project; its archive copy does not show a clear license. Inspect code for reference only until rights are established.
- Halftone mike, Halftone eas, and Halftone ps require license verification before code reuse. Halftone ps is a Photoshop UXP project, not an AE-native implementation.
- The archive currently contains seven named Halftone open-source project folders, not nine.

### Glow / Glint
- HaloGlow: MIT and AE-native C++ project. Strong candidate for studying/reusing multi-scale glow, CPU/GPU parity, MFR, threshold, falloff, tint and alpha behavior, subject to dependency and code review.
- SuperBloom: MIT, but primarily a Svelte/web/Photoshop UXP/Electron project. Use its bloom concepts/presets selectively; it is not a native AE engine.
- Deep Glow, Starglow and S_Glint AEX files are binary references. Their adjacent .c/.h files are decompiler outputs, not original vendor source.

### Rays
- Rays and S_Rays are AEX binaries. Their .c/.h companions appear to be decompiler output. Use them for reverse-engineering/parameter/behavior research, not as ready-to-build source.

### Other Open Source
- filtr: MIT, WebGL2/browser effects studio; useful for studying composable effects, ASCII, dithering, halftone, edge and post-processing stacks.
- trapper-photoshop: Apache-2.0 Photoshop UXP print-trapping project. Its trapping algorithm may be useful as an optional print/ink concept, but it is not a core XAO effect and its Photoshop host code cannot be used as an AE plug-in adapter.

## 6. Font archive — embedding warning

The font files are real font assets and should be used as font files, not redrawn substitutes. However, embedded metadata shows mixed terms:
- Some are explicitly personal-use only, non-redistributable, all-rights-reserved, or require contacting the author for a commercial license.
- Some identify SIL Open Font License or other permissive terms.
- Several have missing or ambiguous license metadata.

Implementation direction:
- Build a font-import/library system that uses the exact supplied TTF/OTF files.
- Keep restricted fonts user-supplied/local and do not package them inside a distributable installer unless redistribution/embedding rights are confirmed.
- Bundle only fonts whose licenses explicitly permit redistribution/embedding, preserving their license notices.
- Arabic support requires proper shaping and bidirectional handling for typography mode, plus a separate glyph-art mode for individual letterforms.

## 7. Engineering direction

XAO should be a native AE C++ plug-in with independent engines and a shared composition pipeline:
- ASCII / Hybrid Glyph
- Halftone
- Dither
- Glow
- Rays
- Glint
- Array / Mosaic
- Typeset

The engines should remain individually usable and combinable through explicit layer/blend/compositing controls. CPU fallback is mandatory; GPU acceleration is optional and must not be required on modest hardware. Build and runtime tests must cover PiPL/version/OutFlags consistency, Smart Pre-render bounds, alpha/premultiplication, pixel formats, MFR/thread safety, deterministic animation, parameter registration and actual AE loading/rendering.
