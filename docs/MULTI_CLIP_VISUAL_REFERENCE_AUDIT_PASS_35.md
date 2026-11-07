# XAO Multi-Clip Visual Reference Audit — Pass 35
Date: 2026-11-07
Scope: Eight supplied MAIN IDEAS clips, reviewed as a grouped visual batch using timestamped frame samples across each clip. This pass records visual structure and temporal evidence; it does not claim pixel-perfect reverse engineering of proprietary effects.

## 1. ASCII CGO — 234 frames, 466×474, 4.742 s, 49.35 fps average
Reference: ScreenRecording_11-07-2026 18-04-37_1.mov
- Split comparison shows a source portrait on the left and a dark, high-density ASCII/glyph rendering on the right.
- Glyphs are arranged on a fine regular grid, with clear horizontal banding and a strong dark-to-warm tonal field.
- The face and clothing are reconstructed from a mixture of dense glyph marks and bright orange/white highlights.
- Highlight regions are localized and appear to pulse or vary in intensity; not every glyph glows.
- The subject changes pose through the clip, and the rendered glyph field follows the source image.
- User requirement from the accompanying note: glyphs/numbers/symbols should change randomly and quickly; glow should be assignable to selected glyphs/regions, with fixed or randomized selection and editable colors.

XAO decomposition:
1. Source-to-cell tone/color analysis.
2. Glyph identity selection (fixed, seeded-random, animated-random).
3. Per-glyph color sampling or palette override.
4. Independent glow eligibility mask (manual/seeded random/brightness/edge).
5. Glow extraction and multi-scale composite, separate from glyph fill.
6. Stable grid anchoring and deterministic time-based glyph changes.

Do not make glyph identity and glow selection share the same random stream; otherwise changing glow density will reshuffle the text.

## 2. ASCII Ghost — 248 frames, 656×354, 5.217 s, 47.55 fps average
Reference: ScreenRecording_11-07-2026 18-05-32_1.mov
- Source is on the left; output is a dense glyph field on the right with a strong red/warm tint.
- Glyphs appear small and numerous, with mixed characters, numbers and symbol-like marks.
- The field follows source luminance and color regions; localized bright glyphs stand out against dark areas.
- Temporal changes are visible in the subject and the glyph/color pattern. The reference reads as image-colored glyphs rather than one flat foreground ink.
- Accompanying user note explicitly requests each glyph to sample the color from its corresponding source-image region and adds a Rays component.

XAO decomposition:
1. Per-cell average/weighted source color, not one global glyph color.
2. Separate foreground glyph color from background fill.
3. Optional source-color sampling modes: cell average, center sample, edge-weighted, palette quantized.
4. Rays are a separate engine fed by selected glyph/highlight masks; no ray geometry should be baked into ASCII.
5. Preserve alpha and avoid forcing a full opaque background unless the user enables it.

## 3. Golden Glow Halftone — 276 frames, 214×386, 5.667 s, 48.71 fps average
Reference: ScreenRecording_11-07-2026 18-06-24_1.mov
- Warm orange/gold dot screen on a nearly black field.
- Dot density and brightness describe the subject silhouette and highlight regions; the dots themselves carry strong luminous edges.
- Glow is visually integrated with the halftone result, but architecturally should remain a separate glow pass within the same Halftone engine.
- The reference includes large dark negative-space regions, so the effect must not fill every cell.
- The subject moves/changes pose over the clip; the halftone representation follows the image.

XAO decomposition:
1. Halftone coverage from source tone/threshold curve.
2. Golden ink palette and optional highlight-only color ramp.
3. Dot geometry with antialiased coverage and dot-gain control.
4. Separate glow mask derived from dot luminance/coverage.
5. Glow radius, threshold, exposure, color and blend mode remain controls of the unified Halftone look.
6. Background policy must support black, source, transparent or custom color.

## 4. Liquid ASCII — 200 frames, 304×374, 3.883 s, 51.50 fps average
Reference: ScreenRecording_11-07-2026 18-06-56_1.mov
- The output is a stack of rounded horizontal rectangular tiles, not a conventional square ASCII grid.
- Tiles have variable widths and a consistent but adjustable row height; thin dark gaps separate them.
- Each tile has its own background color sampled from the corresponding source region, producing a mosaic of image-colored capsules.
- Tiny glyphs/letters appear inside the tiles; selected tiles use brighter accent colors.
- The layout remains spatially structured while source subject movement changes sampled color/content. It is not a freely drifting field of independent boxes.
- User note asks for independent rectangle width/height controls, random Japanese/other scripts or words, ability to hide words, change font/size/content and text color.

XAO decomposition:
1. Rectangular tile grid with separate X/Y dimensions, corner radius and gap.
2. Optional controlled width variation, with row alignment and deterministic placement.
3. Per-tile source color sampling.
4. Text/glyph content layer with Fixed, Random Glyph, Random Word and Unicode-set modes.
5. Text visibility, font, scale, baseline, alignment, foreground color and per-tile contrast.
6. Keep the tile geometry independent from the glyph animation; text changes must not cause boxes to jump.

## 5. PixelDitherGo — 145 frames, 310×374, 2.948 s, 49.18 fps average
Reference: ScreenRecording_11-07-2026 18-09-47_1.mov
- Output uses a highly restricted black and fluorescent yellow-green palette.
- A regular fine lattice is visible underneath larger block-like tonal clusters.
- Large image regions are built from coarse square/block clusters, while fine dots or cross-like marks remain visible within and around them.
- The structure follows the face silhouette and facial details; it is not simply a uniform Bayer screen or a standard single-scale pixelation.
- Across the sampled timeline, the overall grid and major clusters remain spatially stable while the source changes subtly; no clear evidence yet proves a travelling noise field or feedback animation.
- User's note says they cannot describe the effect and explicitly asks for close analysis to understand its formation and motion.

Current working model (still a hypothesis):
- A multi-resolution pixel-dither composition: coarse tonal/block map + fine ordered or clustered pattern + local detail/edge preservation.
- Separate coarse and fine grid scales, each with independent thresholds and coverage.
- Palette mapping and edge/detail protection are likely central to preserving recognizable facial structure.
- Need deeper per-frame cell tracking before selecting the exact temporal mechanism; do not claim the effect is fully reverse-engineered yet.

XAO candidate controls:
- Coarse Cell Size, Fine Cell Size, Scale Ratio.
- Pattern Family, Pattern Angle/Phase, Contrast, Threshold, Palette.
- Coarse/Fine Mix, Edge Preserve, Detail Strength, Cluster Size.
- Optional seeded temporal variation; default static deterministic pattern.

## 6. Rainbow ASCII — 205 frames, 298×392, 4.083 s, 50.20 fps average
Reference: ScreenRecording_11-07-2026 18-10-16_1.mov
- Dark, dense ASCII-like image with multicolor speckles and colored highlight regions.
- Visible color behavior is not a simple rainbow gradient applied uniformly over glyphs; color is spatially selective and appears tied to image features/highlights.
- Bright orange/yellow and green/purple regions coexist against dark background areas.
- The source image changes, and the colored regions track its features.
- User note requests the combined concept of ASCII + Glow + Rays, with unusual multicolor glyphs, multicolor glow and multicolor rays.

XAO decomposition:
1. ASCII glyph layer with source/palette color sampling.
2. Multi-band or per-cell color assignment (source, gradient, palette, randomized palette).
3. Glow engine with per-channel/per-region tint control.
4. Rays engine fed by selected bright glyph/cell mask, with independent color map.
5. Explicit engine stack order and blend modes; never bake glow/rays into the glyph atlas.

## 7. Mosaic ASCII — 195 frames, 296×368, 3.833 s, 50.87 fps average
Reference: ScreenRecording_11-07-2026 18-10-49_1.mov
- Output combines a coarse square mosaic with a finer layer of small glyphs/characters.
- Cell scale varies across regions; larger blocks define the broad tonal structure, while smaller marks add detail.
- A strong bright diagonal/light region and bloom-like halo appear in the output.
- Overall saturation is subdued, with cool gray/blue/violet tones and isolated highlights.
- The output remains aligned to the source silhouette while brightness distribution changes through the clip.
- User note requests a Mosaic layer + Glow + low saturation, with independently varying large and small glyphs/characters and detailed control.

XAO decomposition:
1. Coarse mosaic layer and fine glyph layer must be independently switchable and sized.
2. Per-layer source sampling and tone curves.
3. Separate glyph size classes with deterministic distribution and independent palette controls.
4. Glow extracted from selected bright cells, not applied indiscriminately to all pixels.
5. Saturation and color grading after explicit layer compositing.

## 8. Threshold ASCII — 145 frames, 294×376, 2.900 s, 50 fps
Reference: ScreenRecording_11-07-2026 18-11-20_1.mov
- Monochrome output made from horizontal bars/short line segments and block-like dark/light regions.
- Line length and density vary with image tone, producing a recognizable silhouette and facial detail.
- The grid is row-oriented: many short horizontal marks align to common rows; some areas become broad dark blocks.
- The sampled frames show the subject moving and the threshold pattern updating with the source. The overall row-grid logic remains stable.
- User note requests a threshold effect with randomly moving lines, rectangles and squares and extensive geometry/color controls.

XAO decomposition:
1. Row/cell luminance analysis and threshold bands.
2. Horizontal segment length/occupancy mapped from tone.
3. Optional rectangular and square primitives in separate geometry layers.
4. Deterministic per-segment movement/variation with absolute AE time.
5. Separate control over segment width, row spacing, density, contrast, direction, speed, seed and palette.
6. Keep this as a user-requested Threshold/Pattern engine, not as the excluded Dither Majid standalone Lines effect.

## 9. Shared timing and render conclusions
- These clips are not all 30 or 60 fps. Their decoded average frame rates range from about 47.55 to 51.50 fps, with non-integer ratios in several files. The source clips are likely variable/irregular presentation-timestamp sequences.
- XAO animation must use AE's absolute time and time scale, not assume 30/60 fps and not increment mutable state once per render call.
- For all animated randomness, derive values from stable hashes of seed + cell/layer ID + quantized absolute time. Add a user-controlled hold/rate parameter to determine how often the random state changes.
- The source subject movement is distinct from effect animation. Render should follow the input frame while any additional glyph/shape motion is independently controllable.
- Keep comparison dividers, pause buttons and UI overlays out of the effect design; they belong to the recording interface.
- The review used timestamped contact-sheet samples (roughly 0.3–0.6 s spacing) plus clip metadata and accompanying user notes. It is a broad grouped visual pass, not a claim that every frame was manually inspected.

## 10. Consolidated XAO feature architecture decisions
- ASCII CGO, ASCII Ghost, Rainbow ASCII and Mosaic ASCII should be presets/recipes over shared ASCII, Glow, Rays and Mosaic engines—not four disconnected renderers.
- Golden Glow Halftone remains a Halftone look with an integrated glow sub-pass, not a separate standalone effect.
- Liquid ASCII is a distinct tile/typography mode, sharing font shaping and source sampling with Typeset/ASCII but not forced into the standard square glyph grid.
- PixelDitherGo remains a dedicated multi-scale dither candidate until its exact pattern construction is verified.
- Threshold ASCII is a geometry/threshold engine with row segments and blocks; it is not the excluded Dither Majid Lines effect.
- Every recipe must expose its component engines in a common stack, while preserving a one-click preset/recipe option.
- All renderers remain CPU-capable, deterministic, alpha-correct, MFR-safe, and driven by actual AE time.
