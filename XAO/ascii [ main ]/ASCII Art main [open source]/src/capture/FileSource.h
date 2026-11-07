#pragma once

#include "capture/IFrameSource.h"
#include "core/LatestFrameBuffer.h"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <atomic>
#include <string>
#include <thread>

namespace asciicam::capture {

/// A frame source backed by a file on disk. A still image is published once (and
/// re-used by the consumer); a video is decoded on a background thread, paced to
/// its native frame rate, and looped when it reaches the end.
class FileSource : public IFrameSource {
public:
    explicit FileSource(std::string path);
    ~FileSource() override;

    FileSource(const FileSource&) = delete;
    FileSource& operator=(const FileSource&) = delete;

    [[nodiscard]] bool start() override;
    void stop() override;
    [[nodiscard]] core::LatestFrameBuffer<cv::Mat>& frames() override { return buffer_; }
    [[nodiscard]] SourceKind kind() const override { return kind_; }

    // --- Video transport controls (no-ops for images) ---
    [[nodiscard]] bool isVideo() const { return kind_ == SourceKind::Video; }
    [[nodiscard]] int totalFrames() const { return totalFrames_; }
    [[nodiscard]] int currentFrame() const { return currentFrame_.load(); }
    void seek(int frame) { seekTarget_.store(frame); }
    void setPaused(bool paused) { paused_.store(paused); }
    [[nodiscard]] bool paused() const { return paused_.load(); }

    /// True if the given path looks like a still image (by extension).
    [[nodiscard]] static bool looksLikeImage(const std::string& path);

private:
    void runVideo();  // Video-decode thread body.

    std::string path_;
    SourceKind kind_ = SourceKind::Image;
    cv::VideoCapture video_;
    core::LatestFrameBuffer<cv::Mat> buffer_;
    std::thread thread_;
    std::atomic<bool> running_{false};

    int totalFrames_ = 0;
    std::atomic<int> currentFrame_{0};
    std::atomic<int> seekTarget_{-1};  // >=0 requests a seek to that frame
    std::atomic<bool> paused_{false};
};

}  // namespace asciicam::capture
