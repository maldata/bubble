#include "controller.h"
#include "../model/model.h"

#include <Poco/EventArgs.h>
#include <Poco/Delegate.h>

namespace bubble
{
    Controller::Controller()
        : _logger(Poco::Logger::get("ctlr"))
    {
        _model = new Model();
        _view = new View(_model);
    }

    Controller::~Controller()
    {

    }

    void Controller::initialize()
    {
        poco_information(_logger, "Initializing the controller.");

        _model->initialize();
        _view->initialize();

        _view->windowClosed += Poco::Delegate<Controller, Poco::EventArgs>(this, &Controller::onWindowClosed);
    }

    void Controller::uninitialize()
    {
        poco_information(_logger, "Un-initializing the controller.");

        _view->uninitialize();
        _model->uninitialize();

        _view->windowClosed -= Poco::Delegate<Controller, Poco::EventArgs>(this, &Controller::onWindowClosed);
    }

    void Controller::iterate()
    {
        // TODO: maybe this should be more like "GET events."
        _view->handleEvents();
        // incrementTime()
        // _view.updateScreen()
    }

    void Controller::onWindowClosed(const void* sender, Poco::EventArgs& args)
    {
        Poco::EventArgs placeholder_args;
        shutdownRequested.notify(this, placeholder_args);
    }
}
