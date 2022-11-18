#pragma once

#include "bitmask.h"
#include "../../utils/utilities.h"
#include <map>

struct Key
{
    int index;
    int code;
};

class InputHandler
{
    private:
        Bitmask _keysCurrentFrame;
        Bitmask _keysLastFrame;

        // Stores the indexed list of valid in puts
        // Size must not be more than 32 as bitmasks are 32 bits integers
        std::vector<Key> _validKeys;

    public:
        InputHandler();

        void setValidKeys(std::vector<Key> keys) {_validKeys = keys;};

        // To be passed as callback to the window object
        void update(GLFWwindow* window, int key, int scancode, int action, int mods);

        // Key is pressed this frame
        bool isKeyPressed(Key key);

        // Key is pressed this frame and the previous one
        bool isKeyDown(Key key);
}