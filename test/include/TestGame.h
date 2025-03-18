#pragma once

#include "GfmEngine.h"

class TestGame : public GfmEngine
{
public:
    TestGame();
    ~TestGame();

private:
    void setup() override;
    void update(float deltaTime) override;
    void render() override;

    sf::Vector2f testRectPosition = {-100, 0};
};