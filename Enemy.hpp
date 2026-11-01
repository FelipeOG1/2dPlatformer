#include "Vec2.hpp"

class Enemy {
	Vec2 worldPosition;
	int w;
	int h;
	float speed;
	
public:
	Enemy(Vec2 pos) : worldPosition(pos), speed(200.0f) {}

	void draw();
	void update();
		
	
	
};