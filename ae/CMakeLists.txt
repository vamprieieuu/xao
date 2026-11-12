cmake_minimum_required(VERSION 3.20)

project(XAO_ASCII LANGUAGES C CXX RC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

if(NOT WIN32)
    message(FATAL_ERROR "XAO ASCII AEX build requires Windows x64 MSVC.")
endif()

find_package(Python3 REQUIRED COMPONENTS Interpreter)

if(NOT DEFINED AE_SDK_PATH)
    message(FATAL_ERROR "AE_SDK_PATH must point to the pinned After Effects SDK root.")
endif()
get_filename_component(AE_SDK_PATH "${AE_SDK_PATH}" ABSOLUTE)
if(NOT EXISTS "${AE_SDK_PATH}/CMakeLists.txt")
    message(FATAL_ERROR "After Effects SDK CMakeLists.txt not found: ${AE_SDK_PATH}")
endif()

# Exact SDK CMake integration used by the known-good Dithering MAJEED project.
add_subdirectory("${AE_SDK_PATH}" "${CMAKE_CURRENT_BINARY_DIR}/extern/AfterEffectsSDK")

set(XAO_AE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(XAO_CORE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../core")
set(PIPL_BIN "${CMAKE_CURRENT_BINARY_DIR}/XAO_PiPL.bin")
set(PIPL_RC "${CMAKE_CURRENT_BINARY_DIR}/XAO_PiPL.rc")
set(PIPL_PY "${XAO_AE_DIR}/pipl_gen.py")

if(NOT EXISTS "${PIPL_PY}")
    message(FATAL_ERROR "PiPL generator not found: ${PIPL_PY}")
endif()

# Match MAJEED's proven, deterministic Python PiPL generation pipeline.
add_custom_command(
    OUTPUT "${PIPL_RC}" "${PIPL_BIN}"
    COMMAND "${Python3_EXECUTABLE}" "${PIPL_PY}"
            --header "${XAO_AE_DIR}/XAO_Ascii.h"
            --rc "${PIPL_RC}"
            --bin "${PIPL_BIN}"
    DEPENDS "${XAO_AE_DIR}/XAO_Ascii.h" "${PIPL_PY}"
    COMMENT "Generating XAO PiPL resource and binary"
    VERBATIM
)

add_library(XAO_ASCII SHARED
    "${PIPL_RC}"
    XAO_Ascii.rc
    XAO_Ascii.cpp
    "${XAO_CORE_DIR}/src/Image.cpp"
    "${XAO_CORE_DIR}/src/Compositor.cpp"
    "${XAO_CORE_DIR}/src/Pipeline.cpp"
    "${XAO_CORE_DIR}/src/ascii/Text.cpp"
    "${XAO_CORE_DIR}/src/ascii/Shaping.cpp"
    "${XAO_CORE_DIR}/src/ascii/Atlas.cpp"
    "${XAO_CORE_DIR}/src/ascii/AtlasData.cpp"
    "${XAO_CORE_DIR}/src/ascii/GlyphSets.cpp"
    "${XAO_CORE_DIR}/src/ascii/Palette.cpp"
    "${XAO_CORE_DIR}/src/ascii/AsciiEngine.cpp"
)

target_include_directories(XAO_ASCII PRIVATE
    "${CMAKE_CURRENT_BINARY_DIR}"
    "${XAO_AE_DIR}"
    "${XAO_CORE_DIR}/include"
    ${AESDK_INCLUDE}
)

target_link_libraries(XAO_ASCII PRIVATE AESDK)

target_compile_definitions(XAO_ASCII PRIVATE
    MSWindows
    _WINDOWS
    WIN32
    _WIN32
    _WIN64
    AE_OS_WIN
    _CRT_SECURE_NO_WARNINGS
)

if(MSVC)
    # Same static MSVC runtime and compiler settings as Dithering MAJEED.
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    target_compile_options(XAO_ASCII PRIVATE /W3 /EHsc /MT /O2 /fp:fast)
    target_link_options(XAO_ASCII PRIVATE
        /SUBSYSTEM:WINDOWS,6.00
        /OSVERSION:6.00
        /VERSION:6.00
        /MANIFEST:NO
        /DEF:${XAO_AE_DIR}/XAO_Ascii.def
    )
endif()

set_target_properties(XAO_ASCII PROPERTIES
    PREFIX ""
    OUTPUT_NAME "XAO"
    SUFFIX ".aex"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Release"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/Debug"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Release"
)

# Keep one canonical build output for the workflow artifact.
add_custom_command(TARGET XAO_ASCII POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/dist"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE:XAO_ASCII>" "${CMAKE_BINARY_DIR}/dist/XAO.aex"
    COMMENT "Packaging the single XAO.aex output"
)
