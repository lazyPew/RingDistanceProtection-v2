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
    "substationModels/function.cpp"
    "substationModels/function.h"
    "substationModels/substation.cpp"
    "substationModels/substation.h"
    "substationModels/voltagelevel.cpp"
    "substationModels/voltagelevel.h"

    "substationModels/EquipmentModels/protectedequipment.cpp"
    "substationModels/EquipmentModels/protectedequipment.h"
    "substationModels/EquipmentModels/equipment.h"
    "substationModels/EquipmentModels/equipment.cpp"
    "substationModels/EquipmentModels/system.h"
    "substationModels/EquipmentModels/system.cpp"
    "substationModels/EquipmentModels/transformer.cpp"
    "substationModels/EquipmentModels/transformer.h"
    "substationModels/EquipmentModels/wline.cpp"
    "substationModels/EquipmentModels/wline.h"

    "substationModels/TerminalModels/distanceprotection.h"
    "substationModels/TerminalModels/distanceprotection.cpp"
    "substationModels/TerminalModels/terminal.h"
    "substationModels/TerminalModels/terminal.cpp"

    "qml.qrc"
    "README.md"
    ".gitignore"
    )



target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
