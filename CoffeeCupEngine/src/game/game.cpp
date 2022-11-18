#include "game.h"

void Game::init(std::string title, int width, int height)
{
    _title = title;
    
    // Init GLFW and window object
    if (!glfwInit())
        throw std::runtime_error("Error while initializing GLFW library.");
    
    
    // Sets the appropriate blending function for displaying
    GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        throw std::runtime_error("Error while initializing glew");
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    _window = Window();
    _window.init(_title, width, height, GameConstants::FULLSCREEN);
    _window.setKeyCallBack(&_inputHandler.update);

    // Initialize the renderer with the quad numbers specified in the rendering constants
    Renderer::init();
}

Game::~Game()
{
    _window.destroy();
}

void setValidKeys(std::vector<Key> keys)
{
    _inputHandler.setValidKeys(keys);
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
