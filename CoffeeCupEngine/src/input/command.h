#pragma once

#include <SDL2/SDL_scancode.h>

// Each command should subclassed for a given game 
// Execute function has to be overriden
class Command
{
    protected:
        Command(void* input) : _input(input) {};
        void* _input; // can be a scancode for keyboard events
    
    public:
        virtual ~Command() {};

        // Object is optional an can be typecasted to any type as a command can have different target
        virtual void execute(void *object = nullptr) = 0;

        void* getInput() { return _input;};
};