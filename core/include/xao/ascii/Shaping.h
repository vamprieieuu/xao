#pragma once

// Arabic script support: joining/contextual shaping, right-to-left layout and
// Arabic-Indic / Persian numeral conversion.
//
// Shaping maps base Arabic letters to the Unicode Arabic Presentation Forms
// (block FE70..FEFF and the Persian letters in FB50..FDFF) that the embedded
// faces contain, so connected letter forms render correctly without a
// HarfBuzz-class shaping engine in the render path.

#include "xao/ascii/Text.h"

namespace xao {
namespace ascii {

enum class ArabicForm : int { Isolated = 0, Final, Initial, Medial };

// How a letter joins to its neighbours.  Right-joining letters connect only to
// the preceding letter (which sits to their right in RTL text).
enum class JoiningType : int { NonJoining = 0, RightJoining, DualJoining, Transparent };

struct ShapedArabic {
    Codepoint codepoint = 0;  // presentation form actually drawn
    Codepoint base = 0;       // original base letter (or ligature marker)
    ArabicForm form = ArabicForm::Isolated;
};

bool isArabicCodepoint(Codepoint cp);
bool isArabicDiacritic(Codepoint cp);
JoiningType joiningType(Codepoint cp);
ArabicForm formFor(Codepoint base, bool joinPrevious, bool joinNext);

// Shape a logical-order Arabic run.  Non-Arabic codepoints pass through
// unchanged and break joining.
std::vector<ShapedArabic> shapeArabic(const Text& logical);

// Shape + reorder a mixed Arabic/Latin run into visual (drawing) order.
// Latin and numeric sub-runs keep their own left-to-right order; Arabic runs
// are emitted right-to-left.
Text layoutVisual(const Text& logical);

// Convert ASCII digits 0-9 to Arabic-Indic (U+0660..) or Persian (U+06F0..).
Text toArabicIndicDigits(const Text& asciiDigits, bool persian);

} // namespace ascii
} // namespace xao
