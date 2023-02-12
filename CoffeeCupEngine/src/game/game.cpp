#include "game.h"

void Game::init(std::string title, int width, int height)
{
    std::cout << "__________INIT GAME______________ " << std::endl;
    _title = title;    

    //std::cout << glGetString(GL_VERSION) << std::endl;

    _window = Window::create();
    _window->init(_title, width, height, GameConstants::FULLSCREEN);
    //_window.setKeyCallBack(&_inputHandler.update);

    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        throw std::runtime_error("Error while initializing glew");
    }

    // Initialize global subsystems
    _renderer = Renderer::instance();
    _renderer->init();
    
    _textureManager = TextureManager::instance();
    _textureManager->init();

    std::cout << "_________________________GAME INITIATED_________________" << std::endl;
}

Game::~Game()
{
    _window->destroy();
}

void Game::start()
{
    _state = GameState::running;
}

void Game::processEvents()
{
    
}

void Game::update(float dt)
{

}

void Game::lateUpdate()
{

}

void Game::render()
{

}

void Game::run()
{

}

void Game::pause()
{
    _state = GameState::pause;
}

void Game::shutDown()
{
    
}
