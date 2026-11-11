#include "xao/AsciiEngine.h"
#include "xao/AsciiReferencePalettes.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
namespace { bool near(float a,float b){return std::fabs(a-b)<1.0e-5f;} int fail(const char* s){std::cerr<<"FAIL: "<<s<<'\n';return 1;} }
int main(){
 xao::Image src(32,16),a(32,16),b(32,16);for(int y=0;y<16;++y)for(int x=0;x<32;++x){float v=x<16?0.0f:1.0f;src.at(x,y)={v,v,v,1};}
 xao::AsciiParams p;p.cellSize=8;p.colorize=false;p.paper={0,0,0,0};xao::AsciiEngine engine(p);engine.render(src,a,{});engine.render(src,b,{});
 bool ink=false,paper=false,different=false;for(std::size_t i=0;i<a.pixels().size();++i){const auto&q=a.pixels()[i];const auto&r=b.pixels()[i];ink|=q.a>0.5f;paper|=q.a<0.5f;different|=!near(q.r,r.r)||!near(q.a,r.a);if(!std::isfinite(q.r)||!std::isfinite(q.g)||!std::isfinite(q.b)||!std::isfinite(q.a))return fail("finite output");}
 if(!ink||!paper)return fail("glyph and transparent paper coverage");if(different)return fail("deterministic rendering");
 xao::Image transparent(8,8),transparentOut(8,8);xao::AsciiEngine defaultEngine;defaultEngine.render(transparent,transparentOut,{});for(const auto&q:transparentOut.pixels())if(q.a>1e-6f)return fail("transparent source remains transparent");
 xao::AsciiParams solid;solid.colorize=false;solid.preserveCellAlpha=false;solid.ink={0.25f,0,0,0.5f};solid.paper={0,0,0,0};xao::AsciiEngine alphaEngine(solid);xao::Image semi(8,8),semiOut(8,8);for(auto&q:semi.pixels())q={0.5f,0,0,0.5f};alphaEngine.render(semi,semiOut,{});bool found=false;for(const auto&q:semiOut.pixels())if(near(q.r,0.25f)&&near(q.a,0.5f))found=true;if(!found)return fail("premultiplied ink color preserved without double alpha");
 bool threw=false;try{xao::Image wrong(15,16);engine.render(src,wrong,{});}catch(const std::invalid_argument&){threw=true;}if(!threw)return fail("dimension mismatch rejected");
 if(xao::cratesPreset(xao::AsciiPresetId::AlienSignal).cratesCharacterSet!=13)return fail("Alien Signal charset");
 if(std::string(xao::cratesPreset(xao::AsciiPresetId::PinkShapes).name)!="Pink Shapes")return fail("Pink Shapes label");
 if(xao::asciiCharacterSetName(xao::AsciiCharacterSetId::S1Braille)!="Braille")return fail("S1 character set catalog");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::S1Detailed).size()!=92)return fail("S1 detailed master ramp");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::S1Blocks).size()!=5)return fail("S1 blocks codepoints");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::S1Quadrants).size()!=16)return fail("S1 quadrants codepoints");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::S1BoxDrawing).size()!=6)return fail("S1 box drawing codepoints");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::AsciiArtMainSimple).size()!=5)return fail("ASCII Art main simple ramp");
 const auto* gb=xao::s1Palette(xao::S1PaletteId::GameBoyDMG);if(!gb||gb->count!=4||gb->colors[0].r!=0x0F||gb->colors[3].b!=0x81)return fail("S1 palette byte recovery");
 xao::AsciiParams preset;xao::applyCratesPreset(preset,xao::AsciiPresetId::Matrix);if(preset.characterSet!=xao::AsciiCharacterSetId::CratesBinary||!preset.randomCharacters)return fail("preset application");
 xao::AsciiParams rp=p;rp.randomCharacters=true;rp.randomAmount=0.8f;rp.randomTiming=true;rp.randomSpeed=1.0f;xao::AsciiEngine re(rp);xao::Image r0(32,16),r1(32,16),r2(32,16);xao::RenderContext c0;c0.timeSeconds=0; xao::RenderContext c1;c1.timeSeconds=0;xao::RenderContext c2;c2.timeSeconds=1;re.render(src,r0,c0);re.render(src,r1,c1);re.render(src,r2,c2);bool stable=true,animated=false;for(std::size_t i=0;i<r0.pixels().size();++i){stable&=near(r0.pixels()[i].r,r1.pixels()[i].r)&&near(r0.pixels()[i].a,r1.pixels()[i].a);animated|=!near(r0.pixels()[i].r,r2.pixels()[i].r)||!near(r0.pixels()[i].a,r2.pixels()[i].a);}if(!stable)return fail("random deterministic at same time");if(!animated)return fail("random timing advances");
 std::cout<<"XAO ASCII engine tests passed\n";return 0;
}
