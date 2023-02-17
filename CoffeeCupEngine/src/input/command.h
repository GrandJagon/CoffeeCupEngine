#pragma once

#include <SDL2/SDL_events.h>

// Each command should subclassed for a given game 
// Execute function has to be overriden
class Command
{
    protected:
        Command(SDL_Event event) : _event(event) {};
        SDL_Event _event;
    
    public:
        virtual ~Command() {};

        // Object is optional an can be typecasted to any type as a command can have different target
        virtual void execute(void *object = nullptr) = 0;
};