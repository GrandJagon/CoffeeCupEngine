#pragma once

#include "component.h"
#include "rendering/window.h"
#include <vector>

class Entity
{
    private:
        std::vector<Component> _components; // objects or pointer ???
    
    public:
        void addComponent(Component component);
        virtual void update(float dt);
        virtual void lateUpdate();
        virtual void draw(); 
 
};