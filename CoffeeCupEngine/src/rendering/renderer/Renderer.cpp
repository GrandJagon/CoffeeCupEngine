#include "Renderer.h"

#include "../../platform/OpenGL/GLRenderer.h"

std::shared_ptr<Renderer> Renderer::instance()
{
    // Only OpenGL is supported at the moment
    static std::shared_ptr<GLRenderer> instance = std::make_shared<GLRenderer>();
    return instance;
}