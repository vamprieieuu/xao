#include "pipeline/FrameConverter.h"

#include "engine/Luminance.h"

#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <cmath>
#include <vector>

namespace asciicam::pipeline {

using engine::AsciiFrame;
using engine::RenderConfig;
using engine::RenderMode;
using engine::Rgb;

namespace {

/// A canonical heart outline (parametric heart curve) used as the template that
/// detected red blobs are compared against with matchShapes.
const std::vector<cv::Point>& heartTemplate() {
    static const std::vector<cv::Point> pts = [] {
        std::vector<cv::Point> p;
        for (double t = 0.0; t < 2.0 * 3.14159265; t += 0.05) {
            const double x = 16.0 * std::pow(std::sin(t), 3);
            const double y = 13.0 * std::cos(t) - 5.0 * std::cos(2 * t) -
                             2.0 * std::cos(3 * t) - std::cos(4 * t);
            p.emplace_back(static_cast<int>(x * 4 + 100), static_cast<int>(-y * 4 + 100));
        }
        return p;
    }();
    return pts;
}

/// Build a cell-grid mask (non-zero where a heart-shaped red region was found).
/// Detection runs at a moderate working resolution (not the coarse cell grid) so
/// contours are smooth enough for shape matching, then the mask is downsampled
/// to the grid. Best-effort: matches clear heart contours, not hand gestures.
cv::Mat detectHeartCells(const cv::Mat& frameBgr, cv::Size grid) {
    constexpr int kWorkW = 256;
    const int workH = std::max(
        1, static_cast<int>(std::lround(kWorkW * static_cast<double>(frameBgr.rows) /
                                        std::max(1, frameBgr.cols))));
    cv::Mat work;
    cv::resize(frameBgr, work, cv::Size(kWorkW, workH), 0, 0, cv::INTER_AREA);

    cv::Mat hsv;
    cv::cvtColor(work, hsv, cv::COLOR_BGR2HSV);

    // Match red AND pink/magenta regions (OpenCV hue is 0..180). Red wraps hue 0,
    // so threshold both ends; add a magenta/pink band so pink hearts also match.
    cv::Mat lo, hi, mag;
    cv::inRange(hsv, cv::Scalar(0, 70, 50), cv::Scalar(12, 255, 255), lo);
    cv::inRange(hsv, cv::Scalar(158, 70, 50), cv::Scalar(180, 255, 255), hi);
    cv::inRange(hsv, cv::Scalar(140, 45, 60), cv::Scalar(160, 255, 255), mag);
    cv::Mat red = lo | hi | mag;
    const cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, {5, 5});
    cv::morphologyEx(red, red, cv::MORPH_CLOSE, kernel);
    cv::morphologyEx(red, red, cv::MORPH_OPEN, kernel);  // drop speckle

    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(red, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    cv::Mat mask = cv::Mat::zeros(work.size(), CV_8U);
    const double minArea = 0.015 * work.total();
    for (std::size_t i = 0; i < contours.size(); ++i) {
        if (cv::contourArea(contours[i]) < minArea) {
            continue;
        }
        const double diff =
            cv::matchShapes(contours[i], heartTemplate(), cv::CONTOURS_MATCH_I1, 0.0);
        if (diff < 0.55) {  // lower == closer to a heart (best-effort)
            cv::drawContours(mask, contours, static_cast<int>(i), cv::Scalar(255), cv::FILLED);
        }
    }

    cv::Mat cellMask;
    cv::resize(mask, cellMask, grid, 0, 0, cv::INTER_NEAREST);
    return cellMask;
}

/// Boost local detail before downsampling: CLAHE (adaptive local contrast) on
/// the luminance channel so shadow/highlight detail survives, then an unsharp
/// mask to crisp up edges. This is what makes features "well defined" once the
/// image is reduced to characters.
cv::Mat enhanceForDetail(const cv::Mat& bgr) {
    cv::Mat work = bgr;
    if (work.channels() == 4) {
        cv::cvtColor(work, work, cv::COLOR_BGRA2BGR);
    } else if (work.channels() == 1) {
        cv::cvtColor(work, work, cv::COLOR_GRAY2BGR);
    }

    // Local contrast on the L channel of Lab.
    cv::Mat lab;
    cv::cvtColor(work, lab, cv::COLOR_BGR2Lab);
    std::vector<cv::Mat> ch;
    cv::split(lab, ch);
    static cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE(2.5, cv::Size(8, 8));
    clahe->apply(ch[0], ch[0]);
    cv::merge(ch, lab);
    cv::cvtColor(lab, work, cv::COLOR_Lab2BGR);

    // Unsharp mask: sharpened = 1.5*img - 0.5*blur.
    cv::Mat blur;
    cv::GaussianBlur(work, blur, cv::Size(0, 0), 2.0);
    cv::addWeighted(work, 1.5, blur, -0.5, 0, work);
    return work;
}

}  // namespace

FrameConverter::FrameConverter(RenderConfig cfg) : cfg_(std::move(cfg)) { rebuildMapper(); }

void FrameConverter::setConfig(const RenderConfig& cfg) {
    cfg_ = cfg;
    rebuildMapper();
}

void FrameConverter::rebuildMapper() {
    switch (cfg_.mode) {
        case RenderMode::ColorEmoji:
            mapper_ = std::make_unique<engine::EmojiMapper>(cfg_);
            break;
        case RenderMode::EdgeDirectional:
            mapper_ = std::make_unique<engine::EdgeMapper>(cfg_);
            break;
        case RenderMode::Luminance:
        default:
            mapper_ = std::make_unique<engine::LuminanceMapper>(cfg_);
            break;
    }
}

AsciiFrame FrameConverter::convert(const cv::Mat& frameIn, int maxCols, int maxRows) const {
    if (frameIn.empty() || maxCols <= 0 || maxRows <= 0) {
        return {};
    }

    const cv::Mat frame = cfg_.enhance ? enhanceForDetail(frameIn) : frameIn;

    // Choose a grid that preserves physical aspect given non-square glyph cells:
    //   (cols*cellW) / (rows*cellH) == srcW / srcH
    const double srcW = frame.cols;
    const double srcH = frame.rows;
    const double cellAspect =
        static_cast<double>(cfg_.cellWidth) / std::max(1, cfg_.cellHeight);  // w/h

    int cols = maxCols;
    int rows = static_cast<int>(std::lround(cols * (srcH / srcW) * cellAspect));
    if (rows > maxRows) {
        rows = maxRows;
        cols = static_cast<int>(std::lround(rows * (srcW / srcH) / cellAspect));
    }
    cols = std::clamp(cols, 1, maxCols);
    rows = std::clamp(rows, 1, maxRows);

    // Block-average down to the grid. INTER_AREA is a true area average — this is
    // our per-cell block averaging, giving cleaner output than single-pixel picks.
    cv::Mat small;
    cv::resize(frame, small, cv::Size(cols, rows), 0, 0, cv::INTER_AREA);

    // Normalise to 3-channel BGR 8-bit.
    if (small.channels() == 4) {
        cv::cvtColor(small, small, cv::COLOR_BGRA2BGR);
    } else if (small.channels() == 1) {
        cv::cvtColor(small, small, cv::COLOR_GRAY2BGR);
    }

    // For edge mode, run a Sobel pass on the downsampled luminance to get a
    // per-cell gradient magnitude (normalised 0..1) and orientation bin.
    const bool edgeMode = cfg_.mode == RenderMode::EdgeDirectional;
    cv::Mat gx, gy;
    if (edgeMode) {
        cv::Mat gray;
        cv::cvtColor(small, gray, cv::COLOR_BGR2GRAY);
        cv::Sobel(gray, gx, CV_32F, 1, 0, 3);
        cv::Sobel(gray, gy, CV_32F, 0, 1, 3);
    }
    constexpr float kSobelMax = 4.0f * 255.0f;  // max |response| for a 3x3 Sobel

    AsciiFrame out(cols, rows);
    for (int y = 0; y < rows; ++y) {
        const auto* row = small.ptr<cv::Vec3b>(y);
        for (int x = 0; x < cols; ++x) {
            const cv::Vec3b& px = row[x];  // BGR
            const Rgb color{px[2], px[1], px[0]};
            const float lum = engine::luminance(color.r, color.g, color.b, cfg_.gamma);

            engine::MapInput in{color, lum, y * cols + x, 0.0f, 0};
            if (edgeMode) {
                const float dx = gx.at<float>(y, x);
                const float dy = gy.at<float>(y, x);
                in.edgeMagnitude = std::min(1.0f, std::sqrt(dx * dx + dy * dy) / kSobelMax);
                // Gradient angle folded to [0,180); binned so 0=|,1=/,2=-,3=\.
                float deg = std::atan2(dy, dx) * 180.0f / 3.14159265f;
                if (deg < 0.0f) deg += 180.0f;
                in.edgeBin = static_cast<int>((deg + 22.5f) / 45.0f) % 4;
            }
            out.at(x, y) = mapper_->map(in);
        }
    }

    // Fun overlay: stamp 💖 over cells inside a detected heart region.
    if (cfg_.heartFill) {
        const cv::Mat heart = detectHeartCells(frame, cv::Size(cols, rows));
        for (int y = 0; y < rows; ++y) {
            const auto* m = heart.ptr<std::uint8_t>(y);
            for (int x = 0; x < cols; ++x) {
                if (m[x]) {
                    out.at(x, y) = engine::AsciiCell{"\U0001F496", Rgb{255, 105, 180}};  // 💖
                }
            }
        }
    }
    return out;
}

}  // namespace asciicam::pipeline
