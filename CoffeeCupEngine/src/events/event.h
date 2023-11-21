#pragma once

enum class EventType
{
    MouseEvent,
    KeyboardEvent,
    ControllerEvent,
    WindowEvent,
    ApplicationEvent
};

// Meant to be subclassed for input events and game events
struct Event
{
    EventType type;
    Event(EventType type) : type(type){};
};