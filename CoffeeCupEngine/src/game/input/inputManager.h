#pragma once

#include "inputContext.h"
#include "bitmask.h"
#include "command.h"
#include "../../utils/utilities.h"

#include <memory>
#include <unordered_map>
#include <string>

class InputManager
{
    private:
        std::unordered_map<std::string, std::shared_ptr<InputContext>> _contexts;
        std::shared_ptr<InputContext> _currContext;

    public:
        InputManager();

        static InputManager* instance() {
            static InputManager instance;
            return &instance;
        }

        void init();
        void addContext(std::shared_ptr<InputContext> context);
        std::shared_ptr<InputContext> getCurrentContext() { return _currContext;};  // move to transfer ownership
        void update();

 };