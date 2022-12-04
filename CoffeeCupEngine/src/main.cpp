#include <iostream>
#include <cstring>

#include "utils/utilities.h"
#include "rendering/texture/Texture.h"

#include "game/game.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;


int main(void)
{   

    Game::instance()->init("Game test", WINDOW_WIDTH, WINDOW_HEIGHT);
    
    std::shared_ptr<Texture> guyText = TextureManager::instance()->loadTexture("../res/textures/suit-guy.png");
    std::shared_ptr<Texture> turtle = TextureManager::instance()->loadTexture("../res/textures/turtle.jpeg");
    
    // Projection matrix
    glm::mat4 proj = glm::ortho(0.0f, (float) WINDOW_WIDTH, 0.0f, (float) WINDOW_HEIGHT, -1.0f, 1.0f);

    // Translation vector to be combined with identity matrix
    glm::vec3 translation = glm::vec3(0.0f,0.0f,0.0f);

    bool running = true;
    while (running)
    {   

        // SDL input handling
        SDL_Event e;

        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                std::cout << "Application temrinated by user" << std::endl;
                running = false;
            }
        
         if(e.type == SDL_MOUSEMOTION){
                //std::cout << "mouse has been moved\n";
            }

            // Retrieve the state of all of the keys
            // Then we can query the scan code of one or more
            // keys at a time
            const Uint8* state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_RIGHT]){
                //std::cout << "right arrow key is pressed\n";
            }
        }

        // Translation moves camera such as negative -> left,  positive -> right
        glm::mat4 view = glm::translate(glm::mat4(1.0f), translation);

        glm::mat4 model = glm::mat4(1.0f);
    
        // For MVP multiplication order is reversed in openGL
        glm::mat4 mvp = proj * view * model;

        GlCall(glClear(GL_COLOR_BUFFER_BIT));

        //Sets MVP
        Renderer::instance()->setMVP(mvp);


        for(int i = 0; i < 20; i++)
        {    
            for(int j = 0; j < 20; j++)
            {
                // Color call
                Renderer::instance()->draw({ 0.0f + (i * 100), 0.0f + (j * 100) }, { 100.0f, 100.0f }, {0.0f, 0.0f, 1.0f, 1.0f});
            }
        }
        

        // Texture call
        Renderer::instance()->draw({ 50.0f ,50.0f }, { 100.0f, 100.0f }, guyText);
        Renderer::instance()->draw({ 50.0f ,200.0f }, { 100.0f, 100.0f }, turtle);

        Renderer::instance()->render();
        Window::instance()->endFrame();
    }
    
    return 0;
}

