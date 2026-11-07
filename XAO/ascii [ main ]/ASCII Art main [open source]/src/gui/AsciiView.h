#pragma once

#include "engine/AsciiFrame.h"

#include <QImage>
#include <QPoint>
#include <QRect>
#include <QWidget>

#include <algorithm>

namespace asciicam::gui {

/// Renders an AsciiFrame and, optionally, a draggable picture-in-picture inset
/// showing the original source. The inset can be dragged with the mouse and
/// snaps to the nearest corner on release.
class AsciiView : public QWidget {
    Q_OBJECT

public:
    explicit AsciiView(QWidget* parent = nullptr);

    void setFrame(engine::AsciiFrame frame);
    void setInsetImage(const QImage& image);  // the raw source, for the PiP
    void setInsetVisible(bool on);
    void setCellSize(int w, int h);  // emoji look best in square cells

    [[nodiscard]] bool insetVisible() const { return insetVisible_; }
    [[nodiscard]] const QImage& insetImage() const { return insetImage_; }
    [[nodiscard]] QRect insetRect() const { return insetRect_; }
    [[nodiscard]] const engine::AsciiFrame& frame() const { return frame_; }

    [[nodiscard]] int cellWidthPx() const { return cellW_; }
    [[nodiscard]] int cellHeightPx() const { return cellH_; }
    [[nodiscard]] int maxCols() const { return std::max(1, width() / cellW_); }
    [[nodiscard]] int maxRows() const { return std::max(1, height() / cellH_); }

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    void snapInsetToNearestCorner();

    engine::AsciiFrame frame_;
    int cellW_ = 8;
    int cellH_ = 14;

    QImage insetImage_;
    QRect insetRect_{20, 20, 260, 195};  // resized to match source aspect on first frame
    double insetAspect_ = -1.0;          // cached source aspect ratio (w/h)
    bool insetVisible_ = true;
    bool insetPlaced_ = false;
    bool dragging_ = false;
    QPoint dragOffset_;
};

}  // namespace asciicam::gui
