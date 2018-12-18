#include "gamestate.h"

namespace bubble
{
    GameState::GameState()
        : _logger(Poco::Logger::get("mdel"))
    {

    }

    GameState::~GameState()
    {

    }

    void GameState::initialize()
    {
        poco_information(_logger, "Initializing the game state.");
    }

    void GameState::uninitialize()
    {
        poco_information(_logger, "Un-initializing the game state.");
    }
}
