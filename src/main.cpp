#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/System/Clock.hpp>

#include "screen.h"

int main(int argc, char* argv[])
{
    sf::RenderWindow window(sf::VideoMode(640,480), "First window!");
    bubble::Screen* current_screen = new bubble::Screen(window);
    sf::Clock throttle;
    float frames_per_second = 60.0;
    float sec_per_frame = 1.0 / frames_per_second;

    while (window.isOpen())
    {
        throttle.restart();
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

        // Figure out how long to sleep, then sleep
        sf::Time iteration_time = throttle.getElapsedTime();
        sf::Time sleep_sec = sf::seconds(sec_per_frame - iteration_time.asSeconds());
        sf::sleep(sleep_sec);
    }
}
