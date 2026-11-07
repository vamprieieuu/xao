#include "xao/Compositor.h"

#include <algorithm>
#include <stdexcept>

namespace xao {
namespace {
void validateSameSize(const Image& a, const Image& b, const Image& out) {
    if (a.width() != b.width() || a.height() != b.height() ||
        a.width() != out.width() || a.height() != out.height())
        throw std::invalid_argument("Compositor images must have identical dimensions");
}
float clamp01(float x) { return std::max(0.0f, std::min(1.0f, x)); }
}

void mixPremultiplied(const Image& base, const Image& effect, Image& output, float amount) {
    validateSameSize(base, effect, output);
    const float t = clamp01(amount), u = 1.0f - t;
    for (std::size_t i = 0; i < output.pixels().size(); ++i) {
        const Pixel& a = base.pixels()[i];
        const Pixel& b = effect.pixels()[i];
        output.pixels()[i] = {a.r*u+b.r*t, a.g*u+b.g*t, a.b*u+b.b*t, a.a*u+b.a*t};
    }
}

void sourceOverPremultiplied(const Image& base, const Image& source, Image& output, float opacity) {
    validateSameSize(base, source, output);
    const float o = clamp01(opacity);
    for (std::size_t i = 0; i < output.pixels().size(); ++i) {
        const Pixel& d = base.pixels()[i];
        const Pixel& s = source.pixels()[i];
        const float sa = clamp01(s.a * o);
        const float inv = 1.0f - sa;
        output.pixels()[i] = {s.r*o + d.r*inv, s.g*o + d.g*inv,
                              s.b*o + d.b*inv, sa + d.a*inv};
    }
}

} // namespace xao
