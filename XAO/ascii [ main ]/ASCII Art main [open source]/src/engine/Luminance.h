#pragma once

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <string_view>

namespace asciicam::engine {

/// Perceptual luminance from sRGB bytes using Rec.709 weights, returned in 0..1.
/// A gamma curve is applied so the character ramp maps evenly across midtones —
/// a correctness fix that all three reference projects omit (they map raw
/// linear brightness, which muddies mid-greys).
[[nodiscard]] inline float luminance(std::uint8_t r, std::uint8_t g, std::uint8_t b,
                                     float gamma = 2.2f) {
    const float rf = r / 255.0f;
    const float gf = g / 255.0f;
    const float bf = b / 255.0f;
    const float y = 0.2126f * rf + 0.7152f * gf + 0.0722f * bf;
    return std::pow(y, 1.0f / gamma);
}

/// Apply contrast about mid-grey (0.5), then brightness, clamped to 0..1.
[[nodiscard]] inline float applyToneMap(float y, float contrast, float brightness) {
    const float v = contrast * (y - 0.5f) + 0.5f + brightness;
    return std::clamp(v, 0.0f, 1.0f);
}

/// Map a luminance in 0..1 to an index into a ramp of @p rampSize characters.
/// @p invert swaps the dark/light ends.
[[nodiscard]] inline std::size_t rampIndex(float luminance01, std::size_t rampSize,
                                           bool invert = false) {
    if (rampSize == 0) {
        return 0;
    }
    const float y = invert ? (1.0f - luminance01) : luminance01;
    const auto idx = static_cast<std::size_t>(y * static_cast<float>(rampSize - 1) + 0.5f);
    return std::min(idx, rampSize - 1);
}

}  // namespace asciicam::engine
