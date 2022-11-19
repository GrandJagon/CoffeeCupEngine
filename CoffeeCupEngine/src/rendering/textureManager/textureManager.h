#pragma once

#include "../texture/Texture.h"
#include <unordered_map>


class TextureManager
{
    private:
        std::unordered_map<int, Texture> _textures;
        int _slotIndex = 0;
        
    public:
        Texture loadTexture(const std::string &path);
        Texture loadTexture(void *color, int width, int height);
        void bindTexture(unsigned int textId);
        void unbindTexture(unsigned int textId);
        void unbindAll();
};