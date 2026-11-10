#pragma once
#include "xao/Engine.h"
namespace xao {
struct AsciiParams {
 int cellSize=8; float glyphScale=0.88f; float contrast=1.0f; float brightness=0.0f;
 bool invert=false; bool colorize=true; bool preserveCellAlpha=true;
 Pixel ink{1,1,1,1}; Pixel paper{0,0,0,0};
};
class AsciiEngine final : public Engine {
public:
 explicit AsciiEngine(AsciiParams p={}) noexcept : params_(p) {}
 const char* id() const noexcept override { return "xao.ascii"; }
 void setParams(const AsciiParams& p) noexcept { params_=p; }
 const AsciiParams& params() const noexcept { return params_; }
 void render(const Image&,Image&,const RenderContext&) const override;
private: AsciiParams params_;
};
}