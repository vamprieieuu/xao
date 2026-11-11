# XAO — Crates ASCII and Crates Halftone Reverse-Engineering Pass 53

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Evidence: supplied `CratesASCII.aex.c` and `CratesHalftone.aex.c` decompilations in the XAO archive.
Scope: establish plugin identity, recovered metadata/parameter schema, shader/runtime boundary, and next source-level trace targets. Static analysis only.

## 1. Naming clarification

The archive contains **ProductionCrate plugins** named `Crates ASCII` and `Crates Halftone`. These are not the same thing as the Rust package registry **crates.io**. The two concepts must not be conflated. This pass analyzes the two supplied Crates AEX decompilations; the separate Rust crates.io ecosystem is tracked as external candidate research.

## 2. Crates ASCII — confirmed facts

The decompilation identifies:
- Display name: `Crates ASCII`
- Author in embedded preset metadata: Nate Lovell
- Embedded plugin identifier: `PC_CratesASCII`
- Version string exposed by the plugin: `1.0.0.2.0`
- Embedded preset metadata version: 1
- Description: imagery stylized with letters, characters, and symbols
- Runtime shader directory: `plugin_standalones/CratesASCII/CratesASCII_shaders/`
- Embedded shader file path: `filter_0.spv`
- Embedded metadata file: `CratesASCII_infos.json`

Recovered metadata fields include:
- Character source channel: Red, Green, Blue, Luma (default Luma)
- Character Set options: Special Characters and Letters; Special Characters and Numbers; Classic Typewriter; Japanese Characters; Binary; Minimal Punk; X's; Bubble Growth; Stars; Diamonds; Dots; Circuits 1; Circuits 2; Alien Font; Bars
- Reverse Order
- Character Size (default 35; schema range 0–500 with divide-by-100 flag)
- Character Margins (default 0; schema range 0–100 with divide-by-100 flag)

The metadata JSON is embedded as a string in the decompilation. The decompiled native host code also contains an ONNX bridge with explicit status/error strings and commands for checking models, initializing models, running inference, destroying sessions, and retrieving model output size. This indicates an ONNX integration surface exists in the binary; it does **not** yet prove that the ASCII render path invokes ONNX or identify which model is required.

## 3. Crates Halftone — confirmed facts

The decompilation identifies:
- Display name: `Crates Halftone`
- Author in embedded preset metadata: David Blaker
- Embedded plugin identifier: `PC_CratesHalftone`
- Version string exposed by the plugin: `1.1.0.2.0`
- Embedded preset metadata version: 1.1
- Description: comic-style halftone patterns
- Runtime shader directory: `plugin_standalones/CratesHalftone/CratesHalftone_shaders/`
- Embedded shader file path: `filter_0.spv`
- Embedded metadata file: `CratesHalftone_infos.json`

Recovered metadata fields include:
- Blending > Mode: None, Multiply (default None)
- Blend with Original: default 50, range 0–100, divide-by-100 flag
- Properties > Cells: default 76, range 0–100
- Cells Red, Green, Blue: defaults 100, ranges 0–300, divide-by-100 flags

The source also contains extensive generic parameter-schema handling (dropdown, float sliders, integer sliders, rotation, color and texture parameter groups), JSON parameter loading, SmartFX pre-render/render support paths, and shader loading. This is evidence of a data-driven host/plugin framework, not proof that every generic path is used by this specific effect.

## 4. Rendering and portability boundary

Both plugins load a SPIR-V shader named `filter_0.spv`. The decompilation includes host-side setup, parameter parsing, shader resource loading and render/pre-render machinery. The shader source itself is not established by this text decompilation.

Do not port the ProductionCrate plugin's host framework wholesale into XAO. For XAO:
- reproduce the effect mathematics in the existing native C++ engine boundary;
- use a CPU implementation as the dependable baseline;
- treat GPU acceleration as optional and capability-gated;
- do not introduce ONNX, a web runtime, or a foreign plugin framework without a proven requirement;
- recover shader behavior from the actual SPIR-V/source assets and controlled before/after tests before claiming visual equivalence.

## 5. High-value next traces

1. Decode the complete embedded `CratesASCII_infos.json` and `CratesHalftone_infos.json` strings into standalone readable JSON, preserving all fields and option tables.
2. Trace ASCII's ONNX command callers to determine whether they are active in the render path, what models/files are expected, tensor shapes, preprocessing, and fallback behavior.
3. Trace the ASCII shader dispatch and `filter_0.spv` bindings: inputs, outputs, workgroup dimensions, sampling, glyph/charset data, color and alpha.
4. Trace Halftone shader dispatch and all user parameters, including pattern controls, cell geometry, channels, blend and original-image mixing.
5. Inspect the archive's associated standalone assets and shader binaries; hash and correlate them with the decompilation paths.
6. Compare the resulting behavior against the supplied reference clips/stills. Do not infer a feature solely from a parameter label.

## 6. External crates.io research — separate track

A preliminary registry search surfaced several potentially useful Rust packages, but none is automatically a suitable dependency for a native C++ AE plugin:
- `halftone`: terminal/image-to-ASCII conversion using histogram equalization and Floyd–Steinberg; CLI-oriented and includes optional OpenAI image-generation functionality. Useful as an algorithm reference, not a direct XAO engine.
- `dithr`: buffer-first Rust library with typed Gray/RGB/RGBA buffers for u8/u16/f32 and a broad set of dithering/halftoning methods. Strong candidate for algorithm study and fixtures; Rust code is not directly linkable as a C++ engine without a deliberate FFI/runtime decision.
- `ditherlib`: non-destructive image effects, polygon selections, print-style halftone screens, RGB/CMYK screen angles, and error-diffusion presets. Candidate for algorithm/reference analysis; inspect source and license before reuse.
- `px2ansi`: terminal-art renderer with character-set mapping and optional Floyd–Steinberg dithering; terminal output focus makes it a secondary ASCII reference.
- `blue-noise`: blue-noise dithering candidate; must verify actual algorithm, source, license and data assets before adoption.

The crates.io results are external research leads only. No Rust crate has been copied into XAO, and no Rust runtime/dependency has been added.

## 7. Limitations

This pass is a source/decompilation trace. It does not establish successful compilation, shader execution, exact pixel output, full parameter ranges, or compatibility with AE 2023. The embedded JSON excerpts recovered here are partial; complete field-by-field extraction remains the next task.
