# XAO — Crates Runtime Boundary and Asset Completeness Trace (Pass 54)

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Evidence: archive files `ascii [ main ]/c+/CratesASCII.aex.c`, `halftone/c+/CratesHalftone.aex.c`, and matching AEX binaries.

## 1. Runtime asset references are explicit

The Crates ASCII decompilation constructs and registers these standalone paths:
- `plugin_standalones/CratesASCII/CratesASCII_shaders/`
- `plugin_standalones/CratesASCII/CratesASCII_shaders/filter_0.spv`
- `plugin_standalones/CratesASCII/CratesASCII_infos.json`
- `plugin_standalones/CratesASCII/CratesASCII_low.png`

The Crates Halftone decompilation similarly references:
- `plugin_standalones/CratesHalftone/CratesHalftone_shaders/`
- `plugin_standalones/CratesHalftone/CratesHalftone_shaders/filter_0.spv`
- `plugin_standalones/CratesHalftone/CratesHalftone_infos.json`
- `plugin_standalones/CratesHalftone/CratesHalftone_low.png`

The archive's two matching AEX files are PE32+ x86-64 Windows DLLs. The supplied archive inventory does not contain separately extracted `.spv`, JSON, or preview PNG files at those runtime paths. The decompilations do embed JSON text and show path registration, but the shader bytes are not recovered as readable GLSL/source by these decompilations.

## 2. Embedded JSON is truncated in the decompiler output

The ASCII decompilation contains the beginning of a literal JSON document, including the preset metadata and the first user controls. The literal is explicitly truncated in the decompiler output with an ellipsis marker. It is therefore not possible to reconstruct the complete original JSON schema faithfully from this text alone.

The Halftone decompilation likewise embeds its JSON literal, but this pass has not extracted a complete schema from the original binary resource. Do not publish an invented “full” parameter table.

## 3. ONNX: evidence and boundary

The ASCII decompilation contains a set of ONNX command/status strings, including model check, model initialization, inference, destroy, output-size, and failure states. The command-name construction appears in repeated generated/decompiled wrapper blocks (including many repeated `RUN_INFERENCE` occurrences).

This proves that the binary contains an ONNX command bridge/interface. It does **not** by itself prove:
- that the ASCII shader/render path calls the ONNX bridge;
- which model files are expected or shipped;
- tensor dimensions, input normalization, output semantics, or model purpose;
- whether ONNX is mandatory, optional, or an unused framework facility.

No model file or ONNX Runtime dependency has been found in the inspected archive paths during this pass. Absence from this limited file inventory is not proof that the original commercial installation never shipped such files.

## 4. Architecture implication for XAO

The strongest transferable Crates ideas at this stage are:
- data-driven, named user-parameter schemas;
- independent character-source channel and charset selection;
- a clean distinction between effect metadata, UI schema, and render configuration;
- a shader-backed implementation boundary that can be replaced with XAO's CPU-first native renderer.

Do not add ONNX Runtime or a Rust runtime to XAO based only on these strings. Do not claim shader parity until the SPIR-V is recovered/disassembled or the original effect is tested with controlled inputs.

## 5. Next evidence needed

1. Recover the complete JSON and SPIR-V payloads from the original installation/package, not just the supplied decompiler text.
2. If only AEX files are available, inspect PE resources/sections and embedded blobs to determine whether shader/model assets are embedded or loaded externally.
3. Trace the actual render call graph from AE render entry to parameter parsing, shader dispatch, and output writeback.
4. Use controlled test images to isolate character-set, channel, reverse-order, size, margins, halftone cell, channel weighting, blend and original-mix behavior.
5. For ONNX, identify the caller that sends the command and the concrete model path/session lifecycle before considering it relevant to XAO.

## 6. Scope and confidence

This pass confirms runtime path references, PE file architecture, the decompiler's JSON truncation boundary, and the existence of ONNX command strings. It does not recover the shader source, full JSON schema, ONNX model, or a complete render call graph. No source code was copied into XAO and no AE runtime test was performed.
