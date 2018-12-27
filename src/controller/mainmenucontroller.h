#ifndef MAINMENUCONTROLLER_H
#define MAINMENUCONTROLLER_H

#include "controller.h"
#include "../view/view.h"
#include "../model/model.h"

#include <Poco/EventArgs.h>

namespace bubble
{
    class MainMenuController : public Controller
    {
    public:
        MainMenuController(sf::RenderWindow& window);
        virtual ~MainMenuController();

        virtual void handleEvents(EventList& list) override;

        Poco::BasicEvent<Poco::EventArgs> gameRequested;
        Poco::BasicEvent<Poco::EventArgs> settingsRequested;

    private:
        void onPlayButtonClicked(const void* sender, Poco::EventArgs& args);
    };
}

#endif // MAINMENUCONTROLLER_H
