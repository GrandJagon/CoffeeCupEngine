#pragma once


#include <iostream>

// Each command should subclassed for a given game 
// Execute function has to be overriden
class Command
{
    protected:
        Command(void *input, std::string name) : _input(input), _name(name) {};
        void *_input; // key code or range
        std::string _name; // command string name for mapping to input at creation
    
    public:
        virtual ~Command() {};

        // Object is optional an can be typecasted to any type as a command can have different target
        virtual void execute(void *object = nullptr) = 0;

        // Maps to new input in case user makes new settings
        void setInput(void *input) { _input = input; };

        void *getInput() { return _input;};
};