#pragma once
#include "Bullet.hpp"
#include "Display.hpp"
#include "Player.hpp"
#include "Timer.hpp"
#include "Camera.hpp"
#include "Enemy.hpp"
#include "Constants.hpp"
#include "Entity.hpp"
#include <vector>
#include <array>

class Game {
private:
    Display display;
    Player player;
    Timer timer;
    Camera camera;
    Enemy enemy;
    
    std::vector<Entity*> entities; 
    std::array<Bullet, MAX_NUM_BULLETS> bullets;
    
    void drawEntities();
    void updateEntities(float deltatime);
public:
        Game() :
        display("2D Platformer", 600, 600),
        player({ 200.0f, 200.0f }, this),
        enemy({ 400.0f, 400.0f }),
        camera(),
        timer() {
        entities.reserve(MAX_NUM_ENTITIES);
        entities.push_back(&player);
        entities.push_back(&enemy);
    }
    void start();
    std::vector<Entity*>& getEntities() { return entities; }
    void spawnBullet(Vec2 pos);
    bool goingToColide(Entity* entity, float dx, float dy);
    
};

   