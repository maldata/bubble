#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "controller.h"
#include "../view/mainview.h"
#include "../model/model.h"

namespace bubble
{
    class GameController : public Controller
    {
    public:
        GameController(Model& game_state, MainView& view);
        virtual ~GameController();
    };
}

#endif // GAMECONTROLLER_H
