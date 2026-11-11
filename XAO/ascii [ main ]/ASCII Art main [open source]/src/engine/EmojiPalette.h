#pragma once

#include "engine/Color.h"

#include <initializer_list>
#include <string>
#include <string_view>

namespace asciicam::engine {

/// Pick an emoji for a colour category. @p variety selects among the themed
/// options so adjacent same-colour cells don't all look identical; callers
/// typically pass a per-cell index.
///
/// Neutral returns a space — the mapper is expected to substitute an ASCII ramp
/// glyph for neutral cells to preserve structural detail.
[[nodiscard]] inline std::string pickEmoji(ColorCategory cat, int variety) {
    const auto choose = [variety](std::initializer_list<std::string_view> options) {
        const int n = static_cast<int>(options.size());
        const int i = ((variety % n) + n) % n;  // safe for negative variety
        return std::string(*(options.begin() + i));
    };

    switch (cat) {
        case ColorCategory::Red:
            return choose({"❤️", "\U0001F352", "\U0001F339", "\U0001F460"});  // ❤️ 🍒 🌹 👠
        case ColorCategory::Orange:
            return choose({"\U0001F9E1", "\U0001F34A", "\U0001F525", "\U0001F98A"});  // 🧡 🍊 🔥 🦊
        case ColorCategory::Yellow:
            return choose({"\U0001F49B", "⭐", "\U0001F31F", "\U0001F34B"});  // 💛 ⭐ 🌟 🍋
        case ColorCategory::Green:
            return choose({"\U0001F49A", "\U0001F33F", "\U0001F340", "\U0001F438"});  // 💚 🌿 🍀 🐸
        case ColorCategory::Cyan:
            return choose({"\U0001FA75", "\U0001F4A7", "\U0001F9CA"});  // 🩵 💧 🧊
        case ColorCategory::Blue:
            return choose({"\U0001F499", "\U0001F30A", "\U0001FAD0", "\U0001F537"});  // 💙 🌊 🫐 🔷
        case ColorCategory::Purple:
            return choose({"\U0001F49C", "\U0001F52E", "\U0001F347", "\U0001F7E3"});  // 💜 🔮 🍇 🟣
        case ColorCategory::Pink:
            return choose({"\U0001F496", "\U0001F338", "\U0001F380", "\U0001F497"});  // 💖 🌸 🎀 💗
        case ColorCategory::Neutral:
        default:
            return " ";
    }
}

}  // namespace asciicam::engine
