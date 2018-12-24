#include "gameplayview.h"

namespace bubble
{
    GameplayView::GameplayView(sf::RenderWindow& window, Poco::SharedPtr<Model> model)
        : View(window, model)
    {

    }

    GameplayView::~GameplayView()
    {

    }

    void GameplayView::updateScreen()
    {
        _window.clear(sf::Color::Green);
        _window.display();
    }
}
