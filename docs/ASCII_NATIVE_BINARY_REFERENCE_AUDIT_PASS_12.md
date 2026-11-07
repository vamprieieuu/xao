# XAO Focused Audit — ASCII Native Binary References — Pass 12

Date: 2026-11-07

## Scope

Inspected all four supplied ASCII plugin binaries and their four corresponding decompiler outputs:
- CratesASCII
- L3tt3rM4pp3r2
- OVN_ASCII
- S1AsciiArt

The `.aex` files are compiled third-party binaries. The `.c` files are decompiler output, not original vendor source. Strings and recovered metadata can support a behavioral/control inventory, but they do not establish the complete rendering algorithm, source license, or permission to reuse code.

## 1. Crates ASCII — recovered parameter metadata

The binary embeds a JSON-like effect description identifying these user-facing groups and controls:

### Character
- Characters Based On: Red / Green / Blue / Luma
- Character Set: Special Characters and Letters; Special Characters and Numbers; Classic Typewriter; Japanese Characters; Binary; Minimal Punk; X's; Bubble Growth; Stars; Diamonds; Dots; Circuits 1; Circuits 2; Alien Font; Bars
- Reverse Order
- Character Size
- Character Margins
- Cell Margins
- Anti-Aliasing

### Color
- Tint Strength and Tint Color
- Uniform Luma
- Invert Luma
- Invert Threshold
- Smooth Shading
- Background Color
- Blend With Original

### Random
- Random Shuffle
- Random Speed
- Random Color Amount
- X Flip Threshold

The metadata also includes presets such as Alien Signal, Circles and Dots, Classic, Corrupted, Crossword, Diamonds, Matrix, Motherboard, and Punk Shapes.

### Important architecture/runtime findings
- Binary strings identify a separate ONNX model subsystem with model discovery/loading, session management, inference commands, cancellation and error handling. It has explicit model path/initialization and inference failure cases.
- It references standalone shader assets and a GPU/DirectX compute path. This is not evidence of a CPU-only algorithm implementation.
- The embedded texture metadata includes a CEP-extension path from the original vendor's installation, indicating external product asset assumptions.
- This is a compiled product binary, not a clean source project. No verified license for source reuse is established by the supplied material.

**XAO decision:** treat the recovered controls/preset names as behavioral reference only. Do not depend on its ONNX subsystem, vendor CEP assets, GPU runtime, or proprietary binary. Rebuild any desired character-grid behavior natively and CPU-first. The AI/model-dependent behavior is not part of the baseline XAO ASCII renderer unless a separate, portable, licensed model workflow is designed and explicitly justified.

## 2. OVN ASCII — control inventory

The binary exposes:
- Character Set: ASCII / Code (0-F) / Shades / Blocks / Dots (Halftone) / Custom Layer
- Cell Size
- Color Mode: Mono (Ink/Paper) / Source Color / Terminal / Gradient
- Character
- Gamma
- Contrast
- Edge Structure: Off / Edges Only / Fill + Edges
- Edge Threshold
- Edge Stroke Width
- Custom Glyph Source
- Threshold and Threshold Feather
- Threshold: Shadows
- Color
- Paper (Background)
- Background Opacity
- Draw Over Source
- Depth Source
- Scanline Size
- Reactor > Cell Size

Its embedded product description also mentions a built-in audio-reactive glitch stage. The supplied decompiler output is insufficient to establish the complete algorithm or its exact audio-reactive timing behavior.

**XAO decision:** this is a useful control/feature reference for a flexible ASCII engine (including custom glyph source, edge structure, threshold and scanlines). Treat audio reactivity as an optional future feature only if the user's own visual references require it. No source-level implementation or license permission is established here.

## 3. S1 ASCII Art — control inventory and font implementation clue

The binary exposes:
- Cell Size
- Character Set
- Contrast
- Invert Density
- Color Mode: Monochrome / Source Color / Palette
- Text Color
- Background Color
- Background Opacity
- Solid Characters
- Palette Preset: Monitor Glow / Game Boy DMG / Oil 6 / Retrotronic / Gothic Bit / Curiosities / CGA Palette 1 / CGA Palette 1 Bright / CGA Palette 0 Bright
- Character Opacity
- Backdrop Brightness
- Auto Text Contrast

Additional strings identify Color & Palette, Palette Mapping, Palette Color Strength, Characters, Blend Mode and Background parameter groups.

The binary includes an embedded font atlas and references `stb_truetype.h` / TrueType table processing. It reports explicit errors for an uninitialized atlas and invalid parameters or working-memory limit exceeded. This suggests a native font-atlas pipeline rather than an external system-font-only renderer, but the strings alone do not prove every internal step.

**XAO decision:** the font-atlas and palette architecture are valuable behavioral references. XAO must use its own licensed fonts, robust shaping/BiDi and deterministic atlas cache. Avoid copying decompiled code or bundled third-party font assets without a verified license.

## 4. L3tt3rM4pp3r2 — limits of supplied evidence

- The supplied binary contains extensive OpenGL/WGL API and shader-related strings, consistent with a GPU-oriented implementation.
- The recovered decompiler file is very large and dominated by low-level runtime/graphics API material. A reliable user-parameter schema or original rendering algorithm was not established in this pass.
- Binary strings include no clear source code and do not establish a license for reuse.
- It should not be treated as a CPU-first architecture reference without further evidence.

**XAO decision:** keep it in the reference inventory, but do not infer features or algorithm behavior from generic OpenGL symbols. Further targeted decompiler work would be required before extracting any trustworthy control map.

## 5. Cross-plugin decisions

- These controls are not automatically a single combined UI. XAO's shared-control design remains the governing product requirement; use common controls only where the underlying engines genuinely share semantics.
- Character source, cell size, glyph set, density mapping, palette, background and edge treatment are reusable concepts, but each engine must define clear ranges and deterministic behavior.
- Do not adopt external model runtimes, CEP paths, vendor DLLs, or proprietary compiled assets.
- Preserve alpha and premultiplication consistently; a control named Background Opacity must not silently force the whole output opaque.
- Any audio-reactive or depth-driven mode needs an explicit source contract and should not be promised based only on binary strings.

## 6. Review status

This pass establishes binary-string/control metadata for CratesASCII, OVN ASCII and S1 ASCII Art, and records the evidence limitations for L3tt3rM4pp3r2. It is not original source-code review, license clearance, or runtime testing. Other ASCII source folders and remaining XAO groups still require review.
