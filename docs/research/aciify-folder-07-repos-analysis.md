# Aciify archive — Folder 07: repos

**Source:** `aciify.zip` → `aciify/repos/`  
**Inventory:** 1,647 entries, 61,323,542 bytes (~61.3 MB). This is a multi-project source/reference collection, not one unified application. No repository code has been merged into XAO.

## Project inventory (top-level entry counts)

| Project | Entries | Main domain |
|---|---:|---|
| `Ascii-Motion-main` | 814 | Layered ASCII/ANSI editor, animation timeline, procedural motion, palettes/effects and exports |
| `paython` | 298 | JIN2 Python ASCII-code-art portfolio; creative pieces and source |
| `glyph-master` | 105 | Browser real-time ASCII converter, styles, dithering, FX, layers and presets |
| `filtr` | 88 | WebGL2 retro/ASCII/dither/halftone effects studio |
| `ASCII-Rendering-Shader-in-Unity-master` | 62 | Unity camera ASCII image-effect shader + character texture |
| `ascii-art-man` | 47 | Node ASCII art generation, font files, CLI, tests |
| `image2ascii-master` | 40 | Go image→ASCII library and CLI |
| `asciimake` | 28 | Image to ASCII conversion project |
| `AsciiArtFx-master` | 27 | Unity ASCII art effect based on movAX13h shader |
| `image-to-ascii-3.3.0` | 22 | Node.js image-to-ASCII package |
| `ascii-shader-tsx-main` | 13 | TypeScript/React shader component |
| `AsciiArtist-0.1.0` | 12 | ASCII art tool/project |
| `ascii-dither-shader-main` | 11 | Comprehensive algorithm/reference skill (8,554 lines advertised) |
| `asciigo` | 11 | ASCII utility/project |
| `codepeter` | 11 | ASCII code/project snippets |
| `ASCII-generator-master` | 10 | Python image/video→ASCII (color and monochrome) |
| `ASCIIArtCreator-main` | 10 | ASCII art creator |
| `asciiart-0.1.0` | 9 | ASCII art package |
| `ASCIIArt-main` | 9 | ASCII art project |
| `ascii_art-1.3` | 7 | ASCII art package |
| `ComfyUI-ASCIIArtNode-CoiiNode-main` | 6 | ComfyUI ASCII node |
| `GAN-Based-AsciiArtGenerator-master` | 6 | GAN-based ASCII art experiment |

## High-value references inspected

### Ascii-Motion
README identifies a web editor with:
- grid drawing tools (pencil/eraser/fill/rectangle/ellipse/Bezier/text/gradient);
- image/video conversion with frame-rate matching and rendering controls;
- custom color/character palettes and effects;
- procedural animation tools, layered compositing and keyframe interpolation (including Bézier easing);
- export PNG/JPEG/SVG, MP4/WebM, text/HTML, session files, React/CLI components;
- community and MCP integration.
The repository is very large (814 entries) and includes a BubbleTea CLI/dev animation code with very large effect files. README describes the current web product; it does not establish that every online feature is present or runnable from this archived snapshot. License is declared dual MIT + proprietary; distinguish open portions from proprietary/commercial components before reuse.

### Glyph
README describes a browser Canvas 2D renderer:
- 9 styles (ASCII, Braille, halftone, dot-cross, line, particles, Claude Code, retro, terminal);
- 8 diffusion/ordered dithering options;
- animated noise/interval/beam/glitch/CRT/matrix rain;
- 8 color modes, layers, webcam, 50-state undo, presets and PNG/HTML/React/JSON exports.
Tech: React 19 + TypeScript + Vite + Tailwind + shadcn + Zustand, client-side IndexedDB. Good feature/UX reference; web architecture is not AE-native.

### filtr
WebGL2 real-time retro studio. README lists ASCII/custom charset, 14+ dithering approaches (Floyd–Steinberg, Atkinson, JJN, Stucki, Burkes, Sierra, Bayer, clustered-dot, blue-noise, etc.), halftone, dots, Sobel/Prewitt/Laplacian/contour, pixel sort, matrix rain, wave lines, Voronoi, blockify, threshold/noise/VHS. Post stack includes bloom, grain, chromatic aberration, CRT curve, scanlines, vignette and phosphor; supports image/video/GIF/webcam, palettes, presets, share links and export. GPU browser implementation; use as behavior/look reference, not directly portable code.

### ascii-dither-shader reference
The archive contains an unusually extensive technical guide: algorithms, ASCII rendering/charsets, color science, component patterns, performance, shader effects and video pipeline. README advertises 14 algorithms implemented/referenced across TS, Python/NumPy, GLSL and WGSL. Particularly useful as a theory/reference index for later implementation; validate equations and code before adoption.

### Unity shader examples
- `ASCII-Rendering-Shader-in-Unity-master`: camera image effect with character texture atlas, tile X/Y, glyph width/height/count, brightness and monochrome options.
- `AsciiArtFx-master`: Newskool ASCII frame effect, technique attributed to movAX13h.
These are GPU shader references; their sampling/atlas logic may inform XAO's CPU glyph renderer, but Unity-specific scripts/materials are not AE plug-in code. The Unity rendering project README permits use without mandatory credit; still preserve attribution where practical.

### CPU conversion projects
- `ascii-art-man`: Node CLI/library, font files (Doom/rusted), tests and examples.
- `image2ascii-master`: Go library + CLI, MIT license stated in README; image resize/ratio and colored terminal output.
- `image-to-ascii-3.3.0`: Node package for image-to-ASCII conversion.
- `ASCII-generator-master`: Python + NumPy/Pillow/OpenCV image/video converters, color and monochrome.
These help compare cell sampling, aspect correction, palette selection, terminal color output and test fixtures. Their runtime dependencies and language differ from native AE.

### Python art archive
`paython/` is JIN2's creative ASCII-code art portfolio (e.g. GOOD LUCK, SKIPPED A BEAT, I LOVE YOU, SNOWMAN, NIGHT TIDE, BLACK HOLE, CAT KNIGHT, MONEY RAIN, BIRTHDAY CAKE, ROSE, DIAMOND RING). It is artistic source and visual reference, not an image-to-ASCII conversion engine. Individual work/license statements should be read before reuse.

## Cross-project technical synthesis for XAO (knowledge only)

- **Renderer pipeline:** source color/linearization → cell grid & aspect correction → per-cell sampling/average or edge statistics → charset/glyph choice → glyph coverage/mask → RGB/alpha composite.
- **Algorithm families:** threshold/quantization; ordered Bayer; error diffusion (Floyd–Steinberg, Atkinson, Sierra/JJN/Stucki/Burkes); stochastic/blue-noise; edge/Sobel-directed glyphs; halftone shapes; Braille sub-cell encoding; pixel sort and procedural motion as separate effects.
- **Temporal stability:** seed deterministic noise from stable frame/time inputs; preserve temporal state only where explicitly designed, and avoid shared mutable state under AE MFR.
- **Quality:** sRGB vs linear luminance, source aspect ratio, cell aspect ratio, alpha/premultiplied handling, glyph density calibration, color preservation and resize-aware sampling.
- **Performance:** precompute glyph masks/coverage and charset LUTs; use row/cell loops and avoid redundant source sampling. GPU references need a CPU fallback for XAO's initial target unless GPU support is deliberately implemented.
- **Product UX:** layer/preset/history/timeline features are useful references, but XAO's AE plugin scope and host controls should be prioritized over copying a full web editor.

## Licensing / provenance cautions

- The archive mixes MIT, dual MIT/proprietary, CC BY-NC-SA, permissive project-specific statements, and sources with incomplete license metadata.
- README license badges are only initial indicators; inspect each project's LICENSE and individual source attribution before reuse. Noncommercial/share-alike material is not automatically suitable for a commercial plugin.
- ShaderToy-derived snippets and third-party code need attribution/license review.
- Preserve project-specific licenses when copying any file; this report is not a blanket permission to reuse.

## Inspection and limits

- Top-level inventory and representative README/source documentation were inspected; the 1,647-entry tree was not line-by-line audited.
- The Ascii-Motion and other large projects were not installed, built, or runtime-tested; web feature lists are README claims.
- No source was integrated, no third-party dependency added, and no XAO build/test was run.
- Original project trees remain in `aciify/repos/` in the user's archive.
