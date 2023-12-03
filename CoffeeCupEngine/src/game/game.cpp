#include "CCEnginePrecompiled.h"

#include <GL/glew.h>

#include "game.h"
#include "rendering/window.h"
#include "rendering/camera.h"
#include "rendering/renderer.h"
#include "rendering/textureManager.h"
#include "input/inputManager.h"
#include "scenes/sceneManager.h"
#include "rendering/renderingConstants.h"
#include "gameConstants.h"

void Game::init(std::string title, int width, int height)
{
    std::cout << "__________INIT GAME______________ " << std::endl;
    _title = title;

    // std::cout << glGetString(GL_VERSION) << std::endl;

    _window = Window::create();
    _window->init(_title, width, height, GameConstants::FULLSCREEN);

    _camera = std::make_unique<Camera>(0, width, 0, height);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("Error while initializing glew");
    }

    // Initialize global subsystems
    _renderer = Renderer::instance();
    _renderer->init();

    _textureManager = TextureManager::instance();
    _textureManager->init();

    _inputHandler = InputHandler::instance();
    _inputManager = InputManager::instance();
    _eventManager = EventManager::instance();

    // Make required subscriptions between globan subsystems
    _eventManager->subscribe(EventType::KeyboardEvent, _inputManager);
    _eventManager->subscribe(EventType::MouseEvent, _inputManager);
    _eventManager->subscribe(EventType::ControllerEvent, _inputManager);
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
