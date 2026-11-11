# XAO — SDK and MAJEED Reference Assets Located and Verified (Pass 68)

Branch: `xao/recovery-baseline-2026-11-10`

## Correction to Pass 66

The prior statement that the SDK was not available to the project workflow was incomplete. The user-provided Library contains both:
- `Dithering_MAJEED_build_ready(1).zip` (6,099,364 bytes)
- `May2023_AfterEffectsSDK_Win.zip` (4,638,898 bytes)

Both were materialized and inspected locally in this pass. The Dithering MAJEED archive already contains a populated `extern/AfterEffectsSDK` tree, including `Headers/AE_Effect.h`, `Headers/SP/SPBasic.h`, `Resources/PiPLtool.exe`, `Util/`, and the SDK CMake target. The separate May 2023 SDK archive is also present and contains the SDK distribution under `AfterEffectsSDK/Examples/`; it is not necessary to ask the user to upload the SDK again.

## Confirmed MAJEED build files

- Root `CMakeLists.txt` requires Windows/MSVC, adds `extern`, generates PiPL with the three-stage MSVC/PiPLtool process, compiles AE and core source files into a shared library, and sets the `.aex` suffix.
- `extern/CMakeLists.txt` adds `AfterEffectsSDK`.
- `extern/AfterEffectsSDK/CMakeLists.txt` builds the AESDK utility static library and exports Headers, SP, Util and Resources include paths.
- `.github/workflows/build.yml` uses Windows 2022, MSVC x64, Visual Studio 2022, builds the MAJEED target, verifies the exact AEX filename, and uploads the artifact.
- `ae/MajeedGlue.h` supplies the generic SmartFX command dispatch pattern.
- `ae/Majeed_PiPL.r` contains MAJEED-specific identity and exported function names; those must be replaced with XAO-specific values.

## Required XAO transplant

Use the SDK tree and generic build sequence from the MAJEED archive. Preserve the SDK layout and PiPL generation mechanics. Replace only plugin-specific pieces with XAO's own:
- XAO PiPL resource, name/category/match name/version/outflags and exported entry point.
- XAO parameter schema and one unified XAO effect dispatcher.
- XAO AE-to-core pixel adapter and render callbacks.
- XAO source list, excluding all MAJEED renderers.

## Explicit exclusions

Do not compile or ship MAJEED's:
`MajeedDither.cpp`, `MajeedLines.cpp`, `MajeedGrain.cpp`, `MajeedVHS.cpp`, `MajeedChannels.cpp`, `DitherAlgoList.h`, `majeed_core.h`, or any `core/dither.cpp`, `core/lines.cpp`, `core/grain.cpp`, `core/vhs.cpp`, `core/channels.cpp` renderer. Do not use the MAJEED PiPL identity or export name.

## Current implementation state

This pass locates and verifies the required source assets; it does not yet claim they have been copied into the live XAO GitHub branch. The live branch still needs the SDK tree, XAO adapter, XAO PiPL, and XAO-specific workflow committed. No Windows build or AE runtime test was run in this pass.
