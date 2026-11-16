# Aciify archive — Folder 04: fonts

**Source:** `aciify.zip` → `aciify/fonts/`  
**Inventory:** 49 ZIP entries including 4 directories; 39 font files? (TTF/OTF assets; see catalog below). Total font-folder uncompressed size: 6,623,721 bytes.  
**Purpose:** catalog fonts for later XAO ASCII/glyph mapping experiments. No fonts were added to XAO or redistributed in this report.

## Folder structure

- `arabic/`: Arabic display, handwriting, calligraphic and novelty typefaces.
- `english/`: English display/novelty fonts, including report, flame, manga, matrix-code and Minecraft styles.
- `weird/`: script, cryptic, monster, skull, arrows and novelty glyph fonts.

## Catalog (font internal family/style names read from font name tables)

### Arabic
| File | Internal family / style |
|---|---|
| `A Massir Ballpoint.ttf` | A Massir Ballpoint Regular |
| `A Naskh Tahrir.ttf` | A Naskh Tahrir Regular |
| `a-arslan-wessam-a.ttf` | (A) Arslan Wessam A Regular |
| `a-arslan-wessam-b.ttf` | (A) Arslan Wessam B Regular |
| `a-bad-khat.ttf` | A-bad kh@t Regular |
| `afsaneh-font.ttf` | Afsaneh Font Regular |
| `afsaneh.ttf` | AFSANEH Regular |
| `alfont_com_Guesswhat-Exceptional.otf` | Guesswhat Exceptional Regular |
| `Arabic_Childhood_Regular.ttf` | Arabic Childhood ver1 Regular |
| `b-shekari.ttf` | B Shekari Regular |
| `digi-hilan.ttf` | Digi Hilan Bold |
| `k-kamran.ttf` | K Kamran Regular |
| `ka-hand-naskh-mob-v2.ttf` | KA Hand Naskh MOB V2 Regular |
| `ka-hand-naskh-v2.ttf` | KA Hand Naskh V2 Regular |
| `Maqroo_Arabick_Regular.ttf` | Maqroo Regular |
| `Methlama_Typeface_Black.otf` | KO Methlama Black |
| `Milan_Titles_Black.otf` | Milan Display Black |
| `nasma.ttf` | Nasma Regular |
| `Rooyin_Free_Bold.ttf` | RooyinFree Bold |
| `Sponge_Arabic_Regular.otf` | YR Sponge Arabic Regular |
| `Tajarib_Typeface_Black.otf` | Tajarib Typeface Black |
| `Takeaway_Regular.ttf` | Takeaway Combo Regular |
| `Ummi_Regular_Italic.ttf` | Ummi Regular Italic |
| `ZIAN_Black.ttf` | ZIAN Black |

### English
| File | Internal family / style |
|---|---|
| `1942.ttf` | 1942 report |
| `Flame on Black.ttf` | Flame on Black Regular |
| `Flame on!.ttf` | Flame on! Regular |
| `La Machine Company.ttf` | La Machine Company Regular |
| `Manga Style.ttf` | Manga Style Regular |
| `matrix code nfi.ttf` | Matrix Code NFI Regular |
| `Minecraft.ttf` | Minecraft Medium |
| `ZAMRUDS.ttf` | ZAMRUDS Regular |
| `Zenzai Itacha.ttf` | Zenzai Itacha Regular |
| `Zenzai Itache.ttf` | Zenzai Itache Regular |

### Weird / novelty
| File | Internal family / style |
|---|---|
| `AstroScript-Bold.ttf` | AstroScript Bold |
| `AstroScript.ttf` | AstroScript Regular |
| `Cryptic-Zodiac.ttf` | Cryptic Zodiac Regular |
| `fam-code.ttf` | New Regular (internal metadata) |
| `hallheroes.ttf` | Hall of Heroes Regular |
| `MonsterMasher.ttf` | MonsterMasher Regular |
| `Mxnster-Regular.ttf` | Mxnster Regular |
| `Old_Skull_Hellron.ttf` | Old Skull Hellron Regular |
| `PWNewArrows.ttf` | PWNewArrows Medium |
| `Widget-Italic.ttf` | Widget Italic |
| `Zenzai Itachi.ttf` | Zenzai Itachi Regular |

## Technical observations for XAO

- The archive is a **font asset collection**, not source code. Internal font metadata was read (family/style/PostScript names); font outlines, glyph coverage, kerning, Arabic shaping, and actual visual output were not exhaustively inspected.
- Several filenames/families are display or novelty fonts. Do not assume each font has a complete ASCII 32–126 set, Arabic codepoints, or compatible glyph metrics. Verify character coverage and missing-glyph fallback before using it in a renderer.
- For ASCII rendering, the font's visual glyph shapes are only one component: a reliable atlas/glyph sampler must rasterize glyphs at controlled size, normalize cell dimensions, measure average luminance/coverage, and map them to target brightness. Keep charset ordering and per-glyph weights separate from font identity.
- Arabic needs more than selecting a font: shaping, joining forms, bidi ordering, ligatures, mark positioning and fallback are separate concerns. Font support alone does not guarantee Arabic correctness in an ASCII/glyph-cell pipeline.
- For native AE, fonts are installed/available on the host; avoid bundling or embedding these files without checking their individual license and redistribution terms. This archive does not provide a consolidated license inventory.
- Fonts with unusual glyphs (Matrix Code, arrows, cryptic, monster, etc.) can be candidate glyph palettes, but test actual glyph rasterization and licensing first.

## Preservation and validation

- Source paths are preserved as `fonts/arabic/`, `fonts/english/`, and `fonts/weird/` in the original archive.
- This report catalogs names and metadata only; it does not copy font binaries into the XAO repository.
- No install, glyph-sheet render, charset coverage test, Arabic shaping test, or After Effects runtime test was performed.
- Licensing is **not established** by filename or archive inclusion; inspect each font's accompanying license/source before distribution or bundling.
