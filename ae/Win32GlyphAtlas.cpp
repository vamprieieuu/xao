#include "Win32GlyphAtlas.h"
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <usp10.h>
#include <utility>
#include <algorithm>
#include <cstring>
#include <mutex>
#include <numeric>
#include <limits>
#include <cmath>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

namespace xao::win32 {
namespace {
constexpr int kAtlasW=96,kAtlasH=24;
struct Token { std::wstring text; char32_t codepoint=0; bool word=false; bool number=false; bool rtl=false; bool s1Atlas=false; };
std::wstring toWide(char32_t cp) {
 std::wstring s;
 if(cp<=0xFFFF)s.push_back((wchar_t)cp);
 else{cp-=0x10000;s.push_back((wchar_t)(0xD800+(cp>>10)));s.push_back((wchar_t)(0xDC00+(cp&0x3FF)));}
 return s;
}
bool isNumber(char32_t cp){return(cp>=U'0'&&cp<=U'9')||(cp>=0x0660&&cp<=0x0669)||(cp>=0x06F0&&cp<=0x06F9)||(cp>=0x2160&&cp<=0x2188);}
void addCodepoint(std::vector<Token>& out,std::set<std::wstring>& seen,char32_t cp,bool rtl=false,bool s1=false){
 auto s=toWide(cp);if(s.empty()||!seen.insert(s).second)return;out.push_back({std::move(s),cp,false,isNumber(cp),rtl,s1});
}
void addRange(std::vector<Token>& out,std::set<std::wstring>& seen,char32_t first,char32_t last,bool rtl=false){for(char32_t cp=first;cp<=last;++cp)addCodepoint(out,seen,cp,rtl,false);}
void addText(std::vector<Token>& out,std::set<std::wstring>& seen,std::u32string_view text,bool s1=false){for(char32_t cp:text)addCodepoint(out,seen,cp,false,s1);}
void addWords(std::vector<Token>& out,const std::u32string& alphabet,std::uint32_t seed,bool rtl){
 if(alphabet.empty())return;std::mt19937 rng(seed);std::uniform_int_distribution<int> len(2,6);std::uniform_int_distribution<std::size_t> pick(0,alphabet.size()-1);
 for(int n=0;n<64;++n){std::wstring word;int count=len(rng);for(int i=0;i<count;++i)word+=toWide(alphabet[pick(rng)]);out.push_back({std::move(word),0,true,false,rtl,false});}
}
HRESULT drawShapedText(HDC dc,const Token& token){
 if(token.text.empty())return E_INVALIDARG;
 SCRIPT_STRING_ANALYSIS analysis=nullptr;
 DWORD flags=SSA_GLYPHS|SSA_FALLBACK|SSA_LINK;
 if(token.rtl)flags|=SSA_RTL;
 HRESULT hr=ScriptStringAnalyse(dc,token.text.c_str(),(int)token.text.size(),0,-1,flags,kAtlasW,nullptr,nullptr,nullptr,nullptr,nullptr,&analysis);
 if(FAILED(hr))return hr;
 const SIZE* extent=ScriptString_pSize(analysis);
 int x=extent?std::max(0,(kAtlasW-(int)extent->cx)/2):0;
 int y=extent?std::max(0,(kAtlasH-(int)extent->cy)/2):0;
 hr=ScriptStringOut(analysis,x,y,0,nullptr,0,-1,FALSE);
 ScriptStringFree(&analysis);
 return hr;
}
bool hasGlyph(HDC dc,const std::wstring& text){
 if(text.empty())return false;std::vector<WORD> glyphs(text.size());DWORD result=GetGlyphIndicesW(dc,text.c_str(),(int)text.size(),glyphs.data(),GGI_MARK_NONEXISTING_GLYPHS);
 if(result==GDI_ERROR)return false;return std::find(glyphs.begin(),glyphs.end(),(WORD)0xFFFF)==glyphs.end();
}
std::wstring makeKey(const AsciiParams& p,const std::wstring& family){
 std::wstring k=family+L"|"+std::to_wstring((int)p.characterSet)+L"|"+(p.randomWords?L"1":L"0");
 const bool flags[]={p.enableAncient,p.enableEnglish,p.enableArabic,p.ancientLetters,p.ancientNumbers,p.ancientWords,p.englishLetters,p.englishNumbers,p.englishWords,p.arabicLetters,p.arabicNumbers,p.arabicWords};
 for(bool f:flags)k+=f?L"1":L"0";return k;
}
std::shared_ptr<const GlyphAtlas> build(const AsciiParams& p,const std::wstring& family){
 std::vector<Token> tokens;std::set<std::wstring> seen;
 const bool familyMode=p.enableAncient||p.enableEnglish||p.enableArabic;
 if(!familyMode){
  const bool s1Latin=p.characterSet==AsciiCharacterSetId::S1Classic||p.characterSet==AsciiCharacterSetId::S1Minimal||p.characterSet==AsciiCharacterSetId::S1Detailed||p.characterSet==AsciiCharacterSetId::S1Bourke;
  addText(tokens,seen,asciiCharacterSetCodepoints(p.characterSet),s1Latin);
  switch(p.characterSet){
   case AsciiCharacterSetId::S1Braille:addRange(tokens,seen,0x2800,0x28FF);break;
   case AsciiCharacterSetId::S1Katakana:addRange(tokens,seen,0x30A1,0x30F6);break;
   case AsciiCharacterSetId::S1Blocks:addRange(tokens,seen,0x2580,0x259F);break;
   case AsciiCharacterSetId::S1Quadrants:addRange(tokens,seen,0x2596,0x259F);break;
   case AsciiCharacterSetId::S1BoxDrawing:addRange(tokens,seen,0x2500,0x257F);break;
   default:break;
  }
 }
 const std::u32string ancientLetters=U"ΑΒΓΔΕΖΗΘΙΚΛΜΝΞΟΠΡΣΤΥΦΧΨΩαβγδεζηθικλμνξοπρστυφχψωᚠᚢᚦᚨᚱᚲᚷᚹᚺᚾᛁᛃᛇᛈᛉᛊᛏᛒᛖᛗᛚᛜᛞᛟ";
 const std::u32string englishLetters=U"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
 const std::u32string arabicLetters=U"ءآأؤإئابةتثجحخدذرزسشصضطظعغفقكلمنهوىي";
 const std::u32string ancientNumbers=U"ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩⅪⅫ";
 const std::u32string englishNumbers=U"0123456789";
 const std::u32string arabicNumbers=U"٠١٢٣٤٥٦٧٨٩";
 if(p.enableAncient){
  if(p.ancientLetters){
   for(char32_t cp:ancientLetters)addCodepoint(tokens,seen,cp);
   addRange(tokens,seen,0x1681,0x169A);   // Ogham
   addRange(tokens,seen,0x10330,0x1034A); // Gothic
   addRange(tokens,seen,0x10380,0x1039E); // Ugaritic
   addRange(tokens,seen,0x103A0,0x103C3); // Old Persian
   addRange(tokens,seen,0x10900,0x10915); // Phoenician
   addRange(tokens,seen,0x12000,0x1203F); // Cuneiform sample block
   addRange(tokens,seen,0x13000,0x1303F); // Egyptian hieroglyph sample block
  }
  if(p.ancientNumbers)for(char32_t cp:ancientNumbers)addCodepoint(tokens,seen,cp);
  if(p.ancientWords)addWords(tokens,ancientLetters,p.randomSeed^0xA11CEu,false);
 }
 if(p.enableEnglish){if(p.englishLetters)for(char32_t cp:englishLetters)addCodepoint(tokens,seen,cp);if(p.englishNumbers)for(char32_t cp:englishNumbers)addCodepoint(tokens,seen,cp);if(p.englishWords)addWords(tokens,englishLetters,p.randomSeed^0xE61A5u,false);}
 if(p.enableArabic){if(p.arabicLetters)for(char32_t cp:arabicLetters)addCodepoint(tokens,seen,cp,true);if(p.arabicNumbers)for(char32_t cp:arabicNumbers)addCodepoint(tokens,seen,cp,true);if(p.arabicWords)addWords(tokens,arabicLetters,p.randomSeed^0xA2AB1Cu,true);}
 if(p.randomWords&&std::none_of(tokens.begin(),tokens.end(),[](const Token& t){return t.word;})){
  std::u32string pool;
  for(const auto& token:tokens)if(token.codepoint&&!token.word&&!token.number)pool.push_back(token.codepoint);
  if(pool.empty())pool=englishLetters;
  addWords(tokens,pool,p.randomSeed^0x574F5244u,false);
 }
 if(tokens.empty())addText(tokens,seen,U"@#%&$ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");

 HDC dc=CreateCompatibleDC(nullptr);if(!dc)return builtinAsciiGlyphAtlas();
 BITMAPINFO bmi{};bmi.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);bmi.bmiHeader.biWidth=kAtlasW;bmi.bmiHeader.biHeight=-kAtlasH;bmi.bmiHeader.biPlanes=1;bmi.bmiHeader.biBitCount=32;bmi.bmiHeader.biCompression=BI_RGB;
 void* bits=nullptr;HBITMAP bitmap=CreateDIBSection(dc,&bmi,DIB_RGB_COLORS,&bits,nullptr,0);
 if(!bitmap||!bits){if(bitmap)DeleteObject(bitmap);DeleteDC(dc);return builtinAsciiGlyphAtlas();}
 HGDIOBJ oldBitmap=SelectObject(dc,bitmap);SetBkMode(dc,TRANSPARENT);SetTextColor(dc,RGB(255,255,255));
 const std::wstring preferred=(p.characterSet==AsciiCharacterSetId::S1Katakana)?L"Yu Gothic UI":family;
 const std::wstring fallbacks[]={preferred,L"Yu Gothic UI",L"Meiryo",L"Segoe UI Symbol",L"Segoe UI",L"Tahoma"};
 auto atlas=std::make_shared<GlyphAtlas>();atlas->glyphs.reserve(tokens.size());std::vector<GlyphBitmap> s1Glyphs;
 for(const auto& token:tokens){
  HFONT chosen=nullptr;HGDIOBJ oldFont=nullptr;bool found=false;int height=token.word?-10:-19;
  for(const auto& face:fallbacks){if(face.empty())continue;HFONT f=CreateFontW(height,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_TT_PRECIS,CLIP_DEFAULT_PRECIS,ANTIALIASED_QUALITY,DEFAULT_PITCH|FF_DONTCARE,face.c_str());if(!f)continue;HGDIOBJ prior=SelectObject(dc,f);if(hasGlyph(dc,token.text)){chosen=f;oldFont=prior;found=true;break;}SelectObject(dc,prior);DeleteObject(f);}
  if(!found)continue;
  std::memset(bits,0,kAtlasW*kAtlasH*4);
  if(FAILED(drawShapedText(dc,token))){SelectObject(dc,oldFont);DeleteObject(chosen);continue;}
  GlyphBitmap g;g.codepoint=token.codepoint;g.wordToken=token.word;g.numberToken=token.number;g.width=kAtlasW;g.height=kAtlasH;g.coverage.resize(kAtlasW*kAtlasH);const auto* px=(const std::uint8_t*)bits;std::uint64_t sum=0;
  for(int i=0;i<kAtlasW*kAtlasH;++i){std::uint8_t v=px[i*4+2];g.coverage[(std::size_t)i]=v;sum+=v;}
  if(sum){int minX=kAtlasW,minY=kAtlasH,maxX=-1,maxY=-1;
   for(int yy=0;yy<kAtlasH;++yy)for(int xx=0;xx<kAtlasW;++xx)if(g.coverage[(std::size_t)yy*kAtlasW+xx]>8){minX=std::min(minX,xx);minY=std::min(minY,yy);maxX=std::max(maxX,xx);maxY=std::max(maxY,yy);}
   if(maxX>=minX&&maxY>=minY){const int cropW=maxX-minX+1,cropH=maxY-minY+1;std::vector<std::uint8_t> crop((std::size_t)cropW*cropH);std::uint64_t cropSum=0;
    for(int yy=0;yy<cropH;++yy)for(int xx=0;xx<cropW;++xx){auto v=g.coverage[(std::size_t)(minY+yy)*kAtlasW+minX+xx];crop[(std::size_t)yy*cropW+xx]=v;cropSum+=v;}
    g.width=cropW;g.height=cropH;g.coverage=std::move(crop);sum=cropSum;}
   g.density=(float)sum/(255.0f*(float)g.width*(float)g.height);
   if(token.s1Atlas)s1Glyphs.push_back(std::move(g));else atlas->glyphs.push_back(std::move(g));
  }
  SelectObject(dc,oldFont);DeleteObject(chosen);
 }
 SelectObject(dc,oldBitmap);DeleteObject(bitmap);DeleteDC(dc);
 if(!s1Glyphs.empty()){
  if(p.characterSet==AsciiCharacterSetId::S1Detailed){for(auto& g:s1Glyphs)atlas->glyphs.push_back(std::move(g));}
  else {
  std::size_t wanted=92;
  if(p.characterSet==AsciiCharacterSetId::S1Classic)wanted=10;
  else if(p.characterSet==AsciiCharacterSetId::S1Minimal)wanted=6;
  else if(p.characterSet==AsciiCharacterSetId::S1Bourke)wanted=28;
  wanted=std::min(wanted,s1Glyphs.size());
  std::vector<std::size_t> order(s1Glyphs.size());std::iota(order.begin(),order.end(),0);
  std::stable_sort(order.begin(),order.end(),[&](std::size_t a,std::size_t b){return s1Glyphs[a].density<s1Glyphs[b].density;});
  const float maxDensity=s1Glyphs[order.back()].density;std::vector<bool> used(s1Glyphs.size(),false);std::vector<std::size_t> selected;selected.reserve(wanted);
  for(std::size_t i=0;i<wanted;++i){const float target=wanted>1?(float)i/(float)(wanted-1)*maxDensity:0.0f;std::size_t best=order.front();float bestDistance=std::numeric_limits<float>::max();
   for(std::size_t idx:order)if(!used[idx]){float d=std::fabs(s1Glyphs[idx].density-target);if(d<bestDistance){bestDistance=d;best=idx;}}
   used[best]=true;selected.push_back(best);
  }
  std::stable_sort(selected.begin(),selected.end(),[&](std::size_t a,std::size_t b){return s1Glyphs[a].density<s1Glyphs[b].density;});
  for(std::size_t idx:selected)atlas->glyphs.push_back(std::move(s1Glyphs[idx]));
  }
 }
 if(atlas->glyphs.empty())return std::make_shared<GlyphAtlas>();return atlas;
}
}
std::shared_ptr<const GlyphAtlas> buildGlyphAtlas(const AsciiParams& params,const std::wstring& fontFamily){
 static std::mutex mutex;static std::unordered_map<std::wstring,std::shared_ptr<const GlyphAtlas>> cache;
 const auto key=makeKey(params,fontFamily);std::lock_guard<std::mutex> lock(mutex);auto it=cache.find(key);if(it!=cache.end())return it->second;
 auto result=build(params,fontFamily);
 if(cache.size()>=32)cache.erase(cache.begin());
 cache.emplace(key,result);return result;
}
} // namespace xao::win32
