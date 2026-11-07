#include "xao/Compositor.h"
#include "xao/Image.h"

#include <cmath>
#include <iostream>

namespace {
bool near(float a, float b) { return std::fabs(a-b) < 1.0e-6f; }
int fail(const char* message) { std::cerr << "FAIL: " << message << '\n'; return 1; }
}

int main() {
    xao::Image base(1, 1), effect(1, 1), out(1, 1);
    base.at(0,0) = {0.1f, 0.0f, 0.0f, 0.5f};
    effect.at(0,0) = {0.0f, 0.4f, 0.0f, 0.5f};

    xao::mixPremultiplied(base, effect, out, 0.5f);
    if (!near(out.at(0,0).r, 0.05f) || !near(out.at(0,0).g, 0.2f) || !near(out.at(0,0).a, 0.5f))
        return fail("premultiplied mix");

    xao::sourceOverPremultiplied(base, effect, out, 1.0f);
    if (!near(out.at(0,0).r, 0.05f) || !near(out.at(0,0).g, 0.4f) || !near(out.at(0,0).a, 0.75f))
        return fail("source-over compositing");

    xao::Image empty;
    if (empty.width() != 0 || empty.height() != 0 || !empty.empty())
        return fail("default empty image");

    std::cout << "XAO core tests passed\n";
    return 0;
}
