#pragma once

#include "engine/AsciiFrame.h"

#include <algorithm>
#include <cmath>

namespace asciicam::engine {

/// Coarse colour categories used to drive the emoji palette.
enum class ColorCategory {
    Red,
    Orange,
    Yellow,
    Green,
    Cyan,
    Blue,
    Purple,
    Pink,
    Neutral,  ///< Greys, near-black, near-white — no strong hue.
};

/// Convert RGB to HSV. Hue in [0,360), saturation and value in [0,1].
inline void rgbToHsv(Rgb c, float& h, float& s, float& v) {
    const float r = c.r / 255.0f;
    const float g = c.g / 255.0f;
    const float b = c.b / 255.0f;
    const float mx = std::max({r, g, b});
    const float mn = std::min({r, g, b});
    const float d = mx - mn;

    v = mx;
    s = (mx <= 0.0f) ? 0.0f : d / mx;

    if (d <= 0.0f) {
        h = 0.0f;
        return;
    }
    if (mx == r) {
        h = 60.0f * std::fmod((g - b) / d, 6.0f);
    } else if (mx == g) {
        h = 60.0f * (((b - r) / d) + 2.0f);
    } else {
        h = 60.0f * (((r - g) / d) + 4.0f);
    }
    if (h < 0.0f) {
        h += 360.0f;
    }
}

/// Classify a colour into a coarse hue bucket. Low-saturation or very dark
/// colours are Neutral so structural detail can be kept with an ASCII ramp
/// instead of being turned into arbitrary coloured emoji.
[[nodiscard]] inline ColorCategory classify(Rgb c) {
    float h = 0.0f;
    float s = 0.0f;
    float v = 0.0f;
    rgbToHsv(c, h, s, v);

    if (s < 0.25f || v < 0.15f) {
        return ColorCategory::Neutral;
    }
    // Red only for a narrow, vivid, bright hue window — so orange, skin tones,
    // and dull/dark reds do NOT become red emoji (they fall through to Orange or
    // to Neutral, which renders as the ASCII ramp).
    if (h < 10.0f || h >= 350.0f) {
        return (s >= 0.55f && v >= 0.40f) ? ColorCategory::Red : ColorCategory::Neutral;
    }
    if (h < 45.0f) return ColorCategory::Orange;
    if (h < 70.0f) return ColorCategory::Yellow;
    if (h < 170.0f) return ColorCategory::Green;
    if (h < 200.0f) return ColorCategory::Cyan;
    if (h < 260.0f) return ColorCategory::Blue;
    if (h < 290.0f) return ColorCategory::Purple;
    return ColorCategory::Pink;
}

}  // namespace asciicam::engine
