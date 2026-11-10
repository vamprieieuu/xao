# XAO Glow / Glint Reference Boundary Audit — Pass 62

Date: 2026-11-10  
Archive scope: `XAO/glow/superbloom [open source]`, `XAO/glow/c+/S_Glint.aex.c/.h`, and related binaries.

## 1. Superbloom: actual source behavior

The supplied Superbloom project is MIT-licensed (copyright Yikuan Sun, 2025). Its README identifies it as a browser app, Photopea plugin, Photoshop UXP plugin, and Electron desktop app—not a native After Effects effect.

The core `src/lib/bloom.js` implements a three-stage Canvas 2D pipeline:

1. Draw the source image into a threshold canvas at preview quality, then isolate highlights below the configured threshold. At threshold 255, the mask is filled black.
2. Build the glow by iterating from layer 1 to `glowLayers - 1`. Each pass uses a blur radius proportional to `(i + 1)^2 * glowRadius * previewQuality`, applies CSS brightness/hue-rotate/saturation filters, and screen-blends the threshold image.
3. Stretch the glow horizontally according to `anamorph`, then screen-composite it over the original image. An optional mode returns the glow layer without compositing.

The mask colorization path uses Canvas `color` and `multiply` compositing. The pipeline depends directly on HTMLCanvasElement, CanvasRenderingContext2D, CSS filter strings, browser image objects, and Svelte/JavaScript UI code.

## 2. XAO reuse decision for Superbloom

**Do not port the renderer literally.** Its core is inseparable from browser Canvas and CSS filter behavior, so copying it would violate XAO's native C++/AE-only runtime requirement.

The following are useful as design references, not copied implementation:
- Threshold-isolated highlights as a distinct source buffer.
- Multiple progressively larger glow radii to build a broad bloom.
- Separate brightness, hue, saturation and tint controls.
- Anamorphic horizontal stretch as an independent parameter.
- Separate Glow Only output from source-plus-glow compositing.

These ideas already overlap with HaloGlow's richer native implementation. Avoid adding a second competing bloom engine solely to reproduce this simpler stack.

## 3. S_Glint decompilation: evidence boundary

The archive includes `S_Glint.aex` and Ghidra-style decompilation artifacts `S_Glint.aex.c` / `.h`. The generated C file contains Windows loader/import state, function-pointer tables, opaque globals, and Sapphire-related error strings (including a Sapphire DLL failure message). It is decompiler output, not the original source tree.

This artifact can help identify externally visible behavior, parameter labels, dispatch paths and host integration patterns. It is **not a clean-room source implementation** and must not be treated as reusable code. No licence granting source reuse was found for this decompilation/binary in the inspected archive. Therefore:
- Do not copy decompiled code, tables, constants or reconstructed proprietary implementation into XAO.
- Use only high-level observations independently confirmed from lawful user-visible references.
- Keep the binary as a visual/behavioral reference only.

The current pass did not complete a full parameter/algorithm trace of S_Glint. It does not claim that the decompilation reveals the complete glint model.

## 4. Related glow binaries

The archive also contains Deep Glow, DeepGlow2 and Starglow AEX binaries with decompilation text. Their presence does not establish source availability or a reuse licence. They remain reference-only until their parameter behavior is independently documented; do not port decompiled code.

## 5. XAO implementation direction

- Keep HaloGlow as the primary native Glow candidate; its C++ core and AE adapter are a materially better architectural fit than Superbloom.
- Treat anamorphic stretch and layered screen bloom as optional stylistic controls only if XAO's supplied visual references call for them and HaloGlow does not already provide equivalent behavior.
- Implement Glint as an independent native engine only after extracting a clear user-visible behavior specification from the references. Do not derive a proprietary algorithm from decompiler output.
- Preserve CPU-only rendering as a reliable baseline and keep any GPU acceleration optional.
- No paper/background simulation is introduced by this pass.

## Evidence boundary

Directly inspected: Superbloom `README.md`, `LICENSE.md`, `src/lib/bloom.js`, its project structure and platform declarations; S_Glint decompilation header/source text and associated binary presence.  
Not established: Superbloom's visual match to XAO clips, exact S_Glint algorithm, complete S_Glint parameter map, source reuse rights for proprietary binaries/decompilations, or AE runtime behavior.  
No source copied; no XAO implementation changed; no build or render test performed.
