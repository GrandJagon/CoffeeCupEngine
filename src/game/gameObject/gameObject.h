#pragma once

#include "../sprite/sprite.h"

class GameObject
{
    public:
        glm::vec2 position, velocity, size;
        Sprite sprite;
        bool collidable; 
};