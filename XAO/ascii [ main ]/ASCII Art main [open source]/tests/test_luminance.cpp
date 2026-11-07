#include "engine/Luminance.h"
#include "engine/Ramp.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

using Catch::Matchers::WithinAbs;
using namespace asciicam::engine;

TEST_CASE("luminance is bounded and monotonic in brightness", "[luminance]") {
    CHECK_THAT(luminance(0, 0, 0), WithinAbs(0.0f, 1e-6f));
    CHECK_THAT(luminance(255, 255, 255), WithinAbs(1.0f, 1e-4f));
    CHECK(luminance(128, 128, 128) < luminance(200, 200, 200));
}

TEST_CASE("green contributes more than red or blue (Rec.709)", "[luminance]") {
    CHECK(luminance(0, 255, 0) > luminance(255, 0, 0));
    CHECK(luminance(0, 255, 0) > luminance(0, 0, 255));
}

TEST_CASE("tone map clamps to 0..1", "[luminance]") {
    CHECK_THAT(applyToneMap(1.0f, 3.0f, 0.5f), WithinAbs(1.0f, 1e-6f));
    CHECK_THAT(applyToneMap(0.0f, 3.0f, -0.5f), WithinAbs(0.0f, 1e-6f));
}

TEST_CASE("ramp index spans the whole ramp and honours invert", "[ramp]") {
    const auto ramp = rampChars("standard");
    const std::size_t n = ramp.size();

    CHECK(rampIndex(0.0f, n) == 0);
    CHECK(rampIndex(1.0f, n) == n - 1);

    // Inversion maps the darkest luminance to the opposite end.
    CHECK(rampIndex(0.0f, n, /*invert=*/true) == n - 1);
}

TEST_CASE("unknown ramp name falls back to standard", "[ramp]") {
    CHECK(rampChars("does-not-exist") == rampChars("standard"));
}
