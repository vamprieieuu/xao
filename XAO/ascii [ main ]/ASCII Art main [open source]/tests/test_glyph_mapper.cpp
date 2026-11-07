#include "engine/GlyphMapper.h"

#include <catch2/catch_test_macros.hpp>

using namespace asciicam::engine;

namespace {
RenderConfig baseConfig() {
    RenderConfig cfg;
    cfg.contrast = 1.0f;
    cfg.brightness = 0.0f;
    cfg.ramp = "standard";  // "@%#*+=-:. " : index 0 dark, last is space
    return cfg;
}
}  // namespace

TEST_CASE("luminance mapper: dark -> dense glyph, bright -> space", "[mapper]") {
    LuminanceMapper mapper(baseConfig());

    const AsciiCell dark = mapper.map({Rgb{0, 0, 0}, 0.0f, 0});
    const AsciiCell bright = mapper.map({Rgb{255, 255, 255}, 1.0f, 0});

    CHECK(dark.glyph == "@");
    CHECK(bright.glyph == " ");
}

TEST_CASE("luminance mapper honours colour mode", "[mapper]") {
    RenderConfig mono = baseConfig();
    mono.color = ColorMode::Monochrome;
    CHECK(LuminanceMapper(mono).map({Rgb{200, 30, 40}, 0.5f, 0}).color.g == 255);

    RenderConfig truecolor = baseConfig();
    truecolor.color = ColorMode::Truecolor;
    const AsciiCell c = LuminanceMapper(truecolor).map({Rgb{200, 30, 40}, 0.5f, 0});
    CHECK(c.color.r == 200);
    CHECK(c.color.b == 40);
}

TEST_CASE("emoji mapper: hued cell -> emoji, neutral cell -> ASCII ramp", "[mapper]") {
    EmojiMapper mapper(baseConfig());

    const AsciiCell red = mapper.map({Rgb{255, 0, 0}, 0.5f, 0});
    CHECK(red.glyph != " ");
    CHECK(red.glyph.size() > 1);  // multi-byte emoji, not a lone ASCII char

    const AsciiCell grey = mapper.map({Rgb{120, 120, 120}, 0.0f, 0});
    CHECK(grey.glyph.size() == 1);  // ASCII ramp glyph for neutral
}

TEST_CASE("edge mapper: strong gradient -> directional glyph by bin", "[mapper]") {
    RenderConfig cfg = baseConfig();
    cfg.edgeThreshold = 0.15f;
    EdgeMapper mapper(cfg);

    // edgeMagnitude above threshold selects the line glyph for each bin.
    CHECK(mapper.map({Rgb{200, 200, 200}, 0.5f, 0, 0.9f, 0}).glyph == "|");
    CHECK(mapper.map({Rgb{200, 200, 200}, 0.5f, 0, 0.9f, 1}).glyph == "/");
    CHECK(mapper.map({Rgb{200, 200, 200}, 0.5f, 0, 0.9f, 2}).glyph == "-");
    CHECK(mapper.map({Rgb{200, 200, 200}, 0.5f, 0, 0.9f, 3}).glyph == "\\");
}

TEST_CASE("edge mapper: weak gradient falls back to the ramp", "[mapper]") {
    RenderConfig cfg = baseConfig();
    cfg.edgeThreshold = 0.5f;
    EdgeMapper mapper(cfg);

    const AsciiCell flat = mapper.map({Rgb{0, 0, 0}, 0.0f, 0, 0.01f, 1});
    CHECK(flat.glyph == "@");  // darkest ramp glyph, not a line
}
