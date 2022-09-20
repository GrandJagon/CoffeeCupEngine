#pragma once
#include "../../utils/utilities.h"

class Texture
{
    private:
        unsigned int m_id;
        std::string m_filePath;
        int m_width, m_height, m_bitsPerPixel;
        unsigned char* m_buffer;
        unsigned int _slotIndex;

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
        inline const unsigned int getSlot() {return _slot;}

};