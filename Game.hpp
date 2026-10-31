#pragma once
#include "Display.hpp"
#include "Player.hpp"
#include "Timer.hpp"
#include "Camera.hpp"

class Game {
private:
    Display display;
    Player player;
    Timer timer;
    Camera camera;

    void drawEntities();
    void updateEntities(float deltatime);

public:
    Game();
    void start();
};