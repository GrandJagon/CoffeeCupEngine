#pragma once

#include "GlUtils.h"
#include "../../rendering/vertexBuffer/DynamicVertexBuffer.h"


class GLDynamicVertexBuffer : public DynamicVertexBuffer
{
    private:
        unsigned int _id;
        unsigned int _offset = 0;

    public:
        GLDynamicVertexBuffer() {std::cout << " Dynamic vertex buffer created " << std::endl;};
        ~GLDynamicVertexBuffer();
        
        // Generates buffer and allocates size
        void init(unsigned int size) override;
        void add(const void* data, unsigned int size) override;
        void bind() const override;
        void unbind() const override;
        // Resets vertex buffer, to be called between each frame
        void reset() override;
};