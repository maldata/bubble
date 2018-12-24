#include "gameplaycontroller.h"

namespace bubble
{
    GameController::GameController(sf::RenderWindow& window)
        : Controller()
    {

    }

    GameController::~GameController()
    {

    }

    void GameController::handleEvents(EventList& list)
    {
        for (EventList::iterator it = list.begin(); it != list.end(); it++)
        {
            sf::Event& event = *it;
            if (event.type == sf::Event::Closed)
            {
                Poco::EventArgs placeholder_args;
                shutdownRequested.notify(this, placeholder_args);
            }
        }
    }
}
