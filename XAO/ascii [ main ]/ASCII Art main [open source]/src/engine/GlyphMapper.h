#pragma once

#include "engine/AsciiFrame.h"
#include "engine/Color.h"
#include "engine/EmojiPalette.h"
#include "engine/Luminance.h"
#include "engine/Ramp.h"
#include "engine/RenderConfig.h"

#include <string>
#include <string_view>
#include <utility>

namespace asciicam::engine {

/// Aggregated input for one cell: the block-averaged colour, its precomputed
/// luminance (0..1), a per-cell index used for emoji variety, and (for edge
/// mode) the local gradient strength and quantised direction bin.
struct MapInput {
    Rgb color{};
    float luminance01 = 0.0f;
    int index = 0;
    float edgeMagnitude = 0.0f;  ///< 0..1 gradient strength.
    int edgeBin = 0;             ///< 0=|, 1=/, 2=-, 3=\ (see kEdgeGlyphs).
};

/// Turns a per-cell MapInput into an AsciiCell. Strategy-pattern base so render
/// modes (luminance, emoji, later edge-directional) are swappable without the
/// pipeline knowing which is active.
class GlyphMapper {
public:
    virtual ~GlyphMapper() = default;
    [[nodiscard]] virtual AsciiCell map(const MapInput& in) const = 0;
};

/// Classic brightness ramp. Colour is either the sampled RGB (truecolor) or a
/// fixed foreground (monochrome).
class LuminanceMapper final : public GlyphMapper {
public:
    explicit LuminanceMapper(RenderConfig cfg)
        : cfg_(std::move(cfg)), ramp_(rampChars(cfg_.ramp)) {}

    [[nodiscard]] AsciiCell map(const MapInput& in) const override {
        const float y = applyToneMap(in.luminance01, cfg_.contrast, cfg_.brightness);
        const std::size_t idx = rampIndex(y, ramp_.size(), cfg_.invert);
        AsciiCell cell;
        cell.glyph = std::string(1, ramp_[idx]);
        cell.color = (cfg_.color == ColorMode::Truecolor) ? in.color : kMonoGreen;
        return cell;
    }

private:
    static constexpr Rgb kMonoGreen{0, 255, 0};
    RenderConfig cfg_;
    std::string_view ramp_;
};

/// Edge-directional: cells whose local gradient exceeds the threshold are drawn
/// as a line glyph oriented to the edge ( | / - \ ); everything else falls back
/// to a faint luminance ramp so interiors keep their shading. This is the real
/// edge-aware mode — the gradient comes from a Sobel pass in the converter, not
/// from a denser character set masquerading as "edges".
class EdgeMapper final : public GlyphMapper {
public:
    explicit EdgeMapper(RenderConfig cfg)
        : cfg_(std::move(cfg)), ramp_(rampChars(cfg_.ramp)) {}

    [[nodiscard]] AsciiCell map(const MapInput& in) const override {
        const Rgb color = (cfg_.color == ColorMode::Truecolor) ? in.color : kMonoGreen;
        if (in.edgeMagnitude >= cfg_.edgeThreshold) {
            const int bin = ((in.edgeBin % 4) + 4) % 4;
            return AsciiCell{std::string(1, kEdgeGlyphs[static_cast<std::size_t>(bin)]), color};
        }
        const float y = applyToneMap(in.luminance01, cfg_.contrast, cfg_.brightness);
        const std::size_t idx = rampIndex(y, ramp_.size(), cfg_.invert);
        return AsciiCell{std::string(1, ramp_[idx]), color};
    }

private:
    static constexpr Rgb kMonoGreen{0, 255, 0};
    RenderConfig cfg_;
    std::string_view ramp_;
};

/// Colour-themed emoji. Hued cells become an emoji from that colour's set;
/// neutral (grey/dark) cells fall back to the ASCII ramp so structure is kept.
class EmojiMapper final : public GlyphMapper {
public:
    explicit EmojiMapper(RenderConfig cfg)
        : cfg_(std::move(cfg)), ramp_(rampChars(cfg_.ramp)) {}

    [[nodiscard]] AsciiCell map(const MapInput& in) const override {
        const ColorCategory cat = classify(in.color);
        if (cat == ColorCategory::Neutral) {
            const float y = applyToneMap(in.luminance01, cfg_.contrast, cfg_.brightness);
            const std::size_t idx = rampIndex(y, ramp_.size(), cfg_.invert);
            return AsciiCell{std::string(1, ramp_[idx]), in.color};
        }
        return AsciiCell{pickEmoji(cat, in.index), in.color};
    }

private:
    RenderConfig cfg_;
    std::string_view ramp_;
};

}  // namespace asciicam::engine
