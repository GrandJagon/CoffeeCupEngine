#include "CCEnginePrecompiled.h"
#include "indexBuffer.h"
#include "platform/OpenGL/GLIndexBuffer.h"

std::shared_ptr<IndexBuffer> IndexBuffer::create()
{
    // Only openGL supported for now
    return std::make_shared<GLIndexBuffer>();
}