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
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::AsciiArtMainStandard).size()!=10)return fail("ASCII Art main standard ramp");
 if(xao::asciiCharacterSetCodepoints(xao::AsciiCharacterSetId::AsciiArtMainDetailed).size()!=70)return fail("ASCII Art main detailed ramp");
 const auto* gb=xao::s1Palette(xao::S1PaletteId::GameBoyDMG);if(!gb||gb->count!=4||gb->colors[0].r!=0x0F||gb->colors[3].b!=0x81)return fail("S1 palette byte recovery");
 // A word-only atlas must remain usable independently of the global Random Words toggle.
 xao::AsciiParams wordOnly;wordOnly.colorize=false;wordOnly.randomWords=true;wordOnly.randomCharacters=false;
 auto wordAtlas=std::make_shared<xao::GlyphAtlas>();xao::GlyphBitmap wordGlyph;wordGlyph.wordToken=true;wordGlyph.width=8;wordGlyph.height=8;wordGlyph.coverage.assign(64,255);wordGlyph.density=1.0f;wordAtlas->glyphs.push_back(wordGlyph);wordOnly.atlas=wordAtlas;
 xao::Image wordSource(8,8),wordOutput(8,8);for(auto& px:wordSource.pixels())px={0,0,0,1};xao::AsciiEngine wordEngine(wordOnly);wordEngine.render(wordSource,wordOutput,{});
 bool wordVisible=false;for(const auto& px:wordOutput.pixels())wordVisible|=px.a>0.5f;if(!wordVisible)return fail("word tokens remain renderable when Random Words is enabled");
 // Source-channel mapping must change glyph tone independently from output color.
 xao::Image channelSource(8,8),redMapped(8,8),blueMapped(8,8);for(auto& px:channelSource.pixels())px={1,0,0,1};
 xao::AsciiParams redMode;redMode.colorize=false;redMode.channelMode=xao::AsciiChannelMode::Red;
 xao::AsciiParams blueMode=redMode;blueMode.channelMode=xao::AsciiChannelMode::Blue;
 xao::AsciiEngine redEngine(redMode),blueEngine(blueMode);redEngine.render(channelSource,redMapped,{});blueEngine.render(channelSource,blueMapped,{});
 bool channelDiff=false;for(std::size_t i=0;i<redMapped.pixels().size();++i)channelDiff|=!near(redMapped.pixels()[i].a,blueMapped.pixels()[i].a);if(!channelDiff)return fail("RGB channel mode changes glyph mapping");
 // Edge-directional mode resolves a horizontal luminance gradient to a horizontal glyph.
 xao::AsciiParams edgeMode;edgeMode.colorize=false;edgeMode.mappingMode=xao::AsciiMappingMode::EdgeDirectional;auto edgeAtlas=std::make_shared<xao::GlyphAtlas>();
 xao::GlyphBitmap horizontal;horizontal.codepoint=U'-';horizontal.width=8;horizontal.height=8;horizontal.coverage.assign(64,0);for(int x=0;x<8;++x)horizontal.coverage[3*8+x]=255;horizontal.density=0.125f;edgeAtlas->glyphs.push_back(horizontal);edgeMode.atlas=edgeAtlas;
 xao::Image edgeSource(8,8),edgeOutput(8,8);for(int y=0;y<8;++y)for(int x=0;x<8;++x){float v=(float)x/7.0f;edgeSource.at(x,y)={v,v,v,1};}
 xao::AsciiEngine edgeEngine(edgeMode);edgeEngine.render(edgeSource,edgeOutput,{});
 int horizontalInk=0;for(int x=0;x<8;++x)if(edgeOutput.at(x,3).a>0.5f)++horizontalInk;if(horizontalInk<3)return fail("edge-directional horizontal glyph selection");
 // Selective glyph glow is deterministic and adds a blurred emission layer.
 xao::AsciiParams glowParams;glowParams.colorize=false;glowParams.glowEnabled=true;glowParams.glowSelection=xao::AsciiGlowSelection::All;glowParams.glowRadius=2;glowParams.glowIntensity=2;
 xao::Image glowSource(8,8),glowA(8,8),glowB(8,8);for(auto& px:glowSource.pixels())px={0.2f,0.2f,0.2f,1};
 xao::AsciiEngine glowEngine(glowParams);glowEngine.render(glowSource,glowA,{});glowEngine.render(glowSource,glowB,{});
 for(std::size_t i=0;i<glowA.pixels().size();++i)if(!near(glowA.pixels()[i].r,glowB.pixels()[i].r)||!near(glowA.pixels()[i].a,glowB.pixels()[i].a))return fail("glow deterministic at same time");
 xao::AsciiParams noGlow=glowParams;noGlow.glowEnabled=false;xao::Image noGlowOut(8,8);xao::AsciiEngine noGlowEngine(noGlow);noGlowEngine.render(glowSource,noGlowOut,{});bool glowVisible=false;for(std::size_t i=0;i<glowA.pixels().size();++i)glowVisible|=!near(glowA.pixels()[i].r,noGlowOut.pixels()[i].r);if(!glowVisible)return fail("selective glow emission pass");
 // Radial rays are deterministic and render independently of glyph glow.
 xao::AsciiParams rayParams;rayParams.colorize=false;rayParams.raysEnabled=true;rayParams.raysCount=8;rayParams.raysSpread=360;rayParams.raysIntensity=5;rayParams.raysLength=1;rayParams.raysSharpness=1;
 xao::Image raySource(8,8),rayA(8,8),rayB(8,8);for(auto& px:raySource.pixels())px={0,0,0,0};
 xao::AsciiEngine rayEngine(rayParams);rayEngine.render(raySource,rayA,{});rayEngine.render(raySource,rayB,{});
 bool raysVisible=false;for(std::size_t i=0;i<rayA.pixels().size();++i){raysVisible|=rayA.pixels()[i].r>0.01f;if(!near(rayA.pixels()[i].r,rayB.pixels()[i].r))return fail("radial rays deterministic");}
 if(!raysVisible)return fail("radial ray pass renders visible beams");
 // Liquid layout uses deterministic variable-width and variable-height panels.
 xao::AsciiParams liquidParams;liquidParams.colorize=false;liquidParams.layoutMode=xao::AsciiLayoutMode::LiquidPanels;liquidParams.cellSize=4;liquidParams.panelMinWidth=1;liquidParams.panelMaxWidth=3;liquidParams.panelMinHeight=1;liquidParams.panelMaxHeight=3;liquidParams.randomSeed=1234;liquidParams.randomCharacters=true;
 xao::Image liquidSource(32,24),liquidA(32,24),liquidB(32,24);for(int y=0;y<24;++y)for(int x=0;x<32;++x){float v=(float)(x+y)/55.0f;liquidSource.at(x,y)={v,v,v,1};}
 xao::AsciiEngine liquidEngine(liquidParams);liquidEngine.render(liquidSource,liquidA,{});liquidEngine.render(liquidSource,liquidB,{});
 bool liquidVisible=false;for(std::size_t i=0;i<liquidA.pixels().size();++i){liquidVisible|=liquidA.pixels()[i].a>0.1f;if(!near(liquidA.pixels()[i].r,liquidB.pixels()[i].r)||!near(liquidA.pixels()[i].a,liquidB.pixels()[i].a))return fail("liquid panels deterministic");}
 if(!liquidVisible)return fail("liquid panel layout renders output");
 xao::AsciiParams preset;xao::applyCratesPreset(preset,xao::AsciiPresetId::Matrix);if(preset.characterSet!=xao::AsciiCharacterSetId::CratesBinary||!preset.randomCharacters)return fail("preset application");
 xao::AsciiParams rp=p;rp.randomCharacters=true;rp.randomAmount=0.8f;rp.randomTiming=true;rp.randomSpeed=1.0f;xao::AsciiEngine re(rp);xao::Image r0(32,16),r1(32,16),r2(32,16);xao::RenderContext c0;c0.timeSeconds=0; xao::RenderContext c1;c1.timeSeconds=0;xao::RenderContext c2;c2.timeSeconds=1;re.render(src,r0,c0);re.render(src,r1,c1);re.render(src,r2,c2);bool stable=true,animated=false;for(std::size_t i=0;i<r0.pixels().size();++i){stable&=near(r0.pixels()[i].r,r1.pixels()[i].r)&&near(r0.pixels()[i].a,r1.pixels()[i].a);animated|=!near(r0.pixels()[i].r,r2.pixels()[i].r)||!near(r0.pixels()[i].a,r2.pixels()[i].a);}if(!stable)return fail("random deterministic at same time");if(!animated)return fail("random timing advances");
 xao::AsciiParams thresholdParams;thresholdParams.visualStyle=xao::AsciiVisualStyle::Threshold;thresholdParams.thresholdLevel=0.1f;thresholdParams.thresholdSegmentWidth=12;thresholdParams.thresholdRowSpacing=4;
 xao::Image thresholdSource(24,16),thresholdOut(24,16);for(auto& px:thresholdSource.pixels())px={1,1,1,1};xao::AsciiEngine thresholdEngine(thresholdParams);thresholdEngine.render(thresholdSource,thresholdOut,{});
 int thresholdPixels=0;for(const auto& px:thresholdOut.pixels())if(px.a>0.5f)++thresholdPixels;if(thresholdPixels<=0||thresholdPixels>=24*16)return fail("threshold look emits separated horizontal segments");
 xao::AsciiParams rainbowParams;rainbowParams.visualStyle=xao::AsciiVisualStyle::Rainbow;rainbowParams.colorize=false;xao::Image rainbowSource(16,8),rainbowOut(16,8);for(auto& px:rainbowSource.pixels())px={0.5f,0.5f,0.5f,1};xao::AsciiEngine rainbowEngine(rainbowParams);rainbowEngine.render(rainbowSource,rainbowOut,{});
 bool rainbowColor=false;for(const auto& px:rainbowOut.pixels())rainbowColor|=std::fabs(px.r-px.g)>0.03f||std::fabs(px.g-px.b)>0.03f;if(!rainbowColor)return fail("rainbow look produces chromatic glyphs");
 std::cout<<"XAO ASCII engine tests passed\n";return 0;
}
