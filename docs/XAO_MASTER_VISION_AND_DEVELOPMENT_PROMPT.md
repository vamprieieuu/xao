# XAO — Master Vision & Development Prompt
Version: 1.0-working
Last consolidated: 2026-11-11
Repository: https://github.com/vamprieieuu/xao
Active branch: xao/recovery-baseline-2026-11-10

## Mission
Develop XAO, a native Adobe After Effects plugin for Windows x64, targeting AE 2023 / 23.2.1 and the Adobe After Effects SDK. The product name is XAO, not XAO ASCII. ASCII is the first/default engine when the effect is applied. XAO is a unified image-processing system, not a bundle of unrelated copied effects.

Inspect the user's actual visual references, plugins, source files, reverse-engineering exports, fonts and open-source projects. Understand their behavior, then implement high-quality native engines that reproduce and extend the requested visual results. Visual quality is the acceptance criterion. A successful build alone never proves that an engine is finished.

## Working agreement
- The user may send thoughts in several voice or text messages. Collect and consolidate them; do not require the user to explain every reference individually when the asset already exists.
- Do not start a comprehensive analysis until the user gives an explicit start signal.
- Once started, work in substantial batches. Do not send tiny progress notes or claim completion after checking one file. Deliver one complete report for each completed phase.
- Make strong technical decisions autonomously. Ask only when an essential user decision or missing input blocks correctness.
- Never call an incomplete renderer final. If an acceptance gate is unmet, state exactly what remains.
- Preserve the user's requirements and distinguish them from assistant proposals and technical inferences.
- Update this living file whenever the user supplies further durable requirements.

## Product architecture
XAO contains independently enabled engines that can be combined:
- ASCII (first/default; complete this first)
- Halftone
- Dither
- Glow
- Rays

The user must be able to enable or disable each engine independently and combine them (for example Halftone only, Halftone + Rays, Rays + ASCII). Each engine has its own controls and output, with predictable compositing.

The user has not finalized the advanced color/gradient system. Keep the architecture open for it, but do not invent its final UI or behavior before the user explains it. S1 palette references must be recovered and preserved for later integration.

## ASCII requirements

### Preset-first interface
The first section is Plugin Presets. Recreate the Crates ASCII preset family from the supplied reference data and behavior:
- Default
- Alien Signal
- Circles and Dots
- Classic
- Corrupted
- Crossword
- Diamond (source binary label: Diamonds)
- Matrix
- Motherboard
- Pink Shapes (source binary label: Punk Shapes; pink tint)

Add original XAO presets beyond these. Each preset must be a complete coherent style recipe, not just a renamed look. Selecting a preset applies a baseline while leaving controls editable. Preserve provenance. Do not ship the Crates binary, plugin identity, wrapper or proprietary assets.

### Character-set libraries
Organize a mixable library into:
- Ancient: historic-looking alphabets, ornamental/cryptic glyphs, strange symbols, signals and Matrix-like glyphs.
- English: letters, digits, symbols and text tokens.
- Arabic: Arabic letters, Arabic numerals and words.

Do not add the proposed themed Arabic Word Library taxonomy; the user rejected it. Each language group independently enables Letters, Numbers and Words. The user can mix any groups and categories, such as Arabic letters + English numbers + Ancient words.

Include Crates and S1 character sets in the XAO library alongside original XAO sets. A font family is distinct from a character set: the set defines candidate glyphs/tokens; the font defines how codepoints are drawn. Arabic words must support correct contextual shaping and right-to-left order. Japanese/Katakana, Braille, blocks, quadrants and box-drawing sets need glyph-coverage checks and deterministic fallback.

### Crates ASCII reference
The supplied Crates AEX contains an embedded JSON metadata payload with exact preset and parameter data. Use the extracted data in:
docs/XAO_ASCII_FULL_REFERENCE_AND_IMPLEMENTATION_AUDIT_2026-11-11.md

Recovered Crates character sets:
- Special Characters and Letters
- Special Characters and Numbers
- Classic Typewriter
- Japanese Characters
- Binary
- Minimal Punk
- X's
- Bubble Growth
- Stars
- Diamonds
- Dots
- Circuits 1
- Circuits 2
- Alien Font
- Bars

Recovered controls include Characters Based On (Red, Green, Blue, Luma), Reverse Order, Character Size, Character Margins, Cell Margins, Anti-Aliasing, Tint Strength/Color, Uniform Luma, Invert Luma, Invert Threshold, Smooth Shading, Background Color, Blend With Original, Random Shuffle, Random Speed, Random Color Amount and X Flip Threshold.

### S1 ASCII Art reference
Recovered character sets:
- Classic
- Minimal
- Detailed
- Bourke
- Braille
- Katakana
- Blocks
- Quadrants
- Box Drawing

Color modes:
- Monochrome
- Source Color
- Palette

Palette names:
- Monitor Glow
- Game Boy DMG
- Oil 6
- Retrotronic
- Gothic Bit
- Curiosities
- CGA Palette 1
- CGA Palette 1 Bright
- CGA Palette 0 Bright

S1 also exposes Palette Mapping (Tonal / Original), Palette Color Strength and blend modes (Normal, Multiply, Screen, Overlay, Soft Light, Difference, Add). Recover the exact color stops from the supplied binary or verify against original output. Never invent palette values. The user wants the actual distinctive colors and gradients. Advanced color design remains pending their further explanation.

### Typography controls
Include Character Size, Number Size or per-category size overrides, Character Margins, Cell Margins, Anti-Aliasing, Character Set, glyph density, font family/group, glyph scale/fit and optional size variation. Grid/cell size and glyph size are separate concepts. Allow large and small glyphs in the same frame.

### Random animation
The user approved independent Random Characters, Random Words and Random Timing controls. Also include random amount, speed, per-cell timing variation, seed and animation enable. Randomness must be derived from seed + cell identity + absolute time slot so reverse playback, arbitrary frame order, caching and MFR remain deterministic. Never rely on mutable global RNG or previous-frame feedback.

## Main Ideas visual targets
The Main Ideas clips are the visual truth. Detailed findings are in the audit report. Core observations:
- ASCII CGO: dense changing glyph field, selective warm glyph glow, controllable glyph/region selection and separate subject halo/outline.
- ASCII Ghost: source-matched color per glyph plus a distinct rays contribution.
- Liquid ASCII: variable rounded rectangular text tiles, Japanese-like changing glyph/word content and tile backgrounds sampled from source.
- Mosaic ASCII: coarse mosaic plus fine glyph layer, variable glyph sizes, reduced saturation and selective glow.
- Rainbow ASCII: dark glyph field with localized multi-color source-driven illumination and selective glow, not a global rainbow overlay.
- Threshold ASCII: dedicated horizontal segment/bar/threshold style with optional block details. Do not confuse it with MAJEED Lines.
- PixelDitherGo: separate coarse block quantization and fine micro-pattern layers.
- Golden Glow Halftone belongs to the later Halftone/Glow system, not the default ASCII engine.

Do not collapse these looks into one generic ASCII ramp. Each must retain its distinct visual structure.

## Source and reuse rules
The user wants supplied source/approximate-source files used as actual implementation material where possible, not merely read and summarized. Inspect provenance and license first. Reuse code/assets when authorized and technically compatible; otherwise independently implement the observed algorithm.

Priority references:
- Crates ASCII AEX and decompiled C exports
- S1 ASCII Art AEX and decompiled C exports
- ASCII Art main (MIT)
- ASCII OFX and its public-domain 8×8 bitmap font
- AuraASCII master (MIT)
- Morphing ASCII Shader (MIT)
- GlyphBlocks OFX
- POINTLESS (GPL-3.0)
- OVN ASCII and L3tt3rM4pp3r2 AEX/decompilation exports

Preserve MIT notices when porting MIT code. Do not copy GPL-3.0 POINTLESS code into a differently licensed proprietary XAO build without a deliberate licensing decision. ASCII OFX and GlyphBlocks OFX have no clear top-level license in the supplied archive; treat as algorithmic references unless permission/license evidence is supplied. AEX/decompilation files are not original source repositories; use recovered metadata/behavior, but do not ship their binaries or copy plugin identity. The 45 supplied fonts have mixed license/embedding restrictions; do not bundle blindly. Check per-font rights; prefer installed fonts or properly licensed assets. Sponge Arabic declares SIL OFL; preserve the license if embedding it.

## Native engineering requirements
- Native C++ After Effects plugin, .aex, Windows x64, AE 2023 / 23.2.1.
- CPU-first; no Photoshop UXP runtime; no high-end GPU requirement.
- Correct XAO PiPL identity and metadata, EffectMain and plugin entry exports, parameter count, OutFlags/OutFlags2 and pixel-format declarations.
- Support 8/16/32-bpc with correct transfer conversion, unpremultiplication/re-premultiplication and alpha.
- SmartFX result rectangles must not exceed request rectangles; checkout sufficient source bounds when cells sample across tile boundaries.
- Respect render scale, bounds, rowbytes, origin offsets, abort checks and memory failures.
- Immutable per-render state; deterministic rendering and MFR safety. No mutable global render settings. Caches must be immutable or synchronized.
- Build scripts verify PiPL, PE architecture, exports and runtime dependencies.
- MAJEED is build/SDK architecture reference only. Do not port its effects, algorithms, assets, UI, parameters or identity. Do not include its separate Lines effect. XAO's own Halftone screen families are allowed.

## Work order after the user says start
1. Visual References: inspect every Main Ideas clip and still, compare Before/After, study temporal changes, geometry, glyphs, color, glow, masks and compositing. Deliver one full report.
2. Plugins/AEX: inspect all supplied plugins, binaries, embedded resources, parameter schemas, presets and decompilation exports. Deliver one full report.
3. Open Source: inspect source files, algorithms, tests and licenses. Separate reusable code from ideas requiring independent implementation. Deliver one full report.
4. Websites: inspect user-supplied websites/tools. Deliver one full report.
5. Unified Design: update this master prompt and produce the exact XAO engine/UI/parameter specification.
6. ASCII Implementation: finish the complete ASCII engine before moving to other engines. Include preset library, character-set/font atlas, language/category mixing, words, animation, typography controls, source mapping and accepted ASCII visual sub-modes.
7. Verification: build core tests and Windows native AEX, inspect CI logs/artifacts, and test in AE 23.2.1 when a real runtime is available. Do not call it final before visual and runtime gates pass.

## ASCII completion gate
ASCII is complete only when:
- The default XAO interface exposes the full functional control system, not labels without behavior.
- Crates and S1 character sets/presets are implemented and selectable.
- Ancient, English and Arabic groups can be mixed, with independent Letters/Numbers/Words switches.
- Font rendering uses real glyphs; Arabic words shape correctly.
- Random characters, random words and random timing work independently and deterministically.
- Character size, margins, cell spacing and anti-aliasing work visually.
- Each Main Ideas ASCII target is recognizable and retains its distinct structure.
- Alpha, premultiplication, bit depths, proxies, render scale, tiles, aborts and MFR are tested.
- Windows native build passes and the plugin is actually loaded/applied/rendered in AE 23.2.1 without warnings or crashes.
- Any unverified requirement remains explicitly unaccepted.

## Current state
The current core ASCII engine is only an early 10-mask 5×7 renderer and the AE adapter exposes a small set of basic controls. It does not meet the ASCII completion gate. The full audit is in docs/XAO_ASCII_FULL_REFERENCE_AND_IMPLEMENTATION_AUDIT_2026-11-11.md.

This is a living specification. When the user supplies more notes, especially the advanced color/gradient system, update this file before changing implementation assumptions.


---

## ASCII Engine — User Requirements Captured 2026-11-11 (Draft, awaiting further visual notes)

This section records the user's direct requirements. It is not the final complete product specification; the user may add more after reviewing the Main Ideas clips.

### Default interface and engine
- The plugin identity is **XAO**.
- ASCII is the first/default interface and the default engine when the effect is applied.
- The ASCII interface must open with a prominent **Plugin Presets** selector for fast one-click looks.
- This is a complete production engine requirement, not a request for a prototype, demo, or placeholder UI. A preset must produce a real rendered result, and its exposed controls must work.

### Crates ASCII preset family
Recreate these exact preset names as XAO presets, based on the supplied Crates ASCII reference and recovered parameter data:
1. Default
2. Alien Signal
3. Circles and Dots
4. Classic
5. Corrupted
6. Crossword
7. Diamond
8. Matrix
9. Motherboard
10. Pink Shapes

The supplied reference preset metadata and parameter combinations are recorded in the ASCII audit. Reproduce their visual behavior independently; use supplied source/approximate source files where their provenance and license permit, and do not merely copy names while leaving the presets visually identical. Add further original XAO presets after the reference set.

### S1 ASCII Art — priority reference
Use S1 ASCII Art as a second major source:
- Recover and integrate its Character Sets alongside the Crates sets.
- Preserve its distinct character-set behavior and provide detailed independent controls.
- Carry over the exact S1 palette colors recovered from the supplied binary.
- Recreate the Monochrome, Source Color, and Palette color modes as part of the later advanced color system. The user will explain the desired final color architecture later; do not finalize color UI or behavior before that explanation.

Exact recovered S1 set data and RGB8 palette stops are documented in:
`docs/S1_ASCII_REFERENCE_RECOVERY_2026-11-11.md`
and stored in:
`core/include/xao/AsciiReferencePalettes.h`

### Character libraries and mixed content
Provide independently mixable libraries:
- **Ancient:** historic/ornamental/strange glyphs, symbols, signals, and matrix-like sets.
- **English:** English letters, numbers, and words.
- **Arabic:** Arabic letters, Arabic numerals, and words.

For each library, allow independent selection of Letters, Numbers, and Words. Users must be able to combine categories across libraries (e.g. Arabic letters + English numbers + Ancient words), not be restricted to one language at a time. Do not add the previously proposed curated Arabic Word Library taxonomy; the user rejected that idea.

### Character and typography controls
Provide real controls for:
- Character Set
- Character Size
- Number Size
- Character Margins
- Cell Margins
- Anti-Aliasing
- Glyph/character density and variation
- Font family where useful; font selection is secondary to character-set fidelity.

The character sets from both Crates ASCII and S1 ASCII Art must be available in XAO. The supplied fonts folder should be inspected and used where it materially improves the result, but do not prioritize font choice above character-set behavior.

### Animation and randomness
Provide independent controls for:
- Random Characters
- Random Words
- Random Timing

Also expose meaningful speed, amount/variation, and deterministic seed controls. Randomized characters and words should actually change over time. Random Timing should vary per-cell change timing rather than merely enabling a global synchronous swap.

### Implementation and reuse directive
The user explicitly requests that the supplied source/approximate-source files and open-source projects be used as actual implementation inputs, not merely read and summarized. Inspect the files, isolate reusable components/algorithms, and integrate compatible parts into the XAO ASCII engine. Verify provenance, licenses, dependencies, and compatibility before copying or porting. Do not blindly paste decompiled proprietary code or import incompatible copyleft code into a closed-source build. Preserve the MAJEED boundary: build/SDK architecture only, never its effects or algorithms.

### Required reference batch
When the user authorizes the full phase, analyze all Main Ideas clips and the supplied ASCII references in one comprehensive pass, including:
- ASCII Main and all Main Ideas videos/stills
- Crates ASCII and its AEX/decompilation/source approximation
- S1 ASCII Art and its AEX/decompilation
- ASCII Art Main open-source project
- ASCII OFX
- AuraASCII
- Glyphblocks OFX
- Morphing ASCII Shader
- Pointless (GPL-3.0; inspect only unless its license obligations are deliberately accepted)
- All other relevant ASCII AEX/C++ references, including OVN ASCII and L3tt3rM4pp3r2

The user does not want to be asked to explain each clip. The assistant must analyze the clips and visual references directly, compare Before/After, study motion over time, and document the visual and technical findings.

### Delivery standard
- Do not declare the ASCII engine complete after an inventory, partial implementation, or successful compile alone.
- Deliver a complete, fully functioning final ASCII engine with all agreed controls and presets implemented.
- Verify native build and structural PiPL/exports. Then test inside After Effects 2023 / 23.2.1 for actual application, rendering, UI, and stability before claiming full runtime acceptance.
- Do not send micro-progress reports. Complete the full analysis/implementation phase and then provide one substantial report with the tested build and limitations clearly stated.
