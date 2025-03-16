#include <iostream>

#include "TestGame.h"

TestGame::TestGame()
    : GfmEngine("2D Game", 800, 600)
{
}

TestGame::~TestGame()
{
}

void TestGame::update(float deltaTime)
{
}

void TestGame::render()
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineThickness(0);
    rectangle.setPosition({10, 20});

    this->window.draw(rectangle);
}
