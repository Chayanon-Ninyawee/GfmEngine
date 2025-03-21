#include "Systems/MovementSystem.h"

namespace MovementSystem
{

void update(float deltaTime) {
    for (const auto &entity : EntityManager::getInstance().getEntities()) {
        if (entity->hasComponent<TransformComponent>() &&
            entity->hasComponent<VelocityComponent>())
        {
            TransformComponent &transform = entity->getComponent<TransformComponent>();
            VelocityComponent &velocity = entity->getComponent<VelocityComponent>();

            transform.position.x += velocity.velocity.x * deltaTime;
            transform.position.y += velocity.velocity.y * deltaTime;
        }
    }
}

}  // namespace MovementSystem
