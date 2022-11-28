#pragma once

#include "../.././utils/utilities.h"
#include "../texture/Texture.h"

#include <unordered_map>
#include <memory>


class TextureManager
{
    private:
        // Stores all texture with id as key
        std::unordered_map<int, std::shared_ptr<Texture>> _textures;
        int _slotIndex = 0;
        
    public:
        static TextureManager* instance() {
            static TextureManager instance;
            return &instance;
        }

        std::shared_ptr<Texture> loadTexture(const std::string &path);
        std::shared_ptr<Texture> createTexture(void *color, int width, int height);
        void bindTexture(const unsigned int textId);
        void unbindTexture(const unsigned int textId);
        void unbindAll();
        inline int currIndex() { return _slotIndex;};
};