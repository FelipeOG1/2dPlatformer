#include "Game.hpp"
#include <iostream>
void Game::drawEntities() {
    for (int i = 0; i < entitiesCounter; i++) {
        entities[i]->draw(display, camera);
        
    }
}


void Game::updateEntities(float deltatime) {
    for (int i = 0; i < entitiesCounter; i++) {
        entities[i]->update(deltatime, entities);
        
    }
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
        std::cout << "Player x" << player.getPosition().x << std::endl;
        
        camera.followTarget(player, display);

        display.clear();
        drawEntities();
        display.present();
    }
}