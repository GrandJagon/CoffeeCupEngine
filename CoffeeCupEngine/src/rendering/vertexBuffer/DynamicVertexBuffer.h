#pragma once

#include "../geometry/quad.h"
#include <memory>

class DynamicVertexBuffer
{
    public:
        ~DynamicVertexBuffer() = default;
        
        // Generates buffer and allocates size
        virtual void init(unsigned int size) = 0;
        virtual void add(const void* data, unsigned int size) = 0;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
        // Resets vertex buffer, to be called between each frame
        virtual void reset() = 0;
        unsigned int getId();

        // Creates the proper subclass given the rendering API
        static std::shared_ptr<DynamicVertexBuffer> create();
};