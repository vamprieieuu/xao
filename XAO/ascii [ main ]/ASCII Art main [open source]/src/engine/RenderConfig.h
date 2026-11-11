#pragma once

#include <string>

namespace asciicam::engine {

/// How a frame is turned into glyphs.
enum class RenderMode {
    Luminance,        ///< Classic brightness ramp.
    EdgeDirectional,  ///< Sobel/DoG-driven  |  /  -  \  glyphs (the headline mode).
    ColorEmoji,       ///< Hued cells become themed emoji; neutral cells use the ramp.
};

/// How glyphs are coloured.
enum class ColorMode {
    Monochrome,  ///< Single foreground colour (classic terminal green).
    Truecolor,   ///< Per-cell RGB sampled from the source.
};

/// The single source of truth for all rendering parameters. Mirrors the config
/// used by the (future) web implementation so both engines speak the same
/// vocabulary.
struct RenderConfig {
    // --- Output grid: how many source pixels collapse into one character cell.
    int cellWidth = 8;    ///< Source px per cell, horizontally.
    int cellHeight = 16;  ///< Source px per cell, vertically. Taller than wide to
                          ///< compensate for the aspect ratio of monospace glyphs.

    RenderMode mode = RenderMode::Luminance;
    ColorMode color = ColorMode::Monochrome;

    // --- Tone mapping (applied to luminance in 0..1).
    float contrast = 1.2f;    ///< Multiplier about mid-grey (0.5).
    float brightness = 0.0f;  ///< Added after contrast, in [-1, 1] of full scale.
    float gamma = 2.2f;       ///< Gamma for perceptual-brightness correction.
    bool invert = false;      ///< Swap dark/light mapping.

    // --- Edge mode.
    float edgeThreshold = 0.15f;  ///< Gradient magnitude (0..1) above which a cell
                                  ///< is drawn as a directional edge glyph.

    // --- Detail / quality.
    bool enhance = true;  ///< Local-contrast (CLAHE) + unsharp before downsampling.

    // --- Fun overlay.
    bool heartFill = false;  ///< Detect heart-shaped red regions and fill with 💖.

    std::string ramp = "standard";  ///< Key into the ramp table (see Ramp.h).
};

}  // namespace asciicam::engine
