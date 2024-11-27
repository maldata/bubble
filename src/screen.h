#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

#include "pointer.h"

namespace bubble
{

class Screen
{
public:
    Screen(sf::RenderWindow& w);
    virtual ~Screen();

    void handle_event(sf::Event e);
    void draw();

private:
    sf::RenderWindow& window;
    Pointer pointer;
};

}

#endif // SCREEN_H
