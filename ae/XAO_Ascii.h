#pragma once

// Shared constants for the XAO ASCII After Effects plug-in.
//
// The PiPL version and PF_VERSION come from this one header so they can never
// drift apart (a classic cause of "effect does not load" failures), and the
// parameter enum lists every parameter slot in registration order, including
// group markers, so the parameter count can never disagree with setup.

#define XAO_ASCII_NAME        "XAO ASCII"
#define XAO_ASCII_MATCH_NAME  "XAO ASCII"
#define XAO_ASCII_CATEGORY    "XAO"

#define XAO_VERSION_MAJOR 1
#define XAO_VERSION_MINOR 0
#define XAO_VERSION_BUG   0
#define XAO_VERSION_STAGE PF_Stage_DEVELOP
#define XAO_VERSION_BUILD 1

// Parameter slots, in registration order.  Group start/end markers are
// parameters in AE and therefore take a slot.
enum XaoParamId {
    XAO_PARAM_ASCII_GROUP = 1,      // group start "ASCII"
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

    XAO_PARAM_RANDOM_GROUP,          // group start "Random"
    XAO_PARAM_RANDOM_CHARS,
    XAO_PARAM_RANDOM_WORDS,
    XAO_PARAM_RANDOM_TIMING,
    XAO_PARAM_SEED,
    XAO_PARAM_RANDOM_GROUP_END,      // group end "Random"

    XAO_PARAM_ENGLISH_GROUP,         // group start "English"
    XAO_PARAM_ENGLISH_LETTERS,
    XAO_PARAM_ENGLISH_NUMBERS,
    XAO_PARAM_ENGLISH_WORDS,
    XAO_PARAM_ENGLISH_FONT,
    XAO_PARAM_ENGLISH_GROUP_END,

    XAO_PARAM_ARABIC_GROUP,          // group start "Arabic"
    XAO_PARAM_ARABIC_LETTERS,
    XAO_PARAM_ARABIC_NUMBERS,
    XAO_PARAM_ARABIC_WORDS,
    XAO_PARAM_ARABIC_FONT,
    XAO_PARAM_ARABIC_GROUP_END,

    XAO_PARAM_ANCIENT_GROUP,         // group start "Ancient"
    XAO_PARAM_ANCIENT_LETTERS,
    XAO_PARAM_ANCIENT_NUMBERS,
    XAO_PARAM_ANCIENT_WORDS,
    XAO_PARAM_ANCIENT_FONT,
    XAO_PARAM_ANCIENT_GROUP_END,

    XAO_PARAM_ASCII_GROUP_END        // group end "ASCII"
};

#define XAO_NUM_PARAMS (XAO_PARAM_ASCII_GROUP_END)
