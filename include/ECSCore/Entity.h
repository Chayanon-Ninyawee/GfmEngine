#pragma once

#include <cstddef>
#include <memory>
#include <tuple>

#include "Components/TransformComponent.h"
#include "Components/VelocityComponent.h"

/**
 * @brief Represents an entity in the ECS framework.
 *
 * An entity is a container for components. It holds a fixed set
 * of components, defined by the `ComponentTuple`, and provides
 * utility functions to access and modify them.
 */
class Entity
{
public:
    /**
     * @brief Enum class representing entity tags.
     *
     * Tags can be used to categorize entities, allowing for filtering
     * and efficient system processing.
     */
    enum class Tag
    {
        None
        // Add more as needed
    };

    // Tuple containing all possible components for an entity.
    using ComponentTuple = std::tuple<TransformComponent, VelocityComponent>;

    template <typename T>
    T &getComponent() {
        static_assert(
            std::is_base_of<Component, T>::value,
            "T must inherit from Component"
        );

        return std::get<T>(components);
    }

    template <typename T>
    bool hasComponent() {
        static_assert(
            std::is_base_of<Component, T>::value,
            "T must inherit from Component"
        );

        return std::get<T>(components).exists;
    }

    template <typename T>
    void removeComponent() {
        static_assert(
            std::is_base_of<Component, T>::value,
            "T must inherit from Component"
        );

        std::get<T>(components) = T();
    }

    template <typename T, typename... TArgs>
    T &addComponent(TArgs &&...args) {
        static_assert(
            std::is_base_of<Component, T>::value,
            "T must inherit from Component"
        );

        auto &component = std::get<T>(components);
        component = T(std::forward<TArgs>(args)...);
        component.exists = true;
        return component;
    }

    bool isAlive() const;
    void markAsDead();

private:
    Entity(Tag entityTag, size_t id);

    ComponentTuple components;
    bool alive;
    Tag tag;
    size_t id;

    friend class EntityManager;
};
