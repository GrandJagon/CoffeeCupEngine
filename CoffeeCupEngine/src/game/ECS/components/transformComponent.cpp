#include "CCEnginePrecompiled.h"
#include "transformComponent.h"

void TransformComponent::setPosition(glm::vec3 newPosition)
{
    _position = newPosition;
}

void TransformComponent::addPosition(glm::vec3 position)
{
    _position += position;
}

void TransformComponent::setPosition(glm::vec2 newPosition)
{
    _position = glm::vec3(newPosition.x, newPosition.y, 0.0f);
}

void TransformComponent::addPosition(glm::vec2 position)
{
    _position += glm::vec3(position.x, position.y, 0.0f);
}

void TransformComponent::setX(float x)
{
    _position = glm::vec3(x, _position.y, 0.0f);
}

void TransformComponent::setY(float y)
{
    _position = glm::vec3(_position.x, y, 0.0f);
}

void TransformComponent::addX(float x)
{
    _position = glm::vec3(_position.x + x, _position.y, 0.0f);
}

void TransformComponent::addY(float y)
{
    _position = glm::vec3(_position.x, _position.y + y, 0.0f);
}


