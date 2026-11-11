# XAO Deep Source Review — Glow / Morphing ASCII / Temporal State (Pass 24)

Date: 2026-11-07

Scope: targeted source-level review of the supplied XAO archive. This is not a full archive audit, not an XAO build, and not an After Effects runtime test.

## 1. HaloGlow native AE reference

Source reviewed:
- `glow/haloglow [open source]/CMakeLists.txt`
- `Source/HaloGlow.cpp`, `HaloGlow_CPU.cpp`
- `Source/HG_Core.cpp/.h`, `HG_Parallel.h`
- `Source/HG_ColourCache.cpp/.h`
- `Source/HG_GpuRender.cpp`, `HG_GPU.cpp` and tests
- `Source/HG_UpdateNotice.cpp`, `HG_UpdateCheck.cpp`
- MIT license

### Strong architecture worth learning from
- Clear host-independent FP32 core separated from the AE adapter.
- Smart Pre-Render captures an immutable parameter/settings snapshot; Smart Render consumes it rather than checking out parameters again.
- Explicit layer-space rectangles, render scale and pixel aspect handling, plus separate required-input and maximum-result rectangle calculations.
- 8/16/32-bit AE pixel adapters convert to a common FP32 core. Float storage preserves values above 1 (HDR); integer paths clamp to their legal channel range.
- The core uses premultiplied RGBA and has an explicit source-opacity bypass path.
- GPU is optional; CMake supports a force-CPU-only build. CUDA/OpenCL/Metal are discovered conditionally.
- Host-independent unit tests and GPU-vs-CPU parity tests exist. This is a much better reference architecture than copying a monolithic AE render callback.

### Risks / changes required before XAO adoption
1. `HG_Parallel.h` creates a fresh set of `std::thread` workers on every parallel row pass. The core invokes this helper repeatedly, and AE MFR can render several frames concurrently. This can multiply worker counts by hardware concurrency per frame, causing oversubscription and thread-creation overhead on modest CPUs. XAO should use a bounded shared worker pool or AE-supported concurrency strategy, with a global CPU budget and serial fallback for small workloads.
2. The CPU adapter's `ReadWorld` and `WriteWorld` loops are serial even though the computational core is parallel. Conversion can become a measurable bottleneck at large frame sizes.
3. The colour-space cache is process-wide and atomically publishes immutable snapshots. That avoids torn reads, but it is still shared across effect instances; XAO should explicitly define whether working-space state is per-project, per-instance, or process-wide.
4. Update checking is a process-global background thread started at global setup and joined at global setdown. It is unrelated to rendering and should not be included in XAO's render core or be allowed to block effect teardown on an unbounded network request.
5. The CMake project expects a correctly located/provided Adobe SDK tree. Its optional GPU discovery is not proof that a backend is available on the target machine. XAO's baseline CI should explicitly build CPU-only without CUDA/OpenCL/Metal.
6. Its own tests are useful reference material, but passing host-independent tests does not prove AE installation, PiPL correctness, SmartFX bounds, MFR behavior, or real host rendering.

Decision: use the separation pattern (immutable pre-render snapshot -> host-independent FP32 core -> thin AE adapters), not a wholesale code transplant. HaloGlow is MIT-licensed, but retain its copyright/license notice if any substantial code is reused. Prefer independent XAO implementation unless reuse materially saves time and passes review.

## 2. Morphing ASCII shader reference

Source reviewed:
- `ascii [ main ]/morphing ascii shader [open source]/src/AsciiEffect.js`
- `src/InkBleed.js`
- `src/MemoryGrid.js`
- `docs/PARAMETERS.md`

### Useful rendering concepts
- Glyphs are stored in an atlas; each cell samples a representative image colour/luminance and renders one selected glyph.
- Optional Sobel edge detection samples the eight neighboring cell centres and substitutes directional glyphs.
- A deterministic cell-index hash varies glyph selection without frame-to-frame random flicker.
- The SDF atlas is generated using a separable Euclidean distance transform. Interpolating two signed distance fields and thresholding the result creates shape morphs rather than merely cross-fading two glyph alpha masks.
- Glyph scale, white cutoff, invert, brightness/contrast/gamma, edge threshold, per-cell variety, colour modes and noise blend modes provide a useful control vocabulary.
- Ink bleed is a separate post-process. Its 64-point Vogel-disk sampling spreads dark/coloured ink while retaining the original alpha.
- Resource disposal is explicit for glyph textures, render targets, geometry and shader materials.

### Important limitations and XAO decisions
1. The atlas builder indexes `charset[i]` in JavaScript. JavaScript string indexing returns UTF-16 code units, not Unicode grapheme clusters or shaped glyph runs. Supplementary-plane characters can be split into surrogate halves; combining sequences and joined scripts are not handled as typographic units.
2. Glyphs are rasterized by browser Canvas using a hard-coded generic font stack. This does not reproduce the supplied font files or guarantee consistent glyph coverage/metrics across systems.
3. Arabic and other complex scripts require shaping and positioned glyph output before rasterization. XAO's Typeset/text path must use a real shaping stack (HarfBuzz plus a rasterizer such as FreeType, with bidi/script segmentation) rather than drawing each Unicode code point independently. HarfBuzz documents Arabic shaping, glyph substitutions/positions and font integration: https://harfbuzz.github.io/what-does-harfbuzz-do.html and https://harfbuzz.github.io/getting-started.html.
4. The ASCII shader samples one centre point per cell; this is fast but can miss fine details and alias. XAO should offer a selectable sampling strategy (centre, multi-sample/area average, and optionally edge-aware) rather than assume centre sampling is always best.
5. The SDF atlas is binary-thresholded at alpha 127 and uses a finite spread. Thin details and small glyphs can disappear or morph unevenly. Test glyph-specific padding, spread, baseline/metrics, and per-glyph normalization.
6. The atlas width grows as glyphSize × charset length. There is no visible texture-size policy in this implementation. XAO should use atlas pages/texture arrays or glyph caching with explicit device limits.
7. InkBleed performs 64 texture fetches per output pixel. A direct CPU port would be prohibitively expensive at full resolution. XAO should implement a bounded multi-scale/separable approximation or a carefully optimized radius-dependent kernel, with a quality/performance switch.
8. InkBleed's luminance weights are Rec.601-style constants and its shader is designed for a browser postprocessing pipeline. XAO must use the selected working-space/linear-light policy and alpha-aware premultiplied compositing.
9. The browser implementation's texture and render-target lifecycle is not an AE memory model. Port concepts, not WebGL objects or assumptions.

## 3. Temporal MemoryGrid — critical incompatibility with deterministic AE rendering

MemoryGrid is a ping-pong render-target simulation. Each update reads the prior frame's state, applies an exponential step based on `dt`, and writes a new state. It clamps `dt` to 0.1 seconds.

This is inherently history-dependent: the output at time T depends on which frames were rendered before T and the exact sequence of `dt` values. That is unsafe as-is for After Effects random-access rendering, scrubbing, reverse playback, render farms and Multi-Frame Rendering. Two workers asked to render the same frame could produce different results if their histories differ.

Decision:
- Do not port MemoryGrid as a mutable per-frame simulation into the AE render path.
- Any XAO temporal ASCII morph/trail feature must be deterministic from absolute AE time and stable parameters, or use a deliberate checkpoint/pre-roll cache with keys that include all relevant parameters, source identity, frame time and algorithm version.
- Validate identical-frame output when rendering frames out of order and in parallel before enabling MFR for any temporal feature.

## 4. Dither Majid Lines exclusion

The separate standalone **Lines** effect from Dither Majid remains excluded from XAO. Do not import its implementation, UI, controls, presets, or engine. This exclusion does not prohibit a line-shaped mark as one geometry option inside the Halftone engine, nor does it prohibit the user's independently supplied Threshold ASCII visual reference.

## 5. Status and next audit work

This pass is a focused review of selected source files, not proof that all 805 archive files have been inspected line by line. No XAO binary was built or tested in After Effects during this pass.

Next source targets remain the unfinished Rays/Glint and decompiled plug-in control maps, remaining ASCII shader math and source projects, and complete visual review of the supplied reference clips (especially PixelDitherGo and Array/Plugin settings).
