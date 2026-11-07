set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ascii_cam_gui
    main.cpp
    MainWindow.cpp
    MainWindow.h
    AsciiView.cpp
    AsciiView.h
    AsciiRenderer.cpp
    AsciiRenderer.h
)

target_link_libraries(ascii_cam_gui
    PRIVATE
        ascii_core
        ascii_capture
        ascii_pipeline
        Qt6::Widgets
)
