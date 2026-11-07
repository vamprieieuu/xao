#include "xao/Image.h"

#include <limits>
#include <stdexcept>

namespace xao {

Image::Image(int width, int height) { reset(width, height); }

void Image::reset(int width, int height) {
    if (width < 0 || height < 0) throw std::invalid_argument("Image dimensions cannot be negative");
    const auto w = static_cast<std::size_t>(width);
    const auto h = static_cast<std::size_t>(height);
    if (h != 0 && w > std::numeric_limits<std::size_t>::max() / h)
        throw std::length_error("Image dimensions overflow addressable storage");
    width_ = width;
    height_ = height;
    pixels_.assign(w * h, Pixel{});
}

Pixel* Image::row(int y) noexcept {
    return (y < 0 || y >= height_) ? nullptr : pixels_.data() + static_cast<std::size_t>(y) * width_;
}

const Pixel* Image::row(int y) const noexcept {
    return (y < 0 || y >= height_) ? nullptr : pixels_.data() + static_cast<std::size_t>(y) * width_;
}

Pixel& Image::at(int x, int y) noexcept { return pixels_[static_cast<std::size_t>(y) * width_ + x]; }
const Pixel& Image::at(int x, int y) const noexcept { return pixels_[static_cast<std::size_t>(y) * width_ + x]; }

} // namespace xao
