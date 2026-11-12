# Portable build for the XAO ASCII core, its tests and the offline renderer.
# The After Effects plug-in itself is built with MSVC (see cmake/ and ae/).

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra -Wpedantic
INCLUDES := -Icore/include
BUILD    := build

CORE_SRC := core/src/Image.cpp core/src/Compositor.cpp core/src/Pipeline.cpp
ASCII_SRC := core/src/ascii/Text.cpp core/src/ascii/Shaping.cpp \
             core/src/ascii/Atlas.cpp core/src/ascii/AtlasData.cpp \
             core/src/ascii/GlyphSets.cpp core/src/ascii/Palette.cpp \
             core/src/ascii/AsciiEngine.cpp
CORE_OBJ := $(patsubst %.cpp,$(BUILD)/%.o,$(CORE_SRC) $(ASCII_SRC))

.PHONY: all test clean cli core-tests ascii-tests

all: $(BUILD)/xao_ascii_cli $(BUILD)/ascii_tests $(BUILD)/xao_core_tests

$(BUILD)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(BUILD)/xao_core_objs: $(CORE_OBJ)
	@touch $@

$(BUILD)/xao_core.a: $(CORE_OBJ)
	ar rcs $@ $(CORE_OBJ)

$(BUILD)/xao_ascii_cli: tools/xao_ascii_cli.cpp $(BUILD)/xao_core.a
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< $(BUILD)/xao_core.a -o $@

$(BUILD)/ascii_tests: tests/ascii_tests.cpp $(BUILD)/xao_core.a
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< $(BUILD)/xao_core.a -o $@

$(BUILD)/xao_core_tests: tests/core_tests.cpp $(BUILD)/xao_core.a
	$(CXX) $(CXXFLAGS) $(INCLUDES) $< $(BUILD)/xao_core.a -o $@

ascii-tests: $(BUILD)/ascii_tests
	$(BUILD)/ascii_tests

core-tests: $(BUILD)/xao_core_tests
	$(BUILD)/xao_core_tests

cli: $(BUILD)/xao_ascii_cli

test: core-tests ascii-tests

clean:
	rm -rf $(BUILD)

# Regenerate the embedded glyph atlas from the supplied fonts.
# Requires python3 with Pillow and fontTools.
atlas:
	python3 tools/build_atlas.py
