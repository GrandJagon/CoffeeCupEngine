#pragma once

#include <queue>
#include <memory>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "../utils/utilities.h"
#include "event.h"
#include "eventHandler.h"

typedef int EventType;
typedef std::vector<EventHandler*> SingleEventHandlers;

class EventManager
{
    private:
        std::queue<std::shared_ptr<Event>> _eventQueue;
        std::unordered_map<EventType, SingleEventHandlers> _handlers;
    
    public:
        static std::shared_ptr<EventManager> instance()
        {
            static std::shared_ptr<EventManager> _instance = std::make_shared<EventManager>();
            return _instance;
        }

        // Adds an event to the event queue
        void queue(std::shared_ptr<Event> event);
        
        // Executes event sychronously without queuing it 
        void process(std::shared_ptr<Event> event);

        // Called from 
        void subscribe(EventType type, EventHandler *handler);
        void unsubscribe(EventType type, EventHandler *handler);

        // Dispatches all events from the queue
        void dispatch();
};