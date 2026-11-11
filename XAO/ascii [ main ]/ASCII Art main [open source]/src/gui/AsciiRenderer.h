#pragma once

#include "engine/AsciiFrame.h"

#include <QImage>
#include <QRect>

class QPainter;

namespace asciicam::gui {

/// Paint an AsciiFrame onto a painter using cells of the given pixel size.
/// Shared by the live view and the export path so on-screen and saved output
/// look identical.
void paintFrame(QPainter& painter, const engine::AsciiFrame& frame, int cellW, int cellH);

/// Render an AsciiFrame to a standalone image at the given cell size, optionally
/// compositing a picture-in-picture inset (already positioned in the output's
/// coordinate space). Used for PNG export and video frames.
[[nodiscard]] QImage renderToImage(const engine::AsciiFrame& frame, int cellW, int cellH,
                                   const QImage& inset = {}, QRect insetRect = {});

}  // namespace asciicam::gui
