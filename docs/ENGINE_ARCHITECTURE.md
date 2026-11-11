# XAO — Native Architecture Plan

Status: architecture proposal based on the supplied references and source audit. This is not a claim that the plug-in has been built or runtime-tested.

## 1. Product shape

XAO is one native After Effects effect plug-in (XAO.aex) with a shared render pipeline and independently selectable/stackable image engines. It is not a Photoshop UXP panel and does not require a separate runtime.

Planned engines:
- ASCII / Hybrid Glyph
- Halftone
- Dither
- Glow
- Rays
- Glint
- Array / Mosaic
- Typeset

The separate Lines effect from Dither Majid is excluded. Do not create a Lines engine, Lines tab, Lines preset family, or port core/lines.cpp. A line-shaped halftone screen remains a Halftone geometry option, not the excluded Dither effect.

## 2. Layered render model

Each engine is a processing node with enabled state, engine-specific parameters, blend/composite mode, opacity, deterministic seed where randomness is used, and quality/scale policy.

The graph executes in a stable order. The initial implementation should use a simple ordered stack rather than a general-purpose node editor. Each node reads the current working image and writes a well-defined output; source sampling and intermediate buffers are managed by the shared core.

Shared stages:
1. Validate source world, format, dimensions, row stride, time and render scale.
2. Convert source pixels into a normalized internal working representation while preserving alpha semantics.
3. Optional common pre-adjustments (luminance, contrast, saturation, color space).
4. Execute enabled engine nodes in declared order.
5. Composite each node using its opacity/blend rule.
6. Convert back to the AE output format, preserving alpha and premultiplication rules.

The working representation must explicitly document whether RGB is straight or premultiplied. No engine may silently assume one convention.

## 3. Proposed repository layout

- CMakeLists.txt and cmake/
- resources/XAO_PiPL.r
- ae/: EffectMain, parameter registration, Smart Render, pixel formats
- core/: image, color, sampling, geometry, compositing, animation, memory
- engines/: ascii, halftone, dither, glow, rays, glint, array, typeset
- typography/: font library, glyph atlas, Arabic shaping, bidi layout
- presets/ and tests/
- third_party/licenses/

Keep render algorithms independent from AE SDK types. The AE adapter should translate AE worlds/parameters into core structures and call the core renderer.

## 4. ASCII / Hybrid Glyph architecture

- Load real TTF/OTF font files; rasterize glyphs into cached atlases. Do not replace supplied font files with hand-drawn approximations.
- Separate font discovery/import from rendering. Bundle only fonts with verified redistribution rights; allow local user fonts for restricted assets.
- Use a shaping layer (HarfBuzz + FreeType, or equivalent) for Arabic joining/contextual forms and a bidi implementation for Arabic/English mixed text.
- Provide two Arabic modes: connected Arabic typography and individual Arabic glyph-art units.
- Build glyph source sets from Arabic, Latin, digits, symbols, dingbats, geometric and decorative fonts. Support weighted mixed-source sets.
- Select glyphs using brightness, local shape, edge orientation, density and region similarity; random selection is an optional seeded mode, not the only mapping.
- Render in two stages: source analysis/cell feature extraction, then glyph-atlas placement/color/compositing.
- Cache glyph atlases by font identity, face, size, glyph set, raster mode and render scale. Invalidate safely when a font or glyph configuration changes.

## 5. Engine boundaries

### Halftone
Independent screen geometry and channel separation. Candidate modes include mono, CMYK/spot-channel workflows, dot/line/square/diamond/ellipse/ring and other reference-backed shapes; layouts include square, rotated/diagonal, hex and radial where supported by the final reference set. Paper/ink colors, screen angles, dot gain, ink spread, grain, misregistration and antialiasing belong to this engine.

### Dither
Independent quantization and ordered/error-diffusion algorithms, with palette, cell scale, contrast, spread and deterministic seed controls. The Dither Majid project is a build/algorithm reference only for the algorithms selected for XAO. No standalone Lines effect or Lines module is included.

### Glow
Thresholded multi-scale bloom/glow with controllable radius, falloff, gamma, saturation, tint, source contribution and glow-only output. HaloGlow is the strongest audited native reference, subject to dependency and license preservation.

### Rays and Glint
Separate light-ray and star/glint engines. Reconstruct clean native algorithms from supplied visual references and binary behavior research; decompiler output is not production source.

### Array / Mosaic
Cell/shape layout engine with fixed spatial cells, selectable shape families, edge-aware or brightness-aware mapping, palette, scale/rotation jitter and clumping/chaos controls. Randomness must be seeded and stable over time.

### Typeset
Repeated text/word layout driven by source luminance/color, with font, text string, scale, tracking, leading, density, alignment and sampling controls. Arabic shaping and bidi must use the shared typography layer.

## 6. AE host and compatibility requirements

- Target After Effects 23.2.1 / AE 2023 on Windows 11 x64.
- Native C++ .aex, correct PiPL metadata, EffectMain, parameter registration and parameter count.
- PiPL version and C++ PF_VERSION must be generated from one source of truth.
- PiPL OutFlags/OutFlags2 must match PF_Cmd_GLOBAL_SETUP.
- Support 8/16/32 bpc where each engine is validated; unsupported combinations must fail cleanly rather than corrupt output.
- Smart Pre-render/Smart Render must validate checkout results, request/result rectangles, rowbytes, dimensions, callbacks and allocations.
- Correct alpha and premultiplication handling, bounds expansion for spatial effects, deterministic time/seed behavior, and MFR/thread safety.
- CPU path is mandatory. GPU acceleration is optional and must never be a hardware requirement.
- CI checks binary architecture, exports, PiPL resources and packaging. These checks do not replace actual AE load/apply/render tests.

## 7. Validation gates

1. Core unit tests for color, sampling, glyph mapping, Arabic shaping, geometry, compositing and deterministic animation.
2. Golden-image tests using fixed reference frames and documented tolerances.
3. Pixel-format tests for 8/16/32 bpc and alpha edge cases.
4. Bounds and SmartFX tests, including non-zero origins and cropped render windows.
5. Performance tests on CPU-only hardware and large frames.
6. Windows x64 Release build and package validation.
7. Actual AE 2023 runtime tests: install, launch, apply, change parameters, scrub time, render, duplicate layers, MFR on/off and repeated open/close.

A feature is not marked complete until it passes its relevant gates.
