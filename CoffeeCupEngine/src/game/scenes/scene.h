#pragma once

class Window;

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