#include "CCEnginePrecompiled.h"
#include "SDLInputHandler.h"

#include "events/eventManager.h"

#include "input/keyCodes.h"
#include "input/inputEvents.h"

#include <SDL2/SDL.h>

#include <chrono>


void SDLInputHandler::pollInputs()
{
        SDL_Event event;
        int x = 0;
        int y = 0;
        while(SDL_PollEvent(&event) > 0)
        {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    KeyboardEvent keyboardEvent(PRESSED, event.key.keysym.sym, event.timestamp);
                    EventManager::instance()->queue(keyboardEvent);
                    break;                
                case SDL_KEYUP:
                    KeyboardEvent keyboardEvent(RELEASED, event.key.keysym.sym, event.timestamp);
                    EventManager::instance()->queue(keyboardEvent);
                    break;   
                case SDL_MOUSEBUTTONDOWN:
                    MouseButtonEvent mouseEvent(PRESSED, event.button, event.x, event.y, event.timestamp);
                    EventManager::instance()->queue(mouseEvent);
                    break;
                case SDL_MOUSEBUTTONUP:
                    MouseButtonEvent mouseEvent(RELEASED, event.button, event.x, event.y, event.timestamp);
                    EventManager::instance()->queue(mouseEvent);
                    break;
                case SDL_MOUSEMOTION:
                    MouseMotionEvent mouseEvent(event.button, event.x, event.y, event.timestamp);
                    EventManager::instance()->queue(mouseEvent);
                    break;
                case SDL_MOUSEWHEEL:
                    MouseScrollEvent mouseEvent(event.x, event.y, event.timestamp);
                    EventManager::instance()->queue(mouseEvent);
                    break;
                default:
                    std::cout << "Input event not supported : " << event.type << std::endl;
                    break;
            }
        }
}

