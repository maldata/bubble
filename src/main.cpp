#include <cmath>

#include <SFML/Graphics.hpp>

#include "screen.h"

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(640,480), "First window!");
    bubble::Screen* current_screen = new bubble::Screen(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                // Close window button clicked
                window.close();
            }
            else
            {
                // Anything other event gets handled by the screen
                current_screen->handle_event(event);
            }
        }

        // Clear the window, draw whatever, then display the window.
        window.clear(sf::Color::Black);
        current_screen->draw();
        window.display();
    }
}
