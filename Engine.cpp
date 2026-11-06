#include "Engine.hpp"
#include "Player.hpp"

namespace Engine {
    Entity* Collision::goingToColide(Entity* entity, float dx, float dy, const std::vector<Entity*>& entities) {
        Vec2 entityPos = entity->getPosition();

        for (const auto& currentEntity : entities) {
            if (currentEntity == entity || !currentEntity->isActive()) continue;

            Vec2 currentEntityPos = currentEntity->getPosition();
            
            if (entityPos.x + dx < currentEntityPos.x + currentEntity->tc.w &&
                entityPos.x + entity->tc.w + dx > currentEntityPos.x &&
                entityPos.y + dy < currentEntityPos.y + currentEntity->tc.h &&
                entityPos.y + entity->tc.h + dy > currentEntityPos.y)
            {
                return currentEntity;
            }
        }

        return nullptr;
    }
}
