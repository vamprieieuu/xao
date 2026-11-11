#include "AEConfig.h"
#include "entry.h"
#include "AEFX_SuiteHelper.h"
#include "AE_Effect.h"
#include "AE_EffectCB.h"
#include "AE_EffectCBSuites.h"
#include "AE_Macros.h"
#include "Param_Utils.h"
#include "Smart_Utils.h"
#include "xao/AsciiEngine.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <new>
#ifndef PF_OutFlag2_SUPPORTS_THREADED_RENDERING
#define PF_OutFlag2_SUPPORTS_THREADED_RENDERING (1L << 27)
#endif
namespace {
enum { P_INPUT=0,P_CELL,P_SCALE,P_CONTRAST,P_BRIGHTNESS,P_INVERT,P_COLORIZE,P_TRANSFER,P_COUNT };
enum { T_LINEAR=1,T_REC709=2,T_SRGB=3 };
struct State{xao::AsciiParams ascii;A_long transfer=T_LINEAR;};
void DeleteState(void* p){delete static_cast<State*>(p);}
float Decode(float v,A_long m){v=std::max(0.0f,v);if(m==T_SRGB)return v<=.04045f?v/12.92f:std::pow((v+.055f)/1.055f,2.4f);if(m==T_REC709)return v<.081f?v/4.5f:std::pow((v+.099f)/1.099f,1.f/.45f);return v;}
float Encode(float v,A_long m){v=std::max(0.0f,v);if(m==T_SRGB)return v<=.0031308f?12.92f*v:1.055f*std::pow(v,1.f/2.4f)-.055f;if(m==T_REC709)return v<.018f?4.5f*v:1.099f*std::pow(v,.45f)-.099f;return v;}
template<class T>float Unit(T v,float maxv){return static_cast<float>(v)/maxv;}
template<class T>T Quant(float v,float maxv){return static_cast<T>(std::lround(std::clamp(v,0.f,1.f)*maxv));}
template<>float Quant<float>(float v,float){return v;}
template<class PX>PF_Err Render(const PF_EffectWorld* s,PF_EffectWorld* d,const State& st,float maxv,const xao::RenderContext& ctx){
 if(!s||!d||!s->data||!d->data||s->width<=0||s->height<=0||d->width<0||d->height<0)return PF_Err_BAD_CALLBACK_PARAM;
 const std::int64_t minSrcRow=static_cast<std::int64_t>(s->width)*static_cast<std::int64_t>(sizeof(PX));
 const std::int64_t minDstRow=static_cast<std::int64_t>(d->width)*static_cast<std::int64_t>(sizeof(PX));
 if(s->rowbytes<minSrcRow||d->rowbytes<minDstRow)return PF_Err_BAD_CALLBACK_PARAM;
 xao::Image input(s->width,s->height),output(s->width,s->height);
 for(A_long y=0;y<s->height;++y){const auto* row=reinterpret_cast<const PX*>(reinterpret_cast<const char*>(s->data)+static_cast<std::ptrdiff_t>(y)*s->rowbytes);auto* dst=input.row(y);
  for(A_long x=0;x<s->width;++x){float a=std::clamp(Unit(row[x].alpha,maxv),0.f,1.f),ia=a>1e-8f?1.f/a:0.f;float r=Decode(Unit(row[x].red,maxv)*ia,st.transfer),g=Decode(Unit(row[x].green,maxv)*ia,st.transfer),b=Decode(Unit(row[x].blue,maxv)*ia,st.transfer);dst[x]={r*a,g*a,b*a,a};}}
 xao::AsciiEngine engine(st.ascii);engine.render(input,output,ctx);
 for(A_long y=0;y<d->height;++y){auto* row=reinterpret_cast<PX*>(reinterpret_cast<char*>(d->data)+static_cast<std::ptrdiff_t>(y)*d->rowbytes);A_long sy=d->origin_y+y-s->origin_y;
  for(A_long x=0;x<d->width;++x){A_long sx=d->origin_x+x-s->origin_x;if(sx<0||sy<0||sx>=s->width||sy>=s->height){row[x]=PX{};continue;}const auto& p=output.at(sx,sy);float a=std::clamp(p.a,0.f,1.f),ia=a>1e-8f?1.f/a:0.f;row[x].alpha=Quant<decltype(row[x].alpha)>(a,maxv);row[x].red=Quant<decltype(row[x].red)>(Encode(p.r*ia,st.transfer)*a,maxv);row[x].green=Quant<decltype(row[x].green)>(Encode(p.g*ia,st.transfer)*a,maxv);row[x].blue=Quant<decltype(row[x].blue)>(Encode(p.b*ia,st.transfer)*a,maxv);}}
 return PF_Err_NONE;
}
PF_Err Global(PF_OutData* o){o->my_version=PF_VERSION(1,0,0,PF_Stage_DEVELOP,1);o->out_flags=PF_OutFlag_DEEP_COLOR_AWARE;o->out_flags2=PF_OutFlag2_FLOAT_COLOR_AWARE|PF_OutFlag2_SUPPORTS_SMART_RENDER|PF_OutFlag2_SUPPORTS_THREADED_RENDERING;return PF_Err_NONE;}
PF_Err Params(PF_InData* in_data,PF_OutData* out){PF_ParamDef def;AEFX_CLR_STRUCT(def);
 PF_ADD_FLOAT_SLIDERX("Cell size",2,128,2,64,8,PF_Precision_INTEGER,0,0,P_CELL);
 PF_ADD_FLOAT_SLIDERX("Glyph scale",.1,1.5,.1,1,.88,PF_Precision_TENTHS,0,0,P_SCALE);
 PF_ADD_FLOAT_SLIDERX("Contrast",0,3,0,2,1,PF_Precision_TENTHS,0,0,P_CONTRAST);
 PF_ADD_FLOAT_SLIDERX("Brightness",-1,1,-1,1,0,PF_Precision_TENTHS,0,0,P_BRIGHTNESS);
 PF_ADD_CHECKBOXX("Invert",0,0,P_INVERT);PF_ADD_CHECKBOXX("Colorize",1,0,P_COLORIZE);
 PF_ADD_POPUPX("Input transfer",3,1,"Linear|Rec.709|sRGB",0,P_TRANSFER);out->num_params=P_COUNT;return PF_Err_NONE;}
PF_Err Pre(PF_InData* in,PF_OutData*,PF_PreRenderExtra* e){
 if(!in||!e||!e->input||!e->output||!e->cb)return PF_Err_BAD_CALLBACK_PARAM;
 PF_Err err=PF_Err_NONE;
 auto* state=new(std::nothrow)State();
 if(!state)return PF_Err_OUT_OF_MEMORY;
 auto readParam=[&](A_long index,auto apply){
  if(err!=PF_Err_NONE)return;
  PF_ParamDef param;AEFX_CLR_STRUCT(param);
  PF_Err checkout=PF_CHECKOUT_PARAM(in,index,in->current_time,in->time_step,in->time_scale,&param);
  if(checkout!=PF_Err_NONE){err=checkout;return;}
  apply(param);
  PF_Err checkin=PF_CHECKIN_PARAM(in,&param);
  if(checkin!=PF_Err_NONE)err=checkin;
 };
 readParam(P_CELL,[&](PF_ParamDef& p){state->ascii.cellSize=static_cast<int>(p.u.fs_d.value);});
 readParam(P_SCALE,[&](PF_ParamDef& p){state->ascii.glyphScale=static_cast<float>(p.u.fs_d.value);});
 readParam(P_CONTRAST,[&](PF_ParamDef& p){state->ascii.contrast=static_cast<float>(p.u.fs_d.value);});
 readParam(P_BRIGHTNESS,[&](PF_ParamDef& p){state->ascii.brightness=static_cast<float>(p.u.fs_d.value);});
 readParam(P_INVERT,[&](PF_ParamDef& p){state->ascii.invert=p.u.bd.value!=0;});
 readParam(P_COLORIZE,[&](PF_ParamDef& p){state->ascii.colorize=p.u.bd.value!=0;});
 readParam(P_TRANSFER,[&](PF_ParamDef& p){state->transfer=p.u.pd.value;});
 if(err!=PF_Err_NONE){delete state;return err;}
 PF_RenderRequest request=e->input->output_request;
 request.rect.left=0;request.rect.top=0;request.rect.right=in->width;request.rect.bottom=in->height;
 request.channel_mask=PF_ChannelMask_ARGB;
 PF_CheckoutResult checkoutResult;AEFX_CLR_STRUCT(checkoutResult);
 err=e->cb->checkout_layer(in->effect_ref,P_INPUT,0,&request,in->current_time,in->time_step,in->time_scale,&checkoutResult);
 if(err!=PF_Err_NONE){delete state;return err;}
 const PF_LRect requested=e->input->output_request.rect;
 PF_LRect actual;
 actual.left=std::max(checkoutResult.result_rect.left,requested.left);
 actual.top=std::max(checkoutResult.result_rect.top,requested.top);
 actual.right=std::min(checkoutResult.result_rect.right,requested.right);
 actual.bottom=std::min(checkoutResult.result_rect.bottom,requested.bottom);
 if(actual.right<actual.left)actual.right=actual.left;
 if(actual.bottom<actual.top)actual.bottom=actual.top;
 e->output->result_rect=actual;
 e->output->max_result_rect=checkoutResult.max_result_rect;
 e->output->solid=FALSE;
 e->output->pre_render_data=state;
 e->output->delete_pre_render_data_func=DeleteState;
 return PF_Err_NONE;
}
PF_Err Smart(PF_InData* in,PF_OutData* out,PF_SmartRenderExtra* e){
 if(!in||!out||!e||!e->cb||!e->input)return PF_Err_BAD_CALLBACK_PARAM;
 const auto* state=static_cast<const State*>(e->input->pre_render_data);
 if(!state)return PF_Err_BAD_CALLBACK_PARAM;
 PF_EffectWorld* src=nullptr;
 PF_EffectWorld* dst=nullptr;
 PF_Err err=e->cb->checkout_layer_pixels(in->effect_ref,P_INPUT,&src);
 if(err!=PF_Err_NONE)return err;
 err=e->cb->checkout_output(in->effect_ref,&dst);
 if(err!=PF_Err_NONE){
  if(e->cb->checkin_layer_pixels)e->cb->checkin_layer_pixels(in->effect_ref,P_INPUT);
  return err;
 }
 if(!src||!dst||!src->data||!dst->data||src->width<=0||src->height<=0||dst->width<0||dst->height<0){
  err=PF_Err_BAD_CALLBACK_PARAM;
 }else{
  try{
   AEFX_SuiteScoper<PF_WorldSuite2> worldSuite(in,kPFWorldSuite,kPFWorldSuiteVersion2,out);
   PF_PixelFormat format=PF_PixelFormat_INVALID;
   PF_PixelFormat outputFormat=PF_PixelFormat_INVALID;
   err=worldSuite->PF_GetPixelFormat(src,&format);
   if(err==PF_Err_NONE)err=worldSuite->PF_GetPixelFormat(dst,&outputFormat);
   if(err==PF_Err_NONE&&format!=outputFormat)err=PF_Err_UNRECOGNIZED_PARAM_TYPE;
   if(err==PF_Err_NONE){
    xao::RenderContext context;
    context.timeSeconds=in->time_scale?in->current_time/static_cast<double>(in->time_scale):0.0;
    context.frame=in->time_step?in->current_time/in->time_step:0;
    context.renderScale=in->downsample_x.den?static_cast<float>(in->downsample_x.num)/in->downsample_x.den:1.f;
    switch(format){
     case PF_PixelFormat_ARGB32:err=Render<PF_Pixel>(src,dst,*state,255.f,context);break;
     case PF_PixelFormat_ARGB64:err=Render<PF_Pixel16>(src,dst,*state,32768.f,context);break;
     case PF_PixelFormat_ARGB128:err=Render<PF_PixelFloat>(src,dst,*state,1.f,context);break;
     default:err=PF_Err_UNRECOGNIZED_PARAM_TYPE;break;
    }
   }
  }catch(const std::bad_alloc&){err=PF_Err_OUT_OF_MEMORY;}catch(...){err=PF_Err_INTERNAL_STRUCT_DAMAGED;}
 }
 PF_Err checkin=e->cb->checkin_layer_pixels?e->cb->checkin_layer_pixels(in->effect_ref,P_INPUT):PF_Err_NONE;
 return err!=PF_Err_NONE?err:checkin;
}
}
extern "C" DllExport int PluginDataEntryFunction2(void* inPtr,void* outPtr,int inFlags,int inReserved){(void)inPtr;(void)outPtr;(void)inFlags;(void)inReserved;return 0;}
extern "C" DllExport PF_Err EffectMain(PF_Cmd cmd,PF_InData* in_data,PF_OutData* out_data,PF_ParamDef*[],PF_LayerDef*,void* extra){try{switch(cmd){case PF_Cmd_ABOUT:PF_SPRINTF(out_data->return_msg,"XAO ASCII 1.0\rNative CPU ASCII renderer");return PF_Err_NONE;case PF_Cmd_GLOBAL_SETUP:return Global(out_data);case PF_Cmd_PARAMS_SETUP:return Params(in_data,out_data);case PF_Cmd_SMART_PRE_RENDER:return Pre(in_data,out_data,static_cast<PF_PreRenderExtra*>(extra));case PF_Cmd_SMART_RENDER:return Smart(in_data,out_data,static_cast<PF_SmartRenderExtra*>(extra));default:return PF_Err_NONE;}}catch(const std::bad_alloc&){return PF_Err_OUT_OF_MEMORY;}catch(...){return PF_Err_INTERNAL_STRUCT_DAMAGED;}}
