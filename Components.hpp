#pragma once
#include "Vec2.hpp"
#include "Colors.hpp"
struct TransformComponent {
	Vec2 worldPosition{ 0.0f, 0.0f };
	int w{ 0 };
	int h{ 0 };
};

struct MoveComponent {
	float speed{ 0.0f };
};

struct HealthComponent {
	float health{ 100.0f };
};
struct VisualComponent {
	SDL_Color color {Colors::GREEN}; 
}; 