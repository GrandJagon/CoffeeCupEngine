#pragma once

#include "GlUtils.h"
#include "../../rendering/indexBuffer.h"


#define BUFFER_OFFSET(offset) (static_cast<char*>(0) + (offset))

class GLIndexBuffer : public IndexBuffer
{
    private:
        unsigned int m_id;
        unsigned int m_count = 0;

    public:
        GLIndexBuffer() {std::cout << "Creating index buffer" << std::endl;};
        ~GLIndexBuffer();

        // Generates buffer and generates size * 6 as each quad takes 6 vertices
        void init(unsigned int size) override;
        void bind() const override;
        void unbind() const override;
        void setCount(unsigned int count) override {m_count = count;};
        unsigned int getCount() const override {return m_count;};
        // Resets the count, to be called between each frame
        void reset() override;
};