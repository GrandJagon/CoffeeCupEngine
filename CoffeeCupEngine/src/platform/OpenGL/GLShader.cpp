#include "CCEnginePrecompiled.h"
#include "GLShader.h"
#include "GlUtils.h"

void GLShader::init(std::string &shaderString)
{
    ShaderObject so = parseShaderString(shaderString);
    m_id = createShader(so.vShader, so.fShader);

    std::cout << "Shader initiated with id " << m_id << std::endl;
}

GLShader::~GLShader()
{
    std::cout << "Destroying shader with id " << m_id << std::endl;
    GlCall(glDeleteProgram(m_id));
}

void GLShader::bind() const
{
    GlCall(glUseProgram(m_id));
}

void GLShader::unbind() const
{
    GlCall(glUseProgram(0));
}

unsigned int GLShader::compileShader(std::string &source, unsigned int type)
{
    // Creates a unique id for the shader
    GlCall(unsigned int id = glCreateShader(type));

    // Pointer to source data
    const char *sourceCode = source.c_str();

    // Assigning source code to shader
    GlCall(glShaderSource(id, 1, &sourceCode, nullptr));

    // Compiling shader and returns its id
    GlCall(glCompileShader(id));

    // COMPILING ERROR CHECK
    int result;
    GlCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

    if (result == GL_FALSE)
    {
        int length;
        GlCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));
        char *message = (char *)alloca(sizeof(char) * length);
        GlCall(glGetShaderInfoLog(id, length, &length, message));
        std::cout << "Failed to compile shader " << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << std::endl;
        std::cout << message << std::endl;
        GlCall(glDeleteShader(id));
        return 0;
    }
    return id;
}

unsigned int GLShader::createShader(std::string &vertexShader, std::string &fragmentShader)
{
    // Creates a new program and returns its unique uint identifier
    GlCall(unsigned int program = glCreateProgram());

    // reates a shader objet for both arguments strings
    GlCall(unsigned int vShader = compileShader(vertexShader, GL_VERTEX_SHADER));
    GlCall(unsigned int fShader = compileShader(fragmentShader, GL_FRAGMENT_SHADER));

    // Attaches the shaders, links them and validate the program
    GlCall(glAttachShader(program, vShader));
    GlCall(glAttachShader(program, fShader));
    GlCall(glLinkProgram(program));

    // LINKING ERROR CHECK
    int result;
    GlCall(glGetProgramiv(program, GL_LINK_STATUS, &result));

    if (result == GL_FALSE)
    {
        int length;
        GlCall(glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length));
        char *message = (char *)alloca(sizeof(char) * length);
        GlCall(glGetShaderInfoLog(program, length, &length, message));
        std::cout << "Failed to compile shader program " << std::endl;
        std::cout << message << std::endl;
        GlCall(glDeleteProgram(program));
        return 0;
    }

    GlCall(glValidateProgram(program));

    // Deletes the temporary shader objects
    GlCall(glDeleteShader(vShader));
    GlCall(glDeleteShader(fShader));

    return program;
}

// Retrieves an uniform location according to its name and current shader
int GLShader::getUniformLocation(const std::string &name)
{
    GlCall(int location = glGetUniformLocation(m_id, name.c_str()));

    if (location == -1)
    {
        std::cout << "Uniform does not exists " << std::endl;
    }

    return location;
}

// Sets uniform value if is 4 floats
void GLShader::setUniform4f(const std::string &name, float f1, float f2, float f3, float f4)
{
    bind();
    GlCall(glUniform4f(getUniformLocation(name), f1, f2, f3, f4));
}

// Sets uniform value if its 1 integer
void GLShader::setUniform1i(const std::string &name, int v)
{
    bind();
    GlCall(glUniform1i(getUniformLocation(name), v));
}

// Sets uniform value if its array of integer
void GLShader::setUniformArrayInt(const std::string &name, uint32_t count, int *values)
{
    bind();
    GlCall(glUniform1iv(getUniformLocation(name), count, values));
}

// Sets uniform value if its 4x4 matrix
void GLShader::setUniformMat4(const std::string &name, const glm::mat4 &mat)
{
    bind();
    GlCall(glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]));
}

// Retrieves the shader log, to be call after creation to be sure everything went right
void GLShader::getShaderLog(int id)
{
    int length;
    char *out;

    // Assignslength acording to log length
    glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

    // Declaring message according to length
    char *message = (char *)alloca(sizeof(char) * length);

    // Fetching log and assigning it to message
    glGetShaderInfoLog(id, length, &length, message);

    for (int i = 0; i < length; i++)
    {
        out[i] = message[i];
    }
    std::cout << "Shader compile error" << std::endl;
    std::cout << out << std::endl;
}

// Retrieves the program log, to be called after linking to be sure everything went right
void GLShader::getProgramLog(int id, char *out)
{
    int length;

    // Assignslength acording to log length
    glGetProgramiv(id, GL_INFO_LOG_LENGTH, &length);

    // Declaring message according to length
    char *message = (char *)alloca(sizeof(char) * length);

    // Fetching log and assigning it to message
    glGetProgramInfoLog(id, length, &length, message);

    for (int i = 0; i < length; i++)
    {
        out[i] = message[i];
    }
}
