add_library(ascii_pipeline STATIC FrameConverter.cpp)

target_link_libraries(ascii_pipeline
    PUBLIC
        ascii_core
        ${OpenCV_LIBS}
)
target_include_directories(ascii_pipeline PUBLIC ${OpenCV_INCLUDE_DIRS})
