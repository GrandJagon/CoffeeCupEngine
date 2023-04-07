#include "CCEnginePrecompiled.h"
#include "SDLInputHandler.h"

#include "events/eventManager.h"

#include "input/keyCodes.h"
#include "input/inputEvents.h"

#include <SDL2/SDL.h>


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
                    KeyboardEvent keyboardEvent(PRESSED, event.key.keysym.sym);
                    EventManager::instance()->queue(keyboardEvent);
                    break;                
                case SDL_KEYUP:
                    KeyboardEvent keyboardEvent(RELEASED, event.key.keysym.sym);
                    EventManager::instance()->queue(keyboardEvent);
                    break;   

            }
        }

}

