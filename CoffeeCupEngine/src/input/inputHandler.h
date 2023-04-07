#pragma once

#include <memory>
#include "inputEvents.h"

// Abstract class, generates engine event from OS raw events
class InputHandler
{
    public:
        virtual ~InputHandler() = default;
        static std::shared_ptr<InputHandler> instance();
        
        // Poll an input from the os raw events queue
        InputEvent pollInput();

        // Poll all inputs 
        void pollInputs();
};