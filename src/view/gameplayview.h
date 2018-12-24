#ifndef GAMEPLAYVIEW_H
#define GAMEPLAYVIEW_H

#include "view.h"

namespace bubble
{
    class GameplayView : public View
    {
    public:
        GameplayView(sf::RenderWindow& window, Poco::SharedPtr<Model> model);
        virtual ~GameplayView();

        void updateScreen() override;
        void handleMouseMove(int x, int y) override;
        void handleLeftClick(int x, int y) override;
    };
}

#endif // GAMEPLAYVIEW_H
