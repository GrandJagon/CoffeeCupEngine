#pragma once

#include "../texture/Texture.h"

#include <vector>
#include <memory>


class TextureManager
{
    public:
        virtual ~TextureManager() = default;
        
        static std::shared_ptr<TextureManager> instance();
        
        virtual void init() = 0;

        // Creates texture from asset
        virtual std::shared_ptr<Texture> loadTexture(const std::string &path)= 0;

        // Creates texture from color
        virtual std::shared_ptr<Texture> createTexture(void *color, int width, int height)= 0;
        
        //  Binds a single texture to its slot and returns slot index
        virtual unsigned int bindTexture(std::shared_ptr<Texture> texture)= 0;
        
        // Loops through all textures to bind them, to be called before rendering each frame
        virtual void bindAll()= 0;
        
        // Unbind all textures and clears the vector
        virtual void unbindAll() = 0;

        virtual unsigned int currIndex() {throw std::runtime_error("Method not implemented");};

        virtual int maxSlot() {throw std::runtime_error("Method not implemented");};
};