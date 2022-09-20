#pragma once

#include "entity.h"
#include "../../base/window/window.h"

class Component
{
    protected:
        Entity* _owner;
    
    public:
        Component(Entity owner) : _owner(&owner) {};
        ~Component();
        virtual void update(float dt);
        virtual void lateUpdate();
        virtual void draw(Window &window);

}