#pragma once

// Minimal UTF-8 / UTF-32 helpers plus deterministic hashing shared by the
// ASCII engine.  No locale, no platform services: the engine must behave
// identically inside After Effects and in the test harness.

#include <cstdint>
#include <string>
#include <vector>

namespace xao {
namespace ascii {

using Codepoint = std::uint32_t;
using Text = std::vector<Codepoint>;

Text decodeUtf8(const std::string& utf8);
std::string encodeUtf8(const Text& text);
std::string encodeUtf8(Codepoint codepoint);

// 64-bit mix (splitmix64 finalizer).  Cheap and stable across platforms.
std::uint64_t hashMix(std::uint64_t value);

// Deterministic cell hash: seed, absolute time bucket, cell coordinates and a
// pass salt.  Stateless, so Smart Render may evaluate frames in any order.
std::uint64_t cellHash(std::uint64_t seed, std::uint32_t timeBucket,
                       std::int32_t cellX, std::int32_t cellY,
                       std::uint32_t salt);

// Maps a hash to [0, 1).
inline float unitFloat(std::uint64_t h) {
    return static_cast<float>(h >> 40) * (1.0f / 16777216.0f);
}

// Maps a hash to [0, bound).
inline std::uint32_t boundedInt(std::uint64_t h, std::uint32_t bound) {
    if (bound == 0) return 0;
    return static_cast<std::uint32_t>((h >> 32) % bound);
}

} // namespace ascii
} // namespace xao
