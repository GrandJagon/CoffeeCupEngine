#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera 
{
    private: 
        glm::vec3 _position;

        float _speed = 5;

        // Adjusts coordinates to screen coordinates
        glm::mat4 _projectionMatrix;

        // Sets what camera sees 
        glm::mat4 _viewMatrix;

        // Product of both to be given to shader
        glm::mat4 _viewProjectionMatrix;

        void translate();
    
    public:
        Camera(float left, float right, float bottom, float top);
    
        ~Camera() = default;

        glm::mat4 getVPM() { return _viewProjectionMatrix; };

        void setSpeed(float newSpeed) { _speed = newSpeed; };

        void move(glm::vec3 translation);
        void move(float x, float y, float z = 0);
};