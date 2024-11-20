//#include <Poco/Util/Application.h>
//#include "bubbleapp.h"

//POCO_APP_MAIN(bubble::BubbleApp);

#include <cmath>

#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(640,480), "First window!");
    int cursor_x = 0;
    int cursor_y = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // Close window button clicked.
                window.close();
            }
            else if (event.type == sf::Event::MouseMoved)
            {
                cursor_x = event.mouseMove.x;
                cursor_y = event.mouseMove.y;
            }
        }

        // Clear the window, draw whatever, then display the window.
        window.clear(sf::Color::Black);

        sf::ConvexShape polygon;
        polygon.setPointCount(3);
        polygon.setPoint(0, sf::Vector2f(0, 0));
        polygon.setPoint(1, sf::Vector2f(0, 10));
        polygon.setPoint(2, sf::Vector2f(25, 5));
        polygon.setOutlineColor(sf::Color::Red);
        polygon.setOutlineThickness(5);
        polygon.setPosition(100, 150);

        float dx = cursor_x - 100;
        float dy = cursor_y - 150;
        float angle = atan2(dy, dx);

        //polygon.setRotation(-25.0);
        polygon.setRotation(angle * 180.0 / 3.14159);
        
        window.draw(polygon);

        window.display();
    }
}
