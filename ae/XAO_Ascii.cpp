// XAO ASCII — native After Effects effect plug-in (Windows x64, AE 2023+).
//
// All rendering lives in the XAO core (core/src/ascii).  This file is only the
// host adapter: parameter registration, pixel-format conversion and the render
// entry point.
//
// Audited and corrected against the After Effects SDK headers in
// vamprieieuu/Dithering_MAJEED_build_ready (extern/AfterEffectsSDK):
//
//  * PF_VERSION takes five arguments (vers, subvers, bugvers, stage, build).
//  * Groups use PF_ADD_TOPIC / PF_END_TOPIC; this SDK has no PF_ADD_GROUP.
//  * PF_ADD_SLIDER stores an integer in u.sd.value (PF_Param_FIX_SLIDER, which
//    would use u.fd/u.fs_d, is a different parameter type entirely).
//  * out_data->num_params must include the implicit input-layer parameter.
//  * There is no PF_WORLD_IS_DEEP16.  8/16/32-bpc detection goes through
//    PF_WorldSuite2::PF_GetPixelFormat, which is the SDK's declared API.
//  * Iterate suites take (in_data, base, final, src, area, refcon, pix_fn, dst).
//  * PF_OutData has no about_dialog_string; PF_Cmd_ABOUT fills return_msg.
//  * There is no PF_OutFlag2_SUPPORTS_THREADED_RENDERING in this SDK; the
//    declared flag is PF_OutFlag2_I_AM_THREADSAFE.
//
// Design notes that matter for stability:
//  * No output extent is declared, so AE hands over the whole layer and the
//    cell grid is always anchored to the layer, never to a render tile.
//  * No sequence data, no persistent state, no mutable globals: every render
//    allocates its own buffers, so multi-frame rendering is safe.
//  * Parameter ids are a single continuous enum (XAO_Ascii.h) that includes
//    group markers, so the registered count always matches the enum.

#include "AE_Effect.h"
#include "AE_EffectCB.h"
#include "AE_EffectCBSuites.h"
#include "AE_EffectPixelFormat.h"
#include "AE_Macros.h"
#include "Param_Utils.h"

#include "XAO_Ascii.h"

#include "xao/ascii/AsciiEngine.h"
#include "xao/ascii/Atlas.h"
#include "xao/ascii/GlyphSets.h"

#include <cstdio>
#include <new>
#include <string>

// The PiPL is generated from these same numbers (ae/pipl_gen.py); these
// assertions are what keeps the resource and GlobalSetup from drifting.
static_assert(PF_VERSION(XAO_VERSION_MAJOR, XAO_VERSION_MINOR, XAO_VERSION_BUG,
                         XAO_VERSION_STAGE, XAO_VERSION_BUILD) ==
                  XAO_PIPL_EFFECT_VERSION,
              "XAO_PIPL_EFFECT_VERSION must match PF_VERSION(...)");

static_assert((PF_OutFlag_DEEP_COLOR_AWARE | PF_OutFlag_SEND_UPDATE_PARAMS_UI) ==
                  XAO_PIPL_OUT_FLAGS,
              "PiPL AE_Effect_Global_OutFlags must match GlobalSetup");

static_assert((PF_OutFlag2_I_AM_THREADSAFE | PF_OutFlag2_FLOAT_COLOR_AWARE) ==
                  XAO_PIPL_OUT_FLAGS2,
              "PiPL AE_Effect_Global_OutFlags_2 must match GlobalSetup");

static_assert(XAO_NUM_PARAMS == XAO_PARAM_ASCII_GROUP_END + 1,
              "num_params must count slot 0 (the implicit layer) plus every id");

namespace {

using xao::ascii::AsciiParams;
using xao::ascii::ScriptId;

// ---------------------------------------------------------------------------
// Parameter access
// ---------------------------------------------------------------------------

int popupValue(PF_ParamDef* params[], int id) {
    // PF_ADD_POPUP stores a 1-based choice index.
    return static_cast<int>(params[id]->u.pd.value) - 1;
}

float sliderValue(PF_ParamDef* params[], int id) {
    // PF_ADD_SLIDER registers PF_Param_SLIDER: an integer in u.sd.value.
    return static_cast<float>(params[id]->u.sd.value);
}

bool checkboxValue(PF_ParamDef* params[], int id) {
    return params[id]->u.bd.value != 0;
}

const char* kPresetItems =
    "Default|Alien Signal|Liquid|Ghost|CGO|Mosaic|Rainbow|Threshold|Organic";

const char* kCharsetItems =
    "Auto|Special Characters and Letters|Special Characters and Numbers|"
    "Classic Typewriter|Binary|Minimal Punk|X's|Bubble Growth|Stars|Diamonds|"
    "Dots|Circuits 1|Circuits 2|Alien Font|Bars|Blocks";

const char* kPaletteItems =
    "Source Color|Ember|Cream|Sand|Navy|Chroma|Grey|Acid|Mono|Terminal|Gold|"
    "Ice|Infrared|Vapor";

// Font menus are built from the embedded faces, so a menu can never offer a
// face that is not compiled into the plug-in.
std::string faceMenu(ScriptId script) {
    std::string items;
    const int count = xao::ascii::faceCountForScript(script);
    for (int i = 0; i < count; ++i) {
        if (!items.empty()) items += "|";
        items += xao::ascii::scriptFaceName(script, i);
    }
    return items.empty() ? std::string("Default") : items;
}

int faceMenuCount(ScriptId script) {
    const int count = xao::ascii::faceCountForScript(script);
    return count > 0 ? count : 1;
}

// ---------------------------------------------------------------------------
// Suite access
//
// PF suites are acquired from the host's SPBasicSuite, which is already in
// PF_InData.  Only two are needed, and both are released before returning.
// ---------------------------------------------------------------------------

template <typename Suite>
Suite* acquirePFS(PF_InData* in_data, const char* name, int version) {
    if (in_data == nullptr || in_data->pica_basicP == nullptr) return nullptr;
    const void* suite = nullptr;
    if (in_data->pica_basicP->AcquireSuite(name, version, &suite) != 0) {
        return nullptr;
    }
    return const_cast<Suite*>(static_cast<const Suite*>(suite));
}

void releasePFS(PF_InData* in_data, const char* name, int version) {
    if (in_data != nullptr && in_data->pica_basicP != nullptr) {
        in_data->pica_basicP->ReleaseSuite(name, version);
    }
}

// 8/16/32-bpc detection.  The SDK has no PF_WORLD_IS_DEEP16 (only
// PF_WORLD_IS_DEEP for 32-bpc float), so the declared pixel-format query is the
// only reliable way to tell 8-bit from 16-bit.
PF_Err pixelFormatOf(PF_InData* in_data, const PF_EffectWorld* world,
                     PF_PixelFormat* format) {
    if (format == nullptr) return PF_Err_BAD_CALLBACK_PARAM;
    *format = PF_PixelFormat_INVALID;
    PF_WorldSuite2* suite =
        acquirePFS<PF_WorldSuite2>(in_data, kPFWorldSuite, kPFWorldSuiteVersion2);
    if (suite == nullptr) return PF_Err_INTERNAL_STRUCT_DAMAGED;
    const PF_Err err = suite->PF_GetPixelFormat(world, format);
    releasePFS(in_data, kPFWorldSuite, kPFWorldSuiteVersion2);
    return err;
}

// ---------------------------------------------------------------------------
// Pixel conversion
//
// The core works in normalised RGBA floats (1.0 == white) and the presets were
// designed and validated against that convention, so the adapter scales channel
// values and nothing else.  Values are not premultiplied or gamma-converted
// here; doing so would change the approved look of every preset.
// ---------------------------------------------------------------------------

struct ReadContext {
    xao::Image* image = nullptr;
};

PF_Err readPixel8(void* refcon, A_long x, A_long y, PF_Pixel* in, PF_Pixel* out) {
    ReadContext* ctx = static_cast<ReadContext*>(refcon);
    xao::Pixel& p = ctx->image->at(static_cast<int>(x), static_cast<int>(y));
    const float scale = 1.0f / 255.0f;
    p.a = in->alpha * scale;
    p.r = in->red * scale;
    p.g = in->green * scale;
    p.b = in->blue * scale;
    (void)out;
    return PF_Err_NONE;
}

PF_Err readPixel16(void* refcon, A_long x, A_long y, PF_Pixel16* in, PF_Pixel16* out) {
    ReadContext* ctx = static_cast<ReadContext*>(refcon);
    xao::Pixel& p = ctx->image->at(static_cast<int>(x), static_cast<int>(y));
    const float scale = 1.0f / static_cast<float>(PF_MAX_CHAN16);
    p.a = in->alpha * scale;
    p.r = in->red * scale;
    p.g = in->green * scale;
    p.b = in->blue * scale;
    (void)out;
    return PF_Err_NONE;
}

PF_Err readPixelFloat(void* refcon, A_long x, A_long y, PF_PixelFloat* in,
                      PF_PixelFloat* out) {
    ReadContext* ctx = static_cast<ReadContext*>(refcon);
    xao::Pixel& p = ctx->image->at(static_cast<int>(x), static_cast<int>(y));
    p.a = in->alpha;
    p.r = in->red;
    p.g = in->green;
    p.b = in->blue;
    (void)out;
    return PF_Err_NONE;
}

struct WriteContext {
    const xao::Image* image = nullptr;
};

PF_Err writePixel8(void* refcon, A_long x, A_long y, PF_Pixel* in, PF_Pixel* out) {
    const WriteContext* ctx = static_cast<const WriteContext*>(refcon);
    const xao::Pixel& p = ctx->image->at(static_cast<int>(x), static_cast<int>(y));
    out->alpha = static_cast<A_u_char>(p.a * 255.0f + 0.5f);
    out->red = static_cast<A_u_char>(p.r * 255.0f + 0.5f);
    out->green = static_cast<A_u_char>(p.g * 255.0f + 0.5f);
    out->blue = static_cast<A_u_char>(p.b * 255.0f + 0.5f);
    (void)in;
    return PF_Err_NONE;
}

PF_Err writePixel16(void* refcon, A_long x, A_long y, PF_Pixel16* in, PF_Pixel16* out) {
    const WriteContext* ctx = static_cast<const WriteContext*>(refcon);
    const xao::Pixel& p = ctx->image->at(static_cast<int>(x), static_cast<int>(y));
    const float scale = static_cast<float>(PF_MAX_CHAN16);
    out->alpha = static_cast<A_u_short>(p.a * scale + 0.5f);
    out->red = static_cast<A_u_short>(p.r * scale + 0.5f);
    out->green = static_cast<A_u_short>(p.g * scale + 0.5f);
    out->blue = static_cast<A_u_short>(p.b * scale + 0.5f);
    (void)in;
    return PF_Err_NONE;
}

PF_Err writePixelFloat(void* refcon, A_long x, A_long y, PF_PixelFloat* in,
                       PF_PixelFloat* out) {
    const WriteContext* ctx = static_cast<const WriteContext*>(refcon);
    const xao::Pixel& p = ctx->image->at(static_cast<int>(x), static_cast<int>(y));
    out->alpha = p.a;
    out->red = p.r;
    out->green = p.g;
    out->blue = p.b;
    (void)in;
    return PF_Err_NONE;
}

// ---------------------------------------------------------------------------
// Host commands
// ---------------------------------------------------------------------------

PF_Err About(PF_InData* in_data, PF_OutData* out_data) {
    // PF_OutData has no about dialog string member in this SDK; PF_Cmd_ABOUT is
    // answered through return_msg.
    std::snprintf(out_data->return_msg, sizeof(out_data->return_msg),
                  "%s %d.%d.%d (build %d)\r"
                  "Unified ASCII engine: nine render presets, embedded fonts, "
                  "Arabic shaping, English and ancient glyph systems.",
                  XAO_ASCII_NAME, XAO_VERSION_MAJOR, XAO_VERSION_MINOR,
                  XAO_VERSION_BUG, XAO_VERSION_BUILD);
    (void)in_data;
    return PF_Err_NONE;
}

PF_Err GlobalSetup(PF_InData* in_data, PF_OutData* out_data) {
    out_data->my_version = PF_VERSION(XAO_VERSION_MAJOR, XAO_VERSION_MINOR,
                                      XAO_VERSION_BUG, XAO_VERSION_STAGE,
                                      XAO_VERSION_BUILD);

    // Must match XAO_PIPL_OUT_FLAGS / XAO_PIPL_OUT_FLAGS2 (asserted above).
    out_data->out_flags = PF_OutFlag_DEEP_COLOR_AWARE |
                          PF_OutFlag_SEND_UPDATE_PARAMS_UI;
    out_data->out_flags2 = PF_OutFlag2_I_AM_THREADSAFE |
                           PF_OutFlag2_FLOAT_COLOR_AWARE;
    (void)in_data;
    return PF_Err_NONE;
}

PF_Err ParamsSetup(PF_InData* in_data, PF_OutData* out_data, PF_ParamDef* params[]) {
    PF_ParamDef def;

    const std::string englishFonts = faceMenu(ScriptId::English);
    const std::string arabicFonts = faceMenu(ScriptId::Arabic);
    const std::string ancientFonts = faceMenu(ScriptId::Ancient);

    AEFX_CLR_STRUCT(def);
    PF_ADD_TOPIC("ASCII", XAO_PARAM_ASCII_GROUP);

    AEFX_CLR_STRUCT(def);
    PF_ADD_POPUP("Preset", xao::ascii::presetCount(),
                 static_cast<int>(xao::ascii::Preset::Default) + 1,
                 const_cast<char*>(kPresetItems), XAO_PARAM_PRESET);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("ASCII Cells", 2, 200, 2, 200, 16, XAO_PARAM_CELLS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("ASCII Amount", 0, 100, 0, 100, 100, XAO_PARAM_AMOUNT);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("ASCII Strength", 0, 500, 0, 500, 100, XAO_PARAM_STRENGTH);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("Clip Scale", 5, 100, 5, 100, 100, XAO_PARAM_CLIP_SCALE);

    AEFX_CLR_STRUCT(def);
    PF_ADD_POPUP("Character Set", static_cast<int>(xao::ascii::Charset::Count),
                 1, const_cast<char*>(kCharsetItems), XAO_PARAM_CHARSET);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Enable Character Size", "", TRUE, 0,
                    XAO_PARAM_CHAR_SIZE_ENABLE);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("Character Size", 10, 300, 10, 300, 100, XAO_PARAM_CHAR_SIZE);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Enable Number Size", "", TRUE, 0,
                    XAO_PARAM_NUMBER_SIZE_ENABLE);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("Number Size", 10, 300, 10, 300, 100, XAO_PARAM_NUMBER_SIZE);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Enable Word Size", "", TRUE, 0, XAO_PARAM_WORD_SIZE_ENABLE);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("Word Size", 10, 300, 10, 300, 100, XAO_PARAM_WORD_SIZE);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("Character Margin", 0, 100, 0, 100, 0, XAO_PARAM_MARGIN);

    AEFX_CLR_STRUCT(def);
    PF_ADD_POPUP("Color Palette", static_cast<int>(xao::ascii::Palette::Count),
                 1, const_cast<char*>(kPaletteItems), XAO_PARAM_PALETTE);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("Palette Strength", 0, 100, 0, 100, 0,
                  XAO_PARAM_PALETTE_STRENGTH);

    // --- Random (inside ASCII, directly below the main controls) -----------
    AEFX_CLR_STRUCT(def);
    PF_ADD_TOPIC("Random", XAO_PARAM_RANDOM_GROUP);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Random Characters", "", TRUE, 0, XAO_PARAM_RANDOM_CHARS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Random Words", "", TRUE, 0, XAO_PARAM_RANDOM_WORDS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("Random Timing", 0, 100, 0, 100, 15, XAO_PARAM_RANDOM_TIMING);

    AEFX_CLR_STRUCT(def);
    PF_ADD_SLIDER("Random Seed", 0, 100000, 0, 100000, 1234, XAO_PARAM_SEED);

    AEFX_CLR_STRUCT(def);
    PF_END_TOPIC(XAO_PARAM_RANDOM_GROUP_END);

    // --- English ----------------------------------------------------------
    AEFX_CLR_STRUCT(def);
    PF_ADD_TOPIC("English", XAO_PARAM_ENGLISH_GROUP);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("English Letters", "", TRUE, 0, XAO_PARAM_ENGLISH_LETTERS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("English Numbers", "", TRUE, 0, XAO_PARAM_ENGLISH_NUMBERS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("English Words", "", FALSE, 0, XAO_PARAM_ENGLISH_WORDS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_POPUP("English Font", faceMenuCount(ScriptId::English), 1,
                 const_cast<char*>(englishFonts.c_str()),
                 XAO_PARAM_ENGLISH_FONT);

    AEFX_CLR_STRUCT(def);
    PF_END_TOPIC(XAO_PARAM_ENGLISH_GROUP_END);

    // --- Arabic -----------------------------------------------------------
    AEFX_CLR_STRUCT(def);
    PF_ADD_TOPIC("Arabic", XAO_PARAM_ARABIC_GROUP);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Arabic Letters", "", FALSE, 0, XAO_PARAM_ARABIC_LETTERS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Arabic Numbers", "", FALSE, 0, XAO_PARAM_ARABIC_NUMBERS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Arabic Words", "", FALSE, 0, XAO_PARAM_ARABIC_WORDS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_POPUP("Arabic Font", faceMenuCount(ScriptId::Arabic), 1,
                 const_cast<char*>(arabicFonts.c_str()), XAO_PARAM_ARABIC_FONT);

    AEFX_CLR_STRUCT(def);
    PF_END_TOPIC(XAO_PARAM_ARABIC_GROUP_END);

    // --- Ancient ----------------------------------------------------------
    AEFX_CLR_STRUCT(def);
    PF_ADD_TOPIC("Ancient", XAO_PARAM_ANCIENT_GROUP);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Ancient Letters", "", FALSE, 0, XAO_PARAM_ANCIENT_LETTERS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Ancient Numbers", "", FALSE, 0, XAO_PARAM_ANCIENT_NUMBERS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_CHECKBOX("Ancient Words", "", FALSE, 0, XAO_PARAM_ANCIENT_WORDS);

    AEFX_CLR_STRUCT(def);
    PF_ADD_POPUP("Ancient Font", faceMenuCount(ScriptId::Ancient), 1,
                 const_cast<char*>(ancientFonts.c_str()), XAO_PARAM_ANCIENT_FONT);

    AEFX_CLR_STRUCT(def);
    PF_END_TOPIC(XAO_PARAM_ANCIENT_GROUP_END);

    AEFX_CLR_STRUCT(def);
    PF_END_TOPIC(XAO_PARAM_ASCII_GROUP_END);

    // Slot 0 is AE's implicit input layer, so the count is last id + 1.
    out_data->num_params = XAO_NUM_PARAMS;
    (void)in_data;
    (void)params;
    return PF_Err_NONE;
}

AsciiParams readParams(PF_ParamDef* params[]) {
    AsciiParams p;

    const int preset = popupValue(params, XAO_PARAM_PRESET);
    if (preset >= 0 && preset < xao::ascii::presetCount()) {
        p.preset = static_cast<xao::ascii::Preset>(preset);
    }

    p.cells = sliderValue(params, XAO_PARAM_CELLS);
    p.amount = sliderValue(params, XAO_PARAM_AMOUNT) / 100.0f;
    p.strength = sliderValue(params, XAO_PARAM_STRENGTH);
    p.clipScale = sliderValue(params, XAO_PARAM_CLIP_SCALE) / 100.0f;

    const int charset = popupValue(params, XAO_PARAM_CHARSET);
    if (charset >= 0 && charset < static_cast<int>(xao::ascii::Charset::Count)) {
        p.charset = static_cast<xao::ascii::Charset>(charset);
    }

    p.characters.enabled = checkboxValue(params, XAO_PARAM_CHAR_SIZE_ENABLE);
    p.characters.scale = sliderValue(params, XAO_PARAM_CHAR_SIZE) / 100.0f;
    p.numbers.enabled = checkboxValue(params, XAO_PARAM_NUMBER_SIZE_ENABLE);
    p.numbers.scale = sliderValue(params, XAO_PARAM_NUMBER_SIZE) / 100.0f;
    p.words.enabled = checkboxValue(params, XAO_PARAM_WORD_SIZE_ENABLE);
    p.words.scale = sliderValue(params, XAO_PARAM_WORD_SIZE) / 100.0f;
    p.margin = sliderValue(params, XAO_PARAM_MARGIN) / 100.0f;

    const int palette = popupValue(params, XAO_PARAM_PALETTE);
    if (palette >= 0 && palette < static_cast<int>(xao::ascii::Palette::Count)) {
        p.palette = static_cast<xao::ascii::Palette>(palette);
    }
    p.paletteStrength = sliderValue(params, XAO_PARAM_PALETTE_STRENGTH) / 100.0f;

    p.randomCharacters = checkboxValue(params, XAO_PARAM_RANDOM_CHARS);
    p.randomWords = checkboxValue(params, XAO_PARAM_RANDOM_WORDS);
    p.randomTiming = sliderValue(params, XAO_PARAM_RANDOM_TIMING);
    p.seed = static_cast<std::uint64_t>(
        static_cast<long>(sliderValue(params, XAO_PARAM_SEED)));

    p.english.letters = checkboxValue(params, XAO_PARAM_ENGLISH_LETTERS);
    p.english.numbers = checkboxValue(params, XAO_PARAM_ENGLISH_NUMBERS);
    p.english.words = checkboxValue(params, XAO_PARAM_ENGLISH_WORDS);
    p.english.font = popupValue(params, XAO_PARAM_ENGLISH_FONT);

    p.arabic.letters = checkboxValue(params, XAO_PARAM_ARABIC_LETTERS);
    p.arabic.numbers = checkboxValue(params, XAO_PARAM_ARABIC_NUMBERS);
    p.arabic.words = checkboxValue(params, XAO_PARAM_ARABIC_WORDS);
    p.arabic.font = popupValue(params, XAO_PARAM_ARABIC_FONT);

    p.ancient.letters = checkboxValue(params, XAO_PARAM_ANCIENT_LETTERS);
    p.ancient.numbers = checkboxValue(params, XAO_PARAM_ANCIENT_NUMBERS);
    p.ancient.words = checkboxValue(params, XAO_PARAM_ANCIENT_WORDS);
    p.ancient.font = popupValue(params, XAO_PARAM_ANCIENT_FONT);

    return p;
}

PF_Err Render(PF_InData* in_data, PF_OutData* out_data, PF_ParamDef* params[],
              PF_LayerDef* output) {
    PF_Err err = PF_Err_NONE;

    if (output == nullptr) return PF_Err_BAD_CALLBACK_PARAM;

    const AsciiParams asciiParams = readParams(params);
    PF_LayerDef* input = &params[0]->u.ld;

    const int width = static_cast<int>(output->width);
    const int height = static_cast<int>(output->height);
    if (width <= 0 || height <= 0) return PF_Err_NONE;

    xao::Image source(width, height);
    xao::Image destination(width, height);

    ReadContext readCtx;
    readCtx.image = &source;
    WriteContext writeCtx;
    writeCtx.image = &destination;

    PF_PixelFormat format = PF_PixelFormat_INVALID;
    err = pixelFormatOf(in_data, output, &format);
    if (err != PF_Err_NONE) return err;

    // Pass 1: copy the host's pixels into normalised floats.
    // Pass 2: write the rendered floats back.  Both passes iterate src=input
    // into dst=output, so no NULL destination is ever passed to the host.
    switch (format) {
        case PF_PixelFormat_ARGB64:
            err = PF_ITERATE16(0, height, input, nullptr, &readCtx, readPixel16, output);
            if (err == PF_Err_NONE) {
                err = PF_ITERATE16(0, height, input, nullptr, &writeCtx, writePixel16, output);
            }
            break;

        case PF_PixelFormat_ARGB128: {
            PF_IterateFloatSuite1* suite = acquirePFS<PF_IterateFloatSuite1>(
                in_data, kPFIterateFloatSuite, kPFIterateFloatSuiteVersion1);
            if (suite == nullptr) return PF_Err_INTERNAL_STRUCT_DAMAGED;
            err = suite->iterate(in_data, 0, height, input, nullptr, &readCtx,
                                 readPixelFloat, output);
            if (err == PF_Err_NONE) {
                err = suite->iterate(in_data, 0, height, input, nullptr, &writeCtx,
                                     writePixelFloat, output);
            }
            releasePFS(in_data, kPFIterateFloatSuite, kPFIterateFloatSuiteVersion1);
            break;
        }

        case PF_PixelFormat_ARGB32:
        default:
            err = PF_ITERATE(0, height, input, nullptr, &readCtx, readPixel8, output);
            if (err == PF_Err_NONE) {
                err = PF_ITERATE(0, height, input, nullptr, &writeCtx, writePixel8, output);
            }
            break;
    }
    if (err != PF_Err_NONE) return err;

    xao::RenderContext context;
    context.timeSeconds = in_data->time_scale > 0
                              ? static_cast<double>(in_data->current_time) /
                                    static_cast<double>(in_data->time_scale)
                              : 0.0;
    context.frame = in_data->current_time;
    context.renderScale = 1.0f;
    context.seed = asciiParams.seed;

    xao::ascii::renderAscii(source, destination, context, asciiParams);

    (void)out_data;
    return PF_Err_NONE;
}

PF_Err UserChangedParam(PF_InData* in_data, PF_OutData* out_data,
                        PF_ParamDef* params[], const PF_UserChangedParamExtra* extra) {
    // Preset changes can alter which language controls are meaningful; ask AE
    // to refresh the UI.  No parameter values are rewritten.
    out_data->out_flags |= PF_OutFlag_REFRESH_UI;
    (void)in_data;
    (void)params;
    (void)extra;
    return PF_Err_NONE;
}

PF_Err UpdateParamsUi(PF_InData* in_data, PF_OutData* out_data,
                      PF_ParamDef* params[]) {
    (void)in_data;
    (void)params;
    out_data->out_flags |= PF_OutFlag_REFRESH_UI;
    return PF_Err_NONE;
}

} // namespace

extern "C" __declspec(dllexport) PF_Err EffectMain(PF_Cmd cmd, PF_InData* in_data,
                                                   PF_OutData* out_data,
                                                   PF_ParamDef* params[],
                                                   PF_LayerDef* output,
                                                   void* extra) {
    PF_Err err = PF_Err_NONE;
    try {
        switch (cmd) {
            case PF_Cmd_ABOUT:
                err = About(in_data, out_data);
                break;
            case PF_Cmd_GLOBAL_SETUP:
                err = GlobalSetup(in_data, out_data);
                break;
            case PF_Cmd_PARAMS_SETUP:
                err = ParamsSetup(in_data, out_data, params);
                break;
            case PF_Cmd_RENDER:
                err = Render(in_data, out_data, params, output);
                break;
            case PF_Cmd_USER_CHANGED_PARAM:
                err = UserChangedParam(
                    in_data, out_data, params,
                    reinterpret_cast<const PF_UserChangedParamExtra*>(extra));
                break;
            case PF_Cmd_UPDATE_PARAMS_UI:
                err = UpdateParamsUi(in_data, out_data, params);
                break;
            case PF_Cmd_SEQUENCE_SETUP:
            case PF_Cmd_SEQUENCE_RESETUP:
            case PF_Cmd_SEQUENCE_FLATTEN:
            case PF_Cmd_SEQUENCE_SETDOWN:
                // No sequence data is stored.
                break;
            default:
                break;
        }
    } catch (const std::bad_alloc&) {
        err = PF_Err_OUT_OF_MEMORY;
    } catch (...) {
        err = PF_Err_INTERNAL_STRUCT_DAMAGED;
    }
    return err;
}
