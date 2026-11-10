#include "xao/AsciiEngine.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <stdexcept>
namespace xao { namespace {
constexpr std::array<std::array<unsigned char,7>,10> ramp{{
{{0,0,0,0,0,0,0}},{{0,0,0,4,0,0,0}},{{0,0,4,0,4,0,0}},{{0,0,4,4,4,0,0}},
{{0,4,4,0,4,4,0}},{{0,4,4,4,4,4,0}},{{4,4,4,0,4,4,4}},{{21,10,21,10,21,10,21}},
{{21,31,21,31,21,31,21}},{{31,31,31,31,31,31,31}}
}};
float clamp01(float v){return std::max(0.0f,std::min(1.0f,v));}
float lum(const Pixel& p){if(p.a<=1e-8f)return 0;return clamp01((.2126f*p.r+.7152f*p.g+.0722f*p.b)/p.a);}
}
void AsciiEngine::render(const Image& src,Image& dst,const RenderContext&) const {
 if(src.width()!=dst.width()||src.height()!=dst.height()) throw std::invalid_argument("ASCII dimensions must match");
 const int w=src.width(),h=src.height(),cell=std::max(2,std::min(256,params_.cellSize));
 const float scale=std::max(.1f,std::min(1.0f,params_.glyphScale));
 const float contrast=std::max(0.0f,std::min(4.0f,params_.contrast));
 const float brightness=std::max(-1.0f,std::min(1.0f,params_.brightness));
 for(int y0=0;y0<h;y0+=cell) for(int x0=0;x0<w;x0+=cell){
  const int x1=std::min(w,x0+cell),y1=std::min(h,y0+cell); double sl=0,sa=0; Pixel avg{0,0,0,0}; int n=0;
  for(int y=y0;y<y1;++y) for(int x=x0;x<x1;++x){const Pixel& p=src.row(y)[x];avg.r+=p.r;avg.g+=p.g;avg.b+=p.b;avg.a+=p.a;sl+=lum(p);sa+=p.a;++n;}
  const float inv=1.0f/n; avg.r*=inv;avg.g*=inv;avg.b*=inv;avg.a*=inv;
  float tone=clamp01((float(sl/n)-.5f)*contrast+.5f+brightness); if(params_.invert)tone=1-tone;
  const int gi=std::max(0,std::min(9,int(std::lround(tone*9))));
  const float a=params_.preserveCellAlpha?float(sa/n):1.0f;
  Pixel fg=params_.colorize?avg:params_.ink; if(!params_.colorize){fg.r*=a;fg.g*=a;fg.b*=a;fg.a=a;}
  Pixel bg=params_.paper; bg.r*=a;bg.g*=a;bg.b*=a;bg.a*=a;
  const float gw=std::max(1.0f,(x1-x0)*scale),gh=std::max(1.0f,(y1-y0)*scale);
  const float left=(x0+x1-gw)*.5f,top=(y0+y1-gh)*.5f;
  for(int y=y0;y<y1;++y){Pixel* out=dst.row(y);for(int x=x0;x<x1;++x){
   const int gx=int((x-left)*5/gw),gy=int((y-top)*7/gh);
   const bool on=gx>=0&&gx<5&&gy>=0&&gy<7&&((ramp[gi][gy]>>(4-gx))&1u);
   out[x]=on?fg:bg;
  }}
 }
}
}