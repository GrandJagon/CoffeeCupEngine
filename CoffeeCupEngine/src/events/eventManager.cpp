#include "CCEnginePrecompiled.h"

#include "eventManager.h"

void EventManager::queue(std::shared_ptr<Event> event)
{
    _eventQueue.push(event);
    printf("EventManager.queue() -> Event pushed to the queue, queue size now : %lli\n", _eventQueue.size());
}

std::size_t EventManager::getQueueSize()
{
    return _eventQueue.size();
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
    auto seh = _handlers.find(type);

    if (seh == _handlers.end())
    {
        _handlers[type] = SingleEventHandlers();
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
    while (!_eventQueue.empty())
    {
        printf("Dispatching one event from queue\n");
        std::shared_ptr<Event> event = _eventQueue.front();
        process(event);
        _eventQueue.pop();
    }
}