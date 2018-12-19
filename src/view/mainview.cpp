#include "mainview.h"

namespace bubble
{
    MainView::MainView(GameState& game_state)
        : _logger(Poco::Logger::get("view")), _game_state(game_state)
    {
    }

    MainView::~MainView()
    {

    }

    void MainView::initialize()
    {
        poco_information(_logger, "Initializing the view.");

        _window.create(sf::VideoMode(800, 600), "Bubble Spinner");
        _window.clear();
        _window.display();
    }

    void MainView::uninitialize()
    {
        poco_information(_logger, "Un-initializing the view.");
    }

    void MainView::handleEvents()
    {
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _window.close();
                Poco::EventArgs args;
                windowClosed.notify(this, args);
            }
        }
    }
}
