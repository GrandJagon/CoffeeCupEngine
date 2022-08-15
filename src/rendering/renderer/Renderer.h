#pragma once

#include "../../utils/utilities.h"
#include "../vertexBuffer/DynamicVertexBuffer.h"
#include "../indexBuffer/DynamicIndexBuffer.h"
#include "../vertexArray/VertexArray.h"
#include "../vertexBufferLayout/VertexBufferLayout.h"
#include "../shaders/Shader.h"
#include "../texture/Texture.h"


class Renderer
{
    private:
        static VertexArray _vao;
        static DynamicVertexBuffer _vb;
        static DynamicIndexBuffer _ib;
        static Shader* _shader;
        static unsigned int _maxVertices;
        static unsigned int _quadNumbers;
        static unsigned int _vertexOffset;

        // Actual vertex data stored here before being sent to GPU
        // Needs to be stored in order to update transform for each object
        static Quad* _quads;
        static Quad* _currentQuad;
        
        static std::array<Texture, 32> _textures;
        static unsigned int _textureSlots;

        // Offset of last vertex added to buffer, should be eqauel to ib count
        static unsigned int _renderCalls;

    public:
        static void init(unsigned int quadNumbers);

        static void setShader(Shader &shader);
        static void setMVP(glm::mat4 mvp);

        // Starts a new batch, should be called whenever the first one is full
        static void newBatch();

        // Renders all quads on screen
        static void render();
        
        // Resets stats for new frame
        static void endFrame();
        
        // Free all heap memory
        static void shutDown();

        inline static unsigned int renderCalls() { return _renderCalls;};
 
        static void draw(glm::vec3 position, glm::vec2 size, float textId);
        static void draw(glm::vec3 position, glm::vec2 size, glm::vec4 color);
        static void draw(glm::vec2 position, glm::vec2 size, float textId);
        static void draw(glm::vec2 position, glm::vec2 size, glm::vec4 color);
        
        
};
