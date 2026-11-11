# XAO Focused Audit — Dither, Font Coverage and Typography — Pass 6

Date: 2026-11-07

This pass records findings from direct source inspection of the supplied Dither OFX implementation and font metadata/cmap inspection of all 45 supplied fonts. It also records a verified typography architecture correction from the HarfBuzz documentation.

## 1. Supplied Dither OFX — exact implementation

File: XAO/dither/dither ofx [open source]/dither.cpp

This is one OFX plug-in source file, not an AE-native effect and not the Dither Majid repository.

### Algorithm
- Builds a reduced-resolution cell grid over the full source frame.
- Computes average per-cell luminance using 0.299 R + 0.587 G + 0.114 B.
- Applies contrast around 0.5.
- Applies a fixed 4x4 Bayer threshold matrix.
- Maps each cell to one of five fixed palettes: Game Boy, monochrome, amber, ice or ember.
- Upscales the cell grid to the output using nearest-neighbour pixel-centre sampling.
- Supports 8-bit, 16-bit and float RGB/RGBA dispatch in the OFX source.
- Parameters are limited to palette, pixel size (1–8), dither spread (0–1.5), and contrast (0.5–2.0).

### Important limitations found in code
1. For RGBA output, the renderer writes alpha to full opacity rather than preserving the source alpha. XAO must not repeat this behavior.
2. It is a single fixed Bayer 4x4 method; it does not provide error diffusion, blue-noise, multiple ordered matrices or the larger algorithm family found in Dither Majid / Filtr.
3. It disables tiled rendering because its cell grid is computed over the full source bounds. XAO should design a tile-aware/global-coordinate strategy or explicitly request full-frame processing in a host-safe way.
4. The source marks host-frame threading unsupported and performs the grid build on the render thread. Large images may be slow.
5. Pixel size is scaled using renderScale.x only. XAO should account for both axes and non-square pixel aspect ratios where relevant.
6. Its RGB luminance coefficients are a simple luma approximation; XAO should define color-space behavior explicitly and avoid assuming that display-encoded RGB is linear light.
7. Its float path clamps the palette index to a finite palette but does not preserve HDR source values; this is a stylized palette quantizer, not a general HDR-preserving dither.

### XAO decision
- Treat this OFX source as a compact reference for cell-grid construction, Bayer indexing and palette mapping only.
- Reimplement natively in XAO's C++ core; do not import OFX SDK/runtime dependencies.
- Preserve input alpha and define premultiplied/straight-alpha handling.
- Add multiple validated ordered/error-diffusion/noise algorithms as separate Dither modes, not as the excluded standalone Lines effect.
- Do not port any Dither Majid Lines source, controls, UI or presets.

## 2. Font archive — all 45 font files inspected

The archive has 24 Arabic, 10 English and 11 unusual/symbol font files. Font metadata and Unicode cmap coverage were read from every font file.

### Coverage observations
- The 24 files in the Arabic folder do not all have equivalent Arabic coverage. Several decorative fonts cover a limited subset of Arabic code points; some include Latin glyphs too.
- The English fonts generally cover the basic Latin alphabet, but their total glyph sets vary widely.
- The unusual/symbol fonts vary significantly: some have extensive symbol/private-use or technical codepoint coverage; others are mainly Latin display fonts. A filename or folder name is not proof of actual glyph coverage.
- The font library must expose per-font character coverage and a missing-glyph preview, not just list filenames.
- For mixed glyph pools, each font must be filtered to glyphs it really supports. Do not silently substitute a missing-glyph box or an unrelated fallback glyph.

### License metadata requiring restrictions or review
- Explicitly restrictive/personal-use or non-redistribution metadata was found in fonts including A Massir Ballpoint, KA Hand Naskh MOB V2, KA Hand Naskh V2, Milan Titles Black, Nasma, Takeaway Regular, ZIAN Black, Flame on Black, Flame on!, Manga Style, Matrix Code NFI, ZAMRUDS and the Zenzai family.
- Rooyin Free Bold identifies SIL Open Font License 1.1.
- Sponge Arabic includes the Yusuf Refaiy License text and an embedded SIL OFL 1.1 text. Its exact governing license and reserved-name conditions should be confirmed with the author before redistributing.
- Other files have missing or incomplete license metadata. Missing metadata is not permission to redistribute.

### Font handling decision
- Preserve the exact original font file when the user selects/imports it; do not replace it with a drawn approximation.
- The distributable XAO package should bundle only fonts with verified redistribution rights and preserve required license texts/notices.
- Restricted or uncertain fonts remain local user-imported files; XAO stores a stable font reference and gracefully reports if the file is unavailable.
- Build a Font Inspector view with family/style, file path, format, license status, Arabic/Latin/symbol coverage, and glyph preview.
- Cache rasterized glyph atlases by font file identity/hash, face index, variation axes, size, render scale, hinting/raster mode and glyph set. Invalidate cache when the font file or settings change.

## 3. Arabic and multilingual typography — architecture correction

HarfBuzz's official documentation confirms:
- HarfBuzz performs script-aware shaping for Arabic and many other writing systems, converting Unicode codepoints to positioned glyph IDs.
- HarfBuzz supports TTF, TTC and OTF font formats and integrates with FreeType for glyph rasterization.
- HarfBuzz itself does not perform paragraph bidirectional (bidi) resolution. Mixed Arabic/English runs must first be segmented and ordered with a bidi implementation, then shaped with the correct direction/script/language per run.

Sources:
- https://harfbuzz.github.io/what-does-harfbuzz-do.html
- https://harfbuzz.github.io/getting-started.html
- https://github.com/harfbuzz/harfbuzz/blob/main/docs/usermanual-integration.xml

### Recommended text pipeline
1. Decode text as Unicode and normalize according to a documented policy (do not destructively normalize glyph-art source strings).
2. Resolve paragraph direction and bidi runs using a dedicated bidi implementation (e.g. ICU BiDi or FriBidi).
3. Segment runs by script, language, font and direction.
4. Shape each run with HarfBuzz using the selected font and OpenType features.
5. Use returned glyph IDs, advances and offsets to position glyphs.
6. Rasterize the exact glyph IDs from the same font face using FreeType.
7. Composite glyph bitmaps/outlines into the glyph atlas or output image.
8. For Glyph Art mode, allow codepoint/glyph sampling as independent visual units; this is intentionally distinct from connected text typography.

### Two distinct Arabic modes
- Arabic Typography: preserves words, joining forms, mark positioning, bidi and readable mixed-script layout.
- Arabic Glyph Art: treats selected glyphs as visual tokens for cell-based mapping; no forced word joining unless the user chooses a word/text mode.

## 4. Immediate XAO engineering implications

- Dither core must preserve alpha, handle non-zero world origins and use deterministic global cell coordinates.
- Dither modes should separate quantization method from palette and cell geometry.
- Font selection must be coverage-aware and license-aware.
- Arabic shaping and bidi must be separate stages; HarfBuzz alone is not a full paragraph layout engine.
- CPU rendering remains mandatory. Optional GPU glyph-atlas rendering must match the CPU reference output within defined tolerances.
