#include "mainmenucontroller.h"
#include "mainmenuview.h"

namespace bubble
{
    MainMenuController::MainMenuController(sf::RenderWindow& window)
        : Controller()
    {
        _model = new Model();
        _view = new MainMenuView(window, _model);
    }

    MainMenuController::~MainMenuController()
    {

    }

    void MainMenuController::handleEvents(EventList& list)
    {
        for (EventList::iterator it = list.begin(); it != list.end(); it++)
        {
            sf::Event& event = *it;
            if (event.type == sf::Event::Closed)
            {
                Poco::EventArgs placeholder_args;
                shutdownRequested.notify(this, placeholder_args);
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2))
            {
                poco_information(_logger, "Pressed 2");
                ScreenType next_screen = ScreenType::Settings;
                screenChangeRequested.notify(this, next_screen);
            }
        }
    }
}
