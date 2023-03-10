#pragma once

#include "input/inputHandler.h"



class SDLInputHandler : InputHandler
{
    public:
        InputEvent pollInput() override;
};