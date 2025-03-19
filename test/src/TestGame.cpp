#include <iostream>

#include "TestGame.h"

TestGame::TestGame()
    : GfmEngine("2D Game", 800, 600, 60) {}

TestGame::~TestGame() {}

void TestGame::setup() {
    window.setVerticalSyncEnabled(true);
}

void TestGame::update(float deltaTime) {
    float speed = 200.0f;  // Pixels per second
    testRectPosition.x += speed * deltaTime;

    if (testRectPosition.x >= 800) {
        testRectPosition.x = -100;
        testRectPosition.y += 50;
    }
    if (testRectPosition.y >= 600) {
        testRectPosition.y = 0;
    }
}

void TestGame::render() {
    sf::RectangleShape rectangle;
    rectangle.setSize({100, 50});
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineThickness(0);
    rectangle.setPosition(testRectPosition);  // Use updated position

    this->window.draw(rectangle);
}