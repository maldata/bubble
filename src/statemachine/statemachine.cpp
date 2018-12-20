#include "statemachine.h"

namespace bubble
{
    StateMachine::StateMachine()
        : _logger(Poco::Logger::get("sm"))
    {
        _current_state = &_main_menu_state;
    }

    StateMachine::~StateMachine()
    {

    }

    void StateMachine::iterate()
    {
        _current_state->iterate();
    }
}
