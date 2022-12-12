#include "GLDynamicIndexBuffer.h"

void GLDynamicIndexBuffer::init(unsigned int size)
{
    GlCall(glGenBuffers(1, &m_id));
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
    GlCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * size, nullptr, GL_DYNAMIC_DRAW));
    std::cout <<  " VBO initiated with ID " << m_id << std::endl;
}

GLDynamicIndexBuffer::~GLDynamicIndexBuffer()
{
    std::cout << "Destroying VBO with ID " << m_id << std::endl; 
    GlCall(glDeleteBuffers(1, &m_id));
}

void GLDynamicIndexBuffer::bind() const
{
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}

void GLDynamicIndexBuffer::unbind() const
{
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void GLDynamicIndexBuffer::add(const void *data, unsigned int size)
{   
    bind();
    GlCall(glBufferSubData(GL_ARRAY_BUFFER, m_offset, size, data));
    m_offset += size;
}

void GLDynamicIndexBuffer::reset()
{
    m_offset = 0;
}

