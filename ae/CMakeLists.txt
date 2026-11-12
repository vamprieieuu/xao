cmake_minimum_required(VERSION 3.20)
project(XAO_ASCII_Plugin LANGUAGES CXX)

# Native After Effects plug-in build (Windows x64).
#
# Requirements:
#   * Windows x64, Visual Studio 2022 (v143) or newer
#   * The Adobe After Effects SDK laid out as Headers/ and Util/.  This is the
#     layout used by vamprieieuu/Dithering_MAJEED_build_ready in
#     extern/AfterEffectsSDK (Headers, Util, its own CMakeLists.txt).  The
#     older "Examples/Headers" layout is not used and not required.
#   * Python 3 for the PiPL generator (already on GitHub-hosted runners).
#
# Configure:
#   cmake -S ae -B build-aex -G "Visual Studio 17 2022" -A x64 ^
#         -DAE_SDK_PATH=C:/path/to/AfterEffectsSDK

if(NOT DEFINED AE_SDK_PATH)
    message(FATAL_ERROR
        "AE_SDK_PATH is not set. Point it at an After Effects SDK root that "
        "contains Headers/AE_Effect.h and Util/Param_Utils.h.")
endif()

get_filename_component(AE_SDK_PATH "${AE_SDK_PATH}" ABSOLUTE)

set(AE_HEADERS "${AE_SDK_PATH}/Headers")
set(AE_UTIL    "${AE_SDK_PATH}/Util")

if(NOT EXISTS "${AE_HEADERS}/AE_Effect.h")
    message(FATAL_ERROR "AE_Effect.h not found under ${AE_HEADERS}")
endif()
if(NOT EXISTS "${AE_UTIL}/Param_Utils.h")
    message(FATAL_ERROR "Param_Utils.h not found under ${AE_UTIL}")
endif()

if(NOT WIN32)
    message(FATAL_ERROR "The After Effects plug-in target is Windows x64 only.")
endif()

enable_language(RC)
find_package(Python3 REQUIRED COMPONENTS Interpreter)

set(XAO_AE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(XAO_CORE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../core")

set(PIPL_BIN "${CMAKE_CURRENT_BINARY_DIR}/XAO_PiPL.bin")
set(PIPL_RC  "${CMAKE_CURRENT_BINARY_DIR}/XAO_PiPL.rc")

# PiPL: a binary resource generated from ae/XAO_Ascii.h.  PiPLtool.exe is not
# part of the SDK layout this project builds against, so the resource is written
# directly.  See ae/pipl_gen.py and tools/verify_aex.py.
add_custom_command(
    OUTPUT "${PIPL_RC}" "${PIPL_BIN}"
    COMMAND "${Python3_EXECUTABLE}" "${XAO_AE_DIR}/pipl_gen.py"
            --header "${XAO_AE_DIR}/XAO_Ascii.h"
            --rc "${PIPL_RC}"
            --bin "${PIPL_BIN}"
    DEPENDS "${XAO_AE_DIR}/pipl_gen.py" "${XAO_AE_DIR}/XAO_Ascii.h"
    COMMENT "Generating XAO PiPL resource"
    VERBATIM)

add_library(XAO_ASCII SHARED
    XAO_Ascii.cpp
    XAO_Ascii.rc
    "${PIPL_RC}"
    "${XAO_CORE_DIR}/src/Image.cpp"
    "${XAO_CORE_DIR}/src/Compositor.cpp"
    "${XAO_CORE_DIR}/src/Pipeline.cpp"
    "${XAO_CORE_DIR}/src/ascii/Text.cpp"
    "${XAO_CORE_DIR}/src/ascii/Shaping.cpp"
    "${XAO_CORE_DIR}/src/ascii/Atlas.cpp"
    "${XAO_CORE_DIR}/src/ascii/AtlasData.cpp"
    "${XAO_CORE_DIR}/src/ascii/GlyphSets.cpp"
    "${XAO_CORE_DIR}/src/ascii/Palette.cpp"
    "${XAO_CORE_DIR}/src/ascii/AsciiEngine.cpp")

set_target_properties(XAO_ASCII PROPERTIES
    PREFIX ""
    SUFFIX ".aex"
    OUTPUT_NAME "XAO"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Release"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/Debug"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Release"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/Debug")

target_include_directories(XAO_ASCII PRIVATE
    "${XAO_AE_DIR}"
    "${AE_HEADERS}"
    "${AE_HEADERS}/SP"
    "${AE_UTIL}"
    "${XAO_CORE_DIR}/include")

target_compile_definitions(XAO_ASCII PRIVATE
    AE_OS_WIN
    MSWindows
    _WINDOWS
    WIN32
    _WIN32
    _WIN64
    AE_PLUGIN_BUILD
    _CRT_SECURE_NO_WARNINGS
    NOMINMAX
    WIN32_LEAN_AND_MEAN)

if(MSVC)
    # Static CRT so the plug-in does not depend on a runtime the host may not
    # have loaded.  Optimisation flags follow the proven reference build.
    set_property(TARGET XAO_ASCII PROPERTY
        MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    # C5033: the SDK's own headers use the 'register' keyword.
    target_compile_options(XAO_ASCII PRIVATE /W3 /wd5033 /EHsc /MP /O2 /fp:fast)
    # The AE SDK headers are C-era code; /permissive- is deliberately not used.
    target_link_options(XAO_ASCII PRIVATE
        /SUBSYSTEM:WINDOWS
        "/DEF:${XAO_AE_DIR}/XAO_Ascii.def")
endif()

install(TARGETS XAO_ASCII RUNTIME DESTINATION ".")
