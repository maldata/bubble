#include "controller.h"
#include "../model/model.h"

#include <Poco/EventArgs.h>
#include <Poco/Delegate.h>

namespace bubble
{
    Controller::Controller(Model& model, MainView& view)
        : _logger(Poco::Logger::get("ctlr")), _model(model), _view(view)
    {

    }

    Controller::~Controller()
    {

    }

    void Controller::initialize()
    {
        poco_information(_logger, "Initializing the controller.");

        _view.initialize();

        _view.windowClosed += Poco::Delegate<Controller, Poco::EventArgs>(this, &Controller::onWindowClosed);
    }

    void Controller::uninitialize()
    {
        poco_information(_logger, "Un-initializing the controller.");

        _view.uninitialize();

        _view.windowClosed -= Poco::Delegate<Controller, Poco::EventArgs>(this, &Controller::onWindowClosed);
    }

    void Controller::iterate()
    {
        _view.handleEvents();
        // incrementTime()
        // _view.updateScreen()
    }

    void Controller::onWindowClosed(const void* sender, Poco::EventArgs& args)
    {
        Poco::EventArgs placeholder_args;
        shutdownRequested.notify(this, placeholder_args);
    }
}
