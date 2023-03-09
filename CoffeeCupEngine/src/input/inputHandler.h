#pragma once

#include <memory>
#include "inputEvents.h"

class InputHandler
{
    public:
        virtual ~InputHandler() = default;
        static std::shared_ptr<InputHandler> instance();

        void pollInputs();
};