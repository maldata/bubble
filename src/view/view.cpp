#include "view.h"

#include "../model/model.h"

namespace bubble
{
    View::View(sf::RenderWindow& window, Poco::SharedPtr<Model> model)
        : _logger(Poco::Logger::get("view")), _window(window), _model(model)
    {
    }

    View::~View()
    {

    }

    void View::initialize()
    {
        poco_information(_logger, "Initializing the view.");
    }

    void View::uninitialize()
    {
        poco_information(_logger, "Un-initializing the view.");
    }

    int View::getEvents(EventList& list)
    {
        sf::Event event;
        int count = 0;

        while (_window.pollEvent(event))
        {
            sf::Event copiedEvent = event;
            list.push_front(copiedEvent);
            count++;
        }
        return count;
    }
}
