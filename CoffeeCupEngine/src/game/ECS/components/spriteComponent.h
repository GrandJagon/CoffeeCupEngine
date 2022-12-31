#pragma once

#include "../../../utils/utilities.h"
#include "../component.h"
#include "../../../rendering/texture/Texture.h"
#include "../../../rendering/window/window.h"

class Window;

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