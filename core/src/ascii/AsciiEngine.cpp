#include "xao/ascii/AsciiEngine.h"

#include "xao/ascii/Atlas.h"
#include "xao/ascii/Palette.h"
#include "xao/ascii/Shaping.h"
#include "xao/ascii/Text.h"

#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

namespace xao {
namespace ascii {

// ---------------------------------------------------------------------------
// Names
// ---------------------------------------------------------------------------

const char* presetName(Preset preset) {
    switch (preset) {
        case Preset::Default: return "Default";
        case Preset::AlienSignal: return "Alien Signal";
        case Preset::Liquid: return "Liquid";
        case Preset::Ghost: return "Ghost";
        case Preset::Cgo: return "CGO";
        case Preset::Mosaic: return "Mosaic";
        case Preset::Rainbow: return "Rainbow";
        case Preset::Threshold: return "Threshold";
        case Preset::Organic: return "Organic";
        default: return "Unknown";
    }
}

int presetCount() { return static_cast<int>(Preset::Count); }

const char* charsetName(Charset charset) {
    switch (charset) {
        case Charset::Auto: return "Auto";
        case Charset::SpecialLetters: return "Special Characters and Letters";
        case Charset::SpecialNumbers: return "Special Characters and Numbers";
        case Charset::Typewriter: return "Classic Typewriter";
        case Charset::Binary: return "Binary";
        case Charset::MinimalPunk: return "Minimal Punk";
        case Charset::Xs: return "X's";
        case Charset::BubbleGrowth: return "Bubble Growth";
        case Charset::Stars: return "Stars";
        case Charset::Diamonds: return "Diamonds";
        case Charset::Dots: return "Dots";
        case Charset::Circuits1: return "Circuits 1";
        case Charset::Circuits2: return "Circuits 2";
        case Charset::AlienFont: return "Alien Font";
        case Charset::Bars: return "Bars";
        case Charset::Blocks: return "Blocks";
        default: return "Unknown";
    }
}

const char* paletteName(Palette palette) {
    switch (palette) {
        case Palette::Source: return "Source Color";
        case Palette::Ember: return "Ember";
        case Palette::Cream: return "Cream";
        case Palette::Sand: return "Sand";
        case Palette::Navy: return "Navy";
        case Palette::Chroma: return "Chroma";
        case Palette::Grey: return "Grey";
        case Palette::Acid: return "Acid";
        case Palette::Mono: return "Mono";
        case Palette::Terminal: return "Terminal";
        case Palette::Gold: return "Gold";
        case Palette::Ice: return "Ice";
        case Palette::Infrared: return "Infrared";
        case Palette::Vapor: return "Vapor";
        default: return "Unknown";
    }
}

const char* channelName(SampleChannel channel) {
    switch (channel) {
        case SampleChannel::Red: return "Red";
        case SampleChannel::Green: return "Green";
        case SampleChannel::Blue: return "Blue";
        default: return "Luma";
    }
}

// ---------------------------------------------------------------------------
// Pool resolution
// ---------------------------------------------------------------------------

namespace {

Text arabicIsolatedForms() {
    Text forms;
    for (Codepoint cp : arabicLetters()) {
        const Text single{cp};
        const std::vector<ShapedArabic> shaped = shapeArabic(single);
        if (!shaped.empty()) forms.push_back(shaped.front().codepoint);
    }
    // Arabic-Indic and Persian digits are handled by the numbers pool.
    return forms;
}

GlyphPool poolForScript(ScriptId script, int fontIndex, GlyphCategory category) {
    const std::vector<int> faces = facesForScript(scriptTag(script));
    int face = defaultFaceForScript(script);
    if (!faces.empty() && fontIndex >= 0 &&
        fontIndex < static_cast<int>(faces.size())) {
        face = faces[static_cast<std::size_t>(fontIndex)];
    }
    switch (script) {
        case ScriptId::Arabic:
            return makePool(arabicIsolatedForms(), face, category);
        case ScriptId::Ancient: {
            Text family = ancientGlyphFamily(ScriptId::Ancient);
            return makePool(family, face, category);
        }
        case ScriptId::English:
        default:
            return makePool(englishLetters(), face, category);
    }
}

} // namespace

ResolvedPools resolvePools(const AsciiParams& p) {
    ResolvedPools out;

    // Preset-specific glyph identity.  Alien Signal only ever selects alien
    // symbols, whatever the language toggles say.
    if (p.preset == Preset::AlienSignal) {
        const std::vector<int> faces = facesForScript(scriptTag(ScriptId::Ancient));
        out.letterFace = faces.empty() ? 0 : faces.front();
        out.symbols = makePool(ancientGlyphFamily(ScriptId::Ancient), out.letterFace,
                              GlyphCategory::Symbol);
        out.letters = out.symbols;
        out.numbers = out.symbols;
        out.wordGlyphs = out.symbols;
        out.wordMode = false;
        out.wordScript = ScriptId::Ancient;
        out.wordFace = out.letterFace;
        return out;
    }

    const bool englishLettersOn = p.english.letters;
    const bool arabicLettersOn = p.arabic.letters;
    const bool ancientLettersOn = p.ancient.letters;

    // A character-set override replaces the language letter sets.
    if (p.charset != Charset::Auto) {
        int face = defaultFaceForScript(ScriptId::English);
        if (arabicLettersOn) face = poolForScript(ScriptId::Arabic, p.arabic.font,
                                                 GlyphCategory::Letter).face;
        else if (ancientLettersOn) face = defaultFaceForScript(ScriptId::Ancient);
        out.letters = makePool(charsetCodepoints(p.charset), face,
                               GlyphCategory::Letter);
        out.letterFace = face;
    } else {
        std::vector<GlyphPool> letterPools;
        if (englishLettersOn) {
            letterPools.push_back(poolForScript(ScriptId::English, p.english.font,
                                                GlyphCategory::Letter));
        }
        if (arabicLettersOn) {
            letterPools.push_back(poolForScript(ScriptId::Arabic, p.arabic.font,
                                                GlyphCategory::Letter));
        }
        if (ancientLettersOn) {
            letterPools.push_back(poolForScript(ScriptId::Ancient, p.ancient.font,
                                                GlyphCategory::Letter));
        }
        if (letterPools.empty()) {
            const int face = defaultFaceForScript(ScriptId::English);
            out.letters = makePool(charsetCodepoints(Charset::SpecialLetters), face,
                                   GlyphCategory::Letter);
            out.letterFace = face;
        } else {
            out.letters = mergePools(letterPools);
            out.letterFace = out.letters.empty() ? 0 : out.letters.face;
        }
    }

    // Numbers keep their own size control, so they stay in their own pool.
    {
        std::vector<GlyphPool> numberPools;
        if (p.english.numbers) {
            const GlyphPool pool = poolForScript(ScriptId::English, p.english.font,
                                                 GlyphCategory::Number);
            numberPools.push_back(makePool(englishDigits(), pool.face,
                                           GlyphCategory::Number));
        }
        if (p.arabic.numbers) {
            GlyphPool pool = poolForScript(ScriptId::Arabic, p.arabic.font,
                                           GlyphCategory::Number);
            Text digits = arabicDigits();
            const Text persian = persianDigits();
            digits.insert(digits.end(), persian.begin(), persian.end());
            numberPools.push_back(makePool(digits, pool.face, GlyphCategory::Number));
        }
        if (p.ancient.numbers) {
            GlyphPool pool = poolForScript(ScriptId::Ancient, p.ancient.font,
                                           GlyphCategory::Number);
            numberPools.push_back(makePool(englishDigits(), pool.face,
                                           GlyphCategory::Number));
        }
        out.numbers = mergePools(numberPools);
    }

    // Word mode follows the enabled language.
    if (p.arabic.words) {
        out.wordMode = true;
        out.wordScript = ScriptId::Arabic;
        const GlyphPool pool = poolForScript(ScriptId::Arabic, p.arabic.font,
                                             GlyphCategory::Word);
        out.wordFace = pool.face;
        out.wordGlyphs = pool;
    } else if (p.ancient.words) {
        out.wordMode = true;
        out.wordScript = ScriptId::Ancient;
        const GlyphPool pool = poolForScript(ScriptId::Ancient, p.ancient.font,
                                             GlyphCategory::Word);
        out.wordFace = pool.face;
        out.wordGlyphs = pool;
    } else if (p.english.words) {
        out.wordMode = true;
        out.wordScript = ScriptId::English;
        const GlyphPool pool = poolForScript(ScriptId::English, p.english.font,
                                             GlyphCategory::Word);
        out.wordFace = pool.face;
        out.wordGlyphs = pool;
    }

    out.symbols = makePool(ancientGlyphFamily(ScriptId::Ancient),
                           defaultFaceForScript(ScriptId::Ancient),
                           GlyphCategory::Symbol);
    if (out.letterFace < 0) out.letterFace = 0;
    return out;
}

// ---------------------------------------------------------------------------
// Small helpers
// ---------------------------------------------------------------------------

namespace {

struct Box {
    Rgb color;
    float alpha = 0.0f;
    float luma = 0.0f;
};

inline int clampInt(int v, int lo, int hi) { return v < lo ? lo : (v > hi ? hi : v); }
inline float clamp01(float v) { return v < 0.0f ? 0.0f : (v > 1.0f ? 1.0f : v); }

inline float channelOf(const Rgb& c, SampleChannel ch) {
    switch (ch) {
        case SampleChannel::Red: return c.r;
        case SampleChannel::Green: return c.g;
        case SampleChannel::Blue: return c.b;
        default: return rgbLuma(c);
    }
}

Box sampleBox(const Image& img, int x0, int y0, int x1, int y1, SampleChannel ch) {
    Box box;
    x0 = clampInt(x0, 0, img.width());
    x1 = clampInt(x1, 0, img.width());
    y0 = clampInt(y0, 0, img.height());
    y1 = clampInt(y1, 0, img.height());
    if (x1 <= x0 || y1 <= y0) return box;
    double r = 0.0, g = 0.0, b = 0.0, a = 0.0;
    int count = 0;
    for (int y = y0; y < y1; ++y) {
        const Pixel* row = img.row(y);
        for (int x = x0; x < x1; ++x) {
            const Pixel& px = row[x];
            r += px.r;
            g += px.g;
            b += px.b;
            a += px.a;
            ++count;
        }
    }
    if (count == 0) return box;
    const double inv = 1.0 / static_cast<double>(count);
    const double alpha = a * inv;
    Rgb straight{0.0f, 0.0f, 0.0f};
    if (alpha > 1e-4) {
        const double s = 1.0 / alpha;
        straight.r = static_cast<float>(r * inv * s);
        straight.g = static_cast<float>(g * inv * s);
        straight.b = static_cast<float>(b * inv * s);
    }
    straight = rgbClamp(straight);
    box.color = straight;
    box.alpha = static_cast<float>(alpha);
    box.luma = clamp01(channelOf(straight, ch));
    return box;
}

inline void compositePixel(Image& img, int x, int y, const Rgb& c, float a) {
    if (a <= 0.0f) return;
    if (x < 0 || y < 0 || x >= img.width() || y >= img.height()) return;
    Pixel& d = img.at(x, y);
    const float inv = 1.0f - a;
    d.r = c.r * a + d.r * inv;
    d.g = c.g * a + d.g * inv;
    d.b = c.b * a + d.b * inv;
    d.a = a + d.a * inv;
}

void fillRect(Image& img, int x0, int y0, int x1, int y1, const Rgb& c, float a) {
    x0 = clampInt(x0, 0, img.width());
    x1 = clampInt(x1, 0, img.width());
    y0 = clampInt(y0, 0, img.height());
    y1 = clampInt(y1, 0, img.height());
    for (int y = y0; y < y1; ++y) {
        Pixel* row = img.row(y);
        for (int x = x0; x < x1; ++x) {
            Pixel& d = row[x];
            const float inv = 1.0f - a;
            d.r = c.r * a + d.r * inv;
            d.g = c.g * a + d.g * inv;
            d.b = c.b * a + d.b * inv;
            d.a = a + d.a * inv;
        }
    }
}

void fillRoundedRect(Image& img, int x0, int y0, int w, int h, float radius,
                     const Rgb& c, float a) {
    if (w <= 0 || h <= 0) return;
    const float r = std::min(radius, 0.5f * static_cast<float>(std::min(w, h)));
    const float cx0 = static_cast<float>(x0) + r;
    const float cx1 = static_cast<float>(x0 + w) - r;
    const float cy0 = static_cast<float>(y0) + r;
    const float cy1 = static_cast<float>(y0 + h) - r;
    for (int y = y0; y < y0 + h; ++y) {
        if (y < 0 || y >= img.height()) continue;
        for (int x = x0; x < x0 + w; ++x) {
            if (x < 0 || x >= img.width()) continue;
            float d = 0.0f;
            const float fx = static_cast<float>(x) + 0.5f;
            const float fy = static_cast<float>(y) + 0.5f;
            if (fx < cx0 && fy < cy0) d = std::hypot(cx0 - fx, cy0 - fy);
            else if (fx > cx1 && fy < cy0) d = std::hypot(fx - cx1, cy0 - fy);
            else if (fx < cx0 && fy > cy1) d = std::hypot(cx0 - fx, fy - cy1);
            else if (fx > cx1 && fy > cy1) d = std::hypot(fx - cx1, fy - cy1);
            if (d > r) continue;
            const float cover = d > r - 1.0f ? (r - d) : 1.0f;
            compositePixel(img, x, y, c, a * cover);
        }
    }
}

// One-entry-per-configuration glyph mask cache.  Local to a render call, so
// concurrent Smart Render requests never share mutable state.
class MaskCache {
public:
    const GlyphMask& get(int face, Codepoint cp, int w, int h) {
        w = clampInt(w, 1, 255);
        h = clampInt(h, 1, 255);
        const std::uint64_t key = (static_cast<std::uint64_t>(face & 0xFF) << 56) |
                                  (static_cast<std::uint64_t>(cp & 0xFFFFFF) << 16) |
                                  (static_cast<std::uint64_t>(w) << 8) |
                                  static_cast<std::uint64_t>(h);
        auto it = map_.find(key);
        if (it != map_.end()) return it->second;
        GlyphMask mask;
        rasterize(face, cp, w, h, mask);
        if (map_.size() > 8192) map_.clear();
        return map_.emplace(key, std::move(mask)).first->second;
    }

private:
    std::unordered_map<std::uint64_t, GlyphMask> map_;
};

void blitMask(Image& layer, const GlyphMask& mask, int px, int py, int rotation,
              const Rgb& color, float alpha) {
    if (mask.empty() || alpha <= 0.0f) return;
    const int w = mask.width;
    const int h = mask.height;
    const bool swap = (rotation == 90 || rotation == 270);
    const int outW = swap ? h : w;
    const int outH = swap ? w : h;
    for (int y = 0; y < outH; ++y) {
        for (int x = 0; x < outW; ++x) {
            int sx = 0;
            int sy = 0;
            switch (rotation) {
                case 90: sx = y; sy = h - 1 - x; break;
                case 180: sx = w - 1 - x; sy = h - 1 - y; break;
                case 270: sx = w - 1 - y; sy = x; break;
                default: sx = x; sy = y; break;
            }
            const float cov = mask.at(sx, sy) * alpha;
            if (cov <= 0.004f) continue;
            compositePixel(layer, px + x, py + y, color, cov);
        }
    }
}

// Draw one glyph fitted (aspect preserved) into a box.
void drawGlyphFit(Image& layer, MaskCache& cache, int face, Codepoint cp,
                  int boxX, int boxY, int boxW, int boxH, float scale,
                  float margin, const Rgb& color, float alpha, int rotation = 0) {
    if (boxW <= 0 || boxH <= 0 || alpha <= 0.0f) return;
    const atlas::GlyphRecord* g = findGlyph(face, cp);
    if (g == nullptr || g->width == 0 || g->height == 0) return;
    const float usableW = static_cast<float>(boxW) * (1.0f - margin) * scale;
    const float usableH = static_cast<float>(boxH) * (1.0f - margin) * scale;
    if (usableW < 1.0f || usableH < 1.0f) return;
    const float sx = usableW / static_cast<float>(g->width);
    const float sy = usableH / static_cast<float>(g->height);
    const bool swap = (rotation == 90 || rotation == 270);
    const float s = std::min(sx, sy);
    int gw = clampInt(static_cast<int>(std::lround(static_cast<float>(g->width) * s)), 1, 255);
    int gh = clampInt(static_cast<int>(std::lround(static_cast<float>(g->height) * s)), 1, 255);
    if (swap) std::swap(gw, gh);
    const GlyphMask& mask = cache.get(face, cp, swap ? gh : gw, swap ? gw : gh);
    const int px = boxX + (boxW - gw) / 2;
    const int py = boxY + (boxH - gh) / 2;
    blitMask(layer, mask, px, py, rotation, color, alpha);
}

// Draw a shaped word run: pen-positioned glyphs, then optically centred.
void drawWordRun(Image& layer, MaskCache& cache, int face, const Text& visual,
                 int boxX, int boxY, int boxW, int boxH, float scale,
                 const Rgb& color, float alpha) {
    if (visual.empty() || alpha <= 0.0f || boxW <= 0 || boxH <= 0) return;
    const atlas::FaceRecord& faceInfo = faceAt(face);
    const float em = static_cast<float>(faceInfo.emSize > 0 ? faceInfo.emSize : 40);
    const float s = (static_cast<float>(boxH) * 0.82f * scale) / em;
    if (s <= 0.0f) return;

    struct Placed {
        const atlas::GlyphRecord* g;
        int x, y, w, h;
    };
    std::vector<Placed> placed;
    placed.reserve(visual.size());
    float pen = 0.0f;
    float minX = 1e9f, minY = 1e9f, maxX = -1e9f, maxY = -1e9f;
    for (Codepoint cp : visual) {
        const atlas::GlyphRecord* g = findGlyph(face, cp);
        if (g == nullptr) continue;
        if (g->width > 0 && g->height > 0) {
            const float gx = pen + static_cast<float>(g->left) * s;
            const float gy = static_cast<float>(g->top) * s;
            const float gw = static_cast<float>(g->width) * s;
            const float gh = static_cast<float>(g->height) * s;
            Placed p;
            p.g = g;
            p.x = static_cast<int>(std::lround(gx));
            p.y = static_cast<int>(std::lround(gy));
            p.w = std::max(1, static_cast<int>(std::lround(gw)));
            p.h = std::max(1, static_cast<int>(std::lround(gh)));
            placed.push_back(p);
            minX = std::min(minX, gx);
            minY = std::min(minY, gy);
            maxX = std::max(maxX, gx + gw);
            maxY = std::max(maxY, gy + gh);
        }
        pen += static_cast<float>(g->advance) * s;
    }
    if (placed.empty()) return;
    if (pen > 0.0f && pen > static_cast<float>(boxW)) {
        // Shrink to fit the run width.
        const float fit = static_cast<float>(boxW) / pen;
        for (Placed& p : placed) {
            p.x = static_cast<int>(std::lround(static_cast<float>(p.x) * fit));
            p.w = std::max(1, static_cast<int>(std::lround(static_cast<float>(p.w) * fit)));
        }
        minX *= fit; maxX *= fit; minY *= fit; maxY *= fit;
    }
    const float offsetX = static_cast<float>(boxX) + 0.5f * static_cast<float>(boxW) -
                          0.5f * (minX + maxX);
    const float offsetY = static_cast<float>(boxY) + 0.5f * static_cast<float>(boxH) -
                          0.5f * (minY + maxY);
    for (const Placed& p : placed) {
        if (p.w < 1 || p.h < 1) continue;
        const GlyphMask& mask = cache.get(face, p.g->codepoint, p.w, p.h);
        blitMask(layer, mask, static_cast<int>(std::lround(static_cast<float>(p.x) + offsetX)),
                 static_cast<int>(std::lround(static_cast<float>(p.y) + offsetY)), 0,
                 color, alpha);
    }
}

void blurPremultiplied(Image& img, float amount) {
    if (amount <= 0.0f) return;
    const int w = img.width();
    const int h = img.height();
    if (w < 3 || h < 3) return;
    std::vector<Pixel> temp(img.pixels().size());
    const float k = amount;
    const float center = 1.0f - k;
    for (int y = 0; y < h; ++y) {
        const Pixel* row = img.row(y);
        Pixel* out = temp.data() + static_cast<std::size_t>(y) * static_cast<std::size_t>(w);
        for (int x = 0; x < w; ++x) {
            const Pixel& c = row[x];
            const Pixel& l = row[clampInt(x - 1, 0, w - 1)];
            const Pixel& r = row[clampInt(x + 1, 0, w - 1)];
            out[x].r = c.r * center + (l.r + r.r) * (0.5f * k);
            out[x].g = c.g * center + (l.g + r.g) * (0.5f * k);
            out[x].b = c.b * center + (l.b + r.b) * (0.5f * k);
            out[x].a = c.a * center + (l.a + r.a) * (0.5f * k);
        }
    }
    for (int y = 0; y < h; ++y) {
        Pixel* row = img.row(y);
        const Pixel* up = temp.data() + static_cast<std::size_t>(clampInt(y - 1, 0, h - 1)) * static_cast<std::size_t>(w);
        const Pixel* mid = temp.data() + static_cast<std::size_t>(y) * static_cast<std::size_t>(w);
        const Pixel* down = temp.data() + static_cast<std::size_t>(clampInt(y + 1, 0, h - 1)) * static_cast<std::size_t>(w);
        for (int x = 0; x < w; ++x) {
            row[x].r = mid[x].r * center + (up[x].r + down[x].r) * (0.5f * k);
            row[x].g = mid[x].g * center + (up[x].g + down[x].g) * (0.5f * k);
            row[x].b = mid[x].b * center + (up[x].b + down[x].b) * (0.5f * k);
            row[x].a = mid[x].a * center + (up[x].a + down[x].a) * (0.5f * k);
        }
    }
}

// ---------------------------------------------------------------------------
// Render state
// ---------------------------------------------------------------------------

struct State {
    const Image& src;
    Image& layer;
    const AsciiParams& p;
    const RenderContext& rc;
    const ResolvedPools& pools;
    MaskCache& masks;
    AsciiRenderStats& stats;

    int width = 0;
    int height = 0;
    int cellW = 1;
    int cellH = 1;
    int x0 = 0;
    int y0 = 0;
    int x1 = 0;
    int y1 = 0;
    int cols = 0;
    int rows = 0;
    float density = 1.0f;
    float cutoff = 0.0f;
    float bold = 1.0f;
    int sub = 1;
    std::uint32_t bucket = 0;
    float randomCharacters = 0.0f;
    float randomWords = 0.0f;
};

// Preset-specific visibility floor.  The reference clips keep large parts of
// the frame genuinely black; strength still lowers the floor towards zero.
inline float presetCutoffFloor(Preset preset) {
    switch (preset) {
        case Preset::Cgo: return 0.20f;
        case Preset::Ghost: return 0.18f;
        case Preset::Rainbow: return 0.32f;
        case Preset::Threshold: return 0.30f;
        case Preset::Liquid: return 0.10f;
        default: return 0.0f;
    }
}

inline int colX(const State& s, int col) { return s.x0 + col * s.cellW; }
inline int rowY(const State& s, int row) { return s.y0 + row * s.cellH; }

inline bool randomizes(const State& s, int col, int row, std::uint32_t salt) {
    if (s.randomCharacters <= 0.0f) return false;
    const std::uint64_t h = cellHash(s.p.seed, s.bucket, col, row, salt);
    return unitFloat(h) < s.randomCharacters;
}

// Luminance ramping with an animated local jitter.  The ramp index always
// follows the image; Random Characters moves the pick inside a narrow window
// around that index, so the composition stays coherent while every glyph keeps
// changing from frame to frame.
inline Codepoint pickGlyph(const State& s, const GlyphPool& pool, float luma,
                           int col, int row, std::uint32_t salt,
                           float windowScale = 0.08f) {
    if (pool.empty()) return 0;
    float t = luma;
    if (s.p.reverse) t = 1.0f - t;
    const int n = static_cast<int>(pool.size());
    int index = static_cast<int>(std::lround(t * static_cast<float>(n - 1)));
    if (randomizes(s, col, row, salt)) {
        const int span = std::max(1, static_cast<int>(static_cast<float>(n) * windowScale));
        const std::uint64_t h = cellHash(s.p.seed, s.bucket, col, row, salt ^ 0x5A5Au);
        index += static_cast<int>(boundedInt(h, static_cast<std::uint32_t>(2 * span + 1))) - span;
    }
    index = clampInt(index, 0, n - 1);
    return pool.items[static_cast<std::size_t>(index)].codepoint;
}

// Category-aware cell drawing for the glyph-field presets.
struct CellChoice {
    Codepoint codepoint = 0;
    int face = 0;
    float scale = 1.0f;
    GlyphCategory category = GlyphCategory::Letter;
};

CellChoice chooseCellGlyph(const State& s, float luma, int col, int row,
                           bool allowWords) {
    CellChoice choice;
    const std::uint64_t h = cellHash(s.p.seed, s.bucket, col, row, 0x1234u);
    const float r = unitFloat(h);

    const bool hasLetters = !s.pools.letters.empty();
    const bool hasNumbers = !s.pools.numbers.empty();
    const bool hasWords = allowWords && s.pools.wordMode &&
                          !s.pools.wordGlyphs.empty() && s.p.words.enabled;

    // Category pick: words take a share of the cells when enabled.
    float weightLetters = hasLetters ? 1.0f : 0.0f;
    float weightNumbers = hasNumbers ? 0.55f : 0.0f;
    float weightWords = hasWords ? 0.9f : 0.0f;
    if (s.p.charset != Charset::Auto) {
        weightNumbers = 0.0f;
        weightWords = 0.0f;
        weightLetters = 1.0f;
    }
    const float total = weightLetters + weightNumbers + weightWords;
    Codepoint glyph = 0;
    int face = s.pools.letterFace;
    GlyphCategory category = GlyphCategory::Letter;
    float scale = s.p.characters.enabled ? s.p.characters.scale : 1.0f;

    if (total <= 0.0f) return choice;

    const float pick = r * total;
    if (hasLetters && pick < weightLetters) {
        glyph = pickGlyph(s, s.pools.letters, luma, col, row, 0x2001u, false);
        face = s.pools.letters.face;
        category = GlyphCategory::Letter;
        scale = s.p.characters.enabled ? s.p.characters.scale : 1.0f;
    } else if (hasNumbers && pick < weightLetters + weightNumbers) {
        glyph = pickGlyph(s, s.pools.numbers, luma, col, row, 0x2002u, false);
        face = s.pools.numbers.face;
        category = GlyphCategory::Number;
        scale = s.p.numbers.enabled ? s.p.numbers.scale : 1.0f;
    } else if (hasWords) {
        glyph = pickGlyph(s, s.pools.wordGlyphs, luma, col, row, 0x2003u, false);
        face = s.pools.wordFace;
        category = GlyphCategory::Word;
        scale = s.p.words.enabled ? s.p.words.scale : 1.0f;
    } else if (hasLetters) {
        glyph = pickGlyph(s, s.pools.letters, luma, col, row, 0x2004u, false);
        face = s.pools.letters.face;
        category = GlyphCategory::Letter;
    }

    choice.codepoint = glyph;
    choice.face = face;
    choice.category = category;
    choice.scale = scale;
    return choice;
}

// ---------------------------------------------------------------------------
// Presets
// ---------------------------------------------------------------------------

void renderGlyphField(State& s) {
    const bool isAlien = s.p.preset == Preset::AlienSignal;
    const Palette palette = isAlien && s.p.palette == Palette::Source ? Palette::Acid
                                                                    : s.p.palette;
    const float paletteStrength =
        (isAlien && s.p.palette == Palette::Source) ? 0.85f : s.p.paletteStrength;

    // A per-cell shade under the glyphs keeps the type legible over bright
    // footage without covering the footage the glyphs do not occupy.  Alien
    // Signal uses a near-black cell plate instead of a light shade.
    const Rgb shadeColor = isAlien ? Rgb{0.010f, 0.020f, 0.012f} : Rgb{0.0f, 0.0f, 0.0f};
    const float shadeAlpha = isAlien ? 0.90f : 0.30f;

    for (int row = 0; row < s.rows; ++row) {
        for (int col = 0; col < s.cols; ++col) {
            const int cx = colX(s, col);
            const int cy = rowY(s, row);
            const int stagger = (s.p.preset == Preset::AlienSignal && (row & 1)) ? s.cellW / 2 : 0;
            const Box box = sampleBox(s.src, cx + stagger, cy, cx + s.cellW + stagger,
                                      cy + s.cellH, s.p.channel);
            if (box.luma < s.cutoff) continue;
            fillRect(s.layer, cx, cy, cx + s.cellW, cy + s.cellH, shadeColor, shadeAlpha);

            float alphaLift = 1.0f;
            if (isAlien) {
                const float n = unitFloat(cellHash(s.p.seed, s.bucket, col, row, 0x77u));
                alphaLift = 0.55f + 0.75f * n;
                if (((row + static_cast<int>(s.bucket)) % 9) == 0) alphaLift *= 0.30f;
            }

            Rgb color = paletteApply(palette, paletteStrength, box.luma, box.color);
            if (rgbLuma(color) < 0.10f) color = {0.35f, 0.35f, 0.35f};
            // Ink reads against the shade: lift it towards white so glyphs stay
            // visible over both dark and bright footage.
            color = rgbClamp(rgbLerp(color, Rgb{1.0f, 1.0f, 1.0f}, 0.42f));

            const int sub = s.sub;
            const int sw = std::max(1, s.cellW / sub);
            const int sh = std::max(1, s.cellH / sub);
            for (int sy = 0; sy < sub; ++sy) {
                for (int sx = 0; sx < sub; ++sx) {
                    const int px = cx + sx * sw;
                    const int py = cy + sy * sh;
                    Box subBox = box;
                    if (sub > 1) {
                        subBox = sampleBox(s.src, px + stagger, py, px + sw + stagger,
                                           py + sh, s.p.channel);
                        if (subBox.luma < s.cutoff * 0.8f) continue;
                    }
                    const CellChoice choice =
                        chooseCellGlyph(s, subBox.luma, col * sub + sx, row * sub + sy, true);
                    if (choice.codepoint == 0) continue;
                    Rgb c = paletteApply(palette, paletteStrength, subBox.luma, subBox.color);
                    if (rgbLuma(c) < 0.10f) c = color;
                    const float alpha = clamp01(alphaLift);
                    drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint, px, py,
                                 sw, sh, s.bold * choice.scale, s.p.margin, c,
                                 alpha);
                    ++s.stats.glyphsDrawn;
                }
            }
        }
    }
}

void renderLiquid(State& s) {
    const float paletteStrength =
        s.p.palette == Palette::Source ? 0.55f : s.p.paletteStrength;
    const Palette palette =
        s.p.palette == Palette::Source ? Palette::Sand : s.p.palette;
    const int gap = std::max(1, static_cast<int>(std::lround(s.cellH * 0.14f +
                                                            s.p.margin * s.cellH * 0.5f)));
    const float radius = static_cast<float>(s.cellH) * 0.32f;

    for (int row = 0; row < s.rows; ++row) {
        const int cy = rowY(s, row);
        int col = 0;
        int tileIndex = 0;
        while (col < s.cols) {
            const std::uint64_t th = cellHash(s.p.seed, s.bucket, tileIndex, row, 0x9E37u);
            int spanCells = 1 + static_cast<int>(boundedInt(th, 3));  // 1..3 cells
            if (s.density > 1.2f) spanCells += static_cast<int>((s.density - 1.0f) * 0.6f);
            spanCells = clampInt(spanCells, 1, 6);
            if (col + spanCells > s.cols) spanCells = s.cols - col;

            const int tx = colX(s, col);
            const int tw = spanCells * s.cellW - gap;
            if (tw <= 1) { ++col; continue; }
            const Box box = sampleBox(s.src, tx, cy, tx + tw, cy + s.cellH, s.p.channel);
            if (box.luma < s.cutoff * 0.7f) { col += spanCells; ++tileIndex; continue; }

            Rgb fill = rgbLerp(rgbSaturate(box.color, 0.78f),
                               paletteSample(palette, clamp01(0.15f + box.luma * 1.25f)),
                               clamp01(paletteStrength * 0.9f));
            // Tiles read as light, washed colour chips in the reference.
            fill = rgbClamp(rgbLerp(fill, Rgb{0.92f, 0.90f, 0.86f}, 0.30f));
            fill = rgbClamp(rgbLerp(fill, Rgb{1.0f, 1.0f, 1.0f}, 0.06f));
            fillRoundedRect(s.layer, tx, cy, tw, s.cellH, radius, fill, 1.0f);

            const bool darkInk = rgbLuma(fill) > 0.55f;
            const Rgb ink = darkInk ? Rgb{0.06f, 0.05f, 0.05f}
                                    : rgbClamp(rgbLerp(fill, Rgb{1.0f, 1.0f, 1.0f}, 0.75f));

            const int innerPad = std::max(1, static_cast<int>(static_cast<float>(s.cellH) * 0.10f));
            const bool preferWord = unitFloat(th >> 17) < 0.55f;
            if (s.pools.wordMode && s.p.words.enabled && (preferWord || spanCells > 2)) {
                const std::uint64_t wh =
                    randomizes(s, col, row, 0x3311u) || s.randomWords <= 0.0f
                        ? cellHash(s.p.seed, 0u, tileIndex, row, 0x4411u)
                        : cellHash(s.p.seed, s.bucket, tileIndex, row, 0x4411u);
                Text word = generateWord(s.pools.wordScript, wh, 2, 3);
                if (s.pools.wordScript == ScriptId::Arabic) word = layoutVisual(word);
                else if (s.p.reverse) std::reverse(word.begin(), word.end());
                drawWordRun(s.layer, s.masks, s.pools.wordFace, word, tx + innerPad, cy,
                            tw - 2 * innerPad, s.cellH, s.p.words.scale * 0.92f, ink,
                            0.95f);
                ++s.stats.glyphsDrawn;
            } else {
                const int glyphs = spanCells;
                for (int g = 0; g < glyphs; ++g) {
                    const CellChoice choice = chooseCellGlyph(
                        s, box.luma, col + g, row, false);
                    if (choice.codepoint == 0) continue;
                    const int gx = tx + g * (tw / glyphs);
                    drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint, gx, cy,
                                 tw / glyphs, s.cellH, 0.62f * choice.scale,
                                 s.p.margin * 0.5f, ink, 0.92f);
                    ++s.stats.glyphsDrawn;
                }
            }
            col += spanCells;
            ++tileIndex;
        }
    }
}

void renderGhost(State& s) {
    const Rgb plate{0.075f, 0.008f, 0.012f};
    fillRect(s.layer, s.x0, s.y0, s.x1, s.y1, plate, 0.94f);

    // Diagonal ray bands, additive over the plate.  The rays sit behind the
    // glyph field and stay low contrast so the cream type stays legible.
    const float angle = 0.55f;
    const float ca = std::cos(angle);
    const float sa = std::sin(angle);
    const float phase = static_cast<float>(s.rc.timeSeconds) * 0.35f;
    for (int y = s.y0; y < s.y1; ++y) {
        for (int x = s.x0; x < s.x1; ++x) {
            const float u = (static_cast<float>(x) * ca + static_cast<float>(y) * sa) * 0.0055f;
            const float v = 0.5f + 0.5f * std::sin(u * 6.28318f + phase);
            const float band = v * v * v * v * v * v;
            if (band <= 0.02f) continue;
            const Rgb ray{0.60f, 0.09f, 0.10f};
            compositePixel(s.layer, x, y, ray, band * 0.13f);
        }
    }

    const Palette palette =
        s.p.palette == Palette::Source ? Palette::Cream : s.p.palette;
    const float paletteStrength =
        s.p.palette == Palette::Source ? 0.90f : s.p.paletteStrength;
    for (int row = 0; row < s.rows; ++row) {
        for (int col = 0; col < s.cols; ++col) {
            const int cx = colX(s, col);
            const int cy = rowY(s, row);
            const Box box = sampleBox(s.src, cx, cy, cx + s.cellW, cy + s.cellH,
                                      s.p.channel);
            if (box.luma < s.cutoff) continue;
            const CellChoice choice = chooseCellGlyph(s, box.luma, col, row, false);
            if (choice.codepoint == 0) continue;
            Rgb color = paletteApply(palette, paletteStrength, box.luma, box.color);
            // Cream ink: the reference keeps the type pale and warm whatever
            // the source colour is.
            color = rgbLerp(color, Rgb{0.98f, 0.95f, 0.88f}, 0.75f);
            const float alpha = 0.78f + 0.22f * box.luma;
            drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint, cx, cy,
                         s.cellW, s.cellH, s.bold * choice.scale, s.p.margin, color,
                         clamp01(alpha));
            ++s.stats.glyphsDrawn;
        }
    }
}

void renderCgo(State& s) {
    // Dark, slightly warm plate so the glyph field reads as an overlay plate.
    fillRect(s.layer, s.x0, s.y0, s.x1, s.y1, Rgb{0.02f, 0.005f, 0.004f}, 0.94f);

    const Palette palette =
        s.p.palette == Palette::Source ? Palette::Ember : s.p.palette;
    const float paletteStrength =
        s.p.palette == Palette::Source ? 0.30f : s.p.paletteStrength;

    for (int row = 0; row < s.rows; ++row) {
        for (int col = 0; col < s.cols; ++col) {
            const int cx = colX(s, col);
            const int cy = rowY(s, row);
            const Box box = sampleBox(s.src, cx, cy, cx + s.cellW, cy + s.cellH,
                                      s.p.channel);
            if (box.luma < s.cutoff) continue;
            const int sub = s.sub;
            const int sw = std::max(1, s.cellW / sub);
            const int sh = std::max(1, s.cellH / sub);
            for (int sy = 0; sy < sub; ++sy) {
                for (int sx = 0; sx < sub; ++sx) {
                    const int px = cx + sx * sw;
                    const int py = cy + sy * sh;
                    const Box sb = (sub > 1)
                                       ? sampleBox(s.src, px, py, px + sw, py + sh,
                                                   s.p.channel)
                                       : box;
                    if (sb.luma < s.cutoff * 0.85f) continue;
                    const CellChoice choice =
                        chooseCellGlyph(s, sb.luma, col * sub + sx, row * sub + sy, true);
                    if (choice.codepoint == 0) continue;
                    Rgb color = rgbSaturate(sb.color, 1.60f);
                    color = paletteApply(palette, paletteStrength, sb.luma, color);
                    // The reference glyph field is emissive: ink reads brighter
                    // than the footage it samples.
                    color = rgbClamp(rgbLerp(color, Rgb{1.0f, 0.90f, 0.74f},
                                             0.26f + 0.24f * (1.0f - sb.luma)));
                    color.r = std::min(1.0f, color.r * 1.25f + 0.06f);
                    color.g = std::min(1.0f, color.g * 1.20f + 0.05f);
                    color.b = std::min(1.0f, color.b * 1.15f + 0.04f);
                    if (rgbLuma(color) < 0.30f) color = {0.72f, 0.30f, 0.16f};
                    drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint, px, py,
                                 sw, sh,                                 s.bold * choice.scale * 1.15f, s.p.margin, color, 0.96f);
                    ++s.stats.glyphsDrawn;
                    if (sb.luma > 0.72f) {
                        // Hot accent: a larger, faint pass reads as emission.
                        const Rgb hot{1.0f, 0.45f, 0.10f};
                        drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint,
                                     px - sw / 2, py - sh / 2, sw * 2, sh * 2,
                                     s.bold * choice.scale, s.p.margin, hot, 0.16f);
                    }
                }
            }
        }
    }
}

void renderMosaic(State& s) {
    fillRect(s.layer, s.x0, s.y0, s.x1, s.y1, Rgb{0.02f, 0.025f, 0.07f}, 0.97f);
    const int block = std::max(3, static_cast<int>(std::lround(
                                      static_cast<float>(s.cellW) * 2.6f)));
    const Palette palette =
        s.p.palette == Palette::Source ? Palette::Navy : s.p.palette;
    const float paletteStrength =
        s.p.palette == Palette::Source ? 1.0f : s.p.paletteStrength;

    for (int y = s.y0; y < s.y1; y += block) {
        for (int x = s.x0; x < s.x1; x += block) {
            const int bx1 = std::min(x + block, s.x1);
            const int by1 = std::min(y + block, s.y1);
            const Box box = sampleBox(s.src, x, y, bx1, by1, s.p.channel);
            const std::uint64_t h = cellHash(s.p.seed, s.bucket, x / block, y / block,
                                             0xB10Cu);
            if (unitFloat(h) < 0.05f) continue;  // broken block: stair-stepped edges
            Rgb c = paletteApply(palette, paletteStrength, box.luma, box.color);
            c = rgbClamp(rgbLerp(c, paletteSample(palette, clamp01(box.luma)), 0.45f));
            // Quantize to seven bands for the mosaic look.
            c.r = std::round(c.r * 7.0f) / 7.0f;
            c.g = std::round(c.g * 7.0f) / 7.0f;
            c.b = std::round(c.b * 7.0f) / 7.0f;
            fillRect(s.layer, x, y, bx1, by1, rgbClamp(c), 0.98f);
        }
    }

    // Fine glyph layer on top of the blocks.
    const float gate = 0.75f + std::min(0.24f, (s.density - 1.0f) * 0.12f);
    for (int row = 0; row < s.rows; ++row) {
        for (int col = 0; col < s.cols; ++col) {
            const int cx = colX(s, col);
            const int cy = rowY(s, row);
            const Box box = sampleBox(s.src, cx, cy, cx + s.cellW, cy + s.cellH,
                                      s.p.channel);
            if (box.luma < 0.22f) continue;
            const std::uint64_t h = cellHash(s.p.seed, s.bucket, col, row, 0x5151u);
            if (unitFloat(h) > gate) continue;  // sparse specks, not a solid field
            const CellChoice choice = chooseCellGlyph(s, box.luma, col, row, false);
            if (choice.codepoint == 0) continue;
            Rgb ink = rgbLerp(paletteSample(palette, clamp01(0.6f + 0.4f * box.luma)),
                              Rgb{1.0f, 1.0f, 1.0f}, 0.70f);
            if (box.luma > 0.7f && box.color.r > box.color.b) ink = Rgb{1.0f, 0.72f, 0.38f};
            drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint, cx, cy,
                         s.cellW, s.cellH, 0.46f * s.bold * choice.scale,
                         s.p.margin, ink, 0.92f);
            ++s.stats.glyphsDrawn;
        }
    }
}

void renderRainbow(State& s) {
    fillRect(s.layer, s.x0, s.y0, s.x1, s.y1, Rgb{0.01f, 0.01f, 0.015f}, 0.95f);
    const Palette palette =
        s.p.palette == Palette::Source ? Palette::Chroma : s.p.palette;
    const float paletteStrength =
        s.p.palette == Palette::Source ? 1.0f : clamp01(s.p.paletteStrength + 0.35f);

    for (int row = 0; row < s.rows; ++row) {
        for (int col = 0; col < s.cols; ++col) {
            const int cx = colX(s, col);
            const int cy = rowY(s, row);
            const Box box = sampleBox(s.src, cx, cy, cx + s.cellW, cy + s.cellH,
                                      s.p.channel);
            if (box.luma < s.cutoff) continue;
            const CellChoice choice = chooseCellGlyph(s, box.luma, col, row, false);
            if (choice.codepoint == 0) continue;
            const std::uint64_t h = cellHash(s.p.seed, s.bucket, col, row, 0x7007u);
            // A small spatial jitter only: the reference hue follows tone, it is
            // not per-cell colour noise.
            const float jitter = (unitFloat(h) - 0.5f) * 0.05f;
            Rgb hueSource = rgbSaturate(box.color, 2.2f);
            const float t = clamp01(0.10f + box.luma * 0.95f + jitter);
            Rgb color = paletteSample(palette, t);
            color = rgbLerp(color, hueSource, 0.22f);
            if (box.luma > 0.85f) color = rgbLerp(color, Rgb{1.0f, 1.0f, 1.0f}, 0.55f);
            color = rgbSaturate(color, 1.25f);
            // The reference keeps the field dark: ink alpha follows tone so the
            // shadowed areas stay close to black.
            const float inkAlpha = 0.35f + 0.65f * std::min(1.0f, box.luma * 1.4f);
            drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint, cx, cy,
                         s.cellW, s.cellH, 0.95f * s.bold * choice.scale, s.p.margin,
                         color, inkAlpha);
            ++s.stats.glyphsDrawn;
        }
    }
    (void)paletteStrength;
}

void renderThreshold(State& s) {
    fillRect(s.layer, s.x0, s.y0, s.x1, s.y1, Rgb{0.012f, 0.012f, 0.012f}, 0.96f);
    const Palette palette =
        s.p.palette == Palette::Source ? Palette::Grey : s.p.palette;
    const float thicknessGain = 1.0f + std::min(1.2f, std::max(0.0f, s.density - 1.0f) * 0.5f);

    for (int row = 0; row < s.rows; ++row) {
        const int cy = rowY(s, row);
        for (int col = 0; col < s.cols; ++col) {
            const int cx = colX(s, col);
            const Box box = sampleBox(s.src, cx, cy, cx + s.cellW, cy + s.cellH,
                                      s.p.channel);
            // Row segments only exist above the threshold: the reference keeps
            // large parts of the frame entirely black.
            if (box.luma < std::max(s.cutoff, 0.30f)) continue;
            const std::uint64_t gate = cellHash(s.p.seed, s.bucket, col, row, 0x1A2Bu);
            if (unitFloat(gate) > 0.86f + std::min(0.12f, (s.density - 1.0f) * 0.06f)) continue;
            int thickness = static_cast<int>(std::lround(
                static_cast<float>(s.cellH) * box.luma * thicknessGain));
            thickness = clampInt(thickness, std::max(2, s.cellH / 3), s.cellH);
            const std::uint64_t h = cellHash(s.p.seed, s.bucket, col, row, 0xBAA5u);
            const float span = 0.95f + 0.05f * unitFloat(h);
            const int w = std::max(1, static_cast<int>(std::lround(
                                          static_cast<float>(s.cellW) * span)));
            const int top = cy + (s.cellH - thickness) / 2;
            Rgb color = paletteSample(palette, clamp01(0.45f + 0.55f * box.luma));
            color = rgbLerp(color, Rgb{0.95f, 0.95f, 0.95f}, 0.35f);
            color = rgbLerp(color, box.color, 0.12f);
            if (unitFloat(h >> 8) < 0.08f) {
                // Broken segment: a few small squares instead of a solid bar.
                const int sq = std::max(1, thickness);
                for (int x = cx; x < cx + w; x += std::max(2, sq * 2)) {
                    fillRect(s.layer, x, top, x + sq, top + sq, color, 0.95f);
                }
            } else {
                fillRect(s.layer, cx, top, cx + w, top + thickness, color, 0.95f);
            }
            ++s.stats.glyphsDrawn;
        }
    }
}

void renderOrganic(State& s) {
    const Palette palette =
        s.p.palette == Palette::Source ? Palette::Vapor : s.p.palette;
    const float paletteStrength =
        s.p.palette == Palette::Source ? 0.55f : s.p.paletteStrength;
    const float time = static_cast<float>(s.rc.timeSeconds);
    const float amp = static_cast<float>(s.cellW) * 1.15f;

    const int overscan = 1;
    for (int row = -overscan; row < s.rows + overscan; ++row) {
        for (int col = -overscan; col < s.cols + overscan; ++col) {
            const int cx = colX(s, col);
            const int cy = rowY(s, row);
            const std::uint64_t wh = cellHash(s.p.seed, s.bucket, col, row, 0x0D06u);
            const float nx = unitFloat(wh) - 0.5f;
            const float ny = unitFloat(wh >> 21) - 0.5f;
            // Domain warp around the cell centre.
            const int sx = static_cast<int>(static_cast<float>(cx) +
                                            nx * amp + amp * 0.35f *
                                                std::sin(time * 0.8f + static_cast<float>(row) * 0.35f));
            const int sy = static_cast<int>(static_cast<float>(cy) +
                                            ny * amp + amp * 0.35f *
                                                std::cos(time * 0.6f + static_cast<float>(col) * 0.29f));
            const Box box = sampleBox(s.src, sx, sy, sx + s.cellW, sy + s.cellH,
                                      s.p.channel);
            if (box.luma < s.cutoff) continue;
            const CellChoice choice = chooseCellGlyph(s, box.luma, col, row, true);
            if (choice.codepoint == 0) continue;
            fillRect(s.layer, cx, cy, cx + s.cellW, cy + s.cellH, Rgb{0.0f, 0.0f, 0.0f}, 0.38f);
            Rgb color = paletteApply(palette, paletteStrength, box.luma, box.color);
            color = rgbSaturate(color, 1.15f);
            const int rotation = static_cast<int>(boundedInt(wh >> 40, 4)) * 90;
            const float jitter = 0.68f + 0.62f * unitFloat(wh >> 8);
            drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint, cx, cy,
                         s.cellW, s.cellH, s.bold * choice.scale * jitter, s.p.margin,
                         color, 0.88f, rotation);
            // A second, smaller pass reads as wet ink pooling under the glyph.
            drawGlyphFit(s.layer, s.masks, choice.face, choice.codepoint,
                         cx + s.cellW / 5, cy + s.cellH / 6, s.cellW, s.cellH,
                         s.bold * choice.scale * jitter * 0.7f, s.p.margin, color,
                         0.30f, rotation);
            ++s.stats.glyphsDrawn;
        }
    }
    blurPremultiplied(s.layer, 0.45f);
}

} // namespace

// ---------------------------------------------------------------------------
// Entry points
// ---------------------------------------------------------------------------

AsciiRenderStats renderAscii(const Image& source, Image& destination,
                             const RenderContext& context,
                             const AsciiParams& params) {
    AsciiRenderStats stats;
    destination = source;
    if (source.empty()) return stats;

    const ResolvedPools pools = resolvePools(params);
    MaskCache masks;
    Image layer(source.width(), source.height());

    State s{source,   layer, params, context, pools, masks, stats,
            source.width(), source.height()};
    s.width = source.width();
    s.height = source.height();
    const float cellPx = std::max(2.0f, params.cells * std::max(0.01f, context.renderScale));
    s.cellW = clampInt(static_cast<int>(std::lround(cellPx)), 2, 512);
    s.cellH = s.cellW;

    const float clip = clamp01(params.clipScale <= 0.0f ? 1.0f : params.clipScale);
    s.x0 = static_cast<int>(std::lround((1.0f - clip) * 0.5f * static_cast<float>(s.width)));
    s.y0 = static_cast<int>(std::lround((1.0f - clip) * 0.5f * static_cast<float>(s.height)));
    s.x1 = s.width - s.x0;
    s.y1 = s.height - s.y0;
    s.cols = (s.x1 - s.x0) / s.cellW;
    s.rows = (s.y1 - s.y0) / s.cellH;
    stats.cellsAcross = s.cols;
    stats.cellsDown = s.rows;

    s.density = std::min(5.0f, std::max(0.0f, params.strength / 100.0f));
    s.cutoff = 0.55f - 0.50f * std::min(s.density, 1.0f);
    {
        const float floorValue = presetCutoffFloor(params.preset);
        const float relaxed = floorValue * std::max(0.0f, 1.0f - (s.density - 1.0f) * 0.35f);
        s.cutoff = std::max(s.cutoff, relaxed);
    }
    s.bold = 1.0f + 0.05f * std::max(0.0f, s.density - 1.0f);
    s.sub = s.density <= 1.0f ? 1 : (s.density <= 2.0f ? 2 : 3);
    s.randomCharacters = params.randomCharacters
                             ? clamp01(1.0f)
                             : 0.0f;
    s.randomWords = params.randomWords ? 1.0f : 0.0f;
    {
        const float rate = params.randomTiming <= 0.0f
                               ? 0.0f
                               : 1.0f + params.randomTiming * 0.35f;
        s.bucket = (rate <= 0.0f)
                       ? 0u
                       : static_cast<std::uint32_t>(
                             std::floor(std::max(0.0, context.timeSeconds) * rate));
    }

    if (s.cols <= 0 || s.rows <= 0) return stats;

    if (s.density > 0.0f) {
        switch (params.preset) {
            case Preset::AlienSignal: renderGlyphField(s); break;
            case Preset::Liquid: renderLiquid(s); break;
            case Preset::Ghost: renderGhost(s); break;
            case Preset::Cgo: renderCgo(s); break;
            case Preset::Mosaic: renderMosaic(s); break;
            case Preset::Rainbow: renderRainbow(s); break;
            case Preset::Threshold: renderThreshold(s); break;
            case Preset::Organic: renderOrganic(s); break;
            case Preset::Default:
            default: renderGlyphField(s); break;
        }
    }

    // Amount: scale the ASCII plate's own alpha over the untouched source.
    // At 0 the output is exactly the source, and transparent plate pixels are
    // never allowed to erase the source underneath the glyph field.
    const float amount = clamp01(params.amount);
    std::size_t inked = 0;
    for (std::size_t i = 0; i < layer.pixels().size(); ++i) {
        const Pixel& a = layer.pixels()[i];
        Pixel& d = destination.pixels()[i];
        const Pixel& src = source.pixels()[i];
        const float plateAlpha = clamp01(a.a) * amount;
        const float keep = 1.0f - plateAlpha;
        d.r = a.r * amount + src.r * keep;
        d.g = a.g * amount + src.g * keep;
        d.b = a.b * amount + src.b * keep;
        d.a = plateAlpha + src.a * keep;
        if (plateAlpha > 0.02f) ++inked;
    }
    const std::size_t total = layer.pixels().size();
    stats.inkCoverage = total > 0
                            ? static_cast<float>(inked) / static_cast<float>(total)
                            : 0.0f;
    return stats;
}

AsciiEngine::AsciiEngine(AsciiParams params) : params_(params) {}

void AsciiEngine::render(const Image& source, Image& destination,
                         const RenderContext& context) const {
    renderAscii(source, destination, context, params_);
}

} // namespace ascii
} // namespace xao
