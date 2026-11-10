#pragma once
#include "Components.hpp"
#include "Vec2.hpp"
#include <array>
#include "Constants.hpp"
#include <vector>

class Display;
class Camera;
class Entity {
	
	bool active;
	
public:
    enum EntityType{
		T_PLAYER,
		T_ENEMY,
		T_BULLET
	} type;

    
  TransformComponent tc;
	MoveComponent mc;
	HealthComponent hc;
	VisualComponent vc;
	bool canTakeDamage;
  bool isHit = false;
	Entity(Vec2 spawnPosition, int w, int h, float speed, EntityType type, bool canTakeDamage, bool active) :
		canTakeDamage(canTakeDamage),
		active(active),
		tc{ spawnPosition, w, h },
		mc{ speed },
		vc{ Colors::PINK },
		type(type){};

	virtual ~Entity() = default;
	virtual void draw(Display& display, const Camera& camera) = 0;
	virtual void update(float deltatime) = 0;
	
	void takeDamage(float damage) {
		hc.health -= damage;
	}
	
	Vec2& getPosition() { return tc.worldPosition; }
	const Vec2& getPosition() const { return tc.worldPosition; }
	const bool isActive() const { return active; }
	void setActive(bool status) { active = status; }
	void setColor(SDL_Color color) { vc.color = color; }
	SDL_Color getColor() const { return vc.color; }
  void setPosition(Vec2 pos) { this->tc.worldPosition = pos; } 
};
