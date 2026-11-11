# XAO ASCII — Full Reference, Source, and Implementation Audit
Date: 2026-11-11
Branch: `xao/recovery-baseline-2026-11-10`
Scope: the supplied `XAO.zip`, `fonts.zip`, the current branch's actual ASCII implementation, the Main Ideas screen recordings, Crates ASCII and S1 ASCII reference binaries/decompilations, and the supplied open-source ASCII projects.

## 1. Evidence and audit method

The original `XAO.zip` was materialized and extracted. It contains 996 archive entries. The nine Main Ideas screen recordings were inspected by temporal sampling at 2 frames/second, with the original frame dimensions, durations and declared frame counts checked using ffprobe. Together they contain 2,514 frames:
- Ascii CGO: 466×474, 60 fps, 234 frames, 4.742 s.
- Ascii Ghost: 656×354, 60 fps, 248 frames, 5.217 s.
- Golden Glow Halftone: 214×386, 60 fps, 276 frames, 5.667 s.
- Liquid ASCII: 304×374, 60 fps, 200 frames, 3.883 s.
- Rainbow ASCII: 298×392, 60 fps, 205 frames, 4.083 s.
- Threshold ASCII: 294×376, 60 fps, 145 frames, 2.900 s.
- PixelDitherGo: 310×374, 60 fps, 145 frames, 2.948 s.
- Array settings walkthrough: 828×1792, 240 fps, 866 frames, 19.862 s.
- Mosaic ASCII: 296×368, 60 fps, 195 frames, 3.833 s.

The initial temporal contact sheets sampled the nine recordings at 2 frames/second. A supplementary pass sampled the eight short effect clips at 5 frames/second (166 frames total) and rechecked the Array settings walkthrough at 2 frames/second (40 frames). These samples improve visibility of changing glyph populations, color/glow movement and UI states, but are still temporal samples rather than an inspection of every encoded frame. Contact sheets are evidence for visible structure and motion; they do not prove proprietary shader equations or exact undisclosed algorithms. The findings below distinguish directly visible behavior from implementation inference.

## 2. Main Ideas visual findings

### 2.1 ASCII CGO
**Visible:** split Before/After comparison; the effect side is a dense, stable row/cell field of letters, numbers and symbols. The subject silhouette is preserved by glyph density. A selective warm orange/red emission appears on only a subset of glyphs, with brighter glowing clusters around the subject and a separate soft halo/outline near the silhouette. The glyph population changes over time while the overall subject and grid remain registered.

**XAO implementation model:** independent glyph mapping and emission-mask passes. Glyph choice and random state must be cell-addressed and deterministic. Glow selection must support an explicit glyph/token selection, random selection, fixed spatial regions, and a separate subject-edge/halo mask. Do not apply one uniform glow to every character.

### 2.2 ASCII Ghost
**Visible:** dense random glyph field with the source image's spatial color structure retained in the characters. A diagonal/radial ray contribution crosses the glyph field; the right/lower region is visibly more illuminated in the supplied sample. Glyph/token changes are visible over time.

**XAO implementation model:** source-color sampling is per cell/glyph, while rays are a separate pass sharing the same source and mask. Ray controls should include origin, direction, spread, decay, intensity and color. ASCII and Rays must be independently switchable.

### 2.3 Liquid ASCII
**Visible:** not a conventional square glyph grid. The image is partitioned into rows of rounded rectangular/pill-like message tiles, with variable widths and possible variable row heights. Each tile contains short Japanese-looking character/word sequences. Tile backgrounds inherit local source colors (cyan/blue, beige/brown, red/orange); glyphs vary/change over time.

**XAO implementation model:** a distinct variable-width text-tile layout mode. It needs row partitioning, tile width/height ranges, spacing, corner radius, text alignment/fit, word visibility, token/charset selection and deterministic per-tile animation. Do not implement this look as ordinary ASCII with rounded corners added afterward.

### 2.4 Mosaic ASCII
**Visible:** two distinct spatial scales. Coarse square mosaic blocks establish the large tonal/color structure; a much finer layer of letters, numbers and symbols adds texture. Some glyphs are visibly larger than others. The effect has selective pale/violet glow and reduced saturation in darker regions.

**XAO implementation model:** separate coarse mosaic and fine glyph passes with independent cell sizes, visibility, source sampling, color and compositing. Large/small glyph variation must be deliberate and controllable. Do not collapse this into a single uniform ASCII grid.

### 2.5 Rainbow ASCII
**Visible:** dense glyph field over a predominantly dark/black base. Color is localized and spatially tied to the source: violet, blue, cyan, pale/white and occasional warm accents coexist. The result is not a smooth full-frame rainbow tint. Bright source details create brighter, denser, more luminous glyph clusters.

**XAO implementation model:** cell-local palette selection driven by source color/tone, plus an independent emission mask for selective glow. A global rainbow overlay is not an acceptable reconstruction.

### 2.6 Threshold ASCII
**Visible:** aligned horizontal rows/segments with varying lengths and density; light/dark bands encode source structure. Some point-like or block-like details accompany the bars. The look is monochrome in the supplied sample and remains registered to the source.

**XAO implementation model:** a dedicated threshold/segment renderer with row spacing, segment length/width, threshold, contrast/gamma and optional block/point detail. It is not a generic character-ramp mode and must not be confused with the separately excluded MAJEED Lines effect.

### 2.7 PixelDitherGo
**Visible:** high-contrast yellow/lime against near-black, with a coarse square/block silhouette and a much finer lattice/line structure over it. The coarse and fine scales remain visibly distinct.

**XAO implementation model:** separate coarse quantization and fine micro-pattern passes. Preserve the independent scales; do not reduce it to a simple line screen.

### 2.8 Golden Glow Halftone
**Visible:** separate Halftone look, not ASCII. Gold/orange dots define the subject on a dark background, with bright cores and softer luminous rims. Glow follows the dot field.

**XAO boundary:** retain as a future Halftone+Glow preset/engine combination. Do not mix this into the default ASCII renderer.

### 2.9 Array settings walkthrough
**Visible UI concepts:** multiple shape levels/slots with per-level colors and add/remove controls; separate edge-shape slots; a broad shape library (rings/arcs, crosses, stars, directional marks, stripes, checker patterns, stepped blocks). Color modes include Preserve, Sample Source, Override, Palette and Gradient. Other observed controls include All Sizes, Cell Size, Rotation Jitter, Scale Jitter, Detailing, Clump, Amount, Chaos multiplier, Clump By, Invert, Empty Below, Contrast and Gamma. Blend choices include Normal, Darken, Multiply, Color Burn, Lighten, Screen, Plus Lighter, Color Dodge, Overlay, Soft Light, Hard Light, Difference, Exclusion, Hue, Saturation, Color and Luminosity.

**XAO boundary:** this is a separate shape-field reference. It is not part of the ASCII engine implementation.

## 3. Crates ASCII extraction — exact recovered metadata

The supplied `CratesASCII.aex` contains an embedded JSON payload beginning at byte offset 860,240. The full 15,008-byte payload was extracted through its terminating NUL and parsed successfully. It contains a data-driven parameter schema and exact baseline values for the plugin presets.

### 3.1 Character-set choices recovered from the parameter schema
1. Special Characters and Letters
2. Special Characters and Numbers
3. Classic Typewriter
4. Japanese Characters
5. Binary
6. Minimal Punk
7. X's
8. Bubble Growth
9. Stars
10. Diamonds
11. Dots
12. Circuits 1
13. Circuits 2
14. Alien Font
15. Bars

### 3.2 Presets recovered from the embedded preset table
The binary's embedded table includes: Default, Alien Signal, Circles and Dots, Classic, Corrupted, Crossword, Diamonds, Matrix, Motherboard and Punk Shapes. The user-facing requested labels include Diamond and Pink Shapes; XAO should retain those familiar labels while documenting the source labels (Diamonds and Punk Shapes) in the provenance map. The pink-tinted preset is the source's Punk Shapes entry.

The following exact settings were recovered from the embedded JSON (values are the source plugin's own normalized/encoded values, not yet XAO control defaults):

| Preset | Charset index | Character size | Character margin | Cell margin | Tint strength | Random shuffle | Random speed | Random color | X flip |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| Default | 0 | 35 | 0 | 0 | 0 | 5 | 10 | 0 | 0 |
| Alien Signal | 13 | 70 | 0 | 0 | 100 | 5 | 10 | 25 | 50 |
| Circles and Dots | 7 | 25 | 100 | 15 | 0 | 15 | 10 | 0 | 0 |
| Classic | 1 | 25 | 8 | 0 | 100 | 5 | 10 | 0 | 0 |
| Corrupted | 1 | 50 | 0 | 0 | 0 | 15 | 25 | 25 | 50 |
| Crossword | 2 | 50 | 13 | 0 | 100 | 0 | 10 | 0 | 0 |
| Diamonds | 9 | 35 | 120 | 0 | 0 | 15 | 10 | 0 | 0 |
| Matrix | 4 | 25 | 0 | 0 | 100 | 30 | 50 | 0 | 0 |
| Motherboard | 11 | 65 | 0 | 0 | 0 | 25 | 100 | 15 | 50 |
| Punk Shapes | 5 | 35 | 95 | 0 | 100 | 15 | 10 | 0 | 0 |

Other recovered Crates controls include Characters Based On (Red, Green, Blue, Luma), Reverse Order, Anti-Aliasing, Tint Color, Uniform Luma, Invert Luma, Invert Threshold, Smooth Shading, Background Color and Blend With Original. The Random group includes Random Shuffle, Random Speed, Random Color Amount and X Flip Threshold.

This metadata is valuable for recreating the preset baselines and control relationships. It does not disclose the complete visual shader implementation or the actual glyph atlas assets.

## 4. S1 ASCII extraction

The supplied S1 AEX contains the following exact UI choice strings:

### 4.1 Character sets
- Classic
- Minimal
- Detailed
- Bourke
- Braille
- Katakana
- Blocks
- Quadrants
- Box Drawing

### 4.2 Color modes and palettes
Color modes:
- Monochrome
- Source Color
- Palette

Palette preset names:
- Monitor Glow
- Game Boy DMG
- Oil 6
- Retrotronic
- Gothic Bit
- Curiosities
- CGA Palette 1
- CGA Palette 1 Bright
- CGA Palette 0 Bright

Additional literal controls include Palette Mapping (Tonal / Original), Palette Color Strength, and Blend Mode (Normal, Multiply, Screen, Overlay, Soft Light, Difference, Add).

The decompilation confirms a dedicated GlyphAtlas, character-set identity tables, per-glyph density ramps, source-cell accumulation and a BackdropPalette that sorts color stops and evaluates tonal palette colors. The exact RGB stop values for every named preset have **not** been conclusively recovered in this pass; they must not be invented. The next binary trace must recover the palette stop tables or verify the colors from the original plugin's rendered UI/output before XAO copies the exact palette values.

## 5. Open-source project reuse map

### 5.1 ASCII Art main — MIT
The source includes a clear separation between per-cell sampling, luminance/tone mapping and glyph mapping. Its mapper design supports a normal luminance ramp, an edge-directional strategy (four directional marks selected from Sobel gradient magnitude/orientation), and an optional color-category mapper. The MIT license is present. The reusable parts are the small, independent mapping/tone utilities and the strategy separation; do not import its Qt camera/UI shell.

Required attribution if source portions are ported: preserve the upstream MIT copyright and license notice.

### 5.2 AuraASCII — MIT
The renderer is explicitly two-pass: edge analysis into an intermediate target, then ASCII composition using source, edge data and a glyph atlas. The atlas is built from a selected charset/font and cached until charset/font changes. The WebGL/Three.js runtime is not a native AE renderer; port the pipeline separation and atlas caching concepts to a CPU-first native implementation. The MIT license is present.

### 5.3 Morphing ASCII Shader — MIT
The source includes an ASCII glyph atlas, Sobel edge analysis, glyph transition/morph controls, temporal memory grid and an ink-bleed post-process. InkBleed uses a precomputed 64-sample Vogel-disk kernel. The project also documents blur, brightness, cell size, color variation, contrast, edge threshold, glyph blend/scale, noise and memory controls. Its feedback-style previous-frame memory must not be transplanted directly into AE SmartFX: XAO must remain deterministic for reverse playback, arbitrary frame order and MFR. Port isolated, stateless algorithms only after CPU cost and alpha behavior are tested. The MIT license is present.

### 5.4 ASCII OFX
The supplied OFX source demonstrates two useful modes: brightness-ramp selection and structural glyph matching. Structural mode compares an 8×8 source-cell threshold mask against packed 8×8 glyph masks using Hamming distance. It also uses a long Paul Bourke density ramp and cell-local source color. The source drop has no clear top-level license in the supplied archive; do not copy its implementation wholesale. Its bundled `font8x8_basic.h` explicitly states Public Domain and may be reused independently with that notice. The XAO renderer should implement its own matcher against an owned atlas.

### 5.5 GlyphBlocks OFX
The source computes four quadrant luminance means per cell and builds a four-bit occupancy mask. It demonstrates a useful block/quad glyph strategy and source-color sampling. No top-level license was found in the supplied folder. Treat as algorithmic reference and implement an independent version; do not copy the source file without permission.

### 5.6 POINTLESS — GPL-3.0
Its CPU ASCII renderer rasterizes candidate glyphs, measures ink coverage, caches the coverage atlas, selects nearest density efficiently, and optionally uses ordered dithering between adjacent coverage candidates. It also separates edge, hatching, contour and stipple paths. The project is GPL-3.0 and includes third-party notices. Do not copy or adapt its code into a differently licensed closed-source XAO distribution without a licensing decision. Use the observed algorithmic ideas as an independent design reference.

### 5.7 Proprietary AEX/decompilation references
Crates ASCII, S1 ASCII Art, OVN ASCII and L3tt3rM4pp3r2 are binary/decompilation references, not original source trees. They are useful for control names, preset metadata, dispatch paths, glyph atlas behavior and parameter relationships. Decompiled listings are not proof of exact source code or complete proprietary algorithms. Do not copy the AEX binaries into XAO or transplant their plugin identity, PiPL constants, SDK flags or host-specific wrapper code.

## 6. Fonts archive and packaging boundary

The supplied `fonts.zip` contains 45 font files grouped into Arabic, English and Weird/ornamental families. A fresh metadata pass with fontTools found mixed OS/2 `fsType` embedding flags and a wide range of embedded license strings. **Rooyin Free Bold** (`fonts/arabic/Rooyin_Free_Bold.ttf`) is the font whose metadata explicitly declares the SIL Open Font License 1.1. **Sponge Arabic** is *not* OFL: its metadata declares the Yusuf Refaiy License. Other examples include WinSoft licensing for A Massir Ballpoint, personal-use-only notices for KA Hand Naskh, Takeaway, Flame On and others, and explicit no-redistribution/all-rights-reserved notices for some files. `fsType=0` does not itself grant redistribution rights, and the OS/2 embedding flags are not a substitute for the actual license terms.

Therefore:
- Do not bundle all 45 font files into XAO by default.
- Build the renderer so it can enumerate/use fonts installed on the user's system and support user-supplied fonts when legally installed.
- Maintain a per-font provenance/license manifest before embedding any font.
- Arabic words require proper contextual shaping and bidi handling; rendering isolated Arabic codepoints is not equivalent to rendering Arabic text.
- Ancient/symbol and Japanese glyph-art modes may treat codepoints as independent marks, but must validate actual glyph coverage in the chosen font and use deterministic fallback when missing.

## 7. Current XAO implementation reality

**Implementation checkpoint (2026-11-11, after the latest branch updates):** the core is no longer the original 10-entry 5×7 ramp. It now has a `GlyphBitmap`/`GlyphAtlas` interface, a Windows GDI atlas builder, Crates and S1 character-set catalogs, a ten-entry Crates-derived preset table, deterministic per-cell/time-slot random selection, separate family letter/number/word flags, S1 reference palette constants, and core tests. The AE adapter exposes the preset selector, character-set selector, typography/margin controls, random controls, Ancient/English/Arabic family toggles, font selector, transfer mode, Glyph Mapping, Gamma, Characters Based On (Luma/R/G/B), Edge Threshold, Preserve Cell Alpha, and an explicit preset-tuning override. The renderer now applies gamma, supports Shape Match/Luminance Ramp/Edge Directional selection, and maps glyph tone from the selected source channel. A fix prevents Random Words from excluding ordinary glyphs; generic random words now derive from the active charset (including Japanese codepoints), and atlas family collection deduplicates overlapping codepoints. The Windows atlas now calls Uniscribe for shaped/RTL word rasterization, includes a bounded immutable cache, and Ancient includes selected Ogham, Gothic, Ugaritic, Old Persian, Phoenician, Cuneiform and Egyptian Unicode ranges. The AE adapter also applies a full-frame memory guard for its two linear RGBA buffers.

**This is still incomplete and must not be described as a finished ASCII engine.** The Windows atlas is a first GDI implementation, not yet a production-quality glyph atlas with stable font metrics/bearings or a fully verified font fallback policy. An Uniscribe-based shaping/RTL rasterization path has now been added for word tokens, but it has not yet passed a Windows build or visual Arabic test; Arabic support remains unverified until joining, ordering, fallback and glyph coverage are checked in AE. Word tokens are still sampled and fitted into a single glyph cell rather than laid out as readable multi-cell text. Ancient, English and Arabic family lists are preliminary and require broader source/charset validation. The supplied 45-font archive has not been fully integrated, and redistribution rights prevent bundling fonts without per-font review. The S1 palettes recovered so far are a subset, not the full color system. The separate Main Ideas looks (ASCII CGO, Ghost, Liquid ASCII, Mosaic ASCII, Rainbow ASCII and Threshold ASCII) remain design/architecture targets, not completed production renderers. A reusable selective glyph-glow pass has now been added to the base ASCII engine, with random/fixed-region/all selection, letter/number/symbol/word category filtering, position, region size, radius and intensity controls. This is not yet the full CGO/Rainbow look or a recovered proprietary bloom; explicit per-glyph selection and the independent Rays engine remain outstanding. Liquid tile layout, dual-scale mosaic and threshold segments are still not implemented. AE abort handling, render-scale behavior, performance/memory caps, and real AE 23.2.1 runtime verification remain acceptance gates. The retrieved native build log showed that the actual AE compile blocker was the parameter-registration function: Adobe's `PF_ADD_*X` macros require a local `PF_ParamDef def` and a named `PF_InData* in_data`, but the adapter had an unnamed input parameter and no `def`. The adapter now supplies both, registers the full unique parameter-ID set, removes duplicate Mapping/Gamma/Edge controls, and the CMake target no longer redundantly defines `AE_OS_WIN` already set by `AEConfig.h`. The missing tone-map include was also added earlier. A subsequent Windows/MSVC run has now passed the full `Build AEX and core` step, confirming the native `.aex` target compiles with the AE SDK and Uniscribe linked. The pipeline then stopped in CTest on one incorrect test expectation: the recovered ASCII Art Main Detailed ramp contains 70 codepoints, not 69. The assertion has been corrected, and the native workflow now also triggers when `tests/**` changes so this correction is revalidated in the same AEX pipeline. The corrected follow-up run completed successfully: Windows/MSVC build, both Core CTest suites, PiPL verification, strict AEX verification and direct release publication all passed. GitHub Actions run `43101544790` published the raw `XAO.aex` asset under release tag `xao-build-66`; size 245,248 bytes; SHA-256 `82C04F02538D1B972FA1963BC7E3E7AC5537FD61EF87C3E6B3E66308821E4AD5`. The verifier confirmed PE32+ AMD64, required exports, exact XAO PiPL payload, no MAJEED effect identity, and runtime imports `GDI32.dll`/`USP10.dll` without dynamic MSVC CRT. This is a successful build/metadata/runtime-dependency check only; it is not an After Effects 23.2.1 launch/apply/render test. A green configure step is not a successful build, and CI does not prove AE runtime stability.

## 8. Required XAO ASCII implementation architecture

1. **Glyph atlas subsystem:** immutable, cached atlas entries with glyph identity, Unicode codepoint/token, bitmap coverage, advance/bearing/baseline, ink bounds and measured density. Validate missing glyphs and font fallback.
2. **Cell analysis:** independent source sampling and luminance sampling; support mean/center/weighted sampling, RGB channel selection, 8×8 or higher-resolution structural samples, edge magnitude and direction.
3. **Glyph mapping:** support brightness ramp, measured-density matching and shape-aware matching. Edge glyphs are a selectable mapping/overlay strategy, not a replacement for the entire ramp.
4. **Character-set library:** include Crates' 15 named sets and S1's nine named sets, plus XAO's Ancient, English and Arabic libraries. Each language group must independently enable letters, numbers and words; users can mix groups. Validate actual glyph availability.
5. **Randomization:** Random Character, Random Words and Random Timing must be independent. Derive random state from seed + cell identity + absolute time slot + pass identity. Never use mutable global RNG or previous-frame feedback.
6. **Typography controls:** Character Size, Character Margins, Cell Margins, Anti-Aliasing, glyph scale/fit, cell width/height and density controls. Character size and grid/cell size remain separate.
7. **Presets:** implement the recovered Crates baseline values as named XAO presets, preserve provenance, and add original XAO presets. Selecting a preset must set a coherent style baseline while leaving the controls editable.
8. **Color:** keep the advanced palette/gradient system open for the user's later specification. S1 color modes and palette names are confirmed references; exact palette stop values remain a recovery task. Do not invent those values.
9. **Rendering and AE integration:** CPU-first; immutable per-render configuration; explicit 8/16/32-bpc adapters; correct premultiplied alpha; abort checks; render-scale-aware grid; layer/composition-anchored cells; tile/ROI correctness; MFR-safe caches.
10. **Acceptance:** visual comparisons against the actual Main Ideas references, deterministic frame-order tests, glyph/font coverage tests, alpha/bit-depth tests, CPU performance benchmarks, clean Windows x64 build against the May 2023 AE SDK, and a real AE 23.2.1 load/apply/render test.

## 9. Non-negotiable boundaries

- Product name: **XAO**. ASCII is the default/first engine.
- The MAJEED repository is build/SDK architecture reference only. Do not port its effects, assets, parameters, UI or identity. Do not include the separate MAJEED Lines effect.
- Do not confuse XAO's own Halftone screen families with MAJEED Lines.
- Do not merge the Main Ideas' distinct visual identities into one generic ASCII renderer.
- Do not claim exact proprietary algorithm recovery from appearance alone.
- Do not claim runtime-tested AE stability based only on CI or PiPL/PE verification.
- Do not mark the ASCII engine complete until the atlas, charsets, presets, animation, UI, alpha/bit-depth and AE runtime gates above are met.
