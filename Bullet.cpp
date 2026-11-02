#include "Bullet.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include <SDL3/SDL.H>
#include "Vec2.hpp"
#include "Colors.hpp"

void Bullet::draw(Display& display, const Camera& camera) {
	if (!active) return;
	Vec2 cameraPos = camera.getCameraPosition();
    SDL_FRect rect = {
		this->tc.worldPosition.x - cameraPos.x,
		this->tc.worldPosition.y - cameraPos.y,
		this->tc.w,
		this->tc.h
	};
	display.drawRect(rect, Colors::GREEN);
}

void Bullet::update(float deltatime) {
	if (!active) return;
	tc.worldPosition.x += mc.speed * deltatime;
}
