#pragma once
#include "../../utils/utilities.h"
#include "../../base/window/window.h"
#include "../gameObject/gameObject.h"
#include "../gameConstants.h"
#include "../../rendering/renderer/Renderer.h"
#include "../../rendering/renderingConstants.h"


enum GameState
{
    running, 
    pause, 
    menu
};

// BEST WAY BEFORE FINDIND BETTER
int inputKey;

class Game
{
    private:
        std::string _title;
        Window _window;
        GameObject _player;
        std::vector<GameObject> _gameObjects;
        GameState _state;

    public:
        Game(std::string title) : _title(title) {};
        ~Game();
        void init(int width, int height);
        void start();
        void processEvents();
        void update();
        void render();
        void pause();
        void shutDown();
};