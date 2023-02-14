#include "GLRenderer.h"

void GLRenderer::init()
{
    std::cout << "_______Renderer INIT_________" << std::endl;

    // Sets the appropriate blending function for displaying
    GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    
    _vao = VertexArray::create();
    _vb = VertexBuffer::create();
    _ib = IndexBuffer::create();
    
    _quadNumbers = RenderingConst::RENDERER_QUADS;
    _maxVertices = _quadNumbers * 4;
    
    _vao->init();
    _vb->init(_maxVertices);
    _ib->init(_quadNumbers);

    _vao->bind();
    
    // Defining layout of vertex buffer data
    std::shared_ptr<VertexBufferLayout> layout = VertexBufferLayout::create();

    layout->addElements(
        {
            {GL_FLOAT, 3, false}, // Position
            {GL_FLOAT, 4, false}, // Color
            {GL_FLOAT, 2, false}, // Texture coordinates
            {GL_FLOAT, 1, false}  // Texture ID
        }
    );
    
    // Binding vertex buffer and layout to vertex array
    _vao->addBuffer(_vb, layout);
    
    // Initiating vertex data in the heap and ptr to first element
    _quads = new Quad[_quadNumbers];
    _currentQuad = _quads;

    std::string shaderString = 
    #include "../../../res/shaders/Texture.shader"
    ;

    _shader = Shader::create();
    _shader->init(shaderString);

    // White texture at slot 0
    uint32_t white = 0xffffffff;
    _whiteTexture = TextureManager::instance()->createTexture(&white, 1, 1);

    TextureManager::instance()->bindTexture(_whiteTexture);

    int32_t samplers[32];

    for(int i = 0 ; i < 32; i++)
    {
        samplers[i] = i;
    }

    _shader->setUniformArrayInt("uTextures", 32, samplers);

    std::cout << "_____________________RENDERER INITIATED_____________________" << std::endl;
}
    

void GLRenderer::newBatch()
{
    _vertexOffset = 0;
    _currentQuad = _quads;
    _renderCalls += 1;
    _vb->reset();
    _ib->reset();
}

void GLRenderer::draw(glm::vec3 position, glm::vec2 size, std::shared_ptr<Texture> texture)
{
    
    unsigned int textureIndex;
    
    // Texture already bound to slot
    if((textureIndex = texture->getIndex()) != -1)
    {
        draw(position, size, (float) textureIndex);   
    }

    // All slots taken
    if(TextureManager::instance()->currIndex() >= TextureManager::instance()->maxSlot())
    {
        render();
        TextureManager::instance()->unbindAll();
        TextureManager::instance()->bindTexture(_whiteTexture);   
    }

    textureIndex = TextureManager::instance()->bindTexture(texture);

    draw(position, size, (float) textureIndex);  
}

void GLRenderer::draw(glm::vec3 position, glm::vec2 size, float textId)
{   
    // If maximum vertices number reached then renders and starts new batch
    if( (_vertexOffset + 4) > _maxVertices )
    {   
        render();
    }

    _currentQuad->setData(position, size, textId);
    _currentQuad++;
    _ib->setCount(_ib->getCount() + 6);
    _vertexOffset += 4;
}

void GLRenderer::draw(glm::vec3 position, glm::vec2 size, glm::vec4 color)
{   
    // If maximum vertices number reached then renders and starts new batch
    if( (_vertexOffset + 4) > _maxVertices )
    {
        render();
    }

    _currentQuad->setData(position, size, color);
    _currentQuad++;
    _ib->setCount(_ib->getCount() + 6);
    _vertexOffset += 4;
}

void GLRenderer::draw(glm::vec2 position, glm::vec2 size, std::shared_ptr<Texture> texture)
{
    draw({ position.x, position.y, 0.f }, size, texture);  
}

void GLRenderer::draw(glm::vec2 position, glm::vec2 size, float textId)
{   
    draw({ position.x, position.y, 0.f }, size, textId);
}

void GLRenderer::draw(glm::vec2 position, glm::vec2 size, glm::vec4 color)
{   
    draw({ position.x, position.y, 0.f }, size, color);
}

void GLRenderer::setShader(std::shared_ptr<Shader> shader)
{
    _shader = shader;
}

void GLRenderer::setMVP(glm::mat4 mvp)
{
    _shader->setUniformMat4("uMVP", mvp);
}

void GLRenderer::render()
{   
    
    GlCall(glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT));

    TextureManager::instance()->bindAll();
    
    _shader->bind();

    uint32_t batchSize = (uint8_t *) _currentQuad - (uint8_t *) _quads;
    _vb->add(_quads, batchSize);

    _vao->bind();
    _ib->bind();
    GlCall(glDrawElements(GL_TRIANGLES, _ib->getCount(), GL_UNSIGNED_INT, nullptr));

    newBatch();
}

void GLRenderer::endFrame()
{    
    _renderCalls = 0;
}

void GLRenderer::shutDown()
{
    // Free memory
}