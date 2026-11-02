#pragma once

#include <SDL3/SDL.h>
#include "Vec2.hpp"
#include "Entity.hpp"
#include "Constants.hpp"

class Display;
class Camera;
class Bullet;
class Game;

class Player : public Entity {
private:
    Game* gameContext;

public:
    Player(Vec2 spawnPosition, Game* context)
        : gameContext(context), Entity(spawnPosition, 100, 100, 200.0f) {
    }
    
    void shoot();
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime) override;
};
