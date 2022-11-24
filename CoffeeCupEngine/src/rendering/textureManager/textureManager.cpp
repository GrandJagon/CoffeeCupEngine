#include "textureManager.h"

shared_ptr<Texture> TextureManager::loadTexture(const std::string &path)
{
    // Image loaded inverted so needs to flip it
    stbi_set_flip_vertically_on_load(1);

    // Loading image as a buffer of bytes
    unsigned char buffer;
    int id, width, height, bitsPerPixel;
    buffer = stbi_load(path.c_str(), &width, &height, &bitsPerPixel, 4);
    
    // Generating texture id and assigning it to id + binding it
    GlCall(glGenTextures(1, &id));
    GlCall(glBindTexture(GL_TEXTURE_2D, id));

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
    GlCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer));

    // Since it is now created the texture can be unbinded for future use
    GlCall(glBindTexture(GL_TEXTURE_2D, 0));

    // Clearing the buffer
    if(buffer)
    {
        stbi_image_free(buffer);
    }
    
    // Storing all texture data to texture object
    shared_ptr<Texture> texture(Texture(id, path, width, height, bitsPerPixel));

    return texture;
}

shared_ptr<Texture> TextureManager::loadTexture(void *color, int width, int height) 
{   
    int id, width, height, bitsPerPixel;

    // Creting texture and binding it
    GlCall(glGenTextures(1, &id));
    GlCall(glBindTexture(GL_TEXTURE_2D, id));

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
    GlCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, color));

    // Since it is now create the texture can be unbinded for future use
    GlCall(glBindTexture(GL_TEXTURE_2D, 0));

    // Storing all texture data to texture object
    shared_ptr<Texture> texture(Texture(id, width, height, bitsPerPixel));

    return texture;

}


void TextureManager::bindTexture(unsigned int slot)
{
    GlCall(glActiveTexture(GL_TEXTURE0 + slot));
    GlCall(glBindTexture(GL_TEXTURE_2D, m_id));
}


void TextureManager::unbindTexture()
{
    GlCall(glBindTexture(GL_TEXTURE_2D, 0));
}