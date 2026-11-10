#pragma once
#include "Vec2.hpp"
#include "Entity.hpp"
#include <SDL3/SDL.h>
#include "Components.hpp"
#include "Colors.hpp"
class Enemy : public Entity {
  float animationTimer = 0.0f;
  SDL_Color defaultColor = Colors::PINK;
public:
    Enemy() : Entity({0.0f, 0.0f}, 100, 100, 200.0f, T_ENEMY, true, false) {}
    
    Enemy(Vec2 spawnPosition)
        : Entity(spawnPosition, 100, 100, 200.0f, T_ENEMY, true, false) {}

    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime) override;   
    void startHitAnimation(float deltatime);
};
