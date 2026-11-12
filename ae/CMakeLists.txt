cmake_minimum_required(VERSION 3.20)
project(XAO_ASCII_Plugin LANGUAGES CXX)

# Native After Effects plug-in build.
#
# Requirements:
#   * Windows x64, Visual Studio 2022 (v143) or newer
#   * The Adobe After Effects SDK (23.2.1 / AE 2023 or newer)
#   * AE_SDK_PATH pointing at the extracted SDK root, which must contain
#     Examples/Headers and Examples/Resources/PiPLtool.exe
#
# Configure with, for example:
#   cmake -S ae -B build-aex -G "Visual Studio 17 2022" -A x64 ^
#         -DAE_SDK_PATH="C:/AE_SDK/AfterEffectsSDK"

if(NOT DEFINED AE_SDK_PATH)
    message(FATAL_ERROR
        "AE_SDK_PATH is not set. Point it at the After Effects SDK root "
        "(the folder that contains Examples/Headers).")
endif()

set(AE_HEADERS "${AE_SDK_PATH}/Examples/Headers")
if(NOT EXISTS "${AE_HEADERS}/AE_Effect.h")
    message(FATAL_ERROR "AE_Effect.h not found under ${AE_HEADERS}")
endif()

set(XAO_CORE_SOURCES
    ../core/src/Image.cpp
    ../core/src/Compositor.cpp
    ../core/src/Pipeline.cpp
    ../core/src/ascii/Text.cpp
    ../core/src/ascii/Shaping.cpp
    ../core/src/ascii/Atlas.cpp
    ../core/src/ascii/AtlasData.cpp
    ../core/src/ascii/GlyphSets.cpp
    ../core/src/ascii/Palette.cpp
    ../core/src/ascii/AsciiEngine.cpp)

# PiPL: AE requires the resource in a compiled form on Windows.  The SDK ships
# PiPLtool, which converts the .r template into an .rc the MSVC resource
# compiler can consume.
find_program(PIPLTOOL_EXE NAMES PiPLtool.exe PiPLtool
             HINTS "${AE_SDK_PATH}/Examples/Resources")
if(NOT PIPLTOOL_EXE)
    message(FATAL_ERROR
        "PiPLtool was not found under ${AE_SDK_PATH}/Examples/Resources. "
        "It is required to build the PiPL resource.")
endif()

set(PIPL_RC "${CMAKE_CURRENT_BINARY_DIR}/XAO_PiPL.rc")
add_custom_command(
    OUTPUT "${PIPL_RC}"
    COMMAND "${PIPLTOOL_EXE}" "${CMAKE_CURRENT_SOURCE_DIR}/XAO_PiPL.r" "${PIPL_RC}"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/XAO_PiPL.r"
    COMMENT "Compiling XAO PiPL resource"
    VERBATIM)

add_library(XAO_ASCII SHARED
    XAO_Ascii.cpp
    ${XAO_CORE_SOURCES}
    "${PIPL_RC}")

set_target_properties(XAO_ASCII PROPERTIES
    PREFIX ""
    SUFFIX ".aex"
    OUTPUT_NAME "XAO"
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)

target_include_directories(XAO_ASCII PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}"
    "${AE_HEADERS}"
    "${AE_HEADERS}/SP"
    "${AE_HEADERS}/Win"
    "${CMAKE_CURRENT_SOURCE_DIR}/../core/include")

target_compile_definitions(XAO_ASCII PRIVATE
    AE_OS_WIN
    MSWindows
    WINDOWS
    _WINDOWS
    AE_PLUGIN_BUILD
    NOMINMAX
    WIN32_LEAN_AND_MEAN)

if(MSVC)
    target_compile_options(XAO_ASCII PRIVATE /W4 /permissive- /EHsc /MP)
    # One definition of the AE entry points; no static CRT mismatch.
    target_link_options(XAO_ASCII PRIVATE /SUBSYSTEM:WINDOWS)
endif()

install(TARGETS XAO_ASCII RUNTIME DESTINATION ".")
