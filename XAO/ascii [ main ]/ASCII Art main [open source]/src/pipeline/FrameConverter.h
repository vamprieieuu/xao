#pragma once

#include "engine/AsciiFrame.h"
#include "engine/GlyphMapper.h"
#include "engine/RenderConfig.h"

#include <opencv2/core.hpp>

#include <memory>

namespace asciicam::pipeline {

/// Bridges OpenCV frames to the pure engine: downsamples a frame to a character
/// grid (block-averaging each cell via INTER_AREA) with aspect-ratio
/// compensation for non-square glyph cells, then maps every cell to a glyph
/// using the render mode selected in the config.
class FrameConverter {
public:
    explicit FrameConverter(engine::RenderConfig cfg = {});

    void setConfig(const engine::RenderConfig& cfg);
    [[nodiscard]] const engine::RenderConfig& config() const { return cfg_; }

    /// Convert a frame (any channel count) into an AsciiFrame that fits within
    /// @p maxCols x @p maxRows character cells while preserving source aspect.
    [[nodiscard]] engine::AsciiFrame convert(const cv::Mat& frame, int maxCols,
                                             int maxRows) const;

private:
    void rebuildMapper();

    engine::RenderConfig cfg_;
    std::unique_ptr<engine::GlyphMapper> mapper_;
};

}  // namespace asciicam::pipeline
