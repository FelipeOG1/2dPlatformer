#pragma once
#include "Vec2.hpp"
// Declaración adelantada para evitar dependencias circulares
class Player;
class Display;
class Entity;

class Camera {
private:
	Vec2 position{ 0, 0 };

public:
	Camera() = default;

	void followTarget(const Entity& entity, const Display& display);
	
	const Vec2& getCameraPosition() const { return position; }
};