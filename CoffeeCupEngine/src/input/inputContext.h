#pragma once

#include <vector>
#include <memory>

#include "command.h"
#include "bitmask.h"

struct InputEvent
{
    SDL_EventType type;

    // Extra data according to the type
    union {
        SDL_KeyboardEvent key;
        SDL_MouseButtonEvent button;
        SDL_MouseMotionEvent motion;
    };
};

class InputContext
{
    protected:
        Bitmask _keysCurrentFrame;
        Bitmask _keysLastFrame;

        std::vector<Command> _commands;
        
        // Limited by the 32 bit size of bitmask
        unsigned int _maxCommands = 32;

    public:
        virtual ~InputContext() {};

        void addCommand(Command &command);

        void addCommands(std::vector<Command> &commands);
        
        // Poll event and check/execute each command sequentially
        virtual void upate() = 0;



    
};