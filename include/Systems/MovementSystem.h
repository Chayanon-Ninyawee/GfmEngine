#pragma once

#include "Components/TransformComponent.h"
#include "Components/VelocityComponent.h"
#include "ECSCore/EntityManager.h"

namespace MovementSystem
{

/**
 * @brief Updates the position of all entities that have TransformComponent and
 * VelocityComponent.
 *
 * This function iterates over all active entities and updates their positions
 * by applying their velocity.
 *
 * @param deltaTime The time elapsed since the last update, used for consistent movement
 * speed.
 */
void update(float deltaTime);

}  // namespace MovementSystem
