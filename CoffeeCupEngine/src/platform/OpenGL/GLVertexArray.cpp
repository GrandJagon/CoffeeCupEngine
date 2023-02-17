#include "CCEnginePrecompiled.h"
#include "GLVertexArray.h"
#include "GLVertexBufferLayout.h"
#include "GlUtils.h"


GLVertexArray::~GLVertexArray()
{   
    std::cout << "Destructing VAO with id " << m_id << std::endl;
    GlCall(glDeleteVertexArrays(1, &m_id));
}

void GLVertexArray::init()
{  
    GlCall(glGenVertexArrays(1, &m_id));
    std::cout << "VAO initiated with ID " << m_id << std::endl;
}

void GLVertexArray::bind() const
{   
    GlCall(glBindVertexArray(m_id));
}

void GLVertexArray::unbind() const
{
    GlCall(glBindVertexArray(0));
}

void GLVertexArray::addBuffer(const std::shared_ptr<VertexBuffer> vb, const std::shared_ptr<VertexBufferLayout> layout) const
{
    bind();
    vb->bind();
    const auto& elements = layout->elements();
    unsigned int offset = 0;

    for(unsigned int i = 0 ; i < elements.size(); i++)
    {
        GlCall(glEnableVertexAttribArray(i));
        GlCall(glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, layout->getStride(), (const void*) offset));

        offset += elements[i].count * GLVertexBufferLayout::getSizeOfType(elements[i].type);
    }
}