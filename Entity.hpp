#pragma once
#include "Components.hpp"

class Display;
class Camera;
class Entity {
	
public:
    TransformComponent tc;
	MoveComponent mc;

	virtual ~Entity() = default;
	virtual void draw(Display& display, const Camera& camera) = 0;
	virtual void update(float deltatime) = 0;
};
