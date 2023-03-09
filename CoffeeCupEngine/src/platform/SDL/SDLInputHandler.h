#pragma once

#include "input/inputHandler.h"


class SDLInputHandler : InputHandler
{
    public:

        void pollInputs() override;
};