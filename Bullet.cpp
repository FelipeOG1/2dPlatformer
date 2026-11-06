#include "Bullet.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include <SDL3/SDL.H>
#include "Vec2.hpp"
#include "Colors.hpp"
#include "Game.hpp"
#include  <iostream>

void Bullet::draw(Display& display, const Camera& camera) {
	if (!isActive()) return;
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
	if (!isActive()) return;
	
	float currentMovement = mc.speed * deltatime;
	
    Entity* colidingWith = gameContext->goingToColide(this, currentMovement, 0.0f);
	
	if (colidingWith && colidingWith->type == T_ENEMY) {
		setActive(false);
		if (colidingWith->canTakeDamage) {
			gameContext->tDamage(colidingWith, shooter, bulletDamage);
		}
	}
	tc.worldPosition.x += currentMovement;
}
