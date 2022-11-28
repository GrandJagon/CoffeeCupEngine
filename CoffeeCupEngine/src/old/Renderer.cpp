#include "Renderer.h"

void Renderer::init()
{
    _quadNumbers = RenderingConst::RENDERER_QUADS;
    _maxVertices = _quadNumbers * 4;
    
    _vao.init();
    _vb.init(_maxVertices);
    _ib.init(_quadNumbers);

    _vao.bind();
    
    // Defining layout of vertex buffer data
    VertexBufferLayout layout;

    layout.addElements(
        {
            {GL_FLOAT, 3, false}, // Position
            {GL_FLOAT, 4, false}, // Color
            {GL_FLOAT, 2, false}, // Texture coordinates
            {GL_FLOAT, 1, false}  // Texture ID
        }
    );
    
    // Binding vertex buffer and layout to vertex array
    _vao.addBuffer(_vb, layout);
    
    // Initiating vertex data in the heap
    _quads = new Quad[_quadNumbers];
    _currentQuad = _quads;

    std::string shaderPath = "../res/shaders/Texture.shader";

    _shader = new Shader;
    _shader->init(shaderPath);

    // White texture at slot 0
    uint32_t white = 0xffffffff;
    Texture *whiteTexture = new Texture(&white, 1, 1);

    _textures[0] = *whiteTexture;
    _textureSlots = 1;

    int32_t samplers[32];

    for(int i = 0 ; i < 32; i++)
    {
        samplers[i] = i;
    }

    _shader->setUniformArrayInt("uTextures", 32, samplers);
}
    

void Renderer::newBatch()
{
    _vertexOffset = 0;
    _currentQuad = _quads;
    _renderCalls += 1;
    _vb.reset();
    _ib.reset();
}

void Renderer::draw(glm::vec3 position, glm::vec2 size, float textId)
{   
    // If maximum vertices number reached then renders and starts new batch
    if( (_vertexOffset + 4) > _maxVertices )
    {   
        render();
    }

    _currentQuad->setData(position, size, textId);
    _currentQuad++;
    _ib.setCount(_ib.getCount() + 6);
    _vertexOffset += 4;
}

void Renderer::draw(glm::vec3 position, glm::vec2 size, glm::vec4 color)
{   
    // If maximum vertices number reached then renders and starts new batch
    if( (_vertexOffset + 4) > _maxVertices )
    {
        render();
    }

    _currentQuad->setData(position, size, color);
    _currentQuad++;
    _ib.setCount(_ib.getCount() + 6);
    _vertexOffset += 4;
}

void Renderer::draw(glm::vec2 position, glm::vec2 size, float textId)
{   
    draw({ position.x, position.y, 0.f }, size, textId);
}

void Renderer::draw(glm::vec2 position, glm::vec2 size, glm::vec4 color)
{   
    draw({ position.x, position.y, 0.f }, size, color);
}

void Renderer::setMVP(glm::mat4 mvp)
{
    _shader->setUniformMat4("uMVP", mvp);
}

void Renderer::render()
{   
    GlCall(glClear(GL_COLOR_BUFFER_BIT));

    for(int i = 0; i < _textureSlots; i++)
    {
       // _textures[i].bind(i);
    }
    
    _shader->bind();

    uint32_t batchSize = (uint8_t *) _currentQuad - (uint8_t *) _quads;
    _vb.add(_quads, batchSize);

    _vao.bind();
    _ib.bind();
    GlCall(glDrawElements(GL_TRIANGLES, _ib.getCount(), GL_UNSIGNED_INT, nullptr));

    newBatch();
}

void Renderer::endFrame()
{    
    _renderCalls = 0;
}