#pragma once

#include "../utils/utilities.h"

#include <memory>

class Window
{ 
    protected:
        std::string _title;
        int _width;
        int _height;
        bool _fullScreen;

        int getWidth () {return _width;};
        int getHeight () {return _height;};
        int isFullScreen () {return _fullScreen;};

    public:
        virtual ~Window() = default;
        virtual void init(std::string title, int width, int height, bool fullScreen) = 0;
        virtual void endFrame() = 0;
        virtual void resize(int width, int height) = 0;
        virtual void destroy() = 0;
        virtual void render() {};
        
        // Returns the proper window given the API
        static std::shared_ptr<Window> create();


};