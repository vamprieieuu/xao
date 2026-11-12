#pragma once

// Shared constants for the XAO ASCII After Effects plug-in.
//
// Everything that has to agree between the C++ entry point and the binary PiPL
// resource lives in this one header.  ae/pipl_gen.py parses the XAO_PIPL_*
// defines to emit the resource, and ae/XAO_Ascii.cpp static_asserts those same
// numbers against the SDK's own macros, so the resource can never disagree with
// PF_Cmd_GLOBAL_SETUP.
//
// Audited against the After Effects SDK shipped in
// vamprieieuu/Dithering_MAJEED_build_ready (extern/AfterEffectsSDK).

#define XAO_ASCII_NAME        "XAO ASCII"
#define XAO_ASCII_MATCH_NAME  "XAO ASCII"
#define XAO_ASCII_CATEGORY    "XAO"

// PF_VERSION(vers, subvers, bugvers, stage, build) takes five arguments.
// XAO_VERSION_BUG is the 'bugvers' (bug-fix) field and must not be dropped.
#define XAO_VERSION_MAJOR 1
#define XAO_VERSION_MINOR 0
#define XAO_VERSION_BUG   0
#define XAO_VERSION_STAGE 0   /* PF_Stage_DEVELOP */
#define XAO_VERSION_BUILD 1

// PiPL AE_Effect_Version, laid out exactly like PF_VERSION():
// (vers << 19) | (subvers << 15) | (bugfix << 11) | (stage << 9) | build.
// XAO_Ascii.cpp asserts this equals PF_VERSION(...) at compile time.
#define XAO_PIPL_EFFECT_VERSION 0x00080001

// PiPL AE_Effect_Global_OutFlags / _2.  These must equal the flags that
// PF_Cmd_GLOBAL_SETUP sets:
//   PF_OutFlag_DEEP_COLOR_AWARE        (1 << 25)
//   PF_OutFlag_SEND_UPDATE_PARAMS_UI   (1 << 26)
//   PF_OutFlag2_I_AM_THREADSAFE        (1 << 4)
//   PF_OutFlag2_FLOAT_COLOR_AWARE      (1 << 12)
// XAO_Ascii.cpp holds static_asserts for both.
#define XAO_PIPL_OUT_FLAGS  0x06000000
#define XAO_PIPL_OUT_FLAGS2 0x00000010

// AE_PiPL_Version and AE_Effect_Spec_Version entries of the PiPL.
#define XAO_PIPL_VERSION_MAJOR 2
#define XAO_PIPL_VERSION_MINOR 0
#define XAO_PIPL_SPEC_MAJOR    13
#define XAO_PIPL_SPEC_MINOR    28

#define XAO_PIPL_SUPPORT_URL "https://github.com/vamprieieuu/xao"

// Parameter slots, in registration order.  Group start/end markers are real
// parameters in After Effects and therefore consume a slot.  Slot 0 is the
// implicit input-layer parameter that AE adds itself; ids below start at 1 and
// are contiguous.
enum XaoParamId {
    XAO_PARAM_ASCII_GROUP = 1,      // PF_ADD_TOPIC "ASCII"
    XAO_PARAM_PRESET,
    XAO_PARAM_CELLS,
    XAO_PARAM_AMOUNT,
    XAO_PARAM_STRENGTH,
    XAO_PARAM_CLIP_SCALE,
    XAO_PARAM_CHARSET,
    XAO_PARAM_CHAR_SIZE_ENABLE,
    XAO_PARAM_CHAR_SIZE,
    XAO_PARAM_NUMBER_SIZE_ENABLE,
    XAO_PARAM_NUMBER_SIZE,
    XAO_PARAM_WORD_SIZE_ENABLE,
    XAO_PARAM_WORD_SIZE,
    XAO_PARAM_MARGIN,
    XAO_PARAM_PALETTE,
    XAO_PARAM_PALETTE_STRENGTH,

    XAO_PARAM_RANDOM_GROUP,          // PF_ADD_TOPIC "Random"
    XAO_PARAM_RANDOM_CHARS,
    XAO_PARAM_RANDOM_WORDS,
    XAO_PARAM_RANDOM_TIMING,
    XAO_PARAM_SEED,
    XAO_PARAM_RANDOM_GROUP_END,      // PF_END_TOPIC "Random"

    XAO_PARAM_ENGLISH_GROUP,         // PF_ADD_TOPIC "English"
    XAO_PARAM_ENGLISH_LETTERS,
    XAO_PARAM_ENGLISH_NUMBERS,
    XAO_PARAM_ENGLISH_WORDS,
    XAO_PARAM_ENGLISH_FONT,
    XAO_PARAM_ENGLISH_GROUP_END,

    XAO_PARAM_ARABIC_GROUP,          // PF_ADD_TOPIC "Arabic"
    XAO_PARAM_ARABIC_LETTERS,
    XAO_PARAM_ARABIC_NUMBERS,
    XAO_PARAM_ARABIC_WORDS,
    XAO_PARAM_ARABIC_FONT,
    XAO_PARAM_ARABIC_GROUP_END,

    XAO_PARAM_ANCIENT_GROUP,         // PF_ADD_TOPIC "Ancient"
    XAO_PARAM_ANCIENT_LETTERS,
    XAO_PARAM_ANCIENT_NUMBERS,
    XAO_PARAM_ANCIENT_WORDS,
    XAO_PARAM_ANCIENT_FONT,
    XAO_PARAM_ANCIENT_GROUP_END,

    XAO_PARAM_ASCII_GROUP_END        // PF_END_TOPIC "ASCII"
};

// The SDK documents that out_data->num_params "MUST include the implicit main
// layer parameter", which occupies index 0.  Ids run 1..XAO_PARAM_ASCII_GROUP_END,
// so the registered count is the last id plus one.
#define XAO_NUM_PARAMS (XAO_PARAM_ASCII_GROUP_END + 1)
