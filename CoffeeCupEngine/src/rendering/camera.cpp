#include "CCEnginePrecompiled.h"
#include "camera.h"


Camera::Camera(float left, float right, float bottom, float top)
{
    std::cout << "Camera created with coordinates " << left << right << top << bottom << std::endl;

    _position = glm::mediump_vec3(0.0f);
    
    _projectionMatrix = glm::ortho(left, right, bottom, top);

    translate();
   
}

void Camera::move(glm::vec3 translation)
{
    _position = _position + translation * _speed;
    translate();
    
}

void Camera::move(float x, float y, float z /*= 0.0f*/)
{
    _position = _position + glm::vec3(x, y ,z) * _speed;
    translate();
}

void Camera::translate()
{
    _viewMatrix = glm::translate(glm::mat4(1.0f), _position);

    _viewProjectionMatrix = _projectionMatrix * _viewMatrix;
}