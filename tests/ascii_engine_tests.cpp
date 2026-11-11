#include "xao/AsciiEngine.h"
#include <cmath>
#include <iostream>
#include <stdexcept>
namespace {
bool near(float a,float b){return std::fabs(a-b)<1.0e-5f;}
int fail(const char* s){std::cerr<<"FAIL: "<<s<<'\n';return 1;}
bool differs(const xao::Image& a,const xao::Image& b){for(std::size_t i=0;i<a.pixels().size();++i)if(!near(a.pixels()[i].r,b.pixels()[i].r)||!near(a.pixels()[i].a,b.pixels()[i].a))return true;return false;}
}
int main(){
 xao::Image src(64,48),a(64,48),b(64,48);
 for(int y=0;y<48;++y)for(int x=0;x<64;++x){float v=(float)x/63.0f;src.at(x,y)={v*0.8f,v*0.55f,v*0.3f,1};}
 xao::AsciiParams p;p.cellSize=8;p.colorize=true;p.paper={0,0,0,0};xao::AsciiEngine engine(p);engine.render(src,a,{});engine.render(src,b,{});
 bool visible=false;for(std::size_t i=0;i<a.pixels().size();++i){const auto&q=a.pixels()[i];visible|=q.a>0.05f;if(!std::isfinite(q.r)||!std::isfinite(q.g)||!std::isfinite(q.b)||!std::isfinite(q.a))return fail("finite output");}
 if(!visible)return fail("default ASCII output visible");if(differs(a,b))return fail("deterministic same-time rendering");
 xao::Image transparent(8,8),transparentOut(8,8);xao::AsciiEngine defaultEngine;defaultEngine.render(transparent,transparentOut,{});for(const auto&q:transparentOut.pixels())if(q.a>1e-6f)return fail("transparent source remains transparent");
 xao::AsciiParams amountZero;amountZero.asciiAmount=0;amountZero.paper={0,0,0,0};xao::Image zeroOut(64,48);xao::AsciiEngine zeroEngine(amountZero);zeroEngine.render(src,zeroOut,{});for(const auto&q:zeroOut.pixels())if(q.a>1e-5f)return fail("ASCII Amount zero removes glyph layer");
 xao::AsciiParams fade;fade.blendWithOriginal=100;xao::Image fadeOut(64,48);xao::AsciiEngine fadeEngine(fade);fadeEngine.render(src,fadeOut,{});for(std::size_t i=0;i<src.pixels().size();++i)if(!near(src.pixels()[i].r,fadeOut.pixels()[i].r)||!near(src.pixels()[i].a,fadeOut.pixels()[i].a))return fail("ASCII Fade 100 returns source");
 bool threw=false;try{xao::Image wrong(63,48);engine.render(src,wrong,{});}catch(const std::invalid_argument&){threw=true;}if(!threw)return fail("dimension mismatch rejected");
 if(xao::cratesPreset(xao::AsciiPresetId::AlienSignal).cratesCharacterSet!=13)return fail("Alien Signal character mapping");
 if(std::string(xao::cratesPreset(xao::AsciiPresetId::PinkShapes).name)!="Pink Shapes")return fail("Pink Shapes label");
 if(xao::asciiCharacterSetName(xao::AsciiCharacterSetId::CratesAlienFont)!="Alien Glyphs")return fail("human-readable character set names");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::S1Detailed).size()!=92)return fail("detailed ramp");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::S1Blocks).size()!=5)return fail("blocks character set");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::S1Quadrants).size()!=16)return fail("quadrant character set");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::S1BoxDrawing).size()!=6)return fail("box drawing character set");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::AsciiArtMainSimple).size()!=5)return fail("ASCII simple ramp");
 const auto* gb=xao::s1Palette(xao::S1PaletteId::GameBoyDMG);if(!gb||gb->count!=4||gb->colors[0].r!=0x0F||gb->colors[3].b!=0x81)return fail("palette data");
 xao::AsciiParams palette;p.colorize=false;palette.paletteIndex=(std::uint8_t)xao::S1PaletteId::GameBoyDMG;palette.paletteStrength=100;
 xao::Image paletteOut(64,48);xao::AsciiEngine paletteEngine(palette);paletteEngine.render(src,paletteOut,{});bool chroma=false;for(const auto&q:paletteOut.pixels())chroma|=std::fabs(q.r-q.g)>0.02f||std::fabs(q.g-q.b)>0.02f;if(!chroma)return fail("palette mapping changes output color");
 xao::AsciiParams random=p;random.randomCharacters=true;random.randomAmount=0.9f;random.randomTiming=true;random.randomSpeed=1.0f;xao::AsciiEngine randomEngine(random);xao::Image r0(64,48),r1(64,48),r2(64,48);xao::RenderContext c0,c1,c2;c0.timeSeconds=0;c1.timeSeconds=0;c2.timeSeconds=1;randomEngine.render(src,r0,c0);randomEngine.render(src,r1,c1);randomEngine.render(src,r2,c2);if(differs(r0,r1))return fail("random output deterministic at same time");if(!differs(r0,r2))return fail("random glyphs animate over time");
 xao::AsciiParams threshold;threshold.visualStyle=xao::AsciiVisualStyle::Threshold;threshold.thresholdLevel=0.12f;threshold.thresholdSegmentWidth=24;threshold.thresholdRowSpacing=6;xao::Image mid(64,48),thresholdOut(64,48);for(auto&q:mid.pixels())q={0.24f,0.24f,0.24f,1};xao::AsciiEngine thresholdEngine(threshold);thresholdEngine.render(mid,thresholdOut,{});bool thresholdVisible=false;for(const auto&q:thresholdOut.pixels())thresholdVisible|=q.a>0.15f;if(!thresholdVisible)return fail("threshold preserves dark and midtone detail");
 for(int style=1;style<=11;++style){xao::AsciiParams styled;styled.visualStyle=(xao::AsciiVisualStyle)style;styled.randomSeed=19;xao::Image out(64,48);xao::AsciiEngine styledEngine(styled);styledEngine.render(src,out,{});for(const auto&q:out.pixels())if(!std::isfinite(q.r)||!std::isfinite(q.g)||!std::isfinite(q.b)||!std::isfinite(q.a))return fail("ASCII look outputs finite values");}
 auto wordAtlas=std::make_shared<xao::GlyphAtlas>();xao::GlyphBitmap word;word.wordToken=true;word.width=32;word.height=8;word.coverage.assign(256,255);word.density=1;wordAtlas->glyphs.push_back(word);
 xao::AsciiParams wordParams;wordParams.randomWords=true;wordParams.randomCharacters=false;wordParams.colorize=false;wordParams.cellSize=8;wordParams.atlas=wordAtlas;xao::Image wordSrc(64,8),wordOut(64,8);for(auto&q:wordSrc.pixels())q={0,0,0,1};xao::AsciiEngine wordEngine(wordParams);wordEngine.render(wordSrc,wordOut,{});int wordInk=0;for(const auto&q:wordOut.pixels())if(q.a>0.5f)++wordInk;if(wordInk<=64)return fail("word tokens span multiple cells");
 std::cout<<"XAO ASCII engine tests passed\n";return 0;
}
