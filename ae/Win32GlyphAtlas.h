#pragma once
#include "xao/AsciiEngine.h"
#include <memory>
#include <string>
#include <utility>
namespace xao::win32 {
std::shared_ptr<const GlyphAtlas> buildGlyphAtlas(const AsciiParams& params,const std::wstring& fontFamily);
}
