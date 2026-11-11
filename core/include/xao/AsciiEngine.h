#pragma once
#include "xao/Engine.h"
#include "xao/AsciiReferencePalettes.h"
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>
#include <vector>
namespace xao {
enum class AsciiPresetId : std::uint8_t { Default=0, AlienSignal, CirclesAndDots, Classic, Corrupted, Crossword, Diamonds, Matrix, Motherboard, PinkShapes, Count };
enum class AsciiCharacterSetId : std::uint8_t {
 CratesSpecialLetters=0, CratesSpecialNumbers, CratesTypewriter, CratesJapanese, CratesBinary,
 CratesMinimalPunk, CratesXs, CratesBubbleGrowth, CratesStars, CratesDiamonds, CratesDots,
 CratesCircuits1, CratesCircuits2, CratesAlienFont, CratesBars,
 S1Classic, S1Minimal, S1Detailed, S1Bourke, S1Braille, S1Katakana, S1Blocks, S1Quadrants, S1BoxDrawing, AsciiArtMainStandard, AsciiArtMainSimple, AsciiArtMainDetailed, Count
};
enum class AsciiMappingMode : std::uint8_t { Auto=0, ShapeMatch, LuminanceRamp, EdgeDirectional };
enum class AsciiChannelMode : std::uint8_t { Luma=0, Red, Green, Blue };
enum class AsciiGlowSelection : std::uint8_t { Random=0, FixedRegion, RandomInRegion, All };
enum class AsciiGlowGlyphFilter : std::uint8_t { All=0, Letters, Numbers, Symbols, Words };
enum class AsciiLayoutMode : std::uint8_t { Grid=0, LiquidPanels };
enum class AsciiVisualStyle : std::uint8_t { Standard=0, CGO, Ghost, Liquid, Mosaic, Rainbow, Threshold };
struct GlyphBitmap {
 char32_t codepoint=U' ';
 bool wordToken=false;
 bool numberToken=false;
 int width=8;
 int height=8;
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
 float characterSize=88.0f;
 float numberSize=100.0f;
 float wordSize=100.0f;
 std::uint8_t paletteIndex=0;
 float paletteStrength=100.0f;
 float characterMargin=0.0f;
 float cellMargin=0.0f;
 float contrast=1.0f;
 float brightness=0.0f;
 float randomAmount=0.05f;
 float randomSpeed=0.0f;
 float gamma=2.2f;
 float edgeThreshold=0.15f;
 AsciiMappingMode mappingMode=AsciiMappingMode::Auto;
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
 bool shapeMatch=true;
 bool randomCharacters=true;
 bool randomWords=false;
 bool randomTiming=false;
 bool enableAncient=false;
 bool enableEnglish=false;
 bool enableArabic=false;
 bool ancientLetters=false;
 bool ancientNumbers=false;
 bool ancientWords=false;
 bool englishLetters=false;
 bool englishNumbers=false;
 bool englishWords=false;
 bool arabicLetters=false;
 bool arabicNumbers=false;
 bool arabicWords=false;
 float tintStrength=0.0f;
 float invertThreshold=0.5f;
 float smoothShading=0.0f;
 float blendWithOriginal=0.0f;
 float randomColorAmount=0.0f;
 float xFlipThreshold=0.0f;
 bool glowEnabled=false;
 AsciiGlowSelection glowSelection=AsciiGlowSelection::Random;
 AsciiGlowGlyphFilter glowGlyphFilter=AsciiGlowGlyphFilter::All;
 AsciiLayoutMode layoutMode=AsciiLayoutMode::Grid;
 AsciiVisualStyle visualStyle=AsciiVisualStyle::Standard;
 float thresholdLevel=0.48f;
 int thresholdSegmentWidth=24;
 int thresholdRowSpacing=8;
 int panelMinWidth=1;
 int panelMaxWidth=3;
 int panelMinHeight=1;
 int panelMaxHeight=3;
 float glowIntensity=1.0f;
 float glowRadius=8.0f;
 float glowAmount=0.2f;
 float glowCenterX=0.5f;
 float glowCenterY=0.5f;
 float glowRegionSize=0.25f;
 Pixel glowColor{1.0f,0.22f,0.035f,1.0f};
 bool raysEnabled=false;
 float raysCount=18.0f;
 float raysAngle=0.0f;
 float raysSpread=360.0f;
 float raysLength=1.0f;
 float raysIntensity=1.0f;
 float raysSharpness=6.0f;
 float raysOriginX=0.5f;
 float raysOriginY=0.5f;
 Pixel raysColor{1.0f,0.42f,0.12f,1.0f};
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
private: AsciiParams params_;
};
} // namespace xao
