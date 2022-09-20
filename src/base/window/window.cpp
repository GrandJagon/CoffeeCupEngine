#include "window.h"

void Window::init(std::string title, int width, int height, bool fullScreen)
{   
    _title = title;
    _width = width;
    _height = height;
    _fullScreen = fullScreen;
    
    if(_fullScreen)
    {
        _window = glfwCreateWindow(_width, _height, _title.c_str(), glfwGetPrimaryMonitor(), NULL);
    } else {
        _window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
    }

    if (!_window)
    {
        glfwTerminate();
        throw std::runtime_error("Error while initializing window object");
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(_window);
  
}

void Window::setKeyCallBack(void (*callback) (GLFWwindow*, int, int, int, int))
{
    glfwSetKeyCallback(_window, *callback);
}

void Window::draw(SpriteComponent &sprite)
{
    // Call renderer to draw texture here
}

void Window::endFrame()
{
    if(glfwWindowShouldClose(_window))
    {
        this->destroy();
    }

    glfwSwapBuffers(_window);

    glfwPollEvents();
}

void Window::resize(int width, int height)
{
    glfwSetWindowSize(_window, width, height);
}

void Window::destroy()
{
    glfwTerminate();
    glfwDestroyWindow(_window);
}