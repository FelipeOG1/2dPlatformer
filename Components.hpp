#include "Vec2.hpp"

struct TransformComponent {
	int w; int h; Vec2 worldPosition;
};
struct MoveComponent {
	float speed{ 200.0f };
};