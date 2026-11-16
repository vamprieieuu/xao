# Folder 02 supplement — native AE plug-in build structure only

This supplement narrows Folder 02 to the user's clarified scope: **the valid workflow/structure for producing an After Effects native `.aex` plug-in**. ASCII algorithms, Dither and Lines engines are explicitly out of scope and are not analyzed or reused.

## What the folder actually contains for AE build workflow

### 1. Prebuilt native artifacts
`aex/` contains four compiled plug-ins:
- `OVN_ASCII.aex` — 199,168 bytes
- `L3tt3rM4pp3r2.aex` — 2,406,400 bytes
- `CratesASCII.aex` — 1,077,248 bytes
- `S1AsciiArt.aex` — 5,035,047 bytes

These are compiled PE plug-in artifacts, **not source projects or reproducible build recipes**. Their presence proves only that somebody produced binaries; it does not reveal a trustworthy CMake/VS/PiPL workflow by itself. No binary was decompiled as a build recipe.

### 2. Decompiled C representations
`c+/` contains matching `.aex.c` files (CratesASCII, L3tt3rM4pp3r2, OVN_ASCII, S1AsciiArt). These are decompiler output, not original C++ source and not buildable projects. They can expose symbols/structures but should not be treated as a source tree, PiPL source, SDK headers, or linker configuration. They are deliberately not used to reconstruct rendering algorithms.

### 3. No native project/build system found among these artifacts
The ASCII-main archive contains no matching AE `.sln`, `.vcxproj`, AE plug-in CMake project, PiPL resource source, DEF/export file, or repeatable native build script for those four AEX samples. Therefore this folder **does not supply a complete native AEX build workflow**.

## What is and is not reusable

| Evidence | Safe conclusion |
|---|---|
| Four `.aex` files | Examples of finished binary output only |
| Four `.aex.c` decompiler files | Reverse-engineering output; not source/build input |
| No PiPL/VS/CMake project alongside them | Build pipeline cannot be inferred from this folder |
| Open-source OFX ASCII sample | Different plug-in API/host; not an AE AEX workflow |
| Unity/WebGL/Qt projects elsewhere in folder | Useful only for their own builds; not AE plug-in packaging |

## XAO workflow requirements (design checklist, not copied code)

The reliable native build must be established from XAO's actual project and the matching Adobe SDK—not reverse-engineered from these binaries:

1. **Toolchain/architecture:** Visual Studio MSVC x64, correct Windows SDK and matching AE SDK headers/libs; avoid mixing x86 or MinGW objects with MSVC AE builds.
2. **Native target:** compile C/C++ plug-in sources into a Windows DLL whose final extension is `.aex`; set target architecture and output paths explicitly.
3. **AE entry/export:** define the expected AE plug-in entry point and export it with the appropriate DEF/export configuration; verify exported symbol and calling convention.
4. **PiPL:** maintain PiPL resource source and deterministic generator/resource-compiler steps; embed the generated PiPL into the final binary. PiPL identity/version/flags must match XAO and its SDK target.
5. **SDK integration:** include correct SDK headers and link only required libraries; keep SDK version and path explicit (e.g. configurable CMake cache variable) rather than relying on machine-specific hard-coded paths.
6. **Build configurations:** Release/Debug, x64, runtime library choice and compiler definitions should be consistent across all object files; avoid accidental dependency on debug CRT in release plugin.
7. **Post-build/package:** copy the built `.aex` to a clearly defined staging/install directory (and optionally AE Plug-ins test folder); preserve resources and dependency policy. Do not package source SDK unless license allows.
8. **Verification:** inspect PE architecture, required exports, embedded PiPL/resource, file output and dependency imports; fail the build on missing artifacts.
9. **Host smoke test:** launch the exact AE version (XAO target: AE 2023 23.2.1 x64), confirm plug-in discovery, effect name/category/controls, apply to footage, render a frame, save/reopen project, and check logs.
10. **Reproducibility:** document clean machine prerequisites, configure/build commands, output paths and installation; CI/build script should not silently claim AE runtime success.

These are engineering requirements for XAO, not claims that this folder implements them. Folder 03's ECW examples and folder 08's YMDithers AE wrapper contain additional UI/entry examples; their build/resource instructions are recorded in their own reports. Any reuse must be reviewed against XAO's own code and AE 23.2.1 SDK.

## Scope exclusions
- No Dither source analysis, port, or reuse.
- No Lines source analysis, port, or reuse.
- No ASCII rendering algorithm integration from this folder.
- No decompiler output copied into XAO.
- No binary AEX copied into XAO as a substitute for source/build.

## Verification
Archive paths and artifact inventory were inspected. No plug-in was built, loaded in AE, or validated at runtime. This supplement is an explicit source assessment and build-workflow checklist.
