#include <iostream>

#include "Components/TransformComponent.h"
#include "Components/VelocityComponent.h"
#include "ECSCore/EntityManager.h"
#include "Systems/MovementSystem.h"

#include "TestGame.h"

TestGame::TestGame()
    : GfmEngine("2D Game", 800, 600, 60) {}

TestGame::~TestGame() {}

void TestGame::setup() {
    window.setVerticalSyncEnabled(true);

    EntityManager &entityManager = EntityManager::getInstance();

    // TODO: This is just a test
    testBoxPtr = entityManager.addEntity(Entity::Tag::None);
    testBoxPtr->addComponent<TransformComponent>(sf::Vector2f({0.0f, 0.0f}));
    testBoxPtr->addComponent<VelocityComponent>(sf::Vector2f({200.0f, 200.0f}));
}

void TestGame::update(float deltaTime) {
    MovementSystem::update(deltaTime);
}

void TestGame::render() {
    // TODO: This is just a test
    sf::RectangleShape rectangle;
    rectangle.setSize({100, 50});
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setOutlineThickness(0);
    rectangle.setPosition(testBoxPtr->getComponent<TransformComponent>().position);

    this->window.draw(rectangle);
}