#pragma once

#include <queue>
#include <memory>
#include <unordered_map>
#include <vector>

#include "event.h"
#include "eventHandler.h"

typedef int EventType
typedef std::vector<std::shared_ptr<EventHandler>> handlerList

class EventManager
{
    private:
        std::queue<std::shared_ptr<Event>> _eventQueue;
        std::unordered_map<EventType, handlerList> _handlers;
    
    public:

        // Adds an event to the event queue
        void queue(std::shared_ptr<Event> event);
        
        // Executes event sychronously without queuing it 
        void process(std::shared_ptr<Event> event);

        // Called from 
        void subscribe();
        void unsubscribe();

        // Dispatches all events from the queue
        void dispatch();
}