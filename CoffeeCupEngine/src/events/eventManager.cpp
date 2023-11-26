#include "CCEnginePrecompiled.h"

#include "eventManager.h"

void EventManager::queue(std::shared_ptr<Event> event)
{
    _eventQueue.push(event);
}

void EventManager::process(std::shared_ptr<Event> event)
{
    SingleEventHandlers handlers = _handlers.at(event->getType());

    for (auto handler = handlers.begin(); handler != handlers.end(); ++handler)
    {
        (*handler)->onEvent(event);
    }
}

void EventManager::subscribe(EventType type, std::shared_ptr<EventHandler> handler)
{
    printf("%i is being subscribe to.", type);

    auto seh = _handlers.find(type);

    if (seh == _handlers.end())
    {
        _handlers[type].push_back(handler);
        return;
    }

    (*seh).second.push_back(handler);
}

void EventManager::unsubscribe(EventType type, std::shared_ptr<EventHandler> handler)
{
    auto seh = _handlers.find(type);

    if (seh == _handlers.end())
    {
        std::cout << "Failed unsubscription attempt, not handlers for this event type" << std::endl;
        return;
    }

    auto hdlr = std::find((*seh).second.begin(), (*seh).second.end(), handler);

    if (hdlr == (*seh).second.end())
    {
        std::cout << "Failed unsubscription attempt, handler not found in handlers list" << std::endl;
        return;
    }

    int index = hdlr - (*seh).second.begin();

    (*seh).second.erase((*seh).second.begin() + index);
}

void EventManager::dispatch()
{
    printf("%i", _handlers.size());

    if (_eventQueue.size() > 0)
    {
        printf("Event manager starting to dipatch events : %i events to dispatch\n", _eventQueue.size());
    }

    for (int i = 0; i < _eventQueue.size(); i++)
    {
        std::shared_ptr<Event> event = _eventQueue.front();
        process(event);
        _eventQueue.pop();
    }
}