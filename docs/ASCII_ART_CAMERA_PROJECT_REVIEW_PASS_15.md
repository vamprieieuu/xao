# XAO Focused Audit — ASCII Art Camera Full Project Pass 15

Date: 2026-11-07

## Scope reviewed

Reviewed the supplied MIT-licensed ASCII Art Camera project beyond the previously inspected mapper/engine files:
- top-level CMake and dependency structure
- README and claimed feature/test coverage
- OpenCV frame conversion pipeline
- image/video file source and webcam capture
- latest-frame mailbox
- Qt painting/export path
- CLI path and Catch2 test target
- existing unit tests for luminance, color, glyph mapping and mailbox behavior

This is a focused review of the listed application/core paths, not a claim that every documentation, web-demo, CSS, asset, or UI line in the project has been audited. It is a desktop app, not an AE effect.

## 1. Useful algorithms and design concepts

- Core engine types are separated from OpenCV and Qt, allowing the mapper logic to be tested independently.
- The source frame is resized with `INTER_AREA` to a cell grid, giving each cell an area-averaged color rather than one point sample.
- The grid calculation compensates for non-square glyph cell dimensions to preserve source aspect ratio.
- The Edge mode runs Sobel X/Y on the reduced luminance image, calculates gradient magnitude and folds gradient direction into four glyph bins.
- Luminance and edge mapping are strategy objects; this is a useful way to keep multiple glyph-selection strategies independent.
- Optional detail enhancement uses Lab-L CLAHE followed by an unsharp mask.
- A single-slot latest-frame mailbox intentionally drops stale live frames instead of building latency; that is appropriate for live capture but not for deterministic offline AE rendering.
- The tests cover monotonic/bounded luminance, tone mapping, ramp inversion/fallback, color modes, emoji selection, four edge bins, weak-edge fallback and mailbox behavior.

## 2. Defects and constraints that matter to XAO

1. **Alpha is removed during enhancement:** `enhanceForDetail()` converts BGRA to BGR, discarding source alpha. The later pipeline also normalizes cells to BGR and the Qt export path creates an RGB image. This project is fundamentally opaque-output oriented; XAO must not inherit that behavior.
2. **The frame converter is 8-bit BGR-centric:** it normalizes the reduced frame to 8-bit BGR. There is no 16-bit/32-bit float/HDR path. XAO needs explicit AE 8/16/32-bit handling and should not use this pipeline as its pixel-format foundation.
3. **Edge detection is performed after downsampling:** this is fast and coherent for cell-level direction, but fine edges can disappear before Sobel. XAO should decide per engine whether edge analysis occurs before or after reduction and expose quality/performance choices only where useful.
4. **Sobel orientation is quantized to four bins:** it maps to `|`, `/`, `-`, and `\\`; it is a simple directional ASCII mode, not continuous orientation-aware glyph matching.
5. **Enhancement uses fixed parameters:** CLAHE clip limit 2.5, 8x8 tiles, and Gaussian sigma 2.0 are hard-coded. It also uses a function-static CLAHE object. XAO should make enhancement parameters explicit and keep render state per instance/request; do not carry mutable static processing objects into concurrent MFR paths without proof.
6. **Heart detection is a special demo feature:** it detects red/pink contours at a fixed 256-pixel working width and compares them with a hand-built heart contour. It is not a general object/gesture detector. Do not include this feature in XAO unless the user's reference material asks for it.
7. **Capture and latest-frame semantics are unsuitable for AE rendering:** camera/file threads, wall-clock sleeps, dropped-frame mailbox and frame-index seeking are for interactive preview. AE must render the exact requested time/frame, including out-of-order frame requests, with no capture thread or dropped-frame policy in the effect render path.
8. **File video timing assumes a single reported FPS:** it sleeps according to `CAP_PROP_FPS` and tracks frame indices. It does not use presentation timestamps/VFR timing. This is not an acceptable timing model for XAO animation or imported footage.
9. **Mailbox is intentionally lossy and close is terminal:** after `close()`, the mailbox is not designed to reopen for a new capture session. This is acceptable for a one-shot desktop source lifecycle, but should not be confused with a reusable AE render cache.
10. **Qt font selection is system-dependent:** `Cascadia Mono` plus Qt's monospace fallback does not guarantee identical glyph metrics or the user's supplied fonts on different systems.
11. **Build dependencies are heavy for XAO:** the app path requires OpenCV and the GUI requires Qt 6. The pure engine is header-only, but XAO should not introduce Qt or OpenCV as mandatory runtime dependencies into the native AE effect.
12. **Test count wording:** README advertises 21 unit tests, but the supplied Catch2 test target lists four test translation units. Catch2 may discover multiple individual test cases, but the stated count should be treated as a project README claim, not a validated pass count from this audit.

## 3. XAO decisions

- Retain the conceptual strategy pattern for independent glyph-selection engines.
- Retain area-averaged cell sampling as an optional low-cost ASCII mode; also implement higher-quality sampling/analysis modes where the references demand it.
- Rebuild edge direction analysis in the shared core with explicit color-space, scale, bounds and alpha behavior.
- Treat enhancement as a separate preprocessing stage with explicit parameters and deterministic behavior.
- Do not port webcam capture, Qt UI, CLI, frame dropping, wall-clock playback, heart detection or OpenCV/Qt runtime dependencies into the AE plugin.
- XAO render must be a pure function of source pixels, parameters and requested AE time, with frame-order independence and MFR-safe state.
- Build a proper native text rasterization/shaping pipeline rather than relying on system monospace fallback.

## 4. Audit status

This pass covers the identified application/core files and their role in the project. It does not certify every file in the ASCII Art Camera folder, does not build the project, and does not test any code in After Effects. Remaining ASCII references and other XAO folders still require review.
