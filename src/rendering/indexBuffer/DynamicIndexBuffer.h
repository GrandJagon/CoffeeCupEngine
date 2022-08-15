#pragma once
#include "../../utils/utilities.h"

#define BUFFER_OFFSET(offset) (static_cast<char*>(0) + (offset))

class DynamicIndexBuffer
{
    private:
        unsigned int m_id;
        unsigned int m_count = 0;

    public:
        DynamicIndexBuffer() {std::cout << "Creating index buffer" << std::endl;};
        ~DynamicIndexBuffer();

        // Generates buffer and generates size * 6 as each quad takes 6 vertices
        void init(unsigned int size);
        void bind() const;
        void unbind() const;
        void setCount(unsigned int count) {m_count = count;};
        unsigned int getCount() const {return m_count;};
        // Resets the count, to be called between each frame
        void reset();

};