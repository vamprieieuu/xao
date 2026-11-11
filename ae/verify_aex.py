#!/usr/bin/env python3
"""Strict PE32+ and embedded PiPL verification for XAO's native AE plug-in."""
from __future__ import annotations
import hashlib
import struct
import sys
from pathlib import Path

def fail(message: str) -> int:
    print(f"[FAIL] {message}", file=sys.stderr)
    return 1

def verify(aex_path: Path, pipl_path: Path) -> int:
    if not aex_path.is_file() or not pipl_path.is_file():
        return fail("AEX or generated PiPL binary is missing")
    data = aex_path.read_bytes()
    pipl = pipl_path.read_bytes()
    print(f"[INFO] AEX bytes={len(data)} SHA256={hashlib.sha256(data).hexdigest().upper()}")
    if len(data) < 0x100 or data[:2] != b"MZ":
        return fail("Not a valid PE/MZ image")
    peoff = struct.unpack_from("<I", data, 0x3C)[0]
    if peoff + 24 > len(data) or data[peoff:peoff+4] != b"PE\0\0":
        return fail("PE signature is missing or truncated")
    coff = peoff + 4
    machine, section_count = struct.unpack_from("<HH", data, coff)
    opt_size = struct.unpack_from("<H", data, coff + 16)[0]
    characteristics = struct.unpack_from("<H", data, coff + 18)[0]
    if machine != 0x8664:
        return fail(f"Expected AMD64/x64 image, got machine={machine:#06x}")
    if not (characteristics & 0x2000):
        return fail("PE image is not marked as a DLL")
    opt = coff + 20
    if opt + opt_size > len(data) or struct.unpack_from("<H", data, opt)[0] != 0x20B:
        return fail("Expected PE32+ optional header")
    subsystem = struct.unpack_from("<H", data, opt + 68)[0]
    sub_major, sub_minor = struct.unpack_from("<HH", data, opt + 48)
    if subsystem != 2 or sub_major < 6:
        return fail(f"Expected Windows GUI subsystem >=6.0, got {subsystem} {sub_major}.{sub_minor}")
    print(f"[OK] PE32+ AMD64 DLL; Windows GUI subsystem {sub_major}.{sub_minor}")
    sec_off = opt + opt_size
    sections = []
    rsrc = None
    for i in range(section_count):
        off = sec_off + i * 40
        if off + 40 > len(data):
            return fail("Section table is truncated")
        entry = data[off:off+40]
        name = entry[:8].rstrip(b"\0").decode("ascii", "replace")
        vsize, vaddr, raw_size, raw_ptr = struct.unpack_from("<IIII", entry, 8)
        section = {"name": name, "vaddr": vaddr, "vsize": vsize, "raw_size": raw_size, "raw_ptr": raw_ptr}
        sections.append(section)
        if name == ".rsrc":
            rsrc = section
    def rva_to_offset(rva: int):
        for section in sections:
            span = max(section["vsize"], section["raw_size"])
            if section["vaddr"] <= rva < section["vaddr"] + span:
                return section["raw_ptr"] + (rva - section["vaddr"])
        return None
    # Required exported AE entry points.
    export_rva = struct.unpack_from("<I", data, opt + 112)[0]
    if not export_rva:
        return fail("PE export directory is missing")
    exp_off = rva_to_offset(export_rva)
    if exp_off is None or exp_off + 40 > len(data):
        return fail("Cannot resolve PE export directory")
    fields = struct.unpack_from("<IIHHIIIIIII", data, exp_off)
    num_names, names_rva = fields[7], fields[9]
    names_off = rva_to_offset(names_rva)
    if names_off is None:
        return fail("Cannot resolve PE export names")
    exports = set()
    for i in range(num_names):
        name_rva = struct.unpack_from("<I", data, names_off + i * 4)[0]
        name_off = rva_to_offset(name_rva)
        if name_off is None:
            return fail("Cannot resolve an exported symbol name")
        end = data.find(b"\0", name_off, min(len(data), name_off + 512))
        if end < 0:
            return fail("Unterminated exported symbol")
        exports.add(data[name_off:end].decode("ascii", "replace"))
    for required in ("EffectMain", "PluginDataEntryFunction2"):
        if required not in exports:
            return fail(f"Required AE export missing: {required}")
    if any(token in name for name in exports for token in ("GCC", "Unwind", "emutls", "_ZN", "__gnu")):
        return fail("Unexpected compiler/internal symbol leaked into exports")
    print("[OK] Required exports present; no obvious MinGW/GCC exports")
    # Ensure the exact generated PiPL payload is embedded in the PE resource section.
    if rsrc is None:
        return fail("PE has no .rsrc section")
    start = rsrc["raw_ptr"]
    end = start + rsrc["raw_size"]
    if end > len(data):
        return fail("PE resource section extends beyond the file")
    resource_data = data[start:end]
    if pipl not in resource_data:
        return fail("The exact generated XAO PiPL payload is not embedded in .rsrc")
    if b"MIB8dnik" not in resource_data or b"XAO_ASCII" not in resource_data:
        return fail("XAO PiPL signature or match name is missing from .rsrc")
    if b"YMDithers" in resource_data:
        return fail("MAJEED/YMDithers identity leaked into XAO resources")
    print("[OK] Exact XAO PiPL payload embedded; no MAJEED effect identity")
    # Report imports and reject dynamic MSVC CRTs; XAO is built with the MAJEED /MT profile.
    import_rva = struct.unpack_from("<I", data, opt + 120)[0]
    imported = []
    if import_rva:
        import_off = rva_to_offset(import_rva)
        if import_off is None:
            return fail("Cannot resolve PE import directory")
        for i in range(4096):
            off = import_off + i * 20
            if off + 20 > len(data):
                return fail("Import table is truncated")
            desc = data[off:off+20]
            if desc == b"\0" * 20:
                break
            name_rva = struct.unpack_from("<I", desc, 12)[0]
            name_off = rva_to_offset(name_rva)
            if name_off is None:
                return fail("Cannot resolve imported DLL name")
            name_end = data.find(b"\0", name_off, min(len(data), name_off + 512))
            if name_end < 0:
                return fail("Unterminated imported DLL name")
            imported.append(data[name_off:name_end].decode("ascii", "replace"))
        else:
            return fail("Import table has no terminator")
    dynamic_crt = [name for name in imported if any(x in name.upper() for x in ("MSVCP", "VCRUNTIME"))]
    if dynamic_crt:
        return fail(f"Dynamic MSVC runtime DLLs found despite /MT: {dynamic_crt}")
    print(f"[OK] Runtime imports contain no dynamic MSVC CRT: {', '.join(imported)}")
    print("[PASS] XAO AEX PE, exports, embedded PiPL, architecture, and runtime checks passed")
    return 0

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("usage: verify_aex.py <XAO_ASCII.aex> <XAOAsciiPiPL.bin>", file=sys.stderr)
        raise SystemExit(2)
    raise SystemExit(verify(Path(sys.argv[1]), Path(sys.argv[2])))
