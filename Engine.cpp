#include "Engine.hpp"
#include "Player.hpp"
namespace Engine {
	
	const bool Collision::goingToColide(Player* player, float dx, float dy, std::array<Entity*, MAX_NUM_ENTITIES>& entities) {
		Vec2 playerPos = player->getPosition();
		for (const auto& entity : entities) {
			Vec2 currentEntityPos = entity->getPosition();
			if (playerPos.x + dx < currentEntityPos.x + entity->tc.w &&
				playerPos.x + player->tc.w + dx> currentEntityPos.x &&
				playerPos.y + dy < currentEntityPos.y + entity->tc.h &&
				playerPos.y + player->tc.h + dy > currentEntityPos.y
				) return true;
		}
		return false;
	}
		
	}
