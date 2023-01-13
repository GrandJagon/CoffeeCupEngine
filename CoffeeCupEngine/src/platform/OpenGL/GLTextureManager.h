#pragma once

#include "GlUtils.h"
#include "../../rendering/textureManager.h"

#include <vector>
#include <memory>

class GLTextureManager : public TextureManager
{
    private:
        // Stores active textures with slot index as key
        std::vector<std::shared_ptr<Texture>> _textures;
        int _maxSlot;
        unsigned int _slotIndex;

        void unbindSlot(const unsigned int slotNumber);


    public:
        void init() override;

        // Creates texture from asset
        std::shared_ptr<Texture> loadTexture(const std::string &path) override;

        // Creates texture from color
        std::shared_ptr<Texture> createTexture(void *color, int width, int height) override;
        
        //  Binds a single texture to its slot and returns slot index
        unsigned int bindTexture(std::shared_ptr<Texture> texture) override;
        
        // Loops through all textures to bind them, to be called before rendering each frame
        void bindAll() override;
        
        // Unbind all textures and clears the vector
        void unbindAll() override;

        inline unsigned int currIndex() override { return _slotIndex;};

        inline int maxSlot() override {return _maxSlot;};
};