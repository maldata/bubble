#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include "controller.h"
#include "../view/view.h"
#include "../model/model.h"

namespace bubble
{
    class MainMenuController : public Controller
    {
    public:
        MainMenuController(sf::RenderWindow& window);
        virtual ~MainMenuController();

        virtual void handleEvents(EventList& list) override;

        Poco::BasicEvent<Poco::EventArgs> playButtonClicked;
        Poco::BasicEvent<Poco::EventArgs> settingsButtonClicked;
    };
}

#endif // MAINMENUCONTROLLER_H
