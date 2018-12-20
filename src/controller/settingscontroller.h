#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include "controller.h"
#include "../view/mainview.h"
#include "../model/gamestate.h"

namespace bubble
{
    class SettingsController : public Controller
    {
    public:
        SettingsController(GameState& game_state, MainView& view);
        virtual ~SettingsController();
    };
}

#endif // SETTINGSCONTROLLER_H
