#pragma once
#include "xao/AsciiEngine.h"
#include <memory>
namespace xao::win32 {
std::shared_ptr<const GlyphAtlas> buildGlyphAtlas(const AsciiParams& params);
}
