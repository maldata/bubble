add_library(${MODELLIB} model.cpp
                        gameplaymodel.cpp)

target_link_libraries(${MODELLIB} ${VIEWLIB})
