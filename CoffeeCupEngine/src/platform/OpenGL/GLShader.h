#pragma once

#include "GlUtils.h"
#include "../../rendering/shader.h"

class GLShader : public Shader
{
    private:
        unsigned int m_id;
        unsigned int compileShader(std::string &source, unsigned int type);
        unsigned int createShader(std::string &vertexShader, std::string &fragmentShader);
        void getShaderLog(int id);
        void getProgramLog(int id, char* out);
    
    protected:
        ShaderObject parseShaderFile(std::string &filePath);
        
    public:
        GLShader() = default;
        ~GLShader();
        void init(std::string &filePath) override;
        void bind() const override;
        void unbind() const override;
        int getUniformLocation(const std::string &name) override;
        void setUniform4f(const std::string &name, float v1, float v2, float v3, float v4) override;
        void setUniformMat4(const std::string &name, const glm::mat4 &mat) override;
        void setUniform1i(const std::string &name, int v) override;
        void setUniformArrayInt(const std::string &name, uint32_t count,  int* values) override;
};