# Aciify archive — Folder 02: `ascii [ main ]`

> Analysis date: 2026-11-16  
> Source: `aciify.zip`, folder `aciify/ascii [ main ]/`  
> Purpose: research/reference material for XAO (not code copied into XAO automatically).

## Inventory and coverage

- 422 ZIP entries: 345 files + 77 directories.
- About 89.7 MB uncompressed.
- Extracted to a working analysis directory and inventoried recursively.
- Contents include four compiled Windows After Effects plug-ins (`.aex`), four accompanying large `.aex.c` files, several open-source ASCII renderers, a shader package, a Qt desktop ASCII/halftone editor, screenshots, notes and six short visual-reference recordings.
- ZIP extraction completed; this is research material, not a single cohesive project.

## 1. Native AE plug-in samples (`aex/` and `c+/`)

Files:
- `OVN_ASCII.aex` (~199 KB), `OVN_ASCII.aex.c` (~493 KB)
- `S1AsciiArt.aex` (~5.0 MB), `S1AsciiArt.aex.c` (~1.49 MB)
- `L3tt3rM4pp3r2.aex` (~2.4 MB), `L3tt3rM4pp3r2.aex.c` (~8.24 MB)
- `CratesASCII.aex` (~1.08 MB), `CratesASCII.aex.c` (~5.56 MB)

The binaries are PE/Windows compiled plug-ins; the companion `.aex.c` files are generated/decompiler-style output, not trustworthy original source. They can help identify code paths, constants, UI strings and likely algorithms, but are not clean buildable SDK projects. Initial binary-string inspection confirms PE sections and machine code; it does **not** establish source-level behavior or runtime compatibility. Treat these as black-box/reference evidence until their exported entry points, PiPL/resource data and behavior are inspected separately.

## 2. ASCII Art Camera — C++/Qt/OpenCV

Repository snapshot: `ASCII Art main [open source]/` (MIT).

Architecture:
- C++20, CMake, Qt 6 Widgets, OpenCV 4, Catch2.
- A dependency-free engine layer (`src/engine`) separated from I/O/UI.
- Capture → newest-frame mailbox → conversion worker → Qt paint pipeline; latest-frame-wins intentionally drops stale frames rather than accumulating latency.
- Inputs: webcam, still images, video; file playback pause/seek.
- Modes: luminance, true-color, Sobel edge-directional glyphs; gamma/tone mapping and ramp selection.
- CLAHE/unsharp enhancement; rotation, mirror, invert; draggable aspect-preserving picture-in-picture.
- PNG snapshots and MP4 recording; terminal/headless renderer.
- Engine tests cover luminance, color, glyph mapping and frame mailbox. README advertises 21 tests (not independently run in this analysis).

Useful XAO lessons: isolate pure pixel math from host/UI; represent a grid as explicit cells; make edge direction select dedicated glyphs rather than merely changing density; keep preview responsive by dropping obsolete frames. AE implementation must use AE's render/effect lifecycle rather than Qt/OpenCV capture architecture.

## 3. ASCII Art Camera web build

`docs/` is a browser camera renderer with Canvas, camera permission/status handling, frame loop and UI controls. It is a companion implementation—not the C++ engine itself. Useful as a simple reference for camera-to-cell conversion and web presentation; not a native AE implementation.

## 4. ASCII OFX and GlyphBlocks OFX

- `ascii ofx [open source]/ascii.cpp` (~12.7 KB) + `font8x8_basic.h`: compact OpenFX ASCII effect reference with an 8×8 bitmap font. Its host API is OFX, so lifecycle/parameter wiring cannot be transplanted directly to AE.
- `glyphblocks ofx [open source]/glyphblocks.cpp` (~9.3 KB): another OpenFX glyph/block rendering reference. Potentially useful for glyph selection and block layout ideas; requires API adaptation.

## 5. Morphing ASCII Shader (Three.js/postprocessing)

Package: `@niccolofanton/morphing-ascii-shader` (MIT; source in `src/`, detailed `docs/PARAMETERS.md`).

Core components:
- `AsciiEffect.js`: glyph atlas, cell luminance mapping, optional Sobel contour characters, grain/noise, color modes and SDF-based glyph transitions.
- `MemoryGrid.js`: ping-pong render targets storing per-cell temporal state; exponential convergence makes characters morph rather than snap.
- `InkBleed.js`: bloom/ink bleed using Vogel-disk sampling and blur.
- Demo pipeline uses EffectComposer/RenderPass/EffectPass; TypeScript declarations and procedural flower-video generators are included.

Transferable concepts: persistent per-cell state, deterministic/varied glyph assignment, atlas-based rendering, edge glyphs, separated glow/bleed pass and parameter documentation. GPU textures/shaders are not directly AE SDK code; a CPU implementation or AE-compatible GPU path needs separate design.

## 6. AuraASCII (React + Three.js + WebGL2)

MIT TypeScript project; media-to-ASCII and generative shader tool.

- Supports images, GIF, video, webcam and GLSL math mode.
- Two-pass GPU pipeline: Sobel edge FBO (magnitude/angle/luminance) then glyph-atlas lookup/compositing.
- Glyph atlas is pre-rendered once, avoiding per-frame CPU text calls.
- Eight presets (Matrix, Amber, Cyan, Classic, Binary, Plasma, Ghost, etc.), raw ASCII clipboard and PNG export.
- Math shader executes in a null-origin worker with validation; repository describes file validation, upload limits and CSP.

Transferable concepts: edge angle as well as strength, atlas sampling, one-time glyph rasterization, explicit source abstraction and safe handling of user shader input. The worker/CSP security model applies to browser math mode, not to AE plug-in code as-is.

## 7. POINTLESS — large Qt image/typography application

Snapshot: `pointless [open source]/` (GPLv3; important license distinction).

This is the largest source project in this folder. CMake lists a Qt 6/C++17 application with a substantial CPU core, QRhi/Qt shader GPU path, UI, animation, project persistence, video I/O and tests.

### Core/render modules observed
- `Params.h`: extensive parameter/settings data model.
- `CellSample.h`, `ColorMath.h`: linear-light sampling and color calculations.
- `GridGenerator`: grid/sample generation.
- `AsciiRenderer`, `DitherRenderer`, `HalftoneRenderer`, `DotGridRenderer`, `MosaicRenderer`: separate renderers/modes.
- `BlendCompositor`: blend modes/compositing.
- `ImageAdjuster`: image adjustments.
- `AnimParams`/`Animation`: animated parameters and frame progression.
- `PaletteStore`: palette persistence.
- `ProjectIO`: JSON-backed project serialization, embedded-image handling and validation.
- `VideoIO`/`FrameStore`: frame/video infrastructure.
- `RenderWorker`: document rendering, export and CPU/GPU coordination.
- UI includes main window, GPU canvas, preview, mode/tonal/adjustment/control panels, layer panel, filmstrip and timeline.
- GPU shaders include ASCII, ASCII grid, dither, halftone, mosaic, dot, adjustment, composite and blit passes.
- Tests cover project/document state, export frame, audit regressions, glyph matching and GPU render checks (GPU test may skip when backend unavailable).

### Engineering takeaways for XAO
- Model parameters explicitly and separate renderer-specific settings.
- Keep CPU renderer as a reference/fallback and testable baseline.
- Treat ASCII, dither and halftone as distinct algorithms that can share sampling/color infrastructure.
- Use a consistent project/settings schema and validate imported data.
- Thread/render safety, deterministic outputs and CPU-vs-GPU parity deserve dedicated tests.
- POINTLESS is GPLv3; do not copy its code into a differently licensed XAO project without deliberate license review. Algorithmic ideas and independent implementation are safer; preserve attribution/license obligations for any reuse.

## 8. Visual references and Arabic notes

Folder `visuals/` contains six recordings and Arabic specification notes:
- **Ascii cgo**: randomized digits/letters/symbols, selectively randomized glow per glyph; ability to pin glow to selected glyphs/locations or randomize it; asks for controllable glow/color.
- **Ascii ghost**: each glyph inherits source/background color; adds rays; desired behavior for XAO.
- **Liquid ASCII**: rectangular colored cells/blocks, Japanese or arbitrary words/letters, random motion, variable text size, hide/show text, font and text-color controls; cell colors follow image.
- **Mosaic ASCII**: mosaic + glow + reduced saturation, random animated glyphs with highly varied glyph size; fine control over each aspect.
- **Rainbow ASCII**: asks for multicolor glow/rays while retaining same visual concept.
- **Threshold ASCII**: threshold-like effect with moving/random lines, rectangles and squares; extensive controls/colors desired.

These are user requirements/reference descriptions, not proof that any supplied binary has those exact capabilities. The recordings were catalogued and notes read; this report does not claim frame-by-frame motion measurement or exact pixel reproduction.

## 9. Relevance map for XAO

| XAO feature | Strongest reference in this folder | What to reuse conceptually |
|---|---|---|
| ASCII luminance + true color | ASCII Art Camera / AuraASCII | ramp mapping, per-cell source color |
| Contour glyphs/rays | ASCII Art Camera / AuraASCII | Sobel magnitude + angle, directional glyphs |
| Animated character morph | Morphing ASCII Shader | per-cell temporal memory, SDF morph |
| Glow/ink bleed | Morphing ASCII Shader + visual notes | separate glow/bleed stage and masks |
| Dither/halftone/mosaic | POINTLESS | distinct renderer modes, shared sampling |
| Glyph atlas / performance | AuraASCII | rasterize atlas once, GPU lookup |
| Animated random glyph layout | Liquid/Mosaic/visual notes | seeded randomness, cell state and controls |
| AE SDK implementation | compiled `.aex` samples only | investigate PiPL, entry points and host behavior; do not assume decompiler output is source |

## Limits / verification status

- ZIP was extracted and directory/file inventory completed.
- Source/document inspection covered the listed project architectures and key source modules; binary plug-ins are not reverse-engineered to original source.
- No project was built or executed here; README claims and test counts remain claims unless separately run.
- Visual videos are recorded as reference assets; this document does not certify a frame-by-frame review.
- No code from this archive has been integrated into XAO by this report.

## Bottom line

This folder is a multi-project research collection, not a ready-made AE effect. Its most valuable ingredients for XAO are: edge-aware character selection, glyph-atlas rendering, per-cell temporal memory, a modular CPU render core, independent ASCII/dither/halftone modes, explicit settings/project state, and the user's described glow/rays/liquid/mosaic/threshold looks. The native AE samples warrant a separate ABI/PiPL/resource/behavior investigation before any implementation decisions.
