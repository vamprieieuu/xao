#!/usr/bin/env python3
from pathlib import Path
import sys
ROOT = Path(__file__).resolve().parents[1]
GROUPS = (("weird", 17000), ("english", 17100), ("arabic", 17200))
def main():
    if len(sys.argv) != 2:
        raise SystemExit("usage: generate_font_resources.py <output.rc>")
    output = Path(sys.argv[1]).resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    lines = ["// Embedded XAO glyph fonts. Resource IDs are stable and match Win32GlyphAtlas.cpp."]
    for folder, base in GROUPS:
        files = sorted((ROOT / "XAO" / "fonts" / folder).glob("*"))
        files = [p for p in files if p.is_file() and p.suffix.lower() in (".ttf", ".otf")]
        if len(files) > 99:
            raise SystemExit(f"Too many {folder} fonts for the assigned resource range")
        for index, path in enumerate(files, 1):
            escaped = str(path).replace("\\", "/").replace('"', '\\"')
            lines.append(f'{base + index} RCDATA "{escaped}"')
    output.write_text("\n".join(lines) + "\n", encoding="utf-8")
    print(f"Generated embedded font resources: {len(lines)-1} font files")
if __name__ == "__main__":
    main()
