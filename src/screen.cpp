#include "screen.h"

#include <cmath>

namespace bubble
{

Screen::Screen(sf::RenderWindow& w)
    : window(w), pointer(w)
{

}

Screen::~Screen()
{

}

void Screen::handle_event(sf::Event e)
{
    pointer.handle_event(e);
    // TODO: handle events for other objects
}

void Screen::draw()
{
    pointer.draw();
    // TODO: draw other objects
}

}
