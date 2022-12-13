#include "GLDynamicVertexBuffer.h"

class Vertex;

void GLDynamicVertexBuffer::init(unsigned int size)
{
    GlCall(glGenBuffers(1, &_id));
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, _id));
    GlCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * size, nullptr, GL_DYNAMIC_DRAW));
    std::cout <<  " VBO initiated with ID " << _id << std::endl;
}

GLDynamicVertexBuffer::~GLDynamicVertexBuffer()
{
    std::cout << "Destroying VBO with ID " << _id << std::endl; 
    GlCall(glDeleteBuffers(1, &_id));
}

void GLDynamicVertexBuffer::bind() const
{
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, _id));
}

void GLDynamicVertexBuffer::unbind() const
{
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void GLDynamicVertexBuffer::add(const void *data, unsigned int size)
{   
    bind();
    GlCall(glBufferSubData(GL_ARRAY_BUFFER, _offset, size, data));
    _offset += size;
}

void GLDynamicVertexBuffer::reset()
{
    _offset = 0;
}

