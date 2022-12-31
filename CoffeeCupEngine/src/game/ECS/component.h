#pragma once

#include "../../rendering/window/window.h"

// Forward declared to avoid circular dependency, no method needed
class Entity;

class Component
{
    protected:
        Entity* _owner;
    
    public:
        // Pointer to the owner to be passed
        Component(Entity *owner) : _owner(owner) {};
        ~Component();
        virtual void update(float dt);
        virtual void lateUpdate();
        virtual void draw(Window &window);

};