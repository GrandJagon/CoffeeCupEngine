#include "DynamicIndexBuffer.h"
#include "../../platform/OpenGL/GLDynamicIndexBuffer.h"

std::shared_ptr<DynamicIndexBuffer> DynamicIndexBuffer::create()
{
    // Only openGL supported for now
    return std::make_shared<GLDynamicIndexBuffer>();
}