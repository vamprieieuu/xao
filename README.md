# XAO — ASCII engine

Native, CPU-first ASCII rendering engine with nine distinct visual presets,
embedded typography, Arabic shaping and preset-aware continuous randomization.

* Engine: `core/` (`xao::ascii::AsciiEngine`)
* After Effects adapter: `ae/` (Windows x64 `.aex`, AE 2023+)
* Embedded glyph atlas: `core/src/ascii/AtlasData.cpp` (generated)
* Reference material and prior audits: `XAO/`, `docs/`

## Build and test (core, any platform)

```sh
make -j4 all      # core library, tests, offline renderer
make test         # core tests + 129 ASCII behaviour checks
```

or with CMake:

```sh
cmake -S . -B build && cmake --build build && ctest --test-dir build
```

## Offline renderer

```sh
./build/xao_ascii_cli --list
./build/xao_ascii_cli --in frame.ppm --out out.ppm \
    --preset Liquid --cells 22 --strength 100 --time 1.5 \
    --lang english=letters,numbers,words --lang arabic=letters,words
```

## After Effects plug-in

Requires Windows x64, Visual Studio 2022 and the Adobe After Effects SDK.

```bat
cmake -S ae -B build-aex -G "Visual Studio 17 2022" -A x64 ^
      -DAE_SDK_PATH="C:/AE_SDK/AfterEffectsSDK"
cmake --build build-aex --config Release
```

The result is `build-aex/Release/XAO.aex`. See
[`docs/ASCII_ENGINE_IMPLEMENTATION.md`](docs/ASCII_ENGINE_IMPLEMENTATION.md)
for the full report, and [`docs/ASCII_TYPOGRAPHY_FONTS.md`](docs/ASCII_TYPOGRAPHY_FONTS.md)
for font provenance and licensing.

## Regenerating the glyph atlas

```sh
pip install pillow fonttools
python3 tools/build_atlas.py
```

## Controls

One `ASCII` group: Preset, ASCII Cells, ASCII Amount, ASCII Strength, Clip
Scale, Character Set, Character / Number / Word Size (each with an enable
toggle), Character Margin, Color Palette, Palette Strength, then `Random`
(Random Characters, Random Words, Random Timing, Random Seed) and the
`English`, `Arabic`, `Ancient` language sections with independent letters,
numbers, words and font selectors.
