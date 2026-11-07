# XAO Reverse-Engineered Plug-in Findings — Pass 3

Date: 2026-11-07

This pass inspects the supplied decompiler-output files and extracts reliable structural clues. Decompiler output is not original vendor source and is not a clean-room implementation. It is used only to understand observable architecture, parameter clues and dependencies.

## ASCII binaries / decompiler outputs

### S1 ASCII Art
- The decompiler output contains a substantial custom font parser with references to OpenType/TrueType tables including cmap, loca, head, glyf, hhea and hmtx.
- It also exposes parameter labels for Color & Palette, Palette Mapping, Tonal/Original, Palette Color Strength, Characters, Blend Mode and Background.
- Blend modes visible in the binary strings include Normal, Multiply, Screen, Overlay, Soft Light, Difference and Add.
- This is a stronger font-rendering behavior reference than a fixed 8x8 bitmap charset. Reconstruct the font loading and glyph rasterization cleanly using supported font libraries; do not copy decompiler output.

### CratesASCII
- Binary strings expose an ONNX/model subsystem with model loading, inference, output-size queries, cancellation, and errors for missing model/library/session/inference.
- This indicates that some of its ASCII behavior may rely on machine-learning models and external ONNX runtime/model assets. It must not be treated as a conventional deterministic character-ramp renderer without further validation.
- The decompiler output also exposes many generic parameter framework labels and is very large. A complete parameter-to-render mapping remains pending.

### L3tt3rM4pp3r2
- The decompiler output is large and includes licensing framework strings and AE suite references.
- The extracted string scan did not yet establish a reliable mapping from user-facing controls to render math. Keep it in the binary-analysis queue.

### OVN_ASCII
- The binary contains broad AE suite references including sampling, iteration, world and parameter suites.
- The current string pass did not identify a sufficiently reliable control/algorithm map. Keep as behavior-reference-only pending structured decompiler analysis.

## Halftone binaries / decompiler outputs

### CratesHalftone
- The decompiler output exposes the same ONNX/model management command family as CratesASCII. The effect may use model-driven processing or shared plugin infrastructure; do not assume all visual behavior is classic analytic halftoning.
- Full parameter and inference-path mapping remains pending.

### Sapphire S_HalfTone / S_HalfToneColor / S_HalfToneRings
- The decompiler outputs show a loader/bridge that locates and loads Sapphire's shared runtime DLL, calls Sapphire entry points, and reports DLL-loading errors.
- The supplied files do not contain the original independent halftone algorithm implementation. They are wrappers around a proprietary Sapphire runtime.
- Do not attempt to integrate Sapphire runtime code or dependencies into XAO. Use the actual supplied reference footage and parameter behavior to implement independent algorithms.

## Glow / Glint binaries

### Deep Glow
- The decompiler output includes AE suite references, custom UI, licensing checks, and error strings around parameter checkout, world allocation, mask/matte setup and cleanup.
- These strings help identify architectural responsibilities but do not constitute a reusable Glow algorithm.
- Reconstruct XAO's Glow independently or use the separately licensed HaloGlow source after full dependency and license review.

### Starglow
- The decompiler output is very large and includes Radiance/HDR image format markers. This alone is not enough to infer its star-streak algorithm or parameter model.
- Requires dedicated disassembly/function mapping before any reliable behavioral claims.

### S_Glint
- Like other Sapphire effects, its decompiler output is a wrapper/loader for Sapphire's shared runtime DLL, not the complete glint algorithm.
- Treat as a visual and parameter reference only.

## Rays binaries

### Rays (BCC)
- The decompiler output exposes a dependency on BCCPlus.dll and a driver/bundle command interface.
- It is a wrapper that looks up a driver handle and dispatches commands; the actual effect processing is in an external BCC driver not included as source here.
- This supplied decompiler file cannot provide a standalone Rays implementation.

### S_Rays
- The decompiler output exposes Sapphire shared-runtime loading and effect dispatch.
- It does not contain the complete Sapphire Rays implementation. Use it for parameter/behavior research only.

## Consequence for XAO implementation

- S1 ASCII is the most promising binary reference for advanced font handling and character/palette controls, but its original algorithm must be reconstructed cleanly.
- Crates ASCII/Halftone may have ML model dependencies. Their model files, runtime dependencies, licensing and exact inference behavior must be identified before deciding whether to reproduce those features.
- Sapphire and BCC decompiler outputs are mostly loader/dispatch wrappers; they are not a source of portable effect algorithms.
- XAO must not depend on proprietary Sapphire/BCC runtime DLLs.
- No Lines effect from Dither Majid is included or ported.
- These findings are partial: strings and selected decompiler structures were inspected, not every decompiled function or control-flow path.
