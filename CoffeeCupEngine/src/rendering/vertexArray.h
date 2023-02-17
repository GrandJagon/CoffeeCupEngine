#pragma once

#include <memory>
#include "vertexBuffer.h"
#include "vertexBufferLayout.h"


class VertexArray
{
    public:
        virtual ~VertexArray() = default; 
        virtual void init() = 0;
        virtual void addBuffer(const std::shared_ptr<VertexBuffer> vb, const std::shared_ptr<VertexBufferLayout> layout) const = 0;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
    

        // Creates proper subclass given rendering API 
        static std::shared_ptr<VertexArray> create();
};