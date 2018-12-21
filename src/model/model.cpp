#include "model.h"

namespace bubble
{
    Model::Model()
        : _logger(Poco::Logger::get("mdel"))
    {

    }

    Model::~Model()
    {

    }

    void Model::initialize()
    {
        poco_information(_logger, "Initializing the model.");
    }

    void Model::uninitialize()
    {
        poco_information(_logger, "Un-initializing the model.");
    }
}
