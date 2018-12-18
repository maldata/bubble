#include "bubbleapp.h"

#include <Poco/AutoPtr.h>
#include <Poco/PatternFormatter.h>
#include <Poco/FormattingChannel.h>
#include <Poco/ConsoleChannel.h>
#include <Poco/Delegate.h>
#include <Poco/EventArgs.h>

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
            _logic.iterate();
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

        _logic.initialize();

        _logic.shutdownRequested += Poco::Delegate<BubbleApp, Poco::EventArgs>(this, &BubbleApp::onShutdownRequested);
    }

    void BubbleApp::uninitialize()
    {
        poco_information(_logger, "Bubble Spinner stopping...");
        Poco::Util::Application::uninitialize();

        _logic.uninitialize();

        _logic.shutdownRequested -= Poco::Delegate<BubbleApp, Poco::EventArgs>(this, &BubbleApp::onShutdownRequested);
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

    void BubbleApp::onShutdownRequested(const void* sender, Poco::EventArgs& args)
    {
        _keep_going = false;
    }
}
