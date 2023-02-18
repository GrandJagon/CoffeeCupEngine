#pragma once

#include <memory>
#include <iostream>



class Window;
class Camera;
class Renderer;
class TextureManager;
class InputManager;
class SceneManager;


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

        std::unique_ptr<Window> _window;
        std::unique_ptr<Camera> _camera;

        // Subsystems
        std::shared_ptr<Renderer> _renderer;
        std::shared_ptr<TextureManager> _textureManager;
        std::shared_ptr<InputManager> _inputManager;

        std::unique_ptr<SceneManager> _sceneManager;
        
    public:
        Game() {std::cout << "gam create" << std::endl;};
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

        std::unique_ptr<Camera>& getCamera() { return _camera;};

};