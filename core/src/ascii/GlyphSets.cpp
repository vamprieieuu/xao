#include "xao/ascii/GlyphSets.h"

#include "xao/ascii/Atlas.h"

#include <algorithm>
#include <cstring>

namespace xao {
namespace ascii {

namespace {

Text fromUtf8(const char* s) { return decodeUtf8(std::string(s)); }

Text range(Codepoint first, Codepoint last) {
    Text out;
    for (Codepoint cp = first; cp <= last; ++cp) out.push_back(cp);
    return out;
}

Text concat(Text a, const Text& b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

} // namespace

const char* scriptName(ScriptId script) {
    switch (script) {
        case ScriptId::Arabic: return "Arabic";
        case ScriptId::English: return "English";
        case ScriptId::Ancient: return "Ancient";
        default: return "Unknown";
    }
}

const char* scriptTag(ScriptId script) {
    switch (script) {
        case ScriptId::Arabic: return "arabic";
        case ScriptId::English: return "latin";
        case ScriptId::Ancient: return "ancient";
        default: return "latin";
    }
}

int faceCountForScript(ScriptId script) {
    return static_cast<int>(facesForScript(scriptTag(script)).size());
}

int defaultFaceForScript(ScriptId script) {
    const std::vector<int> faces = facesForScript(scriptTag(script));
    return faces.empty() ? 0 : faces.front();
}

const char* scriptFaceName(ScriptId script, int index) {
    const std::vector<int> faces = facesForScript(scriptTag(script));
    if (index < 0 || index >= static_cast<int>(faces.size())) return "";
    return faceName(faces[static_cast<std::size_t>(index)]);
}

// ---------------------------------------------------------------------------
// Reference character sets
// ---------------------------------------------------------------------------

Text charsetCodepoints(Charset charset) {
    switch (charset) {
        case Charset::SpecialLetters:
            return fromUtf8("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
                            "0123456789!@#$%&*()-_=+[]{};:'\",.<>/?\\|~^`");
        case Charset::SpecialNumbers:
            return fromUtf8("0123456789!@#$%&*+-=<>/\\|()[]{}~^");
        case Charset::Typewriter:
            return fromUtf8(".,:;i1tfLCG08@#$%&*+=~-");
        case Charset::Binary:
            return fromUtf8("01");
        case Charset::MinimalPunk:
            return fromUtf8("-=+*#%&@$Xx");
        case Charset::Xs:
            return concat(fromUtf8("xX"), fromUtf8("\xE2\x9C\x95\xE2\x9C\x96\xE2\x95\xB3"));
        case Charset::BubbleGrowth:
            return fromUtf8("\xC2\xB7\xE2\x80\xA2\xE2\x88\x99\xE2\x97\x8B\xE2\x97\x8F"
                            "\xE2\x97\x89\xE2\x97\xAF\xE2\x97\xA6");
        case Charset::Stars:
            return concat(fromUtf8("*"), fromUtf8("\xE2\x9C\xB3\xE2\x9C\xB4\xE2\x9C\xB6"
                                                    "\xE2\x9C\xB7\xE2\x9C\xB8\xE2\x9C\xB9"
                                                    "\xE2\x9C\xBA\xE2\x98\x85\xE2\x98\x86"
                                                    "\xE2\x9C\xA6\xE2\x9C\xA7"));
        case Charset::Diamonds:
            return fromUtf8("\xE2\x97\x86\xE2\x97\x87\xE2\x97\x88\xE2\x99\xA6"
                            "\xE2\x9F\xA1\xE2\x9F\xA2");
        case Charset::Dots:
            return concat(fromUtf8("."), fromUtf8("\xC2\xB7\xE2\x88\x98\xE2\x97\x8B\xE2\x97\x8F"
                                                   "\xE2\x97\x89\xE2\x97\xA6"));
        case Charset::Circuits1:
            return fromUtf8("|-+/\\_[]{}()<>~=*");
        case Charset::Circuits2:
            return fromUtf8("\xE2\x95\xB1\xE2\x95\xB2\xE2\x95\xB3\xE2\x94\xBC\xE2\x94\x9C"
                            "\xE2\x94\xA4\xE2\x94\xAC\xE2\x94\xB4\xE2\x94\x82\xE2\x94\x80"
                            "\xE2\x95\x8C\xE2\x94\x84\xE2\x94\x88");
        case Charset::AlienFont:
            return ancientGlyphFamily(ScriptId::Ancient);
        case Charset::Bars:
            return concat(fromUtf8("|"), fromUtf8("\xE2\x94\x82\xE2\x94\x83\xE2\x96\x8F"
                                                   "\xE2\x96\x8E\xE2\x96\x8D\xE2\x96\x8C"
                                                   "\xE2\x96\x8B\xE2\x96\x8A\xE2\x96\x89"
                                                   "\xE2\x96\x88\xE2\x96\x95\xE2\x96\x90"));
        case Charset::Blocks:
            return fromUtf8("\xE2\x96\x91\xE2\x96\x92\xE2\x96\x93\xE2\x96\x88\xE2\x96\x84"
                            "\xE2\x96\x80\xE2\x96\x8C\xE2\x96\x90\xE2\x96\xA0\xE2\x96\xA1"
                            "\xE2\x96\xAA\xE2\x96\xAB\xE2\x97\xBC\xE2\x97\xBB");
        case Charset::Auto:
        default:
            return charsetCodepoints(Charset::SpecialLetters);
    }
}

Text ancientGlyphFamily(ScriptId script) {
    Text out;
    const std::vector<int> faces = facesForScript(scriptTag(script));
    for (int face : faces) {
        for (Codepoint cp : faceCodepoints(face)) {
            // Letterforms and symbol families only; skip control/space.
            if (cp < 0x21) continue;
            out.push_back(cp);
        }
    }
    std::sort(out.begin(), out.end());
    out.erase(std::unique(out.begin(), out.end()), out.end());
    return out;
}

// ---------------------------------------------------------------------------
// Language alphabets
// ---------------------------------------------------------------------------

const Text& arabicLetters() {
    static const Text kLetters = [] {
        Text t = range(0x0621, 0x063A);
        // Drop the tatweel placeholder range gaps: 0621..063A is contiguous.
        const Codepoint persian[] = {0x067E, 0x0686, 0x0698, 0x06A9, 0x06AF, 0x06CC};
        for (Codepoint cp : persian) t.push_back(cp);
        return t;
    }();
    return kLetters;
}

const Text& arabicDigits() {
    static const Text kDigits = range(0x0660, 0x0669);
    return kDigits;
}

const Text& persianDigits() {
    static const Text kDigits = range(0x06F0, 0x06F9);
    return kDigits;
}

const Text& englishLetters() {
    static const Text kLetters = [] {
        Text t = range('A', 'Z');
        const Text lower = range('a', 'z');
        t.insert(t.end(), lower.begin(), lower.end());
        return t;
    }();
    return kLetters;
}

const Text& englishDigits() {
    static const Text kDigits = range('0', '9');
    return kDigits;
}

// ---------------------------------------------------------------------------
// Pools
// ---------------------------------------------------------------------------

Codepoint GlyphPool::pickLuma(float luma) const {
    if (items.empty()) return 0;
    const float t = std::min(1.0f, std::max(0.0f, luma));
    const std::size_t index = static_cast<std::size_t>(
        t * static_cast<float>(items.size() - 1) + 0.5f);
    return items[std::min(items.size() - 1, index)].codepoint;
}

Codepoint GlyphPool::pickHash(std::uint64_t h) const {
    if (items.empty()) return 0;
    return items[boundedInt(h, static_cast<std::uint32_t>(items.size()))].codepoint;
}

float GlyphPool::coverageOf(Codepoint cp) const {
    for (const GlyphItem& item : items) {
        if (item.codepoint == cp) return item.coverage;
    }
    return 0.0f;
}

GlyphPool makePool(const Text& codepoints, int face, GlyphCategory category) {
    GlyphPool pool;
    pool.face = face;
    pool.items.reserve(codepoints.size());
    for (Codepoint cp : codepoints) {
        if (cp == 0x20) continue;
        const atlas::GlyphRecord* glyph = findGlyph(face, cp);
        if (glyph == nullptr) continue;
        GlyphItem item;
        item.codepoint = cp;
        item.coverage = glyph->coverage;
        item.category = category;
        pool.items.push_back(item);
    }
    std::stable_sort(pool.items.begin(), pool.items.end(),
                     [](const GlyphItem& a, const GlyphItem& b) {
                         return a.coverage < b.coverage;
                     });
    return pool;
}

GlyphPool mergePools(const std::vector<GlyphPool>& pools) {
    GlyphPool merged;
    if (!pools.empty()) merged.face = pools.front().face;
    for (const GlyphPool& pool : pools) {
        merged.items.insert(merged.items.end(), pool.items.begin(), pool.items.end());
    }
    std::stable_sort(merged.items.begin(), merged.items.end(),
                     [](const GlyphItem& a, const GlyphItem& b) {
                         return a.coverage < b.coverage;
                     });
    return merged;
}

// ---------------------------------------------------------------------------
// Word generation
// ---------------------------------------------------------------------------

Text generateWord(ScriptId script, std::uint64_t h, int minLength, int maxLength) {
    if (maxLength < minLength) maxLength = minLength;
    const int span = maxLength - minLength + 1;
    const int length = minLength + static_cast<int>(boundedInt(h, static_cast<std::uint32_t>(span)));
    Text word;
    word.reserve(static_cast<std::size_t>(length));

    if (script == ScriptId::Arabic) {
        const Text& letters = arabicLetters();
        std::uint64_t state = h;
        for (int i = 0; i < length; ++i) {
            state = hashMix(state + static_cast<std::uint64_t>(i));
            word.push_back(letters[boundedInt(state, static_cast<std::uint32_t>(letters.size()))]);
        }
        return word;
    }

    if (script == ScriptId::Ancient) {
        const Text family = ancientGlyphFamily(ScriptId::Ancient);
        if (family.empty()) return word;
        std::uint64_t state = h;
        for (int i = 0; i < length; ++i) {
            state = hashMix(state + static_cast<std::uint64_t>(i));
            word.push_back(family[boundedInt(state, static_cast<std::uint32_t>(family.size()))]);
        }
        return word;
    }

    // English: pronounceable consonant/vowel alternation.
    static const char* kVowels = "aeiou";
    static const char* kConsonants = "bcdfghklmnprstvwz";
    std::uint64_t state = h;
    for (int i = 0; i < length; ++i) {
        state = hashMix(state + static_cast<std::uint64_t>(i));
        const bool vowel = (i % 2 == 1) || (boundedInt(state, 5) == 0);
        if (vowel) {
            word.push_back(static_cast<Codepoint>(kVowels[boundedInt(state >> 8, 5)]));
        } else {
            word.push_back(static_cast<Codepoint>(kConsonants[boundedInt(state >> 8, 16)]));
        }
    }
    return word;
}

} // namespace ascii
} // namespace xao
