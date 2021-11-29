cmake_minimum_required(VERSION 3.0)

project(graduation_project_cpp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt5Widgets REQUIRED)

add_executable(${PROJECT_NAME}
    "sources/main.cpp"
    "sources/window.h"
    "sources/window.cpp"
    "sources/substationModels/substation.h"
    "sources/substationModels/substation.cpp"
    "sources/substationModels/voltagelevel.h"
    "sources/substationModels/voltagelevel.cpp"
    "sources/substationModels/function.h"
    "sources/substationModels/function.cpp"
    "sources/substationModels/transformer.h"
    "sources/substationModels/transformer.cpp"
    "sources/qml.qrc"
    )

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
