#include "xao/ascii/Atlas.h"

#include <algorithm>
#include <cstring>

namespace xao {
namespace ascii {

namespace {

bool bitAt(const atlas::GlyphRecord& g, int x, int y) {
    const std::uint32_t stride = (static_cast<std::uint32_t>(g.width) + 7u) / 8u;
    const std::uint32_t index =
        g.bitmapOffset + static_cast<std::uint32_t>(y) * stride +
        static_cast<std::uint32_t>(x / 8);
    const std::uint8_t byte = atlas::kBitmapBits[index];
    return ((byte >> (7 - (x & 7))) & 1u) != 0u;
}

const atlas::GlyphRecord* searchFace(int faceIndex, Codepoint cp) {
    if (faceIndex < 0 || faceIndex >= atlas::kFaceCount) return nullptr;
    const atlas::FaceRecord& f = atlas::kFaces[faceIndex];
    if (f.glyphCount == 0) return nullptr;
    std::uint32_t lo = f.glyphBegin;
    std::uint32_t hi = f.glyphBegin + f.glyphCount;
    while (lo < hi) {
        const std::uint32_t mid = lo + (hi - lo) / 2;
        const atlas::GlyphRecord& g = atlas::kGlyphs[mid];
        if (g.codepoint == cp) return &g;
        if (g.codepoint < cp) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return nullptr;
}

} // namespace

int faceCount() { return atlas::kFaceCount; }

const atlas::FaceRecord& faceAt(int index) {
    static const atlas::FaceRecord kEmpty{"", "", 1, 1, 0, 0, 0};
    if (index < 0 || index >= atlas::kFaceCount) return kEmpty;
    return atlas::kFaces[index];
}

const char* faceName(int index) { return faceAt(index).name; }
const char* faceScript(int index) { return faceAt(index).script; }

std::vector<int> facesForScript(const char* script) {
    std::vector<int> out;
    if (script == nullptr) return out;
    for (int i = 0; i < atlas::kFaceCount; ++i) {
        if (std::strcmp(atlas::kFaces[i].script, script) == 0) out.push_back(i);
    }
    return out;
}

bool faceHasGlyph(int faceIndex, Codepoint cp) {
    return searchFace(faceIndex, cp) != nullptr;
}

const atlas::GlyphRecord* findGlyph(int faceIndex, Codepoint cp,
                                    int* resolvedFace) {
    if (const atlas::GlyphRecord* g = searchFace(faceIndex, cp)) {
        if (resolvedFace) *resolvedFace = faceIndex;
        return g;
    }
    const char* script = faceScript(faceIndex);
    for (int i = 0; i < atlas::kFaceCount; ++i) {
        if (i == faceIndex) continue;
        if (script != nullptr && std::strcmp(atlas::kFaces[i].script, script) != 0) continue;
        if (const atlas::GlyphRecord* g = searchFace(i, cp)) {
            if (resolvedFace) *resolvedFace = i;
            return g;
        }
    }
    for (int i = 0; i < atlas::kFaceCount; ++i) {
        if (i == faceIndex) continue;
        if (const atlas::GlyphRecord* g = searchFace(i, cp)) {
            if (resolvedFace) *resolvedFace = i;
            return g;
        }
    }
    if (resolvedFace) *resolvedFace = faceIndex;
    return nullptr;
}

float glyphCoverage(int faceIndex, Codepoint cp) {
    const atlas::GlyphRecord* g = findGlyph(faceIndex, cp);
    return g ? g->coverage : 0.0f;
}

float glyphAspect(int faceIndex, Codepoint cp) {
    const atlas::GlyphRecord* g = findGlyph(faceIndex, cp);
    if (g == nullptr || g->height == 0) return 1.0f;
    return static_cast<float>(g->width) / static_cast<float>(g->height);
}

void rasterize(const atlas::GlyphRecord& glyph, int widthPx, int heightPx,
               GlyphMask& out) {
    if (widthPx <= 0 || heightPx <= 0 || glyph.width == 0 || glyph.height == 0) {
        out.width = 0;
        out.height = 0;
        out.alpha.clear();
        return;
    }
    out.width = widthPx;
    out.height = heightPx;
    out.alpha.assign(static_cast<std::size_t>(widthPx) * static_cast<std::size_t>(heightPx),
                     0.0f);

    // 3x3 supersampling of the 1-bit master.  The master was rasterized at a
    // large em size, so this yields clean edges at the small cell sizes the
    // engine actually draws.
    const float sx = static_cast<float>(glyph.width) / static_cast<float>(widthPx);
    const float sy = static_cast<float>(glyph.height) / static_cast<float>(heightPx);
    for (int y = 0; y < heightPx; ++y) {
        for (int x = 0; x < widthPx; ++x) {
            int hits = 0;
            for (int subY = 0; subY < 3; ++subY) {
                const float fy = (static_cast<float>(y) + (static_cast<float>(subY) + 0.5f) / 3.0f) * sy;
                const int iy = std::min(glyph.height - 1, std::max(0, static_cast<int>(fy)));
                for (int subX = 0; subX < 3; ++subX) {
                    const float fx = (static_cast<float>(x) + (static_cast<float>(subX) + 0.5f) / 3.0f) * sx;
                    const int ix = std::min(glyph.width - 1, std::max(0, static_cast<int>(fx)));
                    if (bitAt(glyph, ix, iy)) ++hits;
                }
            }
            out.alpha[static_cast<std::size_t>(y) * static_cast<std::size_t>(widthPx) +
                      static_cast<std::size_t>(x)] = static_cast<float>(hits) / 9.0f;
        }
    }
}

void rasterize(int faceIndex, Codepoint cp, int widthPx, int heightPx,
               GlyphMask& out) {
    const atlas::GlyphRecord* g = findGlyph(faceIndex, cp);
    if (g == nullptr) {
        out.width = 0;
        out.height = 0;
        out.alpha.clear();
        return;
    }
    rasterize(*g, widthPx, heightPx, out);
}

std::vector<Codepoint> faceCodepoints(int faceIndex) {
    std::vector<Codepoint> out;
    if (faceIndex < 0 || faceIndex >= atlas::kFaceCount) return out;
    const atlas::FaceRecord& f = atlas::kFaces[faceIndex];
    out.reserve(f.glyphCount);
    for (std::uint32_t i = 0; i < f.glyphCount; ++i) {
        out.push_back(atlas::kGlyphs[f.glyphBegin + i].codepoint);
    }
    return out;
}

} // namespace ascii
} // namespace xao
