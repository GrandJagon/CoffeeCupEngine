#include "DynamicVertexBuffer.h"
#include "../../platform/OpenGL/GLDynamicVertexBuffer.h"

std::shared_ptr<DynamicVertexBuffer> DynamicVertexBuffer::create()
{
    // Only OpenGL is supported at the moment
    return std::make_shared<GLDynamicVertexBuffer>();
}
