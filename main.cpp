#include <SDL3/SDL.h>
#include "Game.hpp"
#include <memory>
int main(int argc, char* argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }

    {
        auto game = std::make_unique<Game>();
        game->start();
    }

    SDL_Quit();
    return 0;
}