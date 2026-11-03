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
    enum EntityType{
		T_PLAYER,
		T_ENEMY,
		T_BULLET
	} type;
	
    TransformComponent tc;
	MoveComponent mc;

	Entity(Vec2 spawnPosition, int w, int h, float speed, EntityType type) : tc{ spawnPosition, w, h }, mc{speed}, type(type){};

	virtual ~Entity() = default;
	virtual void draw(Display& display, const Camera& camera) = 0;
	virtual void update(float deltatime) = 0;
	
	Vec2& getPosition() { return tc.worldPosition; };
	const Vec2& getPosition() const { return tc.worldPosition; };
};
