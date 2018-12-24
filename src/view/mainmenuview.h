#ifndef MAINMENUVIEW_H
#define MAINMENUVIEW_H

#include "view.h"

namespace bubble
{
    class MainMenuView : public View
    {
    public:
        MainMenuView(sf::RenderWindow& window, Poco::SharedPtr<Model> model);
        virtual ~MainMenuView();

        virtual void updateScreen() override;
    };
}

#endif // MAINMENUVIEW_H
