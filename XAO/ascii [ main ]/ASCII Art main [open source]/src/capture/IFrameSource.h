#pragma once

#include "core/LatestFrameBuffer.h"

#include <opencv2/core.hpp>

namespace asciicam::capture {

enum class SourceKind {
    Webcam,
    Image,
    Video,
};

/// A source of frames the pipeline can consume, independent of where the frames
/// come from (live camera, an uploaded image, or a video file). Every source
/// publishes into a LatestFrameBuffer, so the consumer always reads the newest
/// frame regardless of the source's own pace.
class IFrameSource {
public:
    virtual ~IFrameSource() = default;

    /// Begin producing frames. Returns false if the source cannot be opened.
    [[nodiscard]] virtual bool start() = 0;

    /// Stop producing and release resources. Safe to call more than once.
    virtual void stop() = 0;

    [[nodiscard]] virtual core::LatestFrameBuffer<cv::Mat>& frames() = 0;

    [[nodiscard]] virtual SourceKind kind() const = 0;
};

}  // namespace asciicam::capture
