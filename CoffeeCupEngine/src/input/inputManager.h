#pragma once

#include <memory>
#include <unordered_map>
#include <string>

#include "events/eventHandler.h"
#include "inputContext.h"
#include "inputContextChain.h"
#include "commandFactory.h"
#include "command.h"

class InputContext;

class InputManager : public EventHandler
{
private:
    static std::shared_ptr<InputManager> _instance;
    InputContextChain _contextChain; // Can be iterated and access with context name
    CommandFactory _commandFactory;  // Used to map strings to subclassed commands for input mapping

public:
    InputManager() = default;

    InputManager(const InputManager &instance) = delete;

    static std::shared_ptr<InputManager> instance()
    {
        if (_instance == nullptr)
        {
            _instance = std::make_shared<InputManager>();
        }
        return _instance;
    }

    void init(const std::string inputMappingFile);
    const void loadInputMapping(const std::string filePath); // reads JSON input mapping file and maps an input to each command given their name

    void setContextStatus(std::string contextName, bool status); // active/inactive

    template <typename T>
    void registerInputCommand(std::string commandName) // Register a command subclass to a name, necessary to allow inputManager to map input to functions
    {
        _commandFactory.registerCommand<T>(commandName);
    };

    // overriden from eventHandler.h
    void onEvent(const std::shared_ptr<Event> event) override;
};