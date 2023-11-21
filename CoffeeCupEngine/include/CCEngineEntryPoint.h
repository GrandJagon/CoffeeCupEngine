#ifdef CCE_PLATFORM_LINUX
#include "../src/game/game.h"

extern Game *createGame();

int main(void)
{
    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;

    auto game = createGame();

    game->init("Game test", WINDOW_WIDTH, WINDOW_HEIGHT);

    game->run();

    delete game;

    return 0;
}

#endif

#ifdef CCE_PLATFORM_WINDOWS
#include <windows.h>
#include "../src/game/game.h"

extern Game *createGame();

int main(void)
{
    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;

    auto game = createGame();

    game->init("Game test", WINDOW_WIDTH, WINDOW_HEIGHT);

    game->run();

    delete game;

    return 0;
}

#endif