#include "Vec2.hpp"

struct TransformComponent {
	Vec2 worldPosition{ 0.0f, 0.0f };
	int w{ 0 };
	int h{ 0 };
};

struct MoveComponent {
	float speed{ 0.0f };
};
