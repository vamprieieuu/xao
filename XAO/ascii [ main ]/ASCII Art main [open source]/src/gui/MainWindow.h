#pragma once

#include "core/LatestFrameBuffer.h"
#include "engine/AsciiFrame.h"
#include "engine/RenderConfig.h"
#include "pipeline/FrameConverter.h"

#include <QImage>
#include <QMainWindow>
#include <QString>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>

#include <atomic>
#include <memory>
#include <thread>

class QTimer;
class QComboBox;
class QAction;
class QSlider;
class QToolBar;

namespace asciicam::capture {
class IFrameSource;
class FileSource;
}

namespace asciicam::gui {

class AsciiView;

/// A unit of work handed to the conversion worker: a raw frame plus everything
/// needed to render it, so the worker is stateless and race-free.
struct RenderJob {
    cv::Mat frame;
    engine::RenderConfig cfg;
    bool mirror = false;
    int rotation = 0;
    int maxCols = 1;
    int maxRows = 1;
};

/// The worker's output: the ASCII grid and the (transformed) source image used
/// for the inset.
struct RenderResult {
    engine::AsciiFrame ascii;
    QImage inset;
};

/// Main application window: owns the active frame source, the converter, and the
/// render loop that pulls the newest frame, converts it, repaints the view, and
/// (optionally) records video.
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;

    void useWebcam(int device = 0);
    void openFile(const QString& path);

    /// Render the current ASCII frame (with inset) to a PNG at @p path.
    /// Returns false if there is nothing rendered yet. Used by the CLI snapshot.
    bool saveSnapshot(const QString& path);

    /// Start/stop recording without the file dialog (used by the CLI hook).
    void beginRecording(const QString& path);
    void endRecording();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void tick();
    void onOpenFileDialog();
    void onModeChanged(int index);
    void onDetailChanged(int index);
    void onToggleInset(bool on);
    void onToggleHeart(bool on);
    void onSavePng();
    void onToggleRecord(bool on);
    void onSeek(int frame);
    void onTogglePlay(bool paused);

private:
    void setSource(std::unique_ptr<capture::IFrameSource> source);
    void buildToolbar();
    void buildTransportBar();
    void stopRecording();
    void quickSave();
    void rotateStep();           // cycle rotation by 90 degrees
    void applyRenderSettings();  // maps mode + detail level to cell size / ramp
    [[nodiscard]] QImage compositeImage(int scale) const;

    AsciiView* view_ = nullptr;
    QTimer* timer_ = nullptr;

    std::unique_ptr<capture::IFrameSource> source_;
    capture::FileSource* videoSource_ = nullptr;  // non-owning; set when a video is open
    engine::RenderConfig config_;
    cv::Mat lastFrame_;             // most recent raw frame (UI thread)
    engine::AsciiFrame lastAscii_;  // most recent converted frame (for export)
    bool dirty_ = true;             // re-convert needed (new frame or settings changed)

    // Conversion runs on a background worker so heavy processing never stalls the
    // UI: the UI posts jobs and paints finished results.
    void processLoop();
    core::LatestFrameBuffer<RenderJob> jobs_;
    core::LatestFrameBuffer<RenderResult> results_;
    pipeline::FrameConverter procConverter_;  // used ONLY on the worker thread
    std::thread procThread_;
    std::atomic<bool> procRunning_{false};

    cv::VideoWriter writer_;
    bool recording_ = false;
    QString recordPathPending_;  // path chosen before the writer opens on frame 1
    bool mirror_ = true;         // horizontal flip (selfie view) for the webcam
    int detail_ = 2;             // 0=Low 1=Medium 2=High 3=Ultra
    int rotation_ = 0;           // 0/1/2/3 => 0/90/180/270 degrees clockwise

    // Toolbar widgets kept so keyboard shortcuts can drive them and stay in sync.
    QComboBox* modeBox_ = nullptr;
    QComboBox* detailBox_ = nullptr;
    QAction* insetAction_ = nullptr;
    QAction* recordAction_ = nullptr;
    QAction* mirrorAction_ = nullptr;
    QAction* enhanceAction_ = nullptr;
    QAction* invertAction_ = nullptr;

    QToolBar* transportBar_ = nullptr;
    QAction* playAction_ = nullptr;
    QSlider* seekSlider_ = nullptr;
};

}  // namespace asciicam::gui
