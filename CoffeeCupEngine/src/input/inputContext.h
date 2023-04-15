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
        bool _status; // active or not
        bool _blocking; // if true event does not pass to next context (useful for menus)
        ContextType _type;
        Bitmask _state;
        glm::vec2 _cursorPos;
        std::vector<std::shared_ptr<Command>> _commands;

    public:
        bool isActive() {return _status;};
        bool isBlocking() {return _blocking;};
        ContextType getType() {return _type;};
        Bitmask& getState() {return _state;};
        glm::vec2 getCursorPos() {return _cursorPos;};

        void setStatus(bool active) {_status = active;};

        void addCommand(std::shared_ptr<Command> command);
        
        // Iterates through all commands and execute event if match
        void processInput(std::shared_ptr<Event> event);
};