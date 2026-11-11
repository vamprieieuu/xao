# XAO Focused Audit — Filtr WebGL Retro Effects Engine — Pass 16

Date: 2026-11-07

## Scope

Reviewed the supplied MIT-licensed Filtr project at source level:
- renderer dispatch and ping-pong framebuffer pipeline
- CPU error-diffusion dither implementation and GPU ordered-dither shader
- ASCII, wave-lines, halftone, dots, pixel-sort, contour, edge, crosshatch, blockify, threshold, noise-field, matrix-rain, VHS and Voronoi shader families
- shared prep and post-processing shader passes
- glyph atlas and source/video/GIF timing implementation
- settings schema/defaults and SVG export path

The project is a WebGL2 browser application, not an AE plugin. The MIT license covers the project's code, but any bundled font/package dependencies retain their own licenses. No browser runtime, React/Zustand UI or WebGL object should be carried into XAO.

## 1. Pipeline and reusable concepts

- A clear `prep → effect → post → composite` pipeline uses ping-pong framebuffers and lazy shader compilation.
- Shared preprocessing handles brightness/contrast and ASCII-specific saturation, hue, gamma, blur, sharpness, edge enhancement and color quantization.
- Post stages are separately enabled: bloom, grain, chromatic aberration, scanlines, vignette, CRT curve and phosphor tint.
- Effects are independently dispatched from a typed settings schema. This is useful as a feature inventory, but XAO's user requirement remains one unified shared control surface with independent engines, not a direct copy of Filtr's separate effect panels.
- The project uses a bounded processing resolution (maximum preview dimension) before running effects. This is a useful quality/performance concept, but AE final render must not silently reduce output resolution; preview and final-render quality policies must be distinct.
- ASCII uses a glyph atlas and cell-based source sampling.
- Halftone rotates the sampling grid and supports circle, square, diamond and line stamps. These line stamps are shapes within the halftone engine and are unrelated to the explicitly excluded standalone Dither Majid Lines effect.
- CPU error diffusion is separated from GPU ordered dithering because diffusion is sequential.

## 2. Dither — exact behavior and critical issues

### Algorithms present
CPU error diffusion kernels:
- Floyd–Steinberg
- Atkinson
- Jarvis–Judice–Ninke
- Stucki
- Burkes
- Sierra
- Sierra Two-Row
- Sierra Lite

GPU ordered methods:
- Bayer 2×2, 4×4, 8×8 and 16×16
- Clustered dot
- Blue noise
- Interleaved gradient noise

### Important limitations
1. **Source alpha is forced to 255 in every CPU dither output mode.** Transparent input becomes opaque. XAO must preserve alpha and composite only according to an explicit background/ink policy.
2. **CPU error diffusion is only used for still images.** For video, GIF and webcam, error-diffusion methods are replaced with an ordered GPU fallback (Bayer 8×8 according to the fallback index). The selected method is therefore not actually honored for time-based footage. XAO must not advertise one algorithm while silently rendering another.
3. **GPU readback stalls the pipeline.** CPU diffusion reads the prepared GPU framebuffer with `readPixels`, processes the full frame on CPU, then uploads the result back to a GPU texture. This synchronization/readback/upload path is expensive and should not be XAO's default video or high-resolution route.
4. **Intensity is not applied by the CPU diffusion routine.** The routine accepts the full dither parameter object but the CPU algorithm uses levels, gamma, palette and colors; the intensity control is not used in the CPU kernel path.
5. **Edge diffusion drops out-of-bounds error.** At image edges, weights sent outside the frame are discarded rather than renormalized. This may be intentional but changes total error conservation at borders; XAO should define and test its edge policy.
6. **Channel handling:** RGB/original modes diffuse each channel independently, which can create hue shifts and color fringing. This is a distinct mode from luminance diffusion and should be named/controlled accordingly.
7. **Luminance is computed directly from normalized channel values.** The path uses Rec.709 coefficients and gamma, but does not document a full linear-light/transfer-function contract. XAO must define the working space.

## 3. Other effect-family findings

- **Halftone:** uses a rotated periodic screen and a tone-dependent stamp size, with Circle/Square/Diamond/Line shape modes. This is a basic AM-style screen reference; it is not the advanced per-ink multi-angle separation seen in the supplied Halftone Studio references.
- **Dots:** offers square/hex grid placement and Circle/Square/Diamond stamps; useful as a distinct grid-mosaic mode.
- **Pixel Sort:** shader samples along a selected direction and scans a bounded streak to find threshold-qualified pixels. This is a GPU bounded-scan effect, not a full CPU sorting implementation.
- **Contour / Edge / Crosshatch:** use luminance bands, neighborhood gradients and repeated angled line families. These can inform optional detail/edge stages but should not be conflated with the excluded Dither Majid Lines product effect.
- **Blockify:** samples a block and can render full, shaded or outline treatment.
- **Noise Field:** includes Perlin/Simplex/Worley selection and time-driven distortion. Its browser time uniform is interactive-demo time; XAO must use AE time and deterministic frame evaluation.
- **Matrix Rain:** depends on time, glyph atlas and directional trail state. A native port must make every cell position/character a deterministic function of absolute AE time and seed, not mutable wall-clock state.
- **VHS:** performs RGB channel offsets, color bleed, noise, scanline and tracking-like distortions. Useful as a collection of image-space primitives, not a full analog tape simulation.
- **Voronoi:** uses a procedural cell search and supports cell color/gradient and edge treatment. Validate search cost and deterministic seed if independently implemented.
- **Post stack:** bloom, grain, chromatic aberration, scanlines, vignette, CRT curve and phosphor are separate passes. XAO can share these primitives across engines, but should avoid repeated full-resolution passes where a merged or downsampled path is possible.

## 4. Timing, input and export constraints

- Video/webcam updates are driven by HTML media readiness and browser animation frames; GIF timing is driven by `performance.now()` and accumulated delays.
- This is suitable for an interactive preview, not for After Effects rendering at arbitrary frame times or out-of-order frame requests.
- GIF decoding composites frames and disposal methods into full snapshots, which is useful behavior for a future asset importer but is not part of the native effect render path.
- SVG export is implemented only for ASCII and Halftone, and it uses its own simplified sampling/geometry path. It should not be treated as pixel-identical to the WebGL output.
- The SVG exporter sanitizes configured colors and escapes text content before embedding it, a useful security practice if XAO ever exports structured formats.

## 5. XAO decisions

- Rebuild the useful algorithms independently in a host-independent C++ core, with the AE adapter isolated from engine math.
- Keep ordered dithering and error diffusion as genuinely separate algorithm families; implement CPU-safe tiled/scanline processing and optional GPU acceleration only if the exact result can be preserved.
- Do not substitute one selected algorithm with another for video. If an algorithm is unsupported in a render mode, report/disable it explicitly rather than silently changing output.
- Preserve alpha and premultiplication, and define color-space semantics before implementing palette quantization and channel diffusion.
- Derive all animated behavior from absolute AE time, frame rate/timebase and stable seed. No `performance.now()`, browser animation frame or mutable playback history.
- Use multi-scale/downsampled intermediates for costly post effects; retain full-resolution output for final render.
- Treat the Filtr effect list as algorithm references only. The final XAO control design must be derived from the user's supplied visual references and shared-control requirement.

## 6. Review status

This is a source-level review of the listed Filtr engine, shader, source, settings and export paths. It is not a Windows build, AE SDK integration, runtime test, or line-by-line review of every UI/script/config file in the Filtr project. The broader XAO audit remains in progress.
