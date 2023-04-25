#include "CCEnginePrecompiled.h"
#include "inputContext.h"


InputContext::InputContext(std::string name, bool blocking)
{
    _name = name;
    _blocking = blocking;
    _status = false;
};


void InputContext::processInput(std::shared_ptr<InputEvent> input)
{

};