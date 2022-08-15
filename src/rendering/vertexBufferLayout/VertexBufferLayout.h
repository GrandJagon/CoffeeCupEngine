#pragma once
#include "../../utils/utilities.h"
#include <vector>

struct LayoutElement
{
    unsigned int index;
    unsigned int type;
    unsigned int count;
    unsigned int normalized;

    static unsigned int GetSizeOfType(unsigned int type)
    {
        switch(type)
        {
            case GL_FLOAT: return 4;
            case GL_UNSIGNED_INT: return 4;
            case GL_UNSIGNED_BYTE: return 1;
        };
        return 0;
    }

};

class VertexBufferLayout
{
    private:
        unsigned int m_id;
        unsigned int m_stride = 0;
        std::vector<LayoutElement> m_elements;

    public:
        VertexBufferLayout() = default;
        void addElement(unsigned int type, unsigned int count, bool normalized);
        void addElements(std::vector<std::array<unsigned int, 3>> elements);
        unsigned int getLastIndex();
        unsigned int getStride() const {return m_stride;};
        inline const std::vector<LayoutElement> elements() const {return m_elements;}

};

