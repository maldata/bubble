add_library(${CONTROLLERLIB} controller.cpp
                             mainmenucontroller.cpp
                             settingscontroller.cpp
                             gameplaycontroller.cpp)

target_link_libraries(${CONTROLLERLIB} ${MODELLIB} ${VIEWLIB})
