#include "capture/FileSource.h"

#include <opencv2/imgcodecs.hpp>

#include <algorithm>
#include <cctype>
#include <chrono>
#include <utility>

namespace asciicam::capture {

namespace {
std::string toLowerExt(const std::string& path) {
    const auto dot = path.find_last_of('.');
    if (dot == std::string::npos) {
        return {};
    }
    std::string ext = path.substr(dot + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(),
                   [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return ext;
}
}  // namespace

bool FileSource::looksLikeImage(const std::string& path) {
    const std::string ext = toLowerExt(path);
    return ext == "jpg" || ext == "jpeg" || ext == "png" || ext == "bmp" ||
           ext == "webp" || ext == "tif" || ext == "tiff";
}

FileSource::FileSource(std::string path) : path_(std::move(path)) {
    kind_ = looksLikeImage(path_) ? SourceKind::Image : SourceKind::Video;
}

FileSource::~FileSource() { stop(); }

bool FileSource::start() {
    if (running_.load()) {
        return true;
    }
    if (kind_ == SourceKind::Image) {
        cv::Mat img = cv::imread(path_, cv::IMREAD_COLOR);
        if (img.empty()) {
            return false;
        }
        running_.store(true);
        buffer_.push(std::move(img));  // published once; consumer keeps the last frame
        return true;
    }

    if (!video_.open(path_)) {
        return false;
    }
    totalFrames_ = static_cast<int>(video_.get(cv::CAP_PROP_FRAME_COUNT));
    running_.store(true);
    thread_ = std::thread(&FileSource::runVideo, this);
    return true;
}

void FileSource::stop() {
    running_.store(false);
    buffer_.close();
    if (thread_.joinable()) {
        thread_.join();
    }
    if (video_.isOpened()) {
        video_.release();
    }
}

void FileSource::runVideo() {
    double fps = video_.get(cv::CAP_PROP_FPS);
    if (fps <= 1.0 || fps > 240.0) {
        fps = 25.0;  // fall back for containers that don't report a sane rate
    }
    const auto framePeriod =
        std::chrono::duration_cast<std::chrono::steady_clock::duration>(
            std::chrono::duration<double>(1.0 / fps));

    while (running_.load()) {
        // Honour a pending seek first.
        const int target = seekTarget_.exchange(-1);
        if (target >= 0) {
            video_.set(cv::CAP_PROP_POS_FRAMES, target);
        }

        // When paused, idle unless a seek just happened (so a scrub still shows
        // the frame you land on).
        if (paused_.load() && target < 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            continue;
        }

        cv::Mat frame;
        if (!video_.read(frame) || frame.empty()) {
            video_.set(cv::CAP_PROP_POS_FRAMES, 0);  // loop
            currentFrame_.store(0);
            continue;
        }
        currentFrame_.store(static_cast<int>(video_.get(cv::CAP_PROP_POS_FRAMES)));

        const auto next = std::chrono::steady_clock::now() + framePeriod;
        buffer_.push(std::move(frame));
        std::this_thread::sleep_until(next);
    }
}

}  // namespace asciicam::capture
