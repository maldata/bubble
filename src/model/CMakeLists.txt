add_library(${MODELLIB} gamestate.cpp)

target_link_libraries(${MODELLIB} ${VIEWLIB})
