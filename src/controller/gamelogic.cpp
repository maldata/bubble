#include "gamelogic.h"

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
}
