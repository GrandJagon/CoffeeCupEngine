#pragma once

#include "keyCodes.h"

typedef enum INPUT_EVENT_CATEGORY {KEYBOARD_EVENT, MOUSE_EVENT, CONTROLLER_EVENT};
typedef enum ACTION {PRESSED, RELEASED};
typedef enum MOUSE_BUTTON {MOUSE_LEFT, MOUSE_MIDDLE, MOUSE_RIGHT};

struct InputEvent
{
    INPUT_EVENT_CATEGORY category;
    int timestamp;
}

struct KeyboardEvent : InputEvent
{
    INPUT_EVENT_CATEGORY category = KEYBOARD_EVENT;
    ACTION action;
    int keycode;
    KeyboardEvent(ACTION actn, int key) : action(actn), keycode(key) {};
};

struct MouseButtonEvent : InputEvent
{
    INPUT_EVENT_CATEGORY category = MOUSE_EVENT;
    MOUSE_BUTTON button;
    int x;
    int y;
    MouseButtonEvent(MOUSE_BUTTON buttn, int X, int Y) : button(buttn), x(X), y(Y) {};
};

struct MouseMotionEvent : InputEvent
{
    INPUT_EVENT_CATEGORY category = MOUSE_EVENT;
    int x;
    int y;
    MouseMotionEvent(int X, int Y) : x(X), y(Y) {};
};

struct MouseScrollEvent : InputEvent
{
    INPUT_EVENT_CATEGORY category = MOUSE_EVENT;
    int x;
    int y;
    MouseScrollEvent(int X, int Y) : x(X), y(Y) {};
};