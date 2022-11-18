#pragma once
#include "../../utils/utilities.h"



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
    private:
        unsigned int m_id;
        ShaderObject parseShaderFile(std::string &filePath);
        unsigned int compileShader(std::string &source, unsigned int type);
        unsigned int createShader(std::string &vertexShader, std::string &fragmentShader);
        void getShaderLog(int id);
        void getProgramLog(int id, char* out);
        
    public:
        Shader() = default;
        ~Shader();
        void init(std::string &filePath);
        void bind() const;
        void unbind() const;
        int getUniformLocation(const std::string &name);
        void setUniform4f(const std::string &name, float v1, float v2, float v3, float v4);
        void setUniformMat4(const std::string &name, const glm::mat4 &mat);
        void setUniform1i(const std::string &name, int v);
        void setUniformArrayInt(const std::string &name, uint32_t count,  int* values);
};