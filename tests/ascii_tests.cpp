// XAO ASCII engine regression tests.
//
// These tests assert behaviour, not compilation: they render through the same
// entry point the After Effects plug-in uses and measure the resulting pixels,
// glyph pools and statistics.

#include "xao/ascii/AsciiEngine.h"
#include "xao/ascii/Atlas.h"
#include "xao/ascii/GlyphSets.h"
#include "xao/ascii/Palette.h"
#include "xao/ascii/Shaping.h"
#include "xao/ascii/Text.h"

#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace xao;
using namespace xao::ascii;

namespace {

int gFailures = 0;
int gChecks = 0;

void check(bool condition, const std::string& what) {
    ++gChecks;
    if (!condition) {
        ++gFailures;
        std::fprintf(stderr, "FAIL: %s\n", what.c_str());
    }
}

Image makeImage(int w, int h) {
    Image image(w, h);
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            const float u = static_cast<float>(x) / static_cast<float>(w);
            const float v = static_cast<float>(y) / static_cast<float>(h);
            Pixel& p = image.at(x, y);
            // A scene with a bright band, a dark corner and colour variation so
            // every preset has something to map.
            const float shape = (u > 0.25f && u < 0.75f && v > 0.2f && v < 0.8f) ? 1.0f : 0.25f;
            p.r = shape * (0.25f + 0.75f * u);
            p.g = shape * (0.20f + 0.60f * v);
            p.b = shape * (0.30f + 0.50f * (1.0f - u));
            p.a = 1.0f;
        }
    }
    return image;
}

Image makeTransparentImage(int w, int h) {
    Image image(w, h);
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            Pixel& p = image.at(x, y);
            const bool solid = (x < w / 2);
            p.r = solid ? 0.8f : 0.0f;
            p.g = solid ? 0.4f : 0.0f;
            p.b = solid ? 0.2f : 0.0f;
            p.a = solid ? 0.5f : 0.0f;
        }
    }
    return image;
}

double meanAbsDiff(const Image& a, const Image& b) {
    if (a.width() != b.width() || a.height() != b.height()) return 1.0e9;
    double sum = 0.0;
    for (std::size_t i = 0; i < a.pixels().size(); ++i) {
        const Pixel& p = a.pixels()[i];
        const Pixel& q = b.pixels()[i];
        sum += std::fabs(p.r - q.r) + std::fabs(p.g - q.g) + std::fabs(p.b - q.b);
    }
    return sum / (3.0 * static_cast<double>(a.pixels().size()));
}

AsciiRenderStats renderStats(const Image& source, const AsciiParams& params,
                             double time, Image* out = nullptr) {
    RenderContext context;
    context.timeSeconds = time;
    context.renderScale = 1.0f;
    Image destination(source.width(), source.height());
    const AsciiRenderStats stats = renderAscii(source, destination, context, params);
    if (out != nullptr) *out = destination;
    return stats;
}

bool poolContains(const GlyphPool& pool, Codepoint cp) {
    for (const GlyphItem& item : pool.items) {
        if (item.codepoint == cp) return true;
    }
    return false;
}

bool nearZero(float v) { return std::fabs(v) < 1.0e-4f; }

Text utf8(const char* s) { return decodeUtf8(std::string(s)); }

} // namespace

int main() {
    const Image source = makeImage(160, 120);

    // --- Amount ------------------------------------------------------------
    {
        AsciiParams p;
        p.amount = 0.0f;
        Image out;
        renderStats(source, p, 0.0, &out);
        check(meanAbsDiff(out, source) < 1.0e-6, "ASCII amount 0 keeps the source exactly");

        p.amount = 0.5f;
        renderStats(source, p, 0.0, &out);
        check(meanAbsDiff(out, source) > 1.0e-4, "ASCII amount 0.5 mixes the plate in");
    }

    // --- Strength ----------------------------------------------------------
    {
        float previousInk = -1.0f;
        for (float strength : {0.0f, 25.0f, 100.0f, 200.0f, 350.0f, 500.0f}) {
            AsciiParams p;
            p.strength = strength;
            Image out;
            const AsciiRenderStats stats = renderStats(source, p, 0.0, &out);
            if (strength == 0.0f) {
                check(meanAbsDiff(out, source) < 1.0e-6,
                      "ASCII strength 0 removes glyphs but keeps the source");
                check(stats.inkCoverage < 1.0e-6, "ASCII strength 0 draws no ink");
            }
            if (strength > 0.0f) {
                check(stats.inkCoverage > previousInk - 1.0e-6,
                      "ASCII strength is monotonic in ink coverage at " +
                          std::to_string(static_cast<int>(strength)));
                check(stats.glyphsDrawn > 0, "ASCII strength draws glyphs at " +
                                                 std::to_string(static_cast<int>(strength)));
            }
            previousInk = stats.inkCoverage;
        }
        AsciiParams low;
        low.strength = 100.0f;
        AsciiParams high;
        high.strength = 500.0f;
        const AsciiRenderStats lowStats = renderStats(source, low, 0.0);
        const AsciiRenderStats highStats = renderStats(source, high, 0.0);
        // Above 100 the engine subdivides each cell into 2x2 then 3x3 glyphs, so
        // density is measured in glyphs drawn, not in cell coverage.
        check(highStats.glyphsDrawn > 3 * lowStats.glyphsDrawn,
              "ASCII strength 500 is meaningfully denser than 100");
        check(highStats.inkCoverage >= lowStats.inkCoverage - 1.0e-3,
              "ASCII strength 500 never covers less than 100");
    }

    // --- Cells -------------------------------------------------------------
    {
        AsciiParams small;
        small.cells = 8.0f;
        AsciiParams large;
        large.cells = 32.0f;
        const AsciiRenderStats a = renderStats(source, small, 0.0);
        const AsciiRenderStats b = renderStats(source, large, 0.0);
        check(a.cellsAcross > b.cellsAcross, "larger cells produce fewer cells across");
        check(b.cellsAcross == source.width() / 32, "cells map directly to pixel size");

        // Every preset must follow the same direction, including Liquid.
        for (int i = 0; i < presetCount(); ++i) {
            AsciiParams pl;
            pl.preset = static_cast<Preset>(i);
            pl.cells = 12.0f;
            const AsciiRenderStats s12 = renderStats(source, pl, 0.0);
            pl.cells = 40.0f;
            const AsciiRenderStats s40 = renderStats(source, pl, 0.0);
            check(s12.cellsAcross > s40.cellsAcross,
                  std::string("cells direction for preset ") + presetName(pl.preset));
            check(s12.glyphsDrawn > s40.glyphsDrawn,
                  std::string("larger cells draw fewer, bigger glyphs for ") +
                      presetName(pl.preset));
        }
    }

    // --- Presets are visually distinct ------------------------------------
    {
        std::vector<Image> renders;
        for (int i = 0; i < presetCount(); ++i) {
            AsciiParams p;
            p.preset = static_cast<Preset>(i);
            p.cells = 12.0f;
            Image out;
            renderStats(source, p, 0.0, &out);
            renders.push_back(out);
        }
        for (std::size_t a = 0; a < renders.size(); ++a) {
            for (std::size_t b = a + 1; b < renders.size(); ++b) {
                const double diff = meanAbsDiff(renders[a], renders[b]);
                const std::string label =
                    std::string("presets differ: ") + presetName(static_cast<Preset>(a)) +
                    " vs " + presetName(static_cast<Preset>(b));
                check(diff > 0.02, label);
            }
        }
    }

    // --- Preset-specific and language-specific glyph collections ----------
    {
        AsciiParams alien;
        alien.preset = Preset::AlienSignal;
        const ResolvedPools alienPools = resolvePools(alien);
        check(!alienPools.letters.empty(), "alien signal has a glyph pool");
        bool allAncient = true;
        for (const GlyphItem& item : alienPools.letters.items) {
            int face = 0;
            if (findGlyph(alienPools.letters.face, item.codepoint, &face) == nullptr) {
                allAncient = false;
                continue;
            }
            if (std::string(faceScript(face)) != "ancient") allAncient = false;
        }
        check(allAncient, "alien signal only uses alien symbol glyphs");

        AsciiParams arabicOnly;
        arabicOnly.arabic.letters = true;
        arabicOnly.arabic.numbers = true;
        arabicOnly.arabic.words = true;
        const ResolvedPools arabicPools = resolvePools(arabicOnly);
        bool noLatin = true;
        for (const GlyphItem& item : arabicPools.letters.items) {
            const Codepoint cp = item.codepoint;
            const bool arabicForm = (cp >= 0xFB50 && cp <= 0xFEFF);
            if (!arabicForm) noLatin = false;
        }
        check(noLatin, "arabic-only letters use Arabic presentation forms only");
        check(poolContains(arabicPools.numbers, 0x0660), "arabic mode has Arabic-Indic digits");
        check(poolContains(arabicPools.numbers, 0x06F0), "arabic mode has Persian digits");
        check(arabicPools.wordMode, "arabic words enable word mode");
        check(arabicPools.wordScript == ScriptId::Arabic, "arabic words use the Arabic script");

        AsciiParams englishOnly;
        englishOnly.english.letters = true;
        const ResolvedPools englishPools = resolvePools(englishOnly);
        bool hasLatinLetter = false;
        for (const GlyphItem& item : englishPools.letters.items) {
            if (item.codepoint >= 'A' && item.codepoint <= 'z') hasLatinLetter = true;
        }
        check(hasLatinLetter, "english mode uses Latin letters");
        check(englishPools.numbers.empty(), "english letters alone do not add digits");

        // Charset override really replaces the collection.
        AsciiParams binary;
        binary.charset = Charset::Binary;
        const ResolvedPools binaryPools = resolvePools(binary);
        bool onlyBinary = !binaryPools.letters.empty();
        for (const GlyphItem& item : binaryPools.letters.items) {
            if (item.codepoint != '0' && item.codepoint != '1') onlyBinary = false;
        }
        check(onlyBinary, "charset override limits the pool to the selected set");
    }

    // --- Arabic shaping ---------------------------------------------------
    {
        // س ل ا م
        const Text salam = {0x0633, 0x0644, 0x0627, 0x0645};
        const std::vector<ShapedArabic> shaped = shapeArabic(salam);
        // Lam + alef collapses into a ligature, so four letters become three
        // glyphs: seen-initial, lam-alef, meem-isolated (alef does not join on).
        check(shaped.size() == 3, "lam-alef collapses while shaping salam");
        if (shaped.size() == 3) {
            check(shaped[0].codepoint == 0xFEB3, "seen takes the initial form");
            check(shaped[1].codepoint == 0xFEFC, "lam-alef ligature takes the final form");
            check(shaped[2].codepoint == 0xFEDD, "meem falls back to the isolated form");
        }

        // A word without lam-alef keeps one glyph per letter.
        const Text bayt = {0x0628, 0x064A, 0x062A};  // ب ي ت
        const std::vector<ShapedArabic> baytShaped = shapeArabic(bayt);
        check(baytShaped.size() == 3, "shaping keeps the letter count without ligatures");
        if (baytShaped.size() == 3) {
            check(baytShaped[0].codepoint == 0xFE91, "beh initial form");
            check(baytShaped[1].codepoint == 0xFEF4, "yeh medial form");
            check(baytShaped[2].codepoint == 0xFE96, "teh final form");
        }

        // لا : lam + alef ligature
        const Text lamAlef = {0x0644, 0x0627};
        const std::vector<ShapedArabic> ligature = shapeArabic(lamAlef);
        check(ligature.size() == 1, "lam-alef collapses into one ligature glyph");
        if (!ligature.empty()) {
            check(ligature[0].codepoint == 0xFEFB, "lam-alef isolated ligature form");
        }

        // Persian letters join.
        const Text persian = {0x067E, 0x0686, 0x06AF};
        const std::vector<ShapedArabic> persianShaped = shapeArabic(persian);
        check(persianShaped.size() == 3, "persian shaping keeps the letter count");
        if (persianShaped.size() == 3) {
            check(persianShaped[0].codepoint == 0xFB58, "peh initial form");
            check(persianShaped[1].codepoint == 0xFB7D, "tcheh medial form");
            check(persianShaped[2].codepoint == 0xFB93, "gaf final form");
        }

        // Right-to-left visual order.
        const Text visual = layoutVisual(salam);
        check(visual.size() == 3, "visual layout keeps the glyph count");
        if (visual.size() == 3) {
            check(visual[0] == 0xFEDD && visual[2] == 0xFEB3,
                  "arabic runs are laid out right to left");
        }

        // Mixed Arabic + digits keeps Latin numerals readable.
        Text mixed = salam;
        const char digitChars[] = {'1', '2', '3'};
        for (char c : digitChars) mixed.push_back(static_cast<Codepoint>(c));
        const Text mixedVisual = layoutVisual(mixed);
        std::string ascii;
        for (Codepoint cp : mixedVisual) {
            if (cp < 128) ascii.push_back(static_cast<char>(cp));
        }
        check(ascii == "123", "latin digits stay left to right inside Arabic text");

        const Text indic = toArabicIndicDigits(utf8("123"), false);
        check(indic.size() == 3 && indic[0] == 0x0661 && indic[2] == 0x0663,
              "arabic-indic digit conversion");
        const Text persianDigits = toArabicIndicDigits(utf8("123"), true);
        check(persianDigits.size() == 3 && persianDigits[0] == 0x06F1,
              "persian digit conversion");
    }

    // --- Typography controls actually change the render --------------------

    // --- Size controls ----------------------------------------------------
    {
        AsciiParams base;
        base.cells = 12.0f;
        base.english.letters = true;
        base.english.numbers = true;
        Image a;
        renderStats(source, base, 0.0, &a);

        AsciiParams charSize = base;
        charSize.characters.scale = 0.5f;
        Image b;
        renderStats(source, charSize, 0.0, &b);
        check(meanAbsDiff(a, b) > 1.0e-4, "character size changes the render");

        AsciiParams numberSize = base;
        numberSize.numbers.scale = 0.5f;
        Image c;
        renderStats(source, numberSize, 0.0, &c);
        check(meanAbsDiff(a, c) > 1.0e-5, "number size changes the render");

        AsciiParams words;
        words.cells = 12.0f;
        words.english.letters = true;
        words.english.words = true;
        Image d;
        renderStats(source, words, 0.0, &d);
        AsciiParams wordSize = words;
        wordSize.words.scale = 0.5f;
        Image e;
        renderStats(source, wordSize, 0.0, &e);
        check(meanAbsDiff(d, e) > 1.0e-5, "word size changes the render");

        // Disabling Character Size bypasses the control and returns to the
        // natural glyph size, so a non-1.0 scale must stop having an effect.
        AsciiParams disabled = base;
        disabled.characters.scale = 0.5f;
        disabled.characters.enabled = false;
        Image f;
        renderStats(source, disabled, 0.0, &f);
        check(meanAbsDiff(a, f) < 1.0e-6, "disabling character size restores natural size");

        AsciiParams margin = base;
        margin.margin = 0.4f;
        Image g;
        renderStats(source, margin, 0.0, &g);
        check(meanAbsDiff(a, g) > 1.0e-4, "character margin changes the render");
    }

    // --- Palette ----------------------------------------------------------
    {
        AsciiParams p;
        p.cells = 12.0f;
        Image source0;
        renderStats(source, p, 0.0, &source0);

        p.palette = Palette::Ember;
        p.paletteStrength = 0.8f;
        Image ember;
        renderStats(source, p, 0.0, &ember);
        check(meanAbsDiff(source0, ember) > 1.0e-3, "palette changes the render");

        p.paletteStrength = 0.2f;
        Image weak;
        renderStats(source, p, 0.0, &weak);
        check(meanAbsDiff(ember, weak) > 1.0e-3, "palette strength changes the render");

        AsciiParams q;
        q.cells = 12.0f;
        q.palette = Palette::Chroma;
        q.paletteStrength = 1.0f;
        Image chroma;
        renderStats(source, q, 0.0, &chroma);
        check(meanAbsDiff(chroma, ember) > 1.0e-3, "different palettes differ");
    }

    // --- Randomization ----------------------------------------------------
    {
        AsciiParams p;
        p.cells = 10.0f;
        p.randomTiming = 20.0f;
        Image frame0;
        Image frame0b;
        Image frame1;
        renderStats(source, p, 0.0, &frame0);
        renderStats(source, p, 0.0, &frame0b);
        renderStats(source, p, 0.5, &frame1);
        check(meanAbsDiff(frame0, frame0b) < 1.0e-9,
              "same frame renders identically with a fixed seed");
        check(meanAbsDiff(frame0, frame1) > 1.0e-4,
              "randomization changes glyphs between frames");

        AsciiParams still = p;
        still.randomCharacters = false;
        still.randomWords = false;
        Image still0;
        Image still1;
        renderStats(source, still, 0.0, &still0);
        renderStats(source, still, 0.5, &still1);
        check(meanAbsDiff(still0, still1) < 1.0e-6,
              "randomization off keeps frames identical");

        AsciiParams noTiming = p;
        noTiming.randomTiming = 0.0f;
        Image stillA;
        Image stillB;
        renderStats(source, noTiming, 0.0, &stillA);
        renderStats(source, noTiming, 0.5, &stillB);
        check(meanAbsDiff(stillA, stillB) < 1.0e-6,
              "random timing 0 freezes the glyph field");

        AsciiParams slow = p;
        slow.randomTiming = 1.0f;
        Image slowA;
        Image slowB;
        renderStats(source, slow, 0.0, &slowA);
        renderStats(source, slow, 0.05, &slowB);
        check(meanAbsDiff(slowA, slowB) < 1.0e-6,
              "slow random timing holds a bucket for several frames");

        AsciiParams fast = p;
        fast.randomTiming = 60.0f;
        Image fastA;
        Image fastB;
        renderStats(source, fast, 0.0, &fastA);
        renderStats(source, fast, 0.05, &fastB);
        check(meanAbsDiff(fastA, fastB) > 1.0e-4,
              "fast random timing changes glyphs every frame");

        AsciiParams otherSeed = p;
        otherSeed.seed = 42;
        Image seeded;
        renderStats(source, otherSeed, 0.0, &seeded);
        check(meanAbsDiff(frame0, seeded) > 1.0e-4, "the seed changes the glyph field");
    }

    // --- Randomization respects the preset glyph collection ---------------
    {
        AsciiParams alien;
        alien.preset = Preset::AlienSignal;
        alien.cells = 10.0f;
        const ResolvedPools pools = resolvePools(alien);
        bool onlyAlien = true;
        for (const GlyphItem& item : pools.letters.items) {
            int face = 0;
            if (findGlyph(pools.letters.face, item.codepoint, &face) == nullptr ||
                std::string(faceScript(face)) != "ancient") {
                onlyAlien = false;
            }
        }
        check(onlyAlien, "randomization pool for alien signal stays alien");
    }

    // --- Alpha and source preservation ------------------------------------
    {
        const Image transparent = makeTransparentImage(64, 64);
        AsciiParams p;
        p.cells = 8.0f;
        Image out;
        renderStats(transparent, p, 0.0, &out);
        check(nearZero(out.at(60, 60).a), "transparent source stays transparent");
        check(out.at(10, 10).a >= 0.49f && out.at(10, 10).a <= 1.001f,
              "semi-transparent source alpha is preserved as a floor");

        AsciiParams zero;
        zero.amount = 0.0f;
        Image straight;
        renderStats(transparent, zero, 0.0, &straight);
        check(meanAbsDiff(straight, transparent) < 1.0e-6,
              "amount 0 preserves source alpha exactly");
    }

    // --- Clip scale -------------------------------------------------------
    {
        AsciiParams p;
        p.cells = 10.0f;
        p.preset = Preset::Cgo;
        const AsciiRenderStats full = renderStats(source, p, 0.0);
        p.clipScale = 0.5f;
        const AsciiRenderStats half = renderStats(source, p, 0.0);
        check(half.inkCoverage < full.inkCoverage,
              "clip scale shrinks the ASCII plate");
    }

    // --- Reverse ----------------------------------------------------------
    {
        AsciiParams p;
        p.cells = 10.0f;
        Image normal;
        renderStats(source, p, 0.0, &normal);
        p.reverse = true;
        Image reversed;
        renderStats(source, p, 0.0, &reversed);
        check(meanAbsDiff(normal, reversed) > 1.0e-4, "reverse order changes the ramp");
    }

    // --- Atlas sanity -----------------------------------------------------
    {
        check(faceCount() > 0, "the atlas contains faces");
        check(faceCountForScript(ScriptId::Arabic) >= 5, "several Arabic faces are embedded");
        check(!faceHasGlyph(faceCount(), 'A'), "invalid face lookups are safe");
        const atlas::GlyphRecord* glyph = findGlyph(defaultFaceForScript(ScriptId::English), 'A');
        check(glyph != nullptr && glyph->width > 0, "Latin capital A rasterizes");
        GlyphMask mask;
        rasterize(defaultFaceForScript(ScriptId::Arabic), 0xFEB3, 12, 12, mask);
        check(!mask.empty(), "Arabic presentation form rasterizes");
        bool anyInk = false;
        for (float v : mask.alpha) anyInk = anyInk || v > 0.2f;
        check(anyInk, "Arabic glyph mask is not blank");
    }

    // --- Ancient rendering ------------------------------------------------
    {
        AsciiParams ancient;
        ancient.cells = 12.0f;
        ancient.ancient.letters = true;
        ancient.ancient.numbers = true;
        ancient.ancient.words = true;
        Image out;
        renderStats(source, ancient, 0.0, &out);
        check(meanAbsDiff(out, source) > 1.0e-3, "ancient mode renders glyphs");
    }

    std::printf("%d checks, %d failures\n", gChecks, gFailures);
    if (gFailures == 0) std::printf("XAO ASCII tests passed\n");
    return gFailures == 0 ? 0 : 1;
}
