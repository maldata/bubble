#include "gamelogic.h"

#include <Poco/EventArgs.h>
#include <Poco/Delegate.h>

namespace bubble
{
    GameLogic::GameLogic()
        : _logger(Poco::Logger::get("game"))
    {

    }

    GameLogic::~GameLogic()
    {

    }

    void GameLogic::initialize()
    {
        poco_information(_logger, "Initializing the controller.");

        _view.initialize();

        _view.windowClosed += Poco::Delegate<GameLogic, Poco::EventArgs>(this, &GameLogic::onWindowClosed);
    }

    void GameLogic::uninitialize()
    {
        poco_information(_logger, "Un-initializing the controller.");

        _view.uninitialize();

        _view.windowClosed -= Poco::Delegate<GameLogic, Poco::EventArgs>(this, &GameLogic::onWindowClosed);
    }

    void GameLogic::iterate()
    {
        _view.handleEvents();
        // incrementTime()
        // _view.updateScreen()
    }

    void GameLogic::onWindowClosed(const void* sender, Poco::EventArgs& args)
    {
        Poco::EventArgs placeholder_args;
        shutdownRequested.notify(this, placeholder_args);
    }
}
