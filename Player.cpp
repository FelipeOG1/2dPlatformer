#include "Player.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include "Colors.hpp"

SDL_FRect Player::getRect(const Vec2& cameraPosition) const {
    return {
        worldPosition.x - cameraPosition.x,
        worldPosition.y - cameraPosition.y,
        w,
        h
    };
}

void Player::draw(Display& display, const Camera& camera) {
    SDL_FRect rect = getRect(camera.getCameraPosition());

    display.setDrawColor(Colors::RED);
    SDL_RenderFillRect(display.get_render(), &rect);

    display.setDrawColor(Colors::GREEN);
    SDL_RenderRect(display.get_render(), &rect);
}

void Player::update(float deltatime) {
    const bool* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_D]) worldPosition.x += speed * deltatime;
    if (keystate[SDL_SCANCODE_A]) worldPosition.x -= speed * deltatime;
    if (keystate[SDL_SCANCODE_S]) worldPosition.y += speed * deltatime;
    if (keystate[SDL_SCANCODE_W]) worldPosition.y -= speed * deltatime;
    
}