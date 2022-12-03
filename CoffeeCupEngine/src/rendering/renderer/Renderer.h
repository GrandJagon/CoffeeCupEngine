#pragma once

#include "../../utils/utilities.h"
#include "../renderingConstants.h"
#include "../vertexBuffer/DynamicVertexBuffer.h"
#include "../indexBuffer/DynamicIndexBuffer.h"
#include "../vertexArray/VertexArray.h"
#include "../vertexBufferLayout/VertexBufferLayout.h"
#include "../shaders/Shader.h"
#include "../texture/Texture.h"
#include "../textureManager/textureManager.h"

#include <memory>


class Renderer
{
    private:
        std::shared_ptr<VertexArray> _vao;
        std::shared_ptr<DynamicVertexBuffer> _vb;
        std::shared_ptr<DynamicIndexBuffer> _ib;
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
        Renderer() {std::cout << "Renderer instance created" << std::endl;};
        ~Renderer() {};
        
        static Renderer* instance() {
            static Renderer instance;
            return &instance;
        }
        
        void init();

        void setShader(Shader &shader);
        void setMVP(glm::mat4 mvp);

        // Starts a new batch, should be called whenever the first one is full
        void newBatch();

        // Renders all quads on screen
        void render();
        
        // Resets stats for new frame
        void endFrame();
        
        // Free all heap memory
        void shutDown();

        inline unsigned int renderCalls() { return _renderCalls;};
 
        void draw(glm::vec3 position, glm::vec2 size, float textId);
        void draw(glm::vec3 position, glm::vec2 size, glm::vec4 color);
        void draw(glm::vec2 position, glm::vec2 size, float textId);
        void draw(glm::vec2 position, glm::vec2 size, glm::vec4 color);        
};
