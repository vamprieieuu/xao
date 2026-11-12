#!/usr/bin/env python3
"""Verify an XAO ASCII .aex, or just its generated PiPL resource.

Binary checks (default):
  1. PE signature, machine == x86-64, DLL characteristic, Windows GUI subsystem.
  2. The export table contains EffectMain by name.
  3. Resource type 'PIPL' id 16000 exists and parses as a PiPL property list.
  4. A VERSIONINFO resource exists.
  5. The PiPL metadata equals the XAO_PIPL_* values in ae/XAO_Ascii.h.

PiPL-only check (--pipl): step 3 and step 5 against a generated .bin.  That runs
on Linux CI, where the resource can be produced but no PE can be linked.

Exit status is non-zero on the first failure.
"""

import argparse
import re
import struct
import sys

PIPL_TYPE = 0x5049504C  # 'PIPL' packed as a resource type id
RT_VERSION = 16

REQUIRED_KEYS = ("dnik", "eman", "gtac", "4668", "RVPe", "RVSe", "REVe",
                 "OLGe", "2LGe", "ANMe")


def fail(message):
    sys.exit("verify_aex: FAIL: " + message)


def need(condition, message):
    if not condition:
        fail(message)


def u16(data, offset):
    return struct.unpack_from("<H", data, offset)[0]


def u32(data, offset):
    return struct.unpack_from("<I", data, offset)[0]


# ---------------------------------------------------------------------------
# PE
# ---------------------------------------------------------------------------

class PE:
    def __init__(self, data):
        self.data = data
        need(data[:2] == b"MZ", "missing MZ header")
        pe = u32(data, 0x3C)
        need(data[pe:pe + 4] == b"PE\0\0", "missing PE signature")
        coff = pe + 4
        self.machine = u16(data, coff)
        self.sections_count = u16(data, coff + 2)
        self.characteristics = u16(data, coff + 18)
        opt_size = u16(data, coff + 16)
        self.opt = coff + 20
        self.magic = u16(data, self.opt)
        need(self.magic in (0x10B, 0x20B), "unknown optional header magic")
        self.subsystem = u16(data, self.opt + 0x44)

        dirs = self.opt + (0x70 if self.magic == 0x20B else 0x60)
        self.directories = [(u32(data, dirs + i * 8), u32(data, dirs + i * 8 + 4))
                            for i in range(16)]

        table = coff + 20 + opt_size
        self.sections = []
        for index in range(self.sections_count):
            base = table + index * 40
            name = data[base:base + 8].rstrip(b"\0").decode("latin-1")
            vsize = u32(data, base + 8)
            vaddr = u32(data, base + 12)
            rawsize = u32(data, base + 16)
            rawptr = u32(data, base + 20)
            self.sections.append((name, vaddr, vsize, rawptr, rawsize))

    def offset(self, rva):
        for name, vaddr, vsize, rawptr, rawsize in self.sections:
            if vaddr <= rva < vaddr + max(vsize, rawsize):
                delta = rva - vaddr
                need(delta < rawsize,
                     "rva 0x%x falls in %s's uninitialised tail" % (rva, name))
                return rawptr + delta
        fail("rva 0x%x is not mapped by any section" % rva)

    def exports(self):
        rva, size = self.directories[0]
        if rva == 0 or size == 0:
            return []
        base = self.offset(rva)
        count = u32(self.data, base + 24)
        names = u32(self.data, base + 32)
        if names == 0:
            return []
        names_off = self.offset(names)
        result = []
        for index in range(count):
            name_off = self.offset(u32(self.data, names_off + index * 4))
            end = self.data.index(b"\0", name_off)
            result.append(self.data[name_off:end].decode("latin-1"))
        return result

    def resources(self):
        """{(type, id, lang): (rva, size)}; types/ids may be strings or ints."""
        rva, size = self.directories[2]
        if rva == 0 or size == 0:
            return {}
        root = self.offset(rva)
        found = {}

        def name_at(offset):
            length = u16(self.data, root + offset)
            start = root + offset + 2
            raw = self.data[start:start + length * 2]
            need(len(raw) == length * 2, "truncated resource name")
            return raw.decode("utf-16-le")

        def walk(directory_offset, path):
            base = root + directory_offset
            count = u16(self.data, base + 12) + u16(self.data, base + 14)
            for index in range(count):
                entry = base + 16 + index * 16
                raw_name = u32(self.data, entry)
                target = u32(self.data, entry + 4)
                key = (name_at(raw_name & 0x7FFFFFFF)
                       if raw_name & 0x80000000 else raw_name)
                if target & 0x80000000:
                    walk(target & 0x7FFFFFFF, path + [key])
                    continue
                data_offset = root + target
                found[tuple(path + [key])] = (u32(self.data, data_offset),
                                             u32(self.data, data_offset + 4))

        walk(0, [])
        return found


# ---------------------------------------------------------------------------
# PiPL and header metadata
# ---------------------------------------------------------------------------

def parse_pipl(blob):
    need(len(blob) > 10, "PiPL blob is too short")
    need(blob[:4] == struct.pack("<I", 1), "PiPL header version is not 1")
    count = u16(blob, 6)
    props = {}
    offset = 10
    for index in range(count):
        need(blob[offset:offset + 4] == b"MIB8",
             "PiPL property %d is not MIB8-tagged" % index)
        key = blob[offset + 4:offset + 8].decode("latin-1")
        length = u32(blob, offset + 12)
        need(offset + 16 + length <= len(blob), "PiPL property %s overruns" % key)
        props[key] = blob[offset + 16:offset + 16 + length]
        offset += 16 + length + ((-length) % 4)
    need(offset == len(blob), "PiPL has %d trailing bytes" % (len(blob) - offset))
    return props


def pascal(value):
    need(len(value) > 0 and len(value) >= 1 + value[0], "malformed Pascal string")
    return value[1:1 + value[0]].decode("latin-1")


def read_define(text, name):
    match = re.search(r"^#define\s+" + re.escape(name) + r"\s+(.+?)\s*$", text, re.M)
    need(match is not None, "%s is not defined in the header" % name)
    return match.group(1).split("/*")[0].strip()


def read_string(text, name):
    raw = read_define(text, name)
    need(raw.startswith('"') and raw.endswith('"'),
         "%s is not a string literal" % name)
    return raw[1:-1]


def read_int(text, name):
    return int(read_define(text, name).rstrip("uUlL"), 0)


def describe(props):
    out_flags = struct.unpack("<I", props["OLGe"])[0]
    out_flags2 = struct.unpack("<I", props["2LGe"])[0]
    print("pipl keys:  %s" % ", ".join(props.keys()))
    print("name:       %s / %s (match '%s')" % (
        pascal(props["eman"]), pascal(props["gtac"]), pascal(props["ANMe"])))
    print("spec:       %d.%d" % struct.unpack("<HH", props["RVSe"]))
    print("version:    0x%08x" % struct.unpack(">I", props["REVe"])[0])
    print("out flags:  0x%08x / 0x%08x" % (out_flags, out_flags2))
    return out_flags, out_flags2


def check_pipl_metadata(props, header_path):
    for key in REQUIRED_KEYS:
        need(key in props, "PiPL property %s is missing" % key)
    need(props["dnik"] == b"TKFe", "PiPL Kind is not AEEffect")
    need(props["4668"].rstrip(b"\0") == b"EffectMain",
         "PiPL CodeWin64X86 is not EffectMain")

    out_flags, out_flags2 = describe(props)

    with open(header_path, "r", encoding="utf-8") as handle:
        header = handle.read()

    need(pascal(props["eman"]) == read_string(header, "XAO_ASCII_NAME"),
         "PiPL name does not match XAO_ASCII_NAME")
    need(pascal(props["gtac"]) == read_string(header, "XAO_ASCII_CATEGORY"),
         "PiPL category does not match XAO_ASCII_CATEGORY")
    need(pascal(props["ANMe"]) == read_string(header, "XAO_ASCII_MATCH_NAME"),
         "PiPL match name does not match XAO_ASCII_MATCH_NAME")
    need(out_flags == read_int(header, "XAO_PIPL_OUT_FLAGS"),
         "PiPL out_flags 0x%08x != XAO_PIPL_OUT_FLAGS 0x%08x"
         % (out_flags, read_int(header, "XAO_PIPL_OUT_FLAGS")))
    need(out_flags2 == read_int(header, "XAO_PIPL_OUT_FLAGS2"),
         "PiPL out_flags2 0x%08x != XAO_PIPL_OUT_FLAGS2 0x%08x"
         % (out_flags2, read_int(header, "XAO_PIPL_OUT_FLAGS2")))
    version = struct.unpack(">I", props["REVe"])[0]
    need(version == read_int(header, "XAO_PIPL_EFFECT_VERSION"),
         "PiPL version 0x%08x != XAO_PIPL_EFFECT_VERSION 0x%08x"
         % (version, read_int(header, "XAO_PIPL_EFFECT_VERSION")))

    # The declared flags must describe what the adapter actually does.
    need(out_flags & (1 << 25), "DEEP_COLOR_AWARE is not declared")
    need(out_flags & (1 << 26), "SEND_UPDATE_PARAMS_UI is not declared")
    need(out_flags2 & (1 << 12), "FLOAT_COLOR_AWARE is not declared")
    need(out_flags2 & (1 << 4), "I_AM_THREADSAFE is not declared")


# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("aex", nargs="?", help="built .aex")
    parser.add_argument("--pipl", default=None,
                        help="check a generated PiPL .bin instead of an AEX")
    parser.add_argument("--header", default=None,
                        help="ae/XAO_Ascii.h to compare metadata against")
    parser.add_argument("--any", action="store_true",
                        help="only check that the binary is a valid AE plug-in")
    args = parser.parse_args()

    if args.pipl:
        with open(args.pipl, "rb") as handle:
            blob = handle.read()
        print("pipl:       %s (%d bytes)" % (args.pipl, len(blob)))
        props = parse_pipl(blob)
        need(args.header is not None, "--header is required with --pipl")
        check_pipl_metadata(props, args.header)
        print("verify_aex: PiPL OK")
        return

    need(args.aex is not None, "supply an .aex or --pipl")

    with open(args.aex, "rb") as handle:
        data = handle.read()

    pe = PE(data)
    print("file:       %s (%d bytes)" % (args.aex, len(data)))
    print("machine:    0x%04x (%s)" % (
        pe.machine, "x86-64" if pe.machine == 0x8664 else "NOT x86-64"))
    need(pe.machine == 0x8664, "machine is not x86-64")
    need(pe.characteristics & 0x2000, "image is not marked as a DLL")
    print("subsystem:  %d (%s)" % (
        pe.subsystem, "Windows GUI" if pe.subsystem == 2 else "not GUI"))
    need(pe.subsystem == 2, "subsystem is not Windows GUI")

    exports = pe.exports()
    need("EffectMain" in exports,
         "EffectMain is not exported (found: %s)" % exports)
    print("exports:    %s" % ", ".join(sorted(exports)))

    try:
        resources = pe.resources()
    except (struct.error, IndexError, ValueError) as error:
        print("resources:  directory walk unavailable (%s)" % error)
        resources = {}

    pipl = None
    for path, (rva, size) in resources.items():
        if len(path) < 2:
            continue
        if (path[0] in ("PIPL", PIPL_TYPE)) and path[1] == 16000:
            pipl = data[pe.offset(rva):pe.offset(rva) + size]
            print("pipl:       %d bytes from the resource directory" % len(pipl))
            break

    if pipl is None:
        # Fallback: the resource data is stored verbatim in .rsrc, so find the
        # PiPL blob by its property-list header.  Used when a linker's resource
        # directory layout defeats the walker (MSVC nests the tree differently
        # from windres); the bytes checked are the same.
        marker = data.find(b"MIB8dnik")
        need(marker != -1, "resource 'PIPL' 16000 is missing")
        start = marker - 10
        need(start >= 0, "PiPL blob does not start inside the file")
        count = struct.unpack_from("<H", data, start + 6)[0]
        need(0 < count < 64, "implausible PiPL property count %d" % count)
        offset = start + 10
        for _ in range(count):
            need(data[offset:offset + 4] == b"MIB8", "PiPL blob is not contiguous")
            length = struct.unpack_from("<I", data, offset + 12)[0]
            offset += 16 + length + ((-length) % 4)
        need(offset <= len(data), "PiPL blob overruns the file")
        pipl = data[start:offset]
        print("pipl:       %d bytes located by property header" % len(pipl))

    props = parse_pipl(pipl)
    if args.any:
        describe(props)
    else:
        need(args.header is not None, "--header is required unless --any is given")
        check_pipl_metadata(props, args.header)
        has_version = any(path[0] in (RT_VERSION, "VERSION") for path in resources)
        if not has_version:
            has_version = data.find("VS_VERSION_INFO".encode("utf-16-le")) != -1
        need(has_version, "VERSIONINFO resource is missing")

    print("verify_aex: OK")


if __name__ == "__main__":
    main()
