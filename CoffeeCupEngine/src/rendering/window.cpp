#include "CCEnginePrecompiled.h"
#include "window.h"
#include "platform/SDL/SDLWindow.h"

std::unique_ptr<Window> Window::create()
{
    // Only supports SDL at the moment
    return std::make_unique<SDLWindow>();
}