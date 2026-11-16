# Aciify archive — Folder 03: `costuom ui`

> Analysis date: 2026-11-16  
> Source: `aciify.zip`, folder `aciify/costuom ui/`  
> Role: AE custom UI, SDK reference, GUI drawing libraries. This is research material; no source was merged into XAO.

## Inventory and preserved source references

- 492 ZIP entries, ~10.46 MB uncompressed.
- `AE_ECW_Examples-main/`: 3 native AE custom-Effect-Control-Window examples.
- `after-effects-sdk-kb-main/`: 47 files including 37 Markdown technical references, source/provenance registry, scripting and release notes.
- `imgui-master/`: 382 entries (Dear ImGui project snapshot).
- `nanovg-master/`: 33 entries (NanoVG vector drawing library snapshot).
- The original complete source collection remains in the user's `aciify.zip`; the key source paths and implementation observations below are recorded for later retrieval/porting. This report is a source map, not a replacement for original code.

## 1. AE_ECW_Examples — direct After Effects UI references

Repository snapshot README calls these working/buildable examples, but explicitly says UI/render behavior is **unverified in AE**. Build instructions use VS 2022 x64 and an installed AE SDK Examples path. They are the most directly relevant source in this folder because they use AE's own PF event and Drawbot APIs.

### ECW_Gallery
Paths:
- `AE_ECW_Examples-main/ECW_Gallery/src/ECW_Gallery.cpp`
- `ECW_Gallery.h`
- `ECW_Gallery_UI.cpp`
- `ECW_GalleryPiPL.r`

Implements reusable Drawbot primitives (fill/stroke rectangles, circles, lines, text, image buffer drawing) and a gallery of controls: XY pad, knob/dial, button, curve/response editor (cubic-Hermite interpolation → 256-entry LUT), and multiple independent canvases. Dispatch uses `PF_Event_DRAW`, `PF_Event_DO_CLICK`, `PF_Event_DRAG` and `effect_win.index`. The custom-control surface is created from a `PF_ADD_NULL` parameter; event canvas indices let widgets remain independently reusable.

**XAO application:** create custom Drawbot panel only for controls where native AE parameters are inadequate; use small reusable drawing helpers, explicit hit-testing and event dispatch. Keep the normal effect parameter API as the reliable fallback.

### ECW_Gradient
Paths:
- `AE_ECW_Examples-main/ECW_Gradient/src/ECW_Gradient.cpp`
- `ECW_Gradient.h`
- `ECW_Gradient_UI.cpp`
- `ECW_GradientPiPL.r`

A multi-stop gradient editor with a rendered gradient bar and draggable triangular handles. Click empty bar adds a stop sampled from the ramp; drag moves a stop clamped between neighbors; Alt/Option-click deletes while respecting minimum stop count; selecting a stop loads a color swatch and color changes write back. Stop data is held in an ARB parameter; edits raise `PF_ChangeFlag_CHANGED_VALUE`, joining AE's undo/change behavior. Rendering supports 8/16/32 bpc and is described as MFR-safe.

**XAO application:** strong reference for a Gradient Studio: stop list serialization, stable ordering/clamping, custom hit-testing, interaction semantics and AE undo integration. Reimplement/port carefully; do not transplant blindly.

### ECW_Histo
Paths:
- `AE_ECW_Examples-main/ECW_Histo/src/ECW_Histo.cpp`
- `ECW_Histo.h`
- `ECW_Histo_UI.cpp`
- `ECW_HistoPiPL.r`

Computes RGB and luminance histogram bins from upstream frames, supports ARGB128/64/32 world formats, maps values to bins, and tracks display peak excluding endpoint spikes. It uses the modern asynchronous upstream-frame request pattern from `PF_Event_DRAW`/RenderAsyncManager (AE 13.5+): cached frame → compute and update transient sequence state; uncached → request/schedule render and redraw later. Draws last valid cached histogram meanwhile to avoid panel flicker. Also demonstrates Levels adjustment and live-preview canvas.

**XAO application:** useful for histogram/threshold/levels visual controls, but async upstream rendering and sequence cache must be adapted to XAO's own lifecycle and thread-safety requirements.

## 2. After Effects SDK knowledge base — coverage and caution

The snapshot README says 37 Markdown files (~1.2 MB), covers C++ SDK through 25.6, ExtendScript through AE 26.0 and release notes through 26.2 (as of its stated 2026-04-19 update). It includes:
- Wave 1: plug-in architecture, Effect/AEGP/AEIO/Artisan, PF suites, data structures and errors.
- Wave 2: SmartFX, GPU effects, Multi-Frame Rendering/compute cache, audio/Premiere, sample code analysis.
- Wave 3: Mercury Transmit, suite versions, custom effect UI/Drawbot, 3D/camera/light, markers/keyframes, text/shapes, masks/paths, render queue, color management, undo/clipboard/preferences and footage/composition.
- Final consolidated reference, gap analysis, knowledge map, source registry/coverage.
- ExtendScript reference and UXP status; AE 26 release notes.

Important trust note: multiple files declare metadata `verified: false`, some report scraped/unknown source and use generated/Obsidian-style links. The document's own “100% coverage / zero gaps” statements are claims, **not independently verified guarantees**. Use it as an index/secondary guide and verify exact signatures, suite versions and SDK behavior against the installed Adobe SDK headers and official documentation before coding.

### Key reference documents recorded
- `final/MASTER-AE-SDK-REFERENCE.md`
- `final/GAP-ANALYSIS.md`
- `final/KNOWLEDGE-MAP.md`
- `wave-1/01-sdk-overview-architecture.md`
- `wave-1/02-effect-plugins.md`
- `wave-1/06-pf-suites-reference.md`
- `wave-2/01-smartfx-complete.md`
- `wave-2/02-gpu-acceleration.md`
- `wave-2/03-mfr-compute-cache.md`
- `wave-2/06-sample-code-analysis.md`
- `wave-3/04-effect-ui-custom-drawing.md`
- `wave-3/10-color-management.md`
- `release-notes/01-ae-26x-release-notes.md`
- `scripting/UXP-STATUS-NOTE.md`
- `SOURCES.md`, `source-registry.yaml`, `COVERAGE.md`

## 3. Dear ImGui (`imgui-master/`)

Snapshot is the upstream Dear ImGui immediate-mode GUI library, with core `imgui.cpp`/`imgui.h`, draw/list/font code, platform backends (Win32, GLFW, SDL, Android, etc.), renderer backends (DirectX 9–12, OpenGL, Vulkan, Metal, WebGPU, etc.), examples, tests and docs. Its backend architecture separates platform input/window integration from rendering backend.

**XAO relevance:** useful if we later build a separate companion configuration/editor app or internal tool. It is **not** a native AE Effect Controls UI solution by itself: integrating its own event/render loop into AE's panel is nontrivial and may conflict with host UI. For in-effect custom controls, ECW Drawbot examples are the direct fit. ImGui license is MIT (retain copyright/license if source is reused).

## 4. NanoVG (`nanovg-master/`)

Snapshot of NanoVG's antialiased vector drawing API/implementation (path, shape, stroke/fill, text, image, gradients), with GL backends and examples. It is a renderer/library—not an AE custom UI framework. It can inform vector drawing and gradient concepts, but requires a compatible rendering context and careful integration. Do not assume its OpenGL context can be created/owned inside AE Effect Controls; Drawbot is the host-provided route for custom ECW drawing.

## 5. Practical XAO UI plan derived from this folder

1. Keep standard AE parameter controls for stable host behavior and automation.
2. Add a custom Drawbot canvas only for genuinely visual editors (gradient stops, histogram, curve, XY/knob).
3. Each canvas gets independent layout, hit tests and event handlers; persist actual state in parameter/ARB data, not ephemeral UI-only memory.
4. Trigger AE parameter-change/undo correctly and make drawing robust to resize, DPI and event lifetimes.
5. Keep histogram/upstream requests asynchronous and cache-safe; never block UI drawing waiting for a render.
6. Validate against the exact AE 23.2.1 x64 SDK target; newer docs/sample claims do not automatically imply compatibility.
7. Consider ImGui only for external tooling, not as the first choice for embedded AE controls.

## Verification and limits

- ZIP inventory completed (492 entries); core ECW source files and representative SDK docs were extracted and inspected.
- This is a code/document analysis, not a build. No AE compilation, loading, event interaction or rendering test was performed.
- SDK knowledge base is secondary material with unverified metadata in places; confirm against Adobe headers/docs.
- Original archive is retained in conversation input; this report records key file paths and reusable implementation concepts. No external code has been merged into XAO.
