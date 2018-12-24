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

        virtual void updateScreen() override;
    };
}

#endif // GAMEPLAYVIEW_H
