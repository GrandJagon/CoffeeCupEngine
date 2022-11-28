#pragma once
#include "../../utils/utilities.h"
#include "../vertexBuffer/DynamicVertexBuffer.h"
#include "../vertexBufferLayout/VertexBufferLayout.h"

#include <memory>


class VertexArray
{
    private: 
        unsigned int m_id;

    public:
        VertexArray() {std::cout << "Creating VAO" << std::endl;}
        ~VertexArray(); 
        void init();
        void addBuffer(const std::shared_ptr<DynamicVertexBuffer>& vb, const VertexBufferLayout& layout);
        void bind() const;
        void unbind() const;
        unsigned int getId() const {return m_id;};


};