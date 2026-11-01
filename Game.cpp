#include "Game.hpp"
#include <iostream>
Game::Game()
    : display("2D Platformer", 600, 600),
    player({ 200.0f, 200.0f }),
    camera(),
    timer() {
}

void Game::drawEntities() {
    player.draw(display, camera);
}

void Game::updateEntities(float deltatime) {
    player.update(deltatime);
}

void Game::start() {
    bool isRunning = true;
    SDL_Event event;

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            }
        }

        float deltatime = timer.getDeltaTime();
        updateEntities(deltatime);
        std::cout << "Player x" << player.getPosition().x;
        
        camera.followTarget(player, display);

        display.clear();
        drawEntities();
        display.present();
    }
}