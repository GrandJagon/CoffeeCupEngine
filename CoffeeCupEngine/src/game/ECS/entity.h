#pragma once

#include "component.h"
#include "../../base/window/window.h"
#include <vector>

class Entity
{
    private:
        std::vector<Component> _components;
    
    public:
        void addComponent(Component component);
        virtual void update(float dt);
        virtual void lateUpdate();
        virtual void draw(Window &window); 
 
}