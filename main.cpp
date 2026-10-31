#include <SDL3/SDL.h>
#include "Game.hpp"

int main(int argc, char* argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        return -1;
    }

    {
        Game game;
        game.start();
    }

    SDL_Quit();
    return 0;
}