#pragma once

#include <memory>
#include <unordered_map>
#include <string>

#include "events/eventHandler.h"
#include "inputContextChain.h"

class InputContext;


class InputManager : public EventHandler
{
    private:
        InputContextChain _contextChain; // Can be iterated and access with context name
        
    public:
        InputManager() = default;

        static InputManager* instance() {
            static InputManager instance;
            return &instance;
        }

        void init(const std::string inputMappingFile);
        const void loadInputMapping(const std::string filePath); // reads JSON input mapping file and maps an input to each command given their name
        
        void addContext(std::string contextName, std::shared_ptr<InputContext> context);
        void setContextStatus(std::string contextName, bool status); // active/inactive
        
        // overriden from eventHandler.h
        void onEvent(const std::shared_ptr<Event> event) override;
 };