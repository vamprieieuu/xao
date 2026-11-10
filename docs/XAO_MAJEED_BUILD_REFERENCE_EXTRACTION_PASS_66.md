# XAO — MAJEED Build Reference Extraction (Pass 66)

Target branch: `xao/recovery-baseline-2026-11-10`

## Correct reference identified

The canonical build reference supplied with the XAO materials is the extracted `Dithering_MAJEED_build_ready(1)` project. It is distinct from the small `XAO/dither/dither ofx` reference folder and must be used as the build-system reference.

## Build architecture actually present in MAJEED

- Root CMake requires Windows and builds with C++17.
- `extern/AfterEffectsSDK` supplies the AE SDK tree.
- `extern/AfterEffectsSDK/CMakeLists.txt` builds the SDK utility static library and exports the SDK include directories.
- Root CMake runs Adobe's Windows PiPL preprocessing sequence:
  1. MSVC `cl /EP` preprocesses the PiPL resource.
  2. `PiPLtool.exe` generates the intermediate PiPL resource.
  3. MSVC preprocesses the generated resource into a Windows `.rc`.
- The final plugin is a CMake `SHARED` target, with no prefix and `.aex` suffix.
- Build output is placed under `build/bin`.
- The GitHub Actions workflow runs on `windows-2022`, initializes MSVC x64, configures with Visual Studio 2022 x64, builds Release, explicitly checks for the exact `.aex` output, and uploads it as an artifact.

## What must be removed from the reference

The XAO build must not compile or ship:
- `ae/MajeedDither.cpp`
- `ae/MajeedLines.cpp`
- `ae/MajeedGrain.cpp`
- `ae/MajeedVHS.cpp`
- `ae/MajeedChannels.cpp`
- `core/dither.cpp`
- `core/lines.cpp`
- `core/grain.cpp`
- `core/vhs.cpp`
- `core/channels.cpp`
- MAJEED-specific PiPL identity, parameter definitions, assets, and effect entry point.

The MAJEED implementation files are not an XAO engine dependency. Their build settings and SDK/PiPL orchestration are reference material only.

## Current XAO branch blockers confirmed

The live XAO branch currently contains only a host-independent static `xao_core` CMake target (Image, Compositor, Pipeline) and one core test executable. It has no:
- `extern/AfterEffectsSDK` tree,
- native AE adapter source or `EffectMain`,
- XAO PiPL resource,
- Windows `.aex` target,
- GitHub Actions workflow under `.github/workflows`.

Consequently, merely copying the MAJEED workflow would fail: it expects a MAJEED AE target and its SDK tree. The XAO adapter and XAO-specific PiPL identity must be authored before an honest workflow can produce an XAO binary.

## Integration boundary

The next implementation must transplant only the generic build mechanics (SDK utility target, PiPL generation, MSVC x64 configuration, `.aex` target shape, artifact verification/upload) and create XAO-specific AE glue that dispatches into the existing unified XAO core. It must not transplant MAJEED's effect implementation or expose Dither/Lines as XAO effects.

## Validation limits

This pass inspected the actual MAJEED root CMake, SDK CMake, PiPL resource, GitHub Actions workflow, adapter glue and source inventory, and the live XAO branch CMake/core interfaces. No Windows/MSVC/PiPL/AE build was run in this environment. No XAO source was copied from MAJEED.
