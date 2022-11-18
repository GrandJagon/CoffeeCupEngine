#pragma once
#include "../../utils/utilities.h"

class Texture
{
    private:
        unsigned int m_id;

        // SlotId assigned byt textureManager, -1 if not bound
        unsigned int m_slot;
        std::string m_filePath;
        int m_width, m_height, m_bitsPerPixel;

    public:
        Texture() = default;
        // Creates a texture shader from a file path
        Texture(const std::string &path);
        // Creates a color shader
        Texture(void *color, int width, int height);
        ~Texture();
        void bind(unsigned int slot);
        void unbind();

        inline const int getWidth() {return m_width;}
        inline const int getHeight() {return m_height;}

};