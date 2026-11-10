# XAO Current Branch Implementation Reality Check — Pass 64

Date: 2026-11-10  
Branch audited: `xao/recovery-baseline-2026-11-10`

## Executive result

This pass checks the actual Git tree rather than relying on prior-session status notes or package names. The branch currently contains a substantial reference archive and audit documentation, but the checked-out native implementation is still a small host-independent core skeleton. The previously discussed InkMixer packages are not present as implementation source in this branch tree, and there is no AE SDK plugin target in the root build.

This is an important correction to the project status: the archive and research are real; a complete integrated XAO native plugin is not yet established by this branch.

## 1. Actual repository layout

The branch root contains:
- `CMakeLists.txt`
- `XAO/` — supplied reference archive extracted into the repository
- `core/` — small C++ core
- `docs/` — research/audit reports
- `tests/` — core tests

The `XAO/` tree has 1,091 entries. It includes the ASCII, Halftone, Glow, Rays, Dither and Main Ideas references. The reference archive is therefore retained in the branch; this is not itself proof that its contents are integrated into the plugin.

## 2. Root CMake and native AE target status

The root `CMakeLists.txt` declares:
- `project(XAO_Core VERSION 0.1.0 LANGUAGES CXX)`
- static library `xao_core` from `Image.cpp`, `Compositor.cpp`, `Pipeline.cpp`
- one optional test executable, `xao_core_tests`
- C++17 and basic compiler warnings.

It does **not** currently declare:
- an Adobe After Effects SDK include/library path;
- an AE plugin module or Windows `.aex` target;
- PiPL resource generation/compilation;
- `EffectMain` or an AE adapter source;
- SmartFX selectors, GPU device suites, or AE pixel-format registration;
- installation/package rules for the final plugin.

Therefore this branch's root build is a core-only build, not a native AE plugin build.

## 3. Actual core contract

`Image.h` defines float RGBA pixels and documents the internal format as linear-light premultiplied RGBA. `Engine.h` defines a stateless-looking engine interface with a render context (time, frame, render scale, seed), and requires every destination pixel to be written. `Pipeline.cpp`:
- validates source/destination dimensions;
- copies source into a working image;
- invokes enabled engines sequentially;
- composites each pass using Mix or premultiplied SourceOver;
- moves the final image to destination.

The current pipeline allocates/copies full-frame `Image` objects for each render and each pass. It does not yet expose ROI, tile bounds, cancellation/progress, render-format adapters, scratch-memory reuse, or an AE host scheduler contract. Those are gaps to resolve before production use, not proof of a defect in an AE adapter (none is present here).

## 4. InkMixer / Retratone status in this branch

A recursive tree inspection of the complete `XAO/` subtree and the core source tree did not find an integrated XAO InkMixer source directory or Retratone engine source. The tree contains reference Halftone sources and AEX/decompilation artifacts, but no corresponding production XAO InkMixer engine files in this branch snapshot.

Prior-session notes list InkMixer ZIP packages in the user's Library. Those packages are not automatically equivalent to committed branch source. They must be inspected and reconciled against this branch before any claim of integration. This pass does not say the Library packages do not exist; it says they are not present in the audited branch tree.

## 5. Tests and verification boundary

The root CMake declares one test target, `xao_core_tests`. Earlier reports mention additional local InkMixer test binaries, but the current repository tree does not establish that those test sources or targets are part of this branch. No clean CMake configure/build, test execution, AE SDK compile, Windows `.aex` packaging, or After Effects runtime test was performed in this pass.

## 6. Recommended implementation sequence

1. Reconcile the latest InkMixer/Screen/PlateState packages from the Library with the actual branch; identify exact source versions, dependencies, and test sources. Port only after comparison, not by blindly overlaying ZIPs.
2. Add the missing native AE adapter/build target around the existing core, preserving a single plugin entry point and the project's established PiPL/EffectMain contract.
3. Establish the shared pixel/alpha/ROI/cancellation/MFR boundary before adding more effect engines.
4. Integrate InkMixer/Halftone as a deterministic core engine, retaining the four independent plates and the 15 overlap regions, but keep preview and final render on the same compositing implementation.
5. Add CPU regression fixtures first; GPU acceleration remains optional and must preserve a dependable CPU path.
6. Only after the core and AE adapter build cleanly should HaloGlow and other audited engines be selectively integrated.

## Evidence boundary

Inspected live GitHub branch tree recursively (1,091 entries under `XAO/`), root CMake, `Engine.h`, `Image.h`, `Pipeline.h`, and `Pipeline.cpp`.  
Not inspected in this pass: all Library ZIP package contents, all test source bodies, a clean local build, AE SDK integration or runtime behavior.  
No source files changed; this is a status/reconciliation audit only.
