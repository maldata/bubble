#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include "view.h"

namespace bubble
{
    class SettingsView : public View
    {
    public:
        SettingsView(sf::RenderWindow& window, Poco::SharedPtr<Model> model);
        virtual ~SettingsView();

        void updateScreen() override;
        void handleNewMousePosition(int x, int y) override;
        void handleLeftClick(int x, int y) override;
    };
}

#endif // SETTINGSVIEW_H
