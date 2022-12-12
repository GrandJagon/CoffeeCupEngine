#pragma once

#include "GlUtils.h"
#include "../../rendering/vertexBufferLayout/VertexBufferLayout.h"

#include <vector>

class GLVertexBufferLayout : public VertexBufferLayout
{
    private:
        unsigned int m_id;
        unsigned int m_stride = 0;
        std::vector<LayoutElement> m_elements;
        unsigned int getSizeOfType(unsigned int type) const;

    public:
        VertexBufferLayout() = default;
        void addElement(unsigned int type, unsigned int count, bool normalized) override;
        void addElements(std::vector<std::array<unsigned int, 3>> elements) override;
        unsigned int getLastIndex() override;
        unsigned int getStride() const override {return m_stride;};
        inline const std::vector<LayoutElement> elements() const override {return m_elements;}
        
};

