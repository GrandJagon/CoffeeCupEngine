#pragma once

#include "../.././utils/utilities.h"
#include "../texture/Texture.h"

#include <unordered_map>


class TextureManager
{
    private:
        // Stores all texture with id as key
        std::unordered_map<int, shared_ptr<Texture>> _textures;
        int _slotIndex = 0;
        
    public:
        shared_ptr<Texture> loadTexture(const std::string &path);
        shared_ptr<Texture> loadTexture(void *color, int width, int height);
        void bindTexture(unsigned int textId);
        void unbindTexture(unsigned int textId);
        void unbindAll();
};