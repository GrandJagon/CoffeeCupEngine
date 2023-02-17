#include "CCEnginePrecompiled.h"
#include "textureManager.h"
#include "platform/OpenGL/GLTextureManager.h"

std::shared_ptr<TextureManager> TextureManager::instance()
{
    // Only OpenGL is supported at the moment
    static std::shared_ptr<GLTextureManager> instance = std::make_shared<GLTextureManager>();
    return instance;
}
