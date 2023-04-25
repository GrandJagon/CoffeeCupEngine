#pragma once

#include <unordered_map>
#include <memory>

#include "utils/linkedList.h"
#include "inputContext.h"
#include "inputEvents.h"


// Hybrid data struct containing a linked list for traversal and a map for access by key
class InputContextChain : public LinkedList
{
    private:
        std::unordered_map<std::string, std::shared_ptr<InputContext>> _contextMap; // Used for acces by name

    public:
        void addContext(std::shared_ptr<InputContext> context);
        std::shared_ptr<InputContext> getContext(std::string contextName);
        void processInput(std::shared_ptr<InputEvent> event);
};