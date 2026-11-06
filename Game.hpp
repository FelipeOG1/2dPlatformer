#pragma once
#include "Constants.hpp"
#include <vector>
#include <array>
#include "Engine.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Entity.hpp"
#include "Player.hpp"
#include "Display.hpp"
#include "Camera.hpp"
#include "Timer.hpp"
#include "Vec2.hpp"

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
        for (Bullet& b : bullets) b.setGameContext(this); 
    }
    void start();
    std::vector<Entity*>& getEntities() { return entities; }
    void spawnBullet(Vec2 pos, Entity* shooter);
    Entity* goingToColide(Entity* entity, float dx, float dy);
    void tDamage(Entity* inflictor, Entity* attacker, float damage); //quake inspired }

};