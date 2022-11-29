#pragma once

#include "../.././utils/utilities.h"
#include "../texture/Texture.h"

#include <unordered_map>
#include <memory>


class TextureManager
{
    private:
        // Stores all texture with id as key
        std::unordered_map<unsigned int, std::shared_ptr<Texture>> _textures;
        unsigned int _slotIndex = 0;
        unsigned int _maxSlot;

        // Unbinds a single texture given its ID, not sure will be used, remove if not
        void unbindTexture(const unsigned int textId);

        // Frees a single slot
        void freeSlot(const unsigned int slotNumber);


    public:
        static TextureManager* instance() {
            static TextureManager instance;
            return &instance;
        }

        std::shared_ptr<Texture> loadTexture(const std::string &path);
        std::shared_ptr<Texture> createTexture(void *color, int width, int height);
        void bindTexture(const unsigned int textId);
        void overrideTexture(const unsigned int textId, const unsigned int slot);
        void unbindAll();
        inline unsigned int currIndex() { return _slotIndex;};
};