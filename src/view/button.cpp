#include "button.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace bubble
{
    Button::Button(unsigned int width, unsigned int height, std::string label)
    {
        _button_state = ButtonState::DEFAULT;

        // See here: https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderTexture.php

        _default_texture = new sf::RenderTexture();
        _default_texture->create(width, height);
        _default_texture->clear(sf::Color::Transparent);

        _hover_texture = new sf::RenderTexture();
        _hover_texture->create(width, height);
        _hover_texture->clear(sf::Color::Transparent);

        sf::RectangleShape default_rect(sf::Vector2f(width, height));
        default_rect.setFillColor(sf::Color::Cyan);
        sf::RectangleShape hover_rect(sf::Vector2f(width, height));
        hover_rect.setFillColor(sf::Color::Blue);

        sf::Font font;
        font.loadFromFile("/usr/share/fonts/TTF/DejaVuSans.ttf");
        sf::Text text;
        text.setFont(font);
        text.setString(label);
        text.setFillColor(sf::Color::Red);
        text.setCharacterSize(24);

        _default_texture->draw(default_rect);
        _default_texture->draw(text);
        _default_texture->display();

        _hover_texture->draw(hover_rect);
        _hover_texture->draw(text);
        _hover_texture->display();

        _default_sprite = new sf::Sprite(_default_texture->getTexture());
        _default_sprite->setPosition(200, 200);

        _hover_sprite = new sf::Sprite(_hover_texture->getTexture());
        _hover_sprite->setPosition(200, 200);
    }

    Button::~Button()
    {

    }

    void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (_button_state == ButtonState::DEFAULT)
        {
            target.draw(*_default_sprite, states);
        }
        else
        {
            target.draw(*_hover_sprite, states);
        }
    }

    void Button::setButtonState(ButtonState new_state)
    {
        if (_button_state != new_state)
        {
            _button_state = new_state;
        }
    }

    bool Button::contains(int x, int y)
    {
        sf::FloatRect bounds = _default_sprite->getGlobalBounds();
        return bounds.contains((float)x, (float)y);
    }
}
