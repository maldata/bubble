#include "gameplaycontroller.h"

#include "gameplayview.h"

namespace bubble
{
    GameplayController::GameplayController(sf::RenderWindow& window)
        : Controller()
    {
        _model = new Model();
        _view = new GameplayView(window, _model);
    }

    GameplayController::~GameplayController()
    {

    }

    void GameplayController::handleEvents(EventList& list)
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
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num2))
            {
                poco_information(_logger, "Pressed 2");
                ScreenType next_screen = ScreenType::Settings;
                screenChangeRequested.notify(this, next_screen);
            }
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Num3))
            {
                poco_information(_logger, "Pressed 3");
                ScreenType next_screen = ScreenType::Gameplay;
                screenChangeRequested.notify(this, next_screen);
            }
            if (event.type == sf::Event::MouseMoved)
            {
                _view->handleNewMousePosition(event.mouseMove.x, event.mouseMove.y);
            }
        }
    }
}
