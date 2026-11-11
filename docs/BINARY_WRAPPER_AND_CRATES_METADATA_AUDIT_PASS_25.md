# XAO Binary Metadata and Wrapper Audit — Pass 25

Date: 2026-11-07

Scope: inspect supplied PE/AEX binaries and decompiler outputs for Rays, Sapphire wrappers, Crates ASCII and Crates Halftone. These are reverse-engineering observations, not original vendor source and not permission to reuse proprietary code.

## 1. Rays and Glint are wrappers, not standalone algorithm sources

### Boris Continuum Rays
- `Rays.aex` imports/loads `BCCPlus.dll`.
- The decompiled `Rays.aex.c` obtains `get_driver_handle` and `do_command` from BCCPlus, resolves the effect using the plug-in name, then forwards effect commands to the driver.
- Therefore this AEX is a thin driver/loader wrapper. The actual BCC Rays implementation is in BCCPlus, not recovered in the supplied AEX decompilation.
- Do not infer the Rays image algorithm from this wrapper, and do not make XAO depend on BCCPlus.

### Sapphire S_Rays and S_Glint
- The decompiled wrappers read the Sapphire AE install/config location and attempt to load `sapphire_ae.dll`.
- They resolve `sapphire_main` and `sapphire_find_pinfo_for_effect`, then request the named effect (`S_Rays` or `S_Glint`).
- The wrapper includes failure handling/message text when the Sapphire DLL cannot be loaded.
- This confirms these files are bridge wrappers, not the underlying ray/glint algorithms. The supplied material does not reveal a reliable implementation of either algorithm.
- XAO must implement its own Rays and Glint engines and must not depend on Sapphire DLLs or copy proprietary decompiler output.

## 2. Crates ASCII binary metadata recovered

The supplied `CratesASCII.aex` contains an embedded JSON metadata string that can be parsed independently of the decompiler output. Identified:
- Product metadata: Crates ASCII, author Nate Lovell, description: imagery stylized with letters, characters and symbols.
- Presets: Default, Alien Signal, Circles and Dots, Classic, Corrupted, Crossword, Diamonds, Matrix, Motherboard, Punk Shapes.
- Character controls:
  - Characters Based On: Red / Green / Blue / Luma
  - Character Set: Special Characters and Letters, Special Characters and Numbers, Classic Typewriter, Japanese Characters, Binary, Minimal Punk, X's, Bubble Growth, Stars, Diamonds, Dots, Circuits 1, Circuits 2, Alien Font, Bars
  - Reverse Order
  - Character Size (0–500)
  - Character Margins (0–100)
  - Cell Margins (0–100)
  - Anti-Aliasing
- Color controls:
  - Tint Strength and Tint Color
  - Uniform Luma
  - Invert Luma
  - Invert Threshold
  - Smooth Shading
  - Background Color
  - Blend With Original
- Random controls:
  - Random Shuffle
  - Random Speed
  - Random Color Amount
  - X Flip Threshold
- Binary strings also show standalone shader assets (`filter_0.spv`, `analysis.spv`), `CratesASCII_infos.json`, ONNX model management commands, texture inputs, and layer-time-radius controls. These indicate a broader host/plugin framework with model/texture/time support; they do not prove that every feature belongs to the visible ASCII renderer.
- The binary imports/strings include Vulkan/Forge GPU infrastructure and NVIDIA CUDA-related components. This is not an appropriate dependency assumption for XAO's CPU-first target.

### XAO implications
- Useful visual/control references: luma channel selection, curated character sets (including Japanese), character/cell margins as separate controls, anti-aliasing, invert threshold, smooth shading, and independent random shuffle/speed/color/flip controls.
- Random animation must be deterministic from absolute AE time and a stable seed. Do not use mutable random state or elapsed wall-clock time.
- Character atlas generation must respect actual font coverage and shaped glyphs; a preset label such as Japanese Characters does not establish correct Unicode/font shaping.
- The SPIR-V binaries are compiled shader payloads, not readable source. No algorithm-level conclusions should be claimed from their names alone.

## 3. Crates Halftone binary metadata recovered

The supplied `CratesHalftone.aex` also contains embedded JSON metadata:
- Product metadata: Crates Halftone, author David Blaker, version 1.1.
- Visible controls:
  - Blending Mode: None / Multiply
  - Blend with Original
  - Cells
  - Independent Red, Green, Blue cell multipliers
  - Blurring
  - Black & White
  - Independent Red, Green, Blue channel rotations
  - Independent Red, Green, Blue channel centre/offset points
- Metadata includes a luma centre point, hidden texture samplers, and only Default as the named preset (besides None).
- The controls strongly indicate a multi-channel screen/halftone treatment with per-channel frequency/scale, angle and registration/centre controls. This is consistent with print-screen behavior, but exact dot geometry and sampling algorithm are not recoverable from the JSON metadata alone.
- The binary contains `filter_0.spv` and Forge/Vulkan/DX12-related framework strings. Treat the shader payload as opaque; do not claim its internal algorithm is understood without disassembly/validated shader analysis.

### XAO implications
- Preserve independent per-channel screen angle, scale/frequency and registration controls in XAO Halftone.
- Keep screen geometry (dot/line/shape) separate from channel registration and blend mode.
- Implement CPU fallback; do not inherit the original plug-in's GPU framework dependency.

## 4. Licensing and reverse-engineering boundary
- These Crates AEX files and decompiler dumps are vendor binaries/derived reverse-engineering artifacts. No source license granting code reuse was established by this inspection.
- Use metadata and visible behavior as functional reference only. Do not transplant decompiled implementation, embedded shader code, proprietary resources, or vendor runtime dependencies.

## 5. Exclusion reminder
The separate Dither Majid **Lines** effect remains excluded from XAO, including source, UI, controls, presets and any standalone engine. This does not exclude line-shaped Halftone geometry or the user's separate Threshold ASCII reference.

## 6. Audit status
This pass improves the control/architecture map but does not complete the full archive audit. No XAO build or AE runtime validation was performed.
