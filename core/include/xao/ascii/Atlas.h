#pragma once

// Access to the embedded, pre-rasterized glyph atlas plus the scaling and
// anti-aliasing used by the renderer.

#include "xao/ascii/AtlasData.h"
#include "xao/ascii/Text.h"

#include <cstdint>
#include <vector>

namespace xao {
namespace ascii {

// A glyph rasterized at a concrete pixel size, as coverage values in [0,1].
struct GlyphMask {
    int width = 0;
    int height = 0;
    std::vector<float> alpha;

    bool empty() const { return width <= 0 || height <= 0 || alpha.empty(); }
    float at(int x, int y) const {
        if (x < 0 || y < 0 || x >= width || y >= height) return 0.0f;
        return alpha[static_cast<std::size_t>(y) * static_cast<std::size_t>(width) +
                     static_cast<std::size_t>(x)];
    }
};

int faceCount();
const atlas::FaceRecord& faceAt(int index);
const char* faceName(int index);
const char* faceScript(int index);

// Indices of faces whose script string matches, in embedded order.
std::vector<int> facesForScript(const char* script);

// True when this exact face provides the codepoint (no fallback).
bool faceHasGlyph(int faceIndex, Codepoint cp);

// Look up a glyph.  When `faceIndex` does not cover the codepoint the lookup
// falls back to the other faces of the same script and then to every face, so
// a missing glyph never turns into a blank cell.
const atlas::GlyphRecord* findGlyph(int faceIndex, Codepoint cp,
                                    int* resolvedFace = nullptr);

// Ink coverage of the glyph in [0,1]; 0 when unavailable.
float glyphCoverage(int faceIndex, Codepoint cp);

// Natural width/height ratio of the glyph's ink box, 1.0 when unavailable.
float glyphAspect(int faceIndex, Codepoint cp);

// Rasterize with area-averaged anti-aliasing to an arbitrary pixel size.
void rasterize(const atlas::GlyphRecord& glyph, int widthPx, int heightPx,
               GlyphMask& out);
void rasterize(int faceIndex, Codepoint cp, int widthPx, int heightPx,
               GlyphMask& out);

// Glyphs present in a face, sorted by codepoint.
std::vector<Codepoint> faceCodepoints(int faceIndex);

} // namespace ascii
} // namespace xao
