#include "capture/CameraCapture.h"

#include <utility>

namespace asciicam::capture {

CameraCapture::CameraCapture(int deviceIndex) : deviceIndex_(deviceIndex) {}

CameraCapture::~CameraCapture() { stop(); }

bool CameraCapture::start() {
    if (running_.load()) {
        return true;
    }
    if (!cap_.open(deviceIndex_)) {
        return false;
    }
    running_.store(true);
    thread_ = std::thread(&CameraCapture::run, this);
    return true;
}

void CameraCapture::stop() {
    running_.store(false);
    buffer_.close();  // wake a consumer blocked in wait_pop()
    if (thread_.joinable()) {
        thread_.join();
    }
    if (cap_.isOpened()) {
        cap_.release();
    }
}

void CameraCapture::run() {
    while (running_.load()) {
        cv::Mat frame;
        // read() blocks until the next frame; a transient failure just retries.
        if (!cap_.read(frame) || frame.empty()) {
            continue;
        }
        buffer_.push(std::move(frame));
    }
}

}  // namespace asciicam::capture
