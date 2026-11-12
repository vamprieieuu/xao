#include "xao/ascii/Text.h"

namespace xao {
namespace ascii {

Text decodeUtf8(const std::string& utf8) {
    Text out;
    out.reserve(utf8.size());
    std::size_t i = 0;
    const std::size_t n = utf8.size();
    while (i < n) {
        const unsigned char c = static_cast<unsigned char>(utf8[i]);
        Codepoint cp = 0;
        std::size_t extra = 0;
        if (c < 0x80) {
            cp = c;
        } else if ((c & 0xE0) == 0xC0) {
            cp = c & 0x1F;
            extra = 1;
        } else if ((c & 0xF0) == 0xE0) {
            cp = c & 0x0F;
            extra = 2;
        } else if ((c & 0xF8) == 0xF0) {
            cp = c & 0x07;
            extra = 3;
        } else {
            out.push_back(0xFFFD);
            ++i;
            continue;
        }
        if (i + extra >= n) {
            out.push_back(0xFFFD);
            break;
        }
        bool ok = true;
        for (std::size_t k = 1; k <= extra; ++k) {
            const unsigned char cc = static_cast<unsigned char>(utf8[i + k]);
            if ((cc & 0xC0) != 0x80) {
                ok = false;
                break;
            }
            cp = (cp << 6) | (cc & 0x3F);
        }
        if (!ok) {
            out.push_back(0xFFFD);
            ++i;
            continue;
        }
        out.push_back(cp);
        i += extra + 1;
    }
    return out;
}

std::string encodeUtf8(Codepoint cp) {
    std::string out;
    if (cp <= 0x7F) {
        out.push_back(static_cast<char>(cp));
    } else if (cp <= 0x7FF) {
        out.push_back(static_cast<char>(0xC0 | (cp >> 6)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else if (cp <= 0xFFFF) {
        out.push_back(static_cast<char>(0xE0 | (cp >> 12)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else {
        out.push_back(static_cast<char>(0xF0 | (cp >> 18)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    }
    return out;
}

std::string encodeUtf8(const Text& text) {
    std::string out;
    for (Codepoint cp : text) out += encodeUtf8(cp);
    return out;
}

std::uint64_t hashMix(std::uint64_t value) {
    value += 0x9E3779B97F4A7C15ull;
    value = (value ^ (value >> 30)) * 0xBF58476D1CE4E5B9ull;
    value = (value ^ (value >> 27)) * 0x94D049BB133111EBull;
    return value ^ (value >> 31);
}

std::uint64_t cellHash(std::uint64_t seed, std::uint32_t timeBucket,
                       std::int32_t cellX, std::int32_t cellY,
                       std::uint32_t salt) {
    std::uint64_t h = hashMix(seed);
    h = hashMix(h ^ (static_cast<std::uint64_t>(timeBucket) * 0x9E3779B1ull));
    h = hashMix(h ^ (static_cast<std::uint64_t>(static_cast<std::uint32_t>(cellX)) * 0x85EBCA6Bull));
    h = hashMix(h ^ (static_cast<std::uint64_t>(static_cast<std::uint32_t>(cellY)) * 0xC2B2AE35ull));
    h = hashMix(h ^ (static_cast<std::uint64_t>(salt) * 0x27D4EB2Full));
    return h;
}

} // namespace ascii
} // namespace xao
