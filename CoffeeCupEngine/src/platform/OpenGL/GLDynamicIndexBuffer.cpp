#include "GLDynamicIndexBuffer.h"

void GLDynamicIndexBuffer::init(unsigned int size) 
{
    GlCall(glGenBuffers(1, &m_id));

    unsigned int indices[size * 6];
    unsigned int index= 0;
     
    // Generating 6 indices for each quad
    // Pattern always 0, 1, 2, 2, 3, 0
    for(unsigned int i = 0; i < size * 6; i+=6)
    {
        indices[i] = index;
        indices[i + 1] = index + 1;
        indices[i + 2] = index + 2;
        indices[i + 3] = index + 2;
        indices[i + 4] = index + 3;
        indices[i + 5] = index;
        index += 4;
    };

    GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
    GlCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * (size * 6), indices, GL_DYNAMIC_DRAW));

}

GLDynamicIndexBuffer::~GLDynamicIndexBuffer()
{
    GlCall(glDeleteBuffers(1, &m_id));
}

void GLDynamicIndexBuffer::bind() const
{
    GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id));
}

void GLDynamicIndexBuffer::unbind() const
{
    GlCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

void GLDynamicIndexBuffer::reset()
{
    m_count = 0;
}
