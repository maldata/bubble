#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include "view.h"

#include "button.h"

namespace bubble
{
    class MainMenuView : public View
    {
    public:
        MainMenuView(sf::RenderWindow& window, Poco::SharedPtr<Model> model);
        virtual ~MainMenuView();

        void updateScreen() override;
        void handleNewMousePosition(int x, int y) override;
        void handleLeftClick(int x, int y) override;

        Poco::BasicEvent<Poco::EventArgs> playButtonClicked;
        Poco::BasicEvent<Poco::EventArgs> settingsButtonClicked;

    private:
        Poco::SharedPtr<Button> _play_button;
        Button _settings_button;
    };
}

#endif // MAINMENUVIEW_H
