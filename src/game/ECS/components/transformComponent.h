#pragma once

#include "../../utils/utilities.h"

class TransformComponent : public Component 
{
    private:
        glm::vec3 _position;
    
    public:
        const glm::vec2 getPosition() {return _position;};
        void setPosition(glm::vec3 newPos);
        void addPosition(glm::vec3 position);
        void setX(float x);    
        void setY(float y);
        void addX(float x);
        void addY(float y);

    
}