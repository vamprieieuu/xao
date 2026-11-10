cmake_minimum_required(VERSION 3.20)
project(XAO_Core VERSION 0.1.0 LANGUAGES CXX)

option(XAO_BUILD_TESTS "Build XAO core tests" ON)

add_library(xao_core STATIC
    core/src/Image.cpp
    core/src/Compositor.cpp
    core/src/Pipeline.cpp
    core/src/AsciiEngine.cpp
)
target_include_directories(xao_core PUBLIC core/include)
target_compile_features(xao_core PUBLIC cxx_std_17)
set_target_properties(xao_core PROPERTIES POSITION_INDEPENDENT_CODE ON)
if(MSVC)
    target_compile_options(xao_core PRIVATE /W4 /permissive- /EHsc)
else()
    target_compile_options(xao_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

if(XAO_BUILD_TESTS)
    enable_testing()
    add_executable(xao_core_tests tests/core_tests.cpp)
    target_link_libraries(xao_core_tests PRIVATE xao_core)
    add_test(NAME xao_core_tests COMMAND xao_core_tests)
    add_executable(xao_ascii_engine_tests tests/ascii_engine_tests.cpp)
    target_link_libraries(xao_ascii_engine_tests PRIVATE xao_core)
    add_test(NAME xao_ascii_engine_tests COMMAND xao_ascii_engine_tests)
endif()
