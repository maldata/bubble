#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "../view/mainview.h"
#include "../model/gamestate.h"

namespace bubble
{
    class GameLogic
    {
    public:
        GameLogic();
        virtual ~GameLogic();

        void initialize();
        void uninitialize();

    private:
        MainView _view;
        GameState _game_state;
    };
}

#endif // GAMELOGIC_H
