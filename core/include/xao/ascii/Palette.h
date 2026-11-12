#pragma once

// Colour palettes.  A palette is a luminance ramp; palette strength blends the
// ramp over the source colour instead of replacing it, which is what keeps the
// original footage readable through the glyph field.

#include "xao/ascii/AsciiParams.h"

namespace xao {
namespace ascii {

struct Rgb {
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
};

Rgb rgbLerp(const Rgb& a, const Rgb& b, float t);
float rgbLuma(const Rgb& c);
Rgb rgbSaturate(const Rgb& c, float amount);
Rgb rgbClamp(const Rgb& c);

// Sample the palette ramp at t in [0,1].
Rgb paletteSample(Palette palette, float t);

// Blend the palette ramp over a source colour.
Rgb paletteApply(Palette palette, float strength, float t, const Rgb& source);

} // namespace ascii
} // namespace xao
