# XAO — ASCII Archive Reinspection & Native Plugin Findings (Pass 41)
Date: 2026-11-08
Source files: user re-uploaded XAO.zip, fonts.zip, and نص.txt.
Status: original archive is now available and the ASCII source inventory has been re-established. This is a deep audit in progress, not yet a phase-closure declaration.

## 1. Verified archive inventory
- XAO.zip: 996 ZIP entries, 805 regular files, approximately 207.5 MB uncompressed.
- Dedicated ASCII folder: 351 regular files.
- ASCII top-level groups:
  - aex/: 4 native plugins.
  - c+/: 4 Ghidra-style decompilations.
  - ASCII Art main [open source]/: 48 files.
  - ascii ofx [open source]/: 2 files.
  - auraascii master [open source]/: 47 files.
  - glyphblocks ofx [open source]/: 1 file.
  - morphing ascii shader [open source]/: 53 files.
  - pointless [open source]/: 192 files.
- No dedicated Crates preset folder or standalone Crates preset files were found in the archive filename inventory. The Crates AEX and its decompilation are present; a separate preset package is not.
- User prompt نص.txt is 34,269 characters and sets the full XAO development and integration requirements.

## 2. Native AEX inventory
| File | Size | Evidence |
|---|---:|---|
| CratesASCII.aex | 1,077,248 bytes | PE/Windows native binary; Crates product strings and embedded parameter/config data |
| L3tt3rM4pp3r2.aex | 2,406,400 bytes | PE/Windows native binary; large AE suite/runtime footprint; readable effect-specific strings are sparse in basic extraction |
| OVN_ASCII.aex | 199,168 bytes | PE/Windows native binary; extensive readable control labels and character ramp |
| S1AsciiArt.aex | 5,035,047 bytes | PE/Windows native binary; embedded font data, GlyphAtlas-related symbols and detailed renderer strings |

Corresponding approximate decompilations exist for all four under c+/. Decompilation is not original source and must be treated as uncertain where control flow, types or indirect calls are unresolved.

## 3. Crates ASCII — new findings from its decompilation
Verified strings and embedded configuration:
- Product identity: Crates ASCII (Free) / ProductionCrate.
- Embedded config path: plugin_standalones/CratesASCII/CratesASCII_infos.json.
- Embedded preview asset name: CratesASCII_low.png.
- Parsed configuration fragment exposes a grouped Character section:
  - Characters Based On: Red, Green, Blue, Luma.
  - Character Set options: Special Characters and Letters; Special Characters and Numbers; Classic Typewriter; Japanese Characters; Binary; Minimal Punk; X's; Bubble Growth; Stars; Diamonds; Dots; Circuits 1; Circuits 2; Alien Font; Bars.
  - Reverse Order.
  - Character Size.
  - Character Margins.
- Decompilation also contains an ONNX integration command interface and model identifiers:
  - Depth Anything V3 small variants at 336/518/770/1036 FP16.
  - Apple Depth Pro 1536 FP16.
  - RealESRGAN x4 WDN.
  - SwinIR real-world super-resolution x4.
  - Restormer deraining, motion deblurring, defocus deblurring and denoising.
  - Retinexformer low-light and related variants.
- ONNX command names include check models, initialize models, run inference, destroy, get model output size; error/status names include model not found, library not found, inference failed, out of memory and cancelled.

Interpretation limits:
- These strings prove that model integration/configuration code is present in the binary/decompilation. They do not prove every model is shipped, initialized, licensed, available offline, or used by the ASCII render path.
- Do not make ONNX/model inference a mandatory dependency of XAO ASCII. Treat depth/AI enhancement as optional analysis modules after verifying actual call sites, packaging, and runtime behavior.
- The decompiled parameter JSON literal is truncated by the decompiler at the point inspected; the first five labels are verified, but this is not yet a complete Crates parameter inventory.

## 4. OVN ASCII — verified control surface
Readable strings in the native binary and matching decompilation identify:
- Character Set: ASCII, Code (0-F), Shades, Blocks, Dots (Halftone), Custom Layer.
- Cell Size; Cell Aspect.
- Color Mode: Mono (Ink/Paper), Source Color, Terminal, Gradient.
- Amount; Character; Invert Ramp; Gamma; Contrast.
- Edge Structure: Off, Edges Only, Fill + Edges.
- Edge Threshold; Edge Stroke Width.
- Custom Glyph Source; Threshold; Threshold Feather; Threshold: Shadows.
- Color; Ink (Foreground); Paper (Background); Gradient High; Background Opacity; Draw Over Source.
- Depth (3D); Depth Source: Off, Auto (Luminance), Depth Map Layer; Depth Map; Invert Depth (Near = Dark); Parallax; Parallax Angle; Pop (Near Scale); Depth Fog.
- Glitch; Enable Glitch; RGB Split; Split Angle; Block Displace; Scanlines; Scanline Size; Flicker; Noise.
- Reactor (Audio); Reactor; Reactor > Glitch; Reactor > Cell Size.
- An embedded ASCII character ramp is present in the binary; preserve it verbatim from the raw binary extraction before using it as a preset.

Inferred from labels only: the effect exposes distinct character-set, color, edge, depth/parallax, glitch and audio-reactive groups. The labels alone do not prove the mathematical implementation or quality of each path. Inspect corresponding render functions before implementation.

## 5. S1 ASCII Art — verified native implementation clues
Verified from decompilation/binary strings:
- Effect identity: S1 ASCII Art / S1LAX.
- Error messages distinguish invalid input/output pixel buffers or depth mismatch, uninitialized embedded font atlas, invalid grid parameters/working-memory limit, and oversized image dimensions.
- UI groups include Color & Palette and Palette Mapping; palette mapping choices include Tonal and Original.
- Controls include Palette Color Strength, Characters, Blend Mode with Normal, Multiply, Screen, Overlay, Soft Light, Difference, Add, and Background.
- Embedded glyph ramp string is present.
- Decompilation contains C++ symbols/namespaces for s1ascii::GlyphAtlas, WorkingGlyphMasks, DetailedIdentity, and SpecialtyIdentity.
- Embedded font metadata strings identify IBM Plex Mono, VT323, Space Mono, Press Start 2P, Share Tech Mono, Courier Prime, and several Px437/VileR bitmap-inspired fonts. Several included font notices explicitly identify SIL Open Font License 1.1 or CC BY-SA 4.0; verify each embedded font's own notice before reuse.

Interpretation limits: a GlyphAtlas symbol and embedded fonts strongly support an atlas-based renderer, but the exact matching/search strategy, sampling and anti-aliasing path must be traced through the actual decompiled functions. Do not infer a specific glyph-matching algorithm from names alone.

## 6. L3tt3rM4pp3r2 — current findings
- Binary is 2.4 MB; decompilation is 8.24 MB.
- It exposes a broad After Effects SDK suite footprint, including text/document/layer/mask/render/collection/tracker-related suites. Much of this is generic host/runtime capability and is not proof that the effect implements every suite's user-facing functionality.
- Basic strings are dominated by runtime, localization, licensing and AE SDK suite names; effect-specific controls were not reliably recovered by simple string extraction.
- Next step: isolate its parameter setup, command dispatch and render entry points in the decompilation, and inspect embedded resources/PiPL separately. Do not assign unsupported functionality based only on suite imports.

## 7. Open-source directory corrections and technical notes
The supplied ASCII folder contains four substantial Open Source projects plus two compact OFX sources:
1. ASCII Art main — C++/Qt/OpenCV, core engine, glyph mapper, frame converter, capture/UI and unit tests.
2. ascii OFX — one C++ source and an 8x8 font header.
3. auraascii — TypeScript/WebGL2 renderer, glyph atlas, edge shader, preset/control UI and image/GIF/video/math sources.
4. GlyphBlocks OFX — one C++ source.
5. morphing ascii shader — JavaScript/Three.js/postprocessing, core ASCII shader, MemoryGrid, SDF/morph controls, InkBleed and many animated parameter demonstrations.
6. POINTLESS — substantial C++/Qt application, CPU renderers, GPU shaders, animation, project I/O, layers, UI and tests.
The earlier Pass 40 report mentioned Theovia/ascii-lab as an external comparison; it is not one of the supplied top-level ASCII folder projects and must not be counted as an archive asset.

### Key source-level finding: Morphing ASCII MemoryGrid
The actual source implements a ping-pong render-target memory grid at one texel per ASCII cell. Each update blends previous per-cell luminance/color toward the current target using exponential smoothing and derives morph activity from the residual. This is a genuine temporal feedback design, not just a README feature.
XAO decision: do not directly port its mutable frame-by-frame update into AE Smart Render. AE may render frames out of order, in reverse, concurrently or under MFR. Recreate the desired visual behavior with absolute-time/stateless functions or an explicit analysis pass that writes immutable timestamp-indexed state.

### Key source-level finding: Morphing ASCII InkBleed
The actual source implements a separate post-ASCII ink diffusion/blur pass using a 64-sample Vogel disk kernel, with precomputed kernel values and independent bleed/blur controls. The code comments report a measured optimization on an Apple M1 Pro; that benchmark is not transferable to the target CPU or AE.
XAO decision: useful as a separate emission/ink diffusion concept; implement a bounded CPU approximation or optional accelerated path and benchmark on target hardware. Do not assume 64 taps per pixel is acceptable on an older Intel CPU.

### Key source-level finding: Morphing ASCII parameter semantics
The parameter document explicitly describes cellSize (grid resolution), glyphScale (glyph size inside cell), charset ordered light-to-dark, deterministic variety jitter, invert, colorMode, ink/background, whiteCutoff, brightness, contrast, gamma; Sobel edge mode and directional edge glyphs; glyphBlend, magnet, SDF morph, plus other memory/noise/bleed controls.
This supports separating grid density from glyph scale and distinguishing color modes. It does not make the temporal implementation AE-safe as-is.

## 8. Font archive — verified inventory
- fonts.zip: 49 ZIP entries, 45 regular font files, approximately 6.62 MB uncompressed.
- Folders: Arabic (24), English (10), Symbols/Weird (11).
- Font metadata was read from each font's name/cmap tables. The Arabic collection includes A Massir Ballpoint, A Naskh Tahrir, Arslan Wessam A/B, A-bad kh@t, Afsaneh, Guesswhat Exceptional, Arabic Childhood, B Shekari, Digi Hilan, K Kamran, KA Hand Naskh variants, Maqroo, Methlama, Milan Display, Nasma, RooyinFree, YR Sponge Arabic, Tajarib, Takeaway Combo, Ummi and ZIAN Black.
- Unicode cmap coverage is not proof of correct Arabic shaping or connected contextual forms. Test with shaping and bidi libraries; classify fonts by actual Arabic glyph coverage and shaping behavior.
- Some supplied fonts are explicitly open-licensed, while several have proprietary/personal-use/unclear notices from prior review. Do not bundle or redistribute the latter until individual license terms are confirmed.
- S1 embedded fonts are separate from the user-supplied font archive; their notices must also be tracked independently.

## 9. XAO architecture decisions reinforced by the new evidence
1. Unified ASCII Engine is one engine with multiple render strategies and editable presets, as the user prompt specifies. Keep genuinely distinct render strategies (ramp, edge, tile/text, mosaic multi-scale, threshold segments, palette/color, depth/glitch/audio-reactive) as internal modes or capabilities, not separate unrelated plugins.
2. Separate cell size from glyph scale.
3. Support selectable channel/luminance sampling, character set/ramp, invert, margins, and actual per-cell source color.
4. Edge processing must be independently enabled and must not overwrite all glyph behavior unless selected.
5. Depth/parallax is an optional analysis stage; never make model downloads/network access mandatory.
6. Glitch, scanline, flicker, noise and audio reaction must be independent optional modules with deterministic time behavior.
7. Morphing and trails must not depend on render call order.
8. Multi-font mixing needs actual per-cell font assignment and weight/distribution logic, not merely a multi-select UI.
9. Arabic text mode requires bidi + shaping; glyph-art mode deliberately uses independent glyph marks.
10. Preserve source alpha/premultiplication and stable layer-anchored cell coordinates.

## 10. Open gates — ASCII phase remains in progress
- Complete Crates config extraction beyond the truncated JSON and trace which ONNX model commands are actually called from rendering/UI paths.
- Trace L3tt3rM4pp3r2 parameter registration and render path; inspect resources and embedded strings.
- Trace S1 glyph atlas creation, glyph matching/ramp selection, sampling, alpha and thread behavior.
- Read every relevant source file in ASCII Art main, ascii OFX, auraascii, GlyphBlocks OFX, morphing ascii shader and POINTLESS; record licenses and identify code worth independently implementing.
- Inspect all bundled demos/GIFs/videos for the open-source projects as needed to validate behavior.
- Finish font license manifest and Arabic/English/symbol cmap/shaping test report.
- Compare dedicated ASCII folder original assets against prior Pass 40 assumptions.
- Do not begin Halftone until these gates are completed and the ASCII phase is explicitly closed.

## 11. Confidence discipline
- Verified: direct strings, config fragments, source code, file inventory and font metadata.
- Inferred: proposed XAO architecture and behavior suggested by names or examples.
- Unknown: algorithms not yet traced or tested.
No AEX has been run in After Effects in this pass; no runtime behavior or crash-free compatibility is claimed.