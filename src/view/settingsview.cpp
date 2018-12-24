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

    void SettingsView::handleMouseMove(int x, int y)
    {

    }

    void SettingsView::handleLeftClick(int x, int y)
    {

    }
}
