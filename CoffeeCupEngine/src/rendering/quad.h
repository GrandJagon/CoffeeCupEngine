#pragma once
#include <array>
#include "../utils/utilities.h"

struct Vertex
{
    glm::vec3 position;
    glm::vec4 color;
    glm::vec2 textCoord;
    float textId;
};

std::ostream &operator<< (std::ostream &output, const Vertex &v);

struct Quad
{
    Vertex v0;
    Vertex v1;
    Vertex v2;
    Vertex v3;

    void setData(glm::vec3 position, glm::vec2 size, glm::vec4 color);
    void setData(glm::vec3 position, glm::vec2 size, float textId);
    void setData(glm::vec2 position, glm::vec2 size, glm::vec4 color);
    void setData(glm::vec2 position, glm::vec2 size, float textId);
};

std::ostream &operator <<(std::ostream &output, const Quad &q);






