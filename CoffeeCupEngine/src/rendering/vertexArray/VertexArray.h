#pragma once

#include "../vertexBuffer/DynamicVertexBuffer.h"
#include "../vertexBufferLayout/VertexBufferLayout.h"
#include "../geometry/quad.h"

#include <memory>


class VertexArray
{
    public:
        virtual ~VertexArray() = default; 
        virtual void init() = 0;
        virtual void addBuffer(const std::shared_ptr<DynamicVertexBuffer> vb, const std::shared_ptr<VertexBufferLayout> layout) const = 0;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
        virtual unsigned int getId() const;

        // Creates proper subclass given rendering API 
        static std::shared_ptr<VertexArray> create();
};