#include "CCEnginePrecompiled.h"
#include "inputHandler.h"

#include "platform/SDL/SDLInputHandler.h"

std::shared_ptr<InputHandler> InputHandler::instance()
{
    // Only OpenGL is supported at the moment
    static std::shared_ptr<SDLInputHandler> instance = std::make_shared<SDlInputHandler>();
    return instance;
}
