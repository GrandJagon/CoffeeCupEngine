#pragma once

#include "scene.h"
#include "../../base/window/window.h"

class SceneManager
{
    private:
        std::vector<Scene> _scenes;
        Scene _currentScene;
    
    public:
        void addScene(Scene scene);
        
        void nextScene();
        
        // Passing call to current scene
        void update();
        void lateUpdate();
        void draw(Window &window);
}