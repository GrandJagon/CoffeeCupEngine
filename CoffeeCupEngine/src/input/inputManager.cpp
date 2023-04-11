#include "CCEnginePrecompiled.h"
#include "inputManager.h"


void InputManager::init()
{

}

void InputManager::addContext(std::string contextName, std::shared_ptr<InputContext> context)
{
    _inputContexts.insert({contextName, context});
}

void InputManager::onEvent()
{

}

