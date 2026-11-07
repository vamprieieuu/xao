#include "xao/Compositor.h"
#include "xao/Image.h"
#include "xao/Pipeline.h"

#include <cmath>
#include <iostream>
#include <vector>

namespace {
bool near(float a, float b) { return std::fabs(a-b) < 1.0e-6f; }
int fail(const char* message) { std::cerr << "FAIL: " << message << '\n'; return 1; }
}

class HalfRedEngine final : public xao::Engine {
public:
    const char* id() const noexcept override { return "test.half-red"; }
    void render(const xao::Image& source, xao::Image& destination, const xao::RenderContext&) const override {
        for (std::size_t i = 0; i < source.pixels().size(); ++i) {
            const auto& p = source.pixels()[i];
            destination.pixels()[i] = {p.r * 0.5f, p.g, p.b, p.a};
        }
    }
};

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

    HalfRedEngine engine;
    xao::Pipeline pipeline;
    xao::Image input(1, 1), result(1, 1);
    input.at(0,0) = {0.8f, 0.2f, 0.1f, 1.0f};
    const std::vector<xao::EnginePass> passes = {{&engine, true, 1.0f, xao::CompositeMode::Mix}};
    pipeline.render(input, result, passes, xao::RenderContext{});
    if (!near(result.at(0,0).r, 0.4f) || !near(result.at(0,0).g, 0.2f))
        return fail("ordered engine pipeline");

    std::cout << "XAO core tests passed\n";
    return 0;
}
