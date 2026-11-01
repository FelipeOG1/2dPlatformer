#pragma once
#include "Components.hpp"
#include "Vec2.hpp"
class Display;
class Camera;
class Entity {
	
public:
    TransformComponent tc;
	MoveComponent mc;

	Entity(Vec2 spawnPosition, int w, int h) : tc{spawnPosition, w, h } {};

	virtual ~Entity() = default;
	virtual void draw(Display& display, const Camera& camera) = 0;
	virtual void update(float deltatime) = 0;
};
