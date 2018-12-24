#include "controller.h"
#include "../model/model.h"

#include <SFML/Window.hpp>

#include <Poco/EventArgs.h>
#include <Poco/Delegate.h>

namespace bubble
{
    Controller::Controller()
        : _logger(Poco::Logger::get("ctlr"))
    {

    }

    Controller::~Controller()
    {

    }

    void Controller::initialize()
    {
        poco_information(_logger, "Initializing the controller.");

        _model->initialize();
        _view->initialize();
    }

    void Controller::uninitialize()
    {
        poco_information(_logger, "Un-initializing the controller.");

        _view->uninitialize();
        _model->uninitialize();
    }

    void Controller::iterate()
    {
        EventList list;
        int num_events = _view->getEvents(list);
        if (num_events > 0)
        {
            handleEvents(list);
        }

        // incrementTime()
        _view->updateScreen();
    }
}
