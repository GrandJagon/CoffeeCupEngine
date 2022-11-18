#pragma once

#include "../texture/Texture.h"
#include <unordered_map>


class TextureManager
{
    private:
        static std::unordered_map<int, Texture> _textures;
        static int _slotIndex;

    public:
        static Texture loadTexture(const &path);
        static Texture loadTexture(void *color, int width, int height);
}