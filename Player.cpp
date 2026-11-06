#include "Player.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include "Colors.hpp"
#include "Engine.hpp"
#include <array>
#include "Constants.hpp"
#include "Game.hpp"
#include "Bullet.hpp"
#include "Components.hpp"

void Player::shoot() {
    if (fireTimer <= 0.0f) {
        Vec2 pos = getPosition();
        pos.x += tc.w;
        gameContext->spawnBullet(pos, this);
        fireTimer += fireRate;
    }
}
void Player::draw(Display& display, const Camera& camera) {
    if (!isActive()) return;
	Vec2 cameraPos = camera.getCameraPosition();
	SDL_FRect rect = {
		this->tc.worldPosition.x - cameraPos.x,
		this->tc.worldPosition.y - cameraPos.y,
		this->tc.w,
		this->tc.h
	};
	
	display.drawRect(rect, vc.color);
}

void Player::update(float deltatime) {
    if (!isActive()) return;
    const bool* keystate = SDL_GetKeyboardState(NULL);
    if (fireTimer > 0.0f) {
        fireTimer -= deltatime;
    }
  
    if (keystate[SDL_SCANCODE_W]) {
        if (!gameContext->goingToColide(this, 0.0f, -mc.speed * deltatime)) {
            tc.worldPosition.y -= mc.speed * deltatime;
        }
    }
   
    if (keystate[SDL_SCANCODE_S]) {
        if (!gameContext->goingToColide(this, 0.0f, mc.speed * deltatime)) {
            tc.worldPosition.y += mc.speed * deltatime;
        }
    }
    
    if (keystate[SDL_SCANCODE_A]) {
        if (!gameContext->goingToColide(this, -mc.speed * deltatime, 0.0f)) {
            tc.worldPosition.x -= mc.speed * deltatime;
        }
    }
    if (keystate[SDL_SCANCODE_D]) {
        if (!gameContext->goingToColide(this, mc.speed * deltatime, 0.0f)) {
            tc.worldPosition.x += mc.speed * deltatime;
        }
    }
    if (keystate[SDL_SCANCODE_P] && fireTimer <= 0.0f) {
        shoot();
    }
       
}
