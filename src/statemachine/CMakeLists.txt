add_library(${SMLIB} statemachine.cpp
                     state.cpp
                     mainmenustate.cpp
                     settingsstate.cpp
                     gameplaystate.cpp)

target_link_libraries(${SMLIB})
