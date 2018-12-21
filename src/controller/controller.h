#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Poco/BasicEvent.h>
#include <Poco/EventArgs.h>
#include <Poco/Logger.h>
#include <Poco/SharedPtr.h>

#include "../view/mainview.h"
#include "../model/model.h"

namespace bubble
{
    class Controller
    {
    public:
        Controller(Model& model, MainView& view);
        virtual ~Controller();

        virtual void initialize();
        virtual void uninitialize();
        virtual void iterate();

        Poco::BasicEvent<Poco::EventArgs> shutdownRequested;

    protected:
        Poco::Logger& _logger;
        Model& _model;
        MainView& _view;

        void onWindowClosed(const void* sender, Poco::EventArgs& args);
    };
}

#endif // CONTROLLER_H