#include "xao/AsciiEngine.h"
#include "xao/AsciiRampLibrary.h"
#include "../../XAO/ascii [ main ]/ascii ofx [open source]/font8x8_basic.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <stdexcept>
namespace xao {
namespace {
constexpr CratesPresetDefinition kPresets[] = {
 {AsciiPresetId::Default,"Default",0,35,0,0,true,false,false,false,0,{0.9921568632f,0.9882352948f,0.9882352948f,1},0.50f,0,0,5,10,0,0},
 {AsciiPresetId::AlienSignal,"Alien Signal",13,70,0,0,true,false,false,false,100,{0.8705882430f,1,0,1},0.50f,0,0,5,10,25,50},
 {AsciiPresetId::CirclesAndDots,"Circles and Dots",7,25,100,15,true,false,false,true,0,{1,1,1,1},0.50f,0,0,15,10,0,0},
 {AsciiPresetId::Classic,"Classic",1,25,8,0,true,false,false,false,100,{0.9921568632f,0.9882352948f,0.9882352948f,1},0.50f,0,0,5,10,0,0},
 {AsciiPresetId::Corrupted,"Corrupted",1,50,0,0,true,true,false,false,0,{1,1,1,1},0.25f,0,200,15,25,25,50},
 {AsciiPresetId::Crossword,"Crossword",2,50,13,0,true,true,false,false,100,{0.9921568632f,0.9882352948f,0.9882352948f,1},0,50,0,0,10,0,0},
 {AsciiPresetId::Diamonds,"Diamond",9,35,120,0,true,false,false,true,0,{1,1,1,1},0.50f,5,0,15,10,0,0},
 {AsciiPresetId::Matrix,"Matrix",4,25,0,0,true,false,false,false,100,{0,1,0.2352941185f,1},0.50f,0,0,30,50,0,0},
 {AsciiPresetId::Motherboard,"Motherboard",11,65,0,0,true,false,false,false,0,{0.9921568632f,0.9882352948f,0.9882352948f,1},0,0,0,25,100,15,50},
 {AsciiPresetId::PinkShapes,"Pink Shapes",5,35,95,0,true,false,false,true,100,{1,0.4156862795f,0.7333333492f,1},0.50f,0,0,15,10,0,0}
};
constexpr char32_t k0[]=U"@#%&$ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnpqrstuvwxyz";
constexpr char32_t k1[]=U"@#%&$0123456789";
constexpr char32_t k2[]=U"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,:;!?+-*/=()[]{}<>_";
constexpr char32_t k3[]=U"アイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワン";
constexpr char32_t k4[]=U"01";
constexpr char32_t k5[]=U" .:-=+*#%@";
constexpr char32_t k6[]=U"Xx";
constexpr char32_t k7[]=U"oO0@";
constexpr char32_t k8[]=U".*+";
constexpr char32_t k9[]=U"<>^v";
constexpr char32_t k10[]=U".:;,+";
constexpr char32_t k11[]=U"[]{}<>+-|_/";
constexpr char32_t k12[]=U"[]{}<>+-|_=:/\\";
constexpr char32_t k13[]=U"0123456789ABCDEF";
constexpr char32_t k14[]=U"|/\\-_=.";
constexpr char32_t kS1AtlasChars[]=U" \u0060.-':_,^=;><+!rc*/z?sLTv)J7(|Fi{C}fI31tlu[neoZ5Yxjya]2ESwqkP6h9d4VpOGbUAKXHm8RD#$Bg0MNWQ%&@";
constexpr char32_t kS1Blocks[]=U" \u2591\u2592\u2593\u2588";
constexpr char32_t kS1Quadrants[]=U" \u2580\u2584\u258C\u2590\u2588\u2596\u2597\u2598\u2599\u259A\u259B\u259C\u259D\u259E\u259F";
constexpr char32_t kS1BoxDrawing[]=U" \u2504\u2500\u253C\u254B\u2588";
constexpr char32_t kAsciiArtMainStandard[]=U"@%#*+=-:. ";
constexpr char32_t kAsciiArtMainSimple[]=U"@#+. ";
constexpr char32_t kAsciiArtMainDetailed[]=U"$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^\x60'. ";
constexpr char32_t kEmpty[]=U"";
float clamp01(float v) noexcept{return std::max(0.0f,std::min(1.0f,v));}
float clampf(float v,float lo,float hi) noexcept{return std::max(lo,std::min(hi,v));}
std::uint32_t hash32(std::uint32_t x) noexcept{x^=x>>16;x*=0x7feb352du;x^=x>>15;x*=0x846ca68bu;x^=x>>16;return x;}
float sampleChannel(const Pixel& p,AsciiChannelMode mode) noexcept{
 if(p.a<=1e-8f)return 0.0f;
 const float r=clamp01(p.r/p.a),g=clamp01(p.g/p.a),b=clamp01(p.b/p.a);
 switch(mode){case AsciiChannelMode::Red:return r;case AsciiChannelMode::Green:return g;case AsciiChannelMode::Blue:return b;default:return clamp01(.2126f*r+.7152f*g+.0722f*b);}
}
float srgbToLinear(float v) noexcept{return v<=.04045f?v/12.92f:std::pow((v+.055f)/1.055f,2.4f);}
float maskAt(const GlyphBitmap& g,float u,float v,bool aa) noexcept{
 if(g.width<=0||g.height<=0||g.coverage.size()<(std::size_t)(g.width*g.height))return 0;
 u=clamp01(u);v=clamp01(v);float fx=u*(g.width-1),fy=v*(g.height-1);
 if(!aa){int x=std::clamp((int)std::lround(fx),0,g.width-1),y=std::clamp((int)std::lround(fy),0,g.height-1);return g.coverage[(std::size_t)y*g.width+x]/255.0f;}
 int x0=(int)fx,y0=(int)fy,x1=std::min(g.width-1,x0+1),y1=std::min(g.height-1,y0+1);float tx=fx-x0,ty=fy-y0;
 auto at=[&](int x,int y){return g.coverage[(std::size_t)y*g.width+x]/255.0f;};
 float a=at(x0,y0)*(1-tx)+at(x1,y0)*tx,b=at(x0,y1)*(1-tx)+at(x1,y1)*tx;return a*(1-ty)+b*ty;
}
std::shared_ptr<const GlyphAtlas> makeBuiltin(){
 auto a=std::make_shared<GlyphAtlas>();a->glyphs.reserve(95);
 for(int c=32;c<=126;++c){GlyphBitmap g;g.codepoint=(char32_t)c;g.width=8;g.height=8;g.coverage.resize(64);int ink=0;
  for(int y=0;y<8;++y)for(int x=0;x<8;++x){bool on=((font8x8_basic[c][y]>>x)&1u)!=0;g.coverage[(std::size_t)y*8+x]=on?255:0;ink+=on?1:0;}
  g.density=(float)ink/64.0f;g.numberToken=(c>='0'&&c<='9');a->glyphs.push_back(std::move(g));}
 return a;
}
const GlyphBitmap* selectGlyph(const std::vector<const GlyphBitmap*>& candidates,const std::array<float,64>& target,bool shape,float amount,std::uint32_t random) noexcept{
 if(candidates.empty())return nullptr;
 float mean=0.0f;for(float v:target)mean+=v;mean/=64.0f;
 auto it=std::lower_bound(candidates.begin(),candidates.end(),mean,[](const GlyphBitmap* g,float value){return g->density<value;});
 std::size_t center=it==candidates.end()?candidates.size()-1:(std::size_t)(it-candidates.begin());
 if(center>0&&std::fabs(candidates[center-1]->density-mean)<std::fabs(candidates[center]->density-mean))--center;
 const std::size_t pool=std::min(candidates.size(),(std::size_t)(1+std::lround(clamp01(amount)*15.0f)));
 if(!shape){std::size_t start=center>pool/2?center-pool/2:0;if(start+pool>candidates.size())start=candidates.size()-pool;return candidates[start+(std::size_t)random%pool];}
 struct Score{const GlyphBitmap* glyph=nullptr;float value=0.0f;};
 std::array<Score,16> best{};std::size_t count=0;const std::size_t shortlist=std::min<std::size_t>(candidates.size(),best.size());
 std::size_t start=center>shortlist/2?center-shortlist/2:0;if(start+shortlist>candidates.size())start=candidates.size()-shortlist;
 for(std::size_t i=0;i<shortlist;++i){const auto* g=candidates[start+i];float score=0.0f;for(int y=0;y<8;++y)for(int x=0;x<8;++x){float m=maskAt(*g,(x+.5f)/8.0f,(y+.5f)/8.0f,false);float q=target[(std::size_t)y*8+x]-m;score+=q*q;}std::size_t pos=count;while(pos>0&&best[pos-1].value>score){best[pos]=best[pos-1];--pos;}best[pos]={g,score};++count;}
 const std::size_t choose=std::min(count,pool);return best[(std::size_t)random%choose].glyph;
}
Pixel scaled(Pixel p,float k) noexcept{p.r*=k;p.g*=k;p.b*=k;p.a*=k;return p;}


}
const CratesPresetDefinition& cratesPreset(AsciiPresetId id) noexcept{auto i=(std::size_t)id;return kPresets[i<sizeof(kPresets)/sizeof(kPresets[0])?i:0];}
std::string_view asciiCharacterSetName(AsciiCharacterSetId id) noexcept{
 static constexpr std::array<std::string_view,27> names{{"Fantasy Marks","Vampire Numerals","Typewriter","Neo Tokyo","Binary Code","Punk Minimal","Cross Marks","Bubble Forms","Starfield","Diamond Signs","Dot Matrix","Circuit Lines I","Circuit Lines II","Alien Glyphs","Signal Bars","Classic Ramp","Minimal Ramp","Detailed Ramp","Bourke Ramp","Braille","Katakana","Block Mosaic","Quadrants","Box Drawing","ASCII Standard","ASCII Simple","ASCII Detailed"}};
 auto i=(std::size_t)id;return i<names.size()?names[i]:names[0];
}
std::u32string_view asciiCharacterSetCodepoints(AsciiCharacterSetId id) noexcept{
 switch(id){
 case AsciiCharacterSetId::CratesSpecialLetters:return k0;case AsciiCharacterSetId::CratesSpecialNumbers:return k1;case AsciiCharacterSetId::CratesTypewriter:return k2;case AsciiCharacterSetId::CratesJapanese:return k3;case AsciiCharacterSetId::CratesBinary:return k4;case AsciiCharacterSetId::CratesMinimalPunk:return k5;case AsciiCharacterSetId::CratesXs:return k6;case AsciiCharacterSetId::CratesBubbleGrowth:return k7;case AsciiCharacterSetId::CratesStars:return k8;case AsciiCharacterSetId::CratesDiamonds:return k9;case AsciiCharacterSetId::CratesDots:return k10;case AsciiCharacterSetId::CratesCircuits1:return k11;case AsciiCharacterSetId::CratesCircuits2:return k12;case AsciiCharacterSetId::CratesAlienFont:return k13;case AsciiCharacterSetId::CratesBars:return k14;case AsciiCharacterSetId::S1Classic:return kS1AtlasChars;case AsciiCharacterSetId::S1Minimal:return kS1AtlasChars;case AsciiCharacterSetId::S1Detailed:return kS1AtlasChars;case AsciiCharacterSetId::S1Bourke:return kS1AtlasChars;case AsciiCharacterSetId::S1Blocks:return kS1Blocks;case AsciiCharacterSetId::S1Quadrants:return kS1Quadrants;case AsciiCharacterSetId::S1BoxDrawing:return kS1BoxDrawing;case AsciiCharacterSetId::AsciiArtMainStandard:return kAsciiArtMainStandard;case AsciiCharacterSetId::AsciiArtMainSimple:return kAsciiArtMainSimple;case AsciiCharacterSetId::AsciiArtMainDetailed:return kAsciiArtMainDetailed;default:return kEmpty;
 }
}
std::shared_ptr<const GlyphAtlas> builtinAsciiGlyphAtlas(){static const auto a=makeBuiltin();return a;}
void applyCratesPreset(AsciiParams& p,AsciiPresetId id) noexcept{
 const auto& v=cratesPreset(id);p.preset=id;p.presetCharacterSize=v.characterSize;p.characterMargin=v.characterMargin;p.cellMargin=v.cellMargin;p.antiAliasing=v.antiAliasing;p.invert=v.invert;p.reverseOrder=v.reverseOrder;p.uniformLuma=v.uniformLuma;p.paper={0,0,0,1};p.tintStrength=v.tintStrength;p.tintColor=v.tintColor;p.invertThreshold=v.invertThreshold;p.smoothShading=v.smoothShading;p.blendWithOriginal=v.blendWithOriginal;p.randomAmount=v.randomShuffle/100.0f;p.randomSpeed=v.randomSpeed/100.0f;p.randomColorAmount=v.randomColorAmount/100.0f;p.xFlipThreshold=v.xFlipThreshold/100.0f;p.randomCharacters=v.randomShuffle>0;p.randomTiming=v.randomSpeed>0;p.characterSet=(AsciiCharacterSetId)std::min<std::uint8_t>(v.cratesCharacterSet,14);
}
void AsciiEngine::render(const Image& src,Image& dst,const RenderContext& ctx) const{
 if(src.width()!=dst.width()||src.height()!=dst.height())throw std::invalid_argument("ASCII dimensions must match");
 if(src.empty())return;
 int w=src.width(),h=src.height(),cell=std::max(2,std::min(512,params_.cellSize));
 if(params_.visualStyle==AsciiVisualStyle::Micro)cell=std::max(2,cell/2);
 float contrast=clampf(params_.contrast*(params_.asciiStrength/100.0f),0,4),brightness=clampf(params_.brightness,-1,1);
 float glyphScale=clampf(params_.useClipScale?params_.glyphScale:0.88f,.05f,3.0f)*clampf(params_.presetCharacterSize/100.0f,.1f,3.0f);
 if(params_.visualStyle==AsciiVisualStyle::Micro)glyphScale*=0.68f;
 if(params_.visualStyle==AsciiVisualStyle::Photorealistic)glyphScale*=0.92f;
 float charMargin=clampf(params_.characterMargin/200.0f,0,.45f),cellMargin=clampf(params_.cellMargin/200.0f,0,.45f);

 auto atlas=params_.atlas?params_.atlas:builtinAsciiGlyphAtlas();std::vector<const GlyphBitmap*> candidates;
 auto set=asciiCharacterSetCodepoints(params_.characterSet);
 const bool includeWords=params_.randomWords||params_.ancientWords||params_.englishWords||params_.arabicWords;
 auto inSelectedSet=[&](char32_t cp){switch(params_.characterSet){case AsciiCharacterSetId::S1Braille:return cp>=0x2800&&cp<=0x28FF;case AsciiCharacterSetId::S1Katakana:return cp>=0x30A1&&cp<=0x30F6;default:return !set.empty()&&set.find(cp)!=std::u32string_view::npos;}};
 for(const auto& g:atlas->glyphs){if(g.wordToken&&!includeWords)continue;if(!g.familyToken&&!g.wordToken&&g.codepoint&&!inSelectedSet(g.codepoint))continue;candidates.push_back(&g);}
 int rampLimit=0;if(params_.characterSet==AsciiCharacterSetId::S1Classic)rampLimit=10;else if(params_.characterSet==AsciiCharacterSetId::S1Minimal)rampLimit=6;else if(params_.characterSet==AsciiCharacterSetId::S1Bourke)rampLimit=28;
 if(rampLimit>0){std::vector<const GlyphBitmap*> base;for(auto* g:candidates)if(!g->familyToken&&!g->wordToken)base.push_back(g);std::sort(base.begin(),base.end(),[](const GlyphBitmap* a,const GlyphBitmap* b){return a->density<b->density;});if((int)base.size()>rampLimit){base.resize((std::size_t)rampLimit);candidates.erase(std::remove_if(candidates.begin(),candidates.end(),[&](const GlyphBitmap* g){return !g->familyToken&&!g->wordToken&&std::find(base.begin(),base.end(),g)==base.end();}),candidates.end());}}
 if(candidates.empty()){dst=src;return;}
 std::sort(candidates.begin(),candidates.end(),[](const GlyphBitmap* a,const GlyphBitmap* b){return a->density<b->density;});
 for(int y0=0,rowIndex=0;y0<h;++rowIndex){
  int rowHeight=cell;
  if(params_.visualStyle==AsciiVisualStyle::Organic){const std::uint32_t organic=hash32(params_.randomSeed^(std::uint32_t)rowIndex*0xA511E9B3u);rowHeight=std::max(2,(int)std::lround(cell*(0.82f+0.36f*(float)organic/(float)0xFFFFFFFFu)));}
  if(params_.layoutMode==AsciiLayoutMode::LiquidPanels||params_.visualStyle==AsciiVisualStyle::Liquid){
   const int minH=std::clamp(std::min(params_.panelMinHeight,params_.panelMaxHeight),1,8),maxH=std::clamp(std::max(params_.panelMinHeight,params_.panelMaxHeight),1,8);
   rowHeight=cell*(minH+(int)(hash32(params_.randomSeed^(std::uint32_t)rowIndex*0x9E3779B9u)%(std::uint32_t)(maxH-minH+1)));
  }
  const int y1=std::min(h,y0+rowHeight);
  for(int x0=0,colIndex=0;x0<w;++colIndex){
   int colWidth=cell;
   if(params_.visualStyle==AsciiVisualStyle::Organic){const std::uint32_t organic=hash32(params_.randomSeed^(std::uint32_t)rowIndex*0x85EBCA6Bu^(std::uint32_t)colIndex*0xC2B2AE35u);colWidth=std::max(2,(int)std::lround(cell*(0.78f+0.44f*(float)organic/(float)0xFFFFFFFFu)));}
   if(params_.layoutMode==AsciiLayoutMode::LiquidPanels||params_.visualStyle==AsciiVisualStyle::Liquid){
    const int minW=std::clamp(std::min(params_.panelMinWidth,params_.panelMaxWidth),1,8),maxW=std::clamp(std::max(params_.panelMinWidth,params_.panelMaxWidth),1,8);
    const std::uint32_t panelSeed=params_.randomSeed^((std::uint32_t)rowIndex*0x85EBCA6Bu)^((std::uint32_t)colIndex*0xC2B2AE35u);
    colWidth=cell*(minW+(int)(hash32(panelSeed)%(std::uint32_t)(maxW-minW+1)));
   }
   const int x1=std::min(w,x0+colWidth);
   std::array<float,64> target{};Pixel avg{0,0,0,0};double alphaSum=0;int n=0;
  for(int sy=0;sy<8;++sy)for(int sx=0;sx<8;++sx){int px=std::min(x1-1,x0+(int)((sx+.5f)*(x1-x0)/8.0f)),py=std::min(y1-1,y0+(int)((sy+.5f)*(y1-y0)/8.0f));const Pixel& p=src.row(py)[px];float a=clamp01(p.a);target[(std::size_t)sy*8+sx]=clamp01((1-sampleChannel(p,params_.channelMode))*a);avg.r+=p.r;avg.g+=p.g;avg.b+=p.b;avg.a+=p.a;alphaSum+=a;++n;}
  float inv=1.0f/n;avg.r*=inv;avg.g*=inv;avg.b*=inv;avg.a*=inv;float mean=0;for(float v:target)mean+=v;mean/=64;
  if(params_.uniformLuma)for(float& v:target)v=mean;
  if(params_.reverseOrder)for(float& v:target)v=1-v;
  if(params_.invert)for(float& v:target)if(v>=clamp01(params_.invertThreshold<=1.0f?params_.invertThreshold:params_.invertThreshold/100.0f))v=1-v;
  const float gamma=clampf(params_.gamma,0.1f,4.0f);
  for(float& v:target){v=std::pow(clamp01(applyAsciiToneMap(v,contrast,brightness)),1.0f/gamma);if(params_.smoothShading>0){float sm=v*v*(3-2*v);v=v*(1-clamp01(params_.smoothShading/100.0f))+sm*clamp01(params_.smoothShading/100.0f);}}
  std::uint32_t ci=hash32(params_.randomSeed^((std::uint32_t)rowIndex*0x9E3779B9u)^((std::uint32_t)colIndex*0x85EBCA6Bu));double time=std::max(0.0,ctx.timeSeconds);
  bool animate=params_.randomCharacters||params_.randomWords;
  double cellSpeed=1.0+clampf(params_.randomSpeed,0,10)*24.0;
  if(params_.randomTiming){
   const float jitter=hash32(params_.randomSeed^ci^0x71A1u)/(float)0xFFFFFFFFu;
   const float variation=clampf(params_.randomTimingVariation/10.0f,0,1);
   cellSpeed*=1.0+(jitter*2.0f-1.0f)*variation*0.75f;
  }
  std::uint32_t slot=animate?(std::uint32_t)std::floor(time*cellSpeed):0u;
  std::uint32_t rv=hash32(params_.randomSeed^hash32(ci+0x9e3779b9u)^hash32(slot));
  const bool shapeMatch=params_.mappingMode==AsciiMappingMode::ShapeMatch;
  const GlyphBitmap* glyph=nullptr;
  if(params_.mappingMode==AsciiMappingMode::EdgeDirectional){
   float gx=0.0f,gy=0.0f;
   for(int sy=1;sy<7;++sy)for(int sx=1;sx<7;++sx){gx+=target[(std::size_t)sy*8+(sx+1)]-target[(std::size_t)sy*8+(sx-1)];gy+=target[(std::size_t)(sy+1)*8+sx]-target[(std::size_t)(sy-1)*8+sx];}
   const float edgeStrength=clamp01(std::sqrt(gx*gx+gy*gy)/36.0f);
   if(edgeStrength>=clamp01(params_.edgeThreshold)){
    char32_t direction;
    if(std::fabs(gx)>1.5f*std::fabs(gy))direction=U'-';
    else if(std::fabs(gy)>1.5f*std::fabs(gx))direction=U'|';
    else direction=(gx*gy>=0.0f)?U'\\':U'/';
    for(const auto* candidate:candidates)if(candidate->codepoint==direction){glyph=candidate;break;}
   }
  }
  if(!glyph)glyph=selectGlyph(candidates,target,shapeMatch,(params_.randomCharacters||params_.randomWords)?params_.randomAmount:0,rv);
  if(params_.visualStyle==AsciiVisualStyle::Geometric){for(const auto* candidate:candidates){const char32_t cp=candidate->codepoint;if(cp==43||cp==42||cp==47||cp==92||cp==124||cp==60||cp==62||cp==94||cp==118||cp==91||cp==93||cp==123||cp==125||cp==40||cp==41||cp==35||cp==61||cp==45||cp==95||cp==46){glyph=candidate;break;}}}
  if(!glyph)continue;
  float cw=(float)(x1-x0),ch=(float)(y1-y0),aw=cw*(1-cellMargin),ah=ch*(1-cellMargin);
  float tokenScale=clampf(glyph->sizeScale,0.1f,3.0f);
  if(glyph->wordToken&&params_.useWordSize)tokenScale*=clampf(params_.wordSize/100.0f,0.1f,4.0f);
  else if(glyph->numberToken&&params_.useNumberSize)tokenScale*=clampf(params_.numberSize/100.0f,0.1f,4.0f);
  else if(!glyph->wordToken&&!glyph->numberToken&&params_.useCharacterSize)tokenScale*=clampf(params_.characterSize/100.0f,0.1f,4.0f);
  float dw=std::max(1.0f,aw*glyphScale*tokenScale*(1-charMargin)),dh=std::max(1.0f,ah*glyphScale*tokenScale*(1-charMargin));
  const float glyphAspect=(glyph->height>0)?(float)glyph->width/(float)glyph->height:1.0f;
  const float cellAspect=aw/std::max(1.0f,ah);
  if(glyphAspect>cellAspect)dh=dw/glyphAspect;else dw=dh*glyphAspect;
  if(params_.visualStyle==AsciiVisualStyle::Organic){const float organic=0.82f+0.36f*(float)hash32(rv^0x0A6A91C3u)/(float)0xFFFFFFFFu;dw*=organic;dh*=organic;}
  int drawX1=x1;float left=(x0+x1-dw)*.5f;
  if(params_.visualStyle==AsciiVisualStyle::Organic)left+=(float)((int)(rv%5)-2)*0.06f*cw;
  if(params_.visualStyle==AsciiVisualStyle::Glitch)left+=(float)((int)((rv>>8)%7)-3)*0.08f*cw;
  if(glyph->wordToken){dh=std::max(1.0f,ah*glyphScale*tokenScale*(1-charMargin));dw=std::max(cw,dh*glyphAspect);dw=std::min(dw,(float)(w-x0));drawX1=std::min(w,std::max(x1,x0+(int)std::ceil(dw)));left=(float)x0+charMargin*cw;}
  float top=(y0+y1-dh)*.5f,alpha=params_.preserveCellAlpha?clamp01((float)(alphaSum/n)):1.0f;
  bool flipX=(glyph->codepoint==U'X'||glyph->codepoint==U'x')&&mean>=clamp01(params_.xFlipThreshold);
  if(glyph->wordToken&&drawX1>x1){Pixel wa{0,0,0,0};int wn=0;for(int yy=y0;yy<y1;++yy)for(int xx=x0;xx<drawX1;++xx){const Pixel& q=src.row(yy)[xx];wa.r+=q.r;wa.g+=q.g;wa.b+=q.b;wa.a+=q.a;++wn;}if(wn){float wi=1.0f/(float)wn;avg={wa.r*wi,wa.g*wi,wa.b*wi,wa.a*wi};}}
  if(params_.visualStyle==AsciiVisualStyle::Photorealistic){const Pixel& center=src.at((x0+x1)/2,(y0+y1)/2);const float m=0.16f;avg.r=avg.r*(1-m)+center.r*m;avg.g=avg.g*(1-m)+center.g*m;avg.b=avg.b*(1-m)+center.b*m;}
  Pixel fg=(params_.colorize||params_.visualStyle==AsciiVisualStyle::Ghost)?avg:params_.ink;if((params_.colorize||params_.visualStyle==AsciiVisualStyle::Ghost)&&fg.a>1e-8f){float ia=1.0f/fg.a;fg.r*=ia;fg.g*=ia;fg.b*=ia;fg.a=1;}
  if(params_.tintStrength>0||params_.randomColorAmount>0){float randomTint=(hash32(rv^0xC010A5u)/(float)0xFFFFFFFFu)*clamp01(params_.randomColorAmount);float s=clamp01(params_.tintStrength/100.0f+randomTint);float tr=srgbToLinear(clamp01(params_.tintColor.r)),tg=srgbToLinear(clamp01(params_.tintColor.g)),tb=srgbToLinear(clamp01(params_.tintColor.b));fg.r=fg.r*(1-s)+tr*s;fg.g=fg.g*(1-s)+tg*s;fg.b=fg.b*(1-s)+tb*s;}
  if(params_.visualStyle==AsciiVisualStyle::Glitch){const float glitch=(float)((rv>>16)&255u)/255.0f;const float flicker=0.72f+0.28f*std::fabs(std::sin((float)time*18.0f+glitch*6.28318f));fg.r=clamp01(fg.r*(0.65f+glitch*0.9f));fg.g=clamp01(fg.g*(0.7f+(1.0f-glitch)*0.7f));fg.b=clamp01(fg.b*(0.75f+glitch*0.8f));fg=scaled(fg,flicker);}
  if(params_.visualStyle==AsciiVisualStyle::CGO){const float accent=(float)(rv&255u)/255.0f;if(accent>0.78f){fg.r=std::max(fg.r,0.78f);fg.g=std::max(fg.g,0.16f+0.22f*accent);fg.b*=0.35f;}}
  if(params_.visualStyle==AsciiVisualStyle::Rainbow){
   const std::uint32_t patch=hash32(params_.randomSeed^(std::uint32_t)(x0/std::max(1,cell*4))*0x9E3779B9u^(std::uint32_t)(y0/std::max(1,cell*4))*0x85EBCA6Bu);const float hue=std::fmod((float)(patch&0xFFFFu)/65535.0f*0.72f+(float)time*0.035f+mean*0.08f,1.0f)*6.0f;
   const float chroma=0.28f+0.72f*clamp01(mean),xh=chroma*(1.0f-std::fabs(std::fmod(hue,2.0f)-1.0f));
   float rr=0,gg=0,bb=0;
   if(hue<1){rr=chroma;gg=xh;}else if(hue<2){rr=xh;gg=chroma;}else if(hue<3){gg=chroma;bb=xh;}else if(hue<4){gg=xh;bb=chroma;}else if(hue<5){rr=xh;bb=chroma;}else{rr=chroma;bb=xh;}
   fg.r=rr+0.12f;fg.g=gg+0.12f;fg.b=bb+0.12f;fg.a=1.0f;
  }
  if(params_.paletteIndex>0&&params_.paletteIndex<=kS1PaletteCount){
   const auto* palette=s1Palette((S1PaletteId)params_.paletteIndex);
   if(palette&&palette->count){
    const float invAlpha=1.0f/std::max(avg.a,1.0e-6f);
    const float tone=clamp01(.2126f*avg.r*invAlpha+.7152f*avg.g*invAlpha+.0722f*avg.b*invAlpha);
    const float position=tone*(float)(palette->count-1);
    const std::size_t lo=(std::size_t)position,hi=std::min(lo+1,palette->count-1);
    const float blend=position-(float)lo;
    auto channel=[&](std::uint8_t ca,std::uint8_t cb){return srgbToLinear(((float)ca*(1.0f-blend)+(float)cb*blend)/255.0f);};
    const Pixel color{channel(palette->colors[lo].r,palette->colors[hi].r),channel(palette->colors[lo].g,palette->colors[hi].g),channel(palette->colors[lo].b,palette->colors[hi].b),1.0f};
    const float amount=clamp01(params_.paletteStrength/100.0f);
    fg.r=fg.r*(1.0f-amount)+color.r*amount;fg.g=fg.g*(1.0f-amount)+color.g*amount;fg.b=fg.b*(1.0f-amount)+color.b*amount;
   }
  }
  fg=scaled(fg,alpha);Pixel bg=params_.preserveCellAlpha?scaled(params_.paper,alpha):params_.paper;
  for(int y=y0;y<y1;++y){Pixel* out=dst.row(y);for(int x=x0;x<drawX1;++x){float u=(x+.5f-left)/dw,v=(y+.5f-top)/dh;if(flipX)u=1-u;float c=(u>=0&&u<=1&&v>=0&&v<=1)?maskAt(*glyph,u,v,params_.antiAliasing):0;c=clamp01(c)*clamp01(params_.asciiAmount/100.0f);Pixel r{fg.r*c+bg.r*(1-c),fg.g*c+bg.g*(1-c),fg.b*c+bg.b*(1-c),fg.a*c+bg.a*(1-c)};if(params_.blendWithOriginal>0){const Pixel& o=src.row(y)[x];float m=clamp01(params_.blendWithOriginal/100.0f);r.r=r.r*(1-m)+o.r*m;r.g=r.g*(1-m)+o.g*m;r.b=r.b*(1-m)+o.b*m;r.a=r.a*(1-m)+o.a*m;}out[x]=r;}}
   x0=drawX1;
  }
  y0=y1;
 }
 if(params_.visualStyle==AsciiVisualStyle::Mosaic){
  const int tile=std::clamp(cell*3,6,384);
  for(int ty=0;ty<h;ty+=tile)for(int tx=0;tx<w;tx+=tile){
   const int xEnd=std::min(w,tx+tile),yEnd=std::min(h,ty+tile);Pixel avgTile{0,0,0,0};int count=0;
   for(int yy=ty;yy<yEnd;++yy)for(int xx=tx;xx<xEnd;++xx){const Pixel& q=src.at(xx,yy);avgTile.r+=q.r;avgTile.g+=q.g;avgTile.b+=q.b;avgTile.a+=q.a;++count;}
   if(!count)continue;const float invTile=1.0f/(float)count;avgTile.r*=invTile;avgTile.g*=invTile;avgTile.b*=invTile;avgTile.a*=invTile;
   const float lum=clamp01(.2126f*avgTile.r+.7152f*avgTile.g+.0722f*avgTile.b);
   Pixel mosaic{avgTile.r*0.45f+lum*0.55f,avgTile.g*0.45f+lum*0.55f,avgTile.b*0.45f+lum*0.55f,avgTile.a};
   for(int yy=ty;yy<yEnd;++yy)for(int xx=tx;xx<xEnd;++xx){Pixel& q=dst.at(xx,yy);q.r=q.r*0.58f+mosaic.r*0.42f;q.g=q.g*0.58f+mosaic.g*0.42f;q.b=q.b*0.58f+mosaic.b*0.42f;q.a=std::max(q.a,mosaic.a*0.42f);}
   const std::uint32_t tileSeed=hash32(params_.randomSeed^(std::uint32_t)tx*0x9E3779B9u^(std::uint32_t)ty*0x85EBCA6Bu);
   if(candidates.empty()||(tileSeed&3u)==0u)continue;
   const GlyphBitmap* big=candidates[(tileSeed>>2)%candidates.size()];
   float bw=(float)(xEnd-tx)*0.72f,bh=(float)(yEnd-ty)*0.72f;
   const float aspect=big->height>0?(float)big->width/(float)big->height:1.0f;
   if(aspect>bw/std::max(1.0f,bh))bh=bw/aspect;else bw=bh*aspect;
   const float left=((float)tx+(float)xEnd-bw)*0.5f,top=((float)ty+(float)yEnd-bh)*0.5f;
   const float alpha=clamp01(avgTile.a);Pixel ink=avgTile;
   if(ink.a>1e-6f){ink.r/=ink.a;ink.g/=ink.a;ink.b/=ink.a;}
   const float gray=.2126f*ink.r+.7152f*ink.g+.0722f*ink.b;
   ink.r=clamp01(ink.r*0.55f+gray*0.45f);ink.g=clamp01(ink.g*0.55f+gray*0.45f);ink.b=clamp01(ink.b*0.55f+gray*0.45f);
   const float boost=1.15f+(float)((tileSeed>>12)&255u)/255.0f*0.65f;ink.r=clamp01(ink.r*boost);ink.g=clamp01(ink.g*boost);ink.b=clamp01(ink.b*boost);ink=scaled(ink,alpha);
   for(int yy=ty;yy<yEnd;++yy)for(int xx=tx;xx<xEnd;++xx){float u=((float)xx+0.5f-left)/std::max(1.0f,bw),v=((float)yy+0.5f-top)/std::max(1.0f,bh);if(u<0||u>1||v<0||v>1)continue;float cov=maskAt(*big,u,v,params_.antiAliasing);if(cov<=0.01f)continue;Pixel& q=dst.at(xx,yy);const float sa=cov*alpha,inv=1.0f-sa;q.r=q.r*inv+ink.r*cov;q.g=q.g*inv+ink.g*cov;q.b=q.b*inv+ink.b*cov;q.a=std::max(q.a,sa);}
  }
 }
 if(params_.visualStyle==AsciiVisualStyle::Threshold){
  for(int y=0;y<h;++y)for(int x=0;x<w;++x)dst.at(x,y)=scaled(src.at(x,y),0.38f);
  const int rowStep=std::clamp(cell,3,48),segment=std::clamp(cell*3,8,512);
  const int barHeight=std::max(1,rowStep/3);const float phase=(float)ctx.timeSeconds*1.7f;const float amount=clamp01(params_.asciiAmount/100.0f);
  for(int y=0,row=0;y<h;y+=rowStep,++row)for(int x=0,col=0;x<w;x+=segment,++col){
   const int xEnd=std::min(w,x+segment);float lum=0.0f;float alphaSum=0.0f;int count=0;
   for(int sy=y;sy<std::min(h,y+rowStep);++sy)for(int sx=x;sx<xEnd;++sx){const Pixel& q=src.at(sx,sy);lum+=sampleChannel(q,params_.channelMode);alphaSum+=q.a;++count;}
   if(!count)continue;float l=clamp01(lum/(float)count);l=std::pow(l,1.0f/std::clamp(params_.gamma,0.1f,4.0f));l=clamp01((l-0.5f)*contrast+0.5f+brightness);const int length=std::max(1,(int)std::lround((float)(xEnd-x)*(0.16f+0.84f*l)));
   const int shift=(int)(hash32(params_.randomSeed^(std::uint32_t)row*0x9E3779B9u^(std::uint32_t)col*0x85EBCA6Bu)%std::max(1,segment/3));
   const float sourceAlpha=clamp01(alphaSum/(float)count);const float barLuma=0.20f+0.80f*l;const float alpha=sourceAlpha*(0.62f+0.38f*l)*amount;
   const int sx0=std::min(w-1,x+((int)phase+shift)%(std::max(1,segment/3)));
   for(int yy=y;yy<std::min(h,y+barHeight);++yy)for(int xx=sx0;xx<std::min(w,sx0+length);++xx){Pixel bar=scaled(Pixel{barLuma,barLuma,barLuma,1.0f},alpha);Pixel& d=dst.at(xx,yy);const float invA=1.0f-bar.a;d={bar.r+d.r*invA,bar.g+d.g*invA,bar.b+d.b*invA,bar.a+d.a*invA};}
  }
  const float fade=std::clamp(params_.blendWithOriginal/100.0f,0.0f,2.0f);if(fade>0)for(int y=0;y<h;++y)for(int x=0;x<w;++x){Pixel& d=dst.at(x,y);const Pixel& o=src.at(x,y);d.r=d.r*(1-fade)+o.r*fade;d.g=d.g*(1-fade)+o.g*fade;d.b=d.b*(1-fade)+o.b*fade;d.a=d.a*(1-fade)+o.a*fade;}
 }
}
} // namespace xao
