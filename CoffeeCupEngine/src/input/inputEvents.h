#pragma once

#include "events/event.h"

enum class InputKeyAction
{
    KeyDown,
    KeyUp
};

struct KeyboardEvent : public Event
{
    InputKeyAction action;
    int keycode;
    int time;
    KeyboardEvent(InputKeyAction action, int key, int time) : Event(EventType::KeyboardEvent), action(action), keycode(key){};
};

struct MouseEvent : public Event
{
    int time;
    MouseEvent(int time) : Event(EventType::MouseEvent), time(time){};
};

struct MouseButtonEvent : public MouseEvent
{
    InputKeyAction action;
    int button;
    int x;
    int y;
    MouseButtonEvent(InputKeyAction action, int buttn, int X, int Y, int time) : MouseEvent(time), button(buttn), x(X), y(Y){};
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
    ControllerRangeEvent(int rng, int time) : ControllerEvent(time), range(rng){};
};

struct WindowEvent : Event
{
    int time;
    WindowEvent(int time) : Event(EventType::WindowEvent), time(time){};
};

struct WindowCloseEvent : WindowEvent
{
    WindowCloseEvent(int time) : WindowEvent(time){};
};

struct WindowResizeEvent : WindowEvent
{
    int width;
    int height;
    WindowResizeEvent(int wdth, int hght, int time) : WindowEvent(time), width(wdth), height(hght){};
};

struct WindowMoveEvent : WindowEvent
{
    int x;
    int y;
    WindowMoveEvent(int X, int Y, int time) : WindowEvent(time), x(X), y(Y){};
};
