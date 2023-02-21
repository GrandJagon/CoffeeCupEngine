#pragma once

#include <unordered_map>
#include <memory>

#include "command.h"
#include "bitmask.h"



class SDL_scancode;

class KeyboardInputContext : public InputContext
{
    
    private:
        Bitmask _keysCurrentFrame;
        Bitmask _keysLastFrame;

        std::unordered_map<SDL_Scancode, unsigned int> _inputToIndex;
        std::shared_ptr<Command> _commands[32];
        
        // Limited by the 32 bit size of bitmask
        unsigned int _maxCommands = 32;

        // Index keeping track of current command quantities
        unsigned int _lastCommandIndex = 0;

    public:
        void addCommand(std::shared_ptr<Command> command);

        void addCommands(std::vector<std::shared_ptr<Command>> commands);

        void removeCommand(SDL_Scancode input);      

        void pollEvents();
        
        // Execute each command sequentially
        void executeCommands();
};