#include "mainmenucontroller.h"

#include "mainmenuview.h"

#include <Poco/EventArgs.h>
#include <Poco/Delegate.h>

namespace bubble
{
    MainMenuController::MainMenuController(sf::RenderWindow& window)
        : Controller()
    {
        _model = new Model();
        _view = new MainMenuView(window, _model);

        MainMenuView* main_menu_view = dynamic_cast<MainMenuView*>(_view.get());
        main_menu_view->playButtonClicked += Poco::Delegate<MainMenuController, Poco::EventArgs>(this, &MainMenuController::onPlayButtonClicked);
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
            if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left))
            {
                _view->handleLeftClick(event.mouseButton.x, event.mouseButton.y);
            }
        }
    }

    void MainMenuController::onPlayButtonClicked(const void* sender, Poco::EventArgs& args)
    {
        poco_information(_logger, "Main menu controller knows the play button was clicked.");
        ScreenType next_screen = ScreenType::Gameplay;
        screenChangeRequested.notify(this, next_screen);
    }
}
