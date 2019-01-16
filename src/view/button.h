#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <string>

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <Poco/SharedPtr.h>

namespace bubble
{
    enum ButtonState
    {
        DEFAULT=0,
        HOVER=1,
        PRESSED=2
    };

    class Button : public sf::Drawable
    {
    public:
        Button(unsigned int width = 0, unsigned int height = 0, std::string label = "");
        virtual ~Button();

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        void setButtonState(ButtonState new_state);
        void setPosition(int x, int y);
        bool contains(int x, int y);

    private:
        ButtonState _button_state;

        // The texture needs to stay alive as long as the sprite does, so we'll keep the textures in class private data also
        Poco::SharedPtr<sf::RenderTexture> _default_texture;
        Poco::SharedPtr<sf::RenderTexture> _hover_texture;

        Poco::SharedPtr<sf::Sprite> _default_sprite;
        Poco::SharedPtr<sf::Sprite> _hover_sprite;
    };
}


#endif // BUTTON_H
