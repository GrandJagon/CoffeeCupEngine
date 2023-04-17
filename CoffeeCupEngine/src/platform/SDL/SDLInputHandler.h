#pragma once

#include "input/inputHandler.h"

class SDLInputHandler : public InputHandler
{
    public:
        void pollInputs() override;
};