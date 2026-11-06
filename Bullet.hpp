#pragma once
#include "Entity.hpp"
class Display;
class Camera;
class Game;

class Bullet : public Entity {
    
    float bulletDamage;
    Game* gameContext;
    Entity* shooter; // who spawned the bullet
public:
    Bullet() :
        Entity({ 0.0f, 0.0f }, 10, 10, 1000.0f, T_BULLET, false, false),
        bulletDamage(15.0f),
        gameContext(nullptr),
        shooter(nullptr) {}
    
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime) override;
    void setGameContext(Game* context) { gameContext = context; };
    void setShooter(Entity* entity) { shooter = entity; };
};
