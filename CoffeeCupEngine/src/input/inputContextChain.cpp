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

void InputContextChain::processInput(std::shared_ptr<InputEvent> event)
{
    InputContext *context = dynamic_cast<InputContext*>(head);

    while(context != nullptr)
    {
        if(context->isActive())
        {
            context->processInput(event);

            if(context->isBlocking()){
                return;
            }
        }
        context = dynamic_cast<InputContext*>(context->next);
    }
};