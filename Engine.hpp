#pragma once
#include <array>
#include "Constants.hpp"
class Player;
class Entity;
namespace Engine {
	
	namespace Collision {
		const bool goingToColide(Player* player, float dx, float dy, std::array<Entity*, MAX_NUM_ENTITIES>& entities);
		
	};
}