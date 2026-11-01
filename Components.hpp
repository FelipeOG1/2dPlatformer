#include "Vec2.hpp"

struct TransformComponent {
	Vec2 worldPosition; int w; int h; };

struct MoveComponent {
	float speed{ 200.0f };
};