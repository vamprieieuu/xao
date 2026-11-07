# XAO Smart Object Tracker — Feature Architecture Proposal (Pass 26)

Date: 2026-11-07
Status: proposed architecture; not implemented or benchmarked.

## 1. Product definition

Add an optional independent subsystem named **Smart Object Tracker**. Its purpose is to identify a selected object in footage, create a temporally coherent per-pixel mask for it, track that object through the clip, and provide the mask, motion data and object-space coordinates to any XAO engine.

Example: select a moving person, car or animal on one frame. XAO follows that subject through the shot. ASCII/glyphs, Halftone, Dither, Glow, Rays, Glint, Array and Typeset can be restricted to the subject mask; the background remains unchanged unless the user chooses another compositing mode.

Important distinction:
- Object segmentation answers: "which pixels belong to this object?"
- Motion estimation answers: "which of those pixels/regions are actually moving, and in what direction/speed?"
- Tracking answers: "which object is this on the next frame?"
These must not be conflated. A segmentation model may correctly segment a stationary person; a motion gate can optionally suppress the effect until the person moves.

## 2. Recommended user experience

### Selection
Support:
- Click/positive point on the target.
- Negative point to remove an incorrectly included region.
- Rectangle/box around the target.
- Optional text prompt for object classes, only if a local model backend supports it.
- Add multiple tracked objects with separate IDs and masks.

### Tracking workflow
1. User chooses a frame and selects the subject.
2. AI creates an initial object mask.
3. User optionally corrects the mask with positive/negative clicks or a box.
4. The tracker propagates the mask forward and backward through the source clip.
5. XAO stores per-frame masks and confidence/validity data in a project cache.
6. Any XAO effect samples this immutable mask data during render.

Do not require inference to run independently inside every AE render callback. Provide an explicit Analyze/Track action and progress/cancel UI. If the source or settings change, mark the cache stale and request re-analysis.

## 3. Candidate AI model and deployment strategy

Meta SAM 2 is a strong candidate for the first research prototype because it supports promptable video segmentation: points, boxes or masks can define an object, and a streaming memory mechanism propagates the mask through video. Its official release describes an Apache 2.0 code/model release. References:
- https://ai.meta.com/research/sam2/
- https://github.com/facebookresearch/sam2
- https://ai.meta.com/blog/segment-anything-2-video/

The current Meta Model API also describes SAM 3.1 text-prompted and prompted video segmentation, but it is a hosted API path. XAO should not require cloud uploads or API keys. Keep cloud inference out of the baseline product; consider it only as a separately consented optional future backend.

Deployment recommendation:
- Define a backend interface (initialize, prompt, propagate, refine, cancel, dispose).
- First prototype can evaluate SAM 2 offline as a separate helper process/service, isolated from the AE render thread.
- Investigate ONNX Runtime or another supported local inference path only after verifying that the chosen model can be exported and produces equivalent masks. Do not assume official SAM 2 is already a drop-in ONNX model.
- CPU-only inference must remain possible, but AI analysis may be slow on older Intel hardware. Offer reduced analysis resolution, frame stride, quality/speed presets and cancellation.
- Optional GPU acceleration can be used when available; it must not be a hard requirement.
- Keep model weights outside the .aex binary and document model version, hash, license, storage and update behavior. No silent network download or cloud upload.

ONNX Runtime documents CPU and multiple accelerator execution providers, and Windows ML can select providers dynamically on supported Windows versions. This is an integration option, not proof that SAM 2 itself is already compatible or fast on the user's machine:
- https://onnxruntime.ai/docs/execution-providers/
- https://onnxruntime.ai/docs/get-started/with-windows.html

## 4. Motion-aware behavior

Add a separate **Motion Gate** after segmentation:
- Off: apply to the selected object even when stationary.
- Moving pixels: use optical-flow magnitude/confidence to attenuate the effect only where motion exceeds a threshold.
- Moving object: estimate object-level displacement/velocity from mask centroid or robust flow statistics, then enable/scale the effect for the whole object when its motion exceeds threshold.
- Direction and speed outputs may drive glyph drift, directional rays, streaks or animation intensity.

This avoids a common failure: simply subtracting consecutive frames detects camera motion, flicker and lighting changes as movement. Use camera-motion compensation or robust background motion estimation where possible. Provide threshold, smoothing/hysteresis and minimum-motion duration to avoid mask/effect flicker.

## 5. Mask processing and effect integration

The tracker should output:
- Soft mask (float coverage 0..1), not only a hard binary matte.
- Optional hard/thresholded mask for crisp pixel-art looks.
- Confidence/validity map and lost-track state.
- Bounding box, centroid, scale/rotation approximation and motion vector per object/frame.
- Optional edge/distance field for outlines, glyph placement and feathering.

Mask controls:
- Expand/contract (morphology).
- Feather/softness.
- Edge cleanup and hole handling.
- Temporal smoothing.
- Mask opacity.
- Invert.
- Include/exclude selected objects.
- Background mode: untouched, effect-only, or effect outside subject.

All XAO engines consume a common mask interface. The compositor applies the mask in premultiplied-alpha/linear-light-aware order. Do not duplicate segmentation code inside each effect engine.

### Glyph placement modes
1. **Fill Subject:** distribute cells over the subject's mask; only cells with sufficient mask coverage render.
2. **Subject Center:** keep a glyph/text cluster anchored around the tracked centroid.
3. **Contour:** place glyphs along the mask boundary.
4. **Motion Trail:** optional glyph echoes along the tracked motion path, separately controlled from the mask.
5. **Source-Sampled Glyphs:** sample colour/luminance from the source at each cell while clipping the output to the subject mask.

Cell placement should be stable in source coordinates so glyphs do not crawl randomly between frames. Optional object-relative coordinates can normalize the grid to the tracked bounding box; expose this as a deliberate mode, not an implicit behavior.

## 6. After Effects architecture and MFR safety

Critical rule: AI inference and temporal propagation must not run as mutable state inside Smart Render.

Recommended pipeline:
- Analyze phase: read source frames in timestamp order, run segmentation/tracking, write an immutable mask sequence/cache.
- Render phase: Smart Pre-Render captures an immutable tracker-cache reference/version and time mapping.
- Smart Render: read-only lookup/interpolation of the mask for the requested absolute source time, then apply effects.
- Cache keys include source footage identity/version, interpretation, frame rate/time remap, in/out range, prompts, model/checkpoint hash, model settings, mask refinements and algorithm version.
- Cache entries are indexed by absolute source time or exact source-frame identity, never by assumed 30 fps or render order.
- Support reverse playback, time remapping, duplicate frames, non-integer frame rates and out-of-order frame requests.
- Do not let two concurrent frames mutate one tracking session. Any cache writes occur in the analysis process, not in render callbacks.
- If a frame has no valid mask, use an explicit policy: hold last valid mask only within a configured gap, fade confidence, or disable the effect. Never silently reuse an unrelated frame's mask.

This is necessary because AE Multi-Frame Rendering may request frames concurrently and out of chronological order. The tracker must be deterministic for a given source, settings and time.

## 7. Performance plan for modest CPU hardware

- Analyse at configurable proxy resolution (for example 25%, 50%, 75%, 100%); map masks back with correct source dimensions and pixel aspect.
- Process keyframes at a configurable stride, with temporal propagation/interpolation between them.
- Add user-triggered correction keyframes when confidence drops.
- Reuse image embeddings/features where the model permits.
- Tile/stream large clips where supported; cap memory and cache size.
- Provide low/medium/high quality presets and a clear estimated analysis cost.
- Never block AE's UI or render thread with model inference.
- Allow analysis cancellation and resume from verified cache checkpoints.

Do not promise real-time performance on an older Intel CPU before benchmarking the actual selected model and hardware. The feature can be useful as an offline analysis stage even if it is not real-time.

## 8. Failure cases and required recovery

Test:
- Occlusion and reappearance.
- Similar-looking multiple subjects crossing.
- Fast motion and motion blur.
- Camera pan/zoom/handheld shake.
- Subject leaving and re-entering frame.
- Lighting/color changes and low contrast.
- Thin objects, hair, transparent/reflective regions.
- Long clips and frame-rate/time-remap changes.
- Multiple selected objects and add/remove prompts mid-clip.

Provide confidence visualization and correction prompts on any frame. SAM 2's own publication notes failure modes such as drastic viewpoint changes, long occlusions, crowded similar objects and long videos; interactive correction is part of the intended workflow.

## 9. UI proposal

Smart Object Tracker panel:
- Enable Tracker
- Analyze / Re-analyze / Cancel
- Select Object (click / box)
- Add / Remove Object
- Positive / Negative Correction
- Track Forward / Backward / Both
- Analysis Resolution
- Analysis Quality / Frame Step
- Motion Gate (Off / Moving Pixels / Moving Object)
- Motion Threshold / Smoothing
- Mask Expand / Contract / Feather
- Show Mask / Show Confidence / Show Motion Vectors
- Cache Location / Clear Cache

Keep this panel separate from the shared XAO engine controls. Effects should expose only a compact "Use Smart Mask" selector and optional object ID/mask mode, not duplicate the entire tracker UI.

## 10. Acceptance tests

Before release:
- Same source/time/settings produces identical mask and render when frames are requested in random order.
- Parallel MFR output matches sequential output.
- Reverse and time-remapped footage uses correct source-time masks.
- Mask edges remain stable under camera movement and temporary occlusion.
- Background pixels remain untouched when mask-only mode is selected.
- Multiple objects retain stable IDs through crossing/occlusion, or visibly report lost confidence.
- CPU-only operation works without CUDA/DirectML/NPU.
- Analysis cancellation, cache invalidation and project reopen are safe.
- No model inference occurs in Smart Render.
- AE load/apply/render tests pass on the target AE 2023 / Windows 11 x64 environment.

## 11. Current status

This is a feature architecture proposal only. No tracker has been implemented, model selected for production, performance benchmarked, or AE runtime tested. SAM 2 is the initial research candidate, not a final dependency decision.
