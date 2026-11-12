#include "xao/ascii/Shaping.h"

#include <algorithm>

namespace xao {
namespace ascii {

namespace {

struct ArabicEntry {
    Codepoint base;
    Codepoint isolated;
    Codepoint finalForm;
    Codepoint initial;
    Codepoint medial;
    JoiningType type;
};

// Unicode Arabic Presentation Forms-B layout (block FE70..FEFF) plus the
// Persian letters whose forms live in Presentation Forms-A.
const ArabicEntry kTable[] = {
    {0x0621, 0xFE80, 0x0000, 0x0000, 0x0000, JoiningType::NonJoining},
    {0x0622, 0xFE81, 0xFE82, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0623, 0xFE83, 0xFE84, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0624, 0xFE85, 0xFE86, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0625, 0xFE87, 0xFE88, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0626, 0xFE89, 0xFE8A, 0xFE8B, 0xFE8C, JoiningType::DualJoining},
    {0x0627, 0xFE8D, 0xFE8E, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0628, 0xFE8F, 0xFE90, 0xFE91, 0xFE92, JoiningType::DualJoining},
    {0x0629, 0xFE93, 0xFE94, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x062A, 0xFE95, 0xFE96, 0xFE97, 0xFE98, JoiningType::DualJoining},
    {0x062B, 0xFE99, 0xFE9A, 0xFE9B, 0xFE9C, JoiningType::DualJoining},
    {0x062C, 0xFE9D, 0xFE9E, 0xFE9F, 0xFEA0, JoiningType::DualJoining},
    {0x062D, 0xFEA1, 0xFEA2, 0xFEA3, 0xFEA4, JoiningType::DualJoining},
    {0x062E, 0xFEA5, 0xFEA6, 0xFEA7, 0xFEA8, JoiningType::DualJoining},
    {0x062F, 0xFEA9, 0xFEAA, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0630, 0xFEAB, 0xFEAC, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0631, 0xFEAD, 0xFEAE, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0632, 0xFEAF, 0xFEB0, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0633, 0xFEB1, 0xFEB2, 0xFEB3, 0xFEB4, JoiningType::DualJoining},
    {0x0634, 0xFEB5, 0xFEB6, 0xFEB7, 0xFEB8, JoiningType::DualJoining},
    {0x0635, 0xFEB9, 0xFEBA, 0xFEBB, 0xFEBC, JoiningType::DualJoining},
    {0x0636, 0xFEBD, 0xFEBE, 0xFEBF, 0xFEC0, JoiningType::DualJoining},
    {0x0637, 0xFEC1, 0xFEC2, 0xFEC3, 0xFEC4, JoiningType::DualJoining},
    {0x0638, 0xFEC5, 0xFEC6, 0xFEC7, 0xFEC8, JoiningType::DualJoining},
    {0x0639, 0xFEC9, 0xFECA, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x063A, 0xFECB, 0xFECC, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0641, 0xFECD, 0xFECE, 0xFECF, 0xFED0, JoiningType::DualJoining},
    {0x0642, 0xFED1, 0xFED2, 0xFED3, 0xFED4, JoiningType::DualJoining},
    {0x0643, 0xFED5, 0xFED6, 0xFED7, 0xFED8, JoiningType::DualJoining},
    {0x0644, 0xFED9, 0xFEDA, 0xFEDB, 0xFEDC, JoiningType::DualJoining},
    {0x0645, 0xFEDD, 0xFEDE, 0xFEDF, 0xFEE0, JoiningType::DualJoining},
    {0x0646, 0xFEE1, 0xFEE2, 0xFEE3, 0xFEE4, JoiningType::DualJoining},
    {0x0647, 0xFEE5, 0xFEE6, 0xFEE7, 0xFEE8, JoiningType::DualJoining},
    {0x0648, 0xFEE9, 0xFEEA, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x0649, 0xFEED, 0xFEEE, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x064A, 0xFEF1, 0xFEF2, 0xFEF3, 0xFEF4, JoiningType::DualJoining},
    // Tatweel always joins and is drawn as itself.
    {0x0640, 0x0640, 0x0640, 0x0640, 0x0640, JoiningType::DualJoining},
    {0x0671, 0xFB50, 0xFB51, 0x0000, 0x0000, JoiningType::RightJoining},
    // Persian / Urdu letters (Presentation Forms-A).
    {0x067E, 0xFB56, 0xFB57, 0xFB58, 0xFB59, JoiningType::DualJoining},
    {0x0686, 0xFB7A, 0xFB7B, 0xFB7C, 0xFB7D, JoiningType::DualJoining},
    {0x0698, 0xFB8A, 0xFB8B, 0x0000, 0x0000, JoiningType::RightJoining},
    {0x06A9, 0xFB8E, 0xFB8F, 0xFB90, 0xFB91, JoiningType::DualJoining},
    {0x06AF, 0xFB92, 0xFB93, 0xFB94, 0xFB95, JoiningType::DualJoining},
    {0x06CC, 0xFBFC, 0xFBFD, 0xFBFE, 0xFBFF, JoiningType::DualJoining},
};

const ArabicEntry* lookup(Codepoint cp) {
    for (const ArabicEntry& e : kTable) {
        if (e.base == cp) return &e;
    }
    return nullptr;
}

// Lam + alef ligatures: {alef, isolatedLigature, finalLigature}
struct LamAlef { Codepoint alef; Codepoint isolated; Codepoint finalForm; };
const LamAlef kLamAlef[] = {
    {0x0622, 0xFEF5, 0xFEF6},
    {0x0623, 0xFEF7, 0xFEF8},
    {0x0625, 0xFEF9, 0xFEFA},
    {0x0627, 0xFEFB, 0xFEFC},
};

const LamAlef* lamAlefFor(Codepoint alef) {
    for (const LamAlef& l : kLamAlef) {
        if (l.alef == alef) return &l;
    }
    return nullptr;
}

bool isArabicBlock(Codepoint cp) {
    return (cp >= 0x0600 && cp <= 0x06FF) ||
           (cp >= 0x0750 && cp <= 0x077F) ||
           (cp >= 0x08A0 && cp <= 0x08FF);
}

bool isPresentationForm(Codepoint cp) {
    return (cp >= 0xFB50 && cp <= 0xFDFF) || (cp >= 0xFE70 && cp <= 0xFEFF);
}

} // namespace

bool isArabicCodepoint(Codepoint cp) {
    return isArabicBlock(cp) || isPresentationForm(cp);
}

bool isArabicDiacritic(Codepoint cp) {
    // Harakat, Quranic marks and superscript alef.
    return (cp >= 0x064B && cp <= 0x065F) || cp == 0x0670 ||
           (cp >= 0x06D6 && cp <= 0x06ED) || cp == 0x0653 || cp == 0x0654 ||
           cp == 0x0655;
}

JoiningType joiningType(Codepoint cp) {
    if (isArabicDiacritic(cp)) return JoiningType::Transparent;
    if (const ArabicEntry* e = lookup(cp)) return e->type;
    if (isPresentationForm(cp) || isArabicBlock(cp)) return JoiningType::NonJoining;
    return JoiningType::NonJoining;
}

ArabicForm formFor(Codepoint base, bool joinPrevious, bool joinNext) {
    const ArabicEntry* e = lookup(base);
    if (e == nullptr) return ArabicForm::Isolated;
    if (e->type == JoiningType::DualJoining) {
        if (joinPrevious && joinNext) return ArabicForm::Medial;
        if (joinNext) return ArabicForm::Initial;
        if (joinPrevious) return ArabicForm::Final;
        return ArabicForm::Isolated;
    }
    if (e->type == JoiningType::RightJoining) {
        return joinPrevious ? ArabicForm::Final : ArabicForm::Isolated;
    }
    return ArabicForm::Isolated;
}

std::vector<ShapedArabic> shapeArabic(const Text& logical) {
    std::vector<ShapedArabic> out;
    out.reserve(logical.size());

    const std::size_t n = logical.size();
    std::size_t i = 0;
    while (i < n) {
        const Codepoint cp = logical[i];

        if (isArabicDiacritic(cp)) {
            ShapedArabic s;
            s.codepoint = cp;
            s.base = cp;
            s.form = ArabicForm::Isolated;
            out.push_back(s);
            ++i;
            continue;
        }

        if (!isArabicCodepoint(cp)) {
            ShapedArabic s;
            s.codepoint = cp;
            s.base = cp;
            s.form = ArabicForm::Isolated;
            out.push_back(s);
            ++i;
            continue;
        }

        // Previous joining context skips transparent marks.
        bool joinPrevious = false;
        for (std::size_t k = out.size(); k > 0;) {
            --k;
            const Codepoint prev = out[k].base;
            if (isArabicDiacritic(prev)) continue;
            joinPrevious = joiningType(prev) == JoiningType::DualJoining;
            break;
        }

        // Next joining context, also skipping transparent marks.
        std::size_t nextIndex = i + 1;
        while (nextIndex < n && isArabicDiacritic(logical[nextIndex])) ++nextIndex;
        const bool hasNext = nextIndex < n;
        const JoiningType nextType =
            hasNext ? joiningType(logical[nextIndex]) : JoiningType::NonJoining;

        // Lam + alef ligature.
        if (cp == 0x0644 && hasNext) {
            if (const LamAlef* lig = lamAlefFor(logical[nextIndex])) {
                ShapedArabic s;
                // The ligature consumes both letters; the joining context that
                // follows is the alef's, which never connects forward.  Keeping
                // the alef here is what makes a following letter isolated.
                s.base = logical[nextIndex];
                s.form = joinPrevious ? ArabicForm::Final : ArabicForm::Isolated;
                s.codepoint = joinPrevious ? lig->finalForm : lig->isolated;
                out.push_back(s);
                i = nextIndex + 1;
                continue;
            }
        }

        const ArabicEntry* e = lookup(cp);
        const JoiningType selfType = e ? e->type : JoiningType::NonJoining;
        const bool joinNext = (selfType == JoiningType::DualJoining) && hasNext &&
                              (nextType == JoiningType::DualJoining ||
                               nextType == JoiningType::RightJoining);

        ShapedArabic s;
        s.base = cp;
        s.form = formFor(cp, joinPrevious, joinNext);
        s.codepoint = cp;
        if (e != nullptr) {
            switch (s.form) {
                case ArabicForm::Isolated: s.codepoint = e->isolated; break;
                case ArabicForm::Final: s.codepoint = e->finalForm; break;
                case ArabicForm::Initial: s.codepoint = e->initial; break;
                case ArabicForm::Medial: s.codepoint = e->medial; break;
            }
        }
        out.push_back(s);
        ++i;
    }
    return out;
}

Text layoutVisual(const Text& logical) {
    const std::vector<ShapedArabic> shaped = shapeArabic(logical);

    // Split into directional segments.  A segment is pure Arabic (RTL) or
    // everything else (LTR).  Numbers inside Arabic text therefore stay
    // readable while the Arabic runs are emitted right-to-left.
    struct Segment {
        bool rtl = false;
        Text glyphs;
    };
    std::vector<Segment> segments;
    bool anyArabic = false;
    for (const ShapedArabic& s : shaped) {
        const bool rtl = isArabicCodepoint(s.base);
        if (segments.empty() || segments.back().rtl != rtl) {
            Segment seg;
            seg.rtl = rtl;
            segments.push_back(seg);
        }
        segments.back().glyphs.push_back(s.codepoint);
        anyArabic = anyArabic || rtl;
    }

    if (!anyArabic) {
        Text out;
        for (const Segment& s : segments) {
            out.insert(out.end(), s.glyphs.begin(), s.glyphs.end());
        }
        return out;
    }

    // Right-to-left paragraph: emit segments from last to first, reversing the
    // glyph order inside Arabic segments.
    Text out;
    out.reserve(shaped.size());
    for (std::size_t k = segments.size(); k > 0; --k) {
        const Segment& s = segments[k - 1];
        if (s.rtl) {
            out.insert(out.end(), s.glyphs.rbegin(), s.glyphs.rend());
        } else {
            out.insert(out.end(), s.glyphs.begin(), s.glyphs.end());
        }
    }
    return out;
}

Text toArabicIndicDigits(const Text& asciiDigits, bool persian) {
    Text out;
    out.reserve(asciiDigits.size());
    const Codepoint zero = persian ? 0x06F0 : 0x0660;
    for (Codepoint cp : asciiDigits) {
        if (cp >= '0' && cp <= '9') {
            out.push_back(zero + (cp - '0'));
        } else {
            out.push_back(cp);
        }
    }
    return out;
}

} // namespace ascii
} // namespace xao
