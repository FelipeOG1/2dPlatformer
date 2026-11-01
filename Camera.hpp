#pragma once
#include "Vec2.hpp"
#include "Entity.hpp"
// Declaración adelantada para evitar dependencias circulares
class Player;
class Display;

class Camera {
private:
	Vec2 position{ 0, 0 };

public:
	Camera() = default;

	void followTarget(const Entity& entity, const Display& display);

	// Getter en línea
	const Vec2& getCameraPosition() const { return position; }
};