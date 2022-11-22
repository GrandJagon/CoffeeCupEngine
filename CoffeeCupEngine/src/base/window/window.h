#pragma once

#include "../../utils/utilities.h"
#include "../../rendering/renderer/Renderer.h"

// Forward declared to avoir circular dependency, no method needed
class SpriteComponent;

class Window
{ 
    private:
        SDL_Window *_window;
        std::string _title;
        int _width;
        int _height;
        bool _fullScreen;

    public:
        void init(std::string title, int width, int height, bool fullScreen);
        void setKeyCallBack(void (*keyCallBack) (SDL_Window*, int, int, int, int));
        void endFrame();
        void resize(int width, int height);
        void destroy();
        void draw(SpriteComponent &sprite);
        void render();
        
        SDL_Window* getWindow() {return _window;};       
        int getWidth () {return _width;};
        int getHeight () {return _height;};
        int isFullScreen () {return _fullScreen;};
};