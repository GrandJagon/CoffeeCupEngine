#pragma once

#include "events/event.h"


enum INPUT_EVENT_CATEGORY {KEYBOARD_EVENT, MOUSE_EVENT, CONTROLLER_EVENT, WINDOW_EVENT};
enum ACTION {PRESSED, RELEASED};
enum CONTROLLER_BUTTON {BUTTON_ONE, BUTTON_TWO, BUTTON_THREE, BUTTON_FOUR, BUTTON_FIVE, BUTTON_SIX, BUTTON_SEVEN, BUTTON_EIGHT};

struct InputEvent : Event
{
    int timestamp;
    InputEvent(INPUT_EVENT_CATEGORY category, int time) : Event(INPUT_EVENT, category), timestamp(time) {};
};

struct KeyboardEvent : InputEvent
{
    ACTION action;
    int keycode;
    KeyboardEvent(ACTION actn, int key, int time) : InputEvent(KEYBOARD_EVENT, time), action(actn), keycode(key){};
};

struct MouseButtonEvent : InputEvent
{
    ACTION action;
    int button;
    int x;
    int y;
    MouseButtonEvent(ACTION actn, int buttn, int X, int Y, int time) : InputEvent(MOUSE_EVENT, time), action(actn), button(buttn), x(X), y(Y) {};
};

struct MouseMotionEvent : InputEvent
{
    INPUT_EVENT_CATEGORY category = MOUSE_EVENT;
    int x;
    int y;
    MouseMotionEvent(int X, int Y, int time) : InputEvent(MOUSE_EVENT, time), x(X), y(Y) {};
};

struct MouseScrollEvent : InputEvent
{
    int x;
    int y;
    MouseScrollEvent(int X, int Y, int time) : InputEvent(MOUSE_EVENT, time), x(X), y(Y) {};
};

struct ControllerButtonEvent : InputEvent
{
    CONTROLLER_BUTTON button;
    ControllerButtonEvent(CONTROLLER_BUTTON buttn, int time) : InputEvent(CONTROLLER_EVENT, time), button(buttn) {};
};

struct ControllerRangeEvent : InputEvent
{
    INPUT_EVENT_CATEGORY category = CONTROLLER_EVENT;
    int range;
    ControllerRangeEvent(int rng, int time):  InputEvent(CONTROLLER_EVENT, time), range(rng) {};
};

struct WindowCloseEvent : InputEvent
{
    WindowCloseEvent(int time) : InputEvent(WINDOW_EVENT, time) {};
};

struct WindowResizeEvent : InputEvent
{
    int width;
    int height;
    WindowResizeEvent(int wdth, int hght, int time) :  InputEvent(CONTROLLER_EVENT, time), width(wdth), height(hght) {};
};

struct WindowMoveEvent : InputEvent
{
    int x;
    int y;
    WindowMoveEvent(int X, int Y, int time):  InputEvent(CONTROLLER_EVENT, time), x(X), y(Y) {};
};

