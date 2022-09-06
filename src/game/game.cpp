#include "game.h"

// Input callbacks forward declaration
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


void Game::init(int width, int height, std::vector<int> validKeys)
{
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
    
    // Init game input valid keys
    _validKeys = validKeys;

    for(int i = 0; i < _validKeys.size(); i++)
    {
        // Each key of valid input initiated to false as non pressed
        _inputKeys[_validKeys[i]] = false; 
    }

    _window = Window();
    _window.init(_title, width, height, GameConstants::FULLSCREEN);
    _window.setKeyCallBack(&key_callback);

    // Initialize the renderer with the quad numbers specified in the rendering constants
    Renderer::init(RenderingConst::RENDERER_QUADS);
}

Game::~Game()
{
    _window.destroy();
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


// TO BE DELETD FROM HERE, WILL BE PASSED FROM OUTSIDE AS IT WILL DEPEND ON THE GAME
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(GameConstants::VALID_KEYS[key])
    {
       inputKey = key;
    }
}