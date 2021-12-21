cmake_minimum_required(VERSION 3.16)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include("gate/cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.224.tar.gz"
    SHA1 "18e57a43efc435f2e1dae1291e82e42afbf940be"
)

project(Game)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_library(${PROJECT_NAME} STATIC 
        include/character.hpp 
        sources/character.cpp 
        include/enemy.hpp 
        sources/enemy.cpp    
        include/battle_graphics.hpp
        sources/battle_graphics.cpp 
        sources/battle_press_event.cpp
        sources/battle_drowing.cpp
        sources/battle_load.cpp
        sources/battle_animation.cpp
        include/main_menu.hpp
        sources/main_menu.cpp
        nlohmann_json::nlohmann_json
        )

add_executable(
        demo 
        demo/main.cpp
        sources/main_menu.cpp
        sources/battle_graphics.cpp 
        sources/battle_press_event.cpp
        sources/battle_drowing.cpp
        sources/battle_load.cpp
        sources/battle_animation.cpp
        sources/enemy.cpp
        sources/character.cpp
        )

target_include_directories(${PROJECT_NAME} PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:include>"
        )

qt5_use_modules(${PROJECT_NAME} Core Widgets Gui )



target_link_libraries(
        demo
        PUBLIC
        nlohmann_json::nlohmann_json
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
