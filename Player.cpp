#include "Player.hpp"
#include "Camera.hpp"
#include "Display.hpp"
#include "Colors.hpp"
#include "Engine.hpp"
#include <array>
#include "Constants.hpp"
#include "Bullet.hpp"
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

void Player::update(float deltatime, const std::vector<Entity*>& entities) {
    const bool* keystate = SDL_GetKeyboardState(NULL); 

    if (keystate[SDL_SCANCODE_W]) {
        if (!Engine::Collision::goingToColide(this, 0.0f, -mc.speed * deltatime, entities)) {
            tc.worldPosition.y -= mc.speed * deltatime;
        }
    }
   
    if (keystate[SDL_SCANCODE_S]) {
        if (!Engine::Collision::goingToColide(this, 0.0f, mc.speed * deltatime, entities)) {
            tc.worldPosition.y += mc.speed * deltatime;
        }
    }

    if (keystate[SDL_SCANCODE_A]) {
        if (!Engine::Collision::goingToColide(this, -mc.speed * deltatime, 0.0f, entities)) {
            tc.worldPosition.x -= mc.speed * deltatime;
        }
    }
    if (keystate[SDL_SCANCODE_D]) {
        if (!Engine::Collision::goingToColide(this, mc.speed * deltatime, 0.0f, entities)) {
            tc.worldPosition.x += mc.speed * deltatime;
        }
    }
    if (keystate[SDL_SCANCODE_P]) {
        
    }
    
}

