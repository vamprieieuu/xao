# XAO Focused Audit — HaloGlow Native AE Glow Reference — Pass 10

Date: 2026-11-07

## Scope

Direct review of the supplied HaloGlow MIT project:
- CMake build configuration and CPU/GPU backend selection
- `Source/HaloGlow.cpp`, `HaloGlow_CPU.cpp`, `HG_Core.cpp/.h`
- `HG_Parallel.h`, `HG_Target.h`, GPU dispatch structure
- CPU core tests and README/spec claims

A host-independent core test executable was compiled locally with GCC 17 mode and pthread support from `HG_Core.cpp`, `HG_Coefficients.cpp`, and `tests/hg_core_tests.cpp`. Result: **3,065 checks, 0 failures**. This validates those core tests on this local environment only; it is not a Windows build, an AE SDK build, or an After Effects runtime test.

## 1. Architecture that is valuable for XAO

- Clean separation between a host-independent C++17 rendering core and the AE adapter.
- SmartFX pre-render captures parameter values into immutable per-render data. SmartRender does not re-read AE parameters or mutable sequence state.
- The pre-render stage calculates input/output bounds and asks AE only for the required source region. This is a useful model for XAO engines with expansion (Glow/Rays).
- CPU adapter supports ARGB32, ARGB64 and ARGB128, reads rows using `rowbytes`, accounts for world origins, and normalizes to an FP32 premultiplied RGBA core representation.
- Float output preserves HDR values above 1 (while finite overflow is bounded); integer paths quantize to their channel range.
- Glow is built as a multi-scale pyramid with local filtering and output-driven domains rather than one enormous full-resolution blur.
- CPU-only mode is explicitly supported through `HG_FORCE_CPU_ONLY=ON`; CUDA/OpenCL/Metal are optional backends.
- CPU and GPU share a pixel-math contract, with separate parity tests for optional GPU backends.
- The project uses MIT licensing. Its native AE wrapper, UI, localization, update-check code, and product-specific controls are not XAO requirements and should not be copied wholesale.

## 2. Build and environment findings

- The CMake project requires an external After Effects SDK Examples root containing `Headers/`; the SDK is not self-contained in this project. This is an explicit build prerequisite.
- A CPU-only build can avoid CUDA/OpenCL/Metal discovery and does not require the user's older Intel machine to have a powerful GPU.
- The host-independent core tests can be built separately from the AE SDK adapter; this audit successfully ran them locally as noted above.
- The repository's README reports Windows Release CPU/CUDA/OpenCL and macOS CPU/Metal parity tests as passed. Those are repository claims, not tests repeated in this audit.
- No actual XAO build or AE installation/runtime test has been performed.

## 3. Risks and improvements before considering a port

1. **Nested CPU parallelism / oversubscription:** `HG_Parallel.h` creates and joins a fresh set of `std::thread` workers for each row-band operation, sized from `hardware_concurrency()`. HaloGlow also advertises AE threaded rendering. Multiple concurrent AE frame renders can therefore each create their own full worker set, oversubscribing a modest CPU. XAO should use a bounded worker policy that coordinates with AE MFR, and benchmark with AE MFR on/off. Do not blindly copy this thread-spawning design.
2. **Large FP32 memory footprint:** the CPU adapter materializes input and output images as FP32 RGBA, plus emission, filtered pyramid levels and temporary buffers. This is architecturally clean but can consume substantial RAM at 4K and under concurrent MFR. XAO needs explicit peak-memory budgets, allocation reuse and resolution-aware quality/performance tiers.
3. **Allocation churn:** image buffers and pyramid temporaries are repeatedly allocated/reset during rendering. A reusable per-render scratch arena or carefully bounded cache may improve performance, provided cache ownership remains thread-safe and deterministic.
4. **GPU is optional, not the baseline:** the GPU backend is useful as a later acceleration layer, but XAO's core must remain correct and performant without CUDA/OpenCL. DirectX uses CPU in this reference.
5. **The CPU path is the most relevant reference for XAO:** port the host-independent pyramid/filter concepts and its AE buffer-handling discipline, not the optional GPU stack, product UI, update checker, or unrelated product-specific services.
6. **MFR must be earned, not declared:** HaloGlow's pattern of immutable pre-render data and render-local state is the right direction. XAO should not set `PF_OutFlag2_SUPPORTS_THREADED_RENDERING` until every render path, cache, engine and shared resource is proven thread-safe. Adobe's SDK guide explicitly says the flag indicates concurrent rendering and should only be set after thread-safety is established: https://ae-plugins.docsforadobe.dev/effect-details/multi-frame-rendering-in-ae/
7. **PiPL and source flags must remain identical:** this project centralizes literal values in `HG_Target.h` and uses the same target definitions in the PiPL preprocessing path. XAO should similarly generate or centrally derive its PiPL metadata and C++ flags to avoid the known AE version/outflags mismatch class of failure.

## 4. XAO decisions

- Use HaloGlow's host-independent-core / AE-adapter separation as an architectural reference.
- Implement CPU-first algorithms and establish image format, alpha/premultiplication, rowbytes, origins, render scale, bounds and HDR behavior as shared core contracts.
- For expensive spatial effects, prefer multi-scale pyramids and bounded intermediate regions over full-frame brute-force filters.
- Design thread limits with AE MFR in mind; avoid spawning hardware_concurrency threads inside every render stage.
- Keep render inputs immutable and derive every frame from its requested time and parameters. Use a thread-safe cache only where its key fully identifies the computation.
- Run standalone core tests on every commit, then Windows SDK builds, then AE 2023.2.1 runtime validation on the target environment.

## 5. Status

This is a focused review of the HaloGlow project and a successful standalone run of its host-independent core tests. It does not establish that HaloGlow itself builds in the user's Windows/AE environment, and it does not complete the XAO archive audit.
