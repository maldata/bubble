#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include <Poco/BasicEvent.h>
#include <Poco/EventArgs.h>
#include <Poco/Logger.h>

#include "../view/mainview.h"
#include "../model/gamestate.h"

namespace bubble
{
    class GameLogic
    {
    public:
        GameLogic();
        virtual ~GameLogic();

        void initialize();
        void uninitialize();
        void iterate();

        Poco::BasicEvent<Poco::EventArgs> shutdownRequested;

    private:
        Poco::Logger& _logger;

        MainView _view;
        GameState _game_state;

        void onWindowClosed(const void* sender, Poco::EventArgs& args);
    };
}

#endif // GAMELOGIC_H
