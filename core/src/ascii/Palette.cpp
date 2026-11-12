#include "xao/ascii/Palette.h"

#include <algorithm>

namespace xao {
namespace ascii {

namespace {

struct Stop {
    float t;
    Rgb c;
};

// Ramps sampled from the supplied reference clips: the ASCII references sit on
// a near-black plate with the palette concentrated in the glyph ink.
const Stop kEmber[] = {
    {0.00f, {0.00f, 0.00f, 0.00f}},
    {0.25f, {0.30f, 0.02f, 0.02f}},
    {0.50f, {0.66f, 0.10f, 0.06f}},
    {0.76f, {1.00f, 0.42f, 0.08f}},
    {1.00f, {1.00f, 0.94f, 0.76f}},
};
const Stop kCream[] = {
    {0.00f, {0.02f, 0.00f, 0.00f}},
    {0.22f, {0.17f, 0.02f, 0.03f}},
    {0.46f, {0.36f, 0.08f, 0.09f}},
    {0.70f, {0.62f, 0.26f, 0.25f}},
    {1.00f, {0.96f, 0.93f, 0.85f}},
};
const Stop kSand[] = {
    {0.00f, {0.09f, 0.08f, 0.08f}},
    {0.22f, {0.24f, 0.22f, 0.21f}},
    {0.42f, {0.42f, 0.48f, 0.48f}},
    {0.62f, {0.63f, 0.38f, 0.25f}},
    {0.82f, {0.71f, 0.61f, 0.46f}},
    {1.00f, {0.95f, 0.91f, 0.83f}},
};
const Stop kNavy[] = {
    {0.00f, {0.02f, 0.03f, 0.11f}},
    {0.30f, {0.12f, 0.14f, 0.31f}},
    {0.56f, {0.36f, 0.41f, 0.56f}},
    {0.76f, {0.63f, 0.61f, 0.79f}},
    {1.00f, {0.95f, 0.95f, 1.00f}},
};
const Stop kChroma[] = {
    {0.00f, {0.03f, 0.03f, 0.02f}},
    {0.16f, {0.36f, 0.10f, 0.76f}},
    {0.36f, {0.80f, 0.16f, 0.70f}},
    {0.55f, {1.00f, 0.56f, 0.16f}},
    {0.72f, {0.26f, 0.86f, 0.36f}},
    {0.87f, {0.16f, 0.80f, 0.86f}},
    {1.00f, {1.00f, 1.00f, 1.00f}},
};
const Stop kGrey[] = {
    {0.00f, {0.03f, 0.03f, 0.03f}},
    {0.40f, {0.35f, 0.35f, 0.35f}},
    {0.70f, {0.63f, 0.63f, 0.63f}},
    {1.00f, {0.96f, 0.96f, 0.96f}},
};
const Stop kAcid[] = {
    {0.00f, {0.00f, 0.03f, 0.01f}},
    {0.30f, {0.05f, 0.36f, 0.11f}},
    {0.60f, {0.26f, 0.80f, 0.30f}},
    {0.85f, {0.62f, 1.00f, 0.62f}},
    {1.00f, {0.90f, 1.00f, 0.90f}},
};
const Stop kMono[] = {
    {0.00f, {0.02f, 0.02f, 0.02f}},
    {1.00f, {0.97f, 0.97f, 0.97f}},
};
const Stop kTerminal[] = {
    {0.00f, {0.00f, 0.02f, 0.00f}},
    {0.50f, {0.10f, 0.60f, 0.20f}},
    {1.00f, {0.65f, 1.00f, 0.70f}},
};
const Stop kGold[] = {
    {0.00f, {0.05f, 0.03f, 0.00f}},
    {0.50f, {0.66f, 0.45f, 0.10f}},
    {1.00f, {1.00f, 0.95f, 0.72f}},
};
const Stop kIce[] = {
    {0.00f, {0.01f, 0.03f, 0.06f}},
    {0.50f, {0.20f, 0.55f, 0.76f}},
    {1.00f, {0.88f, 0.97f, 1.00f}},
};
const Stop kInfrared[] = {
    {0.00f, {0.02f, 0.00f, 0.02f}},
    {0.40f, {0.45f, 0.02f, 0.30f}},
    {0.76f, {0.95f, 0.25f, 0.10f}},
    {1.00f, {1.00f, 0.92f, 0.55f}},
};
const Stop kVapor[] = {
    {0.00f, {0.05f, 0.02f, 0.10f}},
    {0.40f, {0.55f, 0.15f, 0.65f}},
    {0.76f, {1.00f, 0.45f, 0.76f}},
    {1.00f, {0.70f, 0.95f, 1.00f}},
};

struct Ramp {
    const Stop* stops;
    int count;
};

Ramp rampFor(Palette palette) {
    switch (palette) {
        case Palette::Ember: return {kEmber, 5};
        case Palette::Cream: return {kCream, 5};
        case Palette::Sand: return {kSand, 6};
        case Palette::Navy: return {kNavy, 5};
        case Palette::Chroma: return {kChroma, 7};
        case Palette::Grey: return {kGrey, 4};
        case Palette::Acid: return {kAcid, 5};
        case Palette::Mono: return {kMono, 2};
        case Palette::Terminal: return {kTerminal, 3};
        case Palette::Gold: return {kGold, 3};
        case Palette::Ice: return {kIce, 3};
        case Palette::Infrared: return {kInfrared, 4};
        case Palette::Vapor: return {kVapor, 4};
        case Palette::Source:
        default: return {kMono, 2};
    }
}

} // namespace

Rgb rgbLerp(const Rgb& a, const Rgb& b, float t) {
    const float k = std::min(1.0f, std::max(0.0f, t));
    return {a.r + (b.r - a.r) * k, a.g + (b.g - a.g) * k, a.b + (b.b - a.b) * k};
}

float rgbLuma(const Rgb& c) {
    return 0.2126f * c.r + 0.7152f * c.g + 0.0722f * c.b;
}

Rgb rgbClamp(const Rgb& c) {
    return {std::min(1.0f, std::max(0.0f, c.r)),
            std::min(1.0f, std::max(0.0f, c.g)),
            std::min(1.0f, std::max(0.0f, c.b))};
}

Rgb rgbSaturate(const Rgb& c, float amount) {
    const float l = rgbLuma(c);
    return rgbClamp({l + (c.r - l) * amount, l + (c.g - l) * amount,
                     l + (c.b - l) * amount});
}

Rgb paletteSample(Palette palette, float t) {
    if (palette == Palette::Source) {
        const float k = std::min(1.0f, std::max(0.0f, t));
        return {k, k, k};
    }
    const Ramp ramp = rampFor(palette);
    const float x = std::min(1.0f, std::max(0.0f, t));
    for (int i = 1; i < ramp.count; ++i) {
        if (x <= ramp.stops[i].t) {
            const float span = ramp.stops[i].t - ramp.stops[i - 1].t;
            const float local = span > 0.0f ? (x - ramp.stops[i - 1].t) / span : 0.0f;
            return rgbLerp(ramp.stops[i - 1].c, ramp.stops[i].c, local);
        }
    }
    return ramp.stops[ramp.count - 1].c;
}

Rgb paletteApply(Palette palette, float strength, float t, const Rgb& source) {
    if (palette == Palette::Source || strength <= 0.0f) return source;
    const Rgb rampColor = paletteSample(palette, t);
    return rgbClamp(rgbLerp(source, rampColor, std::min(1.0f, strength)));
}

} // namespace ascii
} // namespace xao
