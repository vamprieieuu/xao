#pragma once

#include <cstddef>
#include <vector>

namespace xao {

// Internal working pixels are linear-light, premultiplied RGBA floats.
struct Pixel {
    float r = 0.0f;
    float g = 0.0f;
    float b = 0.0f;
    float a = 0.0f;
};

class Image {
public:
    Image() = default;
    Image(int width, int height);

    void reset(int width, int height);
    int width() const noexcept { return width_; }
    int height() const noexcept { return height_; }
    bool empty() const noexcept { return pixels_.empty(); }
    std::size_t stridePixels() const noexcept { return static_cast<std::size_t>(width_); }

    Pixel* row(int y) noexcept;
    const Pixel* row(int y) const noexcept;
    Pixel& at(int x, int y) noexcept;
    const Pixel& at(int x, int y) const noexcept;
    std::vector<Pixel>& pixels() noexcept { return pixels_; }
    const std::vector<Pixel>& pixels() const noexcept { return pixels_; }

private:
    int width_ = 0;
    int height_ = 0;
    std::vector<Pixel> pixels_;
};

} // namespace xao
