#pragma once

#include <unordered_map>
#include <memory>

#include <glm/glm.hpp>

#include "command.h"
#include "bitmask.h"
#include "utils/linkedList.h"

enum ContextType {MOUSE_KEYBOARD, GAMEPAD};

class InputContext : public Node
{
    private:
        std::string _name;
        bool _status; // active or not
        bool _blocking; // if true event does not pass to next context (useful for menus)
        ContextType _type;
        Bitmask _stateCurrentFrame;
        Bitmask _stateLastFrame;
        glm::vec2 _cursorPos; 
        std::vector<std::shared_ptr<Command>> _commands;

    public:
        InputContext() {_status = false;};
        bool isActive() {return _status;};
        bool isBlocking() {return _blocking;};
        ContextType getType() {return _type;};
        std::string getName() {return _name;};
        Bitmask& getStateCurrent() {return _stateCurrentFrame;};
        Bitmask& getStateLast() {return _stateLastFrame;};
        glm::vec2 getCursorPos() {return _cursorPos;};

        void setName(std::string name) {_name = name;};
        void setBlocking(bool blocking) {_blocking = blocking;};
        void setStatus(bool status) {_status = status;};

        void addCommand(std::shared_ptr<Command> command);
        
        // Iterates through all commands and execute event if match
        void processInput(std::shared_ptr<InputEvent> input);
};