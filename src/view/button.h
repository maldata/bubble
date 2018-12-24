#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Text.hpp>

#include "shapes/roundedrectangleshape.h"

namespace bubble
{
    class Button : public sf::Drawable
    {
    public:
        Button();
        virtual ~Button();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    private:
        sf::RoundedRectangleShape _rect;
        sf::Text _button_text;
    };
}


#endif // BUTTON_H
