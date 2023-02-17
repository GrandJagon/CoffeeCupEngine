#include "CCEnginePrecompiled.h"
#include "quad.h"

void Quad::setData(glm::vec3 position, glm::vec2 size, glm::vec4 color) 
{
    v0.position = {position.x, position.y, position.z};
    v0.color = color;
    v0.textCoord = {0.0f, 0.0f};
    v0.textId = 0;

    v1.position = {position.x + size.x, position.y, position.z};
    v1.color = color;
    v1.textCoord = {1.0f, 0.0f};
    v1.textId = 0;

    v2.position = {position.x + size.x, position.y + size.y, position.z};
    v2.color = color;
    v2.textCoord = {1.0f, 1.0f};
    v2.textId = 0;

    v3.position = {position.x, position.y + size.y, position.z};
    v3.color = color;
    v3.textCoord = {0.0f, 1.0f};
    v3.textId = 0;
}

void Quad::setData(glm::vec3 position, glm::vec2 size, float textId) 
{     
    v0.position = {position.x, position.y, position.z};
    v0.color = {1.0f, 1.0f, 1.0f, 1.0f};
    v0.textCoord = {0.0f, 0.0f};
    v0.textId = textId;

    v1.position = {position.x + size.x, position.y, position.z};
    v1.color = {1.0f, 1.0f, 1.0f, 1.0f};
    v1.textCoord = {1.0f, 0.0f};
    v1.textId = textId;

    v2.position = {position.x + size.x, position.y + size.y, position.z};
    v2.color = {1.0f, 1.0f, 1.0f, 1.0f};
    v2.textCoord = {1.0f, 1.0f};
    v2.textId = textId;

    v3.position = {position.x, position.y + size.y, position.z};
    v3.color = {1.0f, 1.0f, 1.0f, 1.0f};
    v3.textCoord = {0.0f, 1.0f};
    v3.textId = textId;
}

void Quad::setData(glm::vec2 position, glm::vec2 size, glm::vec4 color)
{
    setData({ position.x, position.y, 0.0f}, size, color);
}

void Quad::setData(glm::vec2 position, glm::vec2 size, float textId)
{
    setData( {position.x, position.y, 0.0f}, size, textId);
}

std::ostream &operator<< (std::ostream &output, const Vertex &v) 
{
        output << "(" << v.position.x << "," << v.position.y << "," << v.position.z << "),"
                        << "(" << v.color.r << "," << v.color.g << "," << v.color.b << "," << v.color.a  << "),"
                        << "(" << v.textCoord.x << "," << v.textCoord.y  << ")," << v.textId ;

        return output;
}

std::ostream &operator <<(std::ostream &output, const Quad &q)
{
    output << "Quad data : \n" << q.v0 << "\n" << q.v1 << "\n" << q.v2 << "\n" << q.v3;

    return output;
}






