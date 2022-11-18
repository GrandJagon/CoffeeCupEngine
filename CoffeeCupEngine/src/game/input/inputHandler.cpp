#include "inputHandler.h"


void InputHandler::update(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    _keysLastFrame.setMask(_keysCurrentFrame);

    for(Key k : _validKeys)
    {
        if (key == k.code)
        {
            _keysCurrentFrame.setBit(k.index, 1);
        }
    }
}

bool InputHandler::isKeyPressed(Key key)
{
    return _keysCurrentFrame.getBit(key.index);
}

bool InputHandler::isKeyDown(Key key)
{
    return (_keysCurrentFrame.getBit(key.index) && _keysLastFrame.getBit(key.index));
}