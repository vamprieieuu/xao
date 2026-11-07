# XAO Focused Audit — Deep Glow, Deep Glow 2 and Starglow Binary/Shader References — Pass 23

Date: 2026-11-07

## Scope and evidence

Inspected the supplied Deep Glow, Deep Glow 2, Starglow and Sapphire S_Glint binaries and corresponding decompiler listings. Extracted embedded printable/UTF-16 strings and embedded GLSL shader source where available.

These are compiled third-party products. The extracted shader text and decompiler output are forensic evidence for behavior analysis only, not an open-source license or permission to copy vendor implementation. No XAO dependency may be placed on these products or their runtime DLLs.

## 1. Deep Glow (legacy) — embedded shader evidence

The binary embeds OpenGL shader source for preprocessing and separable horizontal/vertical blur:
- Thresholding is per RGB channel with a threshold and a smoothness factor.
- The blur shaders expose independent X/Y stride and a blur ratio that can change directional blur behavior.
- The shader uses exposure and supports Screen-style and Add-style paths.
- The extracted blur shader explicitly writes alpha to 1.0 / discards alpha because the blur pipeline does not preserve it. This is a major warning: XAO must preserve or explicitly reconstruct alpha rather than copying this approach.
- The extracted code references a CPU input view and OpenGL shader paths, but does not establish a modern CPU-first implementation.

The binary exposes controls including Radius, Exposure, Threshold, Threshold Smooth, Blend Mode, Chromatic Aberration, Quality, Glow Iterations, Glow Input/Final Render and Source Opacity.

## 2. Deep Glow 2 — recovered GLSL and control map

The binary embeds a more extensive GLSL pipeline:
- `preProcess`
- `downsample`
- `upsample`
- `blurUnified`
- `postProcess`
- `identity`

### Preprocess shader
- Swizzles channel order to match the upload path.
- Supports per-channel pixel aberration modes (R/G, R/B, G/B) by sampling offset UV positions and replacing selected channels.
- Supports a smooth threshold with two modes:
  - Luma: Rec.709 luminance and smoothstep mask, preserving original RGB relationships by multiplying the color by the mask.
  - Chroma: per-channel smoothstep threshold, optionally biased by a saturation estimate.
- Supports exposure, gamma handling and Screen/Add blend preparation.
- Screen mode clamps the preprocessed RGB to 1.0 and applies exposure later; Add mode scales RGB by exposure.
- The shader includes an HDR-aware saturation helper that normalizes values above 1.0 before computing saturation, but the complete pipeline still needs its own HDR behavior validation.

### Blur shader
- Uses a normalized weighted Gaussian-like kernel: `exp(-0.5 * (x*x) / 0.06)`.
- Performs a separable directional pass with configurable step count and texture stride.
- Supports different horizontal/vertical blur behavior and optional per-channel multipliers for glow aberration.
- A fade multiplier can attenuate selected blur-width iterations.
- The shader samples both directions around each pixel and normalizes by the accumulated weights.

### Downsample / upsample
- Downsample shader uses a 13-sample weighted distribution over a 3x3 neighborhood plus four diagonal half-step samples. Its comments explicitly derive weights to preserve total sample energy.
- Upsample shader uses a normalized 3x3 tent filter with weights 1/2/4 and total normalization 1/16.
- The code includes several tone-mapping functions (ACES filmic, Filmic, Reinhard 2, Uncharted 2, Lottes and Uchimura) and blend helpers (Overlay, Soft Light).
- This is strong evidence for a multi-resolution HDR-aware glow architecture, but not proof of identical output on every bit depth or host.

### External dependency and integration limits
- The binary explicitly requires `IrisBlurSDK.dll` adjacent to `DeepGlow2.aex` and reports an error if it is missing.
- It also has an Iris/Lens mode with an Iris layer, Iris Sampling Quality, Iris Iterations, Iris blur cache, lens dirt texture/matte, source opacity, quality presets and multiple diagnostic views.
- The plugin is an OpenGL implementation with an external blur SDK dependency. It is not a self-contained CPU-first implementation and must not be treated as one.

### Recovered controls
- Glow Mode: Exponential / Lens Iris
- Blend Mode, Radius, Exposure
- Threshold Mode, Threshold, Threshold Smooth, Saturation Bias
- Iris Layer, Iris Sampling Quality, Iris Iterations, Reset Iris
- Chromatic Aberration, Pixel Aberration enable, Aberration Channels, Glow Aberration enable
- Tint Blend Mode, Color, Color Outer, Swap Colors
- Lens Dirt Texture, Inherit Glow Color, Matte Exposure
- Quality, Quality Preset, Quality Preset Iris, Glow Iterations
- Source Opacity, Blur W/Blur H/None, Simplified Exposure, Iris Cull Small Values, Render Quality (Quantization)
- Diagnostic views for Final Result, Glow Input, Iris, Lens Dirt Input/Matte/Matted

## 3. Starglow — recovered behavior and controls

The supplied Starglow binary strings identify it as a Trapcode effect and describe it as generating directional glows based on image lightness.

Recovered parameter labels include:
- PreProcess: Threshold, Threshold Soft, Mask Radius
- Streak Length
- Individual Colors
- Color Map: ColorMap Options, Preset, Highlights, MidHigh, Midtones, MidLow, Shadows
- Source Opacity, Starglow Opacity
- Motion Blur, Colorize, Blend Mode

The binary contains extensive OpenGL/WGL and vendor framework strings, licensing/trial/session infrastructure and compiled runtime code. No reliable self-contained ray/streak algorithm was reconstructed in this pass. Treat the control map as behavior reference only; do not infer exact ray math from the labels.

## 4. Sapphire S_Glint

The recovered S_Glint listing confirms a loader/bridge that looks for `sapphire_ae.dll`, resolves Sapphire exports such as `sapphire_main`, `sapphire_gpu` and `sapphire_find_pinfo_for_effect`, then requests the `S_Glint` effect descriptor.

The actual Glint algorithm is not present as a self-contained implementation in the supplied recovered wrapper. XAO must not require or call Sapphire runtime DLLs.

## 5. XAO decisions

- Build Glow around explicit highlight/luma/chroma threshold extraction, soft threshold, multi-scale pyramid, normalized separable filters, exposure and well-defined blend behavior.
- Keep alpha as a first-class signal through all preprocessing, downsample, blur, upsample and composite passes.
- Use HDR-capable FP32 intermediates with a documented scene-linear or display-referred policy and explicit tone mapping only at the appropriate output stage.
- Add per-channel aberration only as a clearly defined option, with independent channel offsets and proper render bounds.
- Treat Lens Iris and lens dirt as separate advanced capabilities; do not promise them until there is a self-contained algorithm and matching visual reference.
- Treat Starglow's directional lightness-based streaks and tonal color map as visual requirements to compare against the user's own references; independently design the engine.
- Do not copy proprietary decompiler output, require IrisBlurSDK.dll, load Sapphire, or depend on any external commercial plugin runtime.
- The older Deep Glow alpha-discard behavior is explicitly rejected for XAO.

## 6. Review status

This pass records verified embedded shader/control strings and loader evidence from the supplied binaries. It is not a complete reverse engineering of the proprietary products, not a source license clearance, not a Windows build, and not an AE runtime test.
