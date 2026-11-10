#include "xao/AsciiEngine.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

namespace {
bool near(float a,float b){return std::fabs(a-b)<1.0e-5f;}
int fail(const char* s){std::cerr<<"FAIL: "<<s<<'\\n';return 1;}
}
int main(){
    xao::Image src(16,16),a(16,16),b(16,16);
    for(int y=0;y<16;++y)for(int x=0;x<16;++x){
        const float v=x<8?0.0f:1.0f;
        src.at(x,y)={v,v,v,1.0f};
    }
    xao::AsciiParams p;p.cellSize=8;p.colorize=false;p.paper={0,0,0,0};
    xao::AsciiEngine engine(p);engine.render(src,a,{});
    engine.render(src,b,{});
    bool ink=false,paper=false,different=false;
    for(std::size_t i=0;i<a.pixels().size();++i){
        const auto& q=a.pixels()[i];const auto& r=b.pixels()[i];
        ink|=q.a>0.5f;paper|=q.a<0.5f;
        different|=!near(q.r,r.r)||!near(q.a,r.a);
        if(!std::isfinite(q.r)||!std::isfinite(q.g)||!std::isfinite(q.b)||!std::isfinite(q.a))return fail("finite output");
    }
    if(!ink||!paper)return fail("glyph and transparent paper coverage");
    if(different)return fail("deterministic rendering");

    xao::Image transparent(8,8),transparentOut(8,8);
    xao::AsciiEngine defaultEngine;defaultEngine.render(transparent,transparentOut,{});
    for(const auto& q:transparentOut.pixels())if(q.a>1.0e-6f)return fail("transparent source remains transparent");

    xao::AsciiParams solid;p=solid;p.colorize=false;p.preserveCellAlpha=false;
    p.ink={0.25f,0.0f,0.0f,0.5f};p.paper={0.0f,0.0f,0.0f,0.0f};
    xao::AsciiEngine alphaEngine(p);
    xao::Image semi(8,8),semiOut(8,8);
    for(auto& q:semi.pixels())q={0.5f,0.0f,0.0f,0.5f};
    alphaEngine.render(semi,semiOut,{});
    bool foundInk=false;
    for(const auto& q:semiOut.pixels())if(near(q.r,0.25f)&&near(q.a,0.5f))foundInk=true;
    if(!foundInk)return fail("premultiplied ink color preserved without double alpha");

    bool threw=false;
    try{xao::Image wrong(15,16);engine.render(src,wrong,{});}catch(const std::invalid_argument&){threw=true;}
    if(!threw)return fail("dimension mismatch rejected");
    std::cout<<"XAO ASCII engine tests passed\\n";
    return 0;
}