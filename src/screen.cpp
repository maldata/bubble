#include "screen.h"

#include <cmath>

namespace bubble
{

Screen::Screen(sf::RenderWindow& w)
    : window(w)
{

}

Screen::~Screen()
{

}

void Screen::handle_event(sf::Event e)
{
    if (e.type == sf::Event::MouseMoved)
    {
        cursor_x = e.mouseMove.x;
        cursor_y = e.mouseMove.y;
    }
}

void Screen::draw()
{
    sf::ConvexShape polygon;
    polygon.setPointCount(3);
    polygon.setPoint(0, sf::Vector2f(0, 0));
    polygon.setPoint(1, sf::Vector2f(0, 10));
    polygon.setPoint(2, sf::Vector2f(25, 5));
    polygon.setOutlineColor(sf::Color::Red);
    polygon.setOutlineThickness(2);
    polygon.setPosition(100, 150);

    float dx = cursor_x - 100;
    float dy = cursor_y - 150;
    float angle = atan2(dy, dx);

    polygon.setRotation(angle * 180.0 / 3.14159);
    
    window.draw(polygon);
}

}
