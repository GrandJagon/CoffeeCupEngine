#pragma once

#include <memory>

class IndexBuffer
{
    public:
        virtual ~IndexBuffer() = default;

        // Generates buffer and generates size * 6 as each quad takes 6 vertices
        virtual void init(unsigned int size) = 0;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
        virtual void setCount(unsigned int count) = 0;
        virtual unsigned int getCount() const = 0;
        // Resets the count, to be called between each frame
        virtual void reset() = 0;

        // Instantiate required subclass given rendering API
        static std::shared_ptr<IndexBuffer> create();
};