#include <GL/glew.h>
#include <GL/glut.h>
#include <GLFW/glfw3.h>

#include <iostream>

void GlClearError() 
{
    // Retrieves the error until the code is no error
    while(glGetError() != GL_NO_ERROR);
}

bool GlLogError(const char* function, const char* file, int line) 
{
    // Prints the error in the case there is one stored in the error cache
    while(GLenum error = glGetError())
    {
        std::cout << "OpenGL error : " << file << " " << function << " : " << line << " -> " << error << std::endl;
        return false;
    }
    
    // If there is no error
    return true;
}