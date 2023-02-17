#include "CCEnginePrecompiled.h"
#include "GLVertexBufferLayout.h"
#include "GlUtils.h"

void GLVertexBufferLayout::addElement(unsigned int type, unsigned int count, bool normalized)
{
    unsigned int index = getLastIndex();
    
    m_elements.push_back(
        {
            index, type, count, normalized
        }
    );
    m_stride += getSizeOfType(type) * count;
}

void GLVertexBufferLayout::addElements(std::vector<std::array<unsigned int, 3>> elements)
{
    for(int i = 0; i < elements.size(); i++)
    {
        addElement(elements[i][0], elements[i][1], elements[i][2]);
    }
}

unsigned int GLVertexBufferLayout::getLastIndex()
{
    return m_elements.size() - 1;
}

unsigned int GLVertexBufferLayout::getSizeOfType(unsigned int type)
    {
        switch(type)
        {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
        };
        return 0;
}