#pragma once

#include <SFML/System/Vector2.hpp>

#include "ECSCore/Component.h"

/**
 * @brief Represents the transformation properties of an entity.
 *
 * The TransformComponent stores the position, rotation, and scale
 * of an entity in a 2D space. It is commonly used for positioning
 * and manipulating objects in a scene.
 */
class TransformComponent : public Component
{
public:
    /**
     * @brief The position of the entity in 2D space.
     */
    sf::Vector2f position;

    /**
     * @brief The rotation of the entity in degrees.
     */
    float rotation;

    /**
     * @brief The scale of the entity in 2D space.
     */
    sf::Vector2f scale;

    /**
     * @brief Constructs a TransformComponent with default or specified values.
     *
     * @param position The initial position (default: {0.0f, 0.0f}).
     * @param rotation The initial rotation in degrees (default: 0.0f).
     * @param scale The initial scale (default: {1.0f, 1.0f}).
     */
    TransformComponent(
        sf::Vector2f position = {0.0f, 0.0f},
        float rotation = 0.0f,
        sf::Vector2f scale = {1.0f, 1.0f}
    )
        : position(position)
        , rotation(rotation)
        , scale(scale) {}
};
