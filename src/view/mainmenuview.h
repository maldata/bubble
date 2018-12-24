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
        void handleMouseMove(int x, int y) override;
        void handleLeftClick(int x, int y) override;

    private:
        Button _play_button;
        Button _settings_button;
    };
}

#endif // MAINMENUVIEW_H
