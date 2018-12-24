#include "bubbleapp.h"

#include <Poco/AutoPtr.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/Delegate.h>
#include <Poco/EventArgs.h>

#include "controller/mainmenucontroller.h"

namespace bubble
{
    BubbleApp::BubbleApp()
        : _logger(Poco::Logger::root())
    {

    }

    BubbleApp::~BubbleApp()
    {

    }

    int BubbleApp::main(const std::vector<std::string>& args)
    {
        _keep_going = true;
        while (_keep_going)
        {
            _current_controller->iterate();
        }

        return EXIT_OK;
    }

    void BubbleApp::defineOptions(Poco::Util::OptionSet& options)
    {

    }

    void BubbleApp::initialize(Poco::Util::Application& self)
    {
        Poco::Util::Application::initialize(self);

        poco_information(_logger, "Bubble Spinner starting...");
        setUpLogging();

        // We don't want to create the model/view/controller until after the logging gets setup
        _window.create(sf::VideoMode(800, 600), "Bubble Spinner");

        _main_menu_controller = new MainMenuController(_window);
        _settings_controller = new SettingsController(_window);

        // And now that we've created our controllers, connect events
        connectEvents();

        // Set the initial controller and initialize it
        _current_controller = _main_menu_controller;
        _current_controller->initialize();
    }

    void BubbleApp::uninitialize()
    {
        poco_information(_logger, "Bubble Spinner stopping...");
        Poco::Util::Application::uninitialize();

        disconnectEvents();
        _current_controller->uninitialize();
    }

    void BubbleApp::setUpLogging()
    {
        _logger.setLevel(Poco::Message::PRIO_INFORMATION);

        // Set up the logging pathway. The root logger will flow into a formatting channel, which will flow into a file channel.
        Poco::AutoPtr<Poco::PatternFormatter> log_formatter = new Poco::PatternFormatter("%Y-%m-%d %H:%M:%S.%i | %v[4] | %q | %t");
        Poco::AutoPtr<Poco::FormattingChannel> log_format_channel = new Poco::FormattingChannel(log_formatter);
        Poco::AutoPtr<Poco::ConsoleChannel> log_console_channel = new Poco::ConsoleChannel();

        _logger.setChannel(log_format_channel);
        log_format_channel->setChannel(log_console_channel);
        poco_information(_logger, Poco::format("Logger initialized at log level %d", _logger.getLevel()));
    }

    void BubbleApp::connectEvents()
    {
        _main_menu_controller->shutdownRequested += Poco::Delegate<BubbleApp, Poco::EventArgs>(this, &BubbleApp::onShutdownRequested);
        _main_menu_controller->screenChangeRequested += Poco::Delegate<BubbleApp, ScreenType>(this, &BubbleApp::onScreenChangeRequested);

        _settings_controller->shutdownRequested += Poco::Delegate<BubbleApp, Poco::EventArgs>(this, &BubbleApp::onShutdownRequested);
        _settings_controller->screenChangeRequested += Poco::Delegate<BubbleApp, ScreenType>(this, &BubbleApp::onScreenChangeRequested);
    }

    void BubbleApp::disconnectEvents()
    {
        _main_menu_controller->shutdownRequested -= Poco::Delegate<BubbleApp, Poco::EventArgs>(this, &BubbleApp::onShutdownRequested);
        _main_menu_controller->screenChangeRequested -= Poco::Delegate<BubbleApp, ScreenType>(this, &BubbleApp::onScreenChangeRequested);

        _settings_controller->shutdownRequested -= Poco::Delegate<BubbleApp, Poco::EventArgs>(this, &BubbleApp::onShutdownRequested);
        _settings_controller->screenChangeRequested -= Poco::Delegate<BubbleApp, ScreenType>(this, &BubbleApp::onScreenChangeRequested);
    }

    void BubbleApp::onShutdownRequested(const void* sender, Poco::EventArgs& args)
    {
        _keep_going = false;
    }

    void BubbleApp::onScreenChangeRequested(const void* sender, ScreenType& new_screen)
    {
        _current_controller->uninitialize();
        if (new_screen == ScreenType::MainMenu)
        {
            _current_controller = _main_menu_controller;
        }
        else if (new_screen == ScreenType::Settings)
        {
            _current_controller = _settings_controller;
        }
        else
        {
            poco_warning(_logger, "Something's weird in BubbleApp::onScreenChangeRequested");
        }
        _current_controller->initialize();
    }
}
