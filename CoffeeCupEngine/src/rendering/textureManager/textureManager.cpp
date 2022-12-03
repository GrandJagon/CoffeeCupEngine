#include "textureManager.h"

std::shared_ptr<Texture> TextureManager::loadTexture(const std::string &path)
{
    // Image loaded inverted so needs to flip it
    stbi_set_flip_vertically_on_load(1);

    // Loading image as a buffer of bytes
    unsigned char *buffer;
    unsigned int id;
    int width, height, bitsPerPixel;
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
    auto texture = std::make_shared<Texture> (id, path, width, height, bitsPerPixel);
    _textures.insert({id, texture});

    std::cout << "Texture loaded by texture manager from path " << path << " with id " << id << std::endl;

    return texture;
}

std::shared_ptr<Texture> TextureManager::createTexture(void *color, int width, int height) 
{   
    unsigned int id;
    int bitsPerPixel;

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
    auto texture = std::make_shared<Texture> (id, width, height, bitsPerPixel);
    _textures.insert({id, texture});

    std::cout << "Texture created by texture manager with id " << id << std::endl;

    return texture;
}


void TextureManager::bindTexture(const unsigned int textId)
{   
    auto value = _textures.find(textId);

    if(value == _textures.end())
    {
        throw std::runtime_error("Texture id does not exist");
    };

    std::shared_ptr<Texture> texture = value->second;

    unsigned int index;

    if( (index = texture->getIndex()) != -1)
    {
        std::cout << "Texture already bound with index " << index << std::endl;
        return;
    }
    
    GlCall(glActiveTexture(GL_TEXTURE0 + _slotIndex));
    GlCall(glBindTexture(GL_TEXTURE_2D, texture->getId()));

    texture->setIndex(_slotIndex);

    std::cout << "Texture with ID " << texture->getId() << " bound to slot " << _slotIndex << std::endl;

    _slotIndex++;
}

void TextureManager::overrideTexture(const unsigned int textId, const unsigned int slotNumber)
{
    if(slotNumber < 0 || slotNumber > _maxSlot)
    {
        throw std::runtime_error("Invalid slot number, cannot be overriden");
    }

    auto value = _textures.find(textId);

    if(value == _textures.end())
    {
        throw std::runtime_error("Texture id does not exist");
    };

    std::shared_ptr<Texture> texture = value->second;

    GlCall(glActiveTexture(GL_TEXTURE0 + slotNumber));
    GlCall(glBindTexture(GL_TEXTURE_2D, texture->getId()));

    texture->setIndex(_slotIndex);
}

void TextureManager::freeSlot(const unsigned int slotNumber)
{

    if(slotNumber < 0 || slotNumber > _maxSlot)
    {
        throw std::runtime_error("Invalid slot number, cannot be freed");
    }

    GlCall(glActiveTexture(GL_TEXTURE0 + slotNumber));
    GlCall(glBindTexture(GL_TEXTURE_2D, 0));
}


void TextureManager::unbindTexture(const unsigned int textId)
{
    auto value = _textures.find(textId);

    if(value == _textures.end())
    {
        throw std::runtime_error("Texture id does not exist");
    };

    std::shared_ptr<Texture> texture = value->second;

    unsigned int index;

    if( (index = texture->getIndex()) == -1)
    {
        std::cout << "Texture " << index << "is not bound" << std::endl;
        return;
    }

    freeSlot(index);

    texture->setIndex(-1);
}

void TextureManager::unbindAll()
{
    for(int i = _slotIndex; i >= 0; i--)
    {
        freeSlot(i);
    }

    std::cout << "Unbinding successfull" << std::endl;
}