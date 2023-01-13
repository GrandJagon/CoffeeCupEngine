#pragma once

namespace Events
{
    enum Categories
    {
        WindowClose, WindowResize,
        MouseButtonClicked, MouseButtonReleased, MouseScrolled,
        KeyPressed, KeyReleased
    };
}

class Event 
{
    public:
        virtual ~Event() = default;
        int type;
        int category;
};