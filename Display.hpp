#pragma once
#include <SDL3/SDL.h>
#include "Colors.hpp"

class Display {
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    int windowW;
    int windowH;

public:
    Display(const char* window_name, int w = 600, int h = 600);
    ~Display();

    void setDrawColor(SDL_Color color);
    void clear();
    void present();

    SDL_Renderer* get_render() const { return renderer; }
    int getWidth() const { return windowW; }
    int getHeight() const { return windowH; }
};