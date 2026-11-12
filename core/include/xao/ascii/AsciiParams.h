#pragma once

// XAO ASCII engine — parameter model.
//
// One unified control surface drives every ASCII preset.  A preset changes the
// renderer (geometry, glyph pool, colour behaviour); it never changes the
// meaning of a shared control.

#include <cstdint>

namespace xao {
namespace ascii {

enum class Preset : int {
    Default = 0,
    AlienSignal,
    Liquid,
    Ghost,
    Cgo,
    Mosaic,
    Rainbow,
    Threshold,
    Organic,
    Count
};

// Character-set override.  `Auto` means "the preset decides".
enum class Charset : int {
    Auto = 0,
    SpecialLetters,
    SpecialNumbers,
    Typewriter,
    Binary,
    MinimalPunk,
    Xs,
    BubbleGrowth,
    Stars,
    Diamonds,
    Dots,
    Circuits1,
    Circuits2,
    AlienFont,
    Bars,
    Blocks,
    Count
};

enum class SampleChannel : int { Luma = 0, Red, Green, Blue };

enum class Palette : int {
    Source = 0,
    Ember,
    Cream,
    Sand,
    Navy,
    Chroma,
    Grey,
    Acid,
    Mono,
    Terminal,
    Gold,
    Ice,
    Infrared,
    Vapor,
    Count
};

// Per-category typography settings.  `scale` is a multiplier on the cell's
// glyph size, so 1.0 is the natural size and 0.5 is half.
struct CategorySettings {
    bool enabled = true;
    float scale = 1.0f;
};

struct LanguageSettings {
    bool letters = false;
    bool numbers = false;
    bool words = false;
    int font = 0;  // index into the embedded face list for this language
};

struct AsciiParams {
    // --- ASCII group -------------------------------------------------------
    Preset preset = Preset::Default;
    Charset charset = Charset::Auto;
    SampleChannel channel = SampleChannel::Luma;
    bool reverse = false;

    // Cell size in pixels.  Larger value = larger cells and larger glyphs.
    float cells = 16.0f;
    // How much of the ASCII plate is mixed over the source (0..1).
    float amount = 1.0f;
    // Glyph density / intensity.  0 = no glyphs, 100 = the intended full look,
    // up to 500 for progressively denser, bolder coverage.
    float strength = 100.0f;
    // Scale of the ASCII plate around the layer centre (0.05..1).
    float clipScale = 1.0f;

    CategorySettings characters{true, 1.0f};
    CategorySettings numbers{true, 1.0f};
    CategorySettings words{true, 1.0f};
    // Shrinks the glyph inside its cell (0..1).
    float margin = 0.0f;

    Palette palette = Palette::Source;
    float paletteStrength = 0.0f;

    // --- Random group (inside the ASCII group, directly below) -------------
    bool randomCharacters = true;
    bool randomWords = true;
    float randomTiming = 15.0f;  // 0..100
    std::uint64_t seed = 0x58414F4153434949ull;

    // --- Language groups ---------------------------------------------------
    LanguageSettings arabic;
    LanguageSettings english;
    LanguageSettings ancient;
};

const char* presetName(Preset preset);
int presetCount();
const char* charsetName(Charset charset);
const char* paletteName(Palette palette);
const char* channelName(SampleChannel channel);

} // namespace ascii
} // namespace xao
