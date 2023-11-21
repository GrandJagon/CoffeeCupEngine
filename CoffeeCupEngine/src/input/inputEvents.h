#pragma once

#include "events/event.h"

struct KeyboardEvent : public Event
{
    int keycode;
    int time;
    KeyboardEvent(int key, int time) : Event(EventType::KeyboardEvent), keycode(key){};
};

struct MouseEvent : public Event
{
    int time;
    MouseEvent(int time) : Event(EventType::MouseEvent), time(time){};
};

struct MouseButtonEvent : public MouseEvent
{
    int button;
    int x;
    int y;
    MouseButtonEvent(int buttn, int X, int Y, int time) : MouseEvent(time), button(buttn), x(X), y(Y){};
};

struct MouseMotionEvent : public MouseEvent
{
    int x;
    int y;
    MouseMotionEvent(int X, int Y, int time) : MouseEvent(time), x(X), y(Y){};
};

struct MouseScrollEvent : public MouseEvent
{
    int x;
    int y;
    MouseScrollEvent(int X, int Y, int time) : MouseEvent(time), x(X), y(Y){};
};

struct ControllerEvent : public Event
{
    int time;
    ControllerEvent(int time) : Event(EventType::ControllerEvent), time(time){};
};

struct ControllerButtonEvent : public ControllerEvent
{
    int button;
    ControllerButtonEvent(int button, int time) : ControllerEvent(time), button(button){};
};

struct ControllerRangeEvent : public ControllerEvent
{
    int range;
    ControllerRangeEvent(int rng, int time) : Event(time), range(rng){};
};

struct WindowCloseEvent : Event
{
    WindowCloseEvent(int time) : Event(EventType::WindowEvent, time){};
};

struct WindowResizeEvent : Event
{
    int width;
    int height;
    WindowResizeEvent(int wdth, int hght, int time) : Event(EventType::WindowEvent, time), width(wdth), height(hght){};
};

struct WindowMoveEvent : Event
{
    int x;
    int y;
    WindowMoveEvent(int X, int Y, int time) : Event(EventType::WindowEvent, time), x(X), y(Y){};
};
