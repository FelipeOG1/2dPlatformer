#include "Game.hpp"
#include "Vec2.hpp"
#include "Colors.hpp"
#include <iostream>

//testing effects

void Game::tDamage(Entity* inflictor, Entity* attacker, float damage) {
    inflictor->takeDamage(damage);
    if (inflictor->hc.health <= 0.0f) {
        inflictor->setActive(false);
    }
}

void Game::spawnBullet(Vec2 pos, Entity* shooter) {
    for (Bullet& bullet : bullets) {
        if (!bullet.isActive()) {
            bullet.setActive(true);
            bullet.tc.worldPosition = pos;
            bullet.setShooter(shooter);
            break;
        }
    }
}

Entity* Game::goingToColide(Entity* entity, float dx, float dy) {
    return Engine::Collision::goingToColide(entity, dx, dy, entities);   
}

void Game::drawEntities() {
    for (auto& entity : entities) entity->draw(display, camera);
    for (Bullet& bullet : bullets) {
        bullet.draw(display, camera);
    }
}

void Game::updateEntities(float deltatime) {
    for (auto& entity : entities) entity->update(deltatime);
    for (Bullet& bullet : bullets) {
        bullet.update(deltatime);
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
        
        
        camera.followTarget(player, display);

        display.clear();
        drawEntities();
        display.present();
    }
}