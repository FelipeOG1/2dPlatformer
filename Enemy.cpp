#include "Enemy.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include "Vec2.hpp"
#include "Colors.hpp"
#include <SDL3/SDL.h>

void Enemy::draw(Display& display, const Camera& camera) {
	Vec2 cameraPos = camera.getCameraPosition();
	SDL_FRect rect = {
		this->tc.worldPosition.x - cameraPos.x,
		this->tc.worldPosition.y - cameraPos.y,
		this->tc.w,
		this->tc.h
	};
	
	display.drawRect(rect, Colors::RED);
}
