#include "game.h"

void Game::init(std::string title, int width, int height)
{
    std::cout << "__________INIT GAME______________ " << std::endl;
    _title = title;    

    // Sets the appropriate blending function for displaying
    GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    //std::cout << glGetString(GL_VERSION) << std::endl;

    _window = Window::instance();
    _window->init(_title, width, height, GameConstants::FULLSCREEN);
    //_window.setKeyCallBack(&_inputHandler.update);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        throw std::runtime_error("Error while initializing glew");
    }

    // Initialize global subsystems
    _renderer = Renderer::instance();
    _renderer->init();

    std::cout << "_________________________GAME INITIATED_________________" << std::endl;
}

Game::~Game()
{
    _window->destroy();
}

void Game::setValidKeys(std::vector<Key> keys)
{
    
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
