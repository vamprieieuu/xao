add_executable(ascii_cam main.cpp)

target_link_libraries(ascii_cam
    PRIVATE
        ascii_core
        ascii_capture
        ascii_pipeline
)
