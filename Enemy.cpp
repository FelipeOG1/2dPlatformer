#include "Enemy.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include "Vec2.hpp"
#include "Colors.hpp"
#include <SDL3/SDL.h>

void Enemy::draw(Display& display, const Camera& camera) {
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
void Enemy::startHitAnimation(float deltatime) {
  setColor(Colors::RED);
  animationTimer += deltatime;
  if (animationTimer > 0.14f) {
    isHit = false;
    animationTimer = 0.0f;
    setColor(defaultColor);
  }
}
void Enemy::update(float deltatime) {
  if (!isActive()) return;
  if (isHit) {
    startHitAnimation(deltatime);
  }
    
}
