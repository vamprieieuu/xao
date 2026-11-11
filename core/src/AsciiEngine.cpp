#include "xao/AsciiEngine.h"
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
constexpr char32_t k15[]=U"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
constexpr char32_t k16[]=U" .:-=+*#%@";
constexpr char32_t k17[]=U"$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^'. ";
constexpr char32_t kEmpty[]=U"";
float clamp01(float v) noexcept{return std::max(0.0f,std::min(1.0f,v));}
float clampf(float v,float lo,float hi) noexcept{return std::max(lo,std::min(hi,v));}
std::uint32_t hash32(std::uint32_t x) noexcept{x^=x>>16;x*=0x7feb352du;x^=x>>15;x*=0x846ca68bu;x^=x>>16;return x;}
float lum(const Pixel& p) noexcept{if(p.a<=1e-8f)return 0;return clamp01((.2126f*p.r+.7152f*p.g+.0722f*p.b)/p.a);}
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
 struct Score{const GlyphBitmap* glyph=nullptr;float value=0;};
 std::array<Score,32> densityBest{};std::size_t densityCount=0;float mean=0;for(float v:target)mean+=v;mean/=64;
 for(const auto* g:candidates){float d=std::fabs(mean-g->density);std::size_t pos=densityCount;
  if(pos>=densityBest.size())pos=densityBest.size()-1;
  while(pos>0&&densityBest[pos-1].value>d){if(pos<densityBest.size())densityBest[pos]=densityBest[pos-1];--pos;}
  densityBest[pos]={g,d};if(densityCount<densityBest.size())++densityCount;
 }
 std::array<Score,32> shapeBest{};std::size_t shapeCount=0;
 const std::size_t shortlist=std::min<std::size_t>(densityCount,shape?24:1);
 for(std::size_t i=0;i<shortlist;++i){const auto* g=densityBest[i].glyph;float score=0;
  if(shape){for(int y=0;y<8;++y)for(int x=0;x<8;++x){float m=maskAt(*g,(x+.5f)/8.0f,(y+.5f)/8.0f,false);float q=target[(std::size_t)y*8+x]-m;score+=q*q;}}
  else score=densityBest[i].value;
  std::size_t pos=shapeCount;while(pos>0&&shapeBest[pos-1].value>score){shapeBest[pos]=shapeBest[pos-1];--pos;}shapeBest[pos]={g,score};++shapeCount;
 }
 const std::size_t pool=std::min(shapeCount,(std::size_t)(1+std::lround(clamp01(amount)*15.0f)));
 return shapeBest[(std::size_t)random%pool].glyph;
}
Pixel scaled(Pixel p,float k) noexcept{p.r*=k;p.g*=k;p.b*=k;p.a*=k;return p;}
}
const CratesPresetDefinition& cratesPreset(AsciiPresetId id) noexcept{auto i=(std::size_t)id;return kPresets[i<sizeof(kPresets)/sizeof(kPresets[0])?i:0];}
std::string_view asciiCharacterSetName(AsciiCharacterSetId id) noexcept{
 static constexpr std::array<std::string_view,24> names{{"Special Characters and Letters","Special Characters and Numbers","Classic Typewriter","Japanese Characters","Binary","Minimal Punk","X's","Bubble Growth","Stars","Diamonds","Dots","Circuits 1","Circuits 2","Alien Font","Bars","Classic","Minimal","Detailed","Bourke","Braille","Katakana","Blocks","Quadrants","Box Drawing"}};
 auto i=(std::size_t)id;return i<names.size()?names[i]:names[0];
}
std::u32string_view asciiCharacterSetCodepoints(AsciiCharacterSetId id) noexcept{
 switch(id){
 case AsciiCharacterSetId::CratesSpecialLetters:return k0;case AsciiCharacterSetId::CratesSpecialNumbers:return k1;case AsciiCharacterSetId::CratesTypewriter:return k2;case AsciiCharacterSetId::CratesJapanese:return k3;case AsciiCharacterSetId::CratesBinary:return k4;case AsciiCharacterSetId::CratesMinimalPunk:return k5;case AsciiCharacterSetId::CratesXs:return k6;case AsciiCharacterSetId::CratesBubbleGrowth:return k7;case AsciiCharacterSetId::CratesStars:return k8;case AsciiCharacterSetId::CratesDiamonds:return k9;case AsciiCharacterSetId::CratesDots:return k10;case AsciiCharacterSetId::CratesCircuits1:return k11;case AsciiCharacterSetId::CratesCircuits2:return k12;case AsciiCharacterSetId::CratesAlienFont:return k13;case AsciiCharacterSetId::CratesBars:return k14;case AsciiCharacterSetId::S1Classic:return k15;case AsciiCharacterSetId::S1Minimal:return k16;case AsciiCharacterSetId::S1Detailed:return k17;case AsciiCharacterSetId::S1Bourke:return k17;default:return kEmpty;
 }
}
std::shared_ptr<const GlyphAtlas> builtinAsciiGlyphAtlas(){static const auto a=makeBuiltin();return a;}
void applyCratesPreset(AsciiParams& p,AsciiPresetId id) noexcept{
 const auto& v=cratesPreset(id);p.preset=id;p.characterSize=v.characterSize;p.characterMargin=v.characterMargin;p.cellMargin=v.cellMargin;p.antiAliasing=v.antiAliasing;p.invert=v.invert;p.reverseOrder=v.reverseOrder;p.uniformLuma=v.uniformLuma;p.paper={0,0,0,1};p.tintStrength=v.tintStrength;p.tintColor=v.tintColor;p.invertThreshold=v.invertThreshold;p.smoothShading=v.smoothShading;p.blendWithOriginal=v.blendWithOriginal;p.randomAmount=v.randomShuffle/100.0f;p.randomSpeed=v.randomSpeed/100.0f;p.randomColorAmount=v.randomColorAmount/100.0f;p.xFlipThreshold=v.xFlipThreshold/100.0f;p.randomCharacters=v.randomShuffle>0;p.randomTiming=v.randomSpeed>0;p.characterSet=(AsciiCharacterSetId)std::min<std::uint8_t>(v.cratesCharacterSet,14);
 p.enableAncient=p.enableEnglish=p.enableArabic=false;
}
void AsciiEngine::render(const Image& src,Image& dst,const RenderContext& ctx) const{
 if(src.width()!=dst.width()||src.height()!=dst.height())throw std::invalid_argument("ASCII dimensions must match");if(src.empty())return;
 int w=src.width(),h=src.height(),cell=std::max(2,std::min(256,params_.cellSize));
 float contrast=clampf(params_.contrast,0,4),brightness=clampf(params_.brightness,-1,1);
 float glyphScale=clampf(params_.glyphScale*(params_.characterSize/88.0f),.1f,1.5f);
 float charMargin=clampf(params_.characterMargin/200.0f,0,.45f),cellMargin=clampf(params_.cellMargin/200.0f,0,.45f);
 auto atlas=params_.atlas?params_.atlas:builtinAsciiGlyphAtlas();std::vector<const GlyphBitmap*> candidates;
 auto set=asciiCharacterSetCodepoints(params_.characterSet);bool groups=params_.enableAncient||params_.enableEnglish||params_.enableArabic;
 for(const auto& g:atlas->glyphs){if(g.wordToken!=params_.randomWords)continue;if(!groups&&!set.empty()&&g.codepoint&&set.find(g.codepoint)==std::u32string_view::npos)continue;candidates.push_back(&g);}
 if(candidates.empty()&&!params_.randomWords)for(const auto& g:builtinAsciiGlyphAtlas()->glyphs)candidates.push_back(&g);
 if(candidates.empty())return;
 for(int y0=0;y0<h;y0+=cell)for(int x0=0;x0<w;x0+=cell){
  int x1=std::min(w,x0+cell),y1=std::min(h,y0+cell);std::array<float,64> target{};Pixel avg{0,0,0,0};double alphaSum=0;int n=0;
  for(int sy=0;sy<8;++sy)for(int sx=0;sx<8;++sx){int px=std::min(x1-1,x0+(int)((sx+.5f)*(x1-x0)/8.0f)),py=std::min(y1-1,y0+(int)((sy+.5f)*(y1-y0)/8.0f));const Pixel& p=src.row(py)[px];float a=clamp01(p.a);target[(std::size_t)sy*8+sx]=clamp01((1-lum(p))*a);avg.r+=p.r;avg.g+=p.g;avg.b+=p.b;avg.a+=p.a;alphaSum+=a;++n;}
  float inv=1.0f/n;avg.r*=inv;avg.g*=inv;avg.b*=inv;avg.a*=inv;float mean=0;for(float v:target)mean+=v;mean/=64;
  if(params_.uniformLuma)for(float& v:target)v=mean;
  if(params_.reverseOrder)for(float& v:target)v=1-v;
  if(params_.invert)for(float& v:target)if(v>=clamp01(params_.invertThreshold/100.0f))v=1-v;
  for(float& v:target){v=clamp01((v-.5f)*contrast+.5f+brightness);if(params_.smoothShading>0){float sm=v*v*(3-2*v);v=v*(1-clamp01(params_.smoothShading/100.0f))+sm*clamp01(params_.smoothShading/100.0f);}}
  std::uint32_t ci=(std::uint32_t)((y0/cell)*((w+cell-1)/cell)+(x0/cell));double time=std::max(0.0,ctx.timeSeconds);
  bool animate=params_.randomCharacters||params_.randomWords;
  std::uint32_t slot=animate?(std::uint32_t)std::floor(time*(1.0+clampf(params_.randomSpeed,0,10)*24.0)):0u;
  if(params_.randomTiming)slot+=hash32(params_.randomSeed^ci)%(1u+(std::uint32_t)(clampf(params_.randomTimingVariation,0,10)*12));
  std::uint32_t rv=hash32(params_.randomSeed^hash32(ci+0x9e3779b9u)^hash32(slot));
  auto* glyph=selectGlyph(candidates,target,params_.shapeMatch,(params_.randomCharacters||params_.randomWords)?params_.randomAmount:0,rv);if(!glyph)continue;
  float cw=(float)(x1-x0),ch=(float)(y1-y0),aw=cw*(1-cellMargin),ah=ch*(1-cellMargin);
  float numberScale=glyph->numberToken?clampf(params_.numberSize/100.0f,.1f,2.0f):1.0f;
  float dw=std::max(1.0f,aw*glyphScale*numberScale*(1-charMargin)),dh=std::max(1.0f,ah*glyphScale*numberScale*(1-charMargin));
  float left=(x0+x1-dw)*.5f,top=(y0+y1-dh)*.5f,alpha=params_.preserveCellAlpha?clamp01((float)(alphaSum/n)):1.0f;
  Pixel fg=params_.colorize?avg:params_.ink;if(params_.colorize&&fg.a>1e-8f){float ia=1.0f/fg.a;fg.r*=ia;fg.g*=ia;fg.b*=ia;fg.a=1;}
  if(params_.tintStrength>0||params_.randomColorAmount>0){float randomTint=(hash32(rv^0xC010A5u)/(float)0xFFFFFFFFu)*clamp01(params_.randomColorAmount/100.0f);float s=clamp01(params_.tintStrength/100.0f+randomTint);float tr=srgbToLinear(clamp01(params_.tintColor.r)),tg=srgbToLinear(clamp01(params_.tintColor.g)),tb=srgbToLinear(clamp01(params_.tintColor.b));fg.r=fg.r*(1-s)+tr*s;fg.g=fg.g*(1-s)+tg*s;fg.b=fg.b*(1-s)+tb*s;}
  fg=scaled(fg,alpha);Pixel bg=params_.preserveCellAlpha?scaled(params_.paper,alpha):params_.paper;
  bool flipX=(glyph->codepoint==U'X'||glyph->codepoint==U'x')&&mean>=clamp01(params_.xFlipThreshold);
  for(int y=y0;y<y1;++y){Pixel* out=dst.row(y);for(int x=x0;x<x1;++x){float u=(x+.5f-left)/dw,v=(y+.5f-top)/dh;if(flipX)u=1-u;float c=(u>=0&&u<=1&&v>=0&&v<=1)?maskAt(*glyph,u,v,params_.antiAliasing):0;c=clamp01(c);Pixel r{fg.r*c+bg.r*(1-c),fg.g*c+bg.g*(1-c),fg.b*c+bg.b*(1-c),fg.a*c+bg.a*(1-c)};if(params_.blendWithOriginal>0){const Pixel& o=src.row(y)[x];float m=clamp01(params_.blendWithOriginal/100.0f);r.r=r.r*(1-m)+o.r*m;r.g=r.g*(1-m)+o.g*m;r.b=r.b*(1-m)+o.b*m;r.a=r.a*(1-m)+o.a*m;}out[x]=r;}}
 }
}
} // namespace xao
