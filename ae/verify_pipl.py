#!/usr/bin/env python3
"""Validate the generated XAO PiPL binary against the AE adapter's declared flags."""
from __future__ import annotations
import struct
import sys
from pathlib import Path

def pstr(value: bytes) -> bytes:
    data = bytes([len(value)]) + value
    return data + b"\0" * ((-len(data)) % 4)

EXPECTED = {
    b"dnik": b"TKFe",
    b"eman": pstr(b"XAO"),
    b"gtac": pstr(b"Stylize"),
    b"4668": b"EffectMain\0\0",
    b"RVPe": struct.pack("<I", 2),
    b"RVSe": struct.pack("<HH", 13, 28),
    b"REVe": struct.pack("<I", 0x00088001),
    b"OLGe": struct.pack("<I", 0x02000000),
    b"2LGe": struct.pack("<I", 0x08001400),
    b"ANMe": pstr(b"XAO"),
    b"LFea": struct.pack("<I", 0),
}
def parse(data: bytes) -> dict[bytes, bytes]:
    if len(data) < 10:
        raise ValueError("PiPL resource is truncated")
    version, reserved, count = struct.unpack_from("<IHH", data, 0)
    if version != 1 or reserved != 0:
        raise ValueError("Unexpected PiPL resource header")
    pos = 10
    found = {}
    for _ in range(count):
        if pos + 16 > len(data) or data[pos:pos+4] != b"MIB8":
            raise ValueError("Malformed PiPL property record")
        key = data[pos+4:pos+8]
        _flags, size = struct.unpack_from("<II", data, pos+8)
        pos += 16
        if pos + size > len(data):
            raise ValueError(f"Truncated PiPL property {key!r}")
        found[key] = data[pos:pos+size]
        pos += size
        pos += (-size) % 4
    return found
def main() -> int:
    if len(sys.argv) != 2:
        print("usage: verify_pipl.py <XAOAsciiPiPL.bin>", file=sys.stderr)
        return 2
    data = Path(sys.argv[1]).read_bytes()
    actual = parse(data)
    for key, expected in EXPECTED.items():
        if actual.get(key) != expected:
            print(f"[FAIL] PiPL property {key!r}: expected {expected!r}, got {actual.get(key)!r}", file=sys.stderr)
            return 1
    print(f"[OK] PiPL metadata verified ({len(EXPECTED)} properties, {len(data)} bytes)")
    return 0
if __name__ == "__main__":
    raise SystemExit(main())
