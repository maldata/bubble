add_library(${CONTROLLERLIB} gamelogic.cpp)

target_link_libraries(${CONTROLLERLIB} ${MODELLIB} ${VIEWLIB})
