#pragma once
#include "Vec2.hpp"

// Declaración adelantada para evitar dependencias circulares
class Player;
class Display;

class Camera {
private:
	Vec2 position{ 0, 0 };

public:
	Camera() = default;

	void followTarget(const Player& player, const Display& display);

	// Getter en línea
	const Vec2& getCameraPosition() const { return position; }
};