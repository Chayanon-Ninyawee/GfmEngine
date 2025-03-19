#pragma once

#include <string>

#include <SFML/Graphics.hpp>

class GfmEngine
{
public:
    GfmEngine(
        const std::string &title,
        unsigned int width,
        unsigned int height,
        unsigned int updateFrequency
    );
    ~GfmEngine();

    void run();

    virtual void setup() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow window;

private:
    void init();
    void processInput();
    void stop();

    std::string windowTitle;
    unsigned int windowWidth;
    unsigned int windowHeight;

    const unsigned int updateFrequency;

    bool isRunning;
    bool isStopped;
};