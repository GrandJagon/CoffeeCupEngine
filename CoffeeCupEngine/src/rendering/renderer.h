#pragma once

#include "renderingConstants.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "vertexArray.h"
#include "vertexBufferLayout.h"
#include "shader.h"
#include "texture.h"
#include "textureManager.h"

#include <memory>

class Renderer
{
    public:
        virtual ~Renderer() = default;
        
        // Only supports OpenGL for now
        static std::shared_ptr<Renderer> instance();
        
        virtual void init() = 0;

        virtual void setShader(std::shared_ptr<Shader> shader) = 0;
        virtual void setMVP(glm::mat4 mvp) = 0;

        // Starts a new batch, should be called whenever the first one is full
        virtual void newBatch() = 0;

        // Renders all quads on screen
        virtual void render() = 0;
        
        // Resets stats for new frame
        virtual void endFrame() = 0;
        
        // Free all heap memory
        virtual void shutDown() = 0;

        virtual unsigned int renderCalls() {throw std::runtime_error("Method not implemented");};
 
        virtual void draw(glm::vec3 position, glm::vec2 size, std::shared_ptr<Texture> texture) {};
        virtual void draw(glm::vec2 position, glm::vec2 size, std::shared_ptr<Texture> texture) {};

        virtual void draw(glm::vec3 position, glm::vec2 size, float textId) {};
        virtual void draw(glm::vec2 position, glm::vec2 size, float textId) {};

        virtual void draw(glm::vec3 position, glm::vec2 size, glm::vec4 color) {};    
        virtual void draw(glm::vec2 position, glm::vec2 size, glm::vec4 color) {};        
};
