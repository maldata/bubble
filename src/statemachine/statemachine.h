#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <Poco/Logger.h>
#include <Poco/SharedPtr.h>

#include "state.h"
#include "mainmenustate.h"
#include "settingsstate.h"
#include "gameplaystate.h"

namespace bubble
{
    class StateMachine
    {
    public:
        StateMachine();
        virtual ~StateMachine();

        void iterate();

    private:
        Poco::Logger& _logger;

        Poco::SharedPtr<State> _current_state;
        MainMenuState _main_menu_state;
        SettingsState _settings_state;
        GameplayState _gameplay_state;
    };
}

#endif // STATEMACHINE_H
