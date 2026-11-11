# Decompiled ASCII Plug-in Control Map — Pass 32

Date: 2026-11-07
Scope: inspect the supplied decompiler outputs and embedded strings for L3tt3rM4pp3r2, OVN ASCII, S1 ASCII Art and Crates ASCII. Decompiled C is not original vendor source; strings and symbol evidence are used only to identify likely features/dependencies.

## 1. S1 ASCII Art — native AE reference with embedded font atlas

The supplied `S1AsciiArt.aex.c` contains these visible UI/control labels:
- Color & Palette
- Palette Color Strength
- Characters
- Blend Mode
- Background

Other strings include:
- "Embedded font atlas is not initialized."
- "Cannot create the ASCII grid: invalid parameters or working-memory limit exceeded."
- An embedded `stb_truetype.h` source path from the original developer's After Effects SDK project.
- A decompiler-recovered project path indicating an AE 25.6 SDK development environment.

### What can be concluded
- This is a native AE plug-in binary/decompiler output, not a browser or OFX-only effect.
- It appears to rasterize characters from an embedded font atlas and constructs an ASCII grid with an explicit working-memory failure path.
- The UI separates palette strength, character configuration, blend mode and background treatment.
- The presence of stb_truetype strings suggests a bundled font rasterization dependency, but does not establish the exact atlas packing, shaping support, Unicode coverage or alpha behavior.

### XAO implications
- Add a memory budget and graceful failure policy to glyph atlas/grid construction. Never allow huge cell counts or font atlases to cause uncontrolled allocation.
- Keep palette strength separate from glyph selection and blend mode.
- A bundled rasterizer does not solve complex-script shaping. XAO still needs HarfBuzz/bidi and glyph-ID based atlas generation for Arabic and other scripts.
- Do not copy decompiled code or embedded proprietary assets. This is a functional reference only.

## 2. Crates ASCII — additional ML/dependency evidence

The Crates ASCII binary metadata and strings contain a model manager command interface:
- CHECK_MODELS
- INITIALIZE_MODELS
- RUN_INFERENCE
- GET_MODEL_OUTPUT_SIZE
- DESTROY

The same binary includes model identifiers for:
- Depth Anything V3 (multiple small/base resolutions)
- Apple Depth Pro
- RealESRGAN
- SwinIR
- Restormer (deraining, motion deblurring, defocus deblurring, denoising)
- Retinexformer (low-light enhancement variants)

It also includes a model-input/analysis parameter group and Forge/Vulkan infrastructure strings.

### Important interpretation boundary
These strings show that the vendor plug-in package includes or knows about a broader ONNX/model-inference subsystem. They do **not** prove that Crates ASCII uses every listed model, that any listed model performs object segmentation, or that the model binaries are included in the supplied archive. The model names appear in a shared framework/manager and may be shared by other ProductionCrate plug-ins.

### XAO implication
The Smart Object Tracker should have its own explicit model/backend registry and feature requirements. Do not assume that a depth model is a segmentation tracker. A depth map can be useful later for depth-aware glyph layering or occlusion, but it is not a replacement for a promptable object mask.

## 3. L3tt3rM4pp3r2 and OVN ASCII

- L3tt3rM4pp3r2 decompiler output contains broad AE suite imports (including layer masks, mask outlines, text document/text layer, tracker, render, keyframe and color settings suites) and substantial OpenGL/WGL entry-point strings. These imports establish host/GPU capabilities or linked framework surface, not which capabilities are actively used by the ASCII algorithm.
- The supplied string scan did not reveal a trustworthy, human-readable UI control map for L3tt3rM4pp3r2. Do not infer specific tracking, mask or text features solely from imported suite names.
- OVN ASCII exposes its name and a project guide URL, but the supplied decompiler output does not expose a reliable algorithm or detailed controls.

## 4. Smart Object Tracker design refinement

The Crates model registry evidence reinforces the need for capability-based backend selection:
- Segmentation backend: must return object masks over time and support prompts/refinement.
- Depth backend: returns per-pixel depth; useful for depth-aware layering, not object identity.
- Optical-flow backend: estimates motion vectors; useful for motion gating/propagation, not a semantic object mask by itself.
- Enhancement/restoration backend: improves input frames; not tracking.

Keep these capabilities separate in XAO. A model should only appear as an available backend if its actual input/output contract satisfies the selected feature. For the first tracker prototype, SAM 2 remains a research candidate because its official video predictor accepts point/box prompts and propagates object masks through a video; the official repository also documents its Python/PyTorch/CUDA installation requirements and recommends WSL on Windows, so direct installation as an embedded dependency in the user's Windows AE process is not currently justified. See https://github.com/facebookresearch/sam2 and https://ai.meta.com/research/sam2/.

## 5. Licensing and reverse-engineering boundary

The AEX files and decompiler outputs are vendor binaries and derived analysis artifacts. No license permitting reuse of their code or embedded assets was established here. Use the UI/feature observations only; do not copy decompiled source, fonts, atlases, shaders or runtime components.

## 6. Status

Targeted control/dependency mapping only. This does not complete all ASCII sources or all archive files. No XAO build or AE runtime test was performed.
