#include "ECSCore/Entity.h"

Entity::Entity(Tag entityTag, size_t id)
    : components()
    , alive(true)
    , id(id)
    , tag(entityTag) {}

bool Entity::isAlive() const {
    return alive;
}

void Entity::markAsDead() {
    alive = false;
}
