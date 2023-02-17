#pragma once

#include <vector>
#include <array>
#include <memory>

struct LayoutElement
{
    unsigned int index;
    unsigned int type;
    unsigned int count;
    unsigned int normalized;
};

class VertexBufferLayout
{
    public:
        virtual ~VertexBufferLayout() = default;
        virtual void addElement(unsigned int type, unsigned int count, bool normalized) = 0;
        virtual void addElements(std::vector<std::array<unsigned int, 3>> elements) = 0;
        virtual unsigned int getLastIndex() = 0;
        virtual unsigned int getStride() const = 0;
        virtual std::vector<LayoutElement> elements() const = 0;
        
        // Creates proer derived class given rendering API
        static std::shared_ptr<VertexBufferLayout> create();

};

