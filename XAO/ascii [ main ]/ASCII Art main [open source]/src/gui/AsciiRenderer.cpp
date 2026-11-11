#include "gui/AsciiRenderer.h"

#include <QColor>
#include <QFont>
#include <QPainter>
#include <QPen>
#include <QString>

namespace asciicam::gui {

void paintFrame(QPainter& painter, const engine::AsciiFrame& frame, int cellW, int cellH) {
    if (frame.empty()) {
        return;
    }
    QFont font("Cascadia Mono");
    font.setStyleHint(QFont::Monospace);
    font.setPixelSize(cellH - 2);
    painter.setFont(font);

    for (int y = 0; y < frame.rows(); ++y) {
        for (int x = 0; x < frame.cols(); ++x) {
            const engine::AsciiCell& cell = frame.at(x, y);
            if (cell.glyph == " ") {
                continue;
            }
            painter.setPen(QColor(cell.color.r, cell.color.g, cell.color.b));
            painter.drawText(QRect(x * cellW, y * cellH, cellW, cellH), Qt::AlignCenter,
                             QString::fromStdString(cell.glyph));
        }
    }
}

QImage renderToImage(const engine::AsciiFrame& frame, int cellW, int cellH, const QImage& inset,
                     QRect insetRect) {
    QImage image(frame.cols() * cellW, frame.rows() * cellH, QImage::Format_RGB888);
    image.fill(Qt::black);

    QPainter painter(&image);
    paintFrame(painter, frame, cellW, cellH);

    if (!inset.isNull() && insetRect.isValid()) {
        painter.drawImage(insetRect, inset);
        painter.setPen(QPen(Qt::white, 2));
        painter.drawRect(insetRect);
    }
    painter.end();
    return image;
}

}  // namespace asciicam::gui
