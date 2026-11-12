cmake_minimum_required(VERSION 3.20)
project(XAO_ASCII LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

if(NOT WIN32)
    message(FATAL_ERROR "XAO ASCII AEX build requires Windows/MSVC.")
endif()

# Match the proven Dithering MAJEED build: compile Adobe's SDK support library
# and use Adobe's PiPLtool.exe + cl.exe preprocessing pipeline.
if(NOT DEFINED AE_SDK_PATH)
    message(FATAL_ERROR "AE_SDK_PATH must point to the AfterEffectsSDK root.")
endif()
get_filename_component(AE_SDK_PATH "${AE_SDK_PATH}" ABSOLUTE)
if(NOT EXISTS "${AE_SDK_PATH}/CMakeLists.txt")
    message(FATAL_ERROR "After Effects SDK CMakeLists.txt not found: ${AE_SDK_PATH}")
endif()
add_subdirectory("${AE_SDK_PATH}" "${CMAKE_CURRENT_BINARY_DIR}/extern/AfterEffectsSDK")

set(XAO_AE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(XAO_CORE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../core")
set(PIPL_R "${XAO_AE_DIR}/XAO_PiPL.r")
set(PIPL_RR "${CMAKE_CURRENT_BINARY_DIR}/XAO_PiPL.rr")
set(PIPL_RRC "${CMAKE_CURRENT_BINARY_DIR}/XAO_PiPL.rrc")
set(PIPL_RC "${CMAKE_CURRENT_BINARY_DIR}/XAO_PiPL.generated.rc")
set(PIPL_SCRIPT "${CMAKE_CURRENT_BINARY_DIR}/GenerateXAOPiPL.cmd")
set(PIPLTOOL "${AE_SDK_PATH}/Resources/PiPLtool.exe")

if(NOT EXISTS "${PIPL_R}")
    message(FATAL_ERROR "PiPL source not found: ${PIPL_R}")
endif()
if(NOT EXISTS "${PIPLTOOL}")
    message(FATAL_ERROR "Adobe PiPLtool.exe not found: ${PIPLTOOL}")
endif()

# Same three-step Adobe SDK sequence used by the known-good MAJEED project:
# cl /EP .r -> .rr; PiPLtool .rr -> .rrc; cl /D MSWindows /EP .rrc -> .rc.
file(WRITE "${PIPL_SCRIPT}" [=[
@echo off
setlocal
set "CL_EXE=@CL_EXE@"
set "SDK_HEADERS=@SDK_HEADERS@"
set "PIPL_IN=@PIPL_IN@"
set "PIPL_RR=@PIPL_RR@"
set "PIPLTOOL=@PIPLTOOL@"
set "PIPL_RRC=@PIPL_RRC@"
set "PIPL_RC=@PIPL_RC@"

"%CL_EXE%" /nologo /I "%SDK_HEADERS%" /EP "%PIPL_IN%" > "%PIPL_RR%"
if errorlevel 1 exit /b %errorlevel%

"%PIPLTOOL%" "%PIPL_RR%" "%PIPL_RRC%"
if errorlevel 1 exit /b %errorlevel%

"%CL_EXE%" /nologo /D "MSWindows" /EP "%PIPL_RRC%" > "%PIPL_RC%"
if errorlevel 1 exit /b %errorlevel%

if not exist "%PIPL_RC%" exit /b 2
exit /b 0
]=])

file(READ "${PIPL_SCRIPT}" PIPL_SCRIPT_TEXT)
string(REPLACE "@CL_EXE@" "${CMAKE_C_COMPILER}" PIPL_SCRIPT_TEXT "${PIPL_SCRIPT_TEXT}")
string(REPLACE "@SDK_HEADERS@" "${AE_SDK_PATH}/Headers" PIPL_SCRIPT_TEXT "${PIPL_SCRIPT_TEXT}")
string(REPLACE "@PIPL_IN@" "${PIPL_R}" PIPL_SCRIPT_TEXT "${PIPL_SCRIPT_TEXT}")
string(REPLACE "@PIPL_RR@" "${PIPL_RR}" PIPL_SCRIPT_TEXT "${PIPL_SCRIPT_TEXT}")
string(REPLACE "@PIPLTOOL@" "${PIPLTOOL}" PIPL_SCRIPT_TEXT "${PIPL_SCRIPT_TEXT}")
string(REPLACE "@PIPL_RRC@" "${PIPL_RRC}" PIPL_SCRIPT_TEXT "${PIPL_SCRIPT_TEXT}")
string(REPLACE "@PIPL_RC@" "${PIPL_RC}" PIPL_SCRIPT_TEXT "${PIPL_SCRIPT_TEXT}")
file(WRITE "${PIPL_SCRIPT}" "${PIPL_SCRIPT_TEXT}")

add_custom_command(
    OUTPUT "${PIPL_RC}"
    COMMAND cmd.exe /C call "${PIPL_SCRIPT}"
    DEPENDS "${PIPL_R}" "${PIPLTOOL}"
    VERBATIM
    COMMENT "Generating XAO PiPL with Adobe PiPLtool"
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

add_dependencies(XAO_ASCII AESDK)

target_include_directories(XAO_ASCII PRIVATE
    "${XAO_AE_DIR}"
    "${XAO_CORE_DIR}/include"
    ${AESDK_INCLUDE}
)

target_link_libraries(XAO_ASCII PRIVATE AESDK)
target_compile_definitions(XAO_ASCII PRIVATE MSWindows _WINDOWS WIN32)

if(MSVC)
    # Keep the same compiler contract as Dithering MAJEED; Release configuration
    # supplies the normal optimisation flags through the Visual Studio generator.
    target_compile_options(XAO_ASCII PRIVATE /W3 /EHsc /permissive-)
    target_link_options(XAO_ASCII PRIVATE
        /SUBSYSTEM:WINDOWS
        "/DEF:${XAO_AE_DIR}/XAO_Ascii.def"
    )
endif()

set_target_properties(XAO_ASCII PROPERTIES
    PREFIX ""
    OUTPUT_NAME "XAO"
    SUFFIX ".aex"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Release"
)

install(TARGETS XAO_ASCII DESTINATION ".")
