#pragma once
#include "Constants.hpp"
#include <vector>
class Player;
class Entity;

namespace Engine {
	namespace Collision {
		Entity* goingToColide(Entity* entity, float dx, float dy, const std::vector<Entity*>& entities);
	};
}