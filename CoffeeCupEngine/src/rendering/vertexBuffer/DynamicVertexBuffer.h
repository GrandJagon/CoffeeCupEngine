#pragma once
#include "../../utils/utilities.h"

class DynamicVertexBuffer
{
    private:
        unsigned int m_id;
        unsigned int m_offset = 0;

    public:
        DynamicVertexBuffer() {std::cout << " Dynamic vertex buffer created " << std::endl;};
        ~DynamicVertexBuffer();

        // Generates buffer and allocates size
        void init(unsigned int size);
        void add(const void* data, unsigned int size);
        void bind() const;
        void unbind() const;
        // Resets vertex buffer, to be called between each frame
        void reset();
        unsigned int getId() {return m_id;};
};