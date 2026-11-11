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
#include "Win32GlyphAtlas.h"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <new>
#include <string>
#ifndef PF_OutFlag2_SUPPORTS_THREADED_RENDERING
#define PF_OutFlag2_SUPPORTS_THREADED_RENDERING (1L << 27)
#endif
namespace {
enum {
 P_INPUT=0,
 P_PRESET,P_CHARSET,P_CELL,P_SCALE,P_CHAR_SIZE,P_NUMBER_SIZE,P_CHAR_MARGIN,P_CELL_MARGIN,
 P_CONTRAST,P_BRIGHTNESS,P_INVERT,P_COLORIZE,P_AA,
 P_RANDOM_CHAR,P_RANDOM_WORD,P_RANDOM_TIMING,P_RANDOM_AMOUNT,P_RANDOM_SPEED,P_RANDOM_SEED,P_RANDOM_VARIATION,
 P_ANCIENT_LETTERS,P_ANCIENT_NUMBERS,P_ANCIENT_WORDS,
 P_ENGLISH_LETTERS,P_ENGLISH_NUMBERS,P_ENGLISH_WORDS,
 P_ARABIC_LETTERS,P_ARABIC_NUMBERS,P_ARABIC_WORDS,
 P_FONT,P_TRANSFER,P_REVERSE_ORDER,P_UNIFORM_LUMA,P_COUNT
};
enum { T_LINEAR=1,T_REC709=2,T_SRGB=3 };
struct State { xao::AsciiParams ascii; A_long transfer=T_LINEAR; };
void DeleteState(void* p){delete static_cast<State*>(p);}
float Decode(float v,A_long m){v=std::max(0.0f,v);if(m==T_SRGB)return v<=.04045f?v/12.92f:std::pow((v+.055f)/1.055f,2.4f);if(m==T_REC709)return v<.081f?v/4.5f:std::pow((v+.099f)/1.099f,1.f/.45f);return v;}
float Encode(float v,A_long m){v=std::max(0.0f,v);if(m==T_SRGB)return v<=.0031308f?12.92f*v:1.055f*std::pow(v,1.f/2.4f)-.055f;if(m==T_REC709)return v<.018f?4.5f*v:1.099f*std::pow(v,.45f)-.099f;return v;}
template<class T>float Unit(T v,float maxv){return static_cast<float>(v)/maxv;}
template<class T>T Quant(float v,float maxv){return static_cast<T>(std::lround(std::clamp(v,0.f,1.f)*maxv));}
template<>float Quant<float>(float v,float){return v;}

template<class PX>PF_Err Render(const PF_EffectWorld* s,PF_EffectWorld* d,const State& st,float maxv,const xao::RenderContext& ctx){
 if(!s||!d||!s->data||!d->data||s->width<=0||s->height<=0||d->width<0||d->height<0)return PF_Err_BAD_CALLBACK_PARAM;
 const std::int64_t minSrcRow=(std::int64_t)s->width*(std::int64_t)sizeof(PX),minDstRow=(std::int64_t)d->width*(std::int64_t)sizeof(PX);
 if(s->rowbytes<minSrcRow||d->rowbytes<minDstRow)return PF_Err_BAD_CALLBACK_PARAM;
 xao::Image input(s->width,s->height),output(s->width,s->height);
 for(A_long y=0;y<s->height;++y){const auto* row=reinterpret_cast<const PX*>(reinterpret_cast<const char*>(s->data)+(std::ptrdiff_t)y*s->rowbytes);auto* dst=input.row(y);
  for(A_long x=0;x<s->width;++x){float a=std::clamp(Unit(row[x].alpha,maxv),0.f,1.f),ia=a>1e-8f?1.f/a:0.f;float r=Decode(Unit(row[x].red,maxv)*ia,st.transfer),g=Decode(Unit(row[x].green,maxv)*ia,st.transfer),b=Decode(Unit(row[x].blue,maxv)*ia,st.transfer);dst[x]={r*a,g*a,b*a,a};}}
 xao::AsciiEngine engine(st.ascii);engine.render(input,output,ctx);
 for(A_long y=0;y<d->height;++y){auto* row=reinterpret_cast<PX*>(reinterpret_cast<char*>(d->data)+(std::ptrdiff_t)y*d->rowbytes);A_long sy=d->origin_y+y-s->origin_y;
  for(A_long x=0;x<d->width;++x){A_long sx=d->origin_x+x-s->origin_x;if(sx<0||sy<0||sx>=s->width||sy>=s->height){row[x]=PX{};continue;}const auto& p=output.at(sx,sy);float a=std::clamp(p.a,0.f,1.f),ia=a>1e-8f?1.f/a:0.f;row[x].alpha=Quant<decltype(row[x].alpha)>(a,maxv);row[x].red=Quant<decltype(row[x].red)>(Encode(p.r*ia,st.transfer)*a,maxv);row[x].green=Quant<decltype(row[x].green)>(Encode(p.g*ia,st.transfer)*a,maxv);row[x].blue=Quant<decltype(row[x].blue)>(Encode(p.b*ia,st.transfer)*a,maxv);}}
 return PF_Err_NONE;
}
PF_Err Global(PF_OutData* o){o->my_version=PF_VERSION(1,1,0,PF_Stage_DEVELOP,1);o->out_flags=PF_OutFlag_DEEP_COLOR_AWARE;o->out_flags2=PF_OutFlag2_FLOAT_COLOR_AWARE|PF_OutFlag2_SUPPORTS_SMART_RENDER|PF_OutFlag2_SUPPORTS_THREADED_RENDERING;return PF_Err_NONE;}

PF_Err Params(PF_InData*,PF_OutData* out){
 PF_ADD_POPUPX("Plugin Presets",10,1,"Default|Alien Signal|Circles and Dots|Classic|Corrupted|Crossword|Diamond|Matrix|Motherboard|Pink Shapes",0,P_PRESET);
 PF_ADD_POPUPX("Character Set",25,1,"Use Preset|Crates: Special Characters and Letters|Crates: Special Characters and Numbers|Crates: Classic Typewriter|Crates: Japanese Characters|Crates: Binary|Crates: Minimal Punk|Crates: X's|Crates: Bubble Growth|Crates: Stars|Crates: Diamonds|Crates: Dots|Crates: Circuits 1|Crates: Circuits 2|Crates: Alien Font|Crates: Bars|S1: Classic|S1: Minimal|S1: Detailed|S1: Bourke|S1: Braille|S1: Katakana|S1: Blocks|S1: Quadrants|S1: Box Drawing",0,P_CHARSET);
 PF_ADD_FLOAT_SLIDERX("Cell Size",2,128,2,64,12,PF_Precision_INTEGER,0,0,P_CELL);
 PF_ADD_FLOAT_SLIDERX("Glyph Scale",0.1,1.5,0.1,1.5,0.88,PF_Precision_TENTHS,0,0,P_SCALE);
 PF_ADD_FLOAT_SLIDERX("Character Size",10,200,10,200,100,PF_Precision_INTEGER,0,0,P_CHAR_SIZE);
 PF_ADD_FLOAT_SLIDERX("Number Size",10,200,10,200,100,PF_Precision_INTEGER,0,0,P_NUMBER_SIZE);
 PF_ADD_FLOAT_SLIDERX("Character Margins",0,100,0,100,0,PF_Precision_INTEGER,0,0,P_CHAR_MARGIN);
 PF_ADD_FLOAT_SLIDERX("Cell Margins",0,100,0,100,0,PF_Precision_INTEGER,0,0,P_CELL_MARGIN);
 PF_ADD_FLOAT_SLIDERX("Contrast",0,3,0,3,1,PF_Precision_TENTHS,0,0,P_CONTRAST);
 PF_ADD_FLOAT_SLIDERX("Brightness",-1,1,-1,1,0,PF_Precision_TENTHS,0,0,P_BRIGHTNESS);
 PF_ADD_POPUPX("Invert",3,1,"Use Preset|Off|On",0,P_INVERT);
 PF_ADD_CHECKBOXX("Colorize",1,0,P_COLORIZE);
 PF_ADD_CHECKBOXX("Anti-Aliasing",1,0,P_AA);
 PF_ADD_POPUPX("Random Characters",3,1,"Use Preset|Off|On",0,P_RANDOM_CHAR);
 PF_ADD_CHECKBOXX("Random Words",0,0,P_RANDOM_WORD);
 PF_ADD_POPUPX("Random Timing",3,1,"Use Preset|Off|On",0,P_RANDOM_TIMING);
 PF_ADD_FLOAT_SLIDERX("Random Amount",0,100,0,100,0,PF_Precision_INTEGER,0,0,P_RANDOM_AMOUNT);
 PF_ADD_FLOAT_SLIDERX("Random Speed",0,200,0,200,0,PF_Precision_INTEGER,0,0,P_RANDOM_SPEED);
 PF_ADD_FLOAT_SLIDERX("Random Seed",0,99999,0,99999,0,PF_Precision_INTEGER,0,0,P_RANDOM_SEED);
 PF_ADD_FLOAT_SLIDERX("Random Timing Variation",0,10,0,10,1,PF_Precision_TENTHS,0,0,P_RANDOM_VARIATION);
 PF_ADD_CHECKBOXX("Ancient Letters",0,0,P_ANCIENT_LETTERS);
 PF_ADD_CHECKBOXX("Ancient Numbers",0,0,P_ANCIENT_NUMBERS);
 PF_ADD_CHECKBOXX("Ancient Words",0,0,P_ANCIENT_WORDS);
 PF_ADD_CHECKBOXX("English Letters",0,0,P_ENGLISH_LETTERS);
 PF_ADD_CHECKBOXX("English Numbers",0,0,P_ENGLISH_NUMBERS);
 PF_ADD_CHECKBOXX("English Words",0,0,P_ENGLISH_WORDS);
 PF_ADD_CHECKBOXX("Arabic Letters",0,0,P_ARABIC_LETTERS);
 PF_ADD_CHECKBOXX("Arabic Numbers",0,0,P_ARABIC_NUMBERS);
 PF_ADD_CHECKBOXX("Arabic Words",0,0,P_ARABIC_WORDS);
 PF_ADD_POPUPX("Font Family",12,1,"Segoe UI Symbol|Consolas|IBM Plex Mono|VT323|Space Mono|Press Start 2P|Share Tech Mono|Courier Prime|IBM VGA|IBM EGA|Verite|DG One Bold",0,P_FONT);
 PF_ADD_POPUPX("Input Transfer",3,1,"Linear|Rec.709|sRGB",0,P_TRANSFER);
 PF_ADD_CHECKBOXX("Reverse Order",0,0,P_REVERSE_ORDER);
 PF_ADD_POPUPX("Uniform Luma",3,1,"Use Preset|Off|On",0,P_UNIFORM_LUMA);
 out->num_params=P_COUNT;return PF_Err_NONE;
}

PF_Err Pre(PF_InData* in,PF_OutData*,PF_PreRenderExtra* e){
 if(!in||!e||!e->input||!e->output||!e->cb)return PF_Err_BAD_CALLBACK_PARAM;
 PF_Err err=PF_Err_NONE;auto* state=new(std::nothrow)State();if(!state)return PF_Err_OUT_OF_MEMORY;
 auto read=[&](A_long index,auto apply){if(err!=PF_Err_NONE)return;PF_ParamDef p;AEFX_CLR_STRUCT(p);PF_Err q=PF_CHECKOUT_PARAM(in,index,in->current_time,in->time_step,in->time_scale,&p);if(q!=PF_Err_NONE){err=q;return;}apply(p);PF_Err c=PF_CHECKIN_PARAM(in,&p);if(c!=PF_Err_NONE)err=c;};
 A_long preset=1;
 read(P_PRESET,[&](PF_ParamDef& p){preset=p.u.pd.value;});
 preset=std::clamp<A_long>(preset,1,10);xao::applyCratesPreset(state->ascii,(xao::AsciiPresetId)(preset-1));
 read(P_CHARSET,[&](PF_ParamDef& p){if(p.u.pd.value>1)state->ascii.characterSet=(xao::AsciiCharacterSetId)std::clamp<A_long>(p.u.pd.value-2,0,(A_long)xao::AsciiCharacterSetId::Count-1);});
 read(P_CELL,[&](PF_ParamDef& p){state->ascii.cellSize=(int)p.u.fs_d.value;});
 read(P_SCALE,[&](PF_ParamDef& p){state->ascii.glyphScale=(float)p.u.fs_d.value;});
 read(P_CHAR_SIZE,[&](PF_ParamDef& p){state->ascii.characterSize*=std::clamp((float)p.u.fs_d.value/100.0f,0.1f,2.0f);});
 read(P_NUMBER_SIZE,[&](PF_ParamDef& p){state->ascii.numberSize=(float)p.u.fs_d.value;});
 read(P_CHAR_MARGIN,[&](PF_ParamDef& p){state->ascii.characterMargin=std::clamp(state->ascii.characterMargin+(float)p.u.fs_d.value,0.0f,180.0f);});
 read(P_CELL_MARGIN,[&](PF_ParamDef& p){state->ascii.cellMargin=std::clamp(state->ascii.cellMargin+(float)p.u.fs_d.value,0.0f,180.0f);});
 read(P_CONTRAST,[&](PF_ParamDef& p){state->ascii.contrast=(float)p.u.fs_d.value;});
 read(P_BRIGHTNESS,[&](PF_ParamDef& p){state->ascii.brightness=(float)p.u.fs_d.value;});
 read(P_INVERT,[&](PF_ParamDef& p){if(p.u.pd.value==2)state->ascii.invert=false;else if(p.u.pd.value==3)state->ascii.invert=true;});
 read(P_COLORIZE,[&](PF_ParamDef& p){state->ascii.colorize=p.u.bd.value!=0;});
 read(P_AA,[&](PF_ParamDef& p){state->ascii.antiAliasing=p.u.bd.value!=0;});
 read(P_RANDOM_CHAR,[&](PF_ParamDef& p){if(p.u.pd.value==2)state->ascii.randomCharacters=false;else if(p.u.pd.value==3)state->ascii.randomCharacters=true;});
 read(P_RANDOM_WORD,[&](PF_ParamDef& p){state->ascii.randomWords=p.u.bd.value!=0;});
 read(P_RANDOM_TIMING,[&](PF_ParamDef& p){if(p.u.pd.value==2)state->ascii.randomTiming=false;else if(p.u.pd.value==3)state->ascii.randomTiming=true;});
 read(P_RANDOM_AMOUNT,[&](PF_ParamDef& p){state->ascii.randomAmount=std::clamp(state->ascii.randomAmount+(float)p.u.fs_d.value/100.0f,0.0f,1.0f);});
 read(P_RANDOM_SPEED,[&](PF_ParamDef& p){state->ascii.randomSpeed=std::clamp(state->ascii.randomSpeed+(float)p.u.fs_d.value/100.0f,0.0f,10.0f);});
 read(P_RANDOM_SEED,[&](PF_ParamDef& p){state->ascii.randomSeed=(std::uint32_t)std::max(0.0,p.u.fs_d.value);});
 read(P_RANDOM_VARIATION,[&](PF_ParamDef& p){state->ascii.randomTimingVariation=(float)p.u.fs_d.value;});
 read(P_ANCIENT_LETTERS,[&](PF_ParamDef& p){state->ascii.ancientLetters=p.u.bd.value!=0;});
 read(P_ANCIENT_NUMBERS,[&](PF_ParamDef& p){state->ascii.ancientNumbers=p.u.bd.value!=0;});
 read(P_ANCIENT_WORDS,[&](PF_ParamDef& p){state->ascii.ancientWords=p.u.bd.value!=0;});
 read(P_ENGLISH_LETTERS,[&](PF_ParamDef& p){state->ascii.englishLetters=p.u.bd.value!=0;});
 read(P_ENGLISH_NUMBERS,[&](PF_ParamDef& p){state->ascii.englishNumbers=p.u.bd.value!=0;});
 read(P_ENGLISH_WORDS,[&](PF_ParamDef& p){state->ascii.englishWords=p.u.bd.value!=0;});
 read(P_ARABIC_LETTERS,[&](PF_ParamDef& p){state->ascii.arabicLetters=p.u.bd.value!=0;});
 read(P_ARABIC_NUMBERS,[&](PF_ParamDef& p){state->ascii.arabicNumbers=p.u.bd.value!=0;});
 read(P_ARABIC_WORDS,[&](PF_ParamDef& p){state->ascii.arabicWords=p.u.bd.value!=0;});
 state->ascii.enableAncient=state->ascii.ancientLetters||state->ascii.ancientNumbers||state->ascii.ancientWords;
 state->ascii.enableEnglish=state->ascii.englishLetters||state->ascii.englishNumbers||state->ascii.englishWords;
 state->ascii.enableArabic=state->ascii.arabicLetters||state->ascii.arabicNumbers||state->ascii.arabicWords;
 A_long fontIndex=1;
 read(P_FONT,[&](PF_ParamDef& p){fontIndex=p.u.pd.value;});
 read(P_TRANSFER,[&](PF_ParamDef& p){state->transfer=p.u.pd.value;});
 read(P_REVERSE_ORDER,[&](PF_ParamDef& p){state->ascii.reverseOrder=p.u.bd.value!=0;});
 read(P_UNIFORM_LUMA,[&](PF_ParamDef& p){if(p.u.pd.value==2)state->ascii.uniformLuma=false;else if(p.u.pd.value==3)state->ascii.uniformLuma=true;});
 if(err!=PF_Err_NONE){delete state;return err;}
 static const wchar_t* fontNames[]={L"Segoe UI Symbol",L"Consolas",L"IBM Plex Mono",L"VT323",L"Space Mono",L"Press Start 2P",L"Share Tech Mono",L"Courier Prime",L"IBM VGA",L"IBM EGA",L"Verite",L"DG One Bold"};
 fontIndex=std::clamp<A_long>(fontIndex,1,12);
 try{state->ascii.atlas=xao::win32::buildGlyphAtlas(state->ascii,fontNames[fontIndex-1]);}
 catch(const std::bad_alloc&){delete state;return PF_Err_OUT_OF_MEMORY;}
 catch(...){delete state;return PF_Err_INTERNAL_STRUCT_DAMAGED;}

 PF_RenderRequest request=e->input->output_request;request.rect.left=0;request.rect.top=0;request.rect.right=in->width;request.rect.bottom=in->height;request.channel_mask=PF_ChannelMask_ARGB;
 PF_CheckoutResult result;AEFX_CLR_STRUCT(result);err=e->cb->checkout_layer(in->effect_ref,P_INPUT,0,&request,in->current_time,in->time_step,in->time_scale,&result);
 if(err!=PF_Err_NONE){delete state;return err;}
 const PF_LRect asked=e->input->output_request.rect;PF_LRect actual;
 actual.left=std::max(result.result_rect.left,asked.left);actual.top=std::max(result.result_rect.top,asked.top);actual.right=std::min(result.result_rect.right,asked.right);actual.bottom=std::min(result.result_rect.bottom,asked.bottom);
 if(actual.right<actual.left)actual.right=actual.left;if(actual.bottom<actual.top)actual.bottom=actual.top;
 e->output->result_rect=actual;e->output->max_result_rect=result.max_result_rect;e->output->solid=FALSE;e->output->pre_render_data=state;e->output->delete_pre_render_data_func=DeleteState;return PF_Err_NONE;
}
PF_Err Smart(PF_InData* in,PF_OutData* out,PF_SmartRenderExtra* e){
 if(!in||!out||!e||!e->cb||!e->input)return PF_Err_BAD_CALLBACK_PARAM;const auto* state=static_cast<const State*>(e->input->pre_render_data);if(!state)return PF_Err_BAD_CALLBACK_PARAM;
 PF_EffectWorld* src=nullptr;PF_EffectWorld* dst=nullptr;PF_Err err=e->cb->checkout_layer_pixels(in->effect_ref,P_INPUT,&src);if(err!=PF_Err_NONE)return err;
 err=e->cb->checkout_output(in->effect_ref,&dst);if(err!=PF_Err_NONE){if(e->cb->checkin_layer_pixels)e->cb->checkin_layer_pixels(in->effect_ref,P_INPUT);return err;}
 if(!src||!dst||!src->data||!dst->data||src->width<=0||src->height<=0||dst->width<0||dst->height<0)err=PF_Err_BAD_CALLBACK_PARAM;
 else try{AEFX_SuiteScoper<PF_WorldSuite2> suite(in,kPFWorldSuite,kPFWorldSuiteVersion2,out);PF_PixelFormat format=PF_PixelFormat_INVALID,outputFormat=PF_PixelFormat_INVALID;err=suite->PF_GetPixelFormat(src,&format);if(err==PF_Err_NONE)err=suite->PF_GetPixelFormat(dst,&outputFormat);if(err==PF_Err_NONE&&format!=outputFormat)err=PF_Err_UNRECOGNIZED_PARAM_TYPE;
  if(err==PF_Err_NONE){xao::RenderContext ctx;ctx.timeSeconds=in->time_scale?in->current_time/(double)in->time_scale:0.0;ctx.frame=in->time_step?in->current_time/in->time_step:0;ctx.renderScale=in->downsample_x.den?(float)in->downsample_x.num/in->downsample_x.den:1.f;ctx.seed=state->ascii.randomSeed;
   switch(format){case PF_PixelFormat_ARGB32:err=Render<PF_Pixel>(src,dst,*state,255.f,ctx);break;case PF_PixelFormat_ARGB64:err=Render<PF_Pixel16>(src,dst,*state,32768.f,ctx);break;case PF_PixelFormat_ARGB128:err=Render<PF_PixelFloat>(src,dst,*state,1.f,ctx);break;default:err=PF_Err_UNRECOGNIZED_PARAM_TYPE;break;}}
 }catch(const std::bad_alloc&){err=PF_Err_OUT_OF_MEMORY;}catch(...){err=PF_Err_INTERNAL_STRUCT_DAMAGED;}
 PF_Err checkin=e->cb->checkin_layer_pixels?e->cb->checkin_layer_pixels(in->effect_ref,P_INPUT):PF_Err_NONE;return err!=PF_Err_NONE?err:checkin;
}
}
extern "C" DllExport int PluginDataEntryFunction2(void* a,void* b,int c,int d){(void)a;(void)b;(void)c;(void)d;return 0;}
extern "C" DllExport PF_Err EffectMain(PF_Cmd cmd,PF_InData* in,PF_OutData* out,PF_ParamDef*[],PF_LayerDef*,void* extra){
 try{switch(cmd){case PF_Cmd_ABOUT:PF_SPRINTF(out->return_msg,"XAO 1.2\rNative ASCII engine");return PF_Err_NONE;case PF_Cmd_GLOBAL_SETUP:return Global(out);case PF_Cmd_PARAMS_SETUP:return Params(in,out);case PF_Cmd_SMART_PRE_RENDER:return Pre(in,out,(PF_PreRenderExtra*)extra);case PF_Cmd_SMART_RENDER:return Smart(in,out,(PF_SmartRenderExtra*)extra);default:return PF_Err_NONE;}}
 catch(const std::bad_alloc&){return PF_Err_OUT_OF_MEMORY;}catch(...){return PF_Err_INTERNAL_STRUCT_DAMAGED;}
}
