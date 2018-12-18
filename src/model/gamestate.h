#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <Poco/Logger.h>

namespace bubble
{
    class GameState
    {
    public:
        GameState();
        virtual ~GameState();

        void initialize();
        void uninitialize();

    private:
        Poco::Logger& _logger;
    };
}

#endif // GAMESTATE_H
