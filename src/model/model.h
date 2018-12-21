#ifndef MODEL_H
#define MODEL_H

#include <Poco/Logger.h>

namespace bubble
{
    class Model
    {
    public:
        Model();
        virtual ~Model();

        void initialize();
        void uninitialize();

    private:
        Poco::Logger& _logger;
    };
}

#endif // MODEL_H
