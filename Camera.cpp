#include "Camera.hpp"
#include "Player.hpp"
#include "Display.hpp"
#include "Entity.hpp"
void Camera::followTarget(const Entity& entity, const Display& display) {
    Vec2 entityPos = entity.tc.worldPosition;

    position.x = entityPos.x + (entity.tc.w / 2.0f) - (display.getWidth() / 2.0f);
    position.y = entityPos.y + (entity.tc.h / 2.0f) - (display.getHeight() / 2.0f);
}