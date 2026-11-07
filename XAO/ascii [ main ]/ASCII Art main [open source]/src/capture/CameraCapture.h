#pragma once

#include "capture/IFrameSource.h"
#include "core/LatestFrameBuffer.h"

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <atomic>
#include <thread>

namespace asciicam::capture {

/// Owns a background thread that continuously grabs frames from a webcam and
/// publishes the newest one into a LatestFrameBuffer. The capture thread never
/// blocks on the consumer: if the consumer is slow, older frames are simply
/// overwritten, so the feed stays real-time.
///
/// Lifetime follows RAII — the thread is launched in start() and always cleanly
/// joined in stop() / the destructor.
class CameraCapture : public IFrameSource {
public:
    explicit CameraCapture(int deviceIndex = 0);
    ~CameraCapture() override;

    CameraCapture(const CameraCapture&) = delete;
    CameraCapture& operator=(const CameraCapture&) = delete;

    /// Open the device and launch the capture thread.
    /// @return false if the camera could not be opened.
    [[nodiscard]] bool start() override;

    /// Stop the thread, wake any waiting consumer, and release the device.
    /// Safe to call multiple times.
    void stop() override;

    /// The buffer from which the consumer reads the most recent frame.
    [[nodiscard]] core::LatestFrameBuffer<cv::Mat>& frames() override { return buffer_; }

    [[nodiscard]] SourceKind kind() const override { return SourceKind::Webcam; }

    [[nodiscard]] bool running() const { return running_.load(); }

private:
    void run();  // Capture-thread body.

    int deviceIndex_;
    cv::VideoCapture cap_;
    core::LatestFrameBuffer<cv::Mat> buffer_;
    std::thread thread_;
    std::atomic<bool> running_{false};
};

}  // namespace asciicam::capture
