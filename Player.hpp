#pragma once
#include <SDL3/SDL.h>
#include "Vec2.hpp"
#include "Entity.hpp"

class Display;
class Camera;

class Player : public Entity {
public:
    Player(Vec2 spawnPosition) : Entity(spawnPosition, 100, 100, 200.0f) {}
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime, const std::vector<Entity*>& entities) override;

    void shoot();
};
