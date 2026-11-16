# Aciify archive — Folder 06: grd (gradient maps)

**Source:** `aciify.zip` → `aciify/grd/`  
**Inventory:** 11 ZIP entries (10 gradient files + directory), 1,272,476 bytes.  
**Format:** Adobe Photoshop Gradient preset binary format; files begin with `8BGR` signature and contain structured gradient records (e.g. `GrdLVlLs`, `GradObjc`, `Nm  TEXT`). These are assets, not source code.

## Preset catalog

| File | Size | Initial embedded label/observation |
|---|---:|---|
| `1.grd` | 30,791 | Gradient preset set; embedded first name “Custom” |
| `2.grd` | 264,817 | Large set; embedded first name “RGB Gradient Map 01” |
| `8BITGRADIENTS.grd` | 5,266 | 8-bit gradient collection; “FUTURE - 2” label observed |
| `Anti Gradients .grd` | 128,195 | Anti-gradient collection; first visible name “1” |
| `CRT GRADIENTS.grd` | 9,446 | CRT-themed gradient set; first visible name “INVERT” |
| `DERSIGN SYNDROME GRADIENT MAP PACK.grd` | 177,179 | Design Syndrome gradient pack; includes B&W and named presets |
| `DESIGN SYNDROME GRADIENT MAP PACK 2.grd` | 236,533 | Second Design Syndrome pack |
| `DESIGN SYNDROMEGRADIENT MAP PACK.grd` | 236,533 | Same byte size as the prior pack; likely duplicate or alternate copy—content hash comparison needed before deduplication |
| `FASTGRAD 3 - GOD CONTROL.grd` | 179,121 | FastGrad/God Control gradient set |
| `Plastisol Color Gradients.grd` | 4,595 | Plastisol-themed color gradients |

## XAO relevance

- This folder contributes **gradient look/preset assets**, not effect logic.
- Use them as visual/reference material for gradient palette design; if XAO needs import support, implement a deliberate parser or convert them to a documented interchange format. Do not assume Photoshop `.grd` binary can be read as a simple RGB list.
- XAO's Gradient Studio should use its own well-defined internal representation (ordered stops, positions, colors, interpolation/opacity metadata) and serialize presets consistently; importing `.grd` is a separate feature with compatibility tests.
- The ECW Gradient example analyzed in folder 03 is a UI/reference implementation, while these files are actual preset data—distinct sources.

## Verification / limitations
- ZIP sizes and binary signatures were inspected; the files are not text.
- Embedded labels were identified from initial records only. No full preset extraction, visual swatch sheet, Photoshop import, duplicate hash check, or XAO parser was run.
- No gradient binaries were copied to XAO; originals remain in the archive. Redistribution/licensing should be checked for the preset packs.
