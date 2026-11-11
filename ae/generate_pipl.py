#!/usr/bin/env python3
"""Generate the XAO-owned Windows PiPL resource without bundling Adobe binaries."""
from __future__ import annotations
import os
import struct
import sys

def pascal(text: str) -> bytes:
    raw = text.encode("latin-1")
    data = bytes((len(raw),)) + raw
    return data + b"\0" * ((-len(data)) % 4)

def make_resource() -> bytes:
    properties = [
        (b"dnik", b"TKFe"),
        (b"eman", pascal("XAO ASCII")),
        (b"gtac", pascal("Stylize")),
        (b"4668", b"EffectMain\0\0"),
        (b"RVPe", struct.pack("<I", 2)),
        (b"RVSe", struct.pack("<HH", 13, 28)),
        (b"REVe", struct.pack("<I", 0x00080001)),
        (b"FNIe", b"\0\0"),
        (b"OLGe", struct.pack("<I", 0x02000000)),
        (b"2LGe", struct.pack("<I", 0x08001400)),
        (b"ANMe", pascal("XAO_ASCII")),
        (b"LFea", struct.pack("<I", 0)),
        (b"LRUe", pascal("https://github.com/vamprieieuu/xao")),
    ]
    payload = bytearray(struct.pack("<IHH", 1, 0, len(properties)) + b"\0\0")
    for key, value in properties:
        payload += b"MIB8" + key + struct.pack("<II", 0, len(value)) + value
        payload += b"\0" * ((-len(value)) % 4)
    return bytes(payload)

def main() -> int:
    if len(sys.argv) != 3:
        print("usage: generate_pipl.py <output.rc> <output.bin>", file=sys.stderr)
        return 2
    rc_path, bin_path = map(os.path.abspath, sys.argv[1:])
    os.makedirs(os.path.dirname(rc_path), exist_ok=True)
    os.makedirs(os.path.dirname(bin_path), exist_ok=True)
    data = make_resource()
    with open(bin_path, "wb") as f:
        f.write(data)
    with open(rc_path, "w", encoding="ascii", newline="\n") as f:
        f.write("LANGUAGE 9, 1\n")
        f.write(f'16000 PIPL "{bin_path.replace(os.sep, "/")}"\n')
    print(f"Generated XAO PiPL resource ({len(data)} bytes).")
    return 0

if __name__ == "__main__":
    raise SystemExit(main())
