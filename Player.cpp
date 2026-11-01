#include "Player.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include "Colors.hpp"
#include "Engine.hpp"
#include <array>
#include "Constants.hpp"
#include <iostream>
void Player::draw(Display& display, const Camera& camera) {
	Vec2 cameraPos = camera.getCameraPosition();
	SDL_FRect rect = {
		this->tc.worldPosition.x - cameraPos.x,
		this->tc.worldPosition.y - cameraPos.y,
		this->tc.w,
		this->tc.h
	};
	
	display.drawRect(rect, Colors::PINK);
}

void Player::update(float deltatime, std::array<Entity*, MAX_NUM_ENTITIES>& entities) {
    const bool* keystate = SDL_GetKeyboardState(NULL);
	Vec2 currentPos = getPosition();
	if (keystate[SDL_SCANCODE_W]) {
		tc.worldPosition.y -= mc.speed * deltatime;
	}
	if (keystate[SDL_SCANCODE_A]) {
		tc.worldPosition.x -= mc.speed * deltatime;
	}
	if (keystate[SDL_SCANCODE_S]) {
		tc.worldPosition.y += mc.speed * deltatime;
	}
	
	if (keystate[SDL_SCANCODE_D]) {
		tc.worldPosition.x += mc.speed * deltatime;
	}
	
		
    
}