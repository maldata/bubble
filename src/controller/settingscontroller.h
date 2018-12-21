#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include "controller.h"
#include "../view/view.h"
#include "../model/model.h"

namespace bubble
{
    class SettingsController : public Controller
    {
    public:
        SettingsController();
        virtual ~SettingsController();
    };
}

#endif // SETTINGSCONTROLLER_H
