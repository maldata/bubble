#include "mainmenuview.h"

namespace bubble
{
    MainMenuView::MainMenuView(sf::RenderWindow& window, Poco::SharedPtr<Model> model)
        : View(window, model)
    {
        _play_button = new Button(sf::Vector2f(240, 48), "PLAY!");
    }

    MainMenuView::~MainMenuView()
    {

    }

    void MainMenuView::updateScreen()
    {
        _window.clear(sf::Color::White);
        _window.draw(*_play_button);
        _window.display();
    }

    void MainMenuView::handleNewMousePosition(int x, int y)
    {
        if (_play_button->contains(x, y))
        {
            _play_button->setButtonState(ButtonState::HOVER);
        }
        else
        {
            _play_button->setButtonState(ButtonState::DEFAULT);
        }
    }

    void MainMenuView::handleLeftClick(int x, int y)
    {
        Poco::EventArgs args;
        if (_play_button->contains(x, y))
        {
            playButtonClicked.notify(this, args);
        }
        else if (_settings_button.contains(x, y))
        {
            settingsButtonClicked.notify(this, args);
        }
    }
}

