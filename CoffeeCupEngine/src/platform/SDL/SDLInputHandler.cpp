#include "CCEnginePrecompiled.h"
#include "SDLInputHandler.h"

#include "events/eventManager.h"

#include "input/keyCodes.h"
#include "input/inputEvents.h"

#include <SDL2/SDL.h>

#include <chrono>
#include <memory>

void SDLInputHandler::pollInputs()
{
    SDL_Event event;
    while (SDL_PollEvent(&event) > 0)
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
        {
            auto keyboardEvent = std::make_shared<KeyboardEvent>(PRESSED, event.key.keysym.sym, event.key.timestamp);
            EventManager::instance()->queue(keyboardEvent);
            break;
        }
        case SDL_KEYUP:
        {
            auto keyboardEvent = std::make_shared<KeyboardEvent>(RELEASED, event.key.keysym.sym, event.key.timestamp);
            EventManager::instance()->queue(keyboardEvent);
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            auto mouseEvent = std::make_shared<MouseButtonEvent>(PRESSED, event.button.button, event.button.x, event.button.y, event.button.timestamp);
            EventManager::instance()->queue(mouseEvent);
            break;
        }
        case SDL_MOUSEBUTTONUP:
        {
            auto mouseEvent = std::make_shared<MouseButtonEvent>(RELEASED, event.button.button, event.button.x, event.button.y, event.button.timestamp);
            EventManager::instance()->queue(mouseEvent);
            break;
        }
        case SDL_MOUSEMOTION:
        {
            auto mouseEvent = std::make_shared<MouseMotionEvent>(event.motion.x, event.motion.y, event.motion.timestamp);
            EventManager::instance()->queue(mouseEvent);
            break;
        }
        case SDL_MOUSEWHEEL:
        {
            auto mouseEvent = std::make_shared<MouseScrollEvent>(event.wheel.x, event.wheel.y, event.wheel.timestamp);
            EventManager::instance()->queue(mouseEvent);
            break;
        }
        default:
            std::cout << "Input event not supported : " << event.type << std::endl;
            break;
        }
    }
}
