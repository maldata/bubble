#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "controller.h"
#include "../view/view.h"
#include "../model/model.h"

namespace bubble
{
    class GameController : public Controller
    {
    public:
        GameController(sf::RenderWindow& window);
        virtual ~GameController();

        virtual void handleEvents(EventList& list) override;
    };
}

#endif // GAMECONTROLLER_H
