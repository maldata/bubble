#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <SFML/Graphics.hpp>

#include <Poco/BasicEvent.h>
#include <Poco/EventArgs.h>
#include <Poco/Logger.h>
#include <Poco/SharedPtr.h>

#include "../model/model.h"

namespace bubble
{
    class MainView
    {
    public:
        MainView(Poco::SharedPtr<Model> model);
        virtual ~MainView();

        void initialize();
        void uninitialize();
        void handleEvents();

        Poco::BasicEvent<Poco::EventArgs> windowClosed;

    private:
        Poco::Logger& _logger;

        Poco::SharedPtr<Model> _model;

        sf::RenderWindow _window;
    };
}

#endif // MAINVIEW_H


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
