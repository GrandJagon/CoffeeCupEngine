#include "CCEnginePrecompiled.h"
#include "inputManager.h"
#include "inputContext"

InputManager::init()
{

}

InputManager::addContext(std::string contextName, std::shared_ptr<InputContext> context)
{
    _inputContexts.insert({contextName, context});
}

InputManager::setCurrentContext(std::string contextName)
{
    auto foundContext = _inputContexts.find(contextName);
    if(foundContext == _inputContext.end())
    {
        throw std::runtime_error("Cannot set input context as it does not exist");
    }
    _currContext = foundContext;
}

InputManager::processInputs()
{
    _currContext->pollEvents();
    _currContext->executeCommands();
}

