#pragma once

#include <SFML/System/Vector2.hpp>

#include "ECSCore/Component.h"

/**
 * @brief Represents the velocity of an entity.
 *
 * The VelocityComponent stores the speed and direction of movement
 * in a 2D space. It is typically used for physics simulations
 * and movement systems.
 */
class VelocityComponent : public Component
{
public:
    /**
     * @brief The velocity of the entity in 2D space.
     */
    sf::Vector2f velocity;

    /**
     * @brief The angular velocity of the entity in degrees per second.
     */
    float angularVelocity;

    /**
     * @brief Constructs a VelocityComponent with default or specified values.
     *
     * @param velocity The initial velocity (default: {0.0f, 0.0f}).
     * @param angularVelocity The initial angular velocity (default: 0.0f).
     */
    VelocityComponent(sf::Vector2f velocity = {0.0f, 0.0f}, float angularVelocity = 0.0f)
        : velocity(velocity)
        , angularVelocity(angularVelocity) {}
};
