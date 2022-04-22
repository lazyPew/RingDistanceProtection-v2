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

    "substationModels/connectivitynode.h"
    "substationModels/connectivitynode.cpp"
    "substationModels/distanceprotection.h"
    "substationModels/distanceprotection.cpp"
    "substationModels/terminal.h"
    "substationModels/terminal.cpp"
    "substationModels/equipment.h"
    "substationModels/equipment.cpp"
    "substationModels/system.h"
    "substationModels/system.cpp"
    "substationModels/function.cpp"
    "substationModels/function.h"
    "substationModels/substation.cpp"
    "substationModels/substation.h"
    "substationModels/transformer.cpp"
    "substationModels/transformer.h"
    "substationModels/voltagelevel.cpp"
    "substationModels/voltagelevel.h"
    "substationModels/wline.cpp"
    "substationModels/wline.h"

    "csvFiles/Buses.csv"
    "csvFiles/DistanceProtections.csv"
    "csvFiles/Systems.csv"
    "csvFiles/Transformers.csv"
    "csvFiles/WLines.csv"

    "qml.qrc"
    "README.md"
    ".gitignore"
    )



target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
