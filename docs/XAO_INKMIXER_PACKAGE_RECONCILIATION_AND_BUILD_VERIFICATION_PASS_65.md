# XAO InkMixer Package Reconciliation and Portable Build Verification — Pass 65

Date: 2026-11-10  
Target branch: `xao/recovery-baseline-2026-11-10`

## Executive result

The prior InkMixer packages were recovered from the Library and inspected as actual ZIP contents. They contain a coherent progression of the same host-neutral four-plate engine, followed by a separate experimental AE adapter. The newest SDK-adapter package builds its portable C++ core cleanly on this Linux environment and all six CTest targets pass. This independently verifies the portable package snapshot, not the live XAO branch and not an AE `.aex`.

The latest package is a strong candidate for selective integration into the branch. It is not safe to copy its AE adapter wholesale: it declares a separate `XAO_InkMixer` plugin identity/entry point, while XAO must remain one unified effect. Its AE adapter also exposes only a small subset of the reserved controls.

## 1. Package chronology and source relationship

Ten Library ZIP packages were materialized and their archive contents enumerated:
- Initial implementation / opaque-base patch.
- Plate-state transform.
- Procedural screen.
- Screen-to-InkMixer integration.
- MFR core verification.
- AE binding/frame pass.
- AE SDK adapter pass.
- Core patch and Retratone deobfuscation reference.

The packages are not ten independent engines. They are successive snapshots/patches of one InkMixer implementation. In particular:
- The screen integration package contains `ScreenPattern`, `PlateState`, `InkMixer`, four core tests and a CMake project.
- The AE binding/frame package adds `InkSeparation`, `InkMixerFrame`, stable AE parameter ID declarations, frame tests, and an adapter binding/blocker note.
- The SDK adapter package adds `AE_InkMixer.cpp/.h`, PiPL resource source, Windows PiPL preprocessing, build instructions, and a separate optional plugin target.
- Earlier PlateState/Procedural Screen snapshots are superseded by the later Screen Integration source for those same paths; do not overlay old files on top of the latest snapshot.
- The Core Patch and Opaque Base packages are earlier narrow patches and should not override the later full implementation without a specific regression reason.

## 2. Portable build independently reproduced

Built the SDK-adapter package's portable core from a clean CMake build directory with:
- GNU C++ 14.2
- CMake Release
- `XAO_BUILD_AE_PLUGIN=OFF`
- `XAO_BUILD_TESTS=ON`

Result: configure succeeded, all core sources compiled, and CTest passed **6/6**:
1. `xao_core_tests`
2. `xao_ink_mixer_tests`
3. `xao_plate_state_tests`
4. `xao_screen_pattern_tests`
5. `xao_ink_separation_tests`
6. `xao_ink_mixer_frame_tests`

This is a fresh local reproduction of the portable core tests. It is not ASan/UBSan, MSVC, PiPL, Windows resource compilation, AE SDK linking, or After Effects runtime validation.

## 3. Confirmed core capabilities in the latest package

The latest core source set contains:
- Four independent plate states with enabled/color/opacity.
- Per-plate screen settings and plate registration transforms.
- Deterministic source-image-to-four-plate separation via bounded optical-density NNLS/FISTA implementation.
- Screen generation and per-plate transforms.
- Four-plate ink composition and overprint modes.
- A frame-level function joining separation, screen/transform and composition.
- Stateless per-call state/context and local frame buffers intended for concurrent renders.
- Six portable regression test executables.

The adapter package also documents stable parameter IDs for global controls and plate groups. However, only global mode, threshold, and each plate's enabled/color/opacity are registered in the current adapter. Offset, rotation, screen controls, print order and custom visual UI are still not registered.

## 4. AE adapter review: integration blockers and risks

The adapter source contains a real `EffectMain`, `PluginDataEntryFunction`, SmartFX pre-render/render callbacks, pixel-format dispatch for ARGB32/64/128, and a PiPL resource source. It is an experimental standalone plugin target, not proof of an integrated XAO plugin.

Key blockers:
1. **Separate plugin identity:** PiPL/CMake/entry code identify the target as `XAO_InkMixer` with its own effect registration. Do not import it as a second plugin. Its adapter logic must be folded into the eventual single XAO EffectMain and unified parameter map.
2. **No full UI:** current registration exposes only 14 controls after input (two global + three per plate); it does not register the full reserved parameter set or the requested advanced ink preview UI.
3. **Frame/ROI cost:** pre-render requests the full source frame to anchor the procedural screen, then the adapter converts the checked-out world to a full FP32 image for each render. Correctness may be simpler, but memory and CPU cost can be high for large comps and concurrent MFR frames.
4. **Origin/extent validation:** the writeback maps output world origin to the checked-out input origin. This needs explicit tests with non-zero origins, cropped checkouts, odd dimensions, downsample factors and partial output requests in AE itself.
5. **Color contract:** the core is documented as linear premultiplied RGBA, but `ReadImage` directly normalizes host channel values without an explicit AE working-space transfer conversion. This is only correct if the adapter's host pixel values are already in the expected linear encoding; AE color-management behavior must be verified before release.
6. **Parameter snapshot:** pre-render checks out each parameter and stores an immutable state. This is the correct general boundary for SmartFX, but error/checkin paths should be audited carefully for all failure permutations.
7. **PiPL/build not reproduced:** Linux cannot run the Windows PiPLtool/MSVC/resource pipeline here. The CMake target is optional and requires Windows/MSVC and an SDK Examples tree.

## 5. SmartFX contract cross-check

The adapter checks the source layer out during pre-render and accesses its pixels in Smart Render, which matches Adobe's documented two-stage SmartFX model. Adobe's guide states that each pre-render layer checkout must map one-to-one to a single `checkout_layer_pixels` call, and that `result_rect` cannot exceed the requested output rectangle unless extra-pixel output is explicitly declared. The adapter's current output rectangle is intersected with the original output request and input result rectangle, which follows that bound. Its full-frame input request is a deliberate anchoring/memory trade-off, not a reason to claim full-frame output.

The Adobe guide also states that pre-render can occur without a corresponding render; the allocated pre-render payload is therefore correctly assigned a host disposal callback. These contracts still require validation against the supplied May 2023 SDK and actual AE 2023 behavior.

## 6. Integration decision

**Promote the latest Screen Integration + AE Binding/Frame + SDK Adapter package as the canonical InkMixer candidate snapshot.** Do not yet merge the standalone AE adapter target.

Recommended branch integration:
1. Add the host-neutral core files and six tests to the existing XAO core, resolving overlapping `Image`, `Engine`, `Pipeline` and compositor files intentionally rather than copying whole directories.
2. Preserve XAO's existing pipeline and unified plugin identity.
3. Integrate the frame-level InkMixer engine behind the XAO engine interface.
4. Extend the unified parameter map to include the reserved per-plate offsets, angles, screen type/frequency/negative/antialias and print order.
5. Add a single AE adapter dispatch path for XAO; do not ship `XAO_InkMixer.aex` as a second effect.
6. Add explicit alpha, transfer-function, ROI, non-zero-origin and MFR tests before claiming AE integration.

## Evidence and limitations

Inspected all ten ZIP inventories; read the latest SDK adapter CMake, AE adapter header/implementation, parameter IDs, integration blockers and test report. Built the portable SDK-adapter package and ran all six CTest targets successfully. Cross-checked SmartFX checkout/result-rectangle rules against Adobe's published SDK guide.

Not performed: Windows/MSVC build, PiPLtool, AE 2023 load/render, MFR stress test, GPU build, visual reference comparison, sanitizer run, or integration into the XAO branch. No project source was changed in this pass.
