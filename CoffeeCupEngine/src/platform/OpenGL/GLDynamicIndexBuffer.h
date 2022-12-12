#pragma once

#include "GlUtils.h"
#include "../../rendering/indexBuffer/DynamicIndexBuffer.h"


#define BUFFER_OFFSET(offset) (static_cast<char*>(0) + (offset))

class GLDynamicIndexBuffer : public DynamicIndexBuffer
{
    private:
        unsigned int m_id;
        unsigned int m_count = 0;

    public:
        GLDynamicIndexBuffer() {std::cout << "Creating index buffer" << std::endl;};
        ~GLDynamicIndexBuffer();

        // Generates buffer and generates size * 6 as each quad takes 6 vertices
        void init(unsigned int size) override;
        void bind() const override;
        void unbind() const override;
        void setCount(unsigned int count) override {m_count = count;};
        unsigned int getCount() const override {return m_count;};
        // Resets the count, to be called between each frame
        void reset() override;
};