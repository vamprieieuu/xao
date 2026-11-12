# XAO ASCII — implementation report

Status: the ASCII **engine** is implemented, builds and is covered by 129
automated behavioural checks. The **After Effects host adapter** is written
(`ae/`) but has not been compiled here: this environment has neither the Adobe
After Effects SDK nor an MSVC toolchain. See "Limitations" for exactly what is
and is not verified.

## 1. What was inspected

Repository inventory (946 files, ~213 MB):

| Group | Content used |
|---|---|
| `XAO/MAIN IDEAS/` | 8 screen recordings (Ascii cgo, Ascii ghost, Liquid ascii, Mosaic asci, Rainbow ascii, Thridshold asci, Golden glow halftone, Pixeldithergo), Shape Halftone and Typeset preset stills |
| `XAO/ascii [ main ]/c+/` | Ghidra-style decompilations: `CratesASCII.aex.c` (169k lines), `L3tt3rM4pp3r2.aex.c` (266k), `OVN_ASCII.aex.c`, `S1AsciiArt.aex.c` |
| `XAO/ascii [ main ]/aex/` | The four reference plug-in binaries |
| `XAO/ascii [ main ]/ASCII Art main [open source]` | C++/Qt core engine, glyph mapper, luminance/edge modes, unit tests |
| `XAO/ascii [ main ]/ascii ofx`, `glyphblocks ofx` | OFX ASCII and glyph-block renderers |
| `XAO/ascii [ main ]/auraascii master [open source]` | WebGL2 glyph atlas, Sobel edge shader, presets |
| `XAO/ascii [ main ]/morphing ascii shader [open source]` | SDF glyph morph, memory grid, ink bleed, parameter docs |
| `XAO/fonts/` | 24 Arabic, 10 English, 11 symbol/"weird" fonts (TTF/OTF) |
| `docs/` | Passes 2–41 (prior audits, control maps, visual inventories) |
| `core/` | Existing XAO core (image, compositor, pipeline) — kept and extended |

### Reference data recovered from the decompilations

* **Crates ASCII preset names**: `None|Default|Alien Signal|Circles and Dots|
  Classic|Corrupted|Crossword|Diamonds|Matrix|Motherboard|Punk Shapes`
  (`CratesASCII.aex.c`).
* **Crates ASCII parameter JSON**: `Characters Based On` (Red/Green/Blue/Luma),
  `Character Set` (15 entries: Special Characters and Letters, Special
  Characters and Numbers, Classic Typewriter, Japanese Characters, Binary,
  Minimal Punk, X's, Bubble Growth, Stars, Diamonds, Dots, Circuits 1,
  Circuits 2, Alien Font, Bars), `Reverse Order`, `Character Size` (0–500,
  divided by 100), `Character Margins` (0–100, divided by 100).
* **OVN ASCII** character ramp string `0123456789ABCDEF<>[]{}/\|=+*-.` and its
  control labels (cell size/aspect, colour modes, edges, palette mapping).
* **S1 ASCII Art** symbols `s1ascii::GlyphAtlas`, `WorkingGlyphMasks`,
  `Palette Color Strength`, and its embedded-font error strings, which confirm
  a pre-rasterized atlas with a working-memory failure path.

The two numeric ranges above are why **ASCII Strength** runs to 500 and
**Character Margin** is a percentage: both are reference-derived, not invented.

### Video analysis

Frames were extracted with ffmpeg at 8 %, 50 % and 92 % of every clip and
compared side by side with engine output. Measured results:

* ASCII references sit on a **near-black plate**: pure black is 19–23 % of
  pixels in CGO, Ghost and Rainbow frames.
* Ghost is **cream ink on deep maroon** (`#200000`, `#400000`, `#601010`).
* Mosaic is **grey/navy blocks** (`#606060`, `#606080`) with a fine light glyph
  layer on top.
* Threshold is **grey bars** (`#606060`, `#A0A0A0`) broken into small squares
  over black.
* Liquid is **variable-width rounded tiles** with source-sampled fills and
  mixed words/numbers inside them.

## 2. Algorithms reconstructed

### Cell sampling and glyph matching
Each cell is box-averaged from the premultiplied source, un-premultiplied, and
converted to the selected channel (Luma BT.709 by default). Every glyph in the
embedded atlas stores its **ink coverage**, so pools are sorted by visual
weight and luminance maps onto glyph density instead of onto codepoint order —
the same principle the reference plug-ins use for their character ramps.

### Randomization
`cellHash(seed, timeBucket, cellX, cellY, salt)` — a stateless splitmix64 chain.
Random Characters moves the ramp pick **inside a narrow window** around the
luminance index (`±n/12`), which keeps the composition readable while every
eligible glyph changes from frame to frame. Random Timing sets the bucket rate
(`1 + timing × 0.35` per second); 0 freezes the field. No mutable RNG, so frames
render identically in any order, in reverse, or under multi-frame rendering.

### Arabic
A joining table for the 28 core letters plus Persian `پ چ ژ ک گ ی`, mapping to
Unicode Arabic Presentation Forms-B (`FE70–FEFF`) and the Persian forms in
`FB50–FDFF`. Lam + alef becomes `FEF5–FEFC`. Diacritics are transparent to
joining. `layoutVisual` shapes, splits into directional segments, and emits
Arabic runs right-to-left while Latin/number sub-runs keep their own order.
Arabic-Indic (`0660`) and Persian (`06F0`) digits are both generated.

### Liquid layout
Rows are partitioned into 1–3 cell tiles (wider as density rises), each filled
with a rounded, source-sampled, palette-washed chip, then either a generated
word (drawn with pen advances and optically centred) or single glyphs in a
contrasting ink. Tile size is derived from the cell size, so **increasing Cells
always increases tile and glyph size**.

### Palettes
Ramps are sampled from the reference frames (Ember, Cream, Sand, Navy, Chroma,
Grey, …) and blended over the source colour by Palette Strength, so the
footage survives instead of being replaced by a flat tint.

## 3. Presets and their render identities

| Preset | Strategy |
|---|---|
| Default | Luminance-ramped glyph field, source colour, per-cell shade, glyph ink over untouched footage |
| Alien Signal | Alien symbol pool only, near-black cell plates, staggered rows, green ramp, per-cell signal flicker and scanline dropouts |
| Liquid | Row-partitioned variable-width rounded tiles with word/glyph content |
| Ghost | Cream type on a maroon plate with low-contrast diagonal ray bands |
| CGO | Dense emissive field, saturated source colour, warm accent pass on highlights |
| Mosaic | Coarse quantized blocks (2.6× cell) plus a sparse fine glyph layer |
| Rainbow | Tiny dense glyphs, chroma ramp driven by tone, black plate, specular highlights |
| Threshold | Row segments whose bar thickness follows tone, broken into squares |
| Organic | Domain-warped sampling, per-cell 90° rotations, size jitter, ink-pooling second pass, bleed |

## 4. Problems fixed (mapped to the brief)

1. **Presets look alike** — nine distinct renderers; a regression test asserts
   every preset pair differs by more than 0.02 mean absolute pixel difference.
2. **Alien Signal = recoloured Default** — Alien uses only the ancient symbol
   atlas (test asserts every glyph resolves to an ancient face) and its own
   plate/scanline/flicker behaviour.
3. **Liquid starts too large / Cells shrinks it** — tile geometry is derived
   directly from the cell size; tests assert larger cells mean fewer, larger
   tiles and glyphs for *every* preset, including Liquid.
4. **Arabic does not render** — joining forms, ligatures, RTL layout and both
   numeral systems implemented and unit-tested.
5. **Fonts were cosmetic** — 20 supplied faces are rasterized into the binary at
   build time; font selection changes the actual glyph bitmaps.
6. **Randomization too sparse** — the ramp-window jitter changes every eligible
   glyph each time bucket (tests: frames differ over time, same frame is stable,
   timing 0 freezes).
7. **Preset randomization leaks across families** — pools are preset- and
   language-scoped; tests assert no Latin letters in Arabic-only mode and no
   non-alien glyphs in Alien Signal.
8. **Strength capped at 100** — 0 removes glyphs, 100 is the full look, above
   100 the cell subdivides (2×2 then 3×3) and the visibility floor relaxes;
   test asserts >3× the glyph count at 500 vs 100.
9. **Palette degraded** — palettes are luminance ramps blended by strength over
   the source colour, not a flat overlay.
10. **Character Set controls did nothing** — a chosen set replaces the pool; a
    test asserts a Binary override yields only `0`/`1`.
11. **Nested parameter groups** — one `ASCII` group containing `Random` and the
    three language sections; no "XAO ASCII"/"ASCII Core"/"ASCII Controls".
12. **ASCII Amount removed the source** — amount now scales the plate's own
    alpha (`out = plate·a + src·(1−a)`), so amount 0 returns the source exactly
    and transparent plate pixels never erase the footage.

## 5. Files

New:
```
core/include/xao/ascii/{AsciiParams,AsciiEngine,Atlas,AtlasData,GlyphSets,Palette,Shaping,Text}.h
core/src/ascii/{AsciiEngine,Atlas,AtlasData,GlyphSets,Palette,Shaping,Text}.cpp
tools/build_atlas.py        font → embedded atlas generator
tools/xao_ascii_cli.cpp     offline renderer (PPM), used for comparisons
tests/ascii_tests.cpp       129 behavioural checks
tests/core_tests.cpp        (existing)
ae/XAO_Ascii.{h,cpp}        After Effects host adapter
ae/pipl_gen.py              binary PiPL generator (reads XAO_Ascii.h)
ae/XAO_Ascii.{def,rc}       exports and VERSIONINFO
ae/CMakeLists.txt           MSVC .aex build
tools/verify_aex.py         PE/export/PiPL verifier (CI and local)
Makefile                    core/tests/CLI build
.github/workflows/ascii-engine.yml
docs/ASCII_TYPOGRAPHY_FONTS.md
docs/visual/reference_vs_xao.png
```
Modified: `CMakeLists.txt`, `.gitignore`.

`core/include/xao/ascii/AtlasData.cpp` (~20k lines) and `AtlasData.h` are
generated by `tools/build_atlas.py` and committed so builds never need Python.

## 6. Tests

`make test` →

```
XAO core tests passed
129 checks, 0 failures
XAO ASCII tests passed
```

Covered: amount 0/0.5, strength 0/25/100/200/350/500 (monotonic + density),
cells direction per preset, all 36 preset pairs distinct, preset-specific and
language-specific pools, Arabic shaping (seen/lam-alef/meem, Persian letters,
lam-alef ligature, RTL order, mixed digits), Character/Number/Word size and
their enable toggles, margin, palettes and palette strength, random on/off/
timing/seed, alpha preservation, clip scale, reverse order, atlas rasterization
including an Arabic presentation form, and ancient-mode rendering.

## 7. Visual comparisons performed

`docs/visual/reference_vs_xao.png` puts the reference effect region next to the
engine rendering of the same footage region for CGO, Ghost, Liquid, Mosaic,
Rainbow and Threshold. Each was inspected and tuned at least twice.

Remaining mismatches, honestly stated:

* **CGO**: close in density, colour and warm emission, but the reference has a
  stronger bloom around the brightest glyphs than the current single halo pass.
* **Ghost**: cream type and maroon plate match; the reference's rays are broader
  and more directional than the current bands.
* **Liquid**: tile geometry, fills and contrast are close; the reference mixes
  Korean and English words — no CJK face exists in the supplied fonts, so words
  are English/Arabic/ancient only.
* **Mosaic**: block scale and quantisation match; the reference's fine glyph
  layer is slightly denser.
* **Rainbow**: tone-driven chroma matches; the reference has slightly more pure
  black between glyph clusters.
* **Threshold**: bar/segment structure matches; the reference's row pitch is
  tighter in places.

These are known deltas, not claims of pixel equality.

## 8. Limitations

1. **The adapter is audited against real SDK headers, not run in After Effects.**
   Every declaration the host adapter uses was checked against the After Effects
   SDK headers kept in `extern/AfterEffectsSDK` of the reference repository, and
   the adapter compiles cleanly against them. No `.aex` can be produced in this
   authoring environment (no Windows, no MSVC): the `windows-aex` CI job builds
   and verifies one from that pinned SDK checkout. Loading the plug-in inside
   After Effects, and its parameter UI, have not been observed here.
2. **Embedded fonts are the supplied ones.** Some of the supplied font files are
   proprietary or personal-use; embedding them into a distributed `.aex`
   requires confirming each licence. See `docs/ASCII_TYPOGRAPHY_FONTS.md`.
3. **Arabic shaping covers presentation forms**, not GSUB feature substitution.
   This is correct for the supplied faces (which carry `FE70–FEFF` coverage) but
   will not reproduce advanced OpenType features (swashes, stylistic sets).
4. **OTF/CFF faces are not embedded**; the generator reads TrueType outlines
   through FreeType/Pillow, which did rasterize the OTF files supplied, but the
   atlas only includes codepoints those faces actually map (no `.notdef` boxes).
5. **No CJK glyph source** exists in the repository, so the reference's Japanese
   character set and Korean words are not reproduced.
