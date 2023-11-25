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
    EventType _type;
    Event(EventType type) : _type(type){};

    EventType getType() { return this->_type; };
};