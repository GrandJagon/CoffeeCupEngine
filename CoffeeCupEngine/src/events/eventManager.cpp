#include "eventManager.h"


void EventManager::queue(std::shared_ptr<Event> event)
{
    _eventQueue.push(event);
}

void EventManager::process(std::shared_ptr<Event> event)
{
    SingleEventHandlers handlers = _handlers.at(event->type);

    for(auto handler = handlers.begin(); handler != handlers.end(); ++handler)
    {
        (*handler)->onEvent(event);
    }
}

void EventManager::subscribe(EventType type, EventHandler *handler)
{
    auto seh = _handlers.find(type);

    if(seh == _handlers.end())
    {
        std::vector<EventHandler*> vec;
        vec.push_back(handler);
        _handlers[type] = vec;
        return;
    }

    (*seh).second.push_back(handler);
    return;
}