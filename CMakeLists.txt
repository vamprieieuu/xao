cmake_minimum_required(VERSION 3.20)
project(XAO_Core VERSION 0.2.0 LANGUAGES CXX)

option(XAO_BUILD_TESTS "Build XAO core tests" ON)

add_library(xao_core STATIC
    core/src/Image.cpp
    core/src/Compositor.cpp
    core/src/Pipeline.cpp
    core/src/ascii/Text.cpp
    core/src/ascii/Shaping.cpp
    core/src/ascii/Atlas.cpp
    core/src/ascii/AtlasData.cpp
    core/src/ascii/GlyphSets.cpp
    core/src/ascii/Palette.cpp
    core/src/ascii/AsciiEngine.cpp
)
target_include_directories(xao_core PUBLIC core/include)
target_compile_features(xao_core PUBLIC cxx_std_17)
set_target_properties(xao_core PROPERTIES POSITION_INDEPENDENT_CODE ON)
if(MSVC)
    target_compile_options(xao_core PRIVATE /W4 /permissive- /EHsc)
else()
    target_compile_options(xao_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Offline renderer used by the automated visual comparisons.
add_executable(xao_ascii_cli tools/xao_ascii_cli.cpp)
target_link_libraries(xao_ascii_cli PRIVATE xao_core)

if(XAO_BUILD_TESTS)
    enable_testing()
    add_executable(xao_core_tests tests/core_tests.cpp)
    target_link_libraries(xao_core_tests PRIVATE xao_core)
    add_test(NAME xao_core_tests COMMAND xao_core_tests)

    add_executable(xao_ascii_tests tests/ascii_tests.cpp)
    target_link_libraries(xao_ascii_tests PRIVATE xao_core)
    add_test(NAME xao_ascii_tests COMMAND xao_ascii_tests)
endif()
