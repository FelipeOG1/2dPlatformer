#pragma once
#include "Components.hpp"
#include "Vec2.hpp"
#include <array>
#include "Constants.hpp"
#include <vector>
class Display;
class Camera;
class Entity {
	
public:
    TransformComponent tc;
	MoveComponent mc;

	Entity(Vec2 spawnPosition, int w, int h) : tc{spawnPosition, w, h } {};

	virtual ~Entity() = default;
	virtual void draw(Display& display, const Camera& camera) = 0;
	virtual void update(float deltatime, const std::vector<Entity*>& entities) = 0;
	
	Vec2& getPosition() { return tc.worldPosition; };
	const Vec2& getPosition() const { return tc.worldPosition; };
};
