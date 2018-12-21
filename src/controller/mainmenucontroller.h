#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include "controller.h"
#include "../view/mainview.h"
#include "../model/model.h"

namespace bubble
{
    class MainMenuController : public Controller
    {
    public:
        MainMenuController(Model& game_state, MainView& view);
        virtual ~MainMenuController();
    };
}

#endif // MAINMENUCONTROLLER_H
