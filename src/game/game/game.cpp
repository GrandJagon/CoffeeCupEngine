#include "game.h"

void Game::init(int width, int height)
{
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