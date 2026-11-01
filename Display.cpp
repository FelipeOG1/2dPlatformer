#include "Display.hpp"
#include "Entity.hpp"
#include "Camera.hpp"
#include "Vec2.hpp"
#include "Colors.hpp"

Display::Display(const char* window_name, int w, int h) : windowW(w), windowH(h) {
    window = SDL_CreateWindow(window_name, windowW, windowH, 0);
    renderer = SDL_CreateRenderer(window, nullptr);
}

Display::~Display() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
}

void Display::drawRect( SDL_FRect rect, SDL_Color color) {
    setDrawColor(color);
    SDL_RenderFillRect(this->renderer, &rect);
    SDL_RenderRect(this->renderer, &rect); 
}

void Display::setDrawColor(SDL_Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void Display::clear() {
    setDrawColor(Colors::BLACK);
    SDL_RenderClear(renderer);
}

void Display::present() {
    SDL_RenderPresent(renderer);
}
