#ifndef POINTER_H
#define POINTER_H

#include <SFML/Graphics.hpp>

namespace bubble
{

class Pointer
{
public:
    Pointer(sf::RenderWindow& w);
    virtual ~Pointer();

    void handle_event(sf::Event e);
    void draw();

private:
    sf::RenderWindow& window;
    int cursor_x = 0;
    int cursor_y = 0;
    int pivot_x = 320;
    int pivot_y = 480;
};

}

#endif // POINTER_H
