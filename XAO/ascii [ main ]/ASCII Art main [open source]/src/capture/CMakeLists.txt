add_library(ascii_capture STATIC
    CameraCapture.cpp
    FileSource.cpp
)

target_link_libraries(ascii_capture
    PUBLIC
        ascii_core
        ${OpenCV_LIBS}
)
target_include_directories(ascii_capture PUBLIC ${OpenCV_INCLUDE_DIRS})
