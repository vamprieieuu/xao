# XAO HaloGlow Native Glow Source Audit — Pass 60

Date: 2026-11-10  
Archive source: `XAO/glow/haloglow [open source]`  
Upstream project: HaloGlow 1.0.0  
License in supplied archive: MIT, copyright PALF MovieWorks (2026)

## Executive finding

HaloGlow is the strongest directly relevant glow source found in the supplied archive so far. Unlike web/Photoshop-oriented glow projects, it is already a native After Effects SDK plugin with a host-independent C++17 core, CPU reference renderer, SmartFX adapter, optional CUDA/OpenCL/Metal backends, PiPL generation, MFR-aware design, and tests. Its architecture and selected core algorithms are eligible for technical reuse under MIT, provided XAO retains the required copyright/license notices and checks all source-level notices before copying files.

This is a source audit, not a claim that HaloGlow has been integrated into XAO or built against the user's AE 2023 SDK. No source was copied in this pass.

## Project and build architecture verified

- CMake separates a host-independent `haloglow_core` static library from the AE plugin target and test executables.
- Core uses C++17, a shared FP32 reference path, explicit parallel helpers, and disables unsafe fast-math for MSVC.
- AE plugin target compiles the effect entry/UI/CPU adapter and AE SDK helper sources; Windows creates a PiPL resource through Adobe's PiPLtool and emits an `.aex`.
- GPU backends are feature-detected: CUDA on Windows, OpenCL when available, Metal on macOS. A force-CPU-only option exists.
- The README states support for 8-bit, 16-bit and 32-bit float, MFR, and CPU/CUDA/OpenCL on Windows. These are upstream release claims, not independently reproduced by this audit.
- README describes DirectX-host rendering as CPU fallback. GPU memory is allocated per render; pooled allocation and a shared-memory local filter remain listed limitations.

## Glow algorithm and rendering model

The Japanese v0.5 design specification explicitly distinguishes its initial PSF model from the later octave/pyramid model. It defines:
- Bright-source extraction using luminance, threshold and a soft knee; versioned extraction behavior exists in the core.
- A multi-component point-spread function for version 1: narrow Gaussian centre, medium Gaussian spread, and a finite-support Moffat-like long tail. The mixture weights vary with Falloff and are normalized.
- Size calibrated through a 90%-energy radius (R90), rather than treating size as an arbitrary blur radius.
- Independent horizontal and vertical scaling; degenerate single-axis behavior is specified as a marginal distribution rather than simply sampling the centre row/column.
- Version 2 multi-scale low-pass pyramid. Each scale is screened into the result; scale gain/falloff controls the long tail. A flat white field is constrained not to exceed brightness 1, while HDR values above 1 are retained.
- Per-glow intensity, gamma, saturation, two-colour tint, glow opacity, source opacity, and Glow Only output.
- Host working RGB is processed as supplied; the effect does not infer or silently decode an input transfer function. Luminance coefficients are selected separately for Rec.709/sRGB, Display P3 and ACEScg.

Core source confirms a 6×6 2D downsample kernel, single-axis downsample kernel, upsample coefficients, 5-tap binomial companion filter, local integrated-Gaussian bases, finite parameter sanitization and rectangle/domain planning. The core builds a render plan shared across backends, reducing the risk of CPU/GPU schedule drift.

## CPU, GPU and parity design

- The CPU adapter normalizes supported AE pixel depths into FP32 premultiplied RGBA for the shared core and converts back to the host format.
- Shared pixel math/kernel bodies are used to align CUDA/OpenCL/Metal implementations.
- The test tree includes core tests and CPU-vs-GPU parity test programs for CUDA/OpenCL and Metal.
- The test source covers extraction behavior, soft-knee monotonicity, HDR compositing, premultiplied-alpha properties, DC gain, odd/negative-origin tiling, PSF shape/continuity and related invariants.
- Test source inspection does not prove tests passed in this environment. The README's release-test statements were not independently reproduced here.

## Important limitations and integration risks for XAO

1. The source is a complete product with its own plugin ID, UI, localization, versioning and update-check behavior. XAO should reuse the algorithm/core boundary selectively, not transplant product identity, update notices, UI strings or unrelated release infrastructure.
2. Its CMake expects an Adobe AE SDK Examples tree and PiPLtool. XAO's own build must integrate the needed AE SDK pieces into its existing target and avoid creating a second competing plugin entry point.
3. The project uses C++17 and platform-specific GPU toolchains. XAO must keep a dependable CPU-only build path for weak or unsupported GPUs and must not require CUDA/OpenCL merely to load or render.
4. The supplied source's 2026 release and stated AE support are not proof of compatibility with AE 2023 / 23.2.1. Check every SDK API and GPU selector against the exact target SDK.
5. The specification itself says its visual-quality evaluation was not yet completed in v0.5. The README describes release tests, but independent visual comparison against XAO's Glow references is still required.
6. The spec distinguishes algorithm version 1 and version 2. Preserve versioned render semantics for saved projects if adopting either model; do not silently replace an older look.
7. Alpha, HDR, colour-space and MFR contracts must be reviewed in the exact implementation files and tested through XAO's own AE adapter. Do not infer all host behavior from the design document.

## Reuse decision

**Recommended: high-priority MIT reuse candidate for the Glow engine.**

Potentially reusable after file-level review and attribution:
- Host-independent core math and plan construction.
- CPU reference implementation and deterministic filter coefficients.
- Shared pixel math and backend kernel design.
- Focused tests for extraction, PSF, tiling, alpha and HDR invariants.

Do not copy wholesale without review:
- AE plugin entry point and parameter/UI layer.
- PiPL/resource/build scripts (adapt to XAO's single plugin target).
- Update-check/network code, release notices, localization and standalone product identity.
- Platform GPU adapters before confirming XAO's target SDK and deployment constraints.

## Next audit required before source integration

- Trace `HG_Core.h`, remaining `HG_Core.cpp` functions, `HaloGlow_CPU.cpp`, `HG_PixelMath.h`, `HG_Kernels.h`, CUDA/OpenCL kernels, and GPU host bridge line by line.
- Inspect `HG_Parallel.h`, `HG_GpuRender.cpp`, `HG_GPU.cpp`, PiPL and AE selector code for thread safety, MFR, GPU fallback and SDK version dependencies.
- Run the upstream core tests in a clean local build if the available compiler supports it; separately verify test limitations and build dependencies.
- Compare the HaloGlow plugin's PiPL/EffectMain/SmartFX patterns with XAO's existing plugin target before proposing any transplant.
- Review the remaining Glow archive references (Deep Glow, DeepGlow2, Starglow, S_Glint decompilations, and Superbloom) separately; do not equate decompilation with reusable source.

## Evidence boundary

Inspected: README, MIT LICENSE, CMakeLists, Japanese v0.5 design specification, core source excerpts and test source excerpts.  
Not inspected fully in this pass: all GPU kernels, complete AE adapter, complete test suite, all build helper scripts and every third-party dependency.  
No source copied; no XAO code modified; no AE build/runtime test performed.
