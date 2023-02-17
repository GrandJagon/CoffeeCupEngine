#include "CCEnginePrecompiled.h"
#include "vertexBufferLayout.h"
#include "platform/OpenGL/GLVertexBufferLayout.h"

std::shared_ptr<VertexBufferLayout> VertexBufferLayout::create()
{
    // Only OpenGL is supported at the moment
    return std::make_shared<GLVertexBufferLayout>();
}
