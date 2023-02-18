#include <CCEngineEntryPoint.h>

#include "exampleGame.h"


/// JUST HERE TO RUN THE EXANPLE BEFORE THE GAME LOOP IS PROPERLY CODED
#include <SDL2/SDL.h>

Game* createGame()
{
    return new ExampleGame();
}

void ExampleGame::run()
{
    bool running = true;

    std::shared_ptr<Texture> guyText = TextureManager::instance()->loadTexture("../assets/images/suit-guy.png");
    TextureManager::instance()->bindTexture(guyText);

    while(running)
    {
        // Basic event polling for testing purpose
        SDL_Event event;
        int x = 0;
        int y = 0;
        while(SDL_PollEvent(&event) > 0)
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym) {
                        case SDLK_LEFT:
                            x++;
                            break;
                        case SDLK_RIGHT:
                            x--;
                            break;
                        case SDLK_UP:
                            y--;
                            break;
                        case SDLK_DOWN:
                            y++;
                            break;
                    }
                    break;                
                case SDL_QUIT:
                    std::cout << "Quitting" << std::endl;
                    running = false;
                    break;

                case SDL_WINDOWEVENT_CLOSE:
                    std::cout << "Closing window" << std::endl;
                    running = false;
                    break;
            }
        }

        _camera->move(x,y);

        Renderer::instance()->setMVP(_camera->getVPM());

        for(int i = 0; i < 10; i++)
        {    
            for(int j = 0; j < 10; j++)
            {
                // Color call
                Renderer::instance()->draw({ 0.0f + (i * 100), 0.0f + (j * 100) }, { 100.0f, 100.0f }, {0.0f, 0.45f, 1.0f, 1.0f});
            }
        }

        Renderer::instance()->draw({ 50.0f ,50.0f }, { 100.0f, 100.0f }, guyText);

        Renderer::instance()->render();
        Renderer::instance()->endFrame(); 
        _window->endFrame();

    };
    _window->destroy();
    SDL_Quit();
}