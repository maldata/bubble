#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include "controller.h"
#include "../view/mainview.h"
#include "../model/model.h"

namespace bubble
{
    class SettingsController : public Controller
    {
    public:
        SettingsController(Model& game_state, MainView& view);
        virtual ~SettingsController();
    };
}

#endif // SETTINGSCONTROLLER_H
