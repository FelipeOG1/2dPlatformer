#include <string>
#include <cstring>
#include <SDL3/SDL.h>

struct Vec2 {
    float x;
    float y;
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
    int window_w;
    int window_h;
public:
    Display(const char* window_name) : window_w(600), window_h(600) {
        window = SDL_CreateWindow(window_name, window_w, window_h, 0);
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
    
    Vec2 getCenterScreen() {
        return {wid}
    }
    
    SDL_Renderer* get_render() const { return renderer; }
    ~Display() {
        if (renderer) SDL_DestroyRenderer(renderer);
        if (window) SDL_DestroyWindow(window);
    }
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
  
    SDL_FRect get_screnn_rect() const { return {position.x, position.y, w, h}; };
    
    void draw(Display& display) {
        SDL_FRect rect = get_rect();
        display.setDrawColor(Colors::RED);
        SDL_RenderFillRect(display.get_render(), &rect);
        SDL_RenderRect(display.get_render(), &rect);
    }
    void update(float deltatime) {
        const bool* keystate = SDL_GetKeyboardState(NULL);
        if (keystate[SDL_SCANCODE_D]) {
            position.x += speed * deltatime;
            
        }
        if (keystate[SDL_SCANCODE_A]) {
            position.x -= speed * deltatime;
     
        }
        
        
    }
};

class Game {
private:
    Display display;
    Player player;
    Timer timer;

    void drawEntities() {
        player.draw(display);
    }
    void updateEntities(float deltatime) {
        player.update(deltatime);
    }
public:
    
    Game() : display("Hello"), player(), timer() {}

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