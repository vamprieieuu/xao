#!/usr/bin/env python3
"""Generate the binary PiPL resource for the XAO ASCII After Effects plug-in.

The layout below (10-byte header, then 'MIB8' + key + 0 + length + value
properties) is the layout of the shipping YMDithers AEX from the reference
repository; regenerating that plug-in's resource with this same writer
reproduces the bytes embedded in the real .aex exactly (see
tools/verify_aex.py, which reads the resource back out of a built binary).

PiPLtool.exe is no longer used; it is not part of the SDK layout this project
builds against, and its output could not be verified here.

All metadata comes from ae/XAO_Ascii.h so the resource cannot drift from the
C++ side.  Missing defines are a hard error.
"""

import argparse
import os
import re
import struct
import sys


def define(text, name):
    match = re.search(r"^#define\s+" + re.escape(name) + r"\s+(.+?)\s*$", text, re.M)
    if not match:
        sys.exit("pipl_gen: XAO_Ascii.h does not define " + name)
    return match.group(1).strip()


def string_define(text, name):
    raw = define(text, name)
    if not (raw.startswith('"') and raw.endswith('"')):
        sys.exit("pipl_gen: " + name + " is not a string literal")
    return raw[1:-1]


def int_define(text, name):
    raw = define(text, name).split("/*")[0].strip().rstrip("uUlL")
    try:
        return int(raw, 0)
    except ValueError:
        sys.exit("pipl_gen: " + name + " is not an integer: " + raw)


def ps(value):
    """Pascal string, padded to a 4-byte boundary."""
    body = bytes([len(value)]) + value.encode("latin-1")
    return body + b"\0" * ((-len(body)) % 4)


def flag_define(text, name):
    return int_define(text, name)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--header", required=True)
    parser.add_argument("--rc", required=True)
    parser.add_argument("--bin", required=True)
    args = parser.parse_args()

    with open(args.header, "r", encoding="utf-8") as handle:
        header = handle.read()

    name = string_define(header, "XAO_ASCII_NAME")
    match_name = string_define(header, "XAO_ASCII_MATCH_NAME")
    category = string_define(header, "XAO_ASCII_CATEGORY")
    support_url = string_define(header, "XAO_PIPL_SUPPORT_URL")

    effect_version = int_define(header, "XAO_PIPL_EFFECT_VERSION")
    out_flags = int_define(header, "XAO_PIPL_OUT_FLAGS")
    out_flags2 = int_define(header, "XAO_PIPL_OUT_FLAGS2")

    pipl_major = int_define(header, "XAO_PIPL_VERSION_MAJOR")
    pipl_minor = int_define(header, "XAO_PIPL_VERSION_MINOR")
    spec_major = int_define(header, "XAO_PIPL_SPEC_MAJOR")
    spec_minor = int_define(header, "XAO_PIPL_SPEC_MINOR")

    if not 0 <= effect_version <= 0xFFFFFFFF:
        sys.exit("pipl_gen: effect version does not fit in 32 bits")
    if not 0 <= out_flags <= 0xFFFFFFFF or not 0 <= out_flags2 <= 0xFFFFFFFF:
        sys.exit("pipl_gen: output flags do not fit in 32 bits")

    props = [
        ("dnik", b"TKFe"),                                   # Kind: AEEffect
        ("eman", ps(name)),                                  # Name
        ("gtac", ps(category)),                              # Category
        ("4668", b"EffectMain\0\0"),                         # CodeWin64X86
        ("RVPe", struct.pack("<I", pipl_major)),             # AE_PiPL_Version
        ("RVSe", struct.pack("<HH", spec_major, spec_minor)),  # AE_Effect_Spec_Version
        ("REVe", effect_version.to_bytes(4, "big")),         # AE_Effect_Version
        ("FNIe", b"\0\0"),                                   # AE_Effect_Info_Flags
        ("OLGe", struct.pack("<I", out_flags)),              # AE_Effect_Global_OutFlags
        ("2LGe", struct.pack("<I", out_flags2)),             # AE_Effect_Global_OutFlags_2
        ("ANMe", ps(match_name)),                            # AE_Effect_Match_Name
        ("LFea", struct.pack("<I", 8)),                      # AE_Reserved_Info
        ("LRUe", ps(support_url)),                           # AE_Effect_Support_URL
    ]

    blob = bytearray(struct.pack("<IHH", 1, 0, len(props)) + b"\0\0")
    for key, value in props:
        blob += b"MIB8" + key.encode("latin1")
        blob += struct.pack("<II", 0, len(value))
        blob += value + b"\0" * ((-len(value)) % 4)

    bin_path = os.path.abspath(args.bin)
    rc_path = os.path.abspath(args.rc)
    os.makedirs(os.path.dirname(bin_path), exist_ok=True)
    os.makedirs(os.path.dirname(rc_path), exist_ok=True)

    with open(bin_path, "wb") as handle:
        handle.write(blob)
    with open(rc_path, "w", encoding="utf-8") as handle:
        handle.write("LANGUAGE 9, 1\n")
        handle.write('16000 PIPL "%s"\n' % bin_path.replace(os.sep, "/"))

    if pipl_minor != 0:
        sys.exit("pipl_gen: AE_PiPL_Version minor must be 0 for AE 2023+")

    print("pipl_gen: %d bytes, %d properties, name=%s, out_flags=0x%08x, out_flags2=0x%08x"
          % (len(blob), len(props), name, out_flags, out_flags2))


if __name__ == "__main__":
    main()
