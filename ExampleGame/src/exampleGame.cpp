#include <CCEngineEntryPoint.h>

#include "exampleGame.h"
#include "input/controlCommands.h"

/// JUST HERE TO RUN THE EXANPLE BEFORE THE GAME LOOP IS PROPERLY CODED
#include <SDL2/SDL.h>
#include "utils/iniParser.h"

Game *createGame()
{
    return new ExampleGame();
}

void ExampleGame::init(std::string title, int width, int height)
{
    Game::init(title, width, height);

    // Initiating control commands
    // InputManager::instance()->registerInputCommand<UpCommand>("goUp");
    // InputManager::instance()->registerInputCommand<DownCommand>("goDown");
    // InputManager::instance()->registerInputCommand<RightCommand>("goRight");
    // InputManager::instance()->registerInputCommand<LeftCommand>("goLeft");
    // InputManager::instance()->registerInputCommand<JumpCommand>("jump");

    // InputManager::instance()->init("../assets/input/inputMapping.ini");
}

void ExampleGame::run()
{
    std::cout << "Starting to run the game" << std::endl;

    bool running = true;

    std::shared_ptr<Texture> guyText = TextureManager::instance()->loadTexture("../assets/images/suit-guy.png");
    TextureManager::instance()->bindTexture(guyText);

    Renderer::instance()->setMVP(_camera->getVPM());

    while (running)
    {

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                // Color call
                Renderer::instance()->draw({0.0f + (i * 100), 0.0f + (j * 100)}, {100.0f, 100.0f}, {0.0f, 0.45f, 1.0f, 1.0f});
            }
        }

        Renderer::instance()->draw({50.0f, 50.0f}, {100.0f, 100.0f}, guyText);

        Renderer::instance()->render();
        Renderer::instance()->endFrame();
        _window->endFrame();
    };

    _window->destroy();
    SDL_Quit();
}