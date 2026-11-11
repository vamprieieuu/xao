# XAO Rays and Halftone Source Audit — Pass 63

Date: 2026-11-10  
Source: supplied `XAO.zip`, folders `rays/` and `halftone/`

## Executive decision

The supplied archive contains no clearly reusable, licensed native Rays implementation. The Rays AEX files are binaries accompanied by decompiler output; the inspected Rays wrapper dynamically loads a companion BCCPlus DLL and dispatches commands through that proprietary bundle. The Sapphire Rays decompilation likewise exposes Sapphire runtime loading. These are reference-only, not code sources.

The Halftone folder is richer. It contains one small native AE SDK C++ implementation (Meatbags/Halftone), several web/Photoshop/Python implementations, and proprietary Sapphire binaries. The native C++ source is promising technically, but no license file was found in its supplied folder; do not copy it into XAO until the upstream license is confirmed. The other implementations have varying license and runtime restrictions.

## 1. Rays: binary/decompilation boundary

Inspected:
- `rays/aex/Rays.aex`, `S_Rays.aex`
- `rays/c+/Rays.aex.c/.h`, `S_Rays.aex.c/.h`

The decompiled `Rays.aex.c` wrapper's entry path derives a companion DLL name `BCCPlus.dll`, loads it with `LoadLibraryExA`, resolves `get_driver_handle` and `do_command`, and forwards effect commands to that driver. This establishes that the archived binary is not a self-contained source implementation of a Rays algorithm.

The `S_Rays.aex.c` decompilation contains Sapphire DLL loading and a Sapphire failure string. It is likewise a proprietary runtime wrapper, not an open implementation.

No source licence for these binaries/decompilations was found in the inspected Rays folder. Therefore:
- Do not copy decompiled code, constants, tables, or reconstructed proprietary implementation.
- Use only independently documented visual behavior as a reference.
- A native XAO Rays engine must be designed from first principles or built from a separately licensed source whose actual code and licence are verified.

## 2. Native AE Halftone — Meatbags/Halftone

Supplied files:
- `Halftone.cpp`, `Halftone.hpp`, `HalftoneSampler.hpp`, `HalftoneVector.hpp`, `HalftonePiPL.r`
- Existing `binaries/halftone.aex`

README describes a native After Effects colour-halftone effect, 8/16-bit support, tested in CC 15, and instructs building with the AE SDK CC 2015. The code directly uses AE SDK pixel structures and samples source pixels around rotated screen grids.

Source-level observations:
- Three independently angled RGB/CMY channel samplers are used.
- Dot/screen geometry includes round, square, Euclidean, ellipse, line, diamond and flower shape constants.
- The sampler computes screen/grid positions, samples source neighborhoods, and writes channel output; 8-bit and 16-bit paths are present.
- The 8-bit routine copies source alpha and writes RGB channels from independent samplers.
- The 16-bit routine also preserves alpha and samples three channel screens.
- The code uses AE pixel/world rowbytes to address pixels in the source.
- The processor and sampler are tightly coupled to AE SDK types and this older plugin's parameter/build model.

**Licence status:** no LICENSE file was present in the supplied `Halftone master [open source]` folder, and its README does not state a reuse licence. The word “open source” in the folder name and availability of source do not grant redistribution rights. Treat as reference-only until the upstream repository's licence is verified.

**Technical fit:** the best native AE halftone architecture candidate in this archive, but it is an old CC 2015-era implementation. Before any port, review its complete parameter registration, render selectors, bounds, pixel formats, threading, and sampling edge behavior against XAO's AE 2023 SmartFX/MFR contract.

## 3. Halftone Studio — Photoshop UXP

The supplied `Halftone ps` folder identifies itself as a Photoshop UXP plugin. README describes AM and FM halftone screens, independent per-ink angles, CMYK rosette, 24 dither algorithms, editable colour-separated fill layers, active-selection support, batch processing and SVG output.

Its source includes distinct modules for:
- halftone generation and shape geometry;
- CMYK separation and colour processing;
- resampling, jitter, preprocessing and tonemapping;
- dithering and palette quantization;
- SVG and Photoshop document/layer integration.

This is useful analytical material for screen geometry, per-ink separation, AM/FM behavior and test cases. It is not a runtime candidate: XAO must not depend on Photoshop UXP, JavaScript modules, Photoshop imaging APIs or browser UI. The supplied folder does not expose a clear top-level licence file in the inspected listing; do not copy its code unless the upstream licence is verified. Port only independently specified algorithms after licence review.

## 4. Halftone Dean — Python/PySide6 desktop app

The folder contains a full Python/PySide6 application and an explicit MIT licence (Orvlyn, 2026). README lists 13 styles, four grid layouts, mono/4/6/8-channel separation, tone controls, grain/bleed/distortion FX, palettes and presets.

The renderer uses NumPy/Pillow and the app depends on Python, PySide6 and external image libraries. It is not suitable as an XAO runtime or direct native C++ integration. The MIT licence permits reuse subject to preserving notices, but any selected algorithm still needs an isolated source audit and independent C++ port; do not introduce Python, Qt or Pillow into XAO.

## 5. Halftone Akam, Lap and Eas

- **Akam:** the folder contains both a Personal Use / non-commercial / no-redistribution licence and a separate MIT licence file. This is a conflicting licence situation. Do not reuse code until the upstream author clarifies which licence governs the relevant files.
- **Lap / HalftoneLab:** explicit MIT licence (Aaron Dey, 2026), but README describes a browser Canvas implementation. Its visual controls and concepts can inform references; do not add a browser runtime to XAO.
- **Eas:** a short OFX C++ source file includes `../common/purzfx.hpp`; the required common header is not included in this subfolder. The supplied file is OFX-based, not an AE SDK implementation. No licence file was found in the supplied folder. It is not ready for reuse.

## 6. Proprietary halftone references

The archive also contains Sapphire AEX binaries/decompilations for HalfTone, HalfToneColor and HalfToneRings, plus PixyHalftone AEX. Their presence does not establish source rights. Keep them as visual/behavioral references only; do not port decompiled code.

## 7. XAO design implications

1. Build Rays as a new native engine only after defining the desired optical model and reference behavior. The supplied Rays binaries do not provide reusable source.
2. For Halftone, prioritize XAO's existing InkMixer/Retratone architecture rather than adding a disconnected generic overlay. Preserve per-plate separation, independent angles, deterministic screen anchoring, alpha, and the no-paper-background requirement.
3. Treat the Meatbags native AE source as an architectural/behavioral reference until its licence is verified. It may inform rotated-grid sampling and shape geometry, but no literal code reuse yet.
4. Treat Photoshop UXP and browser implementations as algorithm research only. Any port must be native C++ and must not add a Photoshop, browser, Python, Qt, or OFX runtime.
5. Keep 8/16/32-bit handling, SmartFX ROI, non-zero origins, arbitrary render order, MFR safety and premultiplied alpha as explicit XAO acceptance criteria.

## Evidence boundary

Directly inspected: Rays decompilation entry code; native AE Halftone README, `Halftone.cpp` and `HalftoneSampler.hpp`; Halftone Studio README and source tree; Dean MIT licence and README/source; Akam licence files; Lap MIT licence and README; Eas source header/body excerpt.  
Not established: exact Rays optical algorithm, proprietary effect parameter maps, full behavior of all halftone projects, a valid reuse licence for Meatbags/Eas/UXP source, or compatibility with AE 2023.  
No code copied; no XAO implementation changed; no plugin build or runtime test performed.
