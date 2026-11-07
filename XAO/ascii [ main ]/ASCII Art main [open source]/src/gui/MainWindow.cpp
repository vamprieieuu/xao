#include "gui/MainWindow.h"

#include "capture/CameraCapture.h"
#include "capture/FileSource.h"
#include "gui/AsciiRenderer.h"
#include "gui/AsciiView.h"

#include <opencv2/imgproc.hpp>

#include <QAction>
#include <QComboBox>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QImage>
#include <QKeyEvent>
#include <QLabel>
#include <QSignalBlocker>
#include <QSlider>
#include <QStatusBar>
#include <QTimer>
#include <QToolBar>

#include <utility>

namespace asciicam::gui {

namespace {

QImage matToQImage(const cv::Mat& bgr) {
    if (bgr.empty()) {
        return {};
    }
    cv::Mat rgb;
    cv::cvtColor(bgr, rgb, cv::COLOR_BGR2RGB);
    return QImage(rgb.data, rgb.cols, rgb.rows, static_cast<int>(rgb.step),
                  QImage::Format_RGB888)
        .copy();  // deep copy: rgb is about to go out of scope
}

cv::Mat qImageToBgrMat(const QImage& imageRgb888) {
    cv::Mat rgb(imageRgb888.height(), imageRgb888.width(), CV_8UC3,
                const_cast<uchar*>(imageRgb888.bits()),
                static_cast<std::size_t>(imageRgb888.bytesPerLine()));
    cv::Mat bgr;
    cv::cvtColor(rgb, bgr, cv::COLOR_RGB2BGR);
    return bgr;
}

}  // namespace

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    config_.mode = engine::RenderMode::Luminance;
    config_.color = engine::ColorMode::Truecolor;
    config_.contrast = 1.35f;  // a touch more punch so features are better defined

    procRunning_.store(true);
    procThread_ = std::thread(&MainWindow::processLoop, this);

    view_ = new AsciiView(this);
    setCentralWidget(view_);
    buildToolbar();
    buildTransportBar();

    setWindowTitle("ascii-cam");
    resize(1000, 700);

    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &MainWindow::tick);
    timer_->start(33);  // ~30 Hz render loop
}

MainWindow::~MainWindow() {
    // Stop the worker first so it can't touch anything mid-teardown.
    procRunning_.store(false);
    jobs_.close();
    if (procThread_.joinable()) {
        procThread_.join();
    }
    stopRecording();
    if (source_) {
        source_->stop();
    }
}

void MainWindow::processLoop() {
    while (procRunning_.load()) {
        const auto job = jobs_.wait_pop();
        if (!job) {
            break;  // closed
        }

        cv::Mat frame;
        if (job->mirror) {
            cv::flip(job->frame, frame, 1);
        } else {
            frame = job->frame;
        }
        if (job->rotation != 0) {
            const int code = job->rotation == 1 ? cv::ROTATE_90_CLOCKWISE
                             : job->rotation == 2 ? cv::ROTATE_180
                                                  : cv::ROTATE_90_COUNTERCLOCKWISE;
            cv::Mat rotated;
            cv::rotate(frame, rotated, code);
            frame = rotated;
        }

        procConverter_.setConfig(job->cfg);
        RenderResult res;
        res.ascii = procConverter_.convert(frame, job->maxCols, job->maxRows);
        res.inset = matToQImage(frame);
        results_.push(std::move(res));
    }
}

void MainWindow::buildToolbar() {
    QToolBar* bar = addToolBar("Main");
    bar->setMovable(false);

    connect(bar->addAction("Webcam"), &QAction::triggered, this, [this] { useWebcam(0); });
    connect(bar->addAction("Open Image/Video…"), &QAction::triggered, this,
            &MainWindow::onOpenFileDialog);

    bar->addSeparator();
    bar->addWidget(new QLabel(" Mode: "));
    modeBox_ = new QComboBox(this);
    modeBox_->addItem("Luminance");
    modeBox_->addItem("Color");
    modeBox_->addItem("Edge");
    connect(modeBox_, &QComboBox::currentIndexChanged, this, &MainWindow::onModeChanged);
    bar->addWidget(modeBox_);

    bar->addWidget(new QLabel(" Detail: "));
    detailBox_ = new QComboBox(this);
    detailBox_->addItem("Low");
    detailBox_->addItem("Medium");
    detailBox_->addItem("High");
    detailBox_->addItem("Ultra");
    connect(detailBox_, &QComboBox::currentIndexChanged, this, &MainWindow::onDetailChanged);
    bar->addWidget(detailBox_);

    bar->addSeparator();
    mirrorAction_ = bar->addAction("Mirror");
    mirrorAction_->setCheckable(true);
    mirrorAction_->setChecked(true);
    connect(mirrorAction_, &QAction::toggled, this, [this](bool on) {
        mirror_ = on;
        dirty_ = true;
    });

    insetAction_ = bar->addAction("Inset");
    insetAction_->setCheckable(true);
    insetAction_->setChecked(true);
    connect(insetAction_, &QAction::toggled, this, &MainWindow::onToggleInset);

    enhanceAction_ = bar->addAction("Enhance");
    enhanceAction_->setCheckable(true);
    enhanceAction_->setChecked(true);
    connect(enhanceAction_, &QAction::toggled, this, [this](bool on) {
        config_.enhance = on;
        dirty_ = true;
    });

    invertAction_ = bar->addAction("Invert");
    invertAction_->setCheckable(true);
    connect(invertAction_, &QAction::toggled, this, [this](bool on) {
        config_.invert = on;
        dirty_ = true;
    });

    connect(bar->addAction("Rotate ⟳"), &QAction::triggered, this, &MainWindow::rotateStep);

    bar->addSeparator();
    connect(bar->addAction("Save PNG"), &QAction::triggered, this, &MainWindow::onSavePng);
    recordAction_ = bar->addAction("Record");
    recordAction_->setCheckable(true);
    connect(recordAction_, &QAction::toggled, this, &MainWindow::onToggleRecord);

    // Start colourful at a smooth default detail; Ultra is available but heavy.
    detailBox_->setCurrentIndex(1);  // Medium
    modeBox_->setCurrentIndex(1);    // Color (also triggers applyRenderSettings)
    statusBar()->showMessage(
        "Keys: [Space] save  [1-3] mode  [M]irror  [I]nset  [E]nhance  in[V]ert  ro[T]ate  "
        "[R]ec  [F]ullscreen");
}

void MainWindow::buildTransportBar() {
    transportBar_ = new QToolBar("Transport", this);
    transportBar_->setMovable(false);
    addToolBar(Qt::BottomToolBarArea, transportBar_);

    playAction_ = transportBar_->addAction("Pause");
    playAction_->setCheckable(true);
    connect(playAction_, &QAction::toggled, this, &MainWindow::onTogglePlay);

    seekSlider_ = new QSlider(Qt::Horizontal, this);
    seekSlider_->setRange(0, 0);
    connect(seekSlider_, &QSlider::sliderMoved, this, &MainWindow::onSeek);
    transportBar_->addWidget(seekSlider_);

    transportBar_->setVisible(false);  // shown only for video sources
}

void MainWindow::rotateStep() {
    rotation_ = (rotation_ + 1) % 4;
    dirty_ = true;
    statusBar()->showMessage(QString("Rotation: %1°").arg(rotation_ * 90), 1500);
}

void MainWindow::onSeek(int frame) {
    if (videoSource_) {
        videoSource_->seek(frame);
        dirty_ = true;  // refresh even while paused
    }
}

void MainWindow::onTogglePlay(bool paused) {
    if (videoSource_) {
        videoSource_->setPaused(paused);
    }
    playAction_->setText(paused ? "Play" : "Pause");
}

void MainWindow::setSource(std::unique_ptr<capture::IFrameSource> source) {
    if (source_) {
        source_->stop();
    }
    videoSource_ = nullptr;
    if (transportBar_) {
        transportBar_->setVisible(false);
    }
    lastFrame_.release();
    rotation_ = 0;  // never carry a rotation across sources
    source_ = std::move(source);
    dirty_ = true;
}

void MainWindow::useWebcam(int device) {
    auto cam = std::make_unique<capture::CameraCapture>(device);
    if (!cam->start()) {
        statusBar()->showMessage("Could not open webcam.", 4000);
        return;
    }
    statusBar()->showMessage("Webcam live.", 2000);
    // Webcam: selfie mirror + detail enhancement on.
    if (mirrorAction_) {
        mirrorAction_->setChecked(true);
    }
    if (enhanceAction_) {
        enhanceAction_->setChecked(true);
    }
    setSource(std::move(cam));
}

void MainWindow::openFile(const QString& path) {
    auto file = std::make_unique<capture::FileSource>(path.toStdString());
    if (!file->start()) {
        statusBar()->showMessage("Could not open file: " + path, 4000);
        return;
    }
    statusBar()->showMessage("Opened " + path, 2000);
    // Uploaded media is shown faithfully: no mirror, no enhancement edits.
    if (mirrorAction_) {
        mirrorAction_->setChecked(false);
    }
    if (enhanceAction_) {
        enhanceAction_->setChecked(false);
    }
    setSource(std::move(file));

    // Show transport controls for videos.
    if (auto* fs = dynamic_cast<capture::FileSource*>(source_.get()); fs && fs->isVideo()) {
        videoSource_ = fs;
        transportBar_->setVisible(true);
        seekSlider_->setRange(0, std::max(1, fs->totalFrames()));
        const QSignalBlocker block(playAction_);
        playAction_->setChecked(false);
        playAction_->setText("Pause");
    }
}

void MainWindow::onOpenFileDialog() {
    const QString path = QFileDialog::getOpenFileName(
        this, "Open image or video", QString(),
        "Media (*.png *.jpg *.jpeg *.bmp *.webp *.mp4 *.avi *.mov *.mkv *.webm);;All files (*.*)");
    if (!path.isEmpty()) {
        openFile(path);
    }
}

void MainWindow::onModeChanged(int index) {
    switch (index) {
        case 1:  // Color
            config_.mode = engine::RenderMode::Luminance;
            config_.color = engine::ColorMode::Truecolor;
            break;
        case 2:  // Edge
            config_.mode = engine::RenderMode::EdgeDirectional;
            config_.color = engine::ColorMode::Truecolor;
            break;
        case 0:  // Luminance (mono green)
        default:
            config_.mode = engine::RenderMode::Luminance;
            config_.color = engine::ColorMode::Monochrome;
            break;
    }
    applyRenderSettings();
}

void MainWindow::onDetailChanged(int index) {
    detail_ = index;
    applyRenderSettings();
}

void MainWindow::applyRenderSettings() {
    const bool emoji = config_.mode == engine::RenderMode::ColorEmoji;

    // Smaller cells => more characters => more detail. Pushed finer for maximum
    // detailing; Ultra approaches a per-pixel render. Text glyphs pack tighter in
    // taller-than-wide cells; emoji (unused in the GUI now) need square cells.
    static constexpr int kTextW[4] = {8, 6, 4, 3};
    static constexpr int kTextH[4] = {14, 10, 7, 5};
    static constexpr int kEmoji[4] = {22, 18, 14, 10};

    const int cw = emoji ? kEmoji[detail_] : kTextW[detail_];
    const int ch = emoji ? kEmoji[detail_] : kTextH[detail_];
    config_.cellWidth = cw;
    config_.cellHeight = ch;
    view_->setCellSize(cw, ch);

    // Finer 70-level ramp at High/Ultra for smooth tone; simpler ramp when coarse.
    config_.ramp = (!emoji && detail_ >= 2) ? "detailed" : "standard";

    dirty_ = true;
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
        case Qt::Key_Space:
            quickSave();
            break;
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
            modeBox_->setCurrentIndex(event->key() - Qt::Key_1);
            break;
        case Qt::Key_M:
            mirrorAction_->toggle();
            break;
        case Qt::Key_I:
            insetAction_->toggle();
            break;
        case Qt::Key_E:
            enhanceAction_->toggle();
            break;
        case Qt::Key_V:
            invertAction_->toggle();
            break;
        case Qt::Key_T:
            rotateStep();
            break;
        case Qt::Key_R:
            recordAction_->toggle();
            break;
        case Qt::Key_F:
            isFullScreen() ? showNormal() : showFullScreen();
            break;
        default:
            QMainWindow::keyPressEvent(event);
    }
}

void MainWindow::quickSave() {
    QDir().mkpath("snapshots");
    QString path;
    for (int n = 1; n < 100000; ++n) {
        path = QString("snapshots/snap_%1.png").arg(n, 4, 10, QChar('0'));
        if (!QFileInfo::exists(path)) {
            break;
        }
    }
    statusBar()->showMessage(saveSnapshot(path) ? "Saved " + path : "Nothing to save yet.", 3000);
}

void MainWindow::onToggleInset(bool on) { view_->setInsetVisible(on); }

void MainWindow::onToggleHeart(bool on) {
    config_.heartFill = on;
    dirty_ = true;
}

QImage MainWindow::compositeImage(int scale) const {
    QRect insetRect;
    QImage inset;
    if (view_->insetVisible() && !view_->insetImage().isNull()) {
        inset = view_->insetImage();
        const QRect r = view_->insetRect();
        insetRect = QRect(r.x() * scale, r.y() * scale, r.width() * scale, r.height() * scale);
    }
    return renderToImage(lastAscii_, view_->cellWidthPx() * scale, view_->cellHeightPx() * scale,
                         inset, insetRect);
}

bool MainWindow::saveSnapshot(const QString& path) {
    if (lastAscii_.empty()) {
        return false;
    }
    return compositeImage(3).save(path);  // 3x cells => crisp, high-res export
}

void MainWindow::onSavePng() {
    if (lastAscii_.empty()) {
        statusBar()->showMessage("Nothing to save yet.", 3000);
        return;
    }
    const QString path =
        QFileDialog::getSaveFileName(this, "Save ASCII snapshot", "snapshot.png", "PNG (*.png)");
    if (path.isEmpty()) {
        return;
    }
    statusBar()->showMessage(saveSnapshot(path) ? "Saved " + path : "Failed to save " + path, 3000);
}

void MainWindow::onToggleRecord(bool on) {
    if (on) {
        const QString path = QFileDialog::getSaveFileName(this, "Record video to", "capture.mp4",
                                                          "MP4 (*.mp4);;AVI (*.avi)");
        if (path.isEmpty()) {
            // User cancelled — untick handled by caller re-toggling is awkward; just bail.
            statusBar()->showMessage("Recording cancelled.", 2000);
            recording_ = false;
            return;
        }
        recordPathPending_ = path;
        recording_ = true;  // writer opens lazily on the first frame (needs its size)
        statusBar()->showMessage("Recording…", 2000);
    } else {
        stopRecording();
        statusBar()->showMessage("Recording stopped.", 3000);
    }
}

void MainWindow::beginRecording(const QString& path) {
    recordPathPending_ = path;
    recording_ = true;  // writer opens lazily on the first frame (needs its size)
}

void MainWindow::endRecording() { stopRecording(); }

void MainWindow::stopRecording() {
    recording_ = false;
    if (writer_.isOpened()) {
        writer_.release();
    }
}

void MainWindow::tick() {
    if (!source_) {
        return;
    }
    // Drain to the newest available frame (drop-stale keeps us real-time).
    bool gotNew = false;
    while (auto latest = source_->frames().try_pop()) {
        lastFrame_ = *latest;
        gotNew = true;
    }

    // Post a job to the worker when there's a new frame or settings changed.
    // Heavy conversion happens off the UI thread, so display stays smooth.
    if (!lastFrame_.empty() && (gotNew || dirty_)) {
        RenderJob job;
        job.frame = lastFrame_;  // shares data; the worker only reads it
        job.cfg = config_;
        job.mirror = mirror_;
        job.rotation = rotation_;
        job.maxCols = view_->maxCols();
        job.maxRows = view_->maxRows();
        jobs_.push(std::move(job));
        dirty_ = false;
    }

    // Paint the latest finished result.
    if (auto res = results_.try_pop()) {
        lastAscii_ = std::move(res->ascii);
        view_->setInsetImage(res->inset);
        view_->setFrame(lastAscii_);
    }

    // Reflect video playback position on the slider (without triggering a seek).
    if (videoSource_ && !seekSlider_->isSliderDown()) {
        const QSignalBlocker block(seekSlider_);
        seekSlider_->setValue(videoSource_->currentFrame());
    }

    if (recording_) {
        QRect insetRect;
        QImage inset;
        if (view_->insetVisible() && !view_->insetImage().isNull()) {
            inset = view_->insetImage();
            insetRect = view_->insetRect();
        }
        const QImage rendered = renderToImage(lastAscii_, view_->cellWidthPx(),
                                              view_->cellHeightPx(), inset, insetRect);
        cv::Mat bgr = qImageToBgrMat(rendered);
        if (!writer_.isOpened()) {
            writer_.open(recordPathPending_.toStdString(),
                         cv::VideoWriter::fourcc('m', 'p', '4', 'v'), 30.0, bgr.size());
            if (!writer_.isOpened()) {
                statusBar()->showMessage("Could not open video writer.", 4000);
                recording_ = false;
                return;
            }
        }
        writer_.write(bgr);
    }
}

}  // namespace asciicam::gui
