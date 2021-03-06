#include "mainmenuview.h"

namespace bubble
{
    MainMenuView::MainMenuView(sf::RenderWindow& window, Poco::SharedPtr<Model> model)
        : View(window, model)
    {
        _play_button = new Button(240, 48, "PLAY!");
        _play_button->setPosition(200, 200);
        _settings_button = new Button(240, 48, "Settings");
        _settings_button->setPosition(200, 260);
    }

    MainMenuView::~MainMenuView()
    {

    }

    void MainMenuView::initialize()
    {
        View::initialize();

        // TODO: check the cursor position and set the button states accordingly
        _play_button->setButtonState(ButtonState::DEFAULT);
        _settings_button->setButtonState(ButtonState::DEFAULT);
    }

    void MainMenuView::uninitialize()
    {
        View::initialize();
    }

    void MainMenuView::updateScreen()
    {
        _window.clear(sf::Color::White);
        _window.draw(*_play_button);
        _window.draw(*_settings_button);
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

        if (_settings_button->contains(x, y))
        {
            _settings_button->setButtonState(ButtonState::HOVER);
        }
        else
        {
            _settings_button->setButtonState(ButtonState::DEFAULT);
        }
    }

    void MainMenuView::handleLeftClick(int x, int y)
    {
        Poco::EventArgs args;
        if (_play_button->contains(x, y))
        {
            playButtonClicked.notify(this, args);
        }
        else if (_settings_button->contains(x, y))
        {
            settingsButtonClicked.notify(this, args);
        }
    }
}

