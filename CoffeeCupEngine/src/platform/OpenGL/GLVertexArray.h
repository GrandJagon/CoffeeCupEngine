#pragma once

#include "GlUtils.h"
#include "../../rendering/vertexArray/VertexArray.h"

#include <memory>


class GLVertexArray : public VertexArray
{
    private: 
        unsigned int m_id;

    public:
        GLVertexArray() {std::cout << "OpenGl VAO created" << std::endl;};
        ~GLVertexArray() override; 
        void init() override;
        void addBuffer(const std::shared_ptr<DynamicVertexBuffer> vb, const std::shared_ptr<VertexBufferLayout> layout) const override;
        void bind() const override;
        void unbind() const override;
        unsigned int getId() const override {return m_id;};
};