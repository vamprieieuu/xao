#pragma once

// Glyph collections: the reference character sets, the language alphabets and
// the density-ordered pools the renderer actually selects from.
//
// Every sequence is ordered by ink coverage at pool build time, so luminance
// maps onto visual weight rather than onto arbitrary Unicode order.

#include "xao/ascii/AsciiParams.h"
#include "xao/ascii/Text.h"

#include <vector>

namespace xao {
namespace ascii {

enum class ScriptId : int { Arabic = 0, English, Ancient, Count };

enum class GlyphCategory : int { Letter = 0, Number, Word, Symbol };

const char* scriptName(ScriptId script);
const char* scriptTag(ScriptId script);  // "arabic" / "latin" / "ancient"
int defaultFaceForScript(ScriptId script);
int faceCountForScript(ScriptId script);
const char* scriptFaceName(ScriptId script, int index);

struct GlyphItem {
    Codepoint codepoint = 0;
    float coverage = 0.0f;
    GlyphCategory category = GlyphCategory::Letter;
};

struct GlyphPool {
    std::vector<GlyphItem> items;  // ascending ink coverage
    int face = 0;

    bool empty() const { return items.empty(); }
    std::size_t size() const { return items.size(); }
    // Ramp selection: luminance 0..1 picks a glyph of matching visual weight.
    Codepoint pickLuma(float luma) const;
    // Uniform selection inside the pool.
    Codepoint pickHash(std::uint64_t h) const;
    float coverageOf(Codepoint cp) const;
};

// --- Reference character sets ---------------------------------------------
Text charsetCodepoints(Charset charset);
// Every family the ancient faces provide (their letterforms plus symbols).
Text ancientGlyphFamily(ScriptId script);

// --- Language alphabets ---------------------------------------------------
const Text& arabicLetters();    // base letters, including Persian additions
const Text& arabicDigits();     // Arabic-Indic ٠..٩
const Text& persianDigits();    // Extended Arabic-Indic ۰..۹
const Text& englishLetters();
const Text& englishDigits();

GlyphPool makePool(const Text& codepoints, int face, GlyphCategory category);
GlyphPool mergePools(const std::vector<GlyphPool>& pools);

// Deterministic synthetic word generation.  Words are built from the selected
// alphabet each time, so no fixed dictionary is baked into the plug-in.
Text generateWord(ScriptId script, std::uint64_t h, int minLength = 3,
                  int maxLength = 6);

} // namespace ascii
} // namespace xao
