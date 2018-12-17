#ifndef BUBBLEAPP_H
#define BUBBLEAPP_H

#include <Poco/Util/Application.h>
#include <Poco/Logger.h>

#include "controller/gamelogic.h"

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
        GameLogic _logic;

        void setUpLogging();

    };
}

#endif // BUBBLEAPP_H
