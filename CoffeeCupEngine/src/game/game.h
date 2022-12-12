#pragma once

#include "gameConstants.h"

#include "../utils/utilities.h"
#include "../base/window/window.h"

#include "../rendering/renderer/Renderer.h"
#include "../rendering/textureManager/textureManager.h"
#include "../rendering/renderingConstants.h"

#include "input/inputManager.h"
#include "scenes/sceneManager.h"

// Defined in inputHandler.h
struct Key;

enum GameState
{
    running, 
    pause, 
    menu
};

class Game
{     
    private:
        // Core data members
        std::string _title;
        GameState _state;
        float _deltaTime;
        SceneManager _sceneManager;

        // Singletons core members
        // Listed here for clarity but accessible globally through Class:insance()
        Window *_window;
        InputManager *_inputHandler;
        TextureManager *_textureManager;
        Renderer *_renderer;
        
    
    public:
        Game() {};
        ~Game();

        // Singleton instance getter
        static Game* instance() {
            static Game instance;
            return &instance;
        };

        void init(std::string title, int width, int height);

        // To be used later when instantiating game class according to desired game
        void setValidKeys(std::vector<Key>);
        
        void start();

        void update(float dt);

        void processEvents();

        // Updates to be made once we sure the first ones are done
        void lateUpdate();
        void render();
        void pause();
        void shutDown();
};