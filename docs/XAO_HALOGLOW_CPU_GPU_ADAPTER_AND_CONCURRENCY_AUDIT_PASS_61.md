# XAO HaloGlow CPU/GPU Adapter and Concurrency Audit — Pass 61

Date: 2026-11-10  
Source: supplied archive `XAO/glow/haloglow [open source]`  
Related: Pass 60

## Scope

This pass inspected the concrete CPU adapter, GPU render orchestration, CUDA/OpenCL dispatch, shared GPU kernel math, and CPU row scheduler. It is a source inspection only. No code was copied, no XAO files were modified, and no AE runtime or GPU execution was performed.

## Confirmed implementation details

### CPU adapter

- The AE adapter supports `PF_PixelFormat_ARGB32`, `ARGB64`, and `ARGB128`, normalizing each to FP32 RGBA for the shared core.
- Input rows are addressed using `rowbytes`; output is written using the output world's own rowbytes and origin.
- Integer output channels are rounded and clamped to the respective host maximum. Float output is not clamped to 1, preserving HDR values while bounding float overflow.
- Alpha is clamped to [0,1] on writeback. The core's input sanitization is applied on read.
- The no-active-glow bypass copies the input pixel exactly when Source Opacity is 100%; otherwise it fades premultiplied RGB and alpha together. Glow Only emits transparent pixels in the bypass case.
- A `std::bad_alloc` is translated to `PF_Err_OUT_OF_MEMORY`.

### GPU adapter and memory model

- GPU rendering accepts only `PF_PixelFormat_GPU_BGRA128`; other formats return an unsupported-format error.
- The adapter obtains input/output GPU world pointers through `PF_GPUDeviceSuite1::GetGPUWorldData`, derives pitch from `rowbytes / 16`, and passes origin and dimensions into the shared render plan.
- GPU internal buffers are float4 premultiplied RGBA. The shared kernel helpers explicitly convert AE premultiplied BGRA to internal RGBA and back.
- A per-render RAII pool owns temporary allocations. It waits for the backend queue before freeing buffers, including early-return paths after a failed stage.
- The render graph consists of downsample, coarse-to-fine accumulation, and final composite stages. The stage sequence is shared across backends.
- CUDA dispatch uses the host-provided stream and checks launch errors; final synchronization is explicit.
- OpenCL shares the compiled immutable program but creates per-render `cl_kernel` objects because kernel argument state is mutable. It releases those kernel objects at render exit and calls `clFinish` before completion.
- Metal has a separate adapter and returns its host error directly.
- Failed/incomplete GPU renders are not reported as successful; allocation failure maps to out-of-memory, other backend failures to an internal render error.

### Kernel parity boundary

- CUDA, OpenCL and Metal wrappers dispatch the same shared kernel-body definitions in `HG_Kernels.h`.
- Pixel extraction, sanitization, luminance, tone, glow and compositing math is centralized in `HG_PixelMath.h`, intended to keep backend math aligned.
- The shared code explicitly handles BGRA/RGBA channel ordering and premultiplied alpha. The source comments and code establish intended semantics, but only actual backend parity tests can establish numerical equivalence on devices.

## Risks and findings for XAO

1. **CPU nested parallelism risk:** `HG_Parallel.h` creates up to hardware-concurrency worker threads for each CPU render. AE may run multiple frames concurrently under MFR, so this can multiply thread counts and oversubscribe a weak CPU. The code is row-disjoint and deterministic by design, but does not expose a shared host thread budget or use an AE scheduler. XAO should not copy this scheduler unchanged. Prefer a bounded worker policy, serial/small-image fallback, and measured MFR scaling.
2. **GPU allocation-size hardening:** the pool requests `pixels * 16` bytes without a visible checked-multiplication guard at that call site. XAO should use checked size arithmetic and validate dimensions/pitches before allocation.
3. **OpenCL queue concurrency:** kernel argument objects are correctly per render, but the command queue comes from AE's device info. Confirm the host's queue concurrency contract and ensure enqueues from simultaneous MFR renders are safe/ordered as expected; do not assume per-render kernels alone prove queue isolation.
4. **GPU fallback policy:** the setup code can leave unsupported devices unconfirmed so AE can use CPU rendering. XAO should preserve this principle and must never require a GPU to load or render.
5. **GPU coverage is narrower than CPU coverage:** the GPU adapter is BGRA128-only. Do not describe GPU support as equivalent to CPU support for every pixel depth.
6. **CPU conversion cost:** the adapter copies the entire input into an FP32 image and writes the output back. This is a simple correctness boundary but can be memory-bandwidth-heavy. Benchmark before adoption; consider ROI-aware conversion only after correctness is proven.
7. **GPU temporary memory:** every render allocates its own pyramid buffers; the README itself lists pooling/shared-memory optimization as a limitation. Large frames or concurrent MFR frames may increase peak memory significantly.
8. **Error semantics:** non-OOM GPU failures collapse to a generic internal error. XAO should retain diagnostic detail in development builds without leaking device-specific state into render output.
9. **AE SDK compatibility remains unverified:** these selectors, suites, GPU formats and PiPL paths must be checked against the exact AE 2023 SDK. The archive's own release claims are not a substitute for compiling against that SDK.

## XAO adoption guidance

- Reuse the shared pixel math and render-plan concepts only after a complete line-level license and dependency review.
- Keep one XAO EffectMain/PiPL/plugin target; do not import HaloGlow's independent plugin entry point.
- Keep CPU as the guaranteed baseline. Treat GPU as an optional acceleration path selected by AE, not as a prerequisite.
- Design XAO's CPU concurrency around AE MFR rather than spawning a full hardware-sized pool inside every render.
- Add explicit checked allocation arithmetic, format/stride validation, cancellation checks where supported, and deterministic render tests.
- Add parity fixtures that compare CPU/GPU on the same inputs, including odd dimensions, non-zero origins, transparent pixels, HDR values, and edge tiles.

## Evidence boundary

Directly inspected: `HG_Parallel.h`, `HG_GpuRender.cpp`, `HaloGlow_CPU.cpp`, selected sections of `HG_GPU.cpp`, `HG_Kernels.h`, `HG_PixelMath.h`, CUDA/OpenCL/Metal kernel wrappers.  
Not established: successful clean build, AE 2023 compatibility, actual device execution, measured CPU/GPU parity, MFR stress behavior, or visual equivalence to XAO references.  
No source copied and no XAO implementation changed.
