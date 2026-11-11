# XAO — Dither Authentic Palettes & Retratone Ink/Halftone Direction
Date: 2026-11-10
Branch: xao/recovery-baseline-2026-11-10
Status: requirements clarification and recovered-reference findings; no engine source changed.

## 1. User's explicit Dither requirements

Dither must use genuine, correctly implemented dithering algorithms. Do not add random/noise perturbations and label them as established algorithms. Every algorithm entry must correspond to its actual mathematical method and pass algorithm-specific tests.

Minimum algorithm families to distinguish:
- Ordered threshold matrices (e.g. Bayer at multiple matrix sizes; clustered-dot matrices where sourced).
- True error diffusion with propagated quantization error and documented kernels (e.g. Floyd–Steinberg, Jarvis–Judice–Ninke, Stucki, Atkinson, Burkes, Sierra variants, Stevenson–Arce), including serpentine traversal where supported.
- Blue-noise/stochastic thresholding only where it is a real blue-noise method with a documented distribution/threshold texture; ordinary white noise/hash jitter must not be mislabeled blue noise.
- Any additional named methods must be individually verified against their canonical matrix/kernel or reference implementation.

Important source-review finding: the Halftone Dean project labels a mode “Floyd” but its implementation uses seeded hash-noise threshold perturbation, not Floyd–Steinberg error propagation. XAO must not reproduce that mismatch. Halftone Studio's audit records a much broader algorithm list (including the actual error-diffusion kernels above), but its source license is not confirmed; use behavior/algorithm references only until rights are resolved.

The XAO OFX Bayer file currently present in XAO/dither/dither ofx [open source]/dither.cpp is a limited 4x4 Bayer + five-palette implementation, not the full Dither engine. It also forces RGBA alpha to full opacity and disables tile support because it computes a whole-frame grid. It must not be treated as production-complete or copied unchanged.

## 2. Fifteen named palettes — provenance and classification

The earlier conversation recorded this requested 15-entry palette shortlist:
1. DMG Classic
2. DMG Gambatte
3. Pocket
4. PocketGB
5. Game Boy Light
6. Grayscale
7. BGB Classic
8. Game.com
9. Pokémon Classic
10. Neon Red
11. Neon Blue
12. Neon Yellow
13. Neon Green
14. Neon Pink
15. Golden
16. Wild

This recovered list actually contains 16 labels, not 15. Resolve the count by selecting exactly 15 after checking the original user's approved list and palette provenance. Do not silently drop one.

Critical provenance distinction:
- DMG Classic, Pocket, Game Boy Light and similar names refer to different Game Boy hardware/display or emulator palette conventions, but exact RGB values depend on the documented source/profile.
- Gambatte, BGB and PocketGB are emulator/profile-associated names, not official Nintendo hardware models.
- Game.com is a separate handheld device palette reference, not a Game Boy palette.
- Pokémon Classic and Neon/Golden/Wild labels may be community/game-inspired palette presets, not hardware-authentic palettes. They must be sourced and labeled honestly, not marketed as official hardware palettes.

Palette implementation contract:
- Each palette is a fixed, versioned, named set of exact RGB/RGBA swatches with provenance/source notes and a visual preview.
- No random generation or per-render palette mutation.
- Separate built-in reference palettes from user-created Custom Palette and from gradient/ink controls.
- Dither algorithm selection and palette selection are orthogonal: choose an algorithm, then choose a palette; algorithm must not change palette colors.
- Preserve alpha and define color-space/quantization behavior.
- Before shipping, verify exact 15-entry approved list and RGB values from authoritative hardware/emulator/game palette references.

## 3. Main Gradients archive — Retratone identification and role

The archive main gradients files.zip includes a Photoshop UXP plugin named Retratone v1.0.5 (sometimes referred to informally as Retro Tone). It is a Halftone/print-ink reference, not the simple three-stop Gradient Map source.

A previous XAO integration audit records these directly inspected files:
- index.html, index.js
- src/color-processing.js, src/apply-effects.js
- src/commands.js, src/svg-rendering.js
- src/auto-sort-inks.js, src/consolidate-inks.js
- src/lookup-tables.js, src/ui-primary.js
- preset JSON files and QuickStart PDF

The core JS is heavily obfuscated, so UI/function boundaries are visible but some exact equations remain unverified pending deobfuscation and input/output fixtures.

### 3.1 Ink visualization/control model

The UI has four distinct ink plates A/B/C/D, each represented by a separate circle, with explicit overlap regions:
AB, AC, BC, AD, BD, CD, ABC, ABD, BCD, ACD and ABCD, plus opaque-state paths and inactive indicators.

The plate controls include:
- Color Match and Tint modes
- Auto Sort Inks
- Ink Multiply / compositing
- Ink Fade
- Dust & Scratches
- Plate Drift
- Pattern family
- Pattern Roughness, Scale, Brightness and Contrast
- Pattern/plate offset angles

This is not a gradient ramp. It is an interactive multi-ink/plate mixer whose colors and overlap behavior determine the print result. XAO should preserve it as a dedicated Print Ink / Halftone plate system, while sharing reusable color-picker, swatch, and preset infrastructure with the Gradient editor where appropriate.

### 3.2 Thirteen Retratone pattern families

The inspected UI/spec records:
1. Print Dots
2. Positive Dots
3. Negative Dots
4. Lines
5. Broken Lines
6. Cross Lines
7. Waves
8. Broken Waves
9. Cross Waves
10. Fan Dots
11. Negative Fan Dots
12. Solid Colors
13. Smooth Colors

Do not collapse all of these into a generic Bayer screen. They are separate procedural pattern families with their own geometry/coverage behavior. The angle controls include observed values 0°, 22.5°, 30°, 45°, 60° and 90°, with scale, roughness, brightness and contrast. Exact parameter ranges and formula mappings must be extracted from the source/fixtures rather than guessed.

### 3.3 Ink composition and processing boundaries

The inspected entrypoint imports/calls:
- computeBlendRegions, applyRegionsToSVG, detectRegion, svgCoordsFromEvent, updateSVGColors
- computePlateOffsets
- compositeOver, mixModes, multiplyLayer
- generateBlendTableAndQuantizedMap
- getLayerAndProcessIntoBuffersClean
- applyEffects, autoSortInks, consolidateInks

These indicate separate subsystems for interactive overlap-region visualization, ink color updates, compositing, multiply, lookup generation, plate offsets, effects, auto-sorting and ink consolidation.

The SVG overlap diagram is meaningful: the overlap regions are separately modeled and refreshed when plate colors/positions/state change. XAO's preview should visualize actual plate combinations, not merely show four unrelated color swatches.

### 3.4 Known deeper findings from the earlier technical analysis

A previous project analysis recorded a Color Match lookup table of 16×16×16 = 4096 entries and a candidate coverage search space of 7^4 = 2401 before active-ink constraints. It recorded an ink-weight expression (A+B+C+D)/4, a score expression dR²+dG²+dB²+500(1-W), noncommutative ink compositing order, Direct and Multiply compositing paths, and a special Opaque Bottom Ink case. These are prior reverse-analysis findings, not yet independently revalidated in this pass; retain them as hypotheses/known analysis artifacts and rerun fixture tests before treating coefficients as final truth.

A separate earlier report records that Ink Fade at 100 does not erase all ink; it reduces coverage to approximately 90%. Do not assume conventional 0–100 opacity semantics without matching the reference behavior.

## 4. How this relates to XAO Gradient

Keep these systems distinct:
- Gradient engine/editor: multi-stop color ramp and/or spatial/layer-map gradient generation. The Gradient Designer audit documents up to 12 stops with per-stop color, alpha and position, repeat modes, reverse, cycle, insert/delete/even-spacing/reset, and color-bank/preset handling.
- Retratone Print Ink / Halftone: 1–4 independent ink plates, their colors, coverage, order, overlap, tint/color-match behavior, pattern screens, registration and compositing.
- Dither Palette: fixed named discrete color sets used by Dither quantization. This is not the same as Gradient stops or print ink plates.

These can share a native color model, color picker, swatches and preset storage where appropriate, but must not share one conflated UI/data model. Do not modify GradientStudio. Do not restart already-completed XAO Gradient work; inspect its actual latest source and preserve it.

## 5. Native XAO requirements

- Implement algorithms and pattern families as separate, truthful code paths.
- Keep Retratone's 13 pattern families distinct from Dither algorithms.
- Keep ink plates A/B/C/D independent with editable color, active state, coverage, order, offsets/registration and compositing.
- Preserve alpha, define premultiplication and working color space, support 8/16/32-bpc where validated.
- Stable image-space pattern origin and deterministic per-cell/plate random variation; no frame-to-frame flicker unless intentionally animated.
- Bounded buffers and MFR-safe render state; do not rely on mutable shared caches.
- Do not import Photoshop UXP runtime or browser DOM/Canvas into the AE plugin.
- Do not add paper layer/paper background/paper-surface simulation to the XAO Halftone engine, per the user's explicit exclusion.
- Do not include Dither Majid's standalone Lines effect. Retratone's own Lines/Broken Lines/Cross Lines are Halftone pattern families and are distinct.

## 6. Next research steps

1. Locate and re-read the original Main Gradients archive contents and prior conversation explanation for Retratone, including QuickStart, preset JSON and all obfuscated JS modules.
2. Recover the exact ink color, overlap visualization, Color Match, Tint, Auto Sort, Fade, Plate Drift and pattern control semantics using static analysis plus controlled before/after fixtures.
3. Recover the user's approved exact list of 15 Dither palettes and exact swatch values/provenance; reconcile the 16 labels in the recovered historical shortlist.
4. Audit Dither algorithms one by one against canonical matrices/kernels; add golden numerical tests for each.
5. Compare these results to the latest actual XAO native source and existing completed engines before integration. No rewrite or merge until the source-of-truth map is complete.

## 7. Validation statement

This document consolidates user requirements and previous audit findings. It does not claim new source code, new builds, or runtime tests. Obfuscated Retratone formulas and the final 15-palette list remain items for source/fixture verification.
