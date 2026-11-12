#pragma once

// The XAO ASCII engine: one unified renderer with nine distinct visual
// strategies.  All state is derived from the parameters plus absolute time, so
// output is deterministic and independent of render order (Smart Render, MFR).

#include "xao/Engine.h"
#include "xao/ascii/AsciiParams.h"
#include "xao/ascii/GlyphSets.h"

#include <vector>

namespace xao {
namespace ascii {

// Resolved glyph pools for one configuration.  Exposed so tests can verify that
// a preset really uses its own glyph collection and that languages do not leak
// into each other.
struct ResolvedPools {
    GlyphPool letters;      // single-cell letters and symbols
    GlyphPool numbers;      // digits from the active languages
    GlyphPool wordGlyphs;   // glyphs used to draw generated words
    GlyphPool symbols;      // preset-specific symbol family (alien, etc.)
    bool wordMode = false;
    ScriptId wordScript = ScriptId::English;
    int wordFace = 0;
    int letterFace = 0;
};

ResolvedPools resolvePools(const AsciiParams& params);

class AsciiEngine final : public xao::Engine {
public:
    explicit AsciiEngine(AsciiParams params = AsciiParams());

    const char* id() const noexcept override { return "xao.ascii"; }
    void render(const Image& source, Image& destination,
                const RenderContext& context) const override;

    const AsciiParams& params() const noexcept { return params_; }
    void setParams(const AsciiParams& params) { params_ = params; }

private:
    AsciiParams params_;
};

// Reported for diagnostics and regression tests.
struct AsciiRenderStats {
    int glyphsDrawn = 0;
    float inkCoverage = 0.0f;  // fraction of plate pixels covered by glyph ink
    int cellsAcross = 0;
    int cellsDown = 0;
};

AsciiRenderStats renderAscii(const Image& source, Image& destination,
                             const RenderContext& context,
                             const AsciiParams& params);

} // namespace ascii
} // namespace xao
