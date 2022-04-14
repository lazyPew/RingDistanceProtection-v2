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
    "main.cpp"
    "controlpanel.cpp"
    "controlpanel.h"
    "substationSubModels/connectivitynode.h"
    "substationSubModels/connectivitynode.cpp"
    "substationSubModels/distanceprotection.h"
    "substationSubModels/distanceprotection.cpp"
    "substationSubModels/terminal.h"
    "substationSubModels/terminal.cpp"
    "substationSubModels/equipment.h"
    "substationSubModels/equipment.cpp"
    "substationSubModels/system.h"
    "substationSubModels/system.cpp"
    "substationSubModels/function.cpp"
    "substationSubModels/function.h"
    "substationSubModels/substation.cpp"
    "substationSubModels/substation.h"
    "substationSubModels/transformer.cpp"
    "substationSubModels/transformer.h"
    "substationSubModels/voltagelevel.cpp"
    "substationSubModels/voltagelevel.h"
    "substationSubModels/wline.cpp"
    "substationSubModels/wline.h"
    "qml.qrc"
    "README.md"
    )



target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
