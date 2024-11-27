#include "pointer.h"

#include <cmath>

namespace bubble
{

Pointer::Pointer(sf::RenderWindow& w)
    : window(w)
{

}

Pointer::~Pointer()
{

}

void Pointer::handle_event(sf::Event e)
{
    if (e.type == sf::Event::MouseMoved)
    {
        cursor_x = e.mouseMove.x;
        cursor_y = e.mouseMove.y;
    }
}

void Pointer::draw()
{
    sf::ConvexShape polygon;
    polygon.setPointCount(3);
    polygon.setPoint(0, sf::Vector2f(0, -5));
    polygon.setPoint(1, sf::Vector2f(0, 5));
    polygon.setPoint(2, sf::Vector2f(25, 0));
    polygon.setOutlineColor(sf::Color::Red);
    polygon.setOutlineThickness(2);
    polygon.setPosition(pivot_x, pivot_y);

    float dx = cursor_x - pivot_x;
    float dy = cursor_y - pivot_y;
    float angle = atan2(dy, dx);

    polygon.setRotation(angle * 180.0 / M_PI);
    
    window.draw(polygon);
}

}
