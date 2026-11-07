# XAO Focused Audit — Halftone Lap Browser Print Simulator — Pass 21

Date: 2026-11-07

## Scope

Reviewed the supplied MIT-licensed Halftone Lap project:
- full inline JavaScript engine in `index.html`
- source preparation and canvas sampling
- RGB→CMYK conversion, channel profiles, print curves and ink color construction
- mono dots, line screen, bitmap, CMYK/spot plates, duotone and tritone
- rough dot/rectangle geometry, ink spread, paper texture and print impression
- controls, presets, comparison view, responsive canvas and PNG export
- project README, CSS and license

This is a browser Canvas simulator, not a native AE plugin. The line-screen mode is one visual mode inside this halftone simulator; it is not the separate Dither Majid Lines effect explicitly excluded from XAO.

## 1. Main rendering families

- **Mono dots:** rotates a regular screen grid around the canvas center, samples local brightness at each dot center, and maps darkness to dot radius.
- **Line screen:** uses the same rotated grid but maps darkness to line length and width, with small seeded position/angle irregularities.
- **Bitmap:** creates fixed-size rotated square marks only where brightness is below a threshold.
- **CMYK dots:** independently renders C/M/Y/K screens at standard nominal angles, with optional per-plate visibility, screen misregistration and an extra spot-color screen selected by perceptual color similarity.
- **Duotone/tritone:** separates the source into brightness ranges and renders independently angled color layers.
- **Print texture:** roughens dot contours with deterministic radial perturbations, adds ink spread as small satellite marks, adds edge darkening, overlays paper grain and simulates a subtle two-pass print impression.
- **Paper/fit controls:** source scaling, offset, paper stock, fit mode and output dimensions are managed separately from the print renderer.

## 2. CMYK and print model

- RGB is converted to approximate CMYK using a simple black-generation/UCR-style model and a configurable maximum total ink amount.
- Each channel has a profile for dot gain, opacity, shape slur, wobble and edge darkening.
- A channel-specific print curve maps the plate amount through a curve/floor operation.
- The dot outline is a polygon with a bounded 12–24 point count; the radius is adjusted by dot gain and screen angle.
- Ink spread is represented by a small number of deterministic satellite circles around the main mark.
- Misregistration shifts the plate sampling and mark positions by a channel-specific offset vector.
- CMYK and spot layers use Canvas Multiply compositing.

This is a stylized print simulator, not ICC-managed or press-calibrated color separation.

## 3. Important limitations and defects

1. **Canvas output is effectively opaque:** the source is drawn to an RGB-like canvas workflow over a paper/background surface, and PNG export captures the composite. It is not a transparent-output model suitable for direct reuse in XAO.
2. **Browser Canvas is the raster backend:** output depends on browser Canvas antialiasing, compositing and pixel-ratio behavior. XAO needs controlled native rasterization and testable coverage rules.
3. **RGB→CMYK is approximate:** a simple formula and total-ink cap cannot substitute for ICC profiles, device-specific black generation, ink limits or press calibration.
4. **Spot color selection is a heuristic:** it combines RGB distance, hue, saturation and lightness similarity. It is not a robust color segmentation or perceptual color-difference model.
5. **The source image preparation is display-referred:** brightness sampling uses the canvas pixel values, without an explicit linear-light/working-space contract.
6. **Print geometry uses many draw calls:** every cell is rendered as a Canvas path, and roughness/ink spread can add multiple per-dot paths. This can become expensive at large output sizes or small screen spacing.
7. **Deterministic hash is based on floating-point sine:** the same seed/coordinates are repeatable in a given browser, but cross-platform bit-identical output is not guaranteed. XAO should use a specified integer hash/PRNG if exact repeatability is required.
8. **Misregistration is a stylized offset:** it shifts each channel along fixed vectors rather than modeling a measured press registration transform.
9. **The paper impression and grain are procedural overlays:** useful visual texture, but not a physical paper-fiber or ink-absorption simulation.
10. **No animation/time model:** the project is static image processing. It provides no evidence for AE temporal evaluation, caching, MFR or deterministic animated output.
11. **Potential performance scaling:** the rotated grid loops cover an image-sized diagonal square and skip cells outside the canvas. The number of tested grid positions grows with the square of the image diagonal divided by spacing; an optimized grid-bound computation would reduce unnecessary iterations.

## 4. XAO decisions

- Keep the rotated screen, per-plate angle/visibility, CMYK plus spot ink, dot gain, ink spread, misregistration, roughness and paper texture as visual reference concepts.
- Treat Mono Dots, Line Screen, Bitmap, CMYK, Duotone and Tritone as modes/algorithms only where the user's own references require them; do not let a reference tool dictate XAO's product architecture.
- Reimplement screen geometry in native C++ with bounded iteration over visible cells, deterministic integer randomness, explicit anti-aliasing and render-scale handling.
- Keep print separation color management separate from stylized creative CMYK-like modes. Do not claim print-ready calibration without ICC/device profiles and validation.
- Preserve alpha and offer explicit paper/background compositing behavior.
- Keep the separate Dither Majid Lines effect excluded. The line-screen style here is a Halftone rendering mode, not that standalone effect.
- Do not include browser Canvas, DOM, CSS, file input, or browser export APIs in the native AE runtime.

## 5. Review status

This pass covers the supplied browser engine's full main rendering and control logic in `index.html`, plus its supplied license/README/CSS. It is a source review, not a runtime parity test in a browser and not an AE build. The broader XAO archive audit remains in progress.
