#include "settingscontroller.h"
#include "../view/settingsview.h"

namespace bubble
{
    SettingsController::SettingsController(sf::RenderWindow& window)
        : Controller()
    {
        _model = new Model();
        _view = new SettingsView(window, _model);
    }

    SettingsController::~SettingsController()
    {

    }

    void SettingsController::handleEvents(EventList& list)
    {
        for (EventList::iterator it = list.begin(); it != list.end(); it++)
        {
            sf::Event& event = *it;
            if (event.type == sf::Event::Closed)
            {
                Poco::EventArgs placeholder_args;
                shutdownRequested.notify(this, placeholder_args);
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num1))
            {
                poco_information(_logger, "Pressed 1");
                ScreenType next_screen = ScreenType::MainMenu;
                screenChangeRequested.notify(this, next_screen);
            }
        }
    }
}
