# XAO — Archive Validation & Licensing Pass 42

Date: 2026-11-10
Scope: reinspection of the uploaded XAO.zip, existing local InkMixer test build, and the dedicated recovery branch.
Status: audit continuation; no engine phase is declared complete.

## 1. MAIN IDEAS media inventory

The extracted MAIN IDEAS directory contains 12 top-level reference groups:
- Shape Halftone
- Dither asci_
- Liquid ascii
- Mosaic asci_
- Ascii ghost_
- Array_
- Ascii cgo_
- Thridshold asci_
- Pixeldithergo
- Golden glow halftone_
- Typeset
- Rainbow ascii_

Nine video files are present in MAIN IDEAS. ffprobe metadata confirms:
- Eight MOV clips at 60 fps, with frame counts 145–276 each.
- One MP4 clip at 240 fps, 866 frames.
- Total declared frames across the nine primary clips: 2,514.
- The clips include 214x386 through 656x354 MOV sources and one 828x1792 MP4.
This is metadata verification only. Contact sheets/sample frames exist in the working audit folder, but this pass does not claim manual inspection of every one of the 2,514 frames.

The folder also contains reference notes in Arabic for Liquid ASCII, Mosaic ASCII, ASCII Ghost, ASCII CGO, Threshold ASCII, and Golden Glow Halftone. Dither ASCII, PixelDitherGo, Rainbow ASCII, Array, Shape Halftone and Typeset also have visual assets/settings folders that must be read alongside their clips or images.

## 2. Open-source project and license inventory

### ASCII
- ASCII Art main: MIT license present.
- auraascii: MIT license present.
- Morphing ASCII Shader: MIT license present.
- POINTLESS: GPL-3.0 license present, plus a separate third-party license manifest. Treat its code as GPL-covered unless individual files/dependencies establish otherwise; do not copy it into a differently licensed proprietary distribution without resolving obligations.
- ascii OFX and GlyphBlocks OFX are compact source drops; no top-level license file was found beside either source in the archive. Do not assume permission to redistribute.
- The four supplied AEX binaries and their decompilations are reference evidence, not source code licenses.

### Glow
- HaloGlow: MIT license present; source includes AE-related code and CPU/GPU backends. GPU source includes CUDA and OpenCL. Port only the needed algorithm/core after checking SDK/API dependencies and build compatibility; do not pull its whole application/runtime stack into XAO.
- Superbloom: MIT license present, but the archive is a web/Electron/Photoshop-oriented project. Its visual algorithms may inform a native implementation; its UI/runtime is not an AE-native drop-in.

### Other Open Source
- Trapper Photoshop: Apache-2.0 license present. It is a Photoshop extension/project, not a native AE plugin. Reuse of independent algorithms is conditional on dependency and license review.
- Filtr: MIT license present. Its source is a web-oriented image editor/engine; inspect individual modules for reusable algorithms, not the app shell.

### Halftone
Seven project folders are present: Dean, Eas, Akam, PS, Master, Lap, and Mike.
- Dean: MIT license present.
- Lap: MIT license present.
- Akam contains BOTH a LICENSE.md titled "Personal Use License" and a separate MIT LICENSE file. This is a material license conflict; do not select the permissive interpretation or copy its code until provenance/ownership of the two license files is resolved.
- Eas and PS did not show a top-level license file in the extracted archive inventory; treat as no clear reuse permission until verified.
- Master and Mike contain identical Halftone.cpp / Halftone.hpp / HalftoneVector.hpp / HalftoneSampler.hpp source copies. Count them as one distinct source implementation for algorithm analysis, not two independent engines.

### Dither
The archive contains the small OFX dither source. It does not include the separate Dither Majid repository itself in this ZIP; use the user's linked/reference repository separately for algorithm and build-architecture review. The separate Lines effect remains excluded.

### Rays / Glint
The archive contains two Rays AEX binaries and matching .h decompilation files. The Glow folder contains S_Glint.aex and a corresponding decompilation. These are reverse-engineering references only; do not infer a license to reproduce their proprietary code.

## 3. Existing local InkMixer test build

Ran:
`ctest --test-dir /mnt/data/xao_audit/build-ink --output-on-failure`

Result: 6/6 tests passed:
- xao_core_tests
- xao_ink_mixer_tests
- xao_plate_state_tests
- xao_screen_pattern_tests
- xao_ink_separation_tests
- xao_ink_mixer_frame_tests

This verifies the test binaries in the supplied local build directory. It does not prove that the same source revision is present on the GitHub recovery branch, that a clean rebuild succeeds, or that the AE plugin loads/renders in After Effects.

## 4. Integration and safety decisions

1. Keep the ASCII engine as the first phase until the Pass 41 open gates are closed; do not begin Halftone implementation prematurely.
2. Keep the Halftone source candidates separated by license status. The Akam dual-license conflict is a hard stop for code reuse.
3. Do not copy GPL-3.0 POINTLESS code into a proprietary XAO binary without an explicit licensing decision. Algorithmic reimplementation from observed behavior is a separate path; avoid copying protected expression.
4. Do not treat Photoshop, web, Electron, OFX or GPU-specific projects as native AE components. Extract only isolated, technically compatible algorithms after dependency review.
5. No paper layer or paper-surface simulation is part of XAO Halftone.
6. Do not include the standalone Dither Lines effect.
7. No After Effects runtime validation was performed in this pass.

## 5. Remaining gates

- Finish function-level review of the ASCII native AEX decompilations, especially Crates parameter setup/model call sites, S1 GlyphAtlas/matching path, and L3tt3rM4pp3r2 dispatch/render path.
- Read and classify all source files in each ASCII project, not only READMEs and high-level docs.
- Finish per-font license manifest and Arabic shaping/bidi test fixtures.
- Complete visual review of all MAIN IDEAS clips and static references, recording exact settings and temporal behavior where recoverable.
- Resolve the Halftone Akam license conflict and missing licenses for the unlicensed source drops.
- Compare the local InkMixer source/build against the exact recovery branch before integrating or replacing anything.
- Perform a clean configure/build and then AE 2023 Windows x64 validation on a real target environment before making compatibility claims.
