#pragma once

#include "rendering/vertexBuffer.h"


class GLVertexBuffer : public VertexBuffer
{
    private:
        unsigned int _id;
        unsigned int _offset = 0;

    public:
        GLVertexBuffer() {std::cout << " Dynamic vertex buffer created " << std::endl;};
        ~GLVertexBuffer();
        
        // Generates buffer and allocates size
        void init(unsigned int size) override;
        void add(const void* data, unsigned int size) override;
        void bind() const override;
        void unbind() const override;
        // Resets vertex buffer, to be called between each frame
        void reset() override;
};