#include "Display.hpp"

Display::Display(const char* window_name, int w, int h) : windowW(w), windowH(h) {
    window = SDL_CreateWindow(window_name, windowW, windowH, 0);
    renderer = SDL_CreateRenderer(window, nullptr);
}

Display::~Display() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);
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