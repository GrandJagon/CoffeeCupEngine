#include "transformComponent.h"

TransformComponent::setPosition(glm::vec3 newPosition)
{
    _position = newPosition;
}

TransformComponent::addPosition(glm::vec3 position)
{
    _position += position;
}

TransformComponent::setPosition(glm::vec2 newPosition)
{
    _position = glm::vec3(newPosition.x, newPosition.y, 0.0f);
}

TransformComponent::addPosition(glm::vec2 position)
{
    _position += glm::vec3(position.x, position.y, 0.0f);
}

TransformComponent::setX(float x)
{
    _position = glm::vec3(x, _position.y, 0.0f);
}

TransformComponent::setY(float y)
{
    _position = glm::vec3(_position.x, y, 0.0f);
}

TransformComponent::addX(float x)
{
    _position = glm::vec3(_position.x + x, _position.y, 0.0f);
}

TransformComponent::addY(float y)
{
    _position = glm::vec3(_position.x, _position.y + y, 0.0f);
}


