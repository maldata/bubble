#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <Poco/BasicEvent.h>
#include <Poco/EventArgs.h>
#include <Poco/Logger.h>
#include <Poco/SharedPtr.h>

#include "../view/mainview.h"
#include "../model/gamestate.h"

namespace bubble
{
    class GameLogic
    {
    public:
        GameLogic(GameState& game_state, MainView& view);
        virtual ~GameLogic();

        void initialize();
        void uninitialize();
        void iterate();

        Poco::BasicEvent<Poco::EventArgs> shutdownRequested;

    private:
        Poco::Logger& _logger;
        GameState& _game_state;
        MainView& _view;

        void onWindowClosed(const void* sender, Poco::EventArgs& args);
    };
}

#endif // GAMELOGIC_H
