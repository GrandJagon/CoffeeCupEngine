#include "CCEnginePrecompiled.h"

#include "inputContextChain.h"

std::shared_ptr<InputContext> InputContextChain::getcontext(std::string contextName)
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
}