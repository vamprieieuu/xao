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

Requires Windows x64, Visual Studio 2022 and an After Effects SDK laid out as
`Headers/` and `Util/` — the layout used by
[`vamprieieuu/Dithering_MAJEED_build_ready`](https://github.com/vamprieieuu/Dithering_MAJEED_build_ready/tree/main/extern/AfterEffectsSDK).
The old `Examples/Headers` + `PiPLtool.exe` layout is not used.

```bat
cmake -S ae -B build-aex -G "Visual Studio 17 2022" -A x64 ^
      -DAE_SDK_PATH="C:/path/to/AfterEffectsSDK"
cmake --build build-aex --config Release
python tools/verify_aex.py build-aex/bin/Release/XAO.aex --header ae/XAO_Ascii.h
```

The result is `build-aex/bin/Release/XAO.aex`. The PiPL resource is generated
from `ae/XAO_Ascii.h` by `ae/pipl_gen.py` (no `PiPLtool`), and the verifier
checks the PE machine/subsystem, the `EffectMain` export, the PiPL resource and
that the resource's out-flags equal the ones `PF_Cmd_GLOBAL_SETUP` declares.
`.github/workflows/ascii-engine.yml` runs the whole sequence on
`windows-latest` from a pinned checkout of the SDK headers.

See
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
