#pragma once

#include <unordered_map>
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