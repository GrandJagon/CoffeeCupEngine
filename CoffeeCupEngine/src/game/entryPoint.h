#define CCE_PLATFORM_LINUX

#ifdef CCE_PLATFORM_LINUX
#include "game.h"

extern Game* createGame();

int main(void)
{
    const int WINDOW_WIDTH = 640;
    const int WINDOW_HEIGHT = 480;

    auto game = createGame();
    
    // arguments to handle here
    game->init("Game test", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    game->run();

    delete game;
    
    return 0;
}

#endif

// WINDOWS TO COME HERE