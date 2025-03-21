#include <bits/stdc++.h>

#include "ECSCore/EntityManager.h"

std::shared_ptr<Entity> EntityManager::addEntity(Entity::Tag tag) {
    auto entityPtr = std::make_shared<Entity>(Entity(tag, totalEntitiesCreated++));

    entities.push_back(entityPtr);

    return entityPtr;
}

EntityManager::EntityPtrVec &EntityManager::getEntities() {
    return entities;
}

EntityManager::EntityPtrVec &EntityManager::getEntities(const Entity::Tag tag) {
    // TODO: Fix this
    return entities;
}

void EntityManager::update() {}
