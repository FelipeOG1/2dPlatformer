#include "Vec2.hpp"
#include "Entity.hpp"
#include <SDL3/SDL.h>

class Enemy : public Entity {   
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime) override;
};