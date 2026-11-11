const video = document.querySelector("#cameraVideo");
const output = document.querySelector("#asciiCanvas");
const sample = document.querySelector("#sampleCanvas");
const outCtx = output.getContext("2d", { alpha: false });
const sampleCtx = sample.getContext("2d", { willReadFrequently: true });

const controls = {
  start: document.querySelector("#startBtn"),
  stop: document.querySelector("#stopBtn"),
  snapshot: document.querySelector("#snapshotBtn"),
  mobileSnapshot: document.querySelector("#mobileSnapshotBtn"),
  copy: document.querySelector("#copyBtn"),
  mode: document.querySelector("#mode"),
  detail: document.querySelector("#detail"),
  contrast: document.querySelector("#contrast"),
  brightness: document.querySelector("#brightness"),
  edgeThreshold: document.querySelector("#edgeThreshold"),
  color: document.querySelector("#colorToggle"),
  mirror: document.querySelector("#mirrorToggle"),
  invert: document.querySelector("#invertToggle"),
  status: document.querySelector("#status"),
  fps: document.querySelector("#fps"),
  empty: document.querySelector("#emptyState"),
  message: document.querySelector("#cameraMessage"),
};

const ramps = {
  luminance: " .'`^\",:;Il!i><~+_-?][}{1)(|/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$",
  blocks: "  ░▒▓█",
};

let stream = null;
let frameHandle = 0;
let lastFrameTime = 0;
let lastAsciiText = "";

const preferredCamera = {
  video: { width: { ideal: 1280 }, height: { ideal: 720 }, facingMode: "user" },
  audio: false,
};

function setStatus(text) {
  controls.status.textContent = text;
}

function setSnapshotDisabled(disabled) {
  controls.snapshot.disabled = disabled;
  controls.mobileSnapshot.disabled = disabled;
}

function setCameraMessage(text, tone = "info") {
  controls.message.textContent = text;
  controls.message.dataset.tone = tone;
  controls.message.classList.toggle("hidden", !text);
}

function getCameraSupportProblem() {
  if (!window.isSecureContext) {
    return "Camera access needs HTTPS or localhost. Open the live site or serve docs/ from localhost.";
  }
  if (!navigator.mediaDevices || typeof navigator.mediaDevices.getUserMedia !== "function") {
    return "This browser does not expose camera access. Try Chrome, Edge, Firefox, or Safari.";
  }
  return "";
}

function cameraErrorMessage(error) {
  switch (error.name) {
    case "NotAllowedError":
    case "SecurityError":
      return "Camera permission was blocked. Allow camera access from the browser address bar, then press Start Camera again.";
    case "NotFoundError":
    case "DevicesNotFoundError":
      return "No camera was found on this device.";
    case "NotReadableError":
    case "TrackStartError":
      return "The camera is busy in another app or browser tab.";
    case "OverconstrainedError":
    case "ConstraintNotSatisfiedError":
      return "The browser could not use the requested camera settings.";
    default:
      return "Camera could not start. Check browser permissions and try again.";
  }
}

function waitForVideoReady() {
  if (video.readyState >= HTMLMediaElement.HAVE_METADATA) {
    return Promise.resolve();
  }

  return new Promise((resolve, reject) => {
    const timeout = window.setTimeout(() => {
      cleanup();
      reject(new Error("Camera stream did not become ready."));
    }, 5000);

    const done = () => {
      cleanup();
      resolve();
    };

    const failed = () => {
      cleanup();
      reject(video.error || new Error("Camera video failed to load."));
    };

    function cleanup() {
      window.clearTimeout(timeout);
      video.removeEventListener("loadedmetadata", done);
      video.removeEventListener("canplay", done);
      video.removeEventListener("error", failed);
    }

    video.addEventListener("loadedmetadata", done, { once: true });
    video.addEventListener("canplay", done, { once: true });
    video.addEventListener("error", failed, { once: true });
  });
}

async function requestCameraStream() {
  try {
    return await navigator.mediaDevices.getUserMedia(preferredCamera);
  } catch (error) {
    if (error.name === "OverconstrainedError" || error.name === "ConstraintNotSatisfiedError") {
      return navigator.mediaDevices.getUserMedia({ video: true, audio: false });
    }
    throw error;
  }
}

function resizeCanvas() {
  const rect = output.getBoundingClientRect();
  const dpr = window.devicePixelRatio || 1;
  const width = Math.max(320, Math.round(rect.width * dpr));
  const height = Math.max(180, Math.round(rect.height * dpr));
  if (output.width !== width || output.height !== height) {
    output.width = width;
    output.height = height;
  }
}

function tone(value) {
  const contrast = Number(controls.contrast.value) / 100;
  const brightness = Number(controls.brightness.value);
  const adjusted = (value - 128) * contrast + 128 + brightness;
  const clamped = Math.max(0, Math.min(255, adjusted));
  return controls.invert.checked ? 255 - clamped : clamped;
}

function glyphFor(value, ramp) {
  const index = Math.round((value / 255) * (ramp.length - 1));
  return ramp[Math.max(0, Math.min(ramp.length - 1, index))];
}

function edgeGlyph(gray, x, y, cols) {
  const idx = y * cols + x;
  const left = gray[idx - 1] ?? gray[idx];
  const right = gray[idx + 1] ?? gray[idx];
  const up = gray[idx - cols] ?? gray[idx];
  const down = gray[idx + cols] ?? gray[idx];
  const dx = right - left;
  const dy = down - up;
  const magnitude = Math.sqrt(dx * dx + dy * dy);
  if (magnitude < Number(controls.edgeThreshold.value)) return null;

  let angle = Math.atan2(dy, dx) * 180 / Math.PI;
  if (angle < 0) angle += 180;
  if (angle < 22.5 || angle >= 157.5) return "|";
  if (angle < 67.5) return "/";
  if (angle < 112.5) return "-";
  return "\\";
}

function coverSourceRect(sourceWidth, sourceHeight, targetWidth, targetHeight) {
  if (!sourceWidth || !sourceHeight || !targetWidth || !targetHeight) {
    return null;
  }

  const sourceRatio = sourceWidth / sourceHeight;
  const targetRatio = targetWidth / targetHeight;
  let width = sourceWidth;
  let height = sourceHeight;
  let x = 0;
  let y = 0;

  if (sourceRatio > targetRatio) {
    width = sourceHeight * targetRatio;
    x = (sourceWidth - width) / 2;
  } else {
    height = sourceWidth / targetRatio;
    y = (sourceHeight - height) / 2;
  }

  return { x, y, width, height };
}

function drawFrame(now = performance.now()) {
  if (!stream) return;
  if (video.readyState < HTMLMediaElement.HAVE_CURRENT_DATA) {
    frameHandle = requestAnimationFrame(drawFrame);
    return;
  }

  resizeCanvas();

  const charSize = Number(controls.detail.value);
  const fontSize = charSize * (window.devicePixelRatio || 1);
  const cols = Math.max(24, Math.floor(output.width / fontSize));
  const rows = Math.max(12, Math.floor(output.height / (fontSize * 1.55)));
  sample.width = cols;
  sample.height = rows;
  const sourceRect = coverSourceRect(video.videoWidth, video.videoHeight, cols, rows);
  if (!sourceRect) {
    frameHandle = requestAnimationFrame(drawFrame);
    return;
  }

  sampleCtx.save();
  if (controls.mirror.checked) {
    sampleCtx.translate(cols, 0);
    sampleCtx.scale(-1, 1);
  }
  try {
    sampleCtx.drawImage(
      video,
      sourceRect.x,
      sourceRect.y,
      sourceRect.width,
      sourceRect.height,
      0,
      0,
      cols,
      rows
    );
  } catch (error) {
    sampleCtx.restore();
    frameHandle = requestAnimationFrame(drawFrame);
    return;
  }
  sampleCtx.restore();

  const pixels = sampleCtx.getImageData(0, 0, cols, rows).data;
  const gray = new Float32Array(cols * rows);
  for (let i = 0, cell = 0; i < pixels.length; i += 4, cell++) {
    gray[cell] = 0.2126 * pixels[i] + 0.7152 * pixels[i + 1] + 0.0722 * pixels[i + 2];
  }

  outCtx.fillStyle = "#050305";
  outCtx.fillRect(0, 0, output.width, output.height);
  outCtx.font = `${fontSize}px "Cascadia Mono", Consolas, monospace`;
  outCtx.textBaseline = "top";

  const mode = controls.mode.value;
  const ramp = mode === "blocks" ? ramps.blocks : ramps.luminance;
  const cellW = output.width / cols;
  const cellH = output.height / rows;
  const lines = [];

  for (let y = 0; y < rows; y++) {
    let line = "";
    for (let x = 0; x < cols; x++) {
      const cell = y * cols + x;
      const p = cell * 4;
      const value = tone(gray[cell]);
      const edge = mode === "edge" ? edgeGlyph(gray, x, y, cols) : null;
      const glyph = edge ?? glyphFor(value, ramp);
      line += glyph;

      if (controls.color.checked) {
        outCtx.fillStyle = `rgb(${pixels[p]}, ${pixels[p + 1]}, ${pixels[p + 2]})`;
      } else {
        outCtx.fillStyle = "#ffb7d5";
      }
      outCtx.fillText(glyph, x * cellW, y * cellH);
    }
    lines.push(line);
  }

  lastAsciiText = lines.join("\n");
  if (lastFrameTime) {
    const fps = Math.round(1000 / Math.max(1, now - lastFrameTime));
    controls.fps.textContent = `${fps} FPS`;
  }
  lastFrameTime = now;
  frameHandle = requestAnimationFrame(drawFrame);
}

async function startCamera() {
  const supportProblem = getCameraSupportProblem();
  if (supportProblem) {
    setStatus("camera unavailable");
    setCameraMessage(supportProblem, "error");
    return;
  }

  try {
    controls.start.disabled = true;
    setStatus("starting");
    setCameraMessage("");
    stream = await requestCameraStream();
    video.srcObject = stream;
    await waitForVideoReady();
    await video.play();
    controls.empty.classList.add("hidden");
    controls.stop.disabled = false;
    setSnapshotDisabled(false);
    controls.copy.disabled = false;
    setStatus("live");
    lastFrameTime = 0;
    cancelAnimationFrame(frameHandle);
    frameHandle = requestAnimationFrame(drawFrame);
  } catch (error) {
    console.error("Camera start failed", error);
    if (stream) {
      for (const track of stream.getTracks()) track.stop();
    }
    stream = null;
    video.srcObject = null;
    controls.empty.classList.remove("hidden");
    controls.start.disabled = false;
    controls.stop.disabled = true;
    setSnapshotDisabled(true);
    controls.copy.disabled = true;
    const blocked = error.name === "NotAllowedError" || error.name === "SecurityError";
    setStatus(blocked ? "camera blocked" : "camera unavailable");
    setCameraMessage(cameraErrorMessage(error), "error");
  }
}

function stopCamera() {
  cancelAnimationFrame(frameHandle);
  if (stream) {
    for (const track of stream.getTracks()) track.stop();
  }
  stream = null;
  video.srcObject = null;
  controls.empty.classList.remove("hidden");
  controls.start.disabled = false;
  controls.stop.disabled = true;
  setSnapshotDisabled(true);
  controls.copy.disabled = true;
  controls.fps.textContent = "0 FPS";
  setCameraMessage("");
  setStatus("idle");
}

function downloadSnapshot() {
  const link = document.createElement("a");
  link.download = "ascii-camera.png";
  link.href = output.toDataURL("image/png");
  link.click();
}

async function copyAscii() {
  if (!lastAsciiText) return;
  try {
    await navigator.clipboard.writeText(lastAsciiText);
    setStatus("copied");
    setTimeout(() => {
      if (stream) setStatus("live");
    }, 900);
  } catch (error) {
    console.error("Copy failed", error);
    setStatus("copy unavailable");
    setCameraMessage("Clipboard access is blocked in this browser context.", "error");
  }
}

controls.start.addEventListener("click", startCamera);
controls.stop.addEventListener("click", stopCamera);
controls.snapshot.addEventListener("click", downloadSnapshot);
controls.mobileSnapshot.addEventListener("click", downloadSnapshot);
controls.copy.addEventListener("click", copyAscii);
window.addEventListener("resize", resizeCanvas);
resizeCanvas();

const supportProblem = getCameraSupportProblem();
if (supportProblem) {
  setStatus("camera unavailable");
  setCameraMessage(supportProblem, "error");
}
