#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include "player.hpp"

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr int rendererFlags = SDL_RENDERER_ACCELERATED;
constexpr int windowFlags = 0;

struct App{
    SDL_Renderer *renderer;
    SDL_Window *window;

    int up;
    int down;
    int left;
    int right;
};

class TutorialApp
{
public:
void initApp();
void initPlayer(int x, int y, const std::string& filename);

void prepareScene();
void presentScene();

void doInput();
void movePlayer();
void blit();

Entity *getPlayer(){return &player_;};


private:
SDL_Texture* loadTexture(std::string filename);

App app_{};
Entity player_{};
};

