#include "app.hpp"
    
int main(int argc, char *argv[])
{
    TutorialApp app{};
    app.initApp();
    app.initPlayer(50, 50, "player.png");

    // atexit(cleanup);

    while (1)
    {
        app.prepareScene();
        app.doInput();  
        
        app.movePlayer();

        if (app.up)
        {
            player.y -= 4;
        }

        if (app.down)
        {
            player.y += 4;
        }

        if (app.left)
        {
            player.x -= 4;
        }

        if (app.right)
        {
            player.x += 4;
        }

        app.blit();
        app.presentScene();

        SDL_Delay(16);
    }

    return 0;
}
    // const int WINDOW_WIDTH = 800;
    // const int WINDOW_HEIGHT = 600;

    // SDL_Window* window = SDL_CreateWindow("Rectangle Movement", 
    //                                         SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
    //                                         WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

    // if (!window) {
    //     std::cerr << "윈도우 생성 실패: " << SDL_GetError() << std::endl;
    //     SDL_Quit();
    //     return -1;
    // }

    // SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    // if (!renderer) {
    //     std::cerr << "렌더러 생성 실패: " << SDL_GetError() << std::endl;
    //     SDL_DestroyWindow(window);
    //     SDL_Quit();
    //     return -1;
    // }

    // SDL_Rect rect = {100, 100, 10, 10}; // 초기 위치와 크기 설정

    // bool running = true;
    // SDL_Event event;

    // while (running) {
    //     while (SDL_PollEvent(&event)) {
    //         if (event.type == SDL_QUIT) {
    //             running = false;
    //         }
    //     }

    //     const Uint8* keystates = SDL_GetKeyboardState(NULL);
    //     const int RECT_SPEED = 5;

    //     if (keystates[SDL_SCANCODE_UP]) {
    //         rect.y -= RECT_SPEED;
    //     }
    //     if (keystates[SDL_SCANCODE_DOWN]) {
    //         rect.y += RECT_SPEED;
    //     }
    //     if (keystates[SDL_SCANCODE_LEFT]) {
    //         rect.x -= RECT_SPEED;
    //     }
    //     if (keystates[SDL_SCANCODE_RIGHT]) {
    //         rect.x += RECT_SPEED;
    //     }

    //     // 윈도우 경계 내로 제한
    //     if (rect.x < 0) rect.x = 0;
    //     if (rect.y < 0) rect.y = 0;
    //     if (rect.x + rect.w > WINDOW_WIDTH) rect.x = WINDOW_WIDTH - rect.w;
    //     if (rect.y + rect.h > WINDOW_HEIGHT) rect.y = WINDOW_HEIGHT - rect.h;

    //     // 렌더링
    //     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    //     SDL_RenderClear(renderer);

    //     SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    //     SDL_RenderFillRect(renderer, &rect);

    //     SDL_RenderPresent(renderer);

    //     SDL_Delay(16); // ~60 FPS 유지
    // }

    // SDL_DestroyRenderer(renderer);
    // SDL_DestroyWindow(window);
    // SDL_Quit();

    // return 0;
// }
