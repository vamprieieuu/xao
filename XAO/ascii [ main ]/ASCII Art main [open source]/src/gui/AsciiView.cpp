#include "gui/AsciiView.h"

#include "gui/AsciiRenderer.h"

#include <QMouseEvent>
#include <QPainter>
#include <QPen>

#include <array>
#include <cmath>
#include <utility>

namespace asciicam::gui {

AsciiView::AsciiView(QWidget* parent) : QWidget(parent) {
    setAutoFillBackground(true);
    setMinimumSize(320, 240);
    setMouseTracking(false);
}

void AsciiView::setFrame(engine::AsciiFrame frame) {
    frame_ = std::move(frame);
    update();
}

void AsciiView::setInsetImage(const QImage& image) {
    insetImage_ = image;

    // Resize the inset to match the source aspect ratio so wide/tall content
    // isn't squished into a fixed box. Only when the aspect actually changes,
    // so it doesn't fight the user's drag every frame.
    if (!image.isNull() && image.height() > 0) {
        const double ar = static_cast<double>(image.width()) / image.height();
        if (std::abs(ar - insetAspect_) > 0.01) {
            insetAspect_ = ar;
            constexpr int kLongSide = 300;  // longest inset edge, in pixels
            int w = kLongSide;
            int h = static_cast<int>(kLongSide / ar);
            if (h > kLongSide) {
                h = kLongSide;
                w = static_cast<int>(kLongSide * ar);
            }
            if (width() > 8) w = std::min(w, width() - 8);
            if (height() > 8) h = std::min(h, height() - 8);

            QPoint tl = insetRect_.topLeft();
            insetRect_.setSize({std::max(40, w), std::max(30, h)});
            tl.setX(std::clamp(tl.x(), 0, std::max(0, width() - insetRect_.width())));
            tl.setY(std::clamp(tl.y(), 0, std::max(0, height() - insetRect_.height())));
            insetRect_.moveTopLeft(tl);
        }
    }

    if (insetVisible_) {
        update();
    }
}

void AsciiView::setInsetVisible(bool on) {
    insetVisible_ = on;
    update();
}

void AsciiView::setCellSize(int w, int h) {
    cellW_ = std::max(2, w);
    cellH_ = std::max(2, h);
    update();
}

void AsciiView::resizeEvent(QResizeEvent* /*event*/) {
    // Place the inset in the bottom-right corner the first time we have a size.
    if (!insetPlaced_ && width() > 0 && height() > 0) {
        const int margin = 16;
        insetRect_.moveTopLeft({width() - insetRect_.width() - margin,
                                height() - insetRect_.height() - margin});
        insetPlaced_ = true;
    }
}

void AsciiView::paintEvent(QPaintEvent* /*event*/) {
    QPainter p(this);
    p.fillRect(rect(), Qt::black);

    // Centre the character grid so any leftover margin is even (fixes media that
    // doesn't exactly divide into the window — e.g. a 16:9 video in a 4:3 window).
    if (!frame_.empty()) {
        const int gridW = frame_.cols() * cellW_;
        const int gridH = frame_.rows() * cellH_;
        const int ox = std::max(0, (width() - gridW) / 2);
        const int oy = std::max(0, (height() - gridH) / 2);
        p.save();
        p.translate(ox, oy);
        paintFrame(p, frame_, cellW_, cellH_);
        p.restore();
    }

    if (insetVisible_ && !insetImage_.isNull()) {
        p.drawImage(insetRect_, insetImage_);
        p.setPen(QPen(dragging_ ? Qt::yellow : Qt::white, 2));
        p.drawRect(insetRect_);
    }
}

void AsciiView::mousePressEvent(QMouseEvent* event) {
    if (insetVisible_ && !insetImage_.isNull() && insetRect_.contains(event->pos())) {
        dragging_ = true;
        dragOffset_ = event->pos() - insetRect_.topLeft();
    }
}

void AsciiView::mouseMoveEvent(QMouseEvent* event) {
    if (!dragging_) {
        return;
    }
    QPoint topLeft = event->pos() - dragOffset_;
    // Keep the inset fully inside the widget.
    topLeft.setX(std::clamp(topLeft.x(), 0, width() - insetRect_.width()));
    topLeft.setY(std::clamp(topLeft.y(), 0, height() - insetRect_.height()));
    insetRect_.moveTopLeft(topLeft);
    update();
}

void AsciiView::mouseReleaseEvent(QMouseEvent* /*event*/) {
    if (dragging_) {
        dragging_ = false;
        snapInsetToNearestCorner();
        update();
    }
}

void AsciiView::snapInsetToNearestCorner() {
    const int margin = 16;
    const std::array<QPoint, 4> corners{{
        {margin, margin},
        {width() - insetRect_.width() - margin, margin},
        {margin, height() - insetRect_.height() - margin},
        {width() - insetRect_.width() - margin, height() - insetRect_.height() - margin},
    }};

    QPoint best = corners.front();
    double bestDist = 1e18;
    for (const QPoint& c : corners) {
        const double dx = c.x() - insetRect_.x();
        const double dy = c.y() - insetRect_.y();
        const double dist = dx * dx + dy * dy;
        if (dist < bestDist) {
            bestDist = dist;
            best = c;
        }
    }
    insetRect_.moveTopLeft(best);
}

}  // namespace asciicam::gui
