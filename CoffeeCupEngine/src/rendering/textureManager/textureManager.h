#pragma once

#include "../.././utils/utilities.h"
#include "../texture/Texture.h"

#include <vector>
#include <memory>


class TextureManager
{
    private:
        // Stores active textures with slot index as key
        std::vector<std::shared_ptr<Texture>> _textures;
        int _maxSlot;
        unsigned int _slotIndex;

        void unbindSlot(const unsigned int slotNumber);


    public:
        static TextureManager* instance() {
            static TextureManager instance;
            return &instance;
        }
        
        void init();

        // Creates texture from asset
        std::shared_ptr<Texture> loadTexture(const std::string &path);

        // Creates texture from color
        std::shared_ptr<Texture> createTexture(void *color, int width, int height);
        
        //  Binds a single texture to its slot and returns slot index
        unsigned int bindTexture(std::shared_ptr<Texture> texture);
        
        // Loops through all textures to bind them, to be called before rendering each frame
        void bindAll();
        
        // Unbind all textures and clears the vector
        void unbindAll();

        inline unsigned int currIndex() { return _slotIndex;};

        inline int maxSlot() {return _maxSlot;};
};