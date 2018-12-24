#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Poco/BasicEvent.h>
#include <Poco/EventArgs.h>
#include <Poco/Logger.h>
#include <Poco/SharedPtr.h>

#include "../view/view.h"
#include "../model/model.h"

namespace bubble
{
    class Controller
    {
    public:
        Controller();
        virtual ~Controller();

        virtual void initialize();
        virtual void uninitialize();
        virtual void iterate();
        virtual void handleEvents(EventList& list) = 0;

        Poco::BasicEvent<Poco::EventArgs> shutdownRequested;

    protected:
        Poco::Logger& _logger;

        Poco::SharedPtr<Model> _model;
        Poco::SharedPtr<View> _view;
    };
}

#endif // CONTROLLER_H
