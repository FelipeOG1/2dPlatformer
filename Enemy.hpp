#include "Vec2.hpp"
#include "Entity.hpp"
#include <SDL3/SDL.h>

class Enemy : public Entity {   
public:
    
    Enemy(Vec2 spawnPosition) : Entity(spawnPosition, 100, 100, 200.0f, T_ENEMY) {}
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime) override;

};