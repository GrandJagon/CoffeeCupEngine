#include <CCEngineEntryPoint.h>

#include "exampleGame.h"

/// TO BE ADDED TO THE CAMERA CLASS WHEN CREATED
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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

    // Projection matrix
    glm::mat4 proj = glm::ortho(0.0f, (float) 640, 0.0f, (float) 480, -1.0f, 1.0f);

    // Translation vector to be combined with identity matrix
    glm::vec3 translation = glm::vec3(0.0f,0.0f,0.0f);
    
    while(running)
    {
        // Basic event polling for testing purpose
        SDL_Event event;
        while(SDL_PollEvent(&event) > 0)
        {
            switch(event.type)
            {
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

        glm::mat4 view = glm::translate(glm::mat4(1.0f), translation);

        glm::mat4 model = glm::mat4(1.0f);

        // For MVP multiplication order is reversed in openGL
        glm::mat4 mvp = proj * view * model;

        //Sets MVP
        Renderer::instance()->setMVP(mvp);

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