#include "engine/Color.h"
#include "engine/EmojiPalette.h"

#include <catch2/catch_test_macros.hpp>

using namespace asciicam::engine;

TEST_CASE("primary colours classify into the expected hue buckets", "[color]") {
    CHECK(classify(Rgb{255, 0, 0}) == ColorCategory::Red);
    CHECK(classify(Rgb{0, 255, 0}) == ColorCategory::Green);
    CHECK(classify(Rgb{0, 0, 255}) == ColorCategory::Blue);
    CHECK(classify(Rgb{0, 255, 255}) == ColorCategory::Cyan);
    CHECK(classify(Rgb{255, 105, 180}) == ColorCategory::Pink);  // hot pink
}

TEST_CASE("only bright vivid red is Red; orange and dull reds are not", "[color]") {
    CHECK(classify(Rgb{255, 0, 0}) == ColorCategory::Red);        // vivid red
    CHECK(classify(Rgb{255, 140, 0}) == ColorCategory::Orange);   // orange, NOT red
    CHECK(classify(Rgb{90, 40, 40}) == ColorCategory::Neutral);   // dark dull red -> no emoji
    CHECK(classify(Rgb{210, 130, 130}) != ColorCategory::Red);    // washed-out red -> no red emoji
}

TEST_CASE("greys and near-black/white are Neutral", "[color]") {
    CHECK(classify(Rgb{128, 128, 128}) == ColorCategory::Neutral);
    CHECK(classify(Rgb{0, 0, 0}) == ColorCategory::Neutral);
    CHECK(classify(Rgb{255, 255, 255}) == ColorCategory::Neutral);
    CHECK(classify(Rgb{10, 8, 9}) == ColorCategory::Neutral);  // very dark
}

TEST_CASE("emoji palette returns a non-empty glyph for hued cells", "[emoji]") {
    CHECK(pickEmoji(ColorCategory::Red, 0) != " ");
    CHECK_FALSE(pickEmoji(ColorCategory::Pink, 0).empty());
}

TEST_CASE("emoji variety cycles and tolerates negative indices", "[emoji]") {
    const auto a = pickEmoji(ColorCategory::Red, 0);
    const auto b = pickEmoji(ColorCategory::Red, 1);
    CHECK(a != b);                                    // variety actually varies
    CHECK(pickEmoji(ColorCategory::Red, 4) == a);     // wraps (set of 4)
    CHECK(pickEmoji(ColorCategory::Red, -4) == a);    // negative-safe
}

TEST_CASE("neutral category yields a space (mapper substitutes ASCII)", "[emoji]") {
    CHECK(pickEmoji(ColorCategory::Neutral, 0) == " ");
}
