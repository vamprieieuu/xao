# XAO — Original ASCII AEX Decompilation Trace (Pass 44)

Date: 2026-11-10
Scope: targeted inspection of the supplied decompiled C/C++ listings for four original After Effects ASCII plugins. This is static analysis of the supplied decompilations, not a clean-room reconstruction of the original source or a runtime test.

## 1. S1 ASCII Art — native glyph-atlas path

Evidence in `c+/S1AsciiArt.aex.c`:
- The decompilation exposes named native types/symbols `s1ascii::GlyphAtlas` and `RenderParams`, a global atlas instance, an atlas build path, and a render function.
- The plugin entry dispatches About, global setup, parameter/UI update and Render commands. The render command dispatches to `Render(...)`.
- The global setup path calls `BuildAtlas()`; the renderer checks whether the embedded font atlas is initialized and emits the diagnostic string `Embedded font atlas is not initialized.` when it is not.
- Visible parameter/UI strings include `Color & Palette`, `Palette Color Strength`, `Characters`, and `Blend Mode`.
- The renderer references the atlas and render-parameter structures rather than being only a simple text/string overlay.

XAO relevance:
- This is the strongest supplied AEX decompilation evidence so far for a native glyph-atlas architecture and a dedicated character/palette/blend control surface.
- Investigate the atlas construction and per-cell render path further before adopting equations or control ranges. The current pass does not establish exact glyph matching, atlas packing, font coverage, Unicode shaping, or GPU/CPU implementation details.
- Preserve the user's distinction between Arabic text shaping and independent glyph-art mode; the mere presence of a Characters control does not prove either.

## 2. Crates ASCII — parameter and command-dispatch evidence

Evidence in `c+/CratesASCII.aex.c`:
- `EffectMain` has explicit dispatch cases for setup, sequence-related commands, parameter/UI handling and rendering; the render case calls a separate internal render routine.
- The setup case assigns version/flag fields and invokes an internal setup function. The values in this decompilation are evidence about this plugin only and must not be copied into XAO PiPL metadata.
- The source contains dynamically described parameter types including `Slider_Float`, `Slider_Int`, `Checkbox`, and popup/slider parameter declarations, with generated names such as `FORGE_SLIDER_...`.
- Embedded preset metadata identifies the product as “Crates ASCII” and describes imagery stylized with letters, characters and symbols. The decompilation also references an external plugin-standalone info JSON asset.
- The entry point identifies the plugin as “Crates ASCII (Free)” from ProductionCrate.

XAO relevance:
- This plugin uses a data-driven parameter/preset layer rather than a small fixed hand-written control list.
- Its external preset/info asset mechanism is product-specific and is not a reason to add external runtime dependencies to XAO.
- A parameter type string or embedded preset label does not establish the visual algorithm behind that control.

## 3. OVN ASCII — limited dispatch trace

Evidence in `c+/OVN_ASCII.aex.c`:
- The entry point exposes the standard About, global setup, parameter setup, render, and additional command branches in the supplied decompilation.
- Its registration string identifies “OVN ASCII” by Oblivixn and points to `https://oblivixn.de/guide#ovn-ascii`.
- The visible dispatch shows a dedicated render branch and a separate parameter setup branch; the internal functions still need tracing before any visual behavior can be attributed to them.

Limit:
- This pass does not yet establish OVN's glyph-selection algorithm, supported character sets, color behavior, or exact parameter semantics.

## 4. L3tt3rM4pp3r2 — shader/web-rendering evidence

Evidence in `c+/L3tt3rM4pp3r2.aex.c`:
- The decompilation contains a substantial embedded JavaScript/GLSL runtime, shader strings, render-target helpers such as `SB_initRenderTarget`, `SB_blitRenderTarget`, and `SB_renderShader`, and WebGL/OpenGL symbol references.
- It includes a `preRender(w,h)` JavaScript hook and a separate parameter/shader pipeline.
- This points to a hybrid shader/script rendering architecture inside that product, not a simple native CPU glyph loop.

XAO relevance:
- Treat its shader logic as a source of algorithmic ideas only after tracing the relevant shader strings and parameter bindings.
- Do not transplant its browser/WebGL runtime into XAO. A native AE implementation must own its render resources and remain correct under AE's render lifecycle.

## 5. Cross-plugin conclusions and boundaries

- The supplied decompilations provide useful evidence about plugin command dispatch, parameter construction, glyph atlases, shader pipelines and preset metadata.
- Decompiled function names, inferred structure layouts and recovered strings are not equivalent to original source. Where the decompiler shows opaque helper names or uncertain types, conclusions remain provisional.
- No proprietary AEX code has been copied into XAO in this pass.
- No AE runtime behavior, compatibility, or performance claim is made.
- Do not copy any plugin's version/flag constants, PiPL values, parameter IDs, memory patterns or SDK assumptions into XAO without independent validation against the XAO SDK build and AE 2023.

## 6. Next trace targets

1. Trace S1 `GlyphAtlas::Build`, the atlas ramp/accessor, and the per-cell render loop to determine what is actually measured and selected.
2. Trace Crates' JSON-driven parameter schema and the rendering routine far enough to distinguish UI metadata from actual image operations.
3. Trace OVN's render and parameter-setup internals.
4. Extract only relevant L3tt3rM4pp3r shader strings and map each to its parameter inputs; classify GPU dependence and licensing separately.
5. Continue the font metadata/coverage/licensing audit and the remaining open-source source review.

