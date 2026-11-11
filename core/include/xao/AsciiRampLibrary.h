#pragma once
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <string_view>

namespace xao {
struct AsciiRampDefinition { std::string_view name; std::u32string_view codepoints; };
inline constexpr char32_t kAAMainStandard[] = U"@%#*+=-:. ";
inline constexpr char32_t kAAMainSimple[] = U"@#+. ";
inline constexpr char32_t kAAMainDetailed[] = U"$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^\\u0060'. ";
inline constexpr std::array<AsciiRampDefinition,3> kAsciiArtMainRamps{{
 {"Standard",kAAMainStandard},{"Simple",kAAMainSimple},{"Detailed",kAAMainDetailed}
}};
[[nodiscard]] inline float applyAsciiToneMap(float y,float contrast,float brightness) noexcept {
 return std::clamp(contrast*(y-0.5f)+0.5f+brightness,0.0f,1.0f);
}
[[nodiscard]] inline std::size_t asciiRampIndex(float luminance01,std::size_t rampSize,bool invert=false) noexcept {
 if(rampSize==0)return 0;const float y=invert?(1.0f-luminance01):luminance01;
 return std::min(static_cast<std::size_t>(y*static_cast<float>(rampSize-1)+0.5f),rampSize-1);
}
[[nodiscard]] inline float asciiGammaLuminance(float linearLuma,float gamma=2.2f) noexcept {
 return std::pow(std::clamp(linearLuma,0.0f,1.0f),1.0f/std::max(0.1f,gamma));
}
} // namespace xao
