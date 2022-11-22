#pragma once

#include "../../utils/utilities.h"
#include "../renderingConstants.h"
#include "../vertexBuffer/DynamicVertexBuffer.h"
#include "../indexBuffer/DynamicIndexBuffer.h"
#include "../vertexArray/VertexArray.h"
#include "../vertexBufferLayout/VertexBufferLayout.h"
#include "../shaders/Shader.h"
#include "../texture/Texture.h"


class Renderer
{
    private:
        VertexArray _vao;
        DynamicVertexBuffer _vb;
        DynamicIndexBuffer _ib;
        Shader* _shader;
        unsigned int _maxVertices;
        unsigned int _quadNumbers;
        unsigned int _vertexOffset;

        // Actual vertex data stored here before being sent to GPU
        // Needs to be stored in order to update transform for each object
        Quad* _quads;
        Quad* _currentQuad;
        
        std::array<Texture, 32> _textures;
        unsigned int _textureSlots;

        // Offset of last vertex added to buffer, should be eqauel to ib count
        unsigned int _renderCalls;

    public:
        Renderer() {std::cout << "Renderer instnce created" << std::endl;};
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
