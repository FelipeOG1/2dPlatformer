#pragma once
#include "Entity.hpp"


class Display;
class Camera;

class Bullet : public Entity {
    bool active;
public:
    Bullet() : active(false), Entity({0.0f, 0.0f}, 10, 10, 400.0f) {}
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime, const std::vector<Entity*>& entities) override;
    const bool is_active() const { return active;  }
    void set_active(bool status) { active = status; }
};
