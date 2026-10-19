cmake_minimum_required(VERSION 3.14)

project(RTGrapher LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/6.6.1/bin/qt-cmake")
find_package(Qt NAMES Qt6 Qt5 COMPONENTS Widgets Core REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Include directories
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    src/controllers/header
    src/models/header
    src/views/header
    src/resources
)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/src/resources)

# Source files
set(SOURCES
    src/main.cpp
    src/controllers/source/DataController.cpp
    src/models/source/datagenerator.cpp
    src/views/source/ControlPanel.cpp
    src/views/source/GraphWidget.cpp
    src/views/source/MainWindow.cpp
    src/views/source/ResultWidget.cpp
)

# Header files - for IDEs
set(HEADERS
    src/controllers/header/DataController.hpp
    src/models/header/datagenerator.hpp
    src/views/header/ControlPanel.hpp
    src/views/header/GraphWidget.hpp
    src/views/header/MainWindow.hpp
    src/views/header/ResultWidget.hpp
)

# Optional: specify resource files
# set(RESOURCES
#     src/resources/icons/icons.qrc
#     src/resources/styles/styles.qrc
# )

# If you have UI files (Qt Designer .ui files)
set(FORMS
    src/resources/mainwindow.ui
    # List your .ui files here
)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS}
) # ${RESOURCES})

target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
