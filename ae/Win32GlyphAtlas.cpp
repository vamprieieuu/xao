#include "Win32GlyphAtlas.h"
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <usp10.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <limits>
#include <mutex>
#include <numeric>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
namespace xao::win32 {
namespace {
constexpr int kAtlasW=256,kAtlasH=96;
struct Token { std::wstring text; char32_t codepoint=0; bool word=false,number=false,rtl=false,family=false; int fontResource=0; float sizeScale=1.0f; };
std::wstring toWide(char32_t cp){std::wstring s;if(cp<=0xFFFF)s.push_back((wchar_t)cp);else{cp-=0x10000;s.push_back((wchar_t)(0xD800+(cp>>10)));s.push_back((wchar_t)(0xDC00+(cp&0x3FF)));}return s;}
bool isNumber(char32_t cp){return(cp>=U'0'&&cp<=U'9')||(cp>=0x0660&&cp<=0x0669)||(cp>=0x06F0&&cp<=0x06F9)||(cp>=0x2160&&cp<=0x2188);}
int resourceFor(int group,int index){index=std::max(1,index);return (group==0?17000:group==1?17100:17200)+index;}
std::wstring sfntFamily(const BYTE* data,DWORD size){
 if(!data||size<12)return L"";
 auto be16=[&](std::size_t p)->unsigned{return p+2<=size?((unsigned)data[p]<<8)|data[p+1]:0;};
 auto be32=[&](std::size_t p)->unsigned long{return p+4<=size?((unsigned long)data[p]<<24)|((unsigned long)data[p+1]<<16)|((unsigned long)data[p+2]<<8)|data[p+3]:0;};
 unsigned tables=be16(4);std::size_t nameOffset=0,nameLength=0;
 for(unsigned i=0;i<tables;++i){std::size_t p=12+(std::size_t)i*16;if(p+16>size)break;if(std::memcmp(data+p,"name",4)==0){nameOffset=be32(p+8);nameLength=be32(p+12);break;}}
 if(!nameOffset||nameOffset+nameLength>size||nameLength<6)return L"";
 unsigned count=be16(nameOffset+2),strings=be16(nameOffset+4);std::wstring best;
 for(unsigned i=0;i<count;++i){std::size_t p=nameOffset+6+(std::size_t)i*12;if(p+12>size||p+12>nameOffset+nameLength)break;
  unsigned platform=be16(p),encoding=be16(p+2),language=be16(p+4),nameId=be16(p+6),len=be16(p+8),off=be16(p+10);
  if((nameId!=1&&nameId!=4)||len<2||strings+off+len>nameLength)continue;
  if(platform!=3&&platform!=0)continue;
  if(platform==3&&encoding!=1&&encoding!=10)continue;
  std::wstring value;for(unsigned j=0;j+1<len;j+=2){wchar_t ch=(wchar_t)((data[nameOffset+strings+off+j]<<8)|data[nameOffset+strings+off+j+1]);if(ch)value.push_back(ch);}
  if(value.empty())continue;
  if(nameId==1&&platform==3&&language==0x0409)return value;
  if(nameId==1&&best.empty())best=value;
  if(nameId==4&&best.empty())best=value;
 }
 return best;
}
std::wstring fontFace(int id){
 static std::mutex mutex;static std::unordered_map<int,std::wstring> faces;static std::vector<HANDLE> loaded;
 std::lock_guard<std::mutex> lock(mutex);auto it=faces.find(id);if(it!=faces.end())return it->second;
 HMODULE module=nullptr;GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS|GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,reinterpret_cast<LPCWSTR>(&buildGlyphAtlas),&module);
 std::wstring face=(id==0?L"Consolas":L"Segoe UI Symbol");
 if(module){HRSRC res=FindResourceW(module,MAKEINTRESOURCEW(id),MAKEINTRESOURCEW(10));if(res){HGLOBAL loadedResource=LoadResource(module,res);const BYTE* bytes=(const BYTE*)LockResource(loadedResource);DWORD size=SizeofResource(module,res);if(bytes&&size){auto name=sfntFamily(bytes,size);if(!name.empty())face=name;DWORD count=0;HANDLE handle=AddFontMemResourceEx((void*)bytes,size,nullptr,&count);if(handle)loaded.push_back(handle);}}}
 faces.emplace(id,face);return face;
}
bool hasGlyph(HDC dc,const std::wstring& text){if(text.empty())return false;std::vector<WORD> glyphs(text.size());DWORD result=GetGlyphIndicesW(dc,text.c_str(),(int)text.size(),glyphs.data(),GGI_MARK_NONEXISTING_GLYPHS);return result!=GDI_ERROR&&std::find(glyphs.begin(),glyphs.end(),(WORD)0xFFFF)==glyphs.end();}
void addCodepoint(std::vector<Token>& out,std::set<std::wstring>& seen,char32_t cp,int font,bool rtl=false,float scale=1.0f,bool family=false){auto s=toWide(cp);if(s.empty())return;std::wstring key=std::to_wstring(font)+L"|"+(family?L"1":L"0")+L"|"+s;if(!seen.insert(key).second)return;out.push_back({std::move(s),cp,false,isNumber(cp),rtl,family,font,scale});}
void addRange(std::vector<Token>& out,std::set<std::wstring>& seen,char32_t first,char32_t last,int font,bool rtl=false,float scale=1.0f,bool family=false){for(char32_t cp=first;cp<=last;++cp)addCodepoint(out,seen,cp,font,rtl,scale,family);}
void addText(std::vector<Token>& out,std::set<std::wstring>& seen,std::u32string_view text,int font,float scale=1.0f,bool family=false){for(char32_t cp:text)addCodepoint(out,seen,cp,font,false,scale,family);}
void addWords(std::vector<Token>& out,const std::u32string& alphabet,std::uint32_t seed,int font,bool rtl,float scale,bool family=true){if(alphabet.empty())return;std::mt19937 rng(seed);std::uniform_int_distribution<int> len(3,7);std::uniform_int_distribution<std::size_t> pick(0,alphabet.size()-1);for(int n=0;n<72;++n){std::wstring word;int count=len(rng);for(int i=0;i<count;++i){word+=toWide(alphabet[pick(rng)]);if(rtl&&(rng()%5u)==0u)word+=toWide((char32_t)(0x064B+(rng()%15u)));}out.push_back({std::move(word),0,true,false,rtl,family,font,scale});}}
HRESULT drawText(HDC dc,const Token& token){if(token.text.empty())return E_INVALIDARG;SCRIPT_STRING_ANALYSIS analysis=nullptr;DWORD flags=SSA_GLYPHS|SSA_FALLBACK|SSA_LINK;if(token.rtl)flags|=SSA_RTL;HRESULT hr=ScriptStringAnalyse(dc,token.text.c_str(),(int)token.text.size(),0,-1,flags,kAtlasW,nullptr,nullptr,nullptr,nullptr,nullptr,&analysis);if(FAILED(hr))return hr;const SIZE* extent=ScriptString_pSize(analysis);int x=extent?std::max(0,(kAtlasW-(int)extent->cx)/2):0;int y=extent?std::max(0,(kAtlasH-(int)extent->cy)/2):0;hr=ScriptStringOut(analysis,x,y,0,nullptr,0,-1,FALSE);ScriptStringFree(&analysis);return hr;}
std::wstring makeKey(const AsciiParams& p){const bool ancient=p.ancientLetters||p.ancientNumbers||p.ancientWords,english=p.englishLetters||p.englishNumbers||p.englishWords,arabic=p.arabicLetters||p.arabicNumbers||p.arabicWords;const int cs=(p.randomWords||(p.characterSet>=AsciiCharacterSetId::S1Braille&&p.characterSet<=AsciiCharacterSetId::S1BoxDrawing))?(int)p.characterSet:-1;std::wstring k=std::to_wstring(cs)+L"|preset:"+std::to_wstring((int)p.preset)+L"|style:"+std::to_wstring((int)p.visualStyle)+L"|"+std::to_wstring(p.ancientFont)+L"|"+std::to_wstring(english?p.englishFont:0)+L"|"+std::to_wstring(arabic?p.arabicFont:0)+L"|"+std::to_wstring((p.randomWords||p.ancientWords||p.englishWords||p.arabicWords)?p.randomSeed:0)+L"|"+std::to_wstring(arabic&&p.arabicNumbers?p.arabicNumberStyle:0);const bool f[]={p.randomWords,p.ancientLetters,p.ancientNumbers,p.ancientWords,p.englishLetters,p.englishNumbers,p.englishWords,p.arabicLetters,p.arabicNumbers,p.arabicWords,p.useAncientSize,p.useEnglishSize,p.useArabicSize};for(bool v:f)k+=v?L"1":L"0";k+=L"|"+std::to_wstring((int)std::lround(p.ancientSize))+L"|"+std::to_wstring((int)std::lround(p.englishSize))+L"|"+std::to_wstring((int)std::lround(p.arabicSize));return k;}
std::shared_ptr<const GlyphAtlas> build(const AsciiParams& p){
 std::vector<Token> tokens;std::set<std::wstring> seen;
 const int ancientFont=resourceFor(0,p.ancientFont),englishFont=resourceFor(1,p.englishFont),arabicFont=resourceFor(2,p.arabicFont);
 const float ancientScale=p.useAncientSize?std::clamp(p.ancientSize/100.0f,.1f,3.0f):1.0f;
 const float englishScale=p.useEnglishSize?std::clamp(p.englishSize/100.0f,.1f,3.0f):1.0f;
 const float arabicScale=p.useArabicSize?std::clamp(p.arabicSize/100.0f,.1f,3.0f):1.0f;
 int presetFont=0;
 switch(p.preset){
  case AsciiPresetId::AlienSignal:case AsciiPresetId::Diamonds:presetFont=resourceFor(0,1);break;
  case AsciiPresetId::Corrupted:case AsciiPresetId::Motherboard:presetFont=resourceFor(0,4);break;
  case AsciiPresetId::Classic:presetFont=resourceFor(1,1);break;
  case AsciiPresetId::Crossword:presetFont=resourceFor(1,5);break;
  case AsciiPresetId::Matrix:presetFont=resourceFor(1,10);break;
  case AsciiPresetId::PinkShapes:presetFont=resourceFor(1,5);break;
  default:break;
 }
 switch(p.visualStyle){
  case AsciiVisualStyle::CGO:presetFont=resourceFor(0,2);break;
  case AsciiVisualStyle::Liquid:presetFont=0;break;
  case AsciiVisualStyle::Glitch:presetFont=resourceFor(1,10);break;
  case AsciiVisualStyle::Alien:presetFont=resourceFor(0,1);break;
  case AsciiVisualStyle::Ghost:presetFont=resourceFor(0,3);break;
  case AsciiVisualStyle::Mosaic:presetFont=resourceFor(1,6);break;
  case AsciiVisualStyle::Rainbow:presetFont=resourceFor(1,10);break;
  case AsciiVisualStyle::Geometric:presetFont=0;break;
  default:break;
 }
 for(int id=0;id<=18;++id){const int font=(id==13||id==3)?ancientFont:presetFont;addText(tokens,seen,asciiCharacterSetCodepoints((AsciiCharacterSetId)id),font);}
 addText(tokens,seen,asciiCharacterSetCodepoints(AsciiCharacterSetId::CratesCircleDots),presetFont);
 for(int id=24;id<=26;++id)addText(tokens,seen,asciiCharacterSetCodepoints((AsciiCharacterSetId)id),presetFont);
 switch(p.characterSet){case AsciiCharacterSetId::S1Braille:addRange(tokens,seen,0x2800,0x28FF,0);break;case AsciiCharacterSetId::S1Katakana:addRange(tokens,seen,0x30A1,0x30F6,0);break;case AsciiCharacterSetId::S1Blocks:addRange(tokens,seen,0x2580,0x259F,0);break;case AsciiCharacterSetId::S1Quadrants:addRange(tokens,seen,0x2596,0x259F,0);break;case AsciiCharacterSetId::S1BoxDrawing:addRange(tokens,seen,0x2500,0x257F,0);break;default:break;}
 const std::u32string ancient=U"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩαβγδεζηθικλμνξοπρστυφχψωᚠᚢᚦᚨᚱᚲᚷᚹᚺᚾᛁᛃᛇᛈᛉᛊᛏᛒᛖᛗᛚᛜᛞᛟ";
 const std::u32string english=U"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
 const std::u32string arabic=U"ءآأؤإئابةتثجحخدذرزسشصضطظعغفقكلمنهوىيپچژگک";
 if(p.ancientLetters){addText(tokens,seen,ancient,ancientFont,ancientScale,true);addRange(tokens,seen,0x1681,0x169A,ancientFont,false,ancientScale,true);addRange(tokens,seen,0x10330,0x1034A,ancientFont,false,ancientScale,true);addRange(tokens,seen,0x10900,0x10915,ancientFont,false,ancientScale,true);}
 if(p.ancientNumbers)addText(tokens,seen,U"ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩⅪⅫ",ancientFont,ancientScale,true);
 if(p.ancientWords)addWords(tokens,ancient,p.randomSeed^0xA11CEu,ancientFont,false,ancientScale,true);
 if(p.englishLetters)addText(tokens,seen,english,englishFont,englishScale,true);
 if(p.englishNumbers)addText(tokens,seen,U"0123456789",englishFont,englishScale,true);
 if(p.englishWords)addWords(tokens,english,p.randomSeed^0xE61A5u,englishFont,false,englishScale,true);
 if(p.arabicLetters)addText(tokens,seen,arabic,arabicFont,arabicScale,true);
 if(p.arabicNumbers){if(p.arabicNumberStyle==1)addText(tokens,seen,U"۰۱۲۳۴۵۶۷۸۹",arabicFont,arabicScale,true);else if(p.arabicNumberStyle==2)addText(tokens,seen,U"0123456789",arabicFont,arabicScale,true);else addText(tokens,seen,U"٠١٢٣٤٥٦٧٨٩",arabicFont,arabicScale,true);}
 if(p.arabicWords)addWords(tokens,arabic,p.randomSeed^0xA2AB1Cu,arabicFont,true,arabicScale,true);
 if(p.randomWords&&std::none_of(tokens.begin(),tokens.end(),[](const Token& t){return t.word;})){
  std::u32string pool(asciiCharacterSetCodepoints(p.characterSet));if(pool.empty())pool=U"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  addWords(tokens,pool,p.randomSeed^0x574F5244u,0,false,1.0f,false);
 }
 HDC dc=CreateCompatibleDC(nullptr);if(!dc)return builtinAsciiGlyphAtlas();
 BITMAPINFO bmi{};bmi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);bmi.bmiHeader.biWidth=kAtlasW;bmi.bmiHeader.biHeight=-kAtlasH;bmi.bmiHeader.biPlanes=1;bmi.bmiHeader.biBitCount=32;bmi.bmiHeader.biCompression=BI_RGB;void* bits=nullptr;HBITMAP bitmap=CreateDIBSection(dc,&bmi,DIB_RGB_COLORS,&bits,nullptr,0);
 if(!bitmap||!bits){if(bitmap)DeleteObject(bitmap);DeleteDC(dc);return builtinAsciiGlyphAtlas();}
 HGDIOBJ oldBitmap=SelectObject(dc,bitmap);SetBkMode(dc,TRANSPARENT);SetTextColor(dc,RGB(255,255,255));auto atlas=std::make_shared<GlyphAtlas>();atlas->glyphs.reserve(tokens.size());
 const std::wstring fallback[]={L"Segoe UI Symbol",L"Segoe UI",L"Arial",L"Tahoma"};
 for(const auto& token:tokens){
  std::wstring preferred=fontFace(token.fontResource);HFONT chosen=nullptr;HGDIOBJ oldFont=nullptr;bool found=false;
  const bool japanese=token.codepoint>=0x3040&&token.codepoint<=0x30FF;
  std::array<std::wstring,7> faces=japanese?std::array<std::wstring,7>{L"Yu Gothic UI",L"Meiryo",preferred,fallback[0],fallback[1],fallback[2],fallback[3]}:std::array<std::wstring,7>{preferred,fallback[0],fallback[1],fallback[2],fallback[3],L"Yu Gothic UI",L"Meiryo"};
  for(const auto& face:faces){HFONT f=CreateFontW(token.word?-54:-72,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,token.rtl?ARABIC_CHARSET:DEFAULT_CHARSET,OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS,ANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,face.c_str());if(!f)continue;HGDIOBJ prior=SelectObject(dc,f);if(hasGlyph(dc,token.text)){chosen=f;oldFont=prior;found=true;break;}SelectObject(dc,prior);DeleteObject(f);}
  if(!found)continue;std::memset(bits,0,kAtlasW*kAtlasH*4);if(FAILED(drawText(dc,token))){SelectObject(dc,oldFont);DeleteObject(chosen);continue;}
  GlyphBitmap g;g.codepoint=token.codepoint;g.wordToken=token.word;g.numberToken=token.number;g.familyToken=token.family;g.sizeScale=token.sizeScale;g.width=kAtlasW;g.height=kAtlasH;g.coverage.resize(kAtlasW*kAtlasH);const auto* px=(const std::uint8_t*)bits;std::uint64_t sum=0;
  for(int i=0;i<kAtlasW*kAtlasH;++i){auto v=px[i*4+2];g.coverage[(std::size_t)i]=v;sum+=v;}
  if(sum){int minX=kAtlasW,minY=kAtlasH,maxX=-1,maxY=-1;for(int yy=0;yy<kAtlasH;++yy)for(int xx=0;xx<kAtlasW;++xx)if(g.coverage[(std::size_t)yy*kAtlasW+xx]>8){minX=std::min(minX,xx);minY=std::min(minY,yy);maxX=std::max(maxX,xx);maxY=std::max(maxY,yy);}
   if(maxX>=minX&&maxY>=minY){int cw=maxX-minX+1,ch=maxY-minY+1;std::vector<std::uint8_t> crop((std::size_t)cw*ch);std::uint64_t total=0;for(int yy=0;yy<ch;++yy)for(int xx=0;xx<cw;++xx){auto v=g.coverage[(std::size_t)(minY+yy)*kAtlasW+minX+xx];crop[(std::size_t)yy*cw+xx]=v;total+=v;}g.width=cw;g.height=ch;g.coverage=std::move(crop);sum=total;}
   g.density=(float)sum/(255.0f*(float)g.width*(float)g.height);atlas->glyphs.push_back(std::move(g));
  }
  SelectObject(dc,oldFont);DeleteObject(chosen);
 }
 SelectObject(dc,oldBitmap);DeleteObject(bitmap);DeleteDC(dc);
 if(atlas->glyphs.empty())return builtinAsciiGlyphAtlas();return atlas;
}
}
std::shared_ptr<const GlyphAtlas> buildGlyphAtlas(const AsciiParams& params){
 static std::mutex mutex;static std::unordered_map<std::wstring,std::shared_ptr<const GlyphAtlas>> cache;const auto key=makeKey(params);
 {std::lock_guard<std::mutex> lock(mutex);auto it=cache.find(key);if(it!=cache.end())return it->second;}
 auto result=build(params);
 {std::lock_guard<std::mutex> lock(mutex);auto it=cache.find(key);if(it!=cache.end())return it->second;if(cache.size()>=16)cache.erase(cache.begin());cache.emplace(key,result);}
 return result;
}
} // namespace xao::win32
