#include "CCEnginePrecompiled.h"
#include "inputContext.h"

void InputContext::processInput(std::shared_ptr<Event> input)
{
    printf("InputContext %s processing event of type %d\n", getName().c_str(), input->getType());
};

void InputContext::addCommand(std::shared_ptr<Command> command){};