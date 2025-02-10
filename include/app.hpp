#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "player.hpp"
#include <string>

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr int rendererFlags = SDL_RENDERER_ACCELERATED;
constexpr int windowFlags = 0;

struct Inputs
{
    int up = 0;
    int down = 0;
    int left = 0;
    int right = 0;
};

struct App
{
    SDL_Renderer *renderer;
    SDL_Window *window;

    Inputs inputs{};
};

class TutorialApp
{
public:
    void initApp();
    void initPlayer(int x, int y, const std::string &filename);

    void prepareScene();
    void presentScene();

    void doInput();
    void movePlayer(const Inputs &inputs);
    void blit();

    Entity *getPlayer() { return &player_; };
    Inputs *getInputs() { return &app_.inputs; };

private:
    void doKeyUp(SDL_KeyboardEvent *event);
    void doKeyDown(SDL_KeyboardEvent *event);

    SDL_Texture *loadTexture(std::string filename);

    App app_{};
    Entity player_{};
};
