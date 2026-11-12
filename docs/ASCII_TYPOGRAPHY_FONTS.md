# XAO ASCII — embedded typography

The ASCII engine cannot read font files at render time: an `.aex` must not
depend on files that may be missing on the artist's machine, and multi-frame
rendering may evaluate several frames concurrently. `tools/build_atlas.py`
therefore rasterizes the supplied fonts into a 1-bit atlas at a 40 px em size,
which is compiled into the plug-in (`core/src/ascii/AtlasData.cpp`).

Regenerate with:

```
pip install pillow fonttools
python3 tools/build_atlas.py
```

## Embedded faces

| Menu name | Script | Supplied file |
|---|---|---|
| Naskh Tahrir | Arabic | `XAO/fonts/arabic/A Naskh Tahrir.ttf` |
| Massir Ballpoint | Arabic | `A Massir Ballpoint.ttf` |
| Rooyin Bold | Arabic | `Rooyin_Free_Bold.ttf` |
| Bad Khat | Arabic | `a-bad-khat.ttf` |
| Afsaneh | Arabic | `afsaneh.ttf` |
| Shekari | Arabic | `b-shekari.ttf` |
| Digi Hilan | Arabic | `digi-hilan.ttf` |
| Kamran | Arabic | `k-kamran.ttf` |
| Nasma | Arabic | `nasma.ttf` |
| Minecraft | English | `XAO/fonts/english/Minecraft.ttf` |
| 1942 | English | `1942.ttf` |
| Matrix Code | English | `matrix code nfi.ttf` |
| La Machine | English | `La Machine Company.ttf` |
| Zenzai | English | `Zenzai Itache.ttf` |
| Zodiac | Ancient | `XAO/fonts/weird/Cryptic-Zodiac.ttf` |
| Astro | Ancient | `AstroScript.ttf` |
| Fam Code | Ancient | `fam-code.ttf` |
| Arrows | Ancient | `PWNewArrows.ttf` |
| Hall Heroes | Ancient | `hallheroes.ttf` |
| Monster | Ancient | `MonsterMasher.ttf` |

3,955 glyphs, 391 KB of bitmap data.

## Coverage that matters

* All nine Arabic faces carry Presentation Forms-B (`FE70–FEFF`), which is what
  makes connected letter forms possible without a GSUB engine. Rooyin Bold,
  A Massir Ballpoint and Kamran carry the largest form sets (139–140 glyphs).
* Persian letters use Presentation Forms-A (`FB50–FDFF`); Naskh Tahrir, Rooyin,
  Massir and Kamran cover them. Fonts without those forms fall back to the base
  letter, which renders as an isolated shape rather than failing.
* English faces cover basic Latin; several are pixel/bitmap-styled fonts that
  suit ASCII art (Minecraft, 1942, Matrix Code).
* Ancient faces are symbol fonts: Zodiac maps A–Z to zodiac marks, Astro and Old
  Skull to astrological/ornamental letterforms, plus geometric, arrow and
  mathematical ranges.

## `.notdef` filtering

Several supplied fonts map unsupported codepoints to glyph 0, which draws a
hollow "missing glyph" box. The generator resolves every codepoint through the
font's cmap and **skips `.notdef` mappings**, so a cell can never be filled with
a tofu box.

## Licensing

The XAO archive supplied these fonts together with the project. Several carry
proprietary, demo or personal-use notices rather than an open licence. This
repository embeds them for the project owner's own builds; **redistributing the
resulting `.aex` publicly requires confirming the rights for each embedded face**
(or replacing it in `FACES` in `tools/build_atlas.py` with a face whose licence
permits embedding). Fonts explicitly known to be open-licensed may be used
freely; the rest are the owner's responsibility.
