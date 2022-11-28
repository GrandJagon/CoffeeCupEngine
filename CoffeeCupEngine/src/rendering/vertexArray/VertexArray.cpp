#include "VertexArray.h"


VertexArray::~VertexArray()
{   
    std::cout << "Destructing VAO with id " << m_id << std::endl;
    GlCall(glDeleteVertexArrays(1, &m_id));
}

void VertexArray::init()
{  
    std::cout << "Initiating VAO with id " << m_id << std::endl;
    GlCall(glGenVertexArrays(1, &m_id));
}

void VertexArray::bind() const
{   
    GlCall(glBindVertexArray(m_id));
}

void VertexArray::unbind() const
{
    GlCall(glBindVertexArray(0));
}

void VertexArray::addBuffer(const std::shared_ptr<DynamicVertexBuffer>& vb, const VertexBufferLayout& layout)
{
    bind();
    vb->bind();
    const auto& elements = layout.elements();
    unsigned int offset = 0;

    for(unsigned int i = 0 ; i < elements.size(); i++)
    {
        GlCall(glEnableVertexAttribArray(i));
        GlCall(glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, layout.getStride(), (const void*) offset));

        offset += elements[i].count * LayoutElement::GetSizeOfType(elements[i].type);
    }
}