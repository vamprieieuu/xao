#include "xao/AsciiEngine.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <stdexcept>

namespace xao {
namespace {
constexpr std::array<std::array<unsigned char, 7>, 10> ramp{{
    {{0,0,0,0,0,0,0}}, {{0,0,0,4,0,0,0}}, {{0,0,4,0,4,0,0}},
    {{0,0,4,4,4,0,0}}, {{0,4,4,0,4,4,0}}, {{0,4,4,4,4,4,0}},
    {{4,4,4,0,4,4,4}}, {{21,10,21,10,21,10,21}},
    {{21,31,21,31,21,31,21}}, {{31,31,31,31,31,31,31}}
}};
float clamp01(float v) { return std::max(0.0f, std::min(1.0f, v)); }
float luminance(const Pixel& p) {
    if (p.a <= 1.0e-8f) return 0.0f;
    return clamp01((0.2126f*p.r + 0.7152f*p.g + 0.0722f*p.b) / p.a);
}
Pixel withCoverage(Pixel p, float coverage) {
    p.r *= coverage; p.g *= coverage; p.b *= coverage; p.a *= coverage;
    return p;
}
}
void AsciiEngine::render(const Image& src, Image& dst, const RenderContext&) const {
    if (src.width() != dst.width() || src.height() != dst.height())
        throw std::invalid_argument("ASCII dimensions must match");
    const int w=src.width(), h=src.height();
    const int cell=std::max(2, std::min(256, params_.cellSize));
    const float scale=std::max(0.1f, std::min(1.0f, params_.glyphScale));
    const float contrast=std::max(0.0f, std::min(4.0f, params_.contrast));
    const float brightness=std::max(-1.0f, std::min(1.0f, params_.brightness));
    for (int y0=0; y0<h; y0+=cell) for (int x0=0; x0<w; x0+=cell) {
        const int x1=std::min(w,x0+cell), y1=std::min(h,y0+cell);
        double sumLum=0.0, sumAlpha=0.0;
        Pixel average{0,0,0,0};
        int count=0;
        for (int y=y0; y<y1; ++y) for (int x=x0; x<x1; ++x) {
            const Pixel& p=src.row(y)[x];
            average.r+=p.r; average.g+=p.g; average.b+=p.b; average.a+=p.a;
            sumLum+=luminance(p); sumAlpha+=clamp01(p.a); ++count;
        }
        const float inv=1.0f/static_cast<float>(count);
        average.r*=inv; average.g*=inv; average.b*=inv; average.a*=inv;
        float tone=clamp01((static_cast<float>(sumLum/count)-0.5f)*contrast+0.5f+brightness);
        if (params_.invert) tone=1.0f-tone;
        const int glyph=std::max(0,std::min(9,static_cast<int>(std::lround(tone*9.0f))));
        const float coverage=params_.preserveCellAlpha ? static_cast<float>(sumAlpha/count) : 1.0f;
        Pixel foreground=params_.colorize ? average : params_.ink;
        if (params_.colorize && !params_.preserveCellAlpha) {
            if (foreground.a > 1.0e-8f) {
                foreground.r/=foreground.a; foreground.g/=foreground.a; foreground.b/=foreground.a;
            } else foreground.r=foreground.g=foreground.b=0.0f;
            foreground.a=1.0f;
        }
        Pixel background=params_.paper;
        if (params_.preserveCellAlpha) {
            foreground=withCoverage(foreground,coverage);
            background=withCoverage(background,coverage);
        }
        const float glyphW=std::max(1.0f,(x1-x0)*scale);
        const float glyphH=std::max(1.0f,(y1-y0)*scale);
        const float left=(x0+x1-glyphW)*0.5f, top=(y0+y1-glyphH)*0.5f;
        for (int y=y0; y<y1; ++y) {
            Pixel* out=dst.row(y);
            for (int x=x0; x<x1; ++x) {
                const int gx=static_cast<int>((x-left)*5.0f/glyphW);
                const int gy=static_cast<int>((y-top)*7.0f/glyphH);
                const bool on=gx>=0&&gx<5&&gy>=0&&gy<7&&((ramp[glyph][gy]>>(4-gx))&1u)!=0;
                out[x]=on?foreground:background;
            }
        }
    }
}
} // namespace xao