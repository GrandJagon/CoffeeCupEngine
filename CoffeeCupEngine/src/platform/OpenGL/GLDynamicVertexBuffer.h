#pragma once

#include "GlUtils.h"
#include "../../rendering/vertexBuffer/DynamicVertexBuffer.h"

class GLDynamicIndexBuffer : public DynamicVertexBuffer
{
    private:
        unsigned int m_id;
        unsigned int m_offset = 0;

    public:
        GLDynamicIndexBuffer() {std::cout << " Dynamic vertex buffer created " << std::endl;};
        ~GLDynamicIndexBuffer();
        
        // Generates buffer and allocates size
        void init(unsigned int size) override;
        void add(const void* data, unsigned int size) override;
        void bind() const override;
        void unbind() const override;
        // Resets vertex buffer, to be called between each frame
        void reset() override;
};