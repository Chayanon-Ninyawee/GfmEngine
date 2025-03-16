#include "GfmEngine.h"

#include <iostream>

GfmEngine::GfmEngine(const std::string &title, unsigned int width, unsigned int height)
    : windowTitle(title)
    , windowWidth(width)
    , windowHeight(height)
    , isRunning(false)
    , isStopped(true)
{
}

GfmEngine::~GfmEngine()
{
    // TODO: Maybe remove this
    stop();
}

void GfmEngine::init()
{
    isStopped = false;

    window = sf::RenderWindow(
        sf::VideoMode({this->windowWidth, this->windowHeight}), this->windowTitle
    );
    window.setVerticalSyncEnabled(true);
}

void GfmEngine::processInput()
{
    // TODO: processInput: Not Implemented
    std::cout << "processInput: Not Implemented" << std::endl;
}

void GfmEngine::stop()
{
    if (isStopped) return;

    // TODO: stop: Not Implemented
    std ::cout << "stop: Not Implemented" << std::endl;
    isRunning = false;
    isStopped = true;
}

void GfmEngine::run()
{
    init();
    isRunning = true;

    float deltaTime = 1.0f / 60.0f;  // Simulating 60 FPS
    while (isRunning)
    {
        processInput();
        update(deltaTime);

        // TODO: Adapt the time to make the deltatime perfectly 1/60 second
        sf::sleep(sf::seconds(deltaTime));

        // check all the window's events that were triggered since the last iteration of
        // the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) window.close();
        }

        window.clear(sf::Color::Black);
        render();
        window.display();

        if (not window.isOpen()) isRunning = false;
    }
    stop();
}
