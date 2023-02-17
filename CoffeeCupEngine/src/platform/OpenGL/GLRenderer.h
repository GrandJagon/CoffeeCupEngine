#pragma once

#include "rendering/renderer.h"
#include "rendering/textureManager.h"
#include "rendering/vertexArray.h"
#include "rendering/vertexBuffer.h"
#include "rendering/indexBuffer.h"
#include "rendering/shader.h"
#include "rendering/texture.h"
#include "rendering/quad.h"
#include "rendering/renderingConstants.h"


class GLRenderer : public Renderer
{
    private:
        std::shared_ptr<VertexArray> _vao;
        std::shared_ptr<VertexBuffer> _vb;
        std::shared_ptr<IndexBuffer> _ib;
        std::shared_ptr<Shader> _shader;
        std::shared_ptr<Texture> _whiteTexture;
  
        unsigned int _maxVertices;
        unsigned int _quadNumbers;
        unsigned int _vertexOffset;

        // Actual vertex data stored here before being sent to GPU, 
        // Needs to be stored in order to update transform for each object
        Quad* _quads;         // array
        Quad* _currentQuad;   // ptr

        // Offset of last vertex added to buffer, should be eqauel to ib count
        unsigned int _renderCalls;

    public:
        GLRenderer() {std::cout << "GLRenderer instance created" << std::endl;};
        ~GLRenderer() {};
        
        void init() override;

        void setShader(std::shared_ptr<Shader> shader) override;
        void setMVP(glm::mat4 mvp) override;

        // Starts a new batch, should be called whenever the first one is full
        void newBatch() override;

        // Renders all quads on screen
        void render() override;
        
        // Resets stats for new frame
        void endFrame() override;
        
        // Free all heap memory
        void shutDown() override;

        unsigned int renderCalls() override { return _renderCalls; };
 
        void draw(glm::vec3 position, glm::vec2 size, std::shared_ptr<Texture> texture) override;
        void draw(glm::vec2 position, glm::vec2 size, std::shared_ptr<Texture> texture) override;

        void draw(glm::vec3 position, glm::vec2 size, float textId) override;
        void draw(glm::vec2 position, glm::vec2 size, float textId) override;

        void draw(glm::vec3 position, glm::vec2 size, glm::vec4 color) override;    
        void draw(glm::vec2 position, glm::vec2 size, glm::vec4 color) override;        
};
