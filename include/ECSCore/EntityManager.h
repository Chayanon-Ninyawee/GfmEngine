#pragma once

#include <map>
#include <memory>
#include <vector>

#include "ECSCore/Entity.h"

class EntityManager
{
public:
    using EntityPtrVec = std::vector<std::shared_ptr<Entity>>;
    using EntityPtrMap = std::map<Entity::Tag, std::shared_ptr<Entity>>;

    static EntityManager &getInstance() {
        static EntityManager instance;
        return instance;
    }

    std::shared_ptr<Entity> addEntity(const Entity::Tag tag);
    EntityPtrVec &getEntities();
    EntityPtrVec &getEntities(const Entity::Tag tag);
    void update();

private:
    EntityManager() = default;
    ~EntityManager() = default;
    EntityManager(const EntityManager &) = delete;
    EntityManager &operator=(const EntityManager &) = delete;

    EntityPtrVec entities;
    EntityPtrMap entityMap;
    size_t totalEntitiesCreated = 0;
};
