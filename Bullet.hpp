#pragma once
#include "Entity.hpp"


class Display;
class Camera;

class Bullet : public Entity {
public:
    Bullet (Vec2 spawnPosition) : Entity(spawnPosition, 20, 20, 400.0f) {}
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime, const std::vector<Entity*>& entities) override;
};
