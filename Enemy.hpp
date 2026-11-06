#pragma once
#include "Vec2.hpp"
#include "Entity.hpp"
#include <SDL3/SDL.h>
#include "Components.hpp"

class Enemy : public Entity {
public:
    Enemy(Vec2 spawnPosition)
        : Entity(spawnPosition, 100, 100, 200.0f, T_ENEMY, true, true)
    {
    }
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime) override;
};