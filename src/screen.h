#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>

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
    int cursor_x = 0;
    int cursor_y = 0;
};

}

#endif // SCREEN_H
