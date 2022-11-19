#pragma once

#include "../../base/window/window.h"

class Scene
{
    private:
    
    public :
        virtual void onCreate() = 0; 
        virtual void onUpdate(float dt) {};
        virtual void onLateUpdate() {};
        virtual void onDestroy() {};

        virtual void activate() {};
        virtual void deactivate() {};

        virtual void draw(Window &window) {};
        virtual void processEvents() {};
};