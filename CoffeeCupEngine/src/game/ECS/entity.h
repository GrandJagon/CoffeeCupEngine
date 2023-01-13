#pragma once

#include "component.h"
#include "../../rendering/window.h"
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
 
};