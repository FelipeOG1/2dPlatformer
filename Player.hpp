#pragma once
#include <SDL3/SDL.h>
#include "Vec2.hpp"
class Display;
class Camera;

class Player {
    float w;
    float h;
    float speed;
    Vec2 worldPosition;
    
public:
    Player(Vec2 spawnPosition) :
        w(100.0f),
        h(100.0f),
        speed(300.0f),
        worldPosition(spawnPosition) {}
  
    SDL_FRect getRect(const Vec2& cameraPosition) const; 
    void draw(Display& display, const Camera& camera);
    void update(float deltatime);
   
    
    Vec2 getPosition() const { return worldPosition; }
    int getHeight() const { return h; };
    int getWidth() const { return w; };
};
