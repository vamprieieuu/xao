include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.2
)
FetchContent_MakeAvailable(Catch2)

add_executable(unit_tests
    test_latest_frame_buffer.cpp
    test_luminance.cpp
    test_color.cpp
    test_glyph_mapper.cpp
)
target_link_libraries(unit_tests PRIVATE ascii_core Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(unit_tests)
