#include <iostream>
#include <cstring>
#include "rendering/shaders/Shader.h"
#include "rendering/renderer/Renderer.h"
#include "../vendors/imgui/imgui.h"
#include "../vendors/imgui/imgui_impl_glfw_gl3.h"
#include "utils/utilities.h"
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

SDL_Window* window = nullptr;
SDL_GLContext openGlContext = nullptr;

bool sdlQuit = false; // for main loop

int main(void)
{   
    
    // SDL initialization
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {  
        std::cout << "SDL could not init video subsystem" << std::endl;
        return -1;

    };

    // Setting SDL openGL version to 4.5
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 5);
    
    // Deprecated features are not allowed
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // Enabling double buffering with buffer size of 24 bits
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);


    // Creating window
    window = SDL_CreateWindow("Title test", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);

    // Creating context
    openGlContext = SDL_GL_CreateContext(window);

    if(openGlContext == nullptr)
    {
        std::cout << "OpenGL context could not be created" << std::endl;
        return -1;
    }


    // Sets the appropriate blending function for displaying
    GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        throw std::runtime_error("Error while initializing glew");
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    Renderer::init();
    
    // Projection matrix
    glm::mat4 proj = glm::ortho(0.0f, (float) WINDOW_WIDTH, 0.0f, (float) WINDOW_HEIGHT, -1.0f, 1.0f);

    // Translation vector to be combined with identity matrix
    glm::vec3 translation = glm::vec3(0.0f,0.0f,0.0f);


    /* Loop until the user closes the window */
    while (!sdlQuit)
    {   

        // SDL input handling
        SDL_Event e;

        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_QUIT)
            {
                std::cout << "Application temrinated by user" << std::endl;
                sdlQuit = true;
            }
        }
        
        // Translation moves camera such as negative -> left,  positive -> right
        glm::mat4 view = glm::translate(glm::mat4(1.0f), translation);

        glm::mat4 model = glm::mat4(1.0f);
    
        // For MVP multiplication order is reversed in openGL
        glm::mat4 mvp = proj * view * model;

        GlCall(glClear(GL_COLOR_BUFFER_BIT));

        //Sets MVP
        Renderer::setMVP(mvp);
        

        // Draw
        /*for(int i = 0; i < 20; i++)
        {    
            for(int j = 0; j < 20; j++)
            {
                // Color call
                Renderer::draw({ 0.0f + (i * 100), 0.0f + (j * 100) }, { 100.0f, 100.0f }, {0.034f, 0.139f, 0.028f, 1.0f});
            }
        }
        

        // Texture call
        Renderer::draw({ 50.0f ,50.0f }, { 100.0f, 100.0f }, 1.0f);

        Renderer::render();

        Renderer::endFrame(); */
        
        
        // Swaps buffer
        SDL_GL_SwapWindow(window);

     
    }
    
    // Disposing of ImGui objects
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    
    // Terminating SDL
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

