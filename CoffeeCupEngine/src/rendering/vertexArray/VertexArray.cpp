#include "VertexArray.h"
#include "../../platform/OpenGL/GLVertexArray.h"

std::shared_ptr<VertexArray> create()
{
    // Only OpenGL is supported at the moment
    return std::make_shared<GLVertexArray>();
}
