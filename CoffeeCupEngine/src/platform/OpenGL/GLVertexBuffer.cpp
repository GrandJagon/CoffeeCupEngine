#include "GLVertexBuffer.h"

class Vertex;

void GLVertexBuffer::init(unsigned int size)
{
    GlCall(glGenBuffers(1, &_id));
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, _id));
    GlCall(glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * size, nullptr, GL_DYNAMIC_DRAW));
    std::cout <<  " VBO initiated with ID " << _id << std::endl;
}

GLVertexBuffer::~GLVertexBuffer()
{
    std::cout << "Destroying VBO with ID " << _id << std::endl; 
    GlCall(glDeleteBuffers(1, &_id));
}

void GLVertexBuffer::bind() const
{
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, _id));
}

void GLVertexBuffer::unbind() const
{
    GlCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

void GLVertexBuffer::add(const void *data, unsigned int size)
{   
    bind();
    GlCall(glBufferSubData(GL_ARRAY_BUFFER, _offset, size, data));
    _offset += size;
}

void GLVertexBuffer::reset()
{
    _offset = 0;
}

