#include "mainview.h"

namespace bubble
{
    MainView::MainView()
    {
    }

    MainView::~MainView()
    {

    }

    void MainView::initialize()
    {
        _window.create(sf::VideoMode(800, 600), "My window");
        _window.clear();
        _window.display();
    }

    void MainView::uninitialize()
    {

    }
}
