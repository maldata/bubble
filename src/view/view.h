#ifndef VIEW_H
#define VIEW_H

#include "../model/model.h"

#include <SFML/Graphics.hpp>

#include <Poco/BasicEvent.h>
#include <Poco/EventArgs.h>
#include <Poco/Logger.h>
#include <Poco/SharedPtr.h>

#include <forward_list>

namespace bubble
{
    typedef std::forward_list<sf::Event> EventList;

    class View
    {
    public:
        View(sf::RenderWindow& window, Poco::SharedPtr<Model> model);
        virtual ~View();

        void initialize();
        void uninitialize();
        int getEvents(EventList& list);
        virtual void updateScreen() = 0;
        virtual void handleNewMousePosition(int x, int y) = 0;
        virtual void handleLeftClick(int x, int y) = 0;

        Poco::BasicEvent<Poco::EventArgs> windowClosed;

    protected:
        Poco::Logger& _logger;
        sf::RenderWindow& _window;

        Poco::SharedPtr<Model> _model;
    };
}

#endif // VIEW_H


//#include <SFML/Graphics.hpp>

//int main()
//{
//    // create the window
//    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

//    // run the program as long as the window is open
//    while (window.isOpen())
//    {
//        // check all the window's events that were triggered since the last iteration of the loop
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            // "close requested" event: we close the window
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }

//        // clear the window with black color
//        window.clear(sf::Color::White);

//        sf::Text text;
//        sf::Font font;
//        font.loadFromFile("/home/mark/working/bubble/src/NotoSans-Regular.ttf");
//        text.setFont(font);
//        text.setString("Hello world!");
//        text.setCharacterSize(24); // in pixels, not points!
//        text.setFillColor(sf::Color::Black);
//        // text.setStyle(sf::Text::Bold | sf::Text::Underlined);
//        text.setPosition(20, 40);
//        sf::FloatRect globalRect = text.getGlobalBounds();
//        float right_edge = globalRect.left + globalRect.width;
//        float vertical_center = globalRect.top + (globalRect.height / 2.0);

//        sf::Texture texture;
//        texture.loadFromFile("/home/mark/working/bubble/unchecked.png");
//        sf::Sprite sprite;
//        sprite.setTexture(texture);
//        sf::FloatRect spriteRect = sprite.getGlobalBounds();
//        sprite.setPosition(right_edge, vertical_center - (spriteRect.height / 2.0));

//        // inside the main loop, between window.clear() and window.display()
//        window.draw(text);
//        window.draw(sprite);

//        // end the current frame
//        window.display();
//    }

//    return 0;
//}
