#pragma once


typedef enum EVENT_FAMILY {INPUT_EVENT, GAME_EVENT};

// Meant to be subclassed for input events and game events
struct Event
{
    EVENT_FAMILY family;
    int category;
    Event(EVENT_FAMILY fml, int ctgr) : family(fml), category(ctgr) {};
};