cmake_minimum_required(VERSION 3.0)

project(bubble)

set(CMAKE_BUILD_TYPE Debug)

find_package(Threads)

find_library(POCO_FNDN_LIB PocoFoundation)
if(POCO_UTIL_LIB STREQUAL "POCO_FNDN_LIB-NOTFOUND")
    message( FATAL_ERROR "libPocoFoundation was not found. Cannot proceed.")
else()
    message("libPocoFoundation.so found at ${POCO_FNDN_LIB}")
endif()

find_library(POCO_UTIL_LIB PocoUtil)
if(POCO_UTIL_LIB STREQUAL "POCO_UTIL_LIB-NOTFOUND")
    message( FATAL_ERROR "libPocoUtil was not found. Cannot proceed.")
else()
    message("libPocoUtil.so found at ${POCO_UTIL_LIB}")
endif()

set(SMDIR src/statemachine)
set(SMLIB bubblesm)
add_subdirectory(${SMDIR})
link_directories(${SMDIR})
include_directories(${SMDIR})

set(VIEWDIR src/view)
set(VIEWLIB bubbleview)
add_subdirectory(${VIEWDIR})
link_directories(${VIEWDIR})
include_directories(${VIEWDIR})

set(MODELDIR src/model)
set(MODELLIB bubblemodel)
add_subdirectory(${MODELDIR})
link_directories(${MODELDIR})
include_directories(${MODELDIR})

set(CONTROLLERDIR src/controller)
set(CONTROLLERLIB bubblecontroller)
add_subdirectory(${CONTROLLERDIR})
link_directories(${CONTROLLERDIR})
include_directories(${CONTROLLERDIR})

set(SOURCE src/main.cpp
           src/bubbleapp.cpp)

set(BUBBLE_EXE ${PROJECT_NAME})

add_executable(${BUBBLE_EXE} ${SOURCE})

target_link_libraries(${BUBBLE_EXE} ${POCO_FNDN_LIB} ${POCO_UTIL_LIB} ${VIEWLIB} ${MODELLIB} ${CONTROLLERLIB})
