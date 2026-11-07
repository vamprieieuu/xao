# XAO Focused Audit — Halftone Akam Reference Project — Pass 18

Date: 2026-11-07

## Scope

Reviewed the supplied Halftone Akam project:
- README, `LICENSE` and `LICENSE.md`
- halftone mono and CMYK renderer
- dither, Risograph, Pixel Sort, Tiles and stack modules
- deterministic PRNG and scratch-buffer pool
- browser media/export architecture at the project level

## 1. Critical license conflict

The archive contains an MIT `LICENSE` naming Orvlyn, while the README and a separate `LICENSE.md` state “Personal Use Only” and prohibit commercial use and redistribution. The supplied project also identifies a different author in its README. This is a material provenance/license conflict.

**XAO decision:** do not copy, port, bundle, or adapt code from this folder until the rights holder clarifies the applicable license and provenance in writing. The findings below are behavior/algorithm observations only, not a code-reuse clearance.

## 2. Halftone algorithms

### Mono screen
- Constructs a rotated grid over the full image by transforming grid coordinates around the canvas center.
- Samples luminance at the cell center for very small cells, or averages luminance over the cell footprint for larger cells.
- Maps darkness to dot radius with a square-root transfer: `radius = halfCell * sqrt(1 - luminance)`.
- Supports circle, square, star and line-shaped marks.
- Batches vector path fills to reduce Canvas draw-call overhead.

### Four-channel CMYK screen
- Separates source RGB into approximate CMYK percentages.
- Renders four independent screens with fixed angles: Cyan 15°, Magenta 75°, Yellow 0°, Black 45°.
- Each plate gets its own dot screen and ink color; the composite uses Multiply overprinting.
- Per-plate separation export shares the same channel renderer, intended to keep the plates consistent with the composite.
- This is a useful basic multi-angle screen reference, but it is not a full ICC-aware press color-management or modern print-prepress system.

## 3. Dither and color separation concepts

- Dither module includes ordered Bayer 2×2/4×4/8×8 and Floyd–Steinberg diffusion with optional serpentine traversal.
- Supports chunky pixel scaling, multiple limited palettes and a modulation field.
- Risograph uses 2–3 spot-color layers, luminance bands or RGB-based layer amounts, per-layer screen/grain and seeded misregistration offsets, then Multiply compositing.
- The PRNG is Mulberry32; its documented contract is stable output for a stable seed, which is a good deterministic-randomness concept for XAO.
- Effect stack caches intermediate stages by signatures and reuses scratch buffers keyed by pipeline slot.

## 4. Additional algorithms

- Pixel Sort supports full-line, threshold interval, edge-boundary and seeded-random interval sorting; sort keys include brightness, hue, saturation or individual RGB channels.
- Tiles packs a regular grid into multi-span rectangles, optionally partially shuffles tile sources, rotates square tiles, adds jitter and draws gaps.
- The Tiles implementation writes output alpha as 255, so it is opaque-output oriented and would need alpha-aware redesign in XAO.
- Scratch buffer pooling is capped at ten buffers to avoid repeated canvas allocation and browser memory pressure. This is a useful memory-management concept, but the shared mutable browser pool is not an AE MFR-safe cache design.

## 5. Important limitations for XAO

1. **CMYK is approximate RGB math:** the RGB→CMYK conversion is a simple formula and does not use ICC profiles, ink limits, dot gain curves or device-specific calibration.
2. **Fixed screen angles:** useful defaults, but XAO should derive any angle controls from the visual references and avoid claiming calibrated moiré-free print output without testing.
3. **Alpha:** several raster paths fill a paper/background and produce opaque results; the Tiles code explicitly writes alpha 255. XAO needs consistent source-alpha preservation and explicit paper/background composition.
4. **Seeded randomness:** use the concept, but key all random choices by stable layer/cell/engine identity and AE time where animation is intended; avoid a mutable shared random sequence across concurrent renders.
5. **Cache signatures:** useful for avoiding redundant computation, but XAO cache keys must include every parameter, source identity/version, dimensions, pixel format, render scale and time-dependent input. Cache storage must be thread-safe and bounded.
6. **Canvas and p5 rendering:** browser APIs, canvas pooling, DOM, media playback and export workers are not native AE implementation dependencies.
7. **Vector/raster parity:** sharing geometry functions between raster and SVG is a good concept; XAO should define a common geometry representation if vector export is ever needed.

## 6. XAO decisions

- Keep the visual concepts of rotated AM screens, separate channel angles, multiply overprint, multi-ink registration, seeded misregistration, and multi-span tile layouts as reference candidates.
- Rebuild independently in native C++ only after resolving the licensing conflict for any close adaptation; algorithm concepts alone do not establish a right to copy the implementation.
- Preserve alpha, use explicit color-management contracts, and validate all output against the user's reference images.
- Treat Tile/Mosaic as a possible distinct engine or mode, not a hidden variation of Halftone.
- No separate Dither Majid Lines effect is included. A line-shaped mark remains a halftone shape option and is not that excluded effect.

## 7. Review status

This is a focused source-level review of the listed Akam modules and license documents. It does not review every UI/media/test file in this 63-file folder, and it does not constitute a runtime test or permission to reuse the source.
