# XAO Native AE Integration Re-entry Audit — Pass 72

Date: 2026-11-11

## Verified CI result

Commit `e1b23ce7e92eb67814068403977121c068f58d94` triggered workflow run `43079454843`.
Both jobs completed successfully:
- `Core tests (windows-2022)`: Configure, Build, Test all succeeded.
- `Core tests (ubuntu-latest)`: Configure, Build, Test all succeeded.

This verifies the portable XAO core and current ASCII engine compile and pass the registered CTest suite on both platforms. It does not verify an Adobe plug-in binary.

## SDK archive re-materialized and inspected

The user's Library contains `May2023_AfterEffectsSDK_Win.zip`. It was materialized into the working container and extracted for direct inspection.

Confirmed paths:
- SDK root: `AfterEffectsSDK/`
- Headers: `AfterEffectsSDK/Examples/Headers`
- Utilities: `AfterEffectsSDK/Examples/Util`
- Resources: `AfterEffectsSDK/Examples/Resources`
- PiPL compiler: `AfterEffectsSDK/Examples/Resources/PiPLtool.exe`
- Canonical SmartFX example: `AfterEffectsSDK/Examples/Effect/SDK_Noise`

The SDK sample confirms the canonical SmartFX global flags include `PF_OutFlag2_FLOAT_COLOR_AWARE`, `PF_OutFlag2_SUPPORTS_SMART_RENDER`, and `PF_OutFlag2_SUPPORTS_THREADED_RENDERING`. The XAO ASCII engine itself has no host adapter yet.

## Existing adapter package boundary

The Library also contains `XAO_InkMixer_AE_SDK_Adapter_Pass.zip`. Inspection confirms it is a separate InkMixer adapter package, not an ASCII adapter. It demonstrates useful SDK layout and PiPL preprocessing concepts, but it depends on InkMixer-specific state and render functions. It must not be copied into XAO's ASCII target as-is.

In particular, the adapter's current input conversion copies normalized AE pixel values directly into the XAO image buffer. XAO's current core contract is linear-light, premultiplied RGBA. Those contracts are not automatically equivalent in every AE project working space. A production adapter must explicitly define/verify the transfer-function and alpha handling rather than silently assuming equivalence.

## Next implementation milestone

Build a dedicated ASCII host adapter, not an InkMixer adapter:
1. Register a compact first set of ASCII controls (cell size, glyph scale, contrast, brightness, invert, color mode).
2. Use rowbytes-aware 8/16/32-bit pixel access and explicit alpha/color conversion.
3. Keep render state immutable and per invocation; no mutable global state.
4. Add a native Windows `.aex` target with XAO-owned PiPL identity and correct exports.
5. Compile with MSVC against this SDK and only then test loading/rendering in AE 2023.

## Explicit non-claims

- No `.aex` has been built.
- No AE runtime load/render test has been performed.
- No InkMixer adapter source or MAJEED effect implementation has been ported.
- The separate MAJEED Lines effect remains excluded.
