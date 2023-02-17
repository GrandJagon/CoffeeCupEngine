#pragma once

#include "game/ECS/component.h"
#include "rendering/texture.h"
#include "rendering/window.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"


class SpriteComponent : public Component
{
    private:
        Texture _texture;
        glm::vec3 _position;
        glm::vec2 _size;

    public:
        void lateUpdate() override;
        void draw(Window &window) override;

        const glm::vec3 getPosition() {return _position;};
        const Texture getTexture() {return _texture;};
        const glm::vec2 getSize() {return _size;};
};