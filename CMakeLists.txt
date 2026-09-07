cmake_minimum_required(VERSION 3.21)

project(VoidDash VERSION 1.0.0)

add_library(
    ${PROJECT_NAME}
    SHARED

    src/main.cpp

    src/menu/VoidMenu.cpp

    src/features/FPS.cpp
    src/features/Performance.cpp
)

setup_geode_mod(${PROJECT_NAME})
