#pragma once
#include "Entity.hpp"
class Display;
class Camera;
class Game;

class Bullet : public Entity {
    bool active;
    Game* gameContext;
public:
    Bullet() : active(false), gameContext(nullptr), Entity({ 0.0f, 0.0f }, 10, 10, 400.0f, T_BULLET) {}
    void draw(Display& display, const Camera& camera) override;
    void update(float deltatime) override;
    const bool is_active() const { return active; }
    void set_active(bool status) { active = status; }
    void setGameContext(Game* context) { gameContext = context; };
};
