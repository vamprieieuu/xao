# XAO Focused Audit — Rays Binary References — Pass 11

Date: 2026-11-07

## Scope

Inspected all six files under the supplied `XAO/rays/` folder:
- `aex/Rays.aex`
- `aex/S_Rays.aex`
- `c+/Rays.aex.c`, `Rays.aex.h`
- `c+/S_Rays.aex.c`, `S_Rays.aex.h`

The two C files are decompiler output, not original vendor source. The headers primarily contain recovered Windows/runtime structures and declarations.

## 1. Rays.aex — BCC+ Rays

The decompiled entry path explicitly constructs/loads `BCCPlus.dll`, then resolves the exports `get_driver_handle` and `do_command`. The plugin is a bridge/driver wrapper that delegates effect work to the external BCC runtime. The binary strings identify the product as BCC+ Rays / BCC Lights.

**Conclusion:** the actual ray-generation/filter algorithm is not present in the recovered adapter code. Reconstructing the algorithm from these files alone would be guesswork. Do not link XAO to BCCPlus.dll or depend on the installed BCC product.

## 2. S_Rays.aex — Sapphire Rays

The decompiled code checks Sapphire registry/install paths, loads the Sapphire runtime DLL (`sapphire_ae.dll`), looks up `sapphire_main`, `sapphire_gpu`, and `sapphire_find_pinfo_for_effect`, then requests the effect descriptor for `S_Rays`. It can display a Sapphire Plug-ins Error when that runtime cannot be loaded.

**Conclusion:** this is also a loader/bridge around proprietary Sapphire runtime code, not the actual ray algorithm. The binary does not provide a reliable, self-contained implementation to port. XAO must not require Sapphire or call its runtime.

## 3. What can and cannot be used

- These binaries confirm two real-world Rays effect families and their external-runtime dependency patterns.
- The available recovered material does not establish exact ray mathematics, control ranges, sampling strategy, alpha behavior, or visual parity.
- Do not infer the implementation from symbol names or loader strings.
- The visual reference clips and images remain the source of truth for XAO's desired Rays behavior.
- A native XAO Rays engine must be independently designed and tested. It should expose its own center/position, direction/angle, length/reach, intensity, falloff, color/tint, threshold, source contribution and quality controls only when those controls are supported by the user's visual references.
- No proprietary runtime dependency should be introduced.

## 4. Review status

All six supplied files in the Rays folder were inspected at the binary/decompiler-wrapper level. This folder does not contain original ray-rendering source code, so algorithm-level reverse engineering is not possible from this material alone. This does not complete the remaining XAO archive audit.
