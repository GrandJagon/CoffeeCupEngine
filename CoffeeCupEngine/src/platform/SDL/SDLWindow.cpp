#include "CCEnginePrecompiled.h"
#include "SDLWindow.h"
#include <SDL2/SDL.h>

void SDLWindow::init(std::string title, int width, int height, bool fullScreen)
{   
    _title = title;
    _width = width;
    _height = height;
    _fullScreen = fullScreen;
    
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
    _window = SDL_CreateWindow(_title.c_str(), 0, 0, _width, _height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    // Creating context
    SDL_GLContext openGlContext = SDL_GL_CreateContext(_window);

    if(openGlContext == nullptr)
    {
        throw std::runtime_error("OpenGL context could not be created");
    }

    if(_fullScreen)
    {
        SDL_SetWindowFullscreen(_window, SDL_FALSE);
    }
}


void SDLWindow::endFrame()
{
    
    // Swaps buffer
    SDL_GL_SwapWindow(_window);
}

void SDLWindow::resize(int width, int height)
{
    //glfwSetWindowSize(_window, width, height);
}

void SDLWindow::destroy()
{
    // Terminating SDL
    SDL_DestroyWindow(_window);
    SDL_Quit();
}