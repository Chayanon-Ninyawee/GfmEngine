#include "GfmEngine.h"

#include <iostream>

GfmEngine::GfmEngine(
    const std::string &title,
    unsigned int width,
    unsigned int height,
    unsigned int updateFrequency
)
    : windowTitle(title)
    , windowWidth(width)
    , windowHeight(height)
    , updateFrequency(updateFrequency)
    , isRunning(false)
    , isStopped(true) {}

GfmEngine::~GfmEngine() {
    // TODO: Maybe remove this
    stop();
}

void GfmEngine::init() {
    isStopped = false;

    window = sf::RenderWindow(
        sf::VideoMode({this->windowWidth, this->windowHeight}),
        this->windowTitle
    );
}

void GfmEngine::processInput() {
    // TODO: processInput: Not Implemented
    std::cout << "processInput: Not Implemented" << std::endl;
}

void GfmEngine::stop() {
    if (isStopped) return;

    // TODO: stop: Not Implemented
    std ::cout << "stop: Not Implemented" << std::endl;
    isRunning = false;
    isStopped = true;
}

void GfmEngine::run() {
    init();
    isRunning = true;
    setup();

    sf::Clock clock;
    const float timeStep = 1.0f / updateFrequency;
    float accumulatedTime = 0.0f;

    while (isRunning) {
        float deltaTime = clock.restart().asSeconds();
        accumulatedTime += deltaTime;

        processInput();

        // Poll Event for closing window
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) window.close();
        }

        // Fixed update loop
        while (accumulatedTime >= timeStep) {
            update(timeStep);
            accumulatedTime -= timeStep;
        }

        // Render
        window.clear(sf::Color::Black);
        render();
        window.display();

        if (not window.isOpen()) isRunning = false;
    }

    stop();
}
