#!/usr/bin/env python3
"""Rasterize the XAO supplied fonts into an embedded glyph atlas.

The XAO plug-in cannot read font files at render time: an After Effects .aex
must not depend on files that may be missing on the artist's machine, and
Smart Render may run several frames concurrently.  This tool therefore bakes
the real, supplied font outlines into a compact 1-bit atlas that is compiled
into the plug-in.

The output is deterministic: the same font files always produce byte-identical
C++ sources.

Usage:
    PYTHONPATH=<fonttools> python3 tools/build_atlas.py
"""

from __future__ import annotations

import os
import sys
import textwrap

from PIL import Image, ImageFont, ImageDraw

# ---------------------------------------------------------------------------
# Faces to embed.
#
# (id, display name, script, repo-relative font path)
#   script: "arabic" | "latin" | "ancient"
# ---------------------------------------------------------------------------
FACES = [
    ("A Naskh Tahrir",        "Naskh Tahrir",     "arabic", "XAO/fonts/arabic/A Naskh Tahrir.ttf"),
    ("A Massir Ballpoint",    "Massir Ballpoint", "arabic", "XAO/fonts/arabic/A Massir Ballpoint.ttf"),
    ("Rooyin Free Bold",      "Rooyin Bold",      "arabic", "XAO/fonts/arabic/Rooyin_Free_Bold.ttf"),
    ("a-bad-khat",            "Bad Khat",         "arabic", "XAO/fonts/arabic/a-bad-khat.ttf"),
    ("afsaneh",               "Afsaneh",          "arabic", "XAO/fonts/arabic/afsaneh.ttf"),
    ("b-shekari",             "Shekari",          "arabic", "XAO/fonts/arabic/b-shekari.ttf"),
    ("digi-hilan",            "Digi Hilan",       "arabic", "XAO/fonts/arabic/digi-hilan.ttf"),
    ("k-kamran",              "Kamran",           "arabic", "XAO/fonts/arabic/k-kamran.ttf"),
    ("nasma",                 "Nasma",            "arabic", "XAO/fonts/arabic/nasma.ttf"),
    ("Minecraft",             "Minecraft",        "latin",  "XAO/fonts/english/Minecraft.ttf"),
    ("1942",                  "1942",             "latin",  "XAO/fonts/english/1942.ttf"),
    ("matrix code nfi",       "Matrix Code",      "latin",  "XAO/fonts/english/matrix code nfi.ttf"),
    ("La Machine Company",    "La Machine",       "latin",  "XAO/fonts/english/La Machine Company.ttf"),
    ("Zenzai Itache",         "Zenzai",           "latin",  "XAO/fonts/english/Zenzai Itache.ttf"),
    ("Cryptic-Zodiac",        "Zodiac",           "ancient", "XAO/fonts/weird/Cryptic-Zodiac.ttf"),
    ("AstroScript",           "Astro",            "ancient", "XAO/fonts/weird/AstroScript.ttf"),
    ("fam-code",              "Fam Code",         "ancient", "XAO/fonts/weird/fam-code.ttf"),
    ("PWNewArrows",           "Arrows",           "ancient", "XAO/fonts/weird/PWNewArrows.ttf"),
    ("hallheroes",            "Hall Heroes",      "ancient", "XAO/fonts/weird/hallheroes.ttf"),
    ("MonsterMasher",         "Monster",          "ancient", "XAO/fonts/weird/MonsterMasher.ttf"),
]

EM = 40  # rasterization size in pixels; the engine scales down from here

# Codepoint ranges requested from every face.  A face only contributes the
# codepoints it actually covers.
RANGES = [
    (0x0020, 0x007E),   # Basic Latin
    (0x00A0, 0x00FF),   # Latin-1 supplement
    (0x0600, 0x06FF),   # Arabic
    (0xFE70, 0xFEFF),   # Arabic presentation forms-B (contextual shaping)
    (0xFB50, 0xFDFF),   # Arabic presentation forms-A (Persian letters, ligatures)
    (0x2190, 0x21FF),   # Arrows
    (0x2200, 0x22FF),   # Mathematical operators
    (0x2500, 0x257F),   # Box drawing
    (0x2580, 0x259F),   # Block elements
    (0x25A0, 0x25FF),   # Geometric shapes
    (0x2600, 0x26FF),   # Miscellaneous symbols
    (0x2700, 0x27BF),   # Dingbats
    (0x2900, 0x297F),   # Supplemental arrows-B
    (0x2B00, 0x2BFF),   # Miscellaneous symbols and arrows
]

# Explicit extras that matter for the language system but fall outside ranges.
EXTRAS = [
    0x0660 + i for i in range(10)          # Arabic-Indic digits
] + [
    0x06F0 + i for i in range(10)          # Extended Arabic-Indic (Persian) digits
] + [
    0x066A, 0x066B, 0x066C, 0x066D, 0x06D4, 0x060C, 0x061B, 0x061F, 0x0640,
]


def wanted_codepoints(cmap):
    cps = set()
    for lo, hi in RANGES:
        for cp in range(lo, hi + 1):
            if cp in cmap:
                cps.add(cp)
    for cp in EXTRAS:
        if cp in cmap:
            cps.add(cp)
    return sorted(cps)


def font_cmap(path):
    """Read the cmap (codepoint -> glyph name), skipping .notdef mappings.

    Several supplied fonts map unsupported characters to glyph 0, which draws
    the font's hollow "missing glyph" box.  Those must never enter the atlas:
    a cell would show a box instead of art.
    """
    try:
        from fontTools.ttLib import TTFont
    except ImportError:
        sys.exit("fontTools is required: pip install fonttools")
    f = TTFont(path, lazy=True)
    cmap = {}
    for table in f["cmap"].tables:
        for cp, name in table.cmap.items():
            if name == ".notdef":
                continue
            cmap[cp] = name
    return cmap


def pack_rows(mask_image):
    w, h = mask_image.size
    stride = (w + 7) // 8
    out = bytearray(stride * h)
    px = mask_image.load()
    for y in range(h):
        base = y * stride
        for x in range(w):
            if px[x, y] >= 128:
                out[base + (x >> 3)] |= 0x80 >> (x & 7)
    return bytes(out), stride


def build_face(face_id, display, script, path):
    if not os.path.exists(path):
        sys.exit("missing font: " + path)
    cmap = font_cmap(path)
    font = ImageFont.truetype(path, EM)
    ascent, descent = font.getmetrics()
    glyphs = []
    blob = bytearray()
    for cp in wanted_codepoints(set(cmap.keys())):
        ch = chr(cp)
        try:
            bbox = font.getbbox(ch, anchor="ls")
            if bbox is None:
                continue
            x0, y0, x1, y1 = bbox
            if x1 <= x0 or y1 <= y0:
                continue
            img = Image.new("L", (x1 - x0, y1 - y0), 0)
            d = ImageDraw.Draw(img)
            # anchor "ls": left baseline.  y0 is the offset from the baseline
            # (negative above it), so the mask is drawn at -y0 vertically.
            d.text((-x0, -y0), ch, font=font, fill=255, anchor="ls")
            # A glyph that is entirely empty is not useful as art; skip it,
            # except for the space, which the engine handles geometrically.
            if cp != 0x20 and img.getextrema()[1] < 128:
                continue
            bits, stride = pack_rows(img)
            advance = int(round(font.getlength(ch)))
            ink = sum(bin(b).count("1") for b in bits)
            coverage = ink / float(max(1, (x1 - x0) * (y1 - y0)))
            glyphs.append(
                dict(cp=cp, advance=advance, left=x0, top=y0,
                     w=x1 - x0, h=y1 - y0, stride=stride,
                     offset=len(blob), coverage=coverage)
            )
            blob += bits
        except Exception:
            continue
    glyphs.sort(key=lambda g: g["cp"])
    return dict(id=face_id, display=display, script=script, ascent=ascent,
                descent=descent, glyphs=glyphs, blob=bytes(blob)), cmap


def c_escape(s):
    return s.replace("\\", "\\\\").replace('"', '\\"')


def emit(faces, out_h, out_cpp):
    hdr = []
    hdr.append("// Generated by tools/build_atlas.py -- do not edit by hand.")
    hdr.append("// Source fonts: supplied XAO font archive (see docs/ASCII_TYPOGRAPHY_FONTS.md).")
    hdr.append("#pragma once")
    hdr.append("")
    hdr.append("#include <cstdint>")
    hdr.append("")
    hdr.append("namespace xao {")
    hdr.append("namespace ascii {")
    hdr.append("namespace atlas {")
    hdr.append("")
    hdr.append("// One rasterized glyph.  Bits are row-packed, most significant bit first,")
    hdr.append("// stride = (width + 7) / 8 bytes per row.")
    hdr.append("struct GlyphRecord {")
    hdr.append("    std::uint32_t codepoint;")
    hdr.append("    std::int16_t advance;")
    hdr.append("    std::int16_t left;   // bearing from the pen position")
    hdr.append("    std::int16_t top;    // offset above the baseline (negative)")
    hdr.append("    std::uint16_t width;")
    hdr.append("    std::uint16_t height;")
    hdr.append("    float coverage;      // ink ratio, drives luminance ramping")
    hdr.append("    std::uint32_t bitmapOffset;")
    hdr.append("};")
    hdr.append("")
    hdr.append("struct FaceRecord {")
    hdr.append("    const char* name;")
    hdr.append('    const char* script;  // "arabic" | "latin" | "ancient"')
    hdr.append("    std::int16_t emSize;")
    hdr.append("    std::int16_t ascent;")
    hdr.append("    std::int16_t descent;")
    hdr.append("    std::uint32_t glyphBegin;")
    hdr.append("    std::uint32_t glyphCount;")
    hdr.append("};")
    hdr.append("")
    hdr.append("extern const FaceRecord kFaces[];")
    hdr.append("extern const int kFaceCount;")
    hdr.append("extern const GlyphRecord kGlyphs[];")
    hdr.append("extern const std::uint32_t kGlyphCount;")
    hdr.append("extern const std::uint8_t kBitmapBits[];")
    hdr.append("")
    hdr.append("// Number of embedded faces per script.")
    hdr.append("extern const int kArabicFaceCount;")
    hdr.append("extern const int kLatinFaceCount;")
    hdr.append("extern const int kAncientFaceCount;")
    hdr.append("")
    hdr.append("} // namespace atlas")
    hdr.append("} // namespace ascii")
    hdr.append("} // namespace xao")
    hdr.append("")
    with open(out_h, "w", encoding="utf-8") as f:
        f.write("\n".join(hdr))

    src = []
    src.append("// Generated by tools/build_atlas.py -- do not edit by hand.")
    src.append('#include "xao/ascii/AtlasData.h"')
    src.append("")
    src.append("namespace xao {")
    src.append("namespace ascii {")
    src.append("namespace atlas {")
    src.append("")
    # Flatten every face's glyphs into one table with absolute bitmap offsets.
    blob = bytearray()
    glyph_lines = []
    face_rows = []
    for face in faces:
        begin = len(glyph_lines)
        shift = len(blob)
        for g in face["glyphs"]:
            glyph_lines.append(
                "    {%uu, %d, %d, %d, %u, %u, %.6ff, %uu},"
                % (g["cp"], g["advance"], g["left"], g["top"], g["w"], g["h"],
                   g["coverage"], shift + g["offset"])
            )
        blob += face["blob"]
        face_rows.append((face, begin, len(face["glyphs"])))
    src.append("const GlyphRecord kGlyphs[] = {")
    src.extend(glyph_lines)
    src.append("};")
    src.append("")
    src.append("const std::uint32_t kGlyphCount = %du;" % len(glyph_lines))
    src.append("")
    src.append("const int kFaceCount = %d;" % len(faces))
    src.append("const int kArabicFaceCount = %d;" % sum(1 for f in faces if f["script"] == "arabic"))
    src.append("const int kLatinFaceCount = %d;" % sum(1 for f in faces if f["script"] == "latin"))
    src.append("const int kAncientFaceCount = %d;" % sum(1 for f in faces if f["script"] == "ancient"))
    src.append("")
    src.append("const FaceRecord kFaces[] = {")
    for face, begin, count in face_rows:
        src.append('    {"%s", "%s", %d, %d, %d, %uu, %uu},'
                   % (c_escape(face["display"]), face["script"], EM,
                      face["ascent"], -face["descent"], begin, count))
    src.append("};")
    src.append("")
    # bitmap blob as hex bytes
    src.append("const std::uint8_t kBitmapBits[] = {")
    data = bytes(blob)
    for i in range(0, len(data), 24):
        src.append("    " + "".join("0x%02x," % b for b in data[i:i + 24]))
    src.append("};")
    src.append("")
    src.append("} // namespace atlas")
    src.append("} // namespace ascii")
    src.append("} // namespace xao")
    src.append("")
    with open(out_cpp, "w", encoding="utf-8") as f:
        f.write("\n".join(src))
    return len(glyph_lines), len(blob)


def main():
    root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    os.chdir(root)
    faces = []
    for face_id, display, script, path in FACES:
        face, cmap = build_face(face_id, display, script, path)
        faces.append(face)
        print("%-22s %-8s glyphs=%4d bytes=%7d"
              % (display, script, len(face["glyphs"]), len(face["blob"])))
    os.makedirs("core/include/xao/ascii", exist_ok=True)
    os.makedirs("core/src/ascii", exist_ok=True)
    total, blob_size = emit(faces, "core/include/xao/ascii/AtlasData.h",
                            "core/src/ascii/AtlasData.cpp")
    print("total glyphs=%d bitmap bytes=%d" % (total, blob_size))


if __name__ == "__main__":
    main()
