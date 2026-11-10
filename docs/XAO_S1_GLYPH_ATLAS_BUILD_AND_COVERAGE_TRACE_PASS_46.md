# XAO — S1 ASCII GlyphAtlas Build and Coverage Mapping Trace (Pass 46)

Date: 2026-11-10
Scope: focused trace of the supplied `S1AsciiArt.aex.c` decompilation around `BuildAtlas`, `GlyphAtlas::Build`, `GlyphAtlas::Impl::Draw`, `ramp`, `coverage` and `Rasterize`. Findings are limited to what the decompiled listing exposes; no original source or plugin runtime was available in this pass.

## 1. Embedded font-resource loading

Verified in `(anonymous namespace)::BuildAtlas()`:
- The plugin obtains its own module handle and looks up Windows resources of type `RT_RCDATA` (resource type integer 10).
- It iterates resource identifiers 1001 through 1013 inclusive: 13 embedded binary resources.
- Each resource is obtained through `FindResourceA`, `SizeofResource`, `LoadResource` and `LockResource`; the resulting byte pointers and sizes are passed to `GlyphAtlas::Build`.
- Atlas construction is published through a shared pointer/global atlas guarded by a mutex/lock. The renderer also acquires a shared reference under the same lock before use.
- A failed/missing resource or failed atlas build returns failure; the render path reports that the embedded font atlas is not initialized.

What this proves: the plugin ships its font data inside the AEX resources and does not need to locate a system font at render time for this atlas path. The exact font family names and license terms are not established by this trace.

## 2. Font parsing and glyph measurement

Verified in `GlyphAtlas::Build`:
- The implementation initializes font records with `stbtt_GetFontOffsetForIndex` and `stbtt_InitFont` from the embedded byte data. This is a TrueType parsing/rasterization path using stb_truetype.
- The decompilation exposes 13 font records.
- For each font it scans a fixed 92-character ASCII character table (`kAtlasCharacters`; loop bound `0x5c`).
- It calls `stbtt_FindGlyphIndex` and rejects a font record if a character in that scan has glyph index zero. It then obtains each character's outline bounding box with `stbtt_GetCodepointBox`.
- It accumulates a union bounding box over the accepted character set, then rasterizes each character into a fixed 77 × 128 float working canvas. The glyph is scaled to fit the union bounds while preserving aspect ratio and centered in that canvas.
- Raster samples are normalized from 8-bit coverage to float. The code accumulates the four float channels over the 77 × 128 canvas and divides by 9856 (77 × 128), yielding a normalized average coverage/density value for each character.
- The renderer uses `stbtt_GetCodepointBitmapSubpixel` and releases temporary bitmaps with `stbtt_FreeBitmap`.

Interpretation:
- The core glyph score is measured raster ink coverage, not a hand-authored brightness rank.
- The fixed canvas and shared union bounds normalize characters to a common comparison area, making density values comparable within a font.
- This is a useful reference algorithm for a measured-density mode, but it does not by itself establish perceptual shape matching or a complete variable-width text layout engine.

## 3. Multiple character sets and precomputed ramps

Verified in the `GlyphAtlas::Build` continuation:
- The atlas initializes a table of 117 density-ramp slots (`0x75`), then builds character-set-specific ramp data from nine character-set specifications (`iVar15 == 9`).
- For each set, it obtains the character list and count from `CharacterSetGlyphs` and `CharacterSetGlyphCount`.
- It computes/looks up per-character density values for the selected font, sorts glyph indices by density using a stable sort, and stores normalized coverage values in the corresponding ramp record.
- It derives several named subset lists from the density data using `SelectEvenSubset`; the symbols include Classic, Minimal and Bourke member sets.
- The `ramp(fontIndex, setIndex)` accessor validates the atlas state and index ranges before returning a stored ramp. The decompilation shows a 13-font × 9-set addressing scheme.
- The `coverage(fontIndex, glyphIndex)` accessor returns a precomputed coverage value when indices and atlas state are valid.

What remains uncertain:
- The exact semantic names and intended UI mapping of all nine character sets require tracing `kSetSpecs`, `CharacterSetGlyphs`, `CharacterSetGlyphCount` and parameter setup together.
- The exact ramp selection strategy for every UI mode has not been fully reconstructed in this pass.
- The 92-character scan table and the nine selectable character sets are separate structures; do not conflate them.

## 4. Rasterize and draw behavior

Verified:
- `GlyphAtlas::Rasterize` selects a font record and either draws a character from the fixed atlas character table or resolves a glyph index from the selected character-set table.
- The raster path delegates to `GlyphAtlas::Impl::Draw`.
- `Impl::Draw` clears the destination float buffer, computes a uniform scale to fit the glyph's supplied bounds into the requested output dimensions, centers the result, invokes stb_truetype subpixel bitmap rasterization, clips writes to the output rectangle, and stores the maximum coverage value at each destination pixel.
- The public accessors expose both density/ramp data and rasterized glyph masks, allowing the renderer to use precomputed density for selection and a raster mask for drawing.

## 5. XAO implementation decisions

1. Build an independent native measured-density mode: rasterize each eligible glyph into a normalized comparison tile, calculate coverage in a defined linear/coverage domain, and precompute stable sorted candidate ramps.
2. Do not copy S1's 77 × 128 fixed tile as an unquestioned universal resolution. Benchmark multiple tile sizes and supersampling levels, then choose a quality/performance balance.
3. Store per-glyph metrics (advance, bearings, ink bounds, baseline) separately from density. S1's measured density is useful for cell-art matching, but mixed-script typography requires layout metrics and shaping.
4. Keep font resource ingestion separate from glyph rasterization and ramp construction. XAO must validate glyph coverage rather than assume that a nonzero glyph index means a visually suitable glyph.
5. For Unicode and Arabic, use a proper shaping/bidi pipeline and glyph IDs; do not extend S1's byte-oriented 92-character table into a fake Unicode solution.
6. Make atlas creation immutable after publication, with thread-safe lifetime management and deterministic results under AE MFR and arbitrary frame order.

## 6. Scope and non-claims

- This is static analysis of a decompiled listing, not the original S1 source.
- No embedded font family names or font redistribution rights have been verified.
- No exact pixel output, speed, quality comparison, AE 2023 compatibility or runtime stability is claimed.
- No S1 code or binary has been copied into XAO.

## 7. Next trace targets

- Resolve the nine character-set specifications and map each to the visible UI controls and preset labels.
- Trace the S1 render loop from sampled source-cell statistics through ramp selection to `Rasterize` and final pixel compositing.
- Inspect the other three original ASCII decompilations to the same level where useful.
- Complete the independent XAO font coverage, shaping and license matrix before selecting or bundling fonts.

