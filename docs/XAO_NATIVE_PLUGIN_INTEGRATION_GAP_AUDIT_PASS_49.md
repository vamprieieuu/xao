# XAO — Native Plugin Integration Gap Audit (Pass 49)

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Scope: inspect the current branch's actual build entry point and core interfaces against the stated native After Effects delivery requirements.
Status: repository source audit only. No Windows/MSVC build, Adobe SDK build, or After Effects runtime test was performed.

## 1. Files inspected

- Root `CMakeLists.txt`
- `core/include/xao/Engine.h`
- `core/include/xao/Pipeline.h`
- `core/src/Pipeline.cpp`
- Existing ASCII renderer audit (Pass 43)
- Existing S1 AE parameter/pixel-buffer trace (Pass 48)

## 2. Verified current build boundary

The root CMake project is `XAO_Core` version 0.1.0 and declares only CXX as its language. It builds one static library, `xao_core`, from:

- `core/src/Image.cpp`
- `core/src/Compositor.cpp`
- `core/src/Pipeline.cpp`

The only executable target declared in the inspected root CMake file is `xao_core_tests`, conditional on `XAO_BUILD_TESTS`.

No After Effects SDK include path, SDK library, Windows resource/PiPL compilation step, `.aex` module target, or plugin packaging/install target is declared in this root build file.

This is a verified statement about the inspected root CMake file, not a claim that no separate untracked or externally-built plugin exists.

## 3. Verified core architecture

`Engine.h` defines a generic engine interface. Its contract says source and destination dimensions match and pixels use linear premultiplied RGBA; every destination pixel must be written per call.

`Pipeline.cpp`:
- validates matching source/destination dimensions;
- copies source into a working image;
- allocates processed and composed images;
- iterates enabled engine passes;
- calls each engine's `render`;
- composites using either `sourceOverPremultiplied` or `mixPremultiplied`;
- moves the final working image into destination.

This is a useful host-independent processing boundary. It is not, by itself, an AE plugin adapter or a concrete ASCII/Glow/Rays/Glint/Halftone/Dither engine.

## 4. Integration gaps that remain open

| Area | Verified state in inspected files | Required next work |
|---|---|---|
| AE plugin target | Not declared in root CMake | Add isolated Windows x64 AE SDK module target and packaging |
| PiPL / EffectMain | Not represented in inspected build/core files | Implement and validate resource metadata and dispatch |
| AE parameter bridge | No adapter in inspected files | Map AE parameter definitions into immutable typed render configuration |
| Pixel bridge | Core contract is linear premultiplied RGBA, but no AE conversion adapter inspected | Explicit 8/16/32-bpc conversion, channel order, alpha and stride contract |
| SmartFX / MFR | No AE callbacks or sequence lifecycle in inspected files | Implement deterministic arbitrary-frame rendering and correct Smart Pre-render bounds |
| Concrete engines | Generic interface only in inspected files | Audit current tree and integrate engines independently, starting with ASCII |
| GPU | No GPU backend or capability negotiation in inspected files | CPU-first baseline; optional GPU path only after parity tests |
| Tests | Root CMake exposes core tests only | Add pixel adapter, deterministic frame-order, alpha, bounds, and AE host validation |

## 5. Critical design decision: preserve the core boundary

Do not move Adobe SDK types into the host-independent engine headers. Keep the AE adapter responsible for:
1. validating host descriptors and render requests;
2. converting host pixels into the core's documented linear premultiplied RGBA representation;
3. constructing an immutable render context/configuration;
4. invoking the engine pipeline;
5. converting output back to the exact requested AE pixel format and alpha convention;
6. reporting errors through AE's supported error path.

The conversion contract must be proven with fixtures. The S1 decompilation confirms that one reference plugin distinguishes 4-byte and 8-byte pixel paths and checks pointers, dimensions and row strides, but it does not establish XAO's host alpha/premultiplication policy.

## 6. Safety and correctness gates

Before claiming an installable XAO build:
- verify PiPL version and global outflags agree;
- verify EffectMain dispatch and parameter count;
- test 8/16/32-bpc formats and row padding;
- test straight/premultiplied alpha and transparent colored pixels;
- test non-zero origins, ROI and Smart Pre-render request/result bounds;
- test arbitrary frame order, reverse playback and MFR concurrency;
- run a clean Windows x64 build with the intended AE 2023 SDK;
- load, apply, render, duplicate, save/reopen and remove the effect in AE 23.2.1.

No such tests are claimed by this audit.

## 7. Conclusion

The checked-in core is a small, generic compositing foundation. It is not yet evidence of a complete native AE plugin. The next implementation milestone must be the isolated AE SDK adapter and build target, while preserving the core's host-independent image contract. In parallel, the concrete ASCII engine must be verified in the branch rather than inferred from reference audits.
