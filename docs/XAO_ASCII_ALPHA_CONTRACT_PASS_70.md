# XAO ASCII CPU Engine — Pass 70

## Premultiplied-alpha correction and regression coverage

The first ASCII raster pass treated non-colorized ink as straight RGB and multiplied it by cell coverage. That contradicted XAO's documented internal pixel contract (linear-light, premultiplied RGBA) and could double-apply alpha when a caller supplied already-premultiplied ink.

Pass 70 makes the parameter contract explicit: `ink` and `paper` are linear-light premultiplied RGBA values. Preserving source cell alpha now applies the averaged cell coverage once to both colors. When source colorization is enabled and source alpha is not preserved, the averaged premultiplied color is safely unpremultiplied before setting output alpha to one.

The ASCII tests now cover deterministic output, glyph/paper coverage, fully transparent input, premultiplied ink alpha, and mismatched dimensions.

This remains a CPU core engine milestone. It does not yet include the full typography/font-atlas system, AE parameter UI, PiPL, native `.aex` target, or an After Effects runtime test.
