#pragma once
#include <SDL3/SDL.h>

class Timer {
private:
    Uint64 lastTime;

public:
    Timer() : lastTime(SDL_GetTicks()) {}

    float getDeltaTime() {
        Uint64 currTime = SDL_GetTicks();
        float deltaTime = static_cast<float>(currTime - lastTime) / 1000.0f;
        lastTime = currTime;
        return deltaTime;
    }
};