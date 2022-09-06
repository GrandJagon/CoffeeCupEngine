#pragma once
#include "../utils/utilities.h"
#include "../base/window/window.h"
#include "gameObject/gameObject.h"
#include "gameConstants.h"
#include "../rendering/renderer/Renderer.h"
#include "../rendering/renderingConstants.h"


enum GameState
{
    running, 
    pause, 
    menu
};

std::vector<int> defaultValidKeys = {GLFW_KEY_SPACE, GLFW_KEY_ESCAPE, GLFW_KEY_RIGHT, GLFW_KEY_LEFT, GLFW_KEY_UP, GLFW_KEY_DOWN};

// BEST WAY BEFORE FINDIND BETTER
int inputKey;

class Game
{
    private:
        // Core data members
        std::string _title;
        Window _window;
        GameState _state;

        // Input data members
        std::vector<int> _validKeys;
        std::map<int, bool> _inputKeys;
        
        // Ingame data members
        std::vector<GameObject> _gameObjects;
       
    public:
        Game(std::string title) : _title(title) {};
        ~Game();
        void init(int width, int height, std::vector<int> validKeys = defaultValidKeys);

        // To be used later when instantiating game class according to desired game
        void setValidKeys(std::vector<int> validKeys) {_validKeys = validKeys;};
        
        // Need to find a way to pass desired events and the related way to process them
        void setInputs();
        
        void start();

        // Will probably need to be overriden as events will be different given the game
        void processEvents();
        void update();
        void render();
        void pause();
        void shutDown();

        // Getters
        Window getWindow() {return _window;};
};