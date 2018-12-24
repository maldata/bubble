#include "mainmenuview.h"

namespace bubble
{
    MainMenuView::MainMenuView(sf::RenderWindow& window, Poco::SharedPtr<Model> model)
        : View(window, model)
    {

    }

    MainMenuView::~MainMenuView()
    {

    }

    void MainMenuView::updateScreen()
    {
        _window.clear(sf::Color::White);
        _window.display();
    }
}

