#pragma once

#include <string>
#include <memory>

#include "glm/glm.hpp"

//Shader Object struct
struct ShaderObject {
    std::string vShader, fShader;
};

// Different shader types in order to retrieve them from file accordingly
enum ShaderType {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
};

class Shader
{
    protected:
        ShaderObject parseShaderFile(std::string &filePath);
        ShaderObject parseShaderString(std::string &shaderString);
    
    public:
        virtual ~Shader() = default;
        virtual void init(std::string &shaderString) = 0;
        virtual void bind() const = 0;
        virtual void unbind() const = 0;
        virtual int getUniformLocation(const std::string &name) {throw std::runtime_error("Method not implemented");};
        virtual void setUniform4f(const std::string &name, float v1, float v2, float v3, float v4) {};
        virtual void setUniformMat4(const std::string &name, const glm::mat4 &mat) {};
        virtual void setUniform1i(const std::string &name, int v) {};
        virtual void setUniformArrayInt(const std::string &name, uint32_t count,  int* values) {};
        
        // Instatiates the proper subclass given the rendering APi
        static std::shared_ptr<Shader> create();
};