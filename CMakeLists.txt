cmake_minimum_required(VERSION 3.14)
project(Calculator)

find_package(wxWidgets)
include(${wxWidgets_USE_FILE})
add_compile_options(-DwxUSE_DPI_AWARE_MANIFEST=2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRC_FILES
    main.h
    main.cpp
    panels.h
    panels.cpp
    calculator.h
    calculator.cpp
    custom-button.h
    custom-button.cpp
    assets/SFPRODISPLAYMEDIUM.otf
    wx.rc
)


add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
