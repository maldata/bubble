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

add_library(${VIEWLIB} view.cpp
                       mainmenuview.cpp
                       settingsview.cpp
                       checkbox.cpp)

target_link_libraries(${VIEWLIB} ${SFML_WINDOW_LIB} ${SFML_SYSTEM_LIB} ${SFML_GRAPHICS_LIB})
