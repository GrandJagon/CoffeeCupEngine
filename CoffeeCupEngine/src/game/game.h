#pragma once

#include "gameConstants.h"

#include "scenes/sceneManager.h"

#include "../utils/utilities.h"

#include "../rendering/window.h"
#include "../rendering/renderer.h"
#include "../rendering/textureManager.h"
#include "../rendering/renderingConstants.h"

#include "../input/inputManager.h"


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
    protected:
        // Core data members
        std::string _title;
        GameState _state;
        float _deltaTime;

        std::shared_ptr<Window> _window;

        // Subsystems
        std::shared_ptr<Renderer> _renderer;
        std::shared_ptr<TextureManager> _textureManager;
        std::shared_ptr<InputManager> _inputManager;

        SceneManager _sceneManager;
        
    public:
        Game() {};
        virtual ~Game();

        virtual void init(std::string title, int width, int height);
        
        virtual void start();
        
        // Main game loop
        virtual void run();

        virtual void update(float dt);

        virtual void processEvents();

        // Updates to be made once we sure the first ones are done
        virtual void lateUpdate();
        virtual void render();
        virtual void pause();
        virtual void shutDown();
};