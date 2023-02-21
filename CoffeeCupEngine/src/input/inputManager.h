#pragma once

#include <memory>
#include <unordered_map>
#include <string>

class InputContext;


class InputManager
{
    private:
        std::unordered_map<std::string, std::shared_ptr<InputContext>> _inputContexts;
        std::shared_ptr<InputContext> _currContext;

    public:
        InputManager();

        static InputManager* instance() {
            static InputManager instance;
            return &instance;
        }

        void init();
        void addContext(std:string contextName, std::shared_ptr<InputContext> context);
        void setCurrentContext(std::string contextName);
        std::shared_ptr<InputContext> getCurrentContext() { return _currContext;};  // move to transfer ownership
        void processMouseInputs();
        void processKeyboardInputs();
        void processControllerInputs();
 };