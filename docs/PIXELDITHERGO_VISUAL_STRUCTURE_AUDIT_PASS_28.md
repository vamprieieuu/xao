# PixelDitherGo Visual Reference — First Structural Pass (Pass 28)

Date: 2026-11-07

## 1. Source and temporal sampling

Reviewed the supplied `MAIN IDEAS/Pixeldithergo/ScreenRecording_11-07-2026 18-09-47_1.mov` and its accompanying RTF note.

- Video dimensions: 310 × 374.
- Duration: approximately 2.948 seconds.
- 145 frames reported by the container.
- Nominal frame rate: 60 fps; average frame rate: 3000/61 (~49.18 fps). Do not assume constant 60 fps; use presentation timestamps.
- User's note explicitly says the effect is difficult to describe and asks for close analysis of how it forms and moves, square by square.

The screen recording shows a vertical before/after comparison: source portrait on the left, stylized result on the right, with a divider/handle between them. This comparison UI must not be mistaken for part of the effect.

## 2. Visible result — structural observations

The processed half is not a conventional single-scale Bayer dither. It appears to combine several spatial scales and mark types:

1. **Large block regions:** irregular rectangular/square colour masses preserve the broad luminance structure of the portrait.
2. **Fine lattice:** dense, repeated micro-grid lines appear over large areas, with local changes in spacing/density.
3. **Micro-dot / cross-like texture:** dark regions contain small repeated bright marks, while some brighter regions show a fine grid or hatch-like texture.
4. **Hard tonal segmentation:** the visible palette is strongly restricted to black/dark green, mid green and bright yellow-green. Large areas switch between near-solid fills and patterned regions.
5. **Mixed cell scale:** large blocks and fine lattice coexist. A single global cell size would not reproduce this appearance.
6. **Local transitions:** the boundaries between solid blocks and micro-patterned regions are irregular and appear tied to the image's local tone/structure, rather than a uniform overlay covering every cell equally.
7. **Thin structural borders:** some larger rectangular regions have visible dark/bright outlines or seams; this is distinct from the fine internal lattice.

These are visual observations from the supplied recording, not a recovered mathematical algorithm. The source archive does not contain the original PixelDitherGo implementation or its control values.

## 3. Motion / temporal behavior: what can and cannot yet be claimed

The sampled frames show the stylized pattern changing over the short clip while the source portrait remains the comparison reference. The current evidence is insufficient to claim whether the movement is:
- animated cell-size/threshold modulation,
- a travelling pattern/noise field,
- evolving local masks,
- temporal feedback,
- or a combination.

A full native-timestamp frame-by-frame analysis is still required to distinguish these possibilities. In particular, compare the same output coordinates across every frame and track:
- cell boundary positions,
- local pattern frequency,
- colour/threshold transitions,
- whether the fine lattice is fixed in image coordinates or screen coordinates,
- whether large blocks move, resize, or merely change fill,
- whether changes correlate with source motion or with an independent animation phase.

Do not implement it as a generic Bayer dither or random noise overlay based only on this first pass.

## 4. Proposed XAO engine model

Treat this look as a candidate **Multi-Scale Pixel-Dither / Structured Grid** mode inside the Dither/Array family, pending further analysis:

- A coarse block map for broad tonal regions.
- One or more fine pattern maps (grid, micro-dot, cross/hatch) selected by local luminance/contrast/edge features.
- Independent coarse and fine scale controls.
- Local pattern density/coverage and threshold range.
- Palette/ink colours with per-level mapping.
- Optional block borders/seams.
- Deterministic animation phase driven by absolute AE time, not accumulated frame delta.
- Separate controls for static structure and animated modulation.

This is a working architecture hypothesis, not a final engine specification.

## 5. Smart Object Tracker integration

When the Smart Object Tracker is available, its soft mask can gate both the coarse block map and fine pattern maps. This would allow the PixelDitherGo-style structure to appear only on a selected moving subject. The mask must be sampled in source coordinates and remain stable under time remapping and MFR. AI tracking is a separate analysis stage; no model inference belongs in the Dither render callback.

## 6. Next visual-analysis actions

- Decode all 145 frames at original timestamps, not only fixed-FPS samples.
- Build contact sheets for the output half only and inspect representative transitions at full resolution.
- Track candidate cell corners and local pattern frequency across time.
- Compare source and output halves using a fixed divider crop.
- Reconcile any inferred parameter behavior with the user's own description before treating it as a confirmed requirement.

## 7. Status and constraints

This is the first structural pass, not a completed frame-by-frame reverse engineering. No exact formula, parameter range, or final implementation has been claimed. The separate Dither Majid **Lines** effect remains excluded; the grid/lattice observations here concern this user's independent PixelDitherGo reference.
