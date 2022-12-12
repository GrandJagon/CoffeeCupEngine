#include "DynamicIndexBuffer.h"
#include "../../platform/OpenGL/GLDynamicIndexBuffer.h"

std::shared_ptr<DynamicIndexBuffer> DynamicIndexBuffer::create()
{
    // Only openGL supported for now
    std::shared_ptr<GLDynamicIndexBuffer> indexBuffer = std::make_shared<GLDynamicIndexBuffer>();
    return indexBuffer;
}