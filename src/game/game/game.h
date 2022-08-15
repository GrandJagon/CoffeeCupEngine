#pragma once
#include "../../utils/utilities.h"
#include "../gameObject/gameObject.h"
#include "../../rendering/renderer/Renderer.h"
#include "../../rendering/renderingConstants.h"

enum GameState
{
    running, 
    pause, 
    menu
}

class Game
{
    private:
        std::vector<GameObject> _gameObjects;
        bool _running = false;
        GameState _state;

    public:
        void init(int width, int height);
        void start();
        void processEvents();
        void update();
        void render();
        void pause();
        void shutDown();
}