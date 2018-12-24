#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "controller.h"
#include "../view/view.h"
#include "../model/model.h"

namespace bubble
{
    class GameplayController : public Controller
    {
    public:
        GameplayController(sf::RenderWindow& window);
        virtual ~GameplayController();

        virtual void handleEvents(EventList& list) override;
    };
}

#endif // GAMECONTROLLER_H
