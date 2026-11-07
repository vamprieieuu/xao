# XAO Combined Engine Audit — Pass 33
Date: 2026-11-07
Scope: HaloGlow native AE project, Rays/S_Rays decompiler exports, Halftone PS engine internals, Filtr renderer/dither implementation.
Status: source-level audit only; no XAO integration or AE runtime test is claimed.

## 1. HaloGlow — strongest native Glow reference, with important caveats

### What is genuinely useful
- The project is MIT-licensed and separates an AE adapter from a host-independent C++17 core.
- Its AE path uses SmartFX pre-render to capture parameters into immutable per-render data; SmartRender consumes that snapshot rather than checking AE parameter state during pixel processing.
- The CPU adapter explicitly supports ARGB32, ARGB64 and ARGB128, uses rowbytes and world origins when addressing pixels, and retains floating-point HDR values above 1.0 in the FP32 path.
- Core design is a multi-scale glow pyramid with explicit required-input/output rectangle planning, a CPU reference path, and optional CUDA/OpenCL/Metal implementations.
- CMake exposes a real CPU-only configuration (HG_FORCE_CPU_ONLY=ON); GPU SDK/toolkits are optional. This is a useful deployment model for modest/older Intel systems.
- Tests include core behavior and GPU-vs-CPU parity. The README reports release-path tests, but those are upstream claims and do not constitute an XAO build or an After Effects 2023 runtime test.

### Integration risks / changes required before reuse
1. **Nested parallelism / oversubscription:** HG_Core invokes ParallelRows repeatedly across many pyramid stages. ParallelRows creates its own std::threads based on hardware_concurrency for each call. AE MFR can run several frame renders concurrently, so each frame can itself create a hardware-sized worker group. XAO must use one bounded shared worker budget or AE-aware task scheduling; never create a fresh hardware-sized pool inside every render stage.
2. **Thread creation failure can terminate the host:** ParallelRows stores joinable std::thread objects in a vector. If a later std::thread construction throws after earlier workers were created, stack unwinding destroys joinable threads and can call std::terminate. Replace with an RAII join guard / fixed pool / task system that safely joins already-started workers on every failure path.
3. **No explicit render cancellation:** long CPU pyramid work does not visibly poll PF_ABORT or an equivalent cancellation token. XAO needs cancellation checks at safe stage/row boundaries, particularly on large frames and interactive scrubbing.
4. **Update-check side effect:** GlobalSetup starts a background release-check thread; GlobalSetdown joins it. XAO should not make outbound network requests from a rendering plugin by default. Keep updates opt-in and separate from rendering, with no network activity unless user explicitly enables it.
5. **Memory pressure:** the FP32 RGBA conversion plus pyramid/intermediate images creates substantial transient memory. Upstream README also lists per-render GPU allocations and the lack of pooled allocation as remaining limitations. XAO should estimate peak bytes before allocation, reuse bounded scratch buffers, and degrade quality predictably rather than exhausting memory.
6. **Host version target:** source has UTF-8 parameter-name flag support guarded for newer AE, and the current project version/SDK assumptions need to be reconciled with XAO's AE 2023 target. Do not copy current upstream PiPL flags/version constants blindly.
7. **Bounds/SmartFX contract:** pre-render computes required input and max/result rectangles. Preserve the invariant that max_result_rect is independent of the current requested tile and result_rect stays within the request unless the correct extra-pixels flag is used. Test negative origins, non-square downsample, pixel aspect, cropped requests, adjustment layers and zero-alpha edge cases.

### XAO decision
Use HaloGlow as the leading *architectural and algorithmic reference* for a native Glow engine, not as a drop-in folder copy. Port only after a dependency/license review and after replacing nested thread creation, adding cancellation and bounded memory. Keep the CPU renderer first-class; optional acceleration must produce parity with the CPU reference.

## 2. Rays / S_Rays — archive does not contain recoverable effect algorithms
- The supplied Rays.aex.c and S_Rays.aex.c are tiny decompiler entry stubs that include generated headers; the accompanying headers are largely low-level type/decompiler declarations, not meaningful source-level parameter maps or shader implementations.
- S_Rays strings show a loader/bridge pattern, including failure-to-load-DLL messaging and a fallback/interpreter definition. This indicates a bridge/wrapper, not the underlying ray renderer.
- No trustworthy ray geometry, parameter defaults, sampling method, compositing formula, or temporal behavior can be reconstructed from these files alone.
- Do not infer an implementation from the effect name, and do not introduce a dependency on the external vendor DLL.
- Next evidence needed for a proper reverse-engineering pass would be the actual binary's embedded resources/shaders, an authentic UI screenshot/control export, or user-supplied before/after frames with settings. Until then, implement XAO Rays from the user's visual references and document it as an original engine.

## 3. Halftone PS engine — useful performance architecture and shape mathematics
- The engine has distinct cached stages: analysis/preprocessing, cell sampling, cell-to-palette matching, screen generation/per-ink separation, and final rasterization. This separation means changing a geometry control such as radius need not repeat expensive source analysis or OKLab palette matching.
- It supports a distinct per-ink screen path: each ink can have its own grid angle, coverage, screen geometry and seeded misregistration. Transparent ink masks intentionally overlap; they are not mutually exclusive labels.
- Its shape renderer uses signed-distance functions with analytic one-pixel coverage, plus exact-area matching between shapes. It also uses interior row spans to skip most per-pixel SDF work for large filled shapes. This is a strong approach for XAO's Circle/Square/Diamond/Ellipse/Cross/Line-style ink stamps.
- Small subpixel dots use analytic area/splat behavior rather than relying on an unstable subpixel SDF raster.
- Its virtual-grid/view model keeps the grid fixed for a full-resolution render while producing cropped preview windows. XAO should preserve global image-space grid anchoring so zooming, tiling and region renders do not move the pattern.
- Dither mode is a separate pipeline from halftone mode, with its own analysis grid and quantization cache. Do not conflate per-cell halftone geometry with per-pixel error diffusion.
- Cache keys are carefully partitioned by what actually changes each stage. XAO should adopt this dependency-aware cache model, but make cache entries immutable and thread-safe under MFR, with memory limits and invalidation tied to source identity, dimensions, color space, parameters and deterministic seed.
- The supplied source is a Photoshop UXP project, not an AE plugin. It is a behavior/algorithm reference only; no UXP host API or UI code belongs in the native .aex.

## 4. Filtr — useful effect-stack patterns, but browser renderer semantics cannot be copied
- Filtr dispatches many independent effects through a common renderer and ping-pong framebuffer stack. This is a useful reference for XAO's shared compositor and explicit effect ordering.
- It separates ordered GPU dithering from CPU error diffusion. The CPU kernels include Floyd–Steinberg, Atkinson, Jarvis–Judice–Ninke, Stucki, Burkes and Sierra variants.
- Error diffusion is scan-order dependent and cannot be parallelized as independent image rows without changing results. Ordered threshold matrices and blue-noise screens can be tiled/parallelized much more safely.
- The CPU diffusion path forces output alpha to 255 and works on 8-bit readback data; it is therefore not a correct alpha/HDR reference for XAO. XAO must preserve source alpha and support the selected AE bit depth.
- Filtr uses WebGL readPixels to move data to CPU for diffusion, and browser requestAnimationFrame/performance.now for animation. Both are host-specific and should be replaced by direct AE world access and absolute AE time.
- Its 64×64 noise texture is generated using Math.random at renderer construction. That is acceptable for a browser preview but not deterministic enough for XAO. Use a stable seed and a specified noise-table version so identical project/time/settings always render identically.
- The renderer falls back to an ordered 8×8 GPU method for some animated/time-based sources when CPU error diffusion is not used. XAO should never silently change a selected algorithm; unsupported combinations must be explicit.

## 5. Combined implementation decisions for XAO
1. Glow: build a host-independent FP32 CPU reference core first; AE SmartFX adapter second; optional GPU backends only after CPU parity tests.
2. Threading: a single bounded scheduler shared across XAO engines, no per-stage spawning and no nested thread pools. MFR correctness takes priority over maximum parallelism.
3. Cancellation and memory: every expensive stage supports cancellation and checked allocation; scratch memory is pooled with hard limits and deterministic fallback quality.
4. Halftone: shared source-analysis/cell cache, independent per-ink screen grids, SDF coverage, exact-area shape normalization, fixed image-space grid origin, and explicit overprint/knockout behavior.
5. Dither: separate ordered and diffusion families. Diffusion remains serial per scanline dependency (or uses a mathematically proven wavefront scheme); ordered masks can parallelize.
6. Compositing: all engines output premultiplied linear-light RGBA plus an explicit coverage/mask contract; alpha is never silently forced opaque. Color management and transfer functions are explicit.
7. Determinism: all noise, jitter, misregistration and animation derive from stable seeds and absolute AE time/frame mapping, never Math.random or wall-clock time.
8. Rays: treat the supplied binary exports as insufficient evidence. Build an original Rays engine from the actual user reference clips and expose no vendor DLL dependency.
9. Scope guard: do not add the separate Dither Majid Lines effect. A line-shaped halftone stamp remains only a shape primitive within Halftone, not a standalone Lines effect.

## 6. Validation gates before XAO implementation is called complete
- CPU-only build on Windows x64 with the exact AE 2023 / 23.2.1 SDK target.
- PiPL and C++ effect version / OutFlags / OutFlags2 byte-for-byte agreement.
- AE load/apply/remove/reopen tests; no warnings or crashes.
- 8/16/32-bpc correctness, HDR values, alpha/premultiplication, rowbytes, origins, non-square pixels, render scale and cropped tiles.
- MFR on/off output parity, repeated random-order frame renders, reverse/time-remapped footage, concurrent instances and cancellation.
- Deterministic image hashes for fixed source/time/settings/seed.
- Peak-memory and render-time profiling on the user's modest Intel system.
- GPU parity only where a backend is available; CPU-only remains fully functional.
