#include "capture/CameraCapture.h"
#include "capture/FileSource.h"
#include "core/LatestFrameBuffer.h"
#include "engine/RenderConfig.h"
#include "pipeline/FrameConverter.h"

#include <opencv2/core.hpp>

#include <atomic>
#include <chrono>
#include <csignal>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

namespace {

std::atomic<bool> g_stop{false};
void onSignal(int) { g_stop.store(true); }

struct Options {
    int device = 0;
    long maxFrames = -1;  // -1 => run until Ctrl+C
    std::string file;     // if set, convert this image/video frame to ASCII and exit
    int width = 100;      // grid width for --file mode
    bool emoji = false;   // use the color-emoji render mode
    bool edge = false;    // use the edge-directional render mode
    bool heart = false;   // enable heart-shape detection & fill
};

Options parseArgs(int argc, char** argv) {
    Options opt;
    for (int i = 1; i < argc; ++i) {
        const std::string a = argv[i];
        if ((a == "--device" || a == "-d") && i + 1 < argc) {
            opt.device = std::atoi(argv[++i]);
        } else if ((a == "--frames" || a == "-n") && i + 1 < argc) {
            opt.maxFrames = std::atol(argv[++i]);
        } else if ((a == "--file" || a == "-f") && i + 1 < argc) {
            opt.file = argv[++i];
        } else if ((a == "--width" || a == "-w") && i + 1 < argc) {
            opt.width = std::atoi(argv[++i]);
        } else if (a == "--emoji") {
            opt.emoji = true;
        } else if (a == "--edge") {
            opt.edge = true;
        } else if (a == "--heart") {
            opt.heart = true;
        } else if (a == "--help" || a == "-h") {
            std::cout << "usage: ascii_cam [options]\n"
                      << "  --device, -d N   camera index (default 0)\n"
                      << "  --frames, -n N   stop after N frames (webcam mode)\n"
                      << "  --file,   -f P   convert image/video P to ASCII and print\n"
                      << "  --width,  -w N   grid width for --file mode (default 100)\n"
                      << "  --emoji          use the color-emoji render mode\n";
            std::exit(0);
        }
    }
    return opt;
}

// Convert a single frame of an image/video file to ASCII and print it.
int runFileMode(const Options& opt) {
    asciicam::capture::FileSource source(opt.file);
    if (!source.start()) {
        std::cerr << "error: could not open file " << opt.file << "\n";
        return 1;
    }
    const auto frame = source.frames().wait_pop();
    source.stop();
    if (!frame) {
        std::cerr << "error: no frame decoded from " << opt.file << "\n";
        return 1;
    }

    asciicam::engine::RenderConfig cfg;
    if (opt.edge) {
        cfg.mode = asciicam::engine::RenderMode::EdgeDirectional;
    } else if (opt.emoji) {
        cfg.mode = asciicam::engine::RenderMode::ColorEmoji;
    } else {
        cfg.mode = asciicam::engine::RenderMode::Luminance;
    }
    cfg.color = asciicam::engine::ColorMode::Truecolor;
    cfg.heartFill = opt.heart;

    asciicam::pipeline::FrameConverter converter(cfg);
    const auto ascii = converter.convert(*frame, opt.width, 10000);
    std::cout << ascii.toText();
    return 0;
}

// Live webcam capture with an FPS / dropped-frame readout.
int runWebcamMode(const Options& opt) {
    std::signal(SIGINT, onSignal);

    asciicam::capture::CameraCapture camera(opt.device);
    if (!camera.start()) {
        std::cerr << "error: could not open camera device " << opt.device << "\n";
        return 1;
    }
    std::cout << "camera " << opt.device << " opened — press Ctrl+C to stop.\n";

    using clock = std::chrono::steady_clock;
    auto lastReport = clock::now();
    long framesThisWindow = 0;
    long totalFrames = 0;

    while (!g_stop.load()) {
        const auto frame = camera.frames().wait_pop();
        if (!frame) {
            break;
        }
        ++framesThisWindow;
        ++totalFrames;

        const auto now = clock::now();
        const auto elapsedMs =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - lastReport).count();
        if (elapsedMs >= 1000) {
            const double fps = framesThisWindow * 1000.0 / static_cast<double>(elapsedMs);
            std::cout << "\rfps: " << std::fixed << std::setprecision(1) << fps
                      << "   frame: " << frame->cols << "x" << frame->rows
                      << "   dropped: " << camera.frames().dropped() << "        " << std::flush;
            framesThisWindow = 0;
            lastReport = now;
        }
        if (opt.maxFrames > 0 && totalFrames >= opt.maxFrames) {
            break;
        }
    }

    camera.stop();
    std::cout << "\ncaptured " << totalFrames << " frames, dropped "
              << camera.frames().dropped() << ".\n";
    return 0;
}

}  // namespace

int main(int argc, char** argv) {
    const Options opt = parseArgs(argc, argv);
    return opt.file.empty() ? runWebcamMode(opt) : runFileMode(opt);
}
