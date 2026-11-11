#pragma once
#include "xao/Engine.h"
#include "xao/AsciiReferencePalettes.h"
#include <cstdint>
#include <memory>
#include <string_view>
#include <vector>
namespace xao {
enum class AsciiPresetId : std::uint8_t { Default=0, AlienSignal, CirclesAndDots, Classic, Corrupted, Crossword, Diamonds, Matrix, Motherboard, PinkShapes, Count };
enum class AsciiCharacterSetId : std::uint8_t {
 CratesSpecialLetters=0, CratesSpecialNumbers, CratesTypewriter, CratesJapanese, CratesBinary,
 CratesMinimalPunk, CratesXs, CratesBubbleGrowth, CratesStars, CratesDiamonds, CratesDots,
 CratesCircuits1, CratesCircuits2, CratesAlienFont, CratesBars,
 S1Classic, S1Minimal, S1Detailed, S1Bourke, S1Braille, S1Katakana, S1Blocks, S1Quadrants, S1BoxDrawing,
 AsciiArtMainStandard, AsciiArtMainSimple, AsciiArtMainDetailed, Count
};
enum class AsciiMappingMode : std::uint8_t { Auto=0, ShapeMatch, LuminanceRamp, EdgeDirectional };
enum class AsciiChannelMode : std::uint8_t { Luma=0, Red, Green, Blue };
enum class AsciiLayoutMode : std::uint8_t { Grid=0, LiquidPanels };
enum class AsciiVisualStyle : std::uint8_t { Standard=0, CGO, Ghost, Liquid, Mosaic, Rainbow, Threshold, Micro, Organic, Photorealistic, Geometric, Glitch };
struct GlyphBitmap {
 char32_t codepoint=U' ';
 bool wordToken=false;
 bool numberToken=false;
 bool familyToken=false;
 int width=8;
 int height=8;
 float sizeScale=1.0f;
 std::vector<std::uint8_t> coverage;
 float density=0.0f;
};
struct GlyphAtlas { std::vector<GlyphBitmap> glyphs; };
struct CratesPresetDefinition {
 AsciiPresetId id; const char* name; std::uint8_t cratesCharacterSet;
 float characterSize; float characterMargin; float cellMargin; bool antiAliasing; bool invert; bool reverseOrder; bool uniformLuma;
 float tintStrength; Pixel tintColor; float invertThreshold; float smoothShading; float blendWithOriginal;
 float randomShuffle; float randomSpeed; float randomColorAmount; float xFlipThreshold;
};
const CratesPresetDefinition& cratesPreset(AsciiPresetId id) noexcept;
std::string_view asciiCharacterSetName(AsciiCharacterSetId id) noexcept;
std::u32string_view asciiCharacterSetCodepoints(AsciiCharacterSetId id) noexcept;
std::shared_ptr<const GlyphAtlas> builtinAsciiGlyphAtlas();
struct AsciiParams {
 int cellSize=8;
 float glyphScale=0.88f;
 float characterSize=100.0f;
 float presetCharacterSize=100.0f;
 float numberSize=100.0f;
 float wordSize=100.0f;
 float asciiAmount=100.0f;
 float asciiFade=0.0f;
 float asciiStrength=100.0f;
 float paletteStrength=100.0f;
 std::uint8_t paletteIndex=0;
 float characterMargin=0.0f;
 float cellMargin=0.0f;
 float contrast=1.0f;
 float brightness=0.0f;
 float randomAmount=0.85f;
 float randomSpeed=1.0f;
 float gamma=2.2f;
 float edgeThreshold=0.15f;
 AsciiMappingMode mappingMode=AsciiMappingMode::ShapeMatch;
 AsciiChannelMode channelMode=AsciiChannelMode::Luma;
 float randomTimingVariation=1.0f;
 std::uint32_t randomSeed=0;
 AsciiPresetId preset=AsciiPresetId::Default;
 AsciiCharacterSetId characterSet=AsciiCharacterSetId::CratesSpecialLetters;
 bool invert=false;
 bool reverseOrder=false;
 bool uniformLuma=false;
 bool colorize=true;
 bool preserveCellAlpha=true;
 bool antiAliasing=true;
 bool shapeMatch=false;
 bool randomCharacters=true;
 bool randomWords=true;
 bool randomTiming=true;
 bool useClipScale=false;
 bool useCharacterSize=false;
 bool useNumberSize=false;
 bool useWordSize=false;
 bool useCharacterMargin=false;
 bool ancientLetters=false, ancientNumbers=false, ancientWords=false;
 bool englishLetters=false, englishNumbers=false, englishWords=false;
 bool arabicLetters=false, arabicNumbers=false, arabicWords=false;
 bool useAncientSize=false, useEnglishSize=false, useArabicSize=false;
 float ancientSize=100.0f, englishSize=100.0f, arabicSize=100.0f;
 std::uint8_t ancientFont=1, englishFont=1, arabicFont=1;
 std::uint8_t arabicNumberStyle=0;
 float tintStrength=0.0f;
 float invertThreshold=0.5f;
 float smoothShading=0.0f;
 float blendWithOriginal=0.0f;
 float randomColorAmount=0.0f;
 float xFlipThreshold=0.0f;
 AsciiLayoutMode layoutMode=AsciiLayoutMode::Grid;
 AsciiVisualStyle visualStyle=AsciiVisualStyle::Standard;
 float thresholdLevel=0.12f;
 int thresholdSegmentWidth=32;
 int thresholdRowSpacing=8;
 int panelMinWidth=2, panelMaxWidth=5, panelMinHeight=1, panelMaxHeight=2;
 Pixel tintColor{1,1,1,1};
 Pixel ink{1,1,1,1};
 Pixel paper{0,0,0,0};
 std::shared_ptr<const GlyphAtlas> atlas;
};
void applyCratesPreset(AsciiParams& params, AsciiPresetId id) noexcept;
class AsciiEngine final : public Engine {
public:
 explicit AsciiEngine(AsciiParams p={}) noexcept : params_(std::move(p)) {}
 const char* id() const noexcept override { return "xao.ascii"; }
 void setParams(const AsciiParams& p) noexcept { params_=p; }
 const AsciiParams& params() const noexcept { return params_; }
 void setAtlas(std::shared_ptr<const GlyphAtlas> atlas) noexcept { params_.atlas=std::move(atlas); }
 void render(const Image&,Image&,const RenderContext&) const override;
private:
 AsciiParams params_;
};
} // namespace xao
