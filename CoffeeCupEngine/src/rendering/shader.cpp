#include "shader.h"

#include "../platform/OpenGL/GLShader.h"

ShaderObject GLShader::parseShaderFile(std::string &filePath)
{
    // Oening the file
    std::ifstream stream(filePath);

    // Creating a line object to parse the file and 1 string stream for each shader
    std::string line;
    std::stringstream stringStream[2];

    // Initialiazing the type to 0
    ShaderType type = ShaderType::NONE;

    // Parsing the file 
    while(std::getline(stream, line))
    {
        if(line.find("#shader") != std::string::npos) 
        {
            if(line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            } else if(line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }

        } else {
            stringStream[(int)type] << line << '\n';
        }
    }

    ShaderObject shader = {stringStream[0].str(), stringStream[1].str()};

    return shader;
}

std::shared_ptr<Shader> Shader::create()
{
    // Only openGL supported at the moment
    return std::make_shared<GLShader>();
}

 