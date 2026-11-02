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
    void drawEntities();
    void updateEntities(float deltatime);
public:
    
    std::vector<Entity*> entities; 
    std::array<Bullet, MAX_NUM_ENTITIES> bullets;
    Game() :
        display("2D Platformer", 600, 600),
        player({ 200.0f, 200.0f }),
        enemy({ 400.0f, 400.0f }),
        camera(),
        timer() {
        entities.reserve(MAX_NUM_ENTITIES);
        entities.push_back(&player);
        entities.push_back(&enemy);

    }
    void start();
};

   