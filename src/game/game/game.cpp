#include "game.h"

// Input callbacks forward declaration
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


void Game::init(int width, int height)
{
    // Init GLFW and window object
    if (!glfwInit())
        throw std::runtime_error("Error while initializing GLFW library.");
    
    _window = Window();
    _window.init(_title, width, height, GameConstants::FULLSCREEN);
    _window.setKeyCallBack(&key_callback);

    // Initialize the renderer with the quad numbers specified in the rendering constants
    Renderer::init(RenderingConst::RENDERER_QUADS);

}

void Game::start()
{
    _state = GameState::running;
}

void Game::processEvents()
{
    
}

void Game::pause()
{
    _state = GameState::pause;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(GameConstants::VALID_KEYS[key])
    {
       inputKey = key;
    }
}