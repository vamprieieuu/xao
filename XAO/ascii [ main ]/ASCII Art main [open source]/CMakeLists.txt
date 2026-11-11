cmake_minimum_required(VERSION 3.20)
project(ascii_cam LANGUAGES CXX VERSION 0.1.0)

# ---- Language standard -------------------------------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# ---- Options -----------------------------------------------------------------
option(ASCIICAM_BUILD_TESTS "Build unit tests" ON)
option(ASCIICAM_BUILD_APP   "Build the OpenCV-based application" ON)
option(ASCIICAM_BUILD_GUI   "Build the Qt GUI (requires Qt6)" ON)

# ---- Core engine -------------------------------------------------------------
# Header-only, dependency-free, and fully unit-testable WITHOUT OpenCV.
# This deliberate isolation lets the logic build and be verified before any
# heavyweight dependency is installed.
add_library(ascii_core INTERFACE)
target_include_directories(ascii_core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(ascii_core INTERFACE cxx_std_20)

# ---- Application (requires OpenCV) ------------------------------------------
if(ASCIICAM_BUILD_APP)
    find_package(OpenCV QUIET)
    if(OpenCV_FOUND)
        message(STATUS "OpenCV ${OpenCV_VERSION} found — building the app.")
        add_subdirectory(src/capture)
        add_subdirectory(src/pipeline)
        add_subdirectory(src/app)
        if(ASCIICAM_BUILD_GUI)
            find_package(Qt6 QUIET COMPONENTS Widgets)
            if(Qt6_FOUND)
                message(STATUS "Qt6 ${Qt6_VERSION} found — building GUI.")
                add_subdirectory(src/gui)
            else()
                message(WARNING "Qt6 not found — skipping the GUI target.")
            endif()
        endif()
    else()
        message(WARNING
            "OpenCV not found. Skipping the application target.\n"
            "  The core library and unit tests still build.\n"
            "  Install OpenCV and re-run CMake to build the app.")
    endif()
endif()

# ---- Tests -------------------------------------------------------------------
if(ASCIICAM_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
