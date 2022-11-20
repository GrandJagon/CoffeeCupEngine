#include <iostream>
#include <cstring>

#include "../vendors/imgui/imgui.h"
#include "../vendors/imgui/imgui_impl_glfw_gl3.h"
#include "utils/utilities.h"
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;


int main(void)
{   
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL could not be initialized: " <<
                  SDL_GetError();
    }else{
        std::cout << "SDL video system is ready to go\n";
    }

    // Setting SDL openGL version to 4.5
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);
    
    // Deprecated features are not allowed
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Enabling double buffering with buffer size of 24 bits
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


    // Creating window
    SDL_Window *window = SDL_CreateWindow("Title test", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    // Creating context
    SDL_GLContext openGlContext = SDL_GL_CreateContext(window);

    if(openGlContext == nullptr)
    {
        std::cout << "OpenGL context could not be created" << std::endl;
        return -1;
    }

    // Sets glew up
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        throw std::runtime_error("Error while initializing glew");
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

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
                std::cout << "mouse has been moved\n";
            }
 
            // Retrieve the state of all of the keys
            // Then we can query the scan code of one or more
            // keys at a time
            const Uint8* state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_RIGHT]){
                std::cout << "right arrow key is pressed\n";
            }
        }

        glClearColor(1.0f,0.0f,0.0f,1.0f);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }
    
    
    // Terminating SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

