# XAO Focused Audit — Morphing ASCII Shader — Pass 9

Date: 2026-11-07

## Scope and evidence

Direct source inspection of the supplied `morphing ascii shader [open source]` project:
- `src/AsciiEffect.js` (glyph atlas generation, EDT/SDF construction, fragment shader, uniforms and lifecycle)
- `src/InkBleed.js` (64-tap Vogel-disk blur/ink diffusion, kernel baking and render-target setup)
- `src/MemoryGrid.js` (per-cell temporal state, ping-pong render targets, time update and resize/disposal)
- `docs/PARAMETERS.md`, `README.md`, `package.json`, and `LICENSE`

The supplied project declares MIT licensing. This is a source-study reference; its Three.js/postprocessing/WebGL implementation is not an AE-native implementation and is not directly portable as-is.

## 1. Algorithms worth reproducing independently

### ASCII density renderer
- Divides the output into a regular square grid and samples one representative color at each cell center.
- Applies gamma, contrast and brightness to luminance, then maps the result onto an ordered glyph ramp.
- Uses a deterministic per-cell hash for glyph variety, avoiding temporal flicker when the cell index and parameters remain fixed.
- Has four output color modes: custom ink/background, dark glyph over sampled cell color, sampled-color glyphs on white, and sampled-color glyphs on a configurable background.
- Uses a white cutoff independently of the adjusted luminance mapping.
- Has a Sobel edge mode that substitutes directional glyphs based on the gradient orientation.
- Builds a glyph alpha atlas and a separate SDF atlas. The SDF uses a separable Felzenszwalb–Huttenlocher Euclidean distance transform; the signed field is interpolated between adjacent glyphs to morph glyph shape rather than merely cross-fading two alpha masks.
- The atlas is generated at runtime using browser Canvas and system font fallback. This is useful as a concept only: XAO must use its own controlled font loading, glyph metrics, Unicode handling and reproducible rasterization.

### Ink bleed
- A separate post-process samples 64 points in a Vogel/golden-angle disk.
- A pre-baked GPU kernel stores the direction, radial position and weight to avoid per-pixel trigonometric/exponential calculations.
- It computes a weighted ink-presence estimate and an optional weighted blur; alpha is copied from the input in this pass.
- This is visually useful but is expensive at full frame resolution: 64 texture reads per output pixel. It must not be copied as the default CPU path. XAO should evaluate reduced-resolution pyramids, separable/convolution approximations, bounded-radius kernels, and quality tiers.

### Per-cell temporal memory
- Maintains one state texel per grid cell in two ping-pong render targets.
- Moves each cell's stored RGB toward the current video sample with exponential smoothing; alpha encodes a per-cell activity measure that drives cross-fade/morph behavior.
- Uses a clamped real-time frame delta and reinitializes state on resize/reset.
- This is a useful animation concept, but the stateful WebGL implementation is unsuitable for deterministic AE rendering without redesign.

## 2. Important defects and incompatibilities to avoid

1. **Output alpha is discarded by the main ASCII shader.** All four color modes write alpha as `1.0`; transparent source pixels therefore become opaque. XAO must define explicit alpha semantics and preserve/compose premultiplied alpha correctly.
2. **Memory mode and edge detection sample different temporal sources.** The cell's main color is read from the memory texture when memory is enabled, but `tunedLuma()` for the Sobel neighborhood always reads the live `inputBuffer`. Edges can therefore describe the current frame while glyph density/color describe a delayed state. XAO should derive both from the same selected source.
3. **Memory animation depends on render-call history and wall-clock delta.** The ping-pong state changes on each call and uses `dt`; seeking, rendering frames out of order, AE caching, multi-frame rendering and repeated-frame requests can produce different results. XAO must derive temporal animation from AE time/sample time and deterministic state, or use a stateless closed-form function of time.
4. **Shared mutable ping-pong state is not MFR-safe.** The renderer, render targets, current/previous pointers and update sequence are mutable shared state. A direct port would race under concurrent frame rendering. Per-frame state must be isolated or computed deterministically without cross-frame mutation.
5. **Unicode handling is based on JavaScript UTF-16 code units.** `charset.length` and `charset[i]` split supplementary-plane characters into surrogate halves and do not represent grapheme clusters. Combining marks and joined scripts are not handled as a typographic run. XAO must use Unicode scalar/grapheme-aware input plus shaping and BiDi before glyph atlas construction.
6. **Font selection is uncontrolled.** The browser Canvas uses a hard-coded system fallback stack, not the supplied XAO font collection. The same character can rasterize differently on another machine or if a fallback font is missing. XAO must load exact permitted fonts and use stable glyph metrics/rasterization.
7. **Cell-center sampling can leave the image bounds on partial edge cells.** The live path computes the cell center from the full cell size without clamping to the valid image domain. Non-multiple frame dimensions can sample outside the image at right/bottom edges. XAO must clamp or use a documented edge-extension policy.
8. **The 64-tap InkBleed path scales poorly.** Even after kernel precomputation, it performs up to 64 source samples per pixel. This is not an acceptable assumption for a CPU-first effect at 1080p/4K.
9. **Render-target state restoration is not exception-safe.** MemoryGrid restores the prior render target only along the normal path; an error during the reset/update pass can leave the host renderer bound to an unintended target. AE implementation must use scoped state management and restore all modified host state.
10. **SDF construction is a one-time but substantial CPU operation.** It rasterizes every glyph and performs two 2D distance transforms per glyph. XAO should cache by font/glyph/size/spread and avoid doing atlas generation in the render callback.

## 3. XAO implementation decisions

- Rebuild the density ramp, deterministic cell variation, Sobel directional glyphs, SDF glyph morph and ink diffusion as independent native C++ components.
- Keep glyph rasterization/shaping separate from the pixel renderer. Use a licensed font backend and proper shaping/BiDi; never treat UTF-16 code units or isolated Arabic characters as final shaped glyphs.
- Preserve source alpha and establish one documented premultiplication convention across every engine.
- For animation, use AE time and deterministic per-cell seeds. No dependence on the order in which frames are requested.
- Keep memory/state local to a render request or compute its value from absolute time. Design and test for Multi-Frame Rendering before enabling it.
- Optimize ink diffusion for CPU first; use downsampled buffers and bounded kernels, with optional GPU acceleration only as an additional path.
- Clamp all source sampling to valid bounds and test odd frame dimensions, non-square pixels, proxy/render scale and all supported bit depths.

## 4. Review status

This is a focused source-level review of the Morphing ASCII project files listed above, not a review of every file in the full XAO archive and not an AE runtime test. Remaining XAO audit areas include other ASCII projects/shaders, HaloGlow dependency/build and threading audit, Rays/Glint reverse-engineered references, remaining external projects and visual-reference matching.
