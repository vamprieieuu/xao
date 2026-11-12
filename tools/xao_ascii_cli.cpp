// Offline ASCII renderer used by the automated visual comparisons.
//
// Reads a binary PPM (P6) image, renders it with the XAO ASCII engine and
// writes a PPM.  The same code path the After Effects plug-in uses is
// exercised here, so a comparison render is a real engine render.

#include "xao/ascii/AsciiEngine.h"
#include "xao/ascii/Atlas.h"
#include "xao/ascii/GlyphSets.h"
#include "xao/ascii/Palette.h"
#include "xao/ascii/Shaping.h"

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

namespace {

using namespace xao;
using namespace xao::ascii;

bool readPpm(const char* path, Image& image) {
    std::FILE* file = std::fopen(path, "rb");
    if (file == nullptr) return false;
    char magic[3] = {0, 0, 0};
    if (std::fscanf(file, "%2s", magic) != 1 || std::strcmp(magic, "P6") != 0) {
        std::fclose(file);
        return false;
    }
    auto nextInt = [&file]() -> long {
        int c = std::fgetc(file);
        while (c != EOF) {
            if (c == '#') {
                while (c != EOF && c != '\n') c = std::fgetc(file);
            } else if (!std::isspace(c)) {
                break;
            }
            c = std::fgetc(file);
        }
        long value = 0;
        while (c != EOF && std::isdigit(c)) {
            value = value * 10 + (c - '0');
            c = std::fgetc(file);
        }
        return value;
    };
    const long w = nextInt();
    const long h = nextInt();
    const long maxValue = nextInt();
    if (w <= 0 || h <= 0 || maxValue <= 0 || maxValue > 255) {
        std::fclose(file);
        return false;
    }
    image.reset(static_cast<int>(w), static_cast<int>(h));
    std::vector<unsigned char> buffer(static_cast<std::size_t>(w) *
                                      static_cast<std::size_t>(h) * 3u);
    if (std::fread(buffer.data(), 1, buffer.size(), file) != buffer.size()) {
        std::fclose(file);
        return false;
    }
    std::fclose(file);
    for (long i = 0; i < w * h; ++i) {
        Pixel& p = image.pixels()[static_cast<std::size_t>(i)];
        p.r = buffer[static_cast<std::size_t>(i) * 3 + 0] / 255.0f;
        p.g = buffer[static_cast<std::size_t>(i) * 3 + 1] / 255.0f;
        p.b = buffer[static_cast<std::size_t>(i) * 3 + 2] / 255.0f;
        p.a = 1.0f;
    }
    return true;
}

bool writePpm(const char* path, const Image& image) {
    std::FILE* file = std::fopen(path, "wb");
    if (file == nullptr) return false;
    std::fprintf(file, "P6\n%d %d\n255\n", image.width(), image.height());
    std::vector<unsigned char> buffer(image.pixels().size() * 3u);
    for (std::size_t i = 0; i < image.pixels().size(); ++i) {
        const Pixel& p = image.pixels()[i];
        buffer[i * 3 + 0] = static_cast<unsigned char>(p.r * 255.0f + 0.5f);
        buffer[i * 3 + 1] = static_cast<unsigned char>(p.g * 255.0f + 0.5f);
        buffer[i * 3 + 2] = static_cast<unsigned char>(p.b * 255.0f + 0.5f);
    }
    std::fwrite(buffer.data(), 1, buffer.size(), file);
    std::fclose(file);
    return true;
}

std::string lower(std::string s) {
    for (char& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    return s;
}

Preset parsePreset(const std::string& name) {
    const std::string n = lower(name);
    for (int i = 0; i < presetCount(); ++i) {
        const Preset p = static_cast<Preset>(i);
        std::string candidate = lower(presetName(p));
        std::string compact;
        for (char c : candidate) if (c != ' ') compact.push_back(c);
        std::string key;
        for (char c : n) if (c != ' ' && c != '_') key.push_back(c);
        if (key == compact) return p;
    }
    if (n == "cgo") return Preset::Cgo;
    return Preset::Default;
}

Palette parsePalette(const std::string& name) {
    const std::string n = lower(name);
    for (int i = 0; i < static_cast<int>(Palette::Count); ++i) {
        if (n == lower(paletteName(static_cast<Palette>(i)))) return static_cast<Palette>(i);
    }
    if (n == "source") return Palette::Source;
    return Palette::Source;
}

Charset parseCharset(const std::string& name) {
    const std::string n = lower(name);
    for (int i = 0; i < static_cast<int>(Charset::Count); ++i) {
        if (n == lower(charsetName(static_cast<Charset>(i)))) return static_cast<Charset>(i);
    }
    return Charset::Auto;
}

void parseLanguage(const std::string& spec, LanguageSettings& lang) {
    // language=letters,numbers,words:fontIndex
    std::string flags = spec;
    std::string font;
    const std::size_t colon = spec.find(':');
    if (colon != std::string::npos) {
        flags = spec.substr(0, colon);
        font = spec.substr(colon + 1);
    }
    lang.letters = flags.find("letters") != std::string::npos;
    lang.numbers = flags.find("numbers") != std::string::npos;
    lang.words = flags.find("words") != std::string::npos;
    if (!font.empty()) lang.font = std::atoi(font.c_str());
}

void usage() {
    std::printf(
        "xao_ascii_cli --in input.ppm --out output.ppm [options]\n"
        "  --preset NAME        Default|Alien Signal|Liquid|Ghost|CGO|Mosaic|\n"
        "                       Rainbow|Threshold|Organic\n"
        "  --cells N            cell size in pixels (default 16)\n"
        "  --amount F           ASCII amount 0..1 (default 1)\n"
        "  --strength F         0..500 (default 100)\n"
        "  --clip F             plate scale 0..1 (default 1)\n"
        "  --margin F           glyph margin 0..1 (default 0)\n"
        "  --charset NAME       character set override\n"
        "  --palette NAME       palette\n"
        "  --palette-strength F 0..1\n"
        "  --char-size F         --number-size F        --word-size F\n"
        "  --no-char-size       --no-number-size        --no-word-size\n"
        "  --lang english=SPEC  --lang arabic=SPEC      --lang ancient=SPEC\n"
        "                       SPEC is letters,numbers,words[:fontIndex]\n"
        "  --time S             absolute time in seconds (default 0)\n"
        "  --seed N             deterministic seed\n"
        "  --random-timing F    0..100 (default 15)\n"
        "  --no-random-chars    --no-random-words\n"
        "  --reverse            reverse ramp order\n"
        "  --list               print presets, charsets and faces\n");
}

} // namespace

int main(int argc, char** argv) {
    const char* inPath = nullptr;
    const char* outPath = nullptr;
    AsciiParams params;
    RenderContext context;
    context.timeSeconds = 0.0;

    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];
        auto value = [&](const char* name) -> std::string {
            if (i + 1 >= argc) {
                std::fprintf(stderr, "missing value for %s\n", name);
                std::exit(2);
            }
            return argv[++i];
        };
        auto number = [&](const char* name) -> float {
            return static_cast<float>(std::atof(value(name).c_str()));
        };
        if (arg == "--in") inPath = argv[++i];
        else if (arg == "--out") outPath = argv[++i];
        else if (arg == "--preset") params.preset = parsePreset(value("--preset"));
        else if (arg == "--cells") params.cells = number("--cells");
        else if (arg == "--amount") params.amount = number("--amount");
        else if (arg == "--strength") params.strength = number("--strength");
        else if (arg == "--clip") params.clipScale = number("--clip");
        else if (arg == "--margin") params.margin = number("--margin");
        else if (arg == "--charset") params.charset = parseCharset(value("--charset"));
        else if (arg == "--palette") params.palette = parsePalette(value("--palette"));
        else if (arg == "--palette-strength") params.paletteStrength = number("--palette-strength");
        else if (arg == "--char-size") params.characters.scale = number("--char-size");
        else if (arg == "--number-size") params.numbers.scale = number("--number-size");
        else if (arg == "--word-size") params.words.scale = number("--word-size");
        else if (arg == "--no-char-size") params.characters.enabled = false;
        else if (arg == "--no-number-size") params.numbers.enabled = false;
        else if (arg == "--no-word-size") params.words.enabled = false;
        else if (arg == "--time") context.timeSeconds = std::atof(value("--time").c_str());
        else if (arg == "--seed") params.seed = static_cast<std::uint64_t>(std::strtoull(value("--seed").c_str(), nullptr, 10));
        else if (arg == "--random-timing") params.randomTiming = number("--random-timing");
        else if (arg == "--no-random-chars") params.randomCharacters = false;
        else if (arg == "--no-random-words") params.randomWords = false;
        else if (arg == "--reverse") params.reverse = true;
        else if (arg == "--lang") {
            const std::string spec = value("--lang");
            const std::size_t eq = spec.find('=');
            const std::string which = eq == std::string::npos ? spec : spec.substr(0, eq);
            const std::string rest = eq == std::string::npos ? "" : spec.substr(eq + 1);
            if (which == "arabic") parseLanguage(rest, params.arabic);
            else if (which == "ancient") parseLanguage(rest, params.ancient);
            else parseLanguage(rest, params.english);
        } else if (arg == "--list") {
            std::printf("presets:\n");
            for (int p = 0; p < presetCount(); ++p)
                std::printf("  %d %s\n", p, presetName(static_cast<Preset>(p)));
            std::printf("charsets:\n");
            for (int c = 0; c < static_cast<int>(Charset::Count); ++c)
                std::printf("  %d %s\n", c, charsetName(static_cast<Charset>(c)));
            std::printf("faces:\n");
            for (int f = 0; f < faceCount(); ++f)
                std::printf("  %d %s (%s)\n", f, faceName(f), faceScript(f));
            return 0;
        } else if (arg == "--help" || arg == "-h") {
            usage();
            return 0;
        } else {
            std::fprintf(stderr, "unknown argument: %s\n", arg.c_str());
            usage();
            return 2;
        }
    }

    if (inPath == nullptr || outPath == nullptr) {
        usage();
        return 2;
    }

    Image source;
    if (!readPpm(inPath, source)) {
        std::fprintf(stderr, "cannot read %s\n", inPath);
        return 1;
    }
    Image destination(source.width(), source.height());
    const AsciiRenderStats stats = renderAscii(source, destination, context, params);
    if (!writePpm(outPath, destination)) {
        std::fprintf(stderr, "cannot write %s\n", outPath);
        return 1;
    }
    std::printf("preset=%s cells=%d grid=%dx%d glyphs=%d ink=%.3f\n",
                presetName(params.preset), static_cast<int>(params.cells),
                stats.cellsAcross, stats.cellsDown, stats.glyphsDrawn,
                stats.inkCoverage);
    return 0;
}
