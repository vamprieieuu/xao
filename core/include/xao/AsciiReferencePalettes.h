#pragma once
#include <cstddef>
#include <cstdint>

namespace xao {

struct Rgb8 {
    std::uint8_t r, g, b;
};

enum class S1PaletteId : std::uint8_t {
    MonitorGlow = 1,
    GameBoyDMG,
    Oil6,
    Retrotronic,
    GothicBit,
    Curiosities,
    CGAPalette1,
    CGAPalette1Bright,
    CGAPalette0Bright
};

struct S1PaletteDefinition {
    S1PaletteId id;
    const char* name;
    const Rgb8* colors;
    std::size_t count;
};

// Recovered from the palette-selection switch in the supplied S1AsciiArt AEX
// decompilation. The source stores RGB byte triplets and normalizes each by
// 255.0 before constructing the palette. Stops are evenly spaced by tone.
inline constexpr Rgb8 kS1MonitorGlow[] = {
    {0x22,0x23,0x23}, {0xF0,0xF6,0xF0}
};
inline constexpr Rgb8 kS1GameBoyDMG[] = {
    {0x0F,0x38,0x0F}, {0x30,0x62,0x30}, {0x8B,0xAC,0x0F}, {0xCA,0xDC,0x81}
};
inline constexpr Rgb8 kS1Oil6[] = {
    {0x27,0x27,0x44}, {0x49,0x4D,0x7E}, {0x8B,0x6D,0x9C},
    {0xC6,0x9F,0xA5}, {0xF2,0xD3,0xAB}, {0xFB,0xF5,0xEF}
};
inline constexpr Rgb8 kS1Retrotronic[] = {
    {0x39,0x2B,0x35}, {0xBB,0x47,0x4F}, {0x48,0x6B,0x7F},
    {0x7A,0x9C,0x96}, {0xD1,0xBF,0xB0}
};
inline constexpr Rgb8 kS1GothicBit[] = {
    {0x0E,0x0E,0x12}, {0x1A,0x1A,0x24}, {0x33,0x33,0x46}, {0x53,0x53,0x73},
    {0x80,0x80,0xA4}, {0xA6,0xA6,0xBF}, {0xC1,0xC1,0xD2}, {0xE6,0xE6,0xEC}
};
inline constexpr Rgb8 kS1Curiosities[] = {
    {0x46,0x42,0x5E}, {0x15,0x78,0x8C}, {0xFF,0x69,0x73},
    {0x00,0xB9,0xBE}, {0xFF,0xB0,0xA3}, {0xFF,0xEE,0xCC}
};
inline constexpr Rgb8 kS1CGAPalette1[] = {
    {0x00,0x00,0x00}, {0xAA,0x00,0xAA}, {0x00,0xAA,0x00}, {0xAA,0xAA,0xAA}
};
inline constexpr Rgb8 kS1CGAPalette1Bright[] = {
    {0x00,0x00,0x00}, {0xFF,0x55,0xFF}, {0x55,0xFF,0x55}, {0xFF,0xFF,0xFF}
};
inline constexpr Rgb8 kS1CGAPalette0Bright[] = {
    {0x00,0x00,0x00}, {0xFF,0x55,0x55}, {0x55,0xFF,0xFF}, {0x55,0x55,0xFF}
};

inline constexpr S1PaletteDefinition kS1Palettes[] = {
    {S1PaletteId::MonitorGlow,"Monitor Glow",kS1MonitorGlow,2},
    {S1PaletteId::GameBoyDMG,"Game Boy DMG",kS1GameBoyDMG,4},
    {S1PaletteId::Oil6,"Oil 6",kS1Oil6,6},
    {S1PaletteId::Retrotronic,"Retrotronic",kS1Retrotronic,5},
    {S1PaletteId::GothicBit,"Gothic Bit",kS1GothicBit,8},
    {S1PaletteId::Curiosities,"Curiosities",kS1Curiosities,6},
    {S1PaletteId::CGAPalette1,"CGA Palette 1",kS1CGAPalette1,4},
    {S1PaletteId::CGAPalette1Bright,"CGA Palette 1 Bright",kS1CGAPalette1Bright,4},
    {S1PaletteId::CGAPalette0Bright,"CGA Palette 0 Bright",kS1CGAPalette0Bright,4}
};

inline constexpr std::size_t kS1PaletteCount = sizeof(kS1Palettes)/sizeof(kS1Palettes[0]);

inline constexpr const S1PaletteDefinition* s1Palette(S1PaletteId id) noexcept {
    for (const auto& palette : kS1Palettes) if (palette.id == id) return &palette;
    return nullptr;
}

} // namespace xao
