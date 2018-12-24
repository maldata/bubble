#ifndef BUBBLEAPP_H
#define BUBBLEAPP_H

#include <Poco/Util/Application.h>
#include <Poco/Logger.h>
#include <Poco/EventArgs.h>
#include <Poco/SharedPtr.h>

#include <SFML/Graphics.hpp>

#include "controller/controller.h"
#include "controller/mainmenucontroller.h"
#include "controller/settingscontroller.h"
#include "model/model.h"
#include "view/view.h"

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

        sf::RenderWindow _window;
        ScreenType _current_screen_type;
        Poco::SharedPtr<Controller> _current_controller;
        Poco::SharedPtr<MainMenuController> _main_menu_controller;
        Poco::SharedPtr<SettingsController> _settings_controller;

        void setUpLogging();
        void connectEvents();
        void disconnectEvents();
        void onShutdownRequested(const void* sender, Poco::EventArgs& args);
        void onScreenChangeRequested(const void* sender, ScreenType& new_screen);
    };
}

#endif // BUBBLEAPP_H
