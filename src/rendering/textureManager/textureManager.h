#pragma once
#include "../texture/Texture.h"

class TextureManager
{
    private:
        static std::vector<Texture> _textures;
        static int _slotIndex;

    public:
        static Texture loadTexture(const &path);
}