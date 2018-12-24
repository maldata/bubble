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
        SettingsController(sf::RenderWindow& window);
        virtual ~SettingsController();

        virtual void handleEvents(EventList& list) override;
    };
}

#endif // SETTINGSCONTROLLER_H
