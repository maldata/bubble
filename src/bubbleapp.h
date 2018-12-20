#ifndef BUBBLEAPP_H
#define BUBBLEAPP_H

#include <Poco/Util/Application.h>
#include <Poco/Logger.h>
#include <Poco/EventArgs.h>
#include <Poco/SharedPtr.h>

#include "controller/controller.h"

namespace bubble
{
    class BubbleApp : public Poco::Util::Application
    {
    public:
        BubbleApp();
        virtual ~BubbleApp();

    protected:
        int main(const std::vector<std::string>& args) override;
        void defineOptions(Poco::Util::OptionSet& options) override;
        void initialize(Poco::Util::Application & self) override;
        void uninitialize() override;

    private:
        Poco::Logger& _logger;
        bool _keep_going;

        Poco::SharedPtr<Controller> _current_controller;
        Poco::SharedPtr<MainView> _view;
        Poco::SharedPtr<GameState> _game_state;

        void setUpLogging();
        void onShutdownRequested(const void* sender, Poco::EventArgs& args);
    };
}

#endif // BUBBLEAPP_H
