#include "window.h"
#include "../../platform/SDL/SDLWindow.h"

std::shared_ptr<Window> Window::create()
{
    // Only supports SDL at the moment
    return std::make_shared<SDLWindow>();
}