#pragma once

#include "rendering/vertexArray.h"

class GLVertexArray : public VertexArray
{
    private: 
        unsigned int m_id;

    public:
        GLVertexArray() {std::cout << "OpenGl VAO created" << std::endl;};
        ~GLVertexArray() override; 
        void init() override;
        void addBuffer(const std::shared_ptr<VertexBuffer> vb, const std::shared_ptr<VertexBufferLayout> layout) const override;
        void bind() const override;
        void unbind() const override;
};