#pragma once

#include <unordered_map>
#include <memory>

#include "command.h"

// Dynamically maps string to input command

class CommandFactory 
{
    private:
        std::unordered_map<std::string, std::shared_ptr<Command>(*)()> _commandMapping; // allows input manager to properly set input mapping

    public:
    
        template <typename T>
        void registerCommand<T>(std::string key)
        {
            _commandMapping[key] = &Command::createCommand<T>;

            std::cout << key << " successfully mapped" << std::endl;
        };

        std::shared_ptr<Command> createCommand(std::string key)
        {
            auto it = _commandMapping.find(key);

            if(it == _commandMapping.end())
            {
                std::cout << key << " not found in command mapping" << std::endl;
                throw std::runtime_error("Could not map command");
            };

            return it;
        }
}