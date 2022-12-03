#include "DynamicVertexBuffer.h"

void DynamicVertexBuffer::init(unsigned int size)
{
    GlCall(glGenBuffers(1, &m_id));
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
    GlCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * size, nullptr, GL_DYNAMIC_DRAW));
    std::cout <<  " VBO initiated with ID " << m_id << std::endl;
}

DynamicVertexBuffer::~DynamicVertexBuffer()
{
    std::cout << "Destroying VBO with ID " << m_id << std::endl; 
    GlCall(glDeleteBuffers(1, &m_id));
}

void DynamicVertexBuffer::bind() const
{
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, m_id));
}

void DynamicVertexBuffer::unbind() const
{
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void DynamicVertexBuffer::add(const void *data, unsigned int size)
{   
    bind();
    GlCall(glBufferSubData(GL_ARRAY_BUFFER, m_offset, size, data));
    m_offset += size;
}

void DynamicVertexBuffer::reset()
{
    m_offset = 0;
}

