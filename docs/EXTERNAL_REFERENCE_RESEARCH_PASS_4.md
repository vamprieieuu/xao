# XAO External Reference Sites — Research Pass 4

Date: 2026-11-07

This note records only information visible on the supplied reference websites at the time of review. It is a design/feature reference, not a claim that their proprietary code is available for reuse.

## GLCHLAB
Source: https://glchlab.com/ and https://glchlab.com/software.html
- The current desktop product describes 91 styles, 61 effects, 18 blend modes, 108 ink sets and 36 looks.
- Its architecture/product language emphasizes a stack of independently editable media, dither, effect, text, shape and paint layers with opacity, masks, transforms and reorder.
- It documents families including diffusion, ordered, screen, modulation, mosaic, pattern, glitch, type and special.
- Relevant XAO observations: a style/effect stack, independent layer opacity/blend, reusable looks, user font import, source-aware glyph/type styles, video/keyframe rendering, and before/after comparison.
- GLCHLAB is a commercial desktop application; its website is not a source-code license. Do not copy its proprietary implementation.

## Effect.app
Source: https://effect.app/explore and https://effect.app/features
- The public library includes ASCII, Halftone screen, Dither, Bloom, Star glow, Light streaks, Threshold, Risograph, Modulation Dither, Broken halftone, Type Distress and many other looks/effects.
- The feature page describes real-time effect stacks, keyframe animation of effect parameters, custom presets, batch processing, image/video workflows and local browser processing.
- Relevant XAO observations: separate reusable looks from underlying engines; allow users to stack effects and animate parameters; build a searchable preset library; keep the UI focused while preserving deep controls.
- Effect.app is a commercial web product; no source reuse is implied.

## Nexus / Synkit
Source: https://nexus.synkit.net/create, https://nexus.synkit.net/effects/shape-halftone-effect, https://nexus.synkit.net/welcome
- The product describes raster and vector effect workflows, with per-effect controls and stackable filters.
- Shape Halftone specifically maps source brightness to a curated stamped-shape library per cell; controls described include cell size, tone curve, palette slots, preserve/sample/override/gradient color modes, empty-below threshold and edge thickness.
- The product also documents a native After Effects effect workflow with keyframeable controls.
- Relevant XAO observations: shape halftone is not merely round dots; shape libraries should be mapped by local tone and optionally edge features; provide palette modes and per-engine threshold/edge controls.
- Nexus is proprietary; use its visible behavior as a reference, not its code.

## ascii.krackeddevs.com
- URL was supplied in THE WEBS.txt. A reliable page extraction was not obtained in this pass.
- Keep it on the pending external-reference list; do not infer controls or algorithms from the URL alone.

## External-reference implementation consequences
- XAO should use a native effect stack with independently enabled engines and explicit blend/opacity controls.
- Looks/presets should store engine settings, stack order, palette/font references and animation values, not flattened output images.
- Shape Halftone needs its own shape-library and brightness/edge mapping design.
- User fonts should be imported and referenced by identity; font files with restrictive licenses should remain local rather than being bundled.
- No proprietary website implementation is being copied.
