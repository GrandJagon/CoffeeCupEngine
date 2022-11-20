#pragma once

#include <memory>

#include "scene.h"
#include "../../base/window/window.h"

class SceneManager
{
    private:
        std::vector<std::shared_ptr<Scene>> _scenes;
        std::shared_ptr<Scene> _currentScene;
    
    public:
        void addScene(std::shared_ptr<Scene> scene);
        
        void nextScene();
        
        // Passing call to current scene
        void update();
        void lateUpdate();
        void draw(Window &window);
};