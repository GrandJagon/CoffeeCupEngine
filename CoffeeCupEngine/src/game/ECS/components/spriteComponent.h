#pragma once

#include <memory>

#include "game/ECS/component.h"
#include "rendering/window.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"

class Texture;

/* class SpriteComponent : public Component
{
    private:
        std::shared_ptr<Texture> _texture;
        glm::vec3 &_position;
        glm::vec2 _size;

    public:
        
        // Position should references owners transform component position
        SpriteComponent(Entity *owner, std::shared_ptr<Texture> texture, glm::vec3 position, glm::vec2 size)
            : Component(owner) 
        {
            _texture = texture;
            _position = position;
            _size = size;
        };

        void lateUpdate() override;
        void draw() override;
        

        const glm::vec3 getPosition() {return _position;};
        const Texture getTexture() {return _texture;};
        const glm::vec2 getSize() {return _size;};
};*/