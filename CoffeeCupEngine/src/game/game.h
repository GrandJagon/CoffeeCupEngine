#pragma once

#include "gameConstants.h"

#include "../utils/utilities.h"
#include "../base/window/window.h"

#include "../rendering/renderer/Renderer.h"
#include "../rendering/textureManager/textureManager.h"
#include "../rendering/renderingConstants.h"

#include "input/inputHandler.h"
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
        // Singeton as it make global acces to some below data members easier t
        static Game* _instance;

        // Core data members
        std::string _title;
        GameState _state;
        float _deltaTime;
        SceneManager _sceneManager;

        // Globally accessible core data members
        Window _window;
        InputHandler _inputHandler;
        TextureManager _textureManager;
        
    
    public:
        Game();
        ~Game();

        void init(title, int width, int height);

        // To be used later when instantiating game class according to desired game
        void setValidKeys(std::vector<Key>);
        
        void start();

        void update(float dt);

        // Updates to be made once we sure the first ones are done
        void lateUpdate();
        void render();
        void pause();
        void shutDown();

        // Singleton instance getter
        static Game* instance() {
            if(_instance == NULL) _instance = new Game();
            return *_instance;
        };
        
        // Getters
        Window getWindow() {return _window;};
        InputHandler getInputHandler() {return _inputHandler;};
        TextureManager getTextureManager() {return _textureManager;};


    
};