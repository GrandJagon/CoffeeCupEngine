#pragma once
#include "../../utils/utilities.h"


class Window
{ 
    private:
        GLFWwindow* _window;
        std::string _title;
        int _width;
        int _height;
        bool _fullScreen;

    public:
        void init(std::string title, int width, int height, bool fullScreen);
        void setKeyCallBack(void (*keyCallBack) (GLFWwindow*, int, int, int, int));
        void update();
        void resize(int width, int height);
        void destroy();

        
        GLFWwindow* getWindow() {return _window;};       
        int getWidth () {return _width;};
        int getHeight () {return _height;};
        int isFullScreen () {return _fullScreen;};
};