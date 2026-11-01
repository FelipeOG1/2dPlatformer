#include "Vec2.hpp"

struct TransformComponent {
	Vec2 worldPosition{ 0.0f, 0.0f };
	int w{ 100 };
	int h{ 100 };
};

struct MoveComponent {
	float speed{ 200.0f };
};
