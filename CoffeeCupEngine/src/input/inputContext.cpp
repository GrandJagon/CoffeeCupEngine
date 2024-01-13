#include "CCEnginePrecompiled.h"
#include "inputContext.h"

void InputContext::processInput(std::shared_ptr<Event> input)
{
    printf("InputContext.processInput() : %s processing event of type %d\n", getName().c_str(), input->getType());
    // Loop through commands and check if it needs to be triggered
};

void InputContext::addCommand(std::shared_ptr<Command> command)
{
    _commands.push_back(command);
};