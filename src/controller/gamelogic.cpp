#include "gamelogic.h"

#include <Poco/EventArgs.h>

namespace bubble
{
    GameLogic::GameLogic()
    {

    }

    GameLogic::~GameLogic()
    {

    }

    void GameLogic::initialize()
    {
        _view.initialize();
    }

    void GameLogic::uninitialize()
    {
        _view.uninitialize();
    }

    void GameLogic::handleEvents()
    {
        Poco::EventArgs placeholder_args;
        shutdownRequested.notify(this, placeholder_args);
    }
}
