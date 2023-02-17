#pragma once

#include <GL/glew.h>
#include <GL/glut.h>

#define ASSERT(x) if(!x) __builtin_trap()
#define GlCall(x) GlClearError(); \
        x;\
        ASSERT(GlLogError(#x, __FILE__,__LINE__));


// Clears all the error in the openGl error cache
// Useful to retrieve an actual error as it can be some noise
void GlClearError();

// Does nohing and returns true if there si no error
// Prints it and returnfs false if there is an error
bool GlLogError(const char* function, const char* file, int line);




