#include "../../vendors/stb_image/stb_image.h"
#include "Texture.h"

unsigned int Texture::_slot = 0;


Texture::Texture(const std::string &path) :
    m_id(0), m_filePath(path), m_buffer(nullptr), m_width(0), m_height(0), m_bitsPerPixel(0)
{   
    std::cout << "Texture created with slot " << _slot;
    // Image loaded inverted so needs to flip it
    stbi_set_flip_vertically_on_load(1);

    // Loading image as a buffer of bytes
    m_buffer = stbi_load(path.c_str(), &m_width, &m_height, &m_bitsPerPixel, 4);
    
    // Creting texture and binding it
    GlCall(glGenTextures(1, &m_id));
    GlCall(glBindTexture(GL_TEXTURE_2D, m_id));

    // Setting the different textures arguments, all 4 are needed otherwise empty texture
    
    // Behaviour when image is mignified
    // GL_NEAREST = Takes the nearest pixel color GL_LINER = Takes the average color 
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
    
    // Behaviour when image is magnified
    // Same as above
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
    
    // Behaviour when texture is outside of coordinates for the S axis (same as x axis)
    // Values can be GL_REAPEAT, GL_MIRRORED_REPEAT,  GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    
    // Same for axis t (axis y)
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

    // Assigning buffer data to texture
    GlCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_buffer));

    // Since it is now create the texture can be unbinded for future use
    GlCall(glBindTexture(GL_TEXTURE_2D, 0));

    // Clearing the buffer
    if(m_buffer)
    {
        stbi_image_free(m_buffer);
    }

    _slot += 1;
}

Texture::Texture(void *color, int width, int height) :
    m_id(0), m_bitsPerPixel(0), m_width(width), m_height(height)
{   

    std::cout << "Color texture created with slot " << _slot;

    // Creting texture and binding it
    GlCall(glGenTextures(1, &m_id));
    GlCall(glBindTexture(GL_TEXTURE_2D, m_id));

    // Setting the different textures arguments, all 4 are needed otherwise empty texture
    
    // Behaviour when image is mignified
    // GL_NEAREST = Takes the nearest pixel color GL_LINER = Takes the average color 
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    
    // Behaviour when image is magnified
    // Same as above
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
    
    // Behaviour when texture is outside of coordinates for the S axis (same as x axis)
    // Values can be GL_REAPEAT, GL_MIRRORED_REPEAT,  GL_CLAMP_TO_EDGE, GL_CLAMP_TO_BORDER
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
    
    // Same for axis t (axis y)
    GlCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));

    // Assigning buffer data to texture
    GlCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, color));

    // Since it is now create the texture can be unbinded for future use
    GlCall(glBindTexture(GL_TEXTURE_2D, 0));

    _slot += 1;
}  

Texture::~Texture()
{
    GlCall(glDeleteTextures(1, &m_id));
    std::cout << "Texture destroyed " << _slot << std::endl;
    _slot -= 1;
}

// Binds to default texture 0
// Most GPU have 32 slots
// Slot value must then be set accordingly in shader
void Texture::bind(unsigned int slot)
{
    GlCall(glActiveTexture(GL_TEXTURE0 + slot));
    GlCall(glBindTexture(GL_TEXTURE_2D, m_id));
}


void Texture::unbind()
{
    GlCall(glBindTexture(GL_TEXTURE_2D, 0));
}