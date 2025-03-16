#include <SFML/Graphics.hpp>

#include "GfmEngine.h"

GfmEngine::GfmEngine() {
}

GfmEngine::~GfmEngine() {
}

bool GfmEngine::run() {
    running = true;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test window");
    window.setVerticalSyncEnabled(true);

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineThickness(0);
    rectangle.setPosition({10, 20});

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::Black);

        window.draw(rectangle);

        window.display();
    }

    return true;
}
