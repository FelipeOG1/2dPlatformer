#include <string>
#include <cstring>
#include <SDL3/SDL.h>

struct Vec2 {
    float x;
    float y;
};


//render position =  world position - playher
class Camera {
   Vec2 position;
   
   
public:
   void followTarget(Player& player, Display& display) {
       Vec2 playerPos = player.getPosition();

       position.x = playerPos.x + (player.getWidth() / 2.0f) - (display.getWidth());
       position.y = playerPos.y + (player.getHeight() / 2.0f) - (display.getHeight());
   }
    const Vec2 getCameraPosition() const { return position; }
       
   

 
    
    
};

namespace Colors {
    constexpr SDL_Color BLACK = { 0, 0, 0, 255 };
    constexpr SDL_Color RED = { 255, 0,   0,   255 };
    constexpr SDL_Color GREEN = { 0,   255, 0,   255 };
    constexpr SDL_Color BLUE = { 0,   0,   255, 255 };
}

class Display {
private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr; 
    int windowW;
    int windowH;
public:
    Display(const char* window_name) : windowW(600), windowH(600) {
        window = SDL_CreateWindow(window_name, windowW, windowH, 0);
        renderer = SDL_CreateRenderer(window, nullptr);
    }
    void setDrawColor(SDL_Color color) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    }

    void clear() {
        setDrawColor(Colors::BLACK);
        SDL_RenderClear(renderer);
    }

    void present() { 
        SDL_RenderPresent(renderer);
    }
      
    SDL_Renderer* get_render() const { return renderer; }
    ~Display() {
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
    }
    
    int getWidth() const { return windowW; };
    int getHeight() const { return windowW; };

      
};



class Timer {
    Uint64 lastTime;
public:
    Timer() : lastTime(SDL_GetTicks()) {}
    
    float getDeltaTime() {
        Uint64 currTime = SDL_GetTicks();
        float deltaTime = static_cast<float>(currTime - lastTime) / 1000.0f;
        lastTime = currTime;
        return deltaTime;
       
    }
     
};

class Player {
    float w;
    float h;
    float speed;
    Vec2 worldPosition;
    
public:
    Player(Vec2 spawnPosition) :
        w(100.0f),
        h(100.0f),
        speed(300.0f),
        worldPosition(spawnPosition) {}
  
    SDL_FRect get_rect(const Vec2& cameraPosition) const {
        return {
            worldPosition.x - cameraPosition.x,
            worldPosition.y - cameraPosition.y,
            w,
            h
        };
        
    };
  
    void draw(Display& display, const Camera& camera) {
        SDL_FRect rect = get_rect(camera.getCameraPosition());
        display.setDrawColor(Colors::RED);
        SDL_RenderFillRect(display.get_render(), &rect);
        SDL_RenderRect(display.get_render(), &rect);
    }
    void update(float deltatime) {
        const bool* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_D]) worldPosition.x += speed * deltatime;
        if (keystate[SDL_SCANCODE_A]) worldPosition.x -= speed * deltatime;
        if (keystate[SDL_SCANCODE_S]) worldPosition.y += speed * deltatime;
        if (keystate[SDL_SCANCODE_W]) worldPosition.y -= speed * deltatime;
    }
   
    Vec2 getPosition() const {
        return worldPosition;
    }
    
    int getHeight() const { return h; };
    int getWidth() const { return w; };
};

class Game {
private:
    Display display;
    Player player;
    Timer timer;
    Camera camera;

    void drawEntities() {
        player.draw(display, camera);
    }
    void updateEntities(float deltatime) {
        player.update(deltatime);
    }
public:
    
    Game() : 
        display("Hello"), 
        player({200.0f, 200.0f}),
        camera(),
        timer() {}

    void start() {
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
            camera.followTarget(player.getPosition(), 
                player.getWidth(), player.getHeight(),
                );
            

            display.clear();
   
        
            drawEntities();
            display.present();
        }
    }
};

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