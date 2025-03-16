#pragma once

#include "GfmEngine.h"

class TestGame : public GfmEngine
{
public:
    TestGame();
    ~TestGame();

private:
    void update(float deltaTime) override;
    void render() override;
};