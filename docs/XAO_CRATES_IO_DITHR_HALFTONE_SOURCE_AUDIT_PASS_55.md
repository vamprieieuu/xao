# XAO — crates.io Source Audit: dithr and halftone (Pass 55)

Date: 2026-11-10
Branch: `xao/recovery-baseline-2026-11-10`
Scope: inspect actual upstream Rust source/manifests for two high-priority crates.io candidates. This is not a proposal to add Rust to XAO.

## 1. `dithr` — source-level findings

Upstream: https://github.com/pbkx/dithr
Manifest inspected: `Cargo.toml`
Core source inspected: `src/lib.rs`, `src/buffer.rs`, `src/dot_diffusion.rs`
License file inspected: `LICENSE`

### Architecture

The library is buffer-first: mutable typed sample slices with explicit width, height and stride. It has explicit Gray/RGB/RGBA layouts and supports u8, u16 and f32 sample types. `BufferKind` encodes channel count, alpha presence, float-vs-integer and bytes per channel. Buffer validation exposes distinct errors for zero dimensions, insufficient stride, insufficient data, row/pixel bounds, type/layout mismatch and arithmetic/out-of-bounds conditions.

This is a valuable design reference for XAO's host-independent pixel adapters. It does not establish that XAO should use Rust or that Rust code can be directly linked into the current C++ plugin target.

### Algorithm evidence

The public API documents families including:
- ordered Bayer matrices (2x2 through 16x16), cluster-dot and custom ordered maps;
- void-and-cluster, adaptive ordered and space-filling-curve ordered methods;
- error diffusion and variable error diffusion;
- Yliluoma palette methods;
- stochastic methods;
- Knuth dot diffusion and an optimized dot-diffusion variant;
- direct binary search and other advanced halftoning.

The inspected `dot_diffusion.rs` is substantive implementation, not just a wrapper:
- Knuth uses an explicit 8x8 class matrix with 64 classes;
- a 3x3 diffusion weight kernel is defined;
- the optimized path uses a 5x5 weight/objective matrix;
- the optimized class matrix is generated lazily with `OnceLock`;
- it performs up to six greedy swap-improvement passes over the 8x8 matrix;
- the objective evaluates a set of eight threshold levels.

This is a candidate for analytical study and controlled image fixtures. The optimized class matrix generation has a potentially meaningful initialization cost; XAO should benchmark any equivalent preprocessing and cache immutable results rather than recomputing per frame.

### Licensing and dependencies

The inspected manifest declares MIT. Default feature is `std`; optional features are `rayon` and `image`. The manifest lists optional Rayon and image dependencies and Criterion as a development dependency. The LICENSE file contains the MIT grant and requires retaining the copyright and permission notice in copies/substantial portions.

No source from this crate has been copied into XAO. Any future literal reuse still needs a per-file provenance record and preservation of the MIT notice.

### XAO recommendation

**High-priority reference; no Rust dependency.** Translate selected algorithms to native C++ only after:
1. matching behavior with small deterministic fixtures;
2. confirming each algorithm's supported sample/layout combinations;
3. benchmarking 1080p/4K and tile/MFR execution;
4. defining alpha treatment (the generic API's RGBA support alone does not prove correct premultiplied-alpha semantics);
5. preserving deterministic results across arbitrary render order.

Do not claim every algorithm supports every format. The upstream README explicitly documents format restrictions for several advanced families.

## 2. crates.io `halftone` — source-level findings

Upstream: https://github.com/devonoel/halftone
Docs: https://docs.rs/halftone/latest/halftone/
Inspected source paths: `src/lib.rs`, `src/pipeline.rs`, `src/main.rs`, `src/openai.rs`
Inspected published manifest metadata: https://docs.rs/crate/halftone/0.3.0/source/Cargo.toml.orig

### Actual purpose and algorithm

This is primarily an image-to-ASCII/ANSI terminal renderer and raster export tool, not a print-screen halftone engine. Its documented conversion pipeline:
1. resize the image to a character grid;
2. compute Rec.709 luminance per cell;
3. histogram-equalize luminance using the image's cumulative distribution;
4. map to a fixed glyph ramp ` .:-=+*#%@`;
5. apply Floyd–Steinberg error diffusion during glyph quantization;
6. preserve cell RGB for colored output.

The source organization exposes a library pipeline plus CLI and optional image-generation module. The OpenAI image-generation feature is separate from conversion and is not relevant to XAO's native renderer.

### Licensing and dependency boundary

Published metadata inspected for version 0.3.0 declares `MIT OR Apache-2.0`. Its dependency list includes image/imageproc, ab_glyph, serde/serde_json, clap and reqwest. The docs page reports later published versions as well; do not assume the 0.3.0 manifest exactly matches the latest version's dependency graph.

The crate's conversion ideas are useful references, but its terminal/CLI-oriented output and Rust dependency stack make it a poor direct runtime dependency for XAO. No code copied.

### XAO recommendation

**Medium-priority ASCII algorithm reference.** The most useful ideas are image-adaptive histogram equalization before glyph selection and error diffusion over glyph-density quantization. Test them as optional mapping modes against S1's measured-density glyph atlas and area-coverage cell sampling. Do not replace S1's atlas pipeline with a fixed ten-character ramp.

## 3. Comparative decision

| Candidate | Strongest contribution | Main limitation for XAO | Decision |
|---|---|---|---|
| `dithr` | Broad, typed, stride-aware dithering/halftoning algorithms | Rust implementation; algorithm-specific format restrictions; alpha semantics need independent validation | Study deeply; port selected algorithms to C++ |
| `halftone` | Histogram equalization + Floyd–Steinberg glyph-density quantization | Terminal/CLI focus; fixed glyph ramp; Rust dependency stack | Use as optional ASCII mapping reference, not engine base |

## 4. Verification boundary

The source and manifest paths above were fetched from the upstream repositories. This pass did not run Cargo tests, benchmarks, fuzzers, or compare generated pixel outputs. It did not inspect every source file in either repository. The audit therefore supports the specific source-level statements above, not a claim of complete upstream review.

## 5. Next crates.io queue

Prioritize source-level inspection in this order:
1. `ditherlib`: inspect algorithms, RGB/CMYK screen-angle implementation, dependencies and license.
2. `blue-noise`: inspect void-and-cluster generation, threshold rank construction, tiling and reproducibility.
3. `artscii` / reusable workspace crates: inspect whether image conversion logic is actually library-grade and independent of CLI/WASM.
4. Continue the remaining `dithr` modules (ordered, diffusion, stochastic, Yliluoma, palette/indexed) and build a source-to-XAO algorithm matrix.

No crate is approved as a linked dependency yet.
