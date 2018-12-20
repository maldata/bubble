#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "controller.h"
#include "../view/mainview.h"
#include "../model/gamestate.h"

namespace bubble
{
    class GameController : public Controller
    {
    public:
        GameController(GameState& game_state, MainView& view);
        virtual ~GameController();
    };
}

#endif // GAMECONTROLLER_H
