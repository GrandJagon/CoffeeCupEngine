#pragma once

#include <memory>

#include "event.h"

class EventHandler
{
    public:
        virtual void onEvent(const std::shared_ptr<Event>) = 0;
};