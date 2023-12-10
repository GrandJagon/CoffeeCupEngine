#include "CCEnginePrecompiled.h"
#include "inputContextChain.h"

void InputContextChain::addContext(std::shared_ptr<InputContext> context, std::string name)
{
    _contextMap.insert({name, context});
}

std::shared_ptr<InputContext> InputContextChain::getContext(std::string contextName)
{
    return _contextMap.at(contextName);
};

void InputContextChain::processInput(std::shared_ptr<Event> event)
{
    printf("InputContextChain starting to process event of type %d\n", event->getType());

    InputContext *context = dynamic_cast<InputContext *>(head);

    while (context != nullptr)
    {
        if (context->isActive())
        {
            printf("Sending event for processing to context %s as it is found active", context->getName().c_str());
            context->processInput(event);

            if (context->isBlocking())
            {
                return;
            }
        }
        context = dynamic_cast<InputContext *>(context->next);
    }
};