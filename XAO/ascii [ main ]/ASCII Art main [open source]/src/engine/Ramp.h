#pragma once

#include <array>
#include <string_view>

namespace asciicam::engine {

/// A character ramp ordered DARK -> LIGHT. Index 0 is the densest glyph.
struct Ramp {
    std::string_view name;
    std::string_view chars;
};

// NOTE: these ramps are intentionally 7-bit ASCII so a glyph can be indexed by a
// single byte. Unicode ramps (block elements, Braille) need a codepoint-aware
// path and are a deliberate fast-follow, not part of the MVP.
inline constexpr std::array<Ramp, 3> kRamps{{
    {"standard", "@%#*+=-:. "},
    {"simple", "@#+. "},
    {"detailed",
     "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. "},
}};

/// Directional glyphs for edge mode, indexed by quantized gradient-angle bin:
/// 0 = vertical edge, 1 = diagonal '/', 2 = horizontal, 3 = diagonal '\\'.
inline constexpr std::array<char, 4> kEdgeGlyphs{'|', '/', '-', '\\'};

/// Look up a ramp's characters by name, falling back to "standard".
[[nodiscard]] inline constexpr std::string_view rampChars(std::string_view name) {
    for (const auto& r : kRamps) {
        if (r.name == name) {
            return r.chars;
        }
    }
    return kRamps.front().chars;
}

}  // namespace asciicam::engine
