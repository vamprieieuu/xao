#include "xao/AsciiEngine.h"
#include <cmath>
#include <iostream>
int main(){
 xao::Image src(16,16),dst(16,16);
 for(int y=0;y<16;++y)for(int x=0;x<16;++x){float v=x<8?0.0f:1.0f;src.at(x,y)={v,v,v,1};}
 xao::AsciiParams p;p.cellSize=8;p.colorize=false;p.paper={0,0,0,0};xao::AsciiEngine e(p);e.render(src,dst,{});
 bool ink=false,paper=false;for(const auto& q:dst.pixels()){ink|=q.a>.5f;paper|=q.a<.5f;if(!std::isfinite(q.r))return 2;}
 if(!ink||!paper)return 1;std::cout<<"XAO ASCII engine tests passed\n";return 0;
}