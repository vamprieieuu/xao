#pragma once

#include "xao/Image.h"

namespace xao {

// Mix two premultiplied working images. Amount is clamped to [0, 1].
void mixPremultiplied(const Image& base, const Image& effect, Image& output, float amount);

// Premultiplied source-over compositing. Source opacity is applied before compositing.
void sourceOverPremultiplied(const Image& base, const Image& source, Image& output, float opacity);

} // namespace xao
