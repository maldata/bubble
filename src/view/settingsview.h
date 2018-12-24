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

        virtual void updateScreen() override;
    };
}

#endif // SETTINGSVIEW_H
