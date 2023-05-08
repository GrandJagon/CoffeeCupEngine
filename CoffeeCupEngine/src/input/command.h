#pragma once

#include <iostream>

#include "inputEvents.h"

// Each command should subclassed for a given game 
// Execute and check function has to be overriden
class Command
{
    protected:
        void *_input; // key code or range
        
    
    public:
        virtual ~Command() {};
        
        // Check for input event if command needs to be triggered or not
        virtual void check(InputEvent inputEvent) = 0;
        
        // Object is optional an can be typecasted to any type as a command can have different target
        virtual void execute(void *object = nullptr) = 0;

        // Maps to new input in case user makes new settings
        void setInput(void *input) { _input = input;};

        void *getInput() { return _input;};

        template <typename T>
        static std::shared_ptr<Command> createCommand() { return std::make_shared<T>(); };
};