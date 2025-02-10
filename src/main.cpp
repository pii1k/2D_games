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

        app.movePlayer(*app.getInputs());

        // app.blit();
        app.presentScene();

        SDL_Delay(16);
    }

    return 0;
}