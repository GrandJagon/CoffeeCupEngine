#include "CCEnginePrecompiled.h"

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
}

void EventManager::unsubscribe(EventType type, EventHandler *handler)
{
    auto seh = _handlers.find(type);

    if(seh == _handlers.end())
    {
        std::cout << "Failed unsubscription attempt, not handlers for this event type" << std::endl;
        return;
    }

    auto hdlr = std::find((*seh).second.begin(), (*seh).second.end(), handler);

    if(hdlr == (*seh).second.end())
    {
        std::cout << "Failed unsubscription attempt, handler not found in handlers list" << std::endl;
        return;
    }

    int index = hdlr - (*seh).second.begin();

    (*seh).second.erase((*seh).second.begin() + index);

}

void EventManager::dispatch()
{
    for(int i = 0; i < _eventQueue.size(); i++)
    {
        std::shared_ptr<Event> event = _eventQueue.front();
        process(event);
        _eventQueue.pop();
    }
}