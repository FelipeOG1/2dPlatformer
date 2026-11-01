#include "Player.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include "Colors.hpp"


void Player::draw(Display& display, const Camera& camera) {
	Vec2 cameraPos = camera.getCameraPosition();
	SDL_FRect rect = {
		this->tc.worldPosition.x - cameraPos.x,
		this->tc.worldPosition.y - cameraPos.y,
		this->tc.w,
		this->tc.h
	};
	
	display.drawRect(rect, Colors::RED);
}
void Player::update(float deltatime) {
    const bool* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_D]) this->tc.worldPosition.x += this->mc.speed * deltatime;
    if (keystate[SDL_SCANCODE_A]) this->tc.worldPosition.x -= this->mc.speed * deltatime;
    if (keystate[SDL_SCANCODE_S]) this->tc.worldPosition.y += this->mc.speed * deltatime;
    if (keystate[SDL_SCANCODE_W]) this->tc.worldPosition.y -= this->mc.speed * deltatime;
    
}