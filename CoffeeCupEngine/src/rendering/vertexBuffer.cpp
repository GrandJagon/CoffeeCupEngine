#include "CCEnginePrecompiled.h"
#include "vertexBuffer.h"
#include "platform/OpenGL/GLVertexBuffer.h"

std::shared_ptr<VertexBuffer> VertexBuffer::create()
{
    // Only OpenGL is supported at the moment
    return std::make_shared<GLVertexBuffer>();
}
