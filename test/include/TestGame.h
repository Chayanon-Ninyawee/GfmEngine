#pragma once

#include "ECSCore/Entity.h"

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

    std::shared_ptr<Entity> testBoxPtr;
};