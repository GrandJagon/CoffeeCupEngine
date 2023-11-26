#pragma once

#include <memory>
#include "inputEvents.h"

// Abstract class, generates engine event from OS raw events
class InputHandler
{
public:
    virtual ~InputHandler() = default;
    static std::shared_ptr<InputHandler> instance();

    // Poll all inputs
    virtual void pollInputs() = 0;
};