#include "app.hpp"

void TutorialApp::initApp()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }
    printf("SDL initialized\n");

    app_.window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app_.window)
    {
        printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }
    printf("Window created\n");

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    app_.renderer = SDL_CreateRenderer(app_.window, -1, rendererFlags);

    if (!app_.renderer)
    {
        printf("Failed to create renderer: %s\n", SDL_GetError());
        exit(1);
    }
    printf("Renderer Created\n");
}

void TutorialApp::doInput()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                exit(0);
                break;

            case SDL_KEYDOWN:
                doKeyDown(&event.key);
                break;

            case SDL_KEYUP:
                doKeyUp(&event.key);
                break;
            default:
                break;
        }
    }
}

void TutorialApp::prepareScene()
{
    SDL_SetRenderDrawColor(app_.renderer, 96, 128, 255, 255);
    SDL_RenderClear(app_.renderer);
}

void TutorialApp::presentScene()
{
    SDL_RenderPresent(app_.renderer);
}

void TutorialApp::initPlayer(int x, int y, const std::string& filename)
{
    player_.x = x;
    player_.y = y;
    player_.texture = loadTexture(filename);
}

SDL_Texture * TutorialApp::loadTexture(std::string filename)
{
    SDL_Texture *texture;
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename.c_str());
    texture = IMG_LoadTexture(app_.renderer, filename.c_str());

    return texture;
}

void TutorialApp::blit()
{
    SDL_Rect dest;

    dest.x = player_.x;
    dest.y = player_.y;

    dest.w = 50;
    dest.h = 50;

    SDL_QueryTexture(player_.texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(app_.renderer, player_.texture, NULL, &dest);
}