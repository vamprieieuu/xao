# XAO — MAJEED Adapter Contract and XAO Port Boundary (Pass 67)

Branch: `xao/recovery-baseline-2026-11-10`

## Verified MAJEED adapter structure

The reference adapter is a shared SmartFX dispatch layer in `ae/MajeedGlue.h`, with one exported entry point per effect. The dispatcher handles:
- `PF_Cmd_GLOBAL_SETUP`
- `PF_Cmd_PARAMS_SETUP`
- `PF_Cmd_SMART_PRE_RENDER`
- `PF_Cmd_SMART_RENDER`

The reference uses a parameter schema/table and maps parameter checkout into a render callback. Its PiPL resource declares the Windows x64 entry point and plugin identity. The root CMake preprocesses PiPL using the Adobe SDK's MSVC + PiPLtool sequence, then builds a shared library with the `.aex` suffix. The workflow builds on Windows 2022/MSVC x64 and verifies/uploads the artifact.

## What is reusable as architecture

- SDK include/library target setup from `extern/CMakeLists.txt` and `extern/AfterEffectsSDK/CMakeLists.txt`.
- PiPL preprocessing pipeline and generated resource dependency.
- Windows x64 shared-library target and `.aex` suffix.
- SmartFX command-dispatch pattern, provided the XAO adapter independently implements XAO's parameter and render contract.
- Windows workflow and explicit artifact existence check.

## What is explicitly not reusable

Do not include or compile any MAJEED-specific effect or renderer:
- Dither, Lines, Grain, VHS, Channels implementation files.
- `majeed_core.h` or any `majeed::` renderer.
- MAJEED parameter list, effect name, category, match name, version constants, logo, or PiPL identity.
- MAJEED exported entry points.

The XAO plugin must have one XAO-specific entry point and one XAO-specific PiPL identity. Dither and Lines must not appear as XAO effects.

## XAO core boundary

The current XAO engine contract is `xao::Engine::render(source, destination, RenderContext)`, with same-size images and linear premultiplied RGBA float pixels. The core pipeline is host-independent. The AE adapter therefore needs explicit conversion between AE pixel formats and this contract, correct rowbytes handling, output bounds, alpha semantics, and deterministic frame context. The MAJEED adapter's pixel conversion must not be copied blindly because it converts through straight RGB and makes assumptions about AE premultiplication and transfer characteristics that still require XAO-specific validation.

## Implemented compatibility change

`RenderContext::resolutionDpi` has been added with a 300 DPI default so the print-screen engine package's LPI-to-pixel conversion can be represented without breaking existing aggregate/default construction. The AE adapter must set a reliable value when available; 300 DPI is only a fallback default, not a claim about every composition.

## Remaining hard blockers before a valid XAO AEX build

1. The live XAO branch still does not contain the Adobe SDK tree expected by the reference CMake.
2. No XAO-specific AE adapter/EffectMain exists in the branch.
3. No XAO PiPL resource or XAO native shared-library target exists.
4. No XAO Windows workflow exists.
5. The InkMixer package source is not yet reconciled into the live branch; the earlier local 6/6 test result was from a package-copy workspace, not the branch.
6. No Windows/MSVC/PiPL/AE runtime verification has been performed.

Do not create a knowingly failing workflow or label a portable-core test as an AEX build. The next implementation unit is the XAO AE adapter plus SDK provisioning, followed by the XAO PiPL/CMake target and Windows workflow.
