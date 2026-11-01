#pragma once

#include "Display.hpp"
#include "Player.hpp"
#include "Timer.hpp"
#include "Camera.hpp"
#include "Enemy.hpp"
#include "Constants.hpp"
#include "Entity.hpp"
#include <array>
class Game {
private:
    Display display;
    Player player;
    Timer timer;
    Camera camera;
    Enemy enemy;
    int entitiesCounter;
    void drawEntities();
    void updateEntities(float deltatime);
public:
    std::array<Entity*, MAX_NUM_ENTITIES> entities;
    Game() :
        display("2D Platformer", 600, 600),
        player({ 200.0f, 200.0f }),
        enemy({ 400.0f, 400.0f }),
        camera(),
        timer(),
        entitiesCounter(0){
        
        entities[entitiesCounter++] = &player;
        entities[entitiesCounter++] = &enemy;
        
        
    }
    void start();
};

   