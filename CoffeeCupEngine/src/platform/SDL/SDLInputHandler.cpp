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
            printf("Creating Keyboard KeyDown event from SDLEvent\n");
            auto keyboardEvent = std::make_shared<KeyboardEvent>(InputKeyAction::KeyDown, event.key.keysym.sym, event.key.timestamp);
            EventManager::instance()->queue(keyboardEvent);
            break;
        }
        case SDL_KEYUP:
        {
            printf("Creating Keyboard KeyUp event from SDLEvent\n");
            auto keyboardEvent = std::make_shared<KeyboardEvent>(InputKeyAction::KeyUp, event.key.keysym.sym, event.key.timestamp);
            EventManager::instance()->queue(keyboardEvent);
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        {
            printf("Creating Mouse KeyDown event from SDLEvent\n");
            auto mouseEvent = std::make_shared<MouseButtonEvent>(InputKeyAction::KeyDown, event.button.button, event.button.x, event.button.y, event.button.timestamp);
            EventManager::instance()->queue(mouseEvent);
            break;
        }
        case SDL_MOUSEBUTTONUP:
        {
            printf("Creating Mouse KeyUp event from SDLEvent\n");
            auto mouseEvent = std::make_shared<MouseButtonEvent>(InputKeyAction::KeyUp, event.button.button, event.button.x, event.button.y, event.button.timestamp);
            EventManager::instance()->queue(mouseEvent);
            break;
        }
        case SDL_MOUSEMOTION:
        {
            printf("Creating Mouse motion event from SDLEvent\n");
            auto mouseEvent = std::make_shared<MouseMotionEvent>(event.motion.x, event.motion.y, event.motion.timestamp);
            EventManager::instance()->queue(mouseEvent);
            break;
        }
        case SDL_MOUSEWHEEL:
        {
            printf("Creating Mouse scroll event from SDLEvent\n");
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
