#include "settingsview.h"

namespace bubble
{
    SettingsView::SettingsView(sf::RenderWindow& window, Poco::SharedPtr<Model> model)
        : View(window, model)
    {

    }

    SettingsView::~SettingsView()
    {

    }

    void SettingsView::updateScreen()
    {
        _window.clear(sf::Color::Blue);
        _window.display();
    }
}
