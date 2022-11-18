#include "VertexBufferLayout.h"


void VertexBufferLayout::addElement(unsigned int type, unsigned int count, bool normalized)
{
    unsigned int index = getLastIndex();
    
    m_elements.push_back(
        {
            index, type, count, normalized
        }
    );
    m_stride += LayoutElement::GetSizeOfType(type) * count;
    std::cout << m_stride << std::endl;
}

void VertexBufferLayout::addElements(std::vector<std::array<unsigned int, 3>> elements)
{
    for(int i = 0; i < elements.size(); i++)
    {
        addElement(elements[i][0], elements[i][1], elements[i][2]);
    }
}

unsigned int VertexBufferLayout::getLastIndex()
{
    return m_elements.size() - 1;
}