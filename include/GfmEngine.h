#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class GfmEngine
{
public:
    GfmEngine(const std::string &title, unsigned int width, unsigned int height);
    ~GfmEngine();

    void run();

    virtual void setup() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

    // TODO: This is temporary
    sf::RenderWindow window;

private:
    void init();
    void processInput();
    void stop();

    std::string windowTitle;
    unsigned int windowWidth;
    unsigned int windowHeight;
    bool isRunning;
    bool isStopped;
};