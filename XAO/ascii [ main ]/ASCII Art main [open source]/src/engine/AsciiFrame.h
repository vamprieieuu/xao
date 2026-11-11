#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace asciicam::engine {

/// 8-bit RGB colour.
struct Rgb {
    std::uint8_t r{};
    std::uint8_t g{};
    std::uint8_t b{};
};

/// One character cell. The glyph is a UTF-8 string (not a single char) so it can
/// hold multi-byte content — Unicode ramps or full emoji — as well as plain ASCII.
struct AsciiCell {
    std::string glyph = " ";
    Rgb color{};
};

/// A grid of cells produced from a single video frame.
class AsciiFrame {
public:
    AsciiFrame() = default;
    AsciiFrame(int cols, int rows)
        : cols_(cols), rows_(rows), cells_(static_cast<std::size_t>(cols) * rows) {}

    [[nodiscard]] int cols() const { return cols_; }
    [[nodiscard]] int rows() const { return rows_; }
    [[nodiscard]] bool empty() const { return cells_.empty(); }

    [[nodiscard]] AsciiCell& at(int x, int y) { return cells_[index(x, y)]; }
    [[nodiscard]] const AsciiCell& at(int x, int y) const { return cells_[index(x, y)]; }

    /// Flatten to plain text (glyphs only, one row per line). Colour is dropped.
    [[nodiscard]] std::string toText() const {
        std::string out;
        out.reserve(static_cast<std::size_t>(cols_ + 1) * rows_);
        for (int y = 0; y < rows_; ++y) {
            for (int x = 0; x < cols_; ++x) {
                out += cells_[index(x, y)].glyph;
            }
            out += '\n';
        }
        return out;
    }

private:
    [[nodiscard]] std::size_t index(int x, int y) const {
        return static_cast<std::size_t>(y) * cols_ + x;
    }

    int cols_ = 0;
    int rows_ = 0;
    std::vector<AsciiCell> cells_;
};

}  // namespace asciicam::engine
