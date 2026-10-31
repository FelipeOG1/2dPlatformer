#include "Camera.hpp"
#include "Player.hpp"
#include "Display.hpp"

void Camera::followTarget(const Player& player, const Display& display) {
    Vec2 playerPos = player.getPosition();

    // Centrar la cámara en el jugador
    position.x = playerPos.x + (player.getWidth() / 2.0f) - (display.getWidth() / 2.0f);
    position.y = playerPos.y + (player.getHeight() / 2.0f) - (display.getHeight() / 2.0f);
}