add_library(${CONTROLLERLIB} controller.cpp
                             gamelogic.cpp)

target_link_libraries(${CONTROLLERLIB} ${MODELLIB} ${VIEWLIB})
