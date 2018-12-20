#include "gamelogic.h"

namespace bubble
{
    GameController::GameController(GameState& game_state, MainView& view)
        : Controller(game_state, view)
    {

    }

    GameController::~GameController()
    {

    }

    void GameController::iterate()
    {
        _view.handleEvents();
        // incrementTime()
        // _view.updateScreen()
    }

}
