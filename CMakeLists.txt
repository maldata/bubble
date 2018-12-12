cmake_minimum_required(VERSION 3.0)

project(bubble)

set(CMAKE_BUILD_TYPE Debug)

find_package(Threads)



find_library(SFML_WINDOW_LIB sfml-window)
if(SFML_WINDOW_LIB STREQUAL "SFML_WINDOW_LIB-NOTFOUND")
    message( FATAL_ERROR "libsfml-window was not found. Cannot proceed.")
else()
    message("libsfml-window.so found at ${SFML_WINDOW_LIB}")
endif()

find_library(SFML_SYSTEM_LIB sfml-system)
if(SFML_SYSTEM_LIB STREQUAL "SFML_SYSTEM_LIB-NOTFOUND")
    message( FATAL_ERROR "libsfml-system was not found. Cannot proceed.")
else()
    message("libsfml-system.so found at ${SFML_SYSTEM_LIB}")
endif()

find_library(SFML_GRAPHICS_LIB sfml-graphics)
if(SFML_GRAPHICS_LIB STREQUAL "SFML_GRAPHICS_LIB-NOTFOUND")
    message( FATAL_ERROR "libsfml-graphics was not found. Cannot proceed.")
else()
    message("libsfml-graphics.so found at ${SFML_GRAPHICS_LIB}")
endif()

set(SOURCE src/main.cpp)

set(BUBBLE_EXE ${PROJECT_NAME})

add_executable(${BUBBLE_EXE} ${SOURCE})

target_link_libraries(${BUBBLE_EXE} ${SFML_GRAPHICS_LIB} ${SFML_SYSTEM_LIB} ${SFML_WINDOW_LIB})