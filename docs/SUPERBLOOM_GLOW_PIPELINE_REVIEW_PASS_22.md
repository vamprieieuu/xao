# XAO Focused Audit — SuperBloom Glow Reference — Pass 22

Date: 2026-11-07

## Scope

Reviewed the supplied MIT-licensed SuperBloom project:
- complete `src/lib/bloom.js` rendering pipeline
- highlight-isolation pixel pass
- control schema and built-in presets
- Svelte app integration and preview/export flow
- Photoshop UXP host bridge and manifest
- Electron packaging and project build scripts at the architectural level

This project is a browser Canvas / SvelteKit / Photoshop UXP / Electron application. It is not an AE-native effect. Its algorithmic concepts are reference material; its DOM, Canvas, UXP, Photoshop and Electron runtime code are not XAO dependencies.

## 1. Actual Glow pipeline

1. **Highlight extraction:** copies the source image into a threshold canvas. For each RGB channel it linearly remaps `[threshold, 255]` to `[0, 255]`, clamping lower values to zero. The alpha channel is not changed by this remap.
2. **Optional colorization:** applies the selected tint using Canvas `color` and `multiply` composite operations with a configurable tint opacity.
3. **Layered blur:** iterates from layer 1 to `glowLayers - 1`. Each pass draws the threshold image into the glow canvas with a CSS filter consisting of brightness, hue rotation, saturation and Gaussian blur.
4. **Blur growth:** blur radius grows quadratically as `(i + 1)^2 * glowRadius * previewQuality`. This gives a broad multi-scale halo but makes the outer layers increasingly expensive.
5. **Anamorphic stretch:** the glow canvas is drawn again with horizontal width multiplied by `anamorph + 1`.
6. **Composite:** the original base image is drawn, then the glow canvas is added with Screen compositing.
7. **Preview modes:** the UI exposes Full, Glow Only and Mask, with preview quality from 0.1 to 1.0.

Controls include Threshold, Depth, Radius, Colorize, Tint Color/Opacity, Brightness, Saturation, Hue Shift, Anamorph, preview mode and preview quality. Presets include Default, Soft Haze, Jedi, Cinematic and Sunset.

## 2. Strengths and reusable concepts

- Explicit highlight isolation is a sound first stage for a threshold-driven Glow.
- A multi-scale blur stack produces a wider and more natural halo than a single blur.
- Separating mask, glow layer and final composite makes each stage independently inspectable.
- The anamorphic stretch is a simple and understandable optical-shape control.
- The preview has separate Full/Glow Only/Mask views, which is useful for diagnosing threshold and bloom behavior.
- Presets serialize only effect parameters rather than transient UI state.

## 3. Technical limitations and defects

1. **No explicit HDR pipeline:** the implementation uses browser Canvas 8-bit ImageData and CSS filters. Values above display white are clipped/not represented; this is not a scene-linear HDR bloom.
2. **Threshold is display-referred:** it compares 8-bit RGB channel values independently. It is not a linear-light luminance threshold, and bright saturated colors can be treated differently from a luminance-based extraction.
3. **Alpha semantics are incomplete:** the threshold remap leaves alpha untouched, but the source path and Photoshop host bridge flatten the document and encode the transfer image as JPEG. The Photoshop plugin therefore loses transparency before the web renderer receives the source.
4. **Canvas filter behavior is browser-defined:** CSS blur/filter output, edge treatment and compositing may vary by browser/runtime. XAO needs explicit kernels and defined boundary conditions.
5. **Blur cost grows quadratically:** the largest blur radii can be large, and each layer reprocesses the threshold image. Repeated full-resolution Canvas filters are not an appropriate CPU-first 4K strategy.
6. **Glow layers are cumulative Screen draws:** each blur pass is composited into the same glow canvas. This is a stylized layered bloom, not a normalized energy-conserving convolution pyramid.
7. **Potential anamorphic edge clipping:** the widened glow is drawn into a canvas that remains at the original width. The outer horizontal flare can be clipped at the left/right bounds unless the source is padded or the composite domain is expanded.
8. **No explicit alpha/premultiplication contract:** Canvas handles internal premultiplication, but the project does not expose a documented alpha policy for the effect. XAO must define whether Glow is generated from straight or premultiplied color and how transparent bright pixels contribute.
9. **Photoshop transfer is lossy:** the UXP host duplicates/flattens the document and sends the flattened pixels as a base64 JPEG to the webview. It is not a lossless source buffer, and the export creates a separate glow layer/Smart Object.
10. **Photoshop integration is not AE integration:** the UXP APIs, Smart Object conversion, hidden metadata text layer, modal dialog and layer editing workflow are product-specific and must not be brought into XAO.
11. **Preview and final are distinct quality paths:** preview quality scales the canvas and blur radius; it is not evidence of final-render performance or exact parity.
12. **No temporal behavior:** the effect is a still-image renderer. It does not establish deterministic animation, caching, frame-order independence or MFR safety.

## 4. XAO decisions

- Keep threshold extraction, independent mask inspection, multi-scale Glow, hue/saturation/brightness tinting, and anamorphic horizontal spread as design references.
- Build a CPU-first HDR-capable Glow core with a linear-light threshold/luminance policy, correct alpha handling, and explicit boundary padding.
- Prefer a bounded multi-resolution pyramid with controlled filter kernels over repeated full-resolution CSS blur passes.
- Define the energy/normalization behavior of each pyramid level so the glow does not unintentionally brighten with layer count.
- Keep source/mask/glow/composite intermediate domains explicit; expand output bounds for anamorphic spread and any other effect that extends beyond source bounds.
- Use AE time only if a later animated modulation is explicitly required; otherwise keep the Glow result stateless and deterministic.
- Do not import browser Canvas, Svelte, Photoshop UXP, Electron or the Photoshop Smart Object bridge into the native AE runtime.

## 5. Review status

This pass covers the supplied SuperBloom core renderer, highlight extraction, controls/presets and Photoshop host bridge. It is a source-level review, not a browser/Photoshop execution test, not a Windows AE build and not proof of visual parity with the user's references. Remaining Glow binaries/recovered references and the rest of the XAO archive still require audit.
