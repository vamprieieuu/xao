# XAO Project Recovery Baseline
**Date:** 2026-11-10  
**Repository:** `vamprieieuu/xao`  
**Base branch at recovery:** `main`  
**Recovery branch:** `xao/recovery-baseline-2026-11-10`

## Purpose
This document establishes a durable checkpoint for the XAO project so development can continue without repeating completed work or confusing independent engine tests with a verified After Effects plugin build.

This is a recovery/status record, not a claim that every listed engine has been revalidated from its latest source in this session.

## Product direction
XAO is one unified native Adobe After Effects effect/plugin with multiple distinct rendering engines. It is not an Ink Mixer-only plugin and must not be reduced to generic overlays or a single shared image-processing pass.

Target requirements carried forward:
- Native After Effects `.aex`, C++ and Adobe After Effects SDK.
- Windows x64; After Effects 2023 / 23.2.1 target.
- CPU-first baseline; optional acceleration must not be a runtime requirement.
- Robust PiPL metadata, EffectMain, parameter registration/count, Outflags/Outflags2, pixel formats, alpha/premultiplication, render bounds, memory ownership, thread safety, deterministic time/randomness, SmartFX and MFR behavior.
- Each engine must retain its real algorithm and relevant controls. Shared UI is appropriate only where controls have genuinely shared semantics.

## Engine status — current working baseline

| Engine / subsystem | Working status | Evidence / caveat |
|---|---|---|
| ASCII | Existing engine work and substantial reference research | Exact latest source/build state still needs file-by-file verification. |
| Dither | Existing engine work and reference research | Do not confuse PixelDitherGo reverse-engineering with a verified exact proprietary formula. |
| Halftone | Native host-neutral implementation work and closure reports exist | Ink separation, procedural screens and overprint path have independent tests; AE integration remains a separate verification. |
| Typeset | Native engine work is recorded | Verify latest source and complex-script behavior before marking final. |
| Glow | User confirms completed | Historical CPU-core and compute-driver work exists; do not infer actual GPU execution or AE runtime success without evidence. |
| Rays | User confirms completed | Historical CPU-core tests exist; AE runtime remains separately verifiable. |
| Gradients | User confirms completed | Preserve the latest user-confirmed completion; do not reopen or replace the implementation based on older audits. |
| Depth | User confirms completed | Preserve the latest user-confirmed completion; verify source integration only when latest files are available. |
| Glint | User confirms completed | Preserve the latest user-confirmed completion; verify source integration only when latest files are available. |
| Ink Mixer / Retratone | Detailed native implementation and AE adapter work recorded | Keep its status distinct from the overall XAO product; verify adapter and actual AE behavior separately. |

The user explicitly corrected the historical status on 2026-11-10: Gradients, Depth, Rays, Glow and Glint are already completed in the latest development state. Older reports that describe any of these as pending are stale and must not override that correction.

## Verified work records available in the repository
The current repository contains a substantial audit trail, including (not exhaustive):
- `docs/ENGINE_ARCHITECTURE.md`
- `docs/RESEARCH_AUDIT.md`
- `docs/ASCII_ORIGINAL_ARCHIVE_REINSPECTION_PASS_41.md`
- `docs/ASCII_ENGINE_OPEN_SOURCE_AUDIT_PASS_40.md`
- `docs/MAIN_IDEAS_FINAL_DEEP_AUDIT_PASS_39.md`
- `docs/MAIN_IDEAS_NATIVE_SEQUENCE_REVIEW_PASS_38.md`
- `docs/MAIN_IDEAS_DEEP_VISUAL_ASSET_AUDIT_PASS_37.md`
- `docs/MULTI_CLIP_VISUAL_REFERENCE_AUDIT_PASS_35.md`
- `docs/ARRAY_SHAPE_HALFTONE_TYPESET_REFERENCE_AUDIT_PASS_34.md`
- `docs/DEEP_GLOW_STARGLOW_BINARY_SHADER_AUDIT_PASS_23.md`
- `docs/DEEP_GLOW_ASCII_TEMPORAL_REVIEW_PASS_24.md`
- `docs/HALFTONE_AKAM_ALGORITHM_AND_LICENSE_AUDIT_PASS_18.md`
- `docs/LEGACY_HALFTONE_AE_AND_OFX_REVIEW_PASS_19.md`
- `docs/HALFTONE_DEAN_PYTHON_RENDERER_REVIEW_PASS_20.md`
- `docs/HALFTONE_LAP_BROWSER_PRINT_ENGINE_REVIEW_PASS_21.md`
- `docs/SUPERBLOOM_GLOW_PIPELINE_REVIEW_PASS_22.md`
- `docs/PIXELDITHERGO_VISUAL_STRUCTURE_AUDIT_PASS_28.md`
- `docs/POINTLESS_MULTI_ENGINE_SOURCE_AUDIT_PASS_29.md`

These audits include important licensing and reuse boundaries. Reference-only binaries/decompiler output must not be copied into production code. In particular, the Pointless implementation is GPL-3.0 and must remain isolated unless a deliberate GPL compliance decision is made. The Halftone Akam source has a material license/provenance conflict and is not approved for code reuse.

## Ink Mixer / Retratone implementation notes
The latest recorded native work describes:
- Four independent ink plates A/B/C/D with color, coverage/opacity and print order.
- Multiply Overprint and Normal Overprint compositing.
- Fifteen overlap regions generated using the same composition routine as rendering.
- Linear-light premultiplied RGBA handling.
- Optical-density conversion and bounded non-negative least-squares separation using projected FISTA.
- Per-plate procedural screens: Dot, Ellipse, Line, CrossLine, Wave, Fan and Smooth.
- Negative/antialias controls, plate transforms and deterministic drift.
- Versioned state codec with Version 1 migration.
- A source-to-output path covering masks, screening, plate transforms and ordered overprint.

Historical test reports mention successful host-neutral Debug/Release tests and sanitizer/concurrency checks. These results are not proof of a Windows MSVC build or successful operation inside After Effects.

## Hard constraints / exclusions
- Do not modify `GradientStudio`.
- Do not import the separate Dither Majid **Lines** effect, its UI, presets or engine.
- Do not restart the project or replace working engines with generic approximations.
- Do not add proprietary binary/decompiler code or unclear-license assets to production.
- Do not claim a successful `.aex` build or AE runtime test without an actual run on the target toolchain/host.
- Preserve existing working code and history; use focused, reviewable changes.

## Current integration gap to resolve
The repository's default `main` branch has a historical audit/source tree, while newer local development packages and adapter work are recorded outside the currently published main tree. A prior recovery inspection did not find the complete latest `XAO_Development/Source` tree in the accessible Library materials.

Therefore, the next technical step is to inventory all available current source packages and identify the authoritative latest source for each engine before attempting integration. Do not reconstruct or overwrite completed engines from stale audit reports.

## Next execution sequence
1. Inventory repository branches, source tree, workflows, and all available current project packages.
2. Create a source-of-truth manifest mapping each engine to its latest source path, version/revision, tests and integration status.
3. Reconcile completed Gradients, Depth, Rays, Glow and Glint with the unified source tree without reimplementing them.
4. Reconcile ASCII, Dither, Halftone, Typeset and Ink Mixer/Retratone implementations and their reference/license boundaries.
5. Audit the unified AE adapter: PiPL, EffectMain, parameter registration, SmartFX, pixel formats, alpha, render bounds, MFR and state serialization.
6. Run host-neutral tests, then Windows/MSVC SDK build and AE runtime tests when that environment is available.
7. Record every meaningful change, exact test command/result, known limitation and next step in GitHub.

## Change log
### 2026-11-10 — Recovery baseline
- Recovered project direction and constraints from the repository audit trail and prior project context.
- Recorded the user's latest completion correction for Gradients, Depth, Rays, Glow and Glint.
- Separated engine-level work from AE adapter/build/runtime verification.
- Created this recovery checkpoint on a dedicated branch; no changes were made to `main`.
