#include "CCEnginePrecompiled.h"
#include "inputContextChain.h"

void InputContextChain::addContext(std::shared_ptr<InputContext> context, std::string name)
{
    _contextMap.insert({name, context});
    add(context); // Adding the context to the LinkedList in order for it to be accssed during traversal
}

std::shared_ptr<InputContext> InputContextChain::getContext(std::string contextName)
{
    return _contextMap.at(contextName);
};

void InputContextChain::processInput(std::shared_ptr<Event> event)
{
    printf("InputContextChain.processInput(): event of type %d\n", event->getType());

    std::shared_ptr<InputContext> context = std::static_pointer_cast<InputContext>(head);

    while (context != nullptr)
    {
        if (context->isActive())
        {
            context->processInput(event);

            if (context->isBlocking())
            {
                return;
            }
        }
        context = std::static_pointer_cast<InputContext>(context->next);
    }
};